#ifndef GRAPHE_H
#define GRAPHE_H
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "sommet.h"
#include "arrete.h"


class graphe
{
    public:
        ///constructeur qui charge le graphe en mémoire
        //format du fichier ordre/liste des sommets/taille/liste des arêtes
        graphe(std::string,std::string);
        ~graphe();
        void afficher() const;
       //void Prim();
    protected:

    private:
        /// Le réseau est constitué d'une collection de sommets
        std::unordered_map<int, Sommet*> m_sommets;//stockée dans une map (clé=id du sommet, valeur= pointeur sur le sommet)
        std::unordered_map<int, Arrete*> m_arretes;
};

#endif // GRAPHE_H
