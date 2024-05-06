#ifndef PIRE_H
#define PIRE_H
#include "Bocek.h"


struct PIRE {
    Bocek super;
    char* simge;
    void (*yokEt)(struct PIRE*);
};
typedef struct PIRE* Pire;

Pire pireOlustur(int, int, int);
void pireYokEt(Pire);
char* getSimgePire(Pire);
#endif //PIRE_H