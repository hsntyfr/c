#include "Canli.h"
#include <stdlib.h>
#include <stdio.h>

Canli canliOlustur(int x, int y, int deger) {
    Canli this;
    this = (Canli)malloc(sizeof(struct CANLI));
    this->x = x;
    this->y = y;
    this->deger = deger;
    this->yokEt = &yokEt;
    this->gorunum = &gorunum;

    return this;
}


void yokEt(Canli this) {
    if(this == NULL) {
        return;
    }
    free(this);
}

char* gorunum(Canli this, void* p) {
    char* str = (char*)malloc(sizeof(char) * 100); // 100 is just a random number
    int x = this->x;
    int y = this->y;
    char tur = this->tur;
    sprintf(str, "Kazanan : %c : (%d,%d)", tur, x, y);
    return str;
}
