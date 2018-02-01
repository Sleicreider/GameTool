# GameTool

Download v0.01 here: https://drive.google.com/file/d/1yGMOSqNJvlEhq8EDB1WJEiWZnoZENzHb/view?usp=sharing

This project should make it easier to see all important PC infos in one window.
Recently I stared to care more about my cpu/ram/wifi usage, because of some hardware problems
or network problems, and I always were really annoyed to use windows taskmanager (too much unecessary info and not in one place) and other tools for cpu/gpu temperature.

They were also not that easy to use.

Therefore I just came up with the idea, of a small customizeable window, where you can choose what you want to see.
With simple access while playing without being to annoying to you as a gamer.


For now this is Windows only, since I'm no linux user (classic game dev)
and don't have a mac at the moment.
But it will be  designed with crossplatform in mind, therefore I'll be using QT for GUI, everything else will be done
in raw c++

![Image, check right corner vor CPU,RAM](https://puu.sh/z7u6y/df90fa9967.png)

Just Test code at the moment to see how it feels when playing a game.

v0.01
Fix window position ~right corner for 1920x1080 resolution.
Only RAM and CPU usage.
Fix Black color for text
Fix background opacity
Always in foreground
(Does its puprose, at least for me to get rid of taskmanager for quick PC usage info)


Future Features should include:

- Be able to change font color / size.
- Set window position
- More data: Network usage, CPU Temperature, GPU temerature
- Select which data you want to see
- Window opacity
- System Tray functionality
- Shortcut option for fast hiding and display

