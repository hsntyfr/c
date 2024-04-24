//
// Created by Hasan Tayfur on 22.04.2024.
//

#include "Bocek.h"
#include <stdlib.h>
#include <stdio.h>

Bocek bocekOlustur(int x, int y, int deger) {
    Bocek this;
    this = (Bocek)malloc(sizeof(struct BOCEK));
    this->super = canliOlustur(x, y, deger);
    this->super->canliMi = true;
    this->bocekYokEt = &bocekYokEt;
    //this->super->gorunum = &gorunum;
    this->super->tur = 'C';
    return this;
}

void bocekYokEt(Bocek this) {
    if(this == NULL) {
        return;
    }
    this->super->yokEt(this->super);
    //printf("%s", "test");
    free(this);
}

/*char* gorunum(Bocek this) {
    char* str = (char*)malloc(sizeof(char) * 100); // 100 is just a random number
    int x = this->super->x;
    int y = this->super->y;
    char tur = this->super->tur;
    sprintf(str, "Kazanan : %c : (%d,%d)", tur, x, y);
    return str;
}*/