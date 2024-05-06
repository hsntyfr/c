#include "Sinek.h"
#include <stdlib.h>

Sinek sinekOlustur(int x, int y, int deger) {
    Sinek this;
    this = (Sinek)malloc(sizeof(struct SINEK));
    this->super = bocekOlustur(x, y, deger);
    this->simge = "S";
    this->super->super->getSimge = &getSimgeSinek;
    this->yokEt = &sinekYokEt;
    return this;
}

void sinekYokEt(Sinek this) {
    if(this == NULL) {
        return;
    }
    this->super->yokEt(this->super);
    free(this);
}

char* getSimgeSinek(Sinek this) {
    if (this->super->super->canliMi == false)
    {
        return "X";
    }
    else if (this->super->super->canliMi == true) {
        return "S";
    }
}