#include <stdio.h>
#include <stdlib.h>
#include "Collection.h"


void initialiserCollection(Collection* a) {

    /*noeud * n = new
    noeud;

    n->c = N;

    n->info = e;
    n->fg = NULL;
    n->fd = NULL;
    n->pere = NULL;

    a.racine = n;*/

}


/* fonction d'affichage arbre rouge noir




static void print_internal(const noeud * node, int height, int code) {
  int width = 5;
  int w;
  if(node) {
    print_internal(node->fd, height+1, code*2+1);
    int i ;
    for(i = 0; i < height-1; ++i) {
      if(((code >> (height-i-1)) & 1 ) != ((code >> (height-i-2)) & 1)) {
        printf(V_BRANCH);
      } else {
        printf(" ");
      }
      for(w = 0; w < width; ++w) {
        printf(" ");
      }
    }
    if(code%2) {
      printf(UPPER_BRANCH);
    } else {
      if(height) {
        printf(LOWER_BRANCH);
      }
    }
    if(node->color == RED) {
      printf(COLOR_RED);
    }
    if(height) {
      for(w = 0; w < width; ++w) {
        printf(H_BRANCH);
      }
    }
    printf(SPLIT) ;
    printf(COLOR_CLEAR);
    printf(node->info);
    printf("\n");
    print_internal(node->fg, height+1, code*2);
  }
}

void rbtree_print(const arbre & tree) {
  print_internal(tree.racine, 0, 0);
}






/*		initialisationCollection(a,e);
	}
	else
	{
		On cree le noeud
		nn = new noeud;
		nn->info = e;
		nn->c = R;
		nn->fg = NULL;
		nn->fd = NULL;
		nn->pere = NULL;

		p = r;
	while(p != NULL && (p->fg != NULL || p->fd != NULL)){
        if(compare_element(e,p->info)<0){
            pp=p;
            p = p->fg;
        }
        else{
            pp = p;
            p = p->fd;
        }
}


    on effectue les rotations 5 cas possible
		if(p == NULL && pp->fd == NULL)/**on sait que pp->info < e**
		{
			printf("TEST %d\n",pp->pere->info);
			nn->pere = pp;
			pp->fd = nn;
			if(pp->c == R)
			{
				rotationGauche(pp);
				pp->c = N;
			}
		}
		else if(p == NULL && pp->fg == NULL)
		{
			nn->pere = pp;
			pp->fg = nn;
			if(pp->c == R)
			{
				rotationDroite(pp);
				pp->c = N;
			}
		}
		else if(p->c == N && p->fg == NULL && p->fd == NULL)
		{
			if(compare_e(e,p->info)<0)
			{
				nn->pere = p;
				p->fg = nn;
			}
			else



*/





