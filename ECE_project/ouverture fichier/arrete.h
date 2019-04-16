#ifndef ARRETE_H_INCLUDED
#define ARRETE_H_INCLUDED
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Arrete
{
    public:
        ///constructeur qui re�oit en params les donn�es du sommet
        Arrete(int,float,float);
        void afficherData2() const;
        /*int getPoids1();
        int getPoids2();*/
        ~Arrete();

    protected:

    private:
        /// Donn�es sp�cifiques du sommet
        int m_id; // Identifiant
        float m_x, m_y; // Position

};


#endif // ARRETE_H_INCLUDED
