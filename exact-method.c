//
// Created by Luca Deslot on 26/09/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "exact-method.h"

Objet* copyObjets(Objet* source, int size) {
    // Allouer de la mémoire pour le nouvel tableau d'Objet
    Objet* newObjects = (Objet*)malloc(sizeof(Objet) * size);

    // Vérifier que l'allocation a réussi
    if (newObjects == NULL) {
        exit(EXIT_FAILURE); // ou gérer l'erreur comme vous le souhaitez
    }

    // Copier les objets de l'ancien tableau vers le nouveau
    for (int i = 0; i < size; i++) {
        newObjects[i] = source[i];
    }

    // Retourner le pointeur vers le nouveau tableau
    return newObjects;
}

Sac max(Sac a, Sac b) {
    return a.valeur >= b.valeur ? a : b;
}

int isFeasible(Sac sac, Objet objet) {
    return (sac.p1 + objet.p1 <= sac.p1Max && sac.p2 + objet.p2 <= sac.p2Max);
}

int put (Sac *sac, Objet objet) {

    if(isFeasible(*sac, objet)) {
        sac->p1 += objet.p1;
        sac->p2 += objet.p2;
        sac->objets = copyObjets(sac->objets, sac->size + 1);
        sac->objets[sac->size++] = objet;
        sac->valeur += objet.valeur;
        return 1;
    } else {
        return 0;
    }

}

Sac compute(Sac sac, Objet* objets, int nbObjets) {
    if (nbObjets == 0) {
        return sac;
    }

    Sac dontTake = compute(sac, objets, nbObjets - 1); //on ne prend pas l'objet

    Sac doTake = sac; // copie de sac pour le scénario de prise de l'objet
    int res = put(&doTake, objets[nbObjets - 1]);

    if(res) {
        return max(dontTake, compute(doTake, objets, nbObjets - 1));
    } else {
        return max(sac, dontTake);
    }

//    if(isFeasible(sac, objets[nbObjets - 1])) {
//        Sac newSac = put(sac, objets[nbObjets - 1]);
//        return compute(newSac, objets, nbObjets - 1);
//    } else {
//        max(compute(sac, objets, nbObjets - 1), compute(sac, objets, nbObjets - 1));
//    }
}