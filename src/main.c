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
    for (i = 0; i < 20; ++i) {
        int valeur = rand() % (valMax + 1);
        //insererElementDansCollection(&a,element1[i]);
        insererElementDansCollection(&a, valeur);
    }

    afficherArbreEnAscii(&a);


    testamentCollection(&a);
    return 0;
}
