#ifndef _AVL
#define _AVL
#include "Element.h"


typedef struct
{
	Element info;
	int diff;
	struct Noeud * fg;
	struct Noeud * fd;
	struct Noeud * pere;
} Noeud;

typedef struct
{
	Noeud * racine;
} Avl;


void rotationGauche(Noeud *n);

void rotationDroite(Noeud *n);




#endif
