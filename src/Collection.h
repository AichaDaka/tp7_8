#ifndef _collection
#define _collection

#include "Element.h"
#include "Collection.h"
enum Couleur{R,N};


typedef struct
{
	void * racine;
} Collection;


//initialisation sans elements
void initialiserCollection(Collection a);

void testament(Collection collection);

void insererElement(Collection *pos, Element val);

int rechercherElement(Collection collection, Element element);

void afficherABR(Collection collection);




#endif









