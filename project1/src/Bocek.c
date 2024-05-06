#include "Bocek.h"
#include <stdlib.h>
#include <stdio.h>

Bocek bocekOlustur(int x, int y, int deger) {
    Bocek this;
    this = (Bocek)malloc(sizeof(struct BOCEK));
    this->super = canliOlustur(x, y, deger);
    this->simge = "C";
    this->super->getSimge = &getSimgeBocek;
    this->yokEt = &bocekYokEt;
    return this;
}

void bocekYokEt(Bocek this) {
    if(this == NULL) {
        return;
    }
    this->super->yokEt(this->super);
    free(this);
}

char* getSimgeBocek(Bocek this){
    if (this->super->canliMi == false)
    {
        return "X";
    }
    else if (this->super->canliMi == true) {
        return "C";
    }
}