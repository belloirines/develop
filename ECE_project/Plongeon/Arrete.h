#ifndef ARRETE_H_INCLUDED
#define ARRETE_H_INCLUDED

#include "Sommet.h"

class Arrete
{
    public:
        ///constructeur qui re�oit en params les donn�es du sommet
        Arrete(Sommet*,Sommet*,float,float);
        //~Arrete();
        void afficherArrete() const;
        Sommet* getDepart();
        Sommet* getArrivee();
        float getPoids1();
        float getPoids2();

    protected:

    private:
        Sommet* depart;
        Sommet* arrivee;
        float poids1;
        float poids2;
};

#endif // ARRETE_H_INCLUDED
