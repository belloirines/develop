#include <iostream>
#include <stdlib.h>
#include "graphe.h"

int main()
{
    int i=0;
    std::string a,b;
    std::cout << "taper le nom du fichier 1  ";
    std::cin>>a;
    std::cout<<a<<std::endl;
    std::cout << "taper le nom du fichier 2  ";
    std::cin>>b;
    std::cout<<b<<std::endl;

    graphe g{a,b};
   // g.afficher();

    std::cout << "taper 1 pour prim1 et 2 pour Prim 2: ";
    std::cin>>i;
    std::cout<<i<<std::endl;
    switch (i)
    {

    case 1:
        g.Prim1();
        break;
    case 2:
        g.Prim2();
        break;
    default:
        exit (EXIT_FAILURE);
        break;
    }

    return 0;

}


