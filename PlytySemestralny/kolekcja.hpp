#ifndef _KOLEKCJA
#define _KOLEKCJA

#include <fstream>
#include "plyty.hpp"

class Kolekcja
{
 private:
  std::vector<Nosnik*> lista; //Nosnik jest typem abstakcyjnym, więc nie można tworzyć jego obiektów, stąd wskaźnik. Zarówno CD jak CC dziedziczą po Nosniku, więc można je w ten sposób przechowywać w liście.
 public:
  Kolekcja(){};
  ~Kolekcja(); //będziemy używać new, wiec musimy zdefiniować własny destruktor.
  Kolekcja(const Kolekcja& kopia); //nie przewiduję kopiowania kolekcji, ale skoro używam wskaźników, to lepiej to zdefiniować
  Kolekcja& operator=(const Kolekcja& kopia); //jak wyżej

  int Dodaj(Nosnik* nowy); //dodaje nowy element w odpowiednim miejscu
  int Dodaj(const std::string& tytul, const std::string& czas, const std::string& wykonawca, const std::string& rok, const vUtwory& u); //tworzy nowy cd a potem wywoluje Dodaj
  int Dodaj(const std::string& tytul, const std::string& czas, const std::string& wykonawca, const std::string& rok, const vUtwory& a, const vUtwory& b); //jak wyżej
  void Usun(int i);
  void Wczytaj(const char* sciezka);
  void Zapisz(const char* sciezka) const;
  Nosnik* operator [](int i);
  int Size() const;
};

#endif
