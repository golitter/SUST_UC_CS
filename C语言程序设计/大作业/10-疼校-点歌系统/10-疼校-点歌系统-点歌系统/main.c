#include "AdminSys.c"
#include "MainSystem.c"
#include "EXITSYSTEM.c"
#include "SongSys.c"
/**
 * @brief 
 * 计UC211 
 * 组名：疼校
 * 组员：杨宸，杨昊，杨钊瑞;
 * 20211503012_ <--(0 -- 1 -- 2);
 */
/**
 * @brief 
 * 大一下大作业:点歌系统
    =================================
    *         1  管理员系统          |---  ADMINOPT
    *         2  点歌          对应---     SONGOPT
    *         0  退出系统            |---  EXITSYSTEM
    =================================
    ZERO -- 0 
    
 */
#define ADMINOPT  1 // 管理员选项
#define SONGOPT  2 // 点歌选项
#define EXITSYSTEM  3 // 退出程序
const int ZERO = 0;

int _TRUE_ = 1;
int CHOICE;

int main()
{
    ImportMusic();
    FILE* fp_admin = fopen("admin.txt", "r"); // 打开管理文件，获取账号和密码
    fscanf(fp_admin,"%s",FirstAdmin.AdminName); // 
    fscanf(fp_admin, "%s",FirstAdmin.AdminPass);
    fclose(fp_admin);

    MainMenu();
    while(_TRUE_) {
        switch(CHOICE){
            case ADMINOPT:
                AdminLogin();
                break;
            case SONGOPT:
                // 歌；
                SongMainSys();
                break;
            case EXITSYSTEM:
                // 退出系统;
                ExitSys();
                break;
        }

        if(ZERO == CHOICE) {
            MainMenu();
        }
        if(-1 == CHOICE) {
            _TRUE_ = 0;

            break;
        }
        if(!(ZERO <= CHOICE && CHOICE <= EXITSYSTEM)) {
            break;
        }
    }

    return 0;
}
