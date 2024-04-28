#include "Pire.h"
#include <stdlib.h>


Pire pireOlustur(int x, int y, int deger) {
    Pire this;
    this = (Pire)malloc(sizeof(struct PIRE));
    this->super = bocekOlustur(x, y, deger);
    this->simge = 'P';
    this->super->super->getSimge = &getSimgePire;
    this->yokEt = &pireYokEt;
    return this;
}
void pireYokEt(Pire this) {
    if(this == NULL) {
        return;
    }
    this->super->yokEt(this->super);
    free(this);
}
char getSimgePire(Pire this) {
    return this->simge;
}