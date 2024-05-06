#ifndef BOCEK_H
#define BOCEK_H
#include "Canli.h"


struct BOCEK {
    Canli super;
    char* simge;
    void (*yokEt)(struct BOCEK*);

};
typedef struct BOCEK* Bocek;

Bocek bocekOlustur(int, int, int);
void bocekYokEt(Bocek);
char* getSimgeBocek(Bocek);
#endif //BOCEK_H