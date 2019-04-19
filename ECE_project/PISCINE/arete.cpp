#include "arete.h"
#include <iostream>

Arrete::Arrete(int ida, Sommet* s1,Sommet* s2,float p1, float p2):ida {ida},depart{s1},arrivee{s2},poids1{p1},poids2{p2},marque{false}
{
}

int Arrete::getida()
{
    return ida;
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

bool Arrete::getMarqueA()
 {
     return marque;
 }

 void Arrete::setMarqueA()
 {
     marque=true;
 }

 void Arrete::setMarqueA2()
 {
     marque=false;
 }
