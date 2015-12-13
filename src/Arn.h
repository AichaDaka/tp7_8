#ifndef ARN_H
#define ARN_H

#include <stdbool.h>
#include "Element.h"

typedef struct NoeudRN
{
    struct NoeudRN *filsGauche;
    struct NoeudRN *filsDroit;
    Element info;
    int noir;
} NoeudRN;


typedef struct ArbreRN
{
    NoeudRN *racine;
} Arn;

void ArbreRN_init(Arn *arbreRN);

void ArbreRN_testament(Arn * arbreRN);

void ArbreRN_affiche(const Arn *a);

void ArbreRN_ajouteElt(Arn * a, const Element e);


int SousArbre_ajouteElt(Arn *a, NoeudRN **pn, const Element e);
int SousArbre_recherche(const Arn *a, const NoeudRN *pn, const Element e);

int rechercherElementDansArn(const Arn *avl, Element element);

void SousArbre_affiche(const Arn *a, const NoeudRN *pn, unsigned int *nb_espaces);


#endif
