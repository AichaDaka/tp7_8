#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Avl.h"
#include "Utils.h"


/* fonctions et procédures internes */
static int calculHauteur(Noeud *noeud);

static void insertion(Noeud **pNoeud, Element element);

static Noeud *rotationDroite(Noeud *racine);

static Noeud *rotationGauche(Noeud *racine);

static Noeud *creerNoeud(Element element);

static void rotationAvl(Avl *avl);

static void testamentRecursif(Noeud *noeud);

static void rotationRecursif(Noeud **noeud);

static void afficherDigraphRecursif(const Noeud *noeud, FILE *file);

static void afficherNoeud(const Noeud *noeud, FILE *file);

/* **************************************************** */




void initialiserAvl(Avl *a) {
    a->racine = NULL;
}

void testamentAvl(Avl *a) {
    testamentRecursif(a->racine);
}

void insererElementDansAvl(Avl *a, Element element) {
    insertion(&(a->racine), element);
    rotationAvl(a);
}


int calculerHauteurAvl(const Avl *avl) {
    return calculHauteur(avl->racine);
}

void testDoubleRotationGauche() {
    Noeud *root = creerNoeud(2);
    root->filsDroit = creerNoeud(11);
    root->filsDroit->filsGauche = creerNoeud(5);

    root->filsDroit = rotationDroite(root->filsDroit);
    root = rotationGauche(root);
}

void testDoubleRotationDroite() {
    Noeud *root = creerNoeud(10);
    root->filsGauche = creerNoeud(5);
    root->filsGauche->filsDroit = creerNoeud(7);

    root->filsGauche = rotationGauche(root->filsGauche);
    root = rotationDroite(root);
}


void creerFichierDigraphAvl(const Avl *avl, const char *fileName) {
    FILE *fichierDigraph;
    fichierDigraph = fopen(fileName, "w");

    fprintf(fichierDigraph, "strict digraph AVL {\n");
    afficherDigraphRecursif(avl->racine, fichierDigraph);
    fprintf(fichierDigraph, "}\n");
    fclose(fichierDigraph);
}

int rechercherElementRecursif(Noeud *noeud, Element element) {
    if (noeud == NULL) {
        return 0;
    } else {
        if (compare_element(element, noeud->info) > 0) {
            return rechercherElementRecursif(noeud->filsDroit, element);
        } else if (compare_element(element, noeud->info) < 0) {
            return rechercherElementRecursif(noeud->filsGauche, element);
        } else
            return 1;
    }

}

int rechercherElementDansAvl(const Avl *avl, Element element) {
    return rechercherElementRecursif(avl->racine, element);
}


const char SEPARATEUR[3] = "->";
/**<  Separateur des noeuds pour graphviz */

static int idnumer = 0;

/**<   Identification des noeuds null */

static void afficherNoeud(const Noeud *noeud, FILE *file) {
    fprintf(file, "%d", noeud->info);
    fprintf(file, SEPARATEUR);
    fprintf(file, "{");
    if (noeud->filsGauche != NULL || noeud->filsDroit != NULL) {

        if (noeud->filsGauche != NULL)
            fprintf(file, "%d", noeud->filsGauche->info);
        else
            fprintf(file, "id%d [shape=point]", idnumer++);
        fprintf(file, " ");
        if (noeud->filsDroit != NULL)
            fprintf(file, "%d", noeud->filsDroit->info);
        else
            fprintf(file, "id%d [shape=point]", idnumer++);
    }


    fprintf(file, "};\n");
}

/**
 * @brief Crée un noeud avec element comme info
 * @fn static Noeud *creerNoeud(Element element)
 */
static Noeud *creerNoeud(Element element) {
    Noeud *n = malloc(sizeof(Noeud));
    n->info = element;
    n->filsDroit = NULL;
    n->filsGauche = NULL;

    return n;
}


static void afficherDigraphRecursif(const Noeud *noeud, FILE *file) {
    if (noeud != NULL) {
        afficherNoeud(noeud, file);
        afficherDigraphRecursif(noeud->filsGauche, file);
        afficherDigraphRecursif(noeud->filsDroit, file);
    }
}


static void testamentRecursif(Noeud *noeud) {
    if (noeud != NULL) {
        testamentRecursif(noeud->filsDroit);
        testamentRecursif(noeud->filsGauche);
        free(noeud);
    }
}

/**
 * Methodé récursive faisant l'insertion dans l'arbre
 */
static void insertion(Noeud **pNoeud, Element element) {
    if (*pNoeud == NULL) {
        *pNoeud = creerNoeud(element);
    } else {
        if (compare_element(element, (*pNoeud)->info) > 0) { // element > info => on va à droite

            insertion(&((*pNoeud)->filsDroit), element);

        } else if (compare_element(element, (*pNoeud)->info) < 0) { //element < info => on va à gauche
            insertion(&((*pNoeud)->filsGauche), element);
        }
    }
}

static void rotationRecursif(Noeud **noeud) {

    if (*noeud != NULL) {

        int hauteurGauche = calculHauteur((*noeud)->filsGauche);
        int hauteurDroit = calculHauteur((*noeud)->filsDroit);


        if (hauteurGauche - hauteurDroit > 1) { // déséquilibré vers la gauche => rotation vers la droite
            if (hauteurGauche - hauteurDroit == 2) {
                if ((*noeud)->filsGauche->filsDroit != NULL) {
                    (*noeud)->filsGauche = rotationGauche((*noeud)->filsGauche);
                }
            }
            *noeud = rotationDroite(*noeud);
        } else if (hauteurDroit - hauteurGauche > 1) { // déséquilibré vers la droite => rotation vers la gauche
            if (hauteurDroit - hauteurGauche == 2) {
                if ((*noeud)->filsDroit->filsGauche != NULL) {
                    (*noeud)->filsDroit = rotationDroite((*noeud)->filsDroit);
                }
            }
            *noeud = rotationGauche(*noeud);
        }

        rotationRecursif(&(*noeud)->filsDroit);
        rotationRecursif(&(*noeud)->filsGauche);

    }
}

static void rotationAvl(Avl *avl) {
    rotationRecursif(&avl->racine);
}


/**
 * Fonction de rotation droite
 */
static Noeud *rotationDroite(Noeud *racine) {
    Noeud *nouvelleRacine;
    nouvelleRacine = racine->filsGauche;
    racine->filsGauche = nouvelleRacine->filsDroit;
    nouvelleRacine->filsDroit = racine;
    return nouvelleRacine;

}

/*Fonction de rotation gauche*/
static Noeud *rotationGauche(Noeud *racine) {
    Noeud *nouvelleRacine;
    nouvelleRacine = racine->filsDroit;
    racine->filsDroit = nouvelleRacine->filsGauche;
    nouvelleRacine->filsGauche = racine;
    return nouvelleRacine;
}


static int calculHauteur(Noeud *noeud) {
    if (noeud == NULL)
        return 0;
    else return 1 + MAX(calculHauteur(noeud->filsDroit), calculHauteur(noeud->filsGauche));
}