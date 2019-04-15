#include <fstream>
#include <iostream>
#include "graphe.h"


graphe::graphe(std::string nomFichier, std::string nomFichier2){

    std::ifstream ifs{nomFichier};
    std::ifstream ifs2{nomFichier};
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
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>x; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>y; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        m_sommets.insert({id,new Sommet{id,x,y}});
    }

    int taille;
    ifs >> taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
    int id_voisin, arrete;
    //lecture des aretes
    for (int i=0; i<taille; ++i){
        //lecture des ids des deux extrémités
        ifs>>arrete; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 1");
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 1");
        ifs>>id_voisin; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 2");
        //ajouter chaque extrémité à la liste des voisins de l'autre (graphe non orienté)
        (m_sommets.find(id))->second->ajouterVoisin((m_sommets.find(id_voisin))->second);
        (m_sommets.find(id_voisin))->second->ajouterVoisin((m_sommets.find(id))->second);//remove si graphe orienté
    }
    ifs.close();

    int nbre_poids;
    float poids1, poids2;
    ifs2 >> taille >> nbre_poids;
        if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture nombre du graphe");
    for (int i=0; i<taille; ++i){
     ifs2 >>arrete; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 1");
     ifs2 >>poids1;
     ifs2 >>poids2;
    m_arretes.insert({new Arrete{arrete,poids1,poids2}});

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
        std::cout<<"  arrete n: "<<vecSize2<<std::endl;
        std::cout<<"  poids:  ";
}

graphe::~graphe()
{
    //dtor
}
