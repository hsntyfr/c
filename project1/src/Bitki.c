//
// Created by Hasan Tayfur on 22.04.2024.
//

#include "Bitki.h"
#include <stdlib.h>
#include <stdio.h>

Bitki bitkiOlustur(int x, int y, int deger) {
    Bitki this;
    this = (Bitki)malloc(sizeof(struct BITKI));
    this->super = canliOlustur(x, y, deger);
    this->super->canliMi = true;
    this->bitkiYokEt = &bitkiYokEt;
    //this->super->gorunum = &gorunum;
    this->super->tur = 'B';
    return this;
}

void bitkiYokEt(Bitki this) {
    if(this == NULL) {
        return;
    }
    this->super->yokEt(this->super);
    free(this);
}

/*
char* gorunum(Bitki this) {
    char* str = (char*)malloc(sizeof(char) * 100); // 100 is just a random number
    int x = this->super->x;
    int y = this->super->y;
    char tur = this->super->tur;
    sprintf(str, "Kazanan : %c : (%d,%d)", tur, x, y);
    return str;
}
*/
