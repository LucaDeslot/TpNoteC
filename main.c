#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "exact-method.h"

Objet* objets;
int nbObjets;
void euristic(void);
Sac getSacFromFile(const char* path) {
    FILE* file = fopen(path, "r");
    if (!file) {
        perror("Failed to open file");
        exit(1);
    }

    Sac sac;
    fscanf(file, "%d %d %d", &nbObjets, &sac.p1Max, &sac.p2Max);

    Objet object;
    sac.p2 = 0;
    sac.p1 = 0;
    sac.size = 0;
    sac.valeur = 0;
    objets = malloc(sizeof(Objet) * nbObjets);
    int i = 0;
    while (fscanf(file, "%d %d %d", &object.valeur, &object.p1, &object.p2) == 3) {
        objets[i].valeur = object.valeur;
        objets[i].p1 = object.p1;
        objets[i++].p2 = object.p2;
    }
    fclose(file);
    return sac;
}

void printSac(Sac sac) {
    printf("P1: %d\nP2: %d\nValeur: %d\n", sac.p1, sac.p2, sac.valeur);
    for (int i = 0; i < sac.size; ++i) {
        printf("Objet %d: %d %d %d\n", i, sac.objets[i].valeur, sac.objets[i].p1, sac.objets[i].p2);
    }
}

int main() {
    Sac sac = getSacFromFile("../objects/pb2.txt");
    printSac(compute(sac, objets, nbObjets));
    return 0;
}
