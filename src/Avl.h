#ifndef _AVL
#define _AVL
#include "Element.h"


/**
 * @struct Noeud
 * @brief Représente un noeud de l'arbre
 */
typedef struct Noeud {

    struct Noeud *filsGauche;
    struct Noeud *filsDroit;
    Element info;
} Noeud;

/**
 * @struct Avl
 * @brief Représente un arbre AVL
 */
typedef struct {
    /**
     * Racine de l'arbre
     */
    Noeud *racine;
} Avl;

/**
 * Initialise un AVL
 */
void initialiserAvl(Avl *a);

/**
 * Test de l'AVL
 */
void testamentAvl(Avl *a);

/**
 * Retourne la hauteur de l'arbre
 */
int calculerHauteurAvl(const Avl *avl);

/**
 * Insère un élément dans l'AVL
 */
void insererElementDansAvl(Avl *a, Element element);

void creerFichierDigraph(const Avl *avl, const char *fileName);

#endif
