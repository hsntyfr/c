//
// Created by Hasan Tayfur on 22.04.2024.
//

#ifndef BITKI_H
#define BITKI_H
#include "Canli.h"


struct BITKI {
    Canli super;
    void (*bitkiYokEt)(struct BITKI*);



};
typedef struct BITKI* Bitki;

Bitki bitkiOlustur(int, int, int);
void bitkiYokEt(Bitki);
//char* gorunum(Bitki this);


#endif //BITKI_H
