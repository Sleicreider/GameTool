#define COCOS2D_DEBUG 1

#include "FGeneral.h"
#include "FileOperation.h"
#include <fstream>
#include <iostream>
#include <sstream>

#include <filesystem>

using namespace std;


void FileOperation::CreateFileIfNotExist(const std::string& filename)
{
    string path = getFilePath(filename);
    FILE* fp = fopen(path.c_str(), "r+b");

    bool fileExists = false;

    if (!fp)
    {
        CCLOGERROR("can not open file %s... will create file", path.c_str());
        fileExists = false;
    }
    else
    {
        CCLOGERROR("can open file %s... will NOT create file", path.c_str());
        fileExists = true;
        fclose(fp);
    }

    if (!fileExists)
    {
        FILE* fp = fopen(path.c_str(), "w+b");

        if (!fp)
        {
            CCLOGERROR("can not create file %s", path.c_str());
            return;
        }

        fputs("", fp);

        fclose(fp);
    }
}



std::string FileOperation::readFile()
{
    string path = getFilePath(FiLE_DATA_TABLE);
    FILE* fp = fopen(path.c_str(), "r");
    char buf[250] = { 0 };

    if (!fp)
    {
        CCLOGERROR("can not open file %s", path.c_str());
        return "error";
    }

    fgets(buf, 250, fp);
    CCLOGERROR("read content %s", buf);

    fclose(fp);
    std::string str(buf);
    return str;
}

template <typename T>
bool GetValue(const std::string& tag,
    T& in_val,
    std::function<T(const std::string&)> fn_sto,
    const std::string& target_file)
{
    std::string file = target_file == "" ? FileOperation::FILE_SAVED_DATA : target_file;
    auto path = std::string{ FileOperation::getFilePath(file) };
    auto fp = fopen(path.c_str(), "r");

    char line[255];

    if (fp == nullptr)
    {
        CCLOGERROR("failed to open file  FileOperation::GetInt LINE=%d", __LINE__);
        return false;
    }

    bool ret = false;

    while (fgets(line, 255, fp))
    {
        int linesize = 0;
        for (auto i = 0; i < 255; i++)
        {
            if (line[i] == '\0')
            {
                linesize = i;
                break;
            }
        }

        stringstream ss(line);

        std::string first;

        ss >> first;

        if (first == tag)
        {
            int pos = 0;
            for (auto i = 0lu; i < 255; i++)
            {
                if (line[i] == '=')
                {
                    // '=' + space == i+2
                    pos = i + 2;
                    break;
                }
            }

            std::string str = line;
            str = str.substr(pos, linesize);

            in_val = fn_sto(str);

            ret = true;
            break;
        }
    }

    fclose(fp);
    return ret;
    ;
}

template <typename T> bool SetValue(const std::string& tag, T val, const std::string& target_file)
{
    std::string file = target_file == "" ? FileOperation::FILE_SAVED_DATA : target_file;

#pragma message WARN("write if not already in file!!")
    auto path = std::string{ FileOperation::getFilePath(file) };
    auto fp = fopen(path.c_str(), "r+");

    char line[255];

    if (fp == nullptr)
    {
        CCLOGERROR("failed to open file  FileOperation::GetInt LINE=%d", __LINE__);
        return -1;
    }

    // rewrite full file
    // WORKS
    std::vector<std::string> comp_file;

    auto bAvailable = false;

    while (fgets(line, 255, fp))
    {
        stringstream ss(line);
        std::string first;
        ss >> first;

        if (first == tag)
        {
            bAvailable = true;

            for (int i = 0; i < 255; i++)
            {
                if (line[i] == '=')
                {
                    std::string tmp = line;
                    tmp = tmp.substr(0, i + 2);
                    tmp += std14::to_string(val);
                    tmp += "\n";
                    comp_file.push_back(tmp);
                    break;
                }
            }

            std::cout << "write: " << comp_file[comp_file.size() - 1] << std::endl;
        }
        else
        {
            comp_file.push_back(line);
        }
    }

    if (!bAvailable)
    {
        comp_file.push_back(tag + " = " + std14::to_string(val) + "\n");
    }

    fclose(fp);

    fp = fopen(path.c_str(), "w");

    for (auto i = 0lu; i < comp_file.size(); i++)
    {
        fputs(comp_file[i].c_str(), fp);
    }

    fclose(fp);

    return true;
}


bool FileOperation::FileAvailable(const std::string& filename)
{
#pragma message WARN("create file")
    string path = getFilePath(filename);
    FILE* fp = fopen(path.c_str(), "r+b");

    bool fileExists = false;

    if (!fp)
    {
        CCLOGERROR("can not open file %s... will create file", path.c_str());
        fileExists = false;
    }
    else
    {
        CCLOGERROR("can open file %s... will NOT create file", path.c_str());
        fileExists = true;
        fclose(fp);
    }
    return fileExists;
}


bool FileOperation::GetInt(const std::string& tag, int& in_val, const std::string& target_file /* = "" */)
{
    return GetValue<int>(tag, in_val, &std14::stoi, target_file);
}

bool FileOperation::GetInt64(const std::string& tag, int64_t& in_val, const std::string& target_file /* = "" */)
{
    return GetValue<int64_t>(tag, in_val, &std14::stoll, target_file);
}

bool FileOperation::GetUInt64(const std::string& tag, uint64_t& in_val, const std::string& target_file /* = "" */)
{
    return GetValue<uint64_t>(tag, in_val, &std14::stoull, target_file);
}

bool FileOperation::GetUInt32(const std::string& tag, uint32_t& in_val, const std::string& target_file /* = "" */)
{
    return GetValue<uint32_t>(tag, in_val, &std14::stoui, target_file);
}

bool FileOperation::SetInt(const std::string& tag, int val, const std::string& target_file /* = "" */)
{
    return SetValue<int>(tag, val, target_file);
}

bool FileOperation::SetInt64(const std::string& tag, int64_t val, const std::string& target_file /* = "" */)
{
    return SetValue<int64_t>(tag, val, target_file);
}

bool FileOperation::SetUInt64(const std::string& tag, uint64_t val, const std::string& target_file /* = "" */)
{
    return SetValue<uint64_t>(tag, val, target_file);
}

bool FileOperation::SetUInt32(const std::string& tag, uint32_t val, const std::string& target_file /* = "" */)
{
    return SetValue<uint32_t>(tag, val, target_file);
}

