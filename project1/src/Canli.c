#include "Canli.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


Canli canliOlustur(int x, int y, int deger) {
    Canli canli = (Canli)malloc(sizeof(struct CANLI));
    canli->x = x;
    canli->y = y;
    canli->deger = deger;
    canli->canliMi = true;
    canli->yokEt = &yokEt;
    canli->gorunum = &gorunum;
    return canli;
}

void yokEt(Canli canli) {
    if(canli == NULL) {
        return;
    }
    free(canli);
}

char* gorunum(Canli canli, void* p) {
    char* str = (char*)malloc(sizeof(char) * 3);
    strcpy(str, canli->getSimge(p)); // sprintf yerine strcpy kullanıldı
    return str;
}


/*char* gorunum(Canli canli, void* p) {
    char* str = (char*)malloc(sizeof(char) * 10);
    sprintf(str, "", canli->getSimge(p));
    return str;
}*/

