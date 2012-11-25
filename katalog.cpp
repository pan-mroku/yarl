#include <iostream>
#include "kolekcja.hpp"

using namespace std;

Kolekcja kolekcja;
string adres;

inline void CinFlush() //czasem przeyda się oczyścić bufor (np. po cin.get() mogą zostawać śmieci), a cin.sync() nie do końća działa. Inline żeby nie wywoływał tej funkcji, tylko skopiował jje zawartość
{
  for(char c=0;c!='\n';c=cin.get()); 
}

inline void Pasek()  //taki drobiazg dla czytelności. w windowsie konsola często ma 80 znaków szerokości, w linuksie nie ma takiego ograniczenia, ale zawsze będzie coś wiecej widać
{
  for(int i=0;i<80;++i)cout<<'-';
  cout<<endl;
}

bool Init()
{
  char c=0;
  cout<<"Witaj w programie Pawła Szymańskiego do przechowywania informacji o płytotece.\nMożesz:\nw - wczytać istniejącą bazę\nn - utworzyć nową\nq - opuścić program"<<endl;
  while(c!='w'&&c!='n'&&c!='q')
    c=cin.get();
  CinFlush();

  switch(c)
    {
    case 'n':
      cout<<"Podaj nazwę pliku swojej bazy."<<endl;
      cin>>adres;
      break;
    case 'q':return false;
    case 'w':
      while(true)
        {
          cout<<"Podaj nazwę pliku swojej bazy."<<endl;
          cin>>adres;
          try
            {
              kolekcja.Wczytaj(adres.c_str());
            }catch(const char* wyjatek)
            {
              cout<<"Wystąpił problem: "<<wyjatek<<".\nSpróbuj inną nazwę pliku.\n\n";
              continue;
            }
          break;
        }
      break;
    }
  return true;
}

void Wypisz()
{

  Pasek();
  for(int i=0;i<kolekcja.Size();++i)
    {
      cout<<i+1<<". "<<kolekcja[i]->Opis()<<endl;
    }

  Pasek();
}

void Dodaj()
{
  string tytul,wykonawca,rok,tytul_utworu,czas_string;
  bool druga_strona=false; //zmienna która w przyapdku kaset mówi nam, do którego wektora utworów zapisywać
  char typ;
  ushort czas=0;
  char numer,c=0;
  vUtwory a,b;

  czas=0; //jeśli nie jest to druga strona kasety, to zerujemy czas
  druga_strona=false;
  c=0;
  cout<<"Podaj typ albumu:\nk - kaseta\np - płyta"<<endl;
  while(c!='k'&&c!='p')
    {
      c=cin.get();
      CinFlush();
    }
  typ=c;
      
  cout<<"Podaj tytuł albumu."<<endl;
  cin>>tytul;
  cout<<"Podaj wykonawcę albumu."<<endl;
  cin>>wykonawca;
  cout<<"Podaj rok wydania albumu."<<endl;
  cin>>rok;
  cout<<"Teraz utwory."<<endl;
  while(true)
    {
      numer=0;
      cout<<"Podaj numer utworu."<<endl;

      for(c=cin.get();c!='\n'||numer==0;c=cin.get())
        if(isdigit(c))
          {
            numer*=10;
            numer+=c-'0';
          }
      cout<<"Podaj tytuł utworu."<<endl;
      cin>>tytul_utworu;
      while(true)
        {
          cout<<"Podaj czas trwania utworu."<<endl;
          cin>>czas_string;
          try
            {
              czas+=Str2Czas(czas_string);
            }
          catch(const char* wyjatek)
            {
              cout<<wyjatek<<"."<<endl;
              continue;
            }
          break;
        }

      cout<<"Czy podane dane są poprawne? t/n"<<endl;

      do
        {
          c=cin.get();
        }while(c!='t'&&c!='n');
      CinFlush();

      if(c=='n')
        continue;
      try
        {
          if(!druga_strona)
            a.push_back(Utwor(numer,tytul_utworu,czas_string));
          else
            b.push_back(Utwor(numer,tytul_utworu,czas_string));
        }
      catch(const char* wyjatek)
        {
          cout<<wyjatek<<". Jeszcze raz."<<endl;
          continue;
        }

      cout<<"Czy to wszystkie utwory na tej płycie lub stronie? t/n"<<endl;

      do
        c=cin.get();
      while(c!='t'&&c!='n');
      CinFlush();

      if(c=='t')
        {
          if(druga_strona||typ=='p')
            break;
          druga_strona=true;
          cout<<"Teraz strona b."<<endl;
        }
      
    }
  //skoro czytaliśmy już wszstko, to czas spróbować stworzyć nasze elementy
  try
    {
      (typ=='p')?kolekcja.Dodaj(tytul,Int2Czas(czas),wykonawca,rok,a):kolekcja.Dodaj(tytul,Int2Czas(czas),wykonawca,rok,a,b);
    }
  catch(const char* wyjatek)
    {
      cout<<wyjatek<<". Spróbuj jeszcze raz."<<endl;
    }

}

void Usun()
{
  int i=0;
  char p='z';
  Wypisz();
  while(true)
    {
      i=0;
      cout<<"Podaj numer albumu, który chcesz usunąć."<<endl;
      for(char c=cin.get();c!='\n';c=cin.get())
        if(isdigit(c))
          {
            i*=10;
            i+=c-'0';
          }
      try
        {
          cout<<kolekcja[i-1]->Szczegoly()<<endl;
        }
      catch(const char* wyjatek)
        {
          cout<<wyjatek<<". Spróbuj jeszcze raz."<<endl;
          continue;
        }
      cout<<"Czy jesteś pewien? t/n"<<endl;
      while(p!='t'&&p!='n')
        {
          cout<<"Naciśnij t jako tak lub n jako nie."<<endl;
          p=cin.get();
          CinFlush();
        }
      if(p=='n')
        return;
      try
        {
          kolekcja.Usun(i-1);
          break;
        }
      catch(const char* wyjatek)
        {
          cout<<wyjatek<<". Spróbuj jeszcze raz."<<endl;
        }
    }
}

void Zapisz()
{
  cout<<"Wprowadź nazwę pliku, lub naciśnij enter by zaakceptować domyślną nazwę ("<<adres<<").\nPamiętaj, że zapis nadpisze istniejący plik."<<endl;
  string adres2="";
  for(char c=cin.get();c!='\n';c=cin.get())
    adres2+=c;
  if(adres2=="")
    kolekcja.Zapisz(adres.c_str());
  else
    kolekcja.Zapisz(adres2.c_str());
}

void Szczegoly()
{
  int i=kolekcja.Size()+1;
  Wypisz();
  while(i>kolekcja.Size())
    {
      cout<<"Podaj numer płyty, o której chcesz się więcej dowiedzieć."<<endl;
      cin>>i;
      if(i>kolekcja.Size())
        cout<<"Zły numer."<<endl;
    }
  Pasek();  
  try
    {
      cout<<kolekcja[i-1]->Szczegoly()<<endl;
    }
  catch(const char* wyjatek)
    {
      cout<<wyjatek<<"."<<endl;
    }
  Pasek();
}

char Opcje()
{
  char c=0;
  cout<<"Co chcesz zrobić?\nw - wypisać bazę\ns - wypisać szczegóły danego albumu\nd - dodać nowy album\nu - usunąć album\nz - zapisać bazę do pliku\nq - opuścić program bez zapisywania bazy\n";
  while(c!='w'&&c!='d'&&c!='u'&&c!='z'&&c!='q'&&c!='s')
    c=cin.get();
  CinFlush();


  switch(c)
    {
    case 'q':break;
    case 'w':Wypisz(); break;
    case 'd':Dodaj();break;
    case 'u':Usun();break;
    case 'z':Zapisz();break;
    case 's':Szczegoly();break;
    }

  return c;
}

int main()
{
  if(!Init())
    return 0;
  while(true)
    {
      if(Opcje()=='q')
        return 0;
    }

  return 0;
}
