#include <stdio.h>
#include "Element.h"


void afficher_element(Element e) {
    printf("%d ", e);
}

int compare_element(Element e1, Element e2) {
    return e1 - e2;
}
