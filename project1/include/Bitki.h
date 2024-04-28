#ifndef BITKI_H
#define BITKI_H
#include "Canli.h"


struct BITKI {
    Canli super;
    char simge;
    void (*yokEt)(struct BITKI*);
};
typedef struct BITKI* Bitki;

Bitki bitkiOlustur(int, int, int);
void bitkiYokEt(Bitki);
char getSimgeBitki(Bitki);



#endif //BITKI_H