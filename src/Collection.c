#include <stdlib.h>
#include "Collection.h"
#include "Avl.h"

void initialiserCollection(Collection *collection)
{


#ifdef AVL
    collection->racine = (Avl*) malloc(sizeof(Avl));
    initialiserAvl(collection->racine);
#else
    // TODO : initialiserArn(a->racine)
#endif

}



void testamentCollection(Collection *collection)
{
#ifdef AVL
    testamentAvl((Avl*)collection->racine);
    free(collection->racine);
#else
    // TODO : testamentArn((Avl*)collection->racine);
#endif

}

void insererElementDansCollection(Collection *pos, Element val) {
#ifdef AVL
    insererElementDansAvl(pos->racine, val);
#else
    // TODO : insererElementDansArn(pos->racine, val);
#endif
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

*/




int rechercherElement(const Collection const *collection, Element element) {
#ifdef AVL
    return rechercherElementDansAvl((Avl*)collection->racine,element);
#else
    // TODO :
    return 0;

#endif
}
