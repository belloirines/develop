#include <iostream>
#include "graphe.h"


int main()
{
    graphe g{"sommet_essai.txt", "arrete_essai.txt"};
    g.afficher();

    return 0;
}
