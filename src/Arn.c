#include <stdio.h>
#include <stdlib.h>
#include "Arn.h"


static void testamentRecursif(NoeudRN *noeud);

void SousArbre_init(Arn *a, NoeudRN *n, const Element e) {
    n->info = e;
    n->filsGauche = NULL;
    n->filsDroit = NULL;
    n->noir = 0;
}


void initialiserArn(Arn *arbreRN) {
    arbreRN->racine = NULL;
}

void testamentArn(Arn *arbreRN) {
    testamentRecursif(arbreRN->racine);
}

NoeudRN *SousArbre_cree(Arn *a, const Element e) {
    NoeudRN *pn = malloc(sizeof(NoeudRN));
    SousArbre_init(a, pn, e);
    return pn;
}


void insererElementDansArn(Arn *a, const Element e) {
    if (a->racine == NULL) {
        a->racine = SousArbre_cree(a, e);
        a->racine->noir = 1;
    }
    else {
        SousArbre_ajouteElt(a, &(a->racine), e);
        a->racine->noir = 1;
    }
}

NoeudRN* SousArbre_rotationGauche(NoeudRN *racine)
{
    NoeudRN *nouvelleRacine;
    nouvelleRacine = racine->filsDroit;
    racine->filsDroit = racine->filsGauche;
    nouvelleRacine->filsGauche = racine;


    racine->noir = 1;
    if(racine->filsGauche != NULL){
        racine->filsGauche->noir = racine->filsDroit->noir = 0;
    }

    return nouvelleRacine;
}

void SousArbre_rotationDoubleGauche(NoeudRN **pn)
{
    NoeudRN *pn_tmp = *pn;
    (*pn) = (*pn)->filsDroit->filsGauche;
    pn_tmp->filsDroit->filsGauche = (*pn)->filsDroit;
    (*pn)->filsDroit = pn_tmp->filsDroit;
    pn_tmp->filsDroit = (*pn)->filsGauche;
    (*pn)->filsGauche = pn_tmp;

    (*pn)->noir = 1;
    (*pn)->filsGauche->noir = (*pn)->filsDroit->noir = 0;
}


void SousArbre_rotationDoubleDroite(NoeudRN **pn)
{
    NoeudRN *pn_tmp = *pn;
    *pn = (*pn)->filsGauche->filsDroit;
    pn_tmp->filsGauche->filsDroit = (*pn)->filsDroit;
    (*pn)->filsGauche = pn_tmp->filsGauche;
    pn_tmp->filsGauche = (*pn)->filsDroit;
    (*pn)->filsDroit = pn_tmp;

    (*pn)->noir = 1;
    (*pn)->filsGauche->noir = (*pn)->filsDroit->noir = 0;
}

NoeudRN* SousArbre_rotationDroite(NoeudRN *racine)
{
    NoeudRN *nouvelleRacine;
    nouvelleRacine = racine->filsGauche;
    racine->filsGauche = nouvelleRacine->filsDroit;
    nouvelleRacine->filsDroit = racine;

    racine->noir = 1;
    if(racine->filsGauche != NULL){
        racine->filsGauche->noir = racine->filsDroit->noir = 0;
    }

    return nouvelleRacine;
}

int SousArbre_ajouteElt(Arn *a, NoeudRN **pn, const Element e) {

    if(compare_element(e,(*pn)->info) >0)
    {
        if((*pn)->filsDroit == NULL)
        {
            (*pn)->filsDroit = SousArbre_cree(a, e);
            if((*pn)->noir == 0)	return 2;		//Désequilibre avec insersion à droite
            else return 0;		//Pas de désequilibre
        }
        else
        {
            int desEq = SousArbre_ajouteElt(a, &(*pn)->filsDroit, e);
            if(desEq ==0) return 0;

            //Si il y a un désequilibre potentiel après insertion dans le sous Arbre droit :
            if((*pn)->filsGauche != NULL && (*pn)->filsGauche->noir == 0)	//Si les deux fils sont rouges
            {
                (*pn)->noir = 0;
                (*pn)->filsGauche->noir = (*pn)->filsDroit->noir = 1;
                return 3;
            }
            else if(desEq == 2)	//Si le deséquilibre vient d'une insertion à droite de la droite
            {
                printf("test\n");

                *pn=SousArbre_rotationGauche(*pn);
                return 0;
            }
            else if(desEq == 1)	//Si le désequilibre vient d'une insertion à gauche de la droite
            {
                SousArbre_rotationDoubleGauche(pn);
                return 0;
            }
            else if(desEq == 3)	//Si pas de déséquilibre dans le sous Arbre droit mais déséquilibre potentiel dans le sous Arbre considéré (pn pointe sur la racine de cet arbre)
            {
                if((*pn)->noir == 0 && (*pn)->filsDroit->noir == 0)
                    return 2;
                else
                    return 0;
            }
        }
    }

    else if(compare_element(e,(*pn)->info) <0)
    {
        if((*pn)->filsGauche == NULL)
        {
            (*pn)->filsGauche = SousArbre_cree(a, e);
            if((*pn)->noir == 0)	return 1;		//Désequilibre avec insertion à gauche
            else return 0;		//Pas de désequilibre
        }
        else
        {
            int desEq = SousArbre_ajouteElt(a, &(*pn)->filsGauche, e);
            if(desEq == 0) return 0;

            //Si il y a un désequilibre potentiel après insertion dans le sous Arbre gauche :
            if((*pn)->filsDroit != NULL && (*pn)->filsDroit->noir == 0)	//Si les deux fils sont rouges
            {
                (*pn)->noir = 0;
                (*pn)->filsGauche->noir = (*pn)->filsDroit->noir = 1;
                return 0;
            }
            else if(desEq == 2)	//Si le deséquilibre vient d'une insertion à droite de la gauche
            {
                SousArbre_rotationDoubleDroite(pn);
                return 0;
            }
            else if(desEq == 1)	//Si le désequilibre vient d'une insertion à gauche de la gauche
            {
                *pn=SousArbre_rotationDroite(*pn);
                return 0;
            }
            else if(desEq == 3)
            {
                if((*pn)->noir == 0 && (*pn)->filsGauche->noir == 1)
                    return 1;
                else
                    return 0;
            }
        }
    }

    //Si l'élément est déjà présent, pas d'appel récursif et pas de déséquilibre :
    return 0;
}

int SousArbre_recherche(const Arn *a, const NoeudRN *pn, const Element e) {

    if(pn == NULL)	return 0;
    else if(compare_element(e,pn->info) >0)	return SousArbre_recherche(a, pn->filsDroit, e);
    else if(compare_element(e,pn->info) <0)	return SousArbre_recherche(a, pn->filsGauche, e);
    else 	return 1;

}

void SousArbre_affiche(const Arn *a, const NoeudRN *pn, unsigned int *nb_espaces) {
    for(unsigned int i=0; i<*nb_espaces; i++)
        printf(" ");

    if(pn!=NULL)
    {
        if(pn->noir == 1)	printf("(n)");
        else 			printf("(r)");
        afficher_element(pn->info);
        *nb_espaces =+2;
        SousArbre_affiche(a, pn->filsGauche, nb_espaces);
        SousArbre_affiche(a, pn->filsGauche, nb_espaces);
    }
    else
        printf(" - \n");
}


static void testamentRecursif(NoeudRN *noeud) {
    if (noeud != NULL) {
        testamentRecursif(noeud->filsDroit);
        testamentRecursif(noeud->filsGauche);
        free(noeud);
    }
}

void ArbreRN_affiche(const Arn *a) {

    unsigned int nbSpaces = 0;
    printf("\n");
    SousArbre_affiche(a, a->racine,&nbSpaces);
    printf("\n");
}

int rechercherElementDansArn(const Arn *arbreRN, Element element) {
    return SousArbre_recherche(arbreRN,arbreRN->racine,element);
}




static int idnumer = 0;


static void afficherNoeud(const NoeudRN *noeud, FILE *file) {
    fprintf(file, "%d", noeud->info);
    fprintf(file, "->");
    fprintf(file, "{ ");
    if (noeud->filsGauche != NULL || noeud->filsDroit != NULL) {

        if (noeud->filsGauche != NULL){
            if(noeud->noir == 1){
                fprintf(file, "%d [fillcolor=black]", noeud->filsGauche->info);
            } else {
                fprintf(file, "%d [fillcolor=red]", noeud->filsGauche->info);
            }
        }
        else
            fprintf(file, "id%d [shape=point]", idnumer++);
        fprintf(file, " ");
        if (noeud->filsDroit != NULL){
            if(noeud->noir == 1){
                fprintf(file, "%d [fillcolor=black]", noeud->filsDroit->info);
            } else {
                fprintf(file, "%d [fillcolor=red]", noeud->filsDroit->info);
            }
        }
        else
            fprintf(file, "id%d [shape=point]", idnumer++);
    }


    fprintf(file, "};\n");
}


static void afficherDigraphRecursif(const NoeudRN *noeud, FILE *file) {
    if (noeud != NULL) {
        afficherNoeud(noeud, file);
        afficherDigraphRecursif(noeud->filsGauche, file);
        afficherDigraphRecursif(noeud->filsDroit, file);
    }
}

void creerFichierDigraphArn(const Arn *arn, const char *fileName) {
    FILE *fichierDigraph;
    fichierDigraph = fopen(fileName, "w");

    fprintf(fichierDigraph, "strict digraph AVL {\n node [style=filled fontcolor=white] \n");
    fprintf(fichierDigraph,"%d [fillcolor=black]",arn->racine->info);
    afficherDigraphRecursif(arn->racine, fichierDigraph);
    fprintf(fichierDigraph, "}\n");
    fclose(fichierDigraph);
}
