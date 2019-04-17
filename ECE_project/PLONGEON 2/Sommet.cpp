#include "Sommet.h"
#include <iostream>

Sommet::Sommet(int cx, int cy,int id):m_cx{cx},m_cy{cy},m_id{id},marque{false}
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

 int Sommet::getcx()
 {
     return m_cx;
 }

 int Sommet::getcy()
 {
     return m_cy;
 }


/*
void Sommet::afficherVoisins() const{
    std::cout<<"  voisins :"<<std::endl;
    for(auto v:m_voisins) {
        v->afficherData();
    }
}
*/
