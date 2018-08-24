#ifndef __HELLOWORLD_FILE_OPERATION__
#define __HELLOWORLD_FILE_OPERATION__

#include <string>
#include <cfloat>

class FileOperation 
{
public:
	//static void saveFile(std::vector<HighscoreScene::GameUser>& userData);
	static void createFileIfNotExist();
	static void CreateFileIfNotExist(const std::string& filename);
	//static void CreateResourceFileIfNotExist(const std::string& filename);

	static std::string readFile();
    static std::string getFilePath(const std::string& filename);
    
    static bool GetInt(const std::string& tag, int& in_val, const std::string& target_file = "");
	static bool GetInt64(const std::string& tag, int64_t& in_val, const std::string& target_file = "");
	static bool GetUInt64(const std::string& tag, uint64_t& in_val, const std::string& target_file = "");
    static bool GetUInt32(const std::string& tag, uint32_t& in_val, const std::string& target_file = "");

	static bool GetResourceInt(const std::string& tag, int& in_val, const std::string& target_file = "");
	static bool GetResourceInt64(const std::string& tag, int64_t& in_val, const std::string& target_file = "");
	static bool GetResourceUInt64(const std::string& tag, uint64_t& in_val, const std::string& target_file = "");
    static bool GetResourceUInt32(const std::string& tag, uint32_t& in_val, const std::string& target_file = "");
	static bool GetResourceFloat(const std::string& tag, float& in_val, const std::string& target_file = "");
	static bool GetResourceString(const std::string& tag, std::string& in_val, const std::string& target_file = "");


    static bool SetInt(const std::string& tag, int val, const std::string& target_file = "");
	static bool SetInt64(const std::string& tag, int64_t val, const std::string& target_file = "");
	static bool SetUInt64(const std::string& tag, uint64_t val, const std::string& target_file = "");
    static bool SetUInt32(const std::string& tag, uint32_t val, const std::string& target_file = "");

	//should only be used for editing on pc's
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
	static bool SetResourceInt(const std::string& tag, int val, const std::string& target_file = "");
	static bool SetResourceInt64(const std::string& tag, int64_t val, const std::string& target_file = "");
	static bool SetResourceUInt64(const std::string& tag, uint64_t val, const std::string& target_file = "");
    static bool SetResourceUInt32(const std::string& tag, uint32_t val, const std::string& target_file = "");
	static bool SetResourceFloat(const std::string& tag, float val, const std::string& target_file = "");
#endif

	static bool FileAvailable(const std::string& filename);
	static bool ResourceFileAvailable(const std::string& filename);

	//static void Test();

	static void ReadAndSaveEncrypted(const std::string& target_file = "");
	static void ReadDecrypted(const std::string& target_file = "");

public:
    static const std::string FILE_SAVED_DATA;
    static const std::string FiLE_DATA_TABLE;
};

#endif
