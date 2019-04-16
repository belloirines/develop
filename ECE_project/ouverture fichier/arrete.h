#ifndef ARRETE_H_INCLUDED
#define ARRETE_H_INCLUDED
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Arrete
{
    public:
        ///constructeur qui reçoit en params les données du sommet
        Arrete(int,float,float);
        void afficherData2() const;
        /*int getPoids1();
        int getPoids2();*/
        ~Arrete();

    protected:

    private:
        /// Données spécifiques du sommet
        int m_id; // Identifiant
        float m_x, m_y; // Position

};


#endif // ARRETE_H_INCLUDED
