#include <stdio.h>
extern int CHOICE;
void ExitSys() {
    if(3 == CHOICE) {
        CHOICE = -1;
    }
}
