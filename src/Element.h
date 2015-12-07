#ifndef _ELEMENT
#define _ELEMENT

typedef int Element;

/**
 * @brief Affiche l'élément e
 */
void afficher_element(Element e);

/**
 * @brief Compare deux éléments.
 * Renvoie x tel que :
 * x = 0 si e1=e2,
 * x<0 si e1 < e2,
 * x >0 si e1 > e2
 */
int compare_element(Element e1, Element e2);


#endif
