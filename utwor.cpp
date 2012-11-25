#include "utwor.hpp"

using std::string;

Utwor::Utwor(const string& linia)
{
  int i;
  char n=0;
  string t="";
  string c="";

  for(i=0;linia[i]!=';';++i)
    {
      n*=10;
      n+=linia[i]-'0';
    }

  for(++i;linia[i]!=';';++i)
    t+=linia[i];

  for(++i;linia[i]!=';';++i)
    c+=linia[i];


  if(n==0)
    throw "Zły numer utworu";
  numer=n;

  if(t=="")
    throw "Pusta nazwa utworu";
  tytul=t;

  czas=Str2Czas(c);
}

Utwor::Utwor(char n, const string& t, const string& c)
{
  if(n==0)
    throw "Zły numer utworu";
  numer=n;

  if(t=="")
    throw "Pusta nazwa utworu";
  tytul=t;

  czas=Str2Czas(c);
}

string Utwor::Czas() const
{
  return Int2Czas(czas);
}

ushort Utwor::CzasLiczba() const
{
  return czas;
}

string Utwor::Tytul() const
{
  return tytul;
}

int Utwor::Numer() const
{
  return numer;
}

string Utwor::Zapis() const
{
  return Int2Str(numer)+";"+tytul+";"+Czas()+";";
}

string Utwor::Szczegoly() const
{
  return Int2Str(numer)+" "+tytul+" "+Czas();
}
