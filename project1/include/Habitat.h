#ifndef HABITAT_H
#define HABITAT_H

#include "Canli.h"

struct HABİTAT {
    Canli canlilar;
    int boyut;


};
typedef struct HABİTAT *Habitat;



Habitat habitatOlustur();
void habitatYokEt(Habitat);
void habitataEkle(Habitat, Canli);
Canli kazananBul(Canli, Canli);


//habiat bıyut belirle fonksiyon file işaretçisini alan boyutu döndüren fonksiyon

//habitat olustur


#endif
