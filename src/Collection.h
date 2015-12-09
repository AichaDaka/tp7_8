#ifndef _collection
#define _collection

#include "Element.h"

typedef struct {
    void *racine;
} Collection;


/**
 * @brief Initialise une nouvelle collection
 */
void initialiserCollection(Collection *a);

/**
 * Testament de la collection initialisée
 */
void testamentCollection(Collection *collection);

/**
 * Insère un élément dans la collection
 */
void insererElementDansCollection(Collection *pos, Element val);

int rechercherElement(const Collection const *collection, Element element);

void afficherABR(const Collection const *collection);


#endif









