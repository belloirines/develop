#include <fstream>
#include <iostream>
#include "graphe.h"
#include "arrete.h"


graphe::graphe(std::string nomFichier, std::string nomFichier2){

    std::ifstream ifs{nomFichier};

    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    int ordre;
    ifs >> ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    int id;
    double x,y;
    //lecture des sommets
    for (int i=0; i<ordre; ++i){
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture donn�es sommet");
        ifs>>x; if(ifs.fail()) throw std::runtime_error("Probleme lecture donn�es sommet");
        ifs>>y; if(ifs.fail()) throw std::runtime_error("Probleme lecture donn�es sommet");
        m_sommets.insert({id,new Sommet{id,x,y}});
    }

    int taille;
    ifs >> taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
    int id_voisin, arrete;
    //lecture des aretes
    for (int i=0; i<taille; ++i){
        //lecture des ids des deux extr�mit�s
        ifs>>arrete; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 1");
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 1");
        ifs>>id_voisin; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 2");
        //ajouter chaque extr�mit� � la liste des voisins de l'autre (graphe non orient�)
        (m_sommets.find(id))->second->ajouterVoisin((m_sommets.find(id_voisin))->second);
        (m_sommets.find(id_voisin))->second->ajouterVoisin((m_sommets.find(id))->second);//remove si graphe orient�
    }
    ifs.close();

    std::ifstream ifs2{nomFichier2};
    if (!ifs2)
    throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    int nbre_poids;
    float poids1, poids2;
    ifs2 >> taille;
    ifs2 >> nbre_poids;
        if ( ifs2.fail() )
        throw std::runtime_error("Probleme lecture nombre du graphe");
    for (int i=0; i<taille; ++i){
     ifs2 >>arrete; if(ifs2.fail()) throw std::runtime_error("Probleme lecture arete sommet 1");
     ifs2 >>poids1;
     ifs2 >>poids2;
     m_arretes.insert({arrete, new Arrete{arrete,poids1,poids2}});
    }
}


void graphe::afficher() const
{
    size_t vecSize;
    size_t vecSize2;
    vecSize=m_sommets.size();
    vecSize2=m_arretes.size();

    std::cout<<"graphe : "<<std::endl;
    std::cout<<"  Ordre: "<<vecSize<<std::endl;

    for ( const auto elem : m_sommets)
    {
        std::cout<<"  Sommet:  ";
        elem.second->afficherData();
        elem.second->afficherVoisins();
        std::cout<<" "<<std::endl;

    }
        std::cout<<" nombre d'arrete : "<<vecSize2<<std::endl;
        std::cout<<"  poids:  "<<std::endl;
        for ( const auto elem2 : m_arretes)
        {
            elem2.second->afficherData2();
        }
}

/*void affichage(std::vector<int> Prim)
{
    for(size_t i=0;i<Prim.size();i++)
    {
        std::cout<<"Sommet: "<<Prim[i]<<std::endl;
    }
}

void graphe::Prim()
{
    int minimum=99;
    std::vector<int> prim;
    int nom= 3;
    int temp;
    int ajout;
    Sommet*temporaire1;
    Sommet*temporaire2;

    for(const auto& elem : m_sommets)
    {
      if(elem.first==nom)
      {
        elem.second->setMarque();
        prim.push_back(elem.first);
        ajout=ajout+1;
      }
    }
    nom= 1;
    for(const auto& elem : m_sommets)
    {
      if(elem.first==nom)
      {
        elem.second->setMarque();
        prim.push_back(elem.first);
        ajout=ajout+1;
      }
    }
    nom=2;
    for(const auto& elem : m_sommets)
    {
      if(elem.first==nom)
      {
        elem.second->setMarque();
        prim.push_back(elem.first);
        ajout=ajout+1;
      }
    }

    do{
        for(const auto& v : m_arretes)
        {
            if(((v->getDepart()->getMarque()==true)&&(v->getArrivee()->getMarque()==false))||((v->getDepart()->getMarque()==false)&&(v->getArrivee()->getMarque()==true)))
            {
                if(minimum>v->getPoids())
                {
                    minimum=v->getPoids();
                    temporaire2=v->getDepart();
                    temporaire1=v->getArrivee();
                }
            }
       }
    if(temporaire1->getMarque()==false)
    {
        temporaire1->setMarque();
        prim.push_back(temporaire1->getID());
        ajout=ajout+1;
    }
    if(temporaire2->getMarque()==false)
    {
    temporaire2->setMarque();
    prim.push_back(temporaire2->getID());
    ajout=ajout+1;
    }
      minimum=99;

    }while(ajout<m_sommets.size()-1);
    affichage(prim);
}
*/
graphe::~graphe()
{
    //dtor
}
