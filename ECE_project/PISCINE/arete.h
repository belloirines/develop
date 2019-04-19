#ifndef ARRETE_H_INCLUDED
#define ARRETE_H_INCLUDED

#include "Sommet.h"

class Arrete
{
    public:
        ///constructeur qui reçoit en params les données du sommet
        Arrete(int,Sommet*,Sommet*,float,float);
        //~Arrete();
        void afficherArrete() const;
        int getida();
        Sommet* getDepart();
        Sommet* getArrivee();
        void setMarqueA();
        void setMarqueA2();
        bool getMarqueA();
        float getPoids1();
        float getPoids2();

    protected:

    private:
        int ida;
        Sommet* depart;
        Sommet* arrivee;
        float poids1;
        float poids2;
        bool marque;
};

#endif // ARRETE_H_INCLUDED
