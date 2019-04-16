#include "Sommet.h"
#include <iostream>

Sommet::Sommet(int id):m_id{id},marque{false}
{
}
/*
void Sommet::ajouterVoisin(const Sommet* voisin){
    m_voisins.push_back(voisin);
}
*/
 void Sommet::afficherData() const{
     std::cout<<"    "<<m_id<<"  "<<marque<<std::endl;
 }

 bool Sommet::getMarque()
 {
     return marque;
 }

 void Sommet::setMarque()
 {
     marque=true;
 }

 int Sommet::getID()
 {
     return m_id;
 }


/*
void Sommet::afficherVoisins() const{
    std::cout<<"  voisins :"<<std::endl;
    for(auto v:m_voisins) {
        v->afficherData();
    }
}
*/
