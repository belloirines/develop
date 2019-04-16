#include "Arrete.h"
#include <iostream>

Arrete::Arrete(Sommet* s1,Sommet* s2,float p1, float p2):depart{s1},arrivee{s2},poids1{p1},poids2{p2}
{
}

void Arrete::afficherArrete() const
{
    depart->afficherData();
    arrivee->afficherData();
    std::cout<<"    "<<poids1<<std::endl;
    std::cout<<"    "<<poids2<<std::endl;
    std::cout<<"--------------------------------------------"<<std::endl;
}

Sommet* Arrete::getDepart()
{
    return depart;
}

Sommet* Arrete::getArrivee()
{
    return arrivee;
}

float Arrete::getPoids1()
{
    return poids1;
}

float Arrete::getPoids2()
{
    return poids2;
}
