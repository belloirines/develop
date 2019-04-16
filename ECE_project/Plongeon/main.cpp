#include <iostream>
#include "graphe.h"



int main()
{
    std::vector<int> prim;
    graphe g{"sommet_essai.txt","arrete_essai.txt"};
    g.afficher();
    g.Prim();
    return 0;
}


