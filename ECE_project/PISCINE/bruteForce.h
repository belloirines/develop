#ifndef BRUTEFORCE_H_INCLUDED
#define BRUTEFORCE_H_INCLUDED

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Bruteforce
{
    public:
        ///
        Bruteforce(std::string);
        //
        void Binary();
        void algo(std::vector<std::string>);

    protected:

    private:
        //std::unordered_map<std::string> m_binaire;
        std::vector<std::string> m_binaires;
        std::string m_bin;
};


#endif // BRUTEFORCE_H_INCLUDED
