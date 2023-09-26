//
// Created by Luca Deslot on 26/09/2023.
//

#ifndef TPNOTEC_MAIN_H
#define TPNOTEC_MAIN_H

typedef struct {
    int valeur;
    int p1;
    int p2;
} Objet;

typedef struct {
    int p1Max;
    int p2Max;
    int p1;
    int p2;
    Objet* objets;
    int size;
} Sac;

void euristic(void);
#endif //TPNOTEC_MAIN_H
