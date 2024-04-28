#include "Canli.h"
#include <stdlib.h>
#include <stdio.h>


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
    char* str = (char*)malloc(sizeof(char) * 100);
    sprintf(str, "Kazanan : %c", canli->getSimge(p));
    return str;
}

