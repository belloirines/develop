#include <iostream>
#include <queue>
#include <stack>
#include<unordered_map>
#include<unordered_set>
#include "sommet.h"

Sommet::Sommet(int cx, int cy,int id):m_cx{cx},m_cy{cy},m_id{id},marque{false}
{
}

void Sommet::ajouterVoisin(const Sommet* voisin){
    m_voisins.push_back(voisin);
}
 void Sommet::afficherData() const{
     std::cout<<"    "<<m_id<<" : "<<"(x,y)=("<<m_cx<<","<<m_cy<<")"<<std::endl;
 }
void Sommet::afficherVoisins() const{
    std::cout<<"  voisins :"<<std::endl;
    for(auto v:m_voisins) {
        v->afficherData();
    }
}

int Sommet::getDegre() //on reprend le code BFS
{
    int degre;
    degre=(this->m_voisins.size());
    return degre;
}

 bool Sommet::getMarque()
 {
     return marque;
 }

 void Sommet::setMarque()
 {
     marque=true;
 }

 void Sommet::setMarque2()
 {
     marque=false;
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

 std::unordered_map<int,int> Sommet::parcoursBFS() const
{

    std::queue<const Sommet*>file; // notion de pred , on insere d'un coté et on extrait de l'autre
    std::unordered_set<const Sommet *> marque; // mettre les elements deja marqués dedans  ( si on peut fzire un file sur le marque c'est pas bien)
    std::unordered_map< int, int> l_pred;
    file.push(this); // premier sommet + on l'enfile
    marque.insert(this); // on le marque



    while (!file.empty())
    {
        const Sommet* s = file.front();
        file.pop();
        for (const auto elem : s->m_voisins) //parcourt la file
        {
            if (marque.find(elem)==marque.end())//si elem est marqué il le renvoit sinon il renvoit rien
            {
                file.push(elem);
                marque.insert(elem);
                l_pred.insert( {elem->m_id, s->m_id} ); //faire passer le précedent
            }
        }

    }
  return l_pred;
}
