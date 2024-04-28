#ifndef SINEK_H
#define SINEK_H
#include "Bocek.h"


struct SINEK {
    Bocek super;
    char simge;
    void (*yokEt)(struct SINEK*);
};
typedef struct SINEK* Sinek;

Sinek sinekOlustur(int, int, int);
void sinekYokEt(Sinek);
char getSimgeSinek(Sinek);
#endif //SINEK_H