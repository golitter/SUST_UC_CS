#include "AdminSys.c"
#include "MainSystem.c"
#include "EXITSYSTEM.c"
#include "SongSys.c"
/**
 * @brief 
 * ��UC211 
 * ��������У
 * ��Ա����巣���껣�������;
 * 20211503012_ <--(0 -- 1 -- 2);
 */
/**
 * @brief 
 * ��һ�´���ҵ:���ϵͳ
    =================================
    *         1  ����Աϵͳ          |---  ADMINOPT
    *         2  ���          ��Ӧ---     SONGOPT
    *         0  �˳�ϵͳ            |---  EXITSYSTEM
    =================================
    ZERO -- 0 
    
 */
#define ADMINOPT  1 // ����Աѡ��
#define SONGOPT  2 // ���ѡ��
#define EXITSYSTEM  3 // �˳�����
const int ZERO = 0;

int _TRUE_ = 1;
int CHOICE;

int main()
{
    ImportMusic();
    FILE* fp_admin = fopen("admin.txt", "r"); // �򿪹����ļ�����ȡ�˺ź�����
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
                // �裻
                SongMainSys();
                break;
            case EXITSYSTEM:
                // �˳�ϵͳ;
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
