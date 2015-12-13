#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Collection.h"
#include "Ascii.h"

#define valMax 1000

int main(int argc, char const *ar[]) {
    Collection a;
    initialiserCollection(&a);
    Element element[11] = {10, 5, 6, 13, 14, 8, -2, 1, 11, -45, 12};

    int i;

    srand((unsigned) time(NULL));
    for (i = 0; i < 40; ++i) {
        int valeur = rand() % (valMax + 1);
        //insererElementDansCollection(&a, element[i]);
        insererElementDansCollection(&a, valeur);
    }

    //afficherArbreEnAscii(&a);

    const char fichier[] = "arbre.gv";
    char commande[256];
    creerFichierDigraphCollection(&a, fichier);
    sprintf(commande, "dot -Tsvg %s > %s.svg && eog %s.svg 2>/dev/null", fichier, fichier, fichier);
    system(commande);

    testamentCollection(&a);



    return 0;
}