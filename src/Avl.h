#ifndef _AVL
#define _AVL
#include "Element.h"


typedef struct Noeud
{
	struct Noeud *fg;
	struct Noeud * fd;
	Element info;
	int diff;
} Noeud;

typedef struct
{
	Noeud * racine;
} Avl;


void rotationGauche(Noeud *n);

void rotationDroite(Noeud *n);




#endif
