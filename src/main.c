#include <stdio.h>
#include "Collection.h"
#include "Ascii.h"

int main(int argc, char const *ar[]) {
    Collection a;
    initialiserCollection(&a);
    Element element[10] = {-1,2,5,12,955,-5,30,0,10,-6};

    int i;
    for ( i = 0; i < 10; ++i) {
        insererElementDansCollection(&a,element[i]);
    }

    afficherArbreEnAscii(&a);

    testamentCollection(&a);
    return 0;
}
