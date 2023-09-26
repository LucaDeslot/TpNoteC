#include <stdio.h>
#include <stdlib.h>
#include "main.h"
Objet* objets;
void euristic(void);
Sac getSacFromFile(const char* path) {
    FILE* file = fopen(path, "r");
    if (!file) {
        perror("Failed to open file");
        exit(1);
    }

    Sac sac;
    int nbObjets;
    fscanf(file, "%d %d %d", &nbObjets, &sac.p1Max, &sac.p2Max);

    Objet object;
    sac.objets = malloc(sizeof(Objet) * nbObjets);
    sac.p2 = 0;
    sac.p1 = 0;
    sac.size = 0;
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

int main() {
    Sac sac = getSacFromFile("../objects/pb1.txt");
    euristic();
    return 0;
}
