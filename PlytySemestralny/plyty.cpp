#include "plyty.hpp"

using std::string;

Nosnik::Nosnik(const string& t,bool n, const string& c, const string& w, const string& r)
{
  czas=Str2Czas(c);

  if(t=="")
    throw "Pusty tytuł albumu";
  tytul=t;

  if(w=="")
    throw "Pusta nazwa artysty";
  wykonawca=w;

  if(r==""||r.size()!=4)
    throw "Zły rok wydania albumu";
  rok=r;

  typ=n;
}

string Nosnik::Tytul() const
{
  return tytul;
}

string Nosnik::Typ() const
{
  return (typ?"CD":"CC");
}

bool Nosnik::TypBool() const
{
  return typ;
}

string Nosnik::Czas() const
{
  return Int2Czas(czas);
}

ushort Nosnik::CzasLiczba() const
{
  return czas;
}

string Nosnik::Wykonawca() const
{
  return wykonawca;
}

string Nosnik::Rok() const
{
  return rok;
}

string Nosnik::Opis() const
{
  return wykonawca+" "+tytul+" "+Typ()+" "+rok+" "+Czas();
}

bool Nosnik::operator >(Nosnik& prawy) const
{
  if(wykonawca>prawy.wykonawca)
    return true;
  if(rok>prawy.rok&&wykonawca==prawy.wykonawca)
    return true;
  if(tytul>=prawy.tytul&&rok==prawy.rok&&wykonawca==prawy.wykonawca)
    return true;
  return false;
}

bool Nosnik::operator <(Nosnik& prawy) const
{
  if(wykonawca<prawy.wykonawca)
    return true;
  if(rok<prawy.rok&&wykonawca==prawy.wykonawca)
    return true;
  if(tytul<=prawy.tytul&&rok==prawy.rok&&wykonawca==prawy.wykonawca)
    return true;
  return false;
}

bool Nosnik::operator >=(Nosnik& prawy) const
{
  return !(*this<prawy);
}

bool Nosnik::operator <=(Nosnik& prawy) const
{
  return !(*this>prawy);
}

bool Nosnik::operator ==(Nosnik& prawy) const
{
  return (!(*this>prawy)&&!(*this<prawy));
}

//-----------------------------------------------------
CD::CD(const string& t, const string& c, const string& w, const string& r, const vUtwory& u):Nosnik(t,1,c,w,r)
{
  if(u.empty())
    throw "Brak utworów";

  ushort tmp=0;
  for(int i=0;i<u.size();++i)
    tmp+=u[i].CzasLiczba();
  if(tmp!=czas)
    throw "Błędny czas trwania płyty";
  utwory=u;
}

string CD::Zapis() const
{
  string wynik="";
  wynik+="1;"+tytul+";"+Czas()+";"+wykonawca+";"+rok;
  wynik+="{\n";
  for(int i=0;i<utwory.size();++i)
    wynik+=utwory[i].Zapis()+"\n";
  wynik+="}\n";
  return wynik;
}

string CD::Szczegoly() const
{
  string wynik=Opis()+"\nUtwory:\n";
  for(int i=0;i<utwory.size();++i)
    wynik+=utwory[i].Szczegoly()+"\n";
  return wynik;
}

const vUtwory& CD::Utwory() const
{
  return utwory;
}
//---------------------------------------------------------------
CC::CC(const string& t, const string& c, const string& w, const string& r, const vUtwory& a, const vUtwory& b):Nosnik(t,0,c,w,r)
{
  if(a.empty())
    throw "Pusta strona a";
  if(b.empty())
    throw "Pusta strona b";
  
  czas=Str2Czas(c); //z niewiadomych mi powodów konstruktor Nosnik wywołany wyżej nie ustawia czasu. w CD działa jednak dobrze.

  ushort tmp=0;
  for(int i=0;i<a.size();++i)
    tmp+=a[i].CzasLiczba();
  for(int i=0;i<b.size();++i)
    tmp+=b[i].CzasLiczba();

  if(tmp!=czas)
    throw "Błędny czas trwania kasety";

  strona_a=a;
  strona_b=b;
}

string CC::Zapis() const
{
  string wynik="";
  wynik+="0;"+tytul+";"+Czas()+";"+wykonawca+";"+rok;
  wynik+="{\n";
  for(int i=0;i<strona_a.size();++i)
    wynik+=strona_a[i].Zapis()+"\n";
  wynik+="}\n";
  wynik+="{\n";
  for(int i=0;i<strona_b.size();++i)
    wynik+=strona_b[i].Zapis()+"\n";
  wynik+="}\n";
  return wynik;
}

const vUtwory& CC::StronaA() const
{
  return strona_a;
}

const vUtwory& CC::StronaB() const
{
  return strona_b;
}

string CC::Szczegoly() const
{
  string wynik=Opis()+"\nStrona A:\n";
  for(int i=0;i<strona_a.size();++i)
    wynik+=strona_a[i].Szczegoly()+"\n";
  wynik+="Strona B\n";
  for(int i=0;i<strona_b.size();++i)
    wynik+=strona_b[i].Szczegoly()+"\n";
  return wynik;
}
