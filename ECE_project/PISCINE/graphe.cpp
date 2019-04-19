#include "graphe.h"
#include "svgfile.h"
#include "util.h"
#include <fstream>
#include"math.h"
#include <iostream>
#include<list>
#include <algorithm>

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

Arrete* graphe::getArrete(int i)
{
    return m_arrete[i];
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
        //svgout.addText()
        svgout.addText(coord1[i]+5,coord2[i]-15,Prim[i],"black");
    }
    svgout.addText(50,50,"Poids de l'arbre de poids minimum :","red");
    svgout.addText(285,50,l,"red");

    std::cout<<"poids total de l'arbre :   "<<l<<std::endl;
}


void graphe::clears()
{
    for(const auto& elem : m_sommets)
    {
        elem.second->setMarque2();

    }
}

/*void graphe::clears2()
{
    for(const auto& elem : m_sommets)
    {
        elem.second->setMarqueA2();

    }
}*/


void graphe::Prim1()
{
    int passage=100;
    std::vector<int> prim;
    std::vector<int> coord1;
    std::vector<int> coord2;
    std::vector<int> nv1;
    std::vector<int> nv2;
    std::vector<int> poids1;
    std::vector<int> parlarret;
    std::vector<int> venantde;
    int compteur=0;
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
        compteur=compteur+1;
      }

    }

    do{
        for(const auto& elem2 : m_arrete)
        {

            if(((elem2->getDepart()->getMarque()==false)&&(elem2->getArrivee()->getMarque()==true))||((elem2->getDepart()->getMarque()==true)&&(elem2->getArrivee()->getMarque()==false)))
            {
                if(passage>elem2->getPoids1())
                {
                    passage=elem2->getPoids1();
                    tmp0=elem2->getida();
                    tmp2=elem2->getDepart();
                    tmp1=elem2->getArrivee();
                }
            }
        }

        if(tmp1->getMarque()==false)
        {
            tmp1->setMarque();
            prim.push_back(tmp1->getID());
            parlarret.push_back(tmp0);
            venantde.push_back(tmp2->getID());
            poids1.push_back(passage);
            coord1.push_back(tmp1->getcx());
            coord2.push_back(tmp1->getcy());
            nv1.push_back(tmp2->getcx());
            nv2.push_back(tmp2->getcy());
            compteur=compteur+1;
        }
        if(tmp2->getMarque()==false)
        {
            tmp2->setMarque();
            prim.push_back(tmp2->getID());
            parlarret.push_back(tmp0);
            venantde.push_back(tmp1->getID());
            poids1.push_back(passage);
            coord1.push_back(tmp2->getcx());
            coord2.push_back(tmp2->getcy());
            nv1.push_back(tmp1->getcx());
            nv2.push_back(tmp1->getcy());
            compteur=compteur+1;
        }
        passage=100;

    }while(compteur<m_sommets.size());
    affichage(prim,parlarret,venantde,coord1,coord2,nv1,nv2,poids1);
}

void graphe::Prim2()
{
    int passage=99;
    std::vector<int> prim;
    std::vector<int> coord1;
    std::vector<int> coord2;
    std::vector<int> nv1;
    std::vector<int> nv2;
    std::vector<int> poids2;
    std::vector<int> parlarret;
    std::vector<int> venantde;
    int compteur=0;
    int tmp0;
    Sommet*tmp1;
    Sommet*tmp2;
    Sommet*tmp3;

    for(const auto& elem : m_sommets)
    {
        if(elem.first==0)
      {
        elem.second->setMarque();

        coord1.push_back(elem.second->getcx());
        coord2.push_back(elem.second->getcy());
        nv1.push_back(elem.second->getcx());
        nv2.push_back(elem.second->getcy());
        poids2.push_back(elem.first);
        parlarret.push_back(elem.first);
        venantde.push_back(elem.first);
        prim.push_back(elem.first);
        compteur=compteur+1;
      }

    }

    do{
        for(const auto& elem2 : m_arrete)
        {
            if(((elem2->getDepart()->getMarque()==false)&&(elem2->getArrivee()->getMarque()==true))||((elem2->getDepart()->getMarque()==true)&&(elem2->getArrivee()->getMarque()==false)))
            {
                if(passage>elem2->getPoids2())
                {
                    passage=elem2->getPoids2();
                    tmp0=elem2->getida();
                    tmp2=elem2->getDepart();
                    tmp1=elem2->getArrivee();
                }
            }
        }

        if(tmp1->getMarque()==false)
        {
            tmp1->setMarque();
            prim.push_back(tmp1->getID());
            parlarret.push_back(tmp0);
            venantde.push_back(tmp2->getID());
            poids2.push_back(passage);
            coord1.push_back(tmp1->getcx());
            coord2.push_back(tmp1->getcy());
            nv1.push_back(tmp2->getcx());
            nv2.push_back(tmp2->getcy());
            compteur=compteur+1;
        }
        if(tmp2->getMarque()==false)
        {
            tmp2->setMarque();
            parlarret.push_back(tmp0);
            prim.push_back(tmp2->getID());
            venantde.push_back(tmp1->getID());
            poids2.push_back(passage);
            coord1.push_back(tmp2->getcx());
            coord2.push_back(tmp2->getcy());
            nv1.push_back(tmp1->getcx());
            nv2.push_back(tmp1->getcy());
            compteur=compteur+1;
        }
        passage=100;

    }while(passage<m_sommets.size());
   affichage(prim,parlarret,venantde,coord1,coord2,nv1,nv2,poids2);
}

/*void graphe::arbrecouvrant(std::vector graphe)
{
    int passage=100;
    std::vector<int> prim;
    std::vector<int> coord1;
    std::vector<int> coord2;
    std::vector<int> nv1;
    std::vector<int> nv2;
    std::vector<int> poids1;
    std::vector<int> parlarret;
    std::vector<int> venantde;

    int compteur=0;
    int j=0;
    int tmp0;
    int tmp;
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
        compteur=compteur+1;
      }
    }
    do
    {
     do{
        for (i=0;)
            for(const auto& elem2 : m_arrete)
        {
        tmp=elem2->getida();
        if(getArrete(tmp)->getMarqueA()==false)
        {
            std::cout<<"Sommet: "<<tmp<<"  de coord :"<<std::endl;
            j=j+1;
            if(((elem2->getDepart()->getMarque()==false)&&(elem2->getArrivee()->getMarque()==true))||((elem2->getDepart()->getMarque()==true)&&(elem2->getArrivee()->getMarque()==false)))
            {

                if(getArrete(tmp)->getMarqueA()==false)
                {
                    passage=elem2->getPoids1();
                    tmp0=elem2->getida();
                    tmp2=elem2->getDepart();
                    tmp1=elem2->getArrivee();
                    //getArrete(tmp)->setMarqueA();


                }
            }

        }
    }

        if(tmp1->getMarque()==false)
        {
            tmp1->setMarque();
            prim.push_back(tmp1->getID());
            parlarret.push_back(tmp0);
            venantde.push_back(tmp2->getID());
            poids1.push_back(passage);
            coord1.push_back(tmp1->getcx());
            coord2.push_back(tmp1->getcy());
            nv1.push_back(tmp2->getcx());
            nv2.push_back(tmp2->getcy());
            compteur=compteur+1;
        }
        if(tmp2->getMarque()==false)
        {
            tmp2->setMarque();
            prim.push_back(tmp2->getID());
            parlarret.push_back(tmp0);
            venantde.push_back(tmp1->getID());
            poids1.push_back(passage);
            coord1.push_back(tmp2->getcx());
            coord2.push_back(tmp2->getcy());
            nv1.push_back(tmp1->getcx());
            nv2.push_back(tmp1->getcy());
            compteur=compteur+1;
        }
        passage=100;
        getArrete(tmp)->setMarqueA();
        //raphe.push_back();


    }while(compteur<m_sommets.size());
    affichage(prim,parlarret,venantde,coord1,coord2,nv1,nv2,poids1);
    clears();
    }while(j<25);

}*/
void graphe::Binary(int na)
{
    std::vector<std::vector<int>> m_binaires;
    std::vector<int> tampon;
    std::vector<int> graphe;
    std::vector<int> graphe2;
    std::vector<int> graphe3;
    std::vector<int> graphe4;
    int compteur=0, bi=2,ajout=0;
    int tmp;
    int n;

    for(int i=1;i<=pow(bi,na);i++)
    {
        n=i;
        //std::cout<<" n :"<<n<<"  ";
        int r;
        ajout=0;

        while(n!=0)
        {
            r=n%2;
            tampon.push_back(r);
            //std::cout<<r ;
            //   ==0 ?"0":"1")+r;
            n=(n-r)/2;
            ajout =ajout +1;
        }
        while(ajout<na)
        {
            tampon.push_back(0);
            ajout=ajout+1;
        }

        for (int i = 0; i < tampon.size(); i++)
        {
            if (tampon[i]==1)
            {
                compteur++;
            }
        }
        //std::cout<<"  compteur "<<compteur;


        if(compteur>3||compteur<3)
        {
            tampon.erase(tampon.begin(),tampon.end());
        }
        if(compteur==3)
        {
            std::reverse(tampon.begin(),tampon.end());
            m_binaires.push_back(tampon);
            tampon.erase(tampon.begin(),tampon.end());
        }
        compteur=0;

    }
    //std::cout<<std::endl;
    for (int x=0;x<10;x++)
    {
        for (int y=0;y<5;y++)
        {
        //std::cout<<m_binaires[x][y];


            if(m_binaires[x][y]==1)
            {
                graphe.push_back(m_arrete[y]->getDepart()->getID());
                graphe3.push_back(m_arrete[y]->getArrivee()->getID());
            }

        }
    }

    Sommet*s0=(m_sommets.find(id))->second;
    std::unordered_map<int,int> l_pred;
    l_pred=s0->parcoursBFS();

}

void graphe::afficherBFS(int id) const{
    Sommet*s0=(m_sommets.find(id))->second;
    std::unordered_map<int,int> l_pred;
    std::cout<<"parcoursBFS a partir de "<<id<<" :"<<std::endl;
    l_pred=s0->parcoursBFS();
    for(auto s:l_pred){
        std::cout<<s.first<<" <--- ";
        std::pair<std::string,std::string> pred=s;
        while(pred.second!=id){
            pred=*l_pred.find(pred.second);
            std::cout<<pred.first<<" <--- ";
        }
        std::cout<<id<<std::endl;
    }
}
