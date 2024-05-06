#include "Bitki.h"
#include <stdlib.h>
#include <stdio.h>

Bitki bitkiOlustur(int x, int y, int deger) {
    Bitki this;
    this = (Bitki)malloc(sizeof(struct BITKI));
    this->super = canliOlustur(x, y, deger);
    this->simge = "B";
    this->super->getSimge = &getSimgeBitki;
    this->yokEt = &bitkiYokEt;
    return this;
}

void bitkiYokEt(Bitki this) {
    if(this == NULL) {
        return;
    }
    this->super->yokEt(this->super);
    free(this);
}

char* getSimgeBitki(Bitki this){
    if (this->super->canliMi == false)
    {
        return "X";
    }
    else if (this->super->canliMi == true) {
        return "B";
    }
}