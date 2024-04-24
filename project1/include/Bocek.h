#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

struct BOCEK {
    Canli super;
    void (*bocekYokEt)(struct BOCEK*);
};
typedef struct BOCEK* Bocek;

Bocek bocekOlustur(int, int, int);
void bocekYokEt(Bocek);
//char* gorunum(Bocek this);


#endif //BOCEK_H
