#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED
#include <random>
#include <string>

namespace util
{
void startAutoCin(std::string fileName, size_t temporisation=0, short couleur=0);

void stopAutoCin();

void videCin();

int alea(int min, int max);

int alea(int min, int max, std::mt19937& randGen);
double alea(double min, double max, std::mt19937& randGen);

#ifdef _WIN32
void accentsPourWindows();
#endif // _WIN32

}


#endif // UTIL_H_INCLUDED
