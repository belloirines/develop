#ifndef SOMMET_H
#define SOMMET_H
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Sommet
{
    public:
        ///constructeur qui re�oit en params les donn�es du sommet
        Sommet(int,double,double);
        void ajouterVoisin(const Sommet*);
        void afficherData() const;
        void afficherVoisins() const;
        //void setMarque();
        //bool getMarque();
        //int getID();
        //double getDepart();
        //double getArrivee();

        ~Sommet();

    protected:

    private:
        /// Voisinage : liste d'adjacence
        std::vector<const Sommet*> m_voisins;

        /// Donn�es sp�cifiques du sommet
        int m_id; // Identifiant
        double m_x, m_y; // Position
        //bool marque;
};

#endif // SOMMET_H
