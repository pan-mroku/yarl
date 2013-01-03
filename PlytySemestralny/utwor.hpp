#ifndef _UTWOR
#define _UTWOR

#include <string>
#include <vector>
#include "utils.hpp"

class Utwor
{
 private:
  char numer;
  std::string tytul;
  ushort czas;

 public:
  Utwor(const std::string& linia); //używany o wczytywania utworów z pliku
  Utwor(char n, const std::string& t, const std::string& c); //zwykły konstruktor
  std::string Czas() const;
  ushort CzasLiczba() const;
  std::string Tytul() const;
  int Numer() const;
  std::string Zapis() const; //do zapisywania utworów do pliku
  std::string Szczegoly() const; //do wyświetlania
};

typedef std::vector<Utwor> vUtwory;

#endif

