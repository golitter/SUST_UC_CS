计UC211
组名：疼校
组员：杨宸，杨昊，杨钊瑞;
# 分工：
杨昊：

主要负责`SongSys.c 、Song.txt`编写

***

杨宸：

主要负责`main.c 、EXITSYSTEM.c 、musiclib`编写
细节改进；

***

杨钊瑞：

主要负责`AdminSys.c 、admin.txt`编写;

**
# 音乐
音乐播放{
    dev C++：
        工具 --> 编译选项 --> 在编译器命令行加入：-lwinmm
    vscode:
        使用 gcc自定义链接库，要在task.json中添加编译参数“-lwinmm”
}