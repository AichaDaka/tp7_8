#include <stdio.h>
#include "Element.h"

void afficher_element(Element e)
{
	printf("e : %d ",e);
}

//e1 - e2 < 0 e1 < e2 etc...
int compare_element(Element e1, Element e2)
{
	return e1 - e2;
}
