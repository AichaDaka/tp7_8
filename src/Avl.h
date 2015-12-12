#ifndef _AVL
#define _AVL
#include "Element.h"


/**
 * @struct Noeud
 * @brief Représente un noeud de l'arbre
 */
typedef struct Noeud {

    struct Noeud *filsGauche; /**< fils gauche du noeud */
    struct Noeud *filsDroit; /**< fils droit du noeud */
    Element info; /**< information contenue dans le noeud */
} Noeud;

/**
 * @struct Avl
 * @brief Représente un arbre AVL. On aurait pu ne pas créer une structure mais celà peut être utile par la suite si on
 * veut ajouter d'autres métadonnées
 */
typedef struct {
    Noeud *racine; /**<  Racine de l'arbre     */
} Avl;

/**
 * @brief Initialise un AVL
 * @param avl arbre à initialiser
 */
void initialiserAvl(Avl *avl);

/**
 * @brief Testament de l'AVL
 * @param avl avl à liberer
 */
void testamentAvl(Avl *avl);

/**
 * @brief Recherche un élément dans l'arbre
 * @param avl arbre dans lequel effectué la recherche
 * @param element à chercher
 * @return 1 si l'élement se trouve dans l'arbre.
 *         0 si ce n'est pas le cas
 */
int rechercherElementDansAvl(const Avl *avl, Element element);

/**
 * @brief Retourne la hauteur de l'arbre
 * @param avl arbre dont on veut calculer la hauteur
 * @return la hauteur de l'arbre
 */
int calculerHauteurAvl(const Avl *avl);

/**
 * @brief Insère un élément dans l'AVL
 * @param a avl dans lequel on veut inserer
 * @param element element à inserer
 */
void insererElementDansAvl(Avl *a, Element element);

/**
 * @brief Crée un fichier avec le langage dot lisible par graphviz qui permet de construire une image de l'arbre
 * @fn void creerFichierDigraph(const Avl *avl, const char *fileName)
 * @param avl l'avl à construire
 * @param filename nom du fichier de sortie
 */
void creerFichierDigraph(const Avl *avl, const char *fileName);

#endif
