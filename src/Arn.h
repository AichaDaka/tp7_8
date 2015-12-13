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

void initialiserArn(Arn *arbreRN);

void testamentArn(Arn *arbreRN);

void insererElementDansArn(Arn *a, const Element e);


int rechercherElementDansArn(const Arn *avl, Element element);

/**
 * @brief Crée un fichier avec le langage dot lisible par graphviz qui permet de construire une image de l'arbre
 * @fn void creerFichierDigraphArn(const Arn *arn, const char *fileName)
 * @param arn l'arn à construire
 * @param filename nom du fichier de sortie
 */
void creerFichierDigraphArn(const Arn *arn, const char *fileName);

#endif
