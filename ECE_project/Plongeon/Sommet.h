#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Sommet
{
    public:
        ///constructeur qui reçoit en params les données du sommet
        Sommet(int,int,int);
        //void ajouterVoisin(const Sommet*);
        void afficherData() const;
        //void afficherVoisins() const;
        ~Sommet();
        void setMarque();
        bool getMarque();
        int getID();
        int getcx();
        int getcy();


    protected:

    private:
        /// Voisinage : liste d'adjacence
        //std::vector<const Sommet*> m_voisins;

        /// Données spécifiques du sommet
        int m_id, m_cx,m_cy; // Identifiant
        bool marque;

};

#endif // SOMMET_H_INCLUDED
