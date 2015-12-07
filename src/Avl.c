#include <stdio.h>
#include <stdlib.h>
#include "Avl.h"


/**
 * @brief Crée un noeud avec element comme info
 * @fn static Noeud *creerNoeud(Element element)
 */
static Noeud *creerNoeud(Element element) {
    Noeud *n = malloc(sizeof(Noeud));
    n->info = element;
    n->diff = 0;
    n->filsDroit = NULL;
    n->filsGauche = NULL;

    return n;
}


void initialiserAvl(Avl *a) {
    a->racine = NULL;

}

/*Fonction de rotation droite*/
void rotationDroiteAVL(Avl *a, Noeud *pn) {
    Noeud *pg;
    pg = pn->filsGauche;
    pn->filsGauche = pg->filsDroit;
    pg->filsDroit = pn;
    pn = pg;
    pn->diff = 0;
    pn->filsDroit->diff = 0;
}

/*Fonction de rotation gauche*/
void rotationGaucheAVL(Avl *a, Noeud *pn) {
    Noeud *pg;
    pg = pn->filsDroit;
    pn->filsDroit = pg->filsGauche;
    pg->filsGauche = pn;
    pn = pg;
    pn->diff = 0;
    //pn->fg->diff = 0;
}


/* Fonction d'insererElement d'un AVL */
/*
void insertionAVL(AVL & a, Noeud * ṕn, Element x,
bool b
){
int n
->
diff = 0;

if(pn==NULL){
pn = newNoeud;
        pn
->
info = x;
pn->
fg = NULL;
pn->
fd = NULL;

else {
if(x<= pn->info){
insertionAVL(a, pn
->fg, x, b)
if b
{
n->
diff = 1;
}
else
insertionAVL(a, pn, x, b
)
if b
{
n->
diff = -1;
}

}


}

}
}
*/