#include <iostream>
#include <queue>
#include <stack>
#include<unordered_map>
#include<unordered_set>
#include "arrete.h"

Arrete::Arrete(int id,float x,float y): m_id{id},m_x{x},m_y{y}
{
}

 void Arrete ::afficherData2() const{
     std::cout<<"    "<<m_id<<" : "<<"(poids1,poids2)=("<<m_x<<","<<m_y<<")"<<std::endl;
 }

Arrete::~Arrete()
{
   //dtor
}
