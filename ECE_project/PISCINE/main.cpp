#include <iostream>
#include <stdlib.h>
#include "graphe.h"
#include "svgfile.h"
#include "util.h"

int main()
{
    int i=0,j=1;
    std::string a,b;

    //Svgfile svgout;
    //svgout.addCircle(200,200,100,100,"black");


    while(j != 0)
    {
        std::cout << "taper le nom du fichier 1  ";
        std::cin>>a;
        std::cout<<a<<std::endl;
        std::cout << "taper le nom du fichier 2  ";
        std::cin>>b;
        std::cout<<b<<std::endl;

        graphe g{a,b};

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

        std::cout << "Continuer ?" << std::endl << "OUI : 1" << std::endl << "NON : 0" << std::endl;
        std::cin >> j;
    }
    return 0;
}
