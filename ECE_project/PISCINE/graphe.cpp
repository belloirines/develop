#include "graphe.h"
#include "svgfile.h"
#include "util.h"
#include <fstream>
#include <iostream>

graphe::graphe(std::string nomFichier,std::string nomFichier2){
    std::ifstream ifs{nomFichier};
    std::ifstream ifs2{nomFichier2};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    if (!ifs2)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier2 );
    int ordre;
    ifs >> ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    int id,c1,c2;
    //lecture des sommets
    for (int i=0; i<ordre; ++i){
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>c1; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>c2; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        m_sommets.insert({id,new Sommet{c1,c2,id}});
    }

    int taille,taille1,colonne;
    ifs >> taille;
    ifs2 >> taille1;
    ifs2>>colonne;

    if ( taille!=taille1)
        throw std::runtime_error("Probleme lecture taille du graphe");
    int arrivee,ida;
    int depart;
    float poids1,poids2;
    //lecture des aretes
    for (int i=0; i<taille; ++i){
        //lecture des ids des deux extrémités
        ifs>>ida; if(ifs.fail()) throw std::runtime_error("Probleme lecture identification arrete 1");
        ifs>>depart; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 1");
        ifs>>arrivee; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 2");
        ifs2>>ida; if(ifs2.fail()) throw std::runtime_error("Probleme identification arrete");
        ifs2>>poids1; if(ifs2.fail()) throw std::runtime_error("Probleme lecture poids1");
        ifs2>>poids2; if(ifs2.fail()) throw std::runtime_error("Probleme lecture poids2");
        m_arrete.push_back({new Arrete{ida,m_sommets.find(depart)->second,m_sommets.find(arrivee)->second,poids1,poids2}});
       // (m_sommets.find(depart))->second->ajouterVoisin((m_sommets.find(arrivee))->second);
    }
}

void graphe::affichage(std::vector<int> Prim,std::vector<int> parlarrete,std::vector<int> venantde,std::vector<int> coord1,std::vector<int> coord2,std::vector<int> nv1,std::vector<int> nv2,std::vector<int>poids)
{
    int l=0;
    Svgfile svgout;

    for(size_t i=0;i<Prim.size();i++)
    {
        std::cout<<"Sommet: "<<Prim[i]<<"  de coord :   "<<coord1[i]<<";"<<coord2[i]<< "   venant de  "<<venantde[i]<<"  par l'arrete  "<<parlarrete[i]<<" de poids:  "<<poids[i]<<std::endl;
        l=l+poids[i];
        svgout.addCircle(coord1[i],coord2[i],5,10,"black");
        svgout.addLine(coord1[i],coord2[i],nv1[i],nv2[i],"red");
        //svgout.addLine(nv1[i],nv2[i],coord1[i],coord2[i],"green");
        //svgout.addText()
        svgout.addText(coord1[i]+5,coord2[i]-15,Prim[i],"black");
    }
    svgout.addText(50,50,"Poids de l'arbre de poids minimum :","red");
    svgout.addText(285,50,l,"red");

    std::cout<<"poids total de l'arbre :   "<<l<<std::endl;
}


void graphe::afficher() const
{
    for(const auto& elem : m_sommets)
    {
        elem.second->afficherData();
    }

    for(const auto& v : m_arrete)
    {
        v->afficherArrete();
    }
}


void graphe::Prim1()
{
    int minimum=99;
    std::vector<int> prim;
    std::vector<int> coord1;
    std::vector<int> coord2;
    std::vector<int> nv1;
    std::vector<int> nv2;
    std::vector<int> poids1;
    std::vector<int> parlarret;
    std::vector<int> venantde;
    int ajout=0;
    int tmp0,tmp;
    Sommet*tmp1;
    Sommet*tmp2;

    for(const auto& elem : m_sommets)
    {
        if(elem.first==0)
      {
        elem.second->setMarque();
        coord1.push_back(elem.second->getcx());
        coord2.push_back(elem.second->getcy());
        nv1.push_back(elem.second->getcx());
        nv2.push_back(elem.second->getcy());
        poids1.push_back(elem.first);
        prim.push_back(elem.first);
        parlarret.push_back(elem.first);
        venantde.push_back(elem.first);
        ajout=ajout+1;
      }

    }

    do{
        for(const auto& v : m_arrete)
        {

            if(((v->getDepart()->getMarque()==true)&&(v->getArrivee()->getMarque()==false))||((v->getDepart()->getMarque()==false)&&(v->getArrivee()->getMarque()==true)))
            {
                if(minimum>v->getPoids1())
                {
                    minimum=v->getPoids1();
                    tmp0=v->getida();
                    tmp2=v->getDepart();
                    tmp1=v->getArrivee();
                }
            }
        }

        if(tmp1->getMarque()==false)
        {
            tmp1->setMarque();
            prim.push_back(tmp1->getID());
            parlarret.push_back(tmp0);
            venantde.push_back(tmp2->getID());
            poids1.push_back(minimum);
            coord1.push_back(tmp1->getcx());
            coord2.push_back(tmp1->getcy());
            nv1.push_back(tmp2->getcx());
            nv2.push_back(tmp2->getcy());
            ajout=ajout+1;
        }
        if(tmp2->getMarque()==false)
        {
            tmp2->setMarque();
            prim.push_back(tmp2->getID());
            parlarret.push_back(tmp0);
            venantde.push_back(tmp1->getID());
            poids1.push_back(minimum);
            coord1.push_back(tmp2->getcx());
            coord2.push_back(tmp2->getcy());
            nv1.push_back(tmp1->getcx());
            nv2.push_back(tmp1->getcy());
            ajout=ajout+1;
        }
        minimum=99;

    }while(ajout<m_sommets.size());
    affichage(prim,parlarret,venantde,coord1,coord2,nv1,nv2,poids1);
}

void graphe::Prim2()
{
    int minimum=99;
    std::vector<int> prim;
    std::vector<int> coord1;
    std::vector<int>coord2;
    std::vector<int> nv1;
    std::vector<int>nv2;
    std::vector<int> poids2;
    std::vector<int> parlarret;
    std::vector<int> venantde;
    int ajout=0;
    int tmp0;
    Sommet*tmp1;
    Sommet*tmp2;
    Sommet*tmp3;

    for(const auto& elem : m_sommets)
    {
        if(elem.first==0)
      {
        coord1.push_back(elem.second->getcx());
        coord2.push_back(elem.second->getcy());
        nv1.push_back(elem.second->getcx());
        nv2.push_back(elem.second->getcy());
        poids2.push_back(elem.first);
        elem.second->setMarque();
        parlarret.push_back(elem.first);
        venantde.push_back(elem.first);
        prim.push_back(elem.first);
        ajout=ajout+1;
      }

    }

    do{
        for(const auto& v : m_arrete)
        {
            if(((v->getDepart()->getMarque()==true)&&(v->getArrivee()->getMarque()==false))||((v->getDepart()->getMarque()==false)&&(v->getArrivee()->getMarque()==true)))
            {
                if(minimum>v->getPoids2())
                {
                    minimum=v->getPoids2();
                    tmp0=v->getida();
                    tmp2=v->getDepart();
                    tmp1=v->getArrivee();
                }
            }
        }

        if(tmp1->getMarque()==false)
        {
            tmp1->setMarque();
            prim.push_back(tmp1->getID());
            parlarret.push_back(tmp0);
            venantde.push_back(tmp2->getID());
            poids2.push_back(minimum);
            coord1.push_back(tmp1->getcx());
            coord2.push_back(tmp1->getcy());
            nv1.push_back(tmp2->getcx());
            nv2.push_back(tmp2->getcy());
            ajout=ajout+1;
        }
        if(tmp2->getMarque()==false)
        {
            tmp2->setMarque();
            parlarret.push_back(tmp0);
            prim.push_back(tmp2->getID());
            venantde.push_back(tmp1->getID());
            poids2.push_back(minimum);
            coord1.push_back(tmp2->getcx());
            coord2.push_back(tmp2->getcy());
            nv1.push_back(tmp1->getcx());
            nv2.push_back(tmp1->getcy());
            ajout=ajout+1;
        }
        minimum=99;

    }while(ajout<m_sommets.size());
   affichage(prim,parlarret,venantde,coord1,coord2,nv1,nv2,poids2);
}
