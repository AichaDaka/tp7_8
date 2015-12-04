#include <stdio.h>
#include <stdlib.h>
#include "Avl.h"

void initialisationAVL(Avl a) {

    a.racine = NULL;
    Noeud *n = malloc(sizeof(Noeud));
    Noeud;

    n->diff = 0;

    n->info = 0;
    n->fg = NULL;
    n->fd = NULL;

    a.racine = n;

}

/*Fonction de rotation droite*/
void rotationDroiteAVL(Avl *a, Noeud *pn) {
    Noeud *pg;
    pg = pn->fg;
    pn->fg = pg->fd;
    pg->fd = pn;
    pn = pg;
    pn->diff = 0;
    pn->fd->diff=0;
}

/*Fonction de rotation gauche*/
void rotationGaucheAVL(Avl *a, Noeud * pn) {
    Noeud *pg;
    pg = pn->fd;
    pn->fd = pg->fg;
    pg->fg = pn;
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