#ifndef _UTILS
#define _UTILS

#include <string>

typedef unsigned short ushort;

std::string Int2Str(int a);  //zamiana int na string za pomocą stringstream
ushort Str2Czas(const std::string& c); //zamiana czasu w formacie (hh:)mm:ss na liczbę sekund. Referencja, żęby było szybciej
std::string Int2Czas(int c); //zamiana liczby sekund na powyższy format

#endif
