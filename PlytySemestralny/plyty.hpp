#ifndef _PLYTY
#define _PLYTY

#include "utwor.hpp"

class Nosnik
{
 protected:
  std::string tytul;
  bool typ; //0- kaseta 1- cd
  ushort czas;
  std::string wykonawca;
  std::string rok;

  Nosnik(const std::string& t, bool n, const std::string& c, const std::string& w, const std::string& r);

 public:
  virtual std::string Zapis() const=0; //funkcja do zapisywania nośnika w pliku
  virtual std::string Szczegoly() const=0; //funkcja do wyświetlania dokładnych informacji o nosniku

  std::string Tytul() const;
  std::string Typ() const;
  bool TypBool() const;
  std::string Czas() const;
  ushort CzasLiczba() const;
  std::string Wykonawca() const;
  std::string Rok() const;
  std::string Opis() const;
  bool operator >(Nosnik& prawy) const;
  bool operator <(Nosnik& prawy) const;
  bool operator >=(Nosnik& prawy) const;
  bool operator <=(Nosnik& prawy) const;
  bool operator ==(Nosnik& prawy) const;
};

//----------------------------------------------------------------------------

class CD: public Nosnik //zachowujemy zasady dostępu (protected, public) takie jak w klasie bazowej
{
 private:
  vUtwory utwory;
 public:
 CD(const std::string& t, const std::string& c, const std::string& w, const std::string& r, const vUtwory& u);
 std::string Zapis() const;
 std::string Szczegoly() const;
 const vUtwory& Utwory() const;
};

//-----------------------------------------------------------------------------

class CC: public Nosnik
{
 private:
  vUtwory strona_a;
  vUtwory strona_b;
  ushort czas;
 public:
  CC(const std::string& t, const std::string& c, const std::string& w, const std::string& r, const vUtwory& a, const vUtwory& b);
  std::string Zapis() const;
  std::string Szczegoly() const;
  const vUtwory& StronaA() const;
  const vUtwory& StronaB() const;
};

#endif
