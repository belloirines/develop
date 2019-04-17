#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include <string>
#include <unordered_map>
#include "sommet.h"
#include "arrete.h"



class graphe
{
    public:
        graphe(std::string,std::string);
        //~graphe();
        void afficher() const;
        void affichage(std::vector<int>,std::vector<int>,std::vector<int>,std::vector<int>,std::vector<int>);
        void Prim1();
        void Prim2();

    protected:

    private:
        /// Le réseau est constitué d'une collection de sommets
        std::unordered_map<int,Sommet*> m_sommets;//stockée dans une map (clé=id du sommet, valeur= pointeur sur le sommet)
        std::vector<Arrete*> m_arrete;

};

#endif // GRAPHE_H_INCLUDED
