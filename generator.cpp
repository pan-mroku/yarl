#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>
#include "utils.hpp"

using namespace std;

string licz[]={"zero", "pierwszy", "drugi", "trzeci", "czwarty", "piaty", "szosty", "siodmy", "osmy", "dziewiaty", "dziesiaty", "jedenasty", "dwunasty", "trzynasty", "czternasty", "pietnasty", "szesnasty", "siedemnasty", "osiemnasty", "dziewietnasty", "dwudziesty","dwudziesty pierwszy", "dwudziesty drugi", "dwudziesty trzeci", "dwudziesty czwarty", "dwudziesty piaty"};

class utwor
{
public:
  char numer;
  string tytul;
  string czas;
 
  utwor(char n,string t):numer(n),tytul(t)
  {
    ushort minuty=0,sekundy=0;
    minuty=rand()%10+1;
    sekundy=rand()%60;
    czas=Int2Str(minuty)+':'+Int2Str(sekundy);
  }

  friend  ostream& operator<<(ostream& out,const struct utwor& co);

};

ostream& operator<<(ostream& out,const utwor& co)
{
  return out<<Int2Str(co.numer)<<';'<<co.tytul<<';'<<co.czas<<';'<<endl;
}

class plyta
{
public:
  string tytul;
  string typ;
  string czas;
  string wykonawca;
  string rok;
  vector<utwor> utwory;
  vector<utwor> utwory2;

  plyta(int tyt, int wyk)
  {
    tytul=licz[tyt];
    wykonawca=licz[wyk];
    int r=rand()%30+1980;
    rok=Int2Str(r);
    int ile=rand()%10+1;
    ushort c=0;
    for(int i=0;i<ile;++i)
      {
        utwor nowy=utwor(i+1,licz[i+1]);
        utwory.push_back(nowy);
        c+=Str2Czas(nowy.czas);
      }
    
    czas=Int2Czas(c);
    int los=rand()%2;
    typ=los+'0';
    
    if(los)
      return;
    
    ile=rand()%10+1;
    for(int i=0;i<ile;++i)
      {
        utwor nowy=utwor(i+1,licz[i+1]);
        utwory2.push_back(nowy);
        c+=Str2Czas(nowy.czas);
      }
    czas=Int2Czas(c);

  }
  friend ostream& operator<<(ostream& out,const struct plyta& co);

};

ostream& operator<<(ostream& out,const plyta& co)
  {
    out<<co.typ<<';'<<co.tytul<<';'<<co.czas<<';'<<co.wykonawca<<';'<<co.rok<<"{\n";
    for(int i=0;i<co.utwory.size();++i)
      out<<co.utwory[i];
    out<<"}\n";
    if(co.utwory2.size()==0)
      return out;
    out<<"{\n";
    for(int i=0;i<co.utwory2.size();++i)
      out<<co.utwory2[i];
    out<<"}\n";
    return out;
  }



vector< vector<int> > albumy;

void Generuj()
{
  int suma=0;
  srand(time(NULL));

  for(int j=1;suma<100;j++)
    {
      int ilosc=rand()%10+1;
      suma+=ilosc;
      vector<int> liczby;
      for(int i=1;i<=ilosc;++i)
        liczby.push_back(i);
      albumy.push_back(liczby);
    }
}


int main()
{
  Generuj();

  /*  for(int i=0;i<=albumy.size();i++)
    {
      cout<<licz[i+1]<<" "<<i<<" "<<albumy[i].size()<<endl;

      for(int j=0;j<albumy[i].size();++j)
        {
          cout<<" "<<licz[albumy[i][j]]<<" "<<i<<" "<<j<<endl;
        }
      }*/

  vector<plyta> kolekcja;

  for(int i=0;i<albumy.size();++i)
    {
      for(int j=0;j<albumy[i].size();++j)
        {
          kolekcja.push_back(plyta(albumy[i][j],i+1));
        }
    }

  for(int i=0;i<kolekcja.size();++i)
    cout<<kolekcja[i];

  return 0;

}
