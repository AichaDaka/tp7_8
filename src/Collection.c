#include <stdlib.h>
#include "Collection.h"
#include "Avl.h"
#include "Arn.h"

void initialiserCollection(Collection *collection)
{


#ifdef AVL
    collection->racine = (Avl*) malloc(sizeof(Avl));
    initialiserAvl(collection->racine);
#else
    collection->racine = (Arn*) malloc(sizeof(Arn));
    initialiserArn(collection->racine);
#endif

}



void testamentCollection(Collection *collection)
{
#ifdef AVL
    testamentAvl((Avl*)collection->racine);
#else
    testamentArn((Arn*) collection->racine);
#endif
    free(collection->racine);
}

void insererElementDansCollection(Collection *pos, Element val) {
#ifdef AVL
    insererElementDansAvl(pos->racine, val);
#else
    insererElementDansArn(pos->racine,val);
#endif
}


int rechercherElement(const Collection const *collection, Element element) {
#ifdef AVL
    return rechercherElementDansAvl((Avl*)collection->racine,element);
#else
    return rechercherElementDansArn((Arn*) collection->racine,element);
#endif
}

void creerFichierDigraphCollection(const Collection const *collection, const char *fileName) {
#ifdef AVL
    creerFichierDigraphAvl((Avl*) collection->racine,fileName);
#else
    creerFichierDigraphArn(collection->racine,fileName);
#endif

}
