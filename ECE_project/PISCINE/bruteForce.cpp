#include "math.h"
#include "Bruteforce.h"
#include <iostream>

Bruteforce::Bruteforce(std::string bin)
{

}

void Bruteforce::Binary()
{
    //std::vector<char> m_binaire;
     std::vector<std::string> m_binaires;
    int n;
    int compt;
    for (int i=0; i<=pow(2,5); i++)///2^nb arretes
    {
        n=i;
        std::string r;
        while(n!=0)
        {
            r=(n%2==0 ?"0":"1")+r;
            n/=2;
        }

        for(std::string::size_type i = 0; i < r.length(); ++i)
        {
            char c = r[i];
            if (c=='1')
            {
                compt++;
            }
        }

        if(compt==4-1)///nb sommet -1
        {
            m_binaires.push_back({r});
            std::cout<<r<<std::endl;
        }
        compt=0;
        //m_binaire.insert({r});
        m_binaires.push_back({r});
    }
    algo(m_binaires);
}

void Bruteforce::algo(std::vector<std::string> binaires)
{

}
