#include "kolekcja.hpp"

using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;

Kolekcja::~Kolekcja()
{
  while(!lista.empty())
    {
      delete lista.back(); //zwalniamy zajętą pamięć
      lista.pop_back(); //i usuwamy, co niepotrzebne
    }
}

int Kolekcja::Dodaj(Nosnik* nowy)
{
  int i=0;
  for(;i<lista.size();++i)
    {
      if(*(lista[i]) > *nowy) //porównujemy elementy dziedziczące po A. Stąd *
        break;
    }
  lista.insert(lista.begin()+i, nowy); //insert przymuje iterator, wiec po prostu bierzemy iterator na pierwszy element i go odpowiednio zwiekszamy
  return i+1;
}

int Kolekcja::Dodaj(const string& tytul, const string& czas, const string& wykonawca, const string& rok, const vUtwory& u)
{
  Nosnik *nowy=new CD(tytul,czas,wykonawca,rok,u);
  return Dodaj(nowy);
}

int Kolekcja::Dodaj(const string& tytul, const string& czas, const string& wykonawca, const string& rok, const vUtwory& a, const vUtwory& b)
{
  Nosnik *nowy=new CC(tytul,czas,wykonawca,rok,a,b);
  return Dodaj(nowy);
}

void Kolekcja::Usun(int i)
{
  if(i>=lista.size())
    throw "Indeks poza zakresem";
  vector<Nosnik*>::iterator it=lista.begin(); //erase bierze iterator, wiec od razu od niego zaczniemy 
  for(int a=0;a<i;a++,it++);
  lista.erase(it);
}

void Kolekcja::Wczytaj(const char* sciezka)
{
  ifstream plik; //plik z którego będziemy wczytywać

  //zmienne do konstruktorów
  bool typ=true;
  string  tytul="";
  string czas;
  string w="";
  string wykonawca;
  string rok;
  vUtwory a,b;

  string linia="";

  plik.open(sciezka,ifstream::in);
  if(plik.fail())
    throw "Podany plik nie istnieje";
  
  while(plik.peek()!=-1) //plik.eof() czekało o jeden znak za dużo
    {
      //będziemy wczytywać w pętli, więc na poczatku trzeba wyczyścić poprzednie wartości, żeby nie było śmieci
      typ=true;
      tytul="";
      wykonawca="";
      rok="";
      czas="";
      a.clear();
      b.clear();

      typ=(plik.get()=='1'?true:false);
      for(plik.get();plik.peek()!=';';tytul+=plik.get()); //następne linijki są podobne. Zaczynamy od pli.get(), żeby połykać ;-znaki oddzielające pola. Ewentualne błędy zgłoszą nam konstruktory. plik.peek() podgląda
      for(plik.get();plik.peek()!=';';czas+=plik.get());
      for(plik.get();plik.peek()!=';';wykonawca+=plik.get());
      for(plik.get();plik.peek()!='{';rok+=plik.get());
      plik.get(); //po { będzie \n, więc tutaj połkniemy ten pierwszy
      for(plik.get();plik.peek()!='}';plik.get())
        {
          linia="";
          for(;plik.peek()!='\n';linia+=plik.get());

          try
            {
              a.push_back(Utwor(linia));
            }
          catch(const char* wyjatek)
            {
            plik.close();
            throw wyjatek;
            }

        }
      plik.get(); //połykamy }
      plik.get(); //oraz /n
      if(typ) //jeśli wczytujemy CD, to proóbujemy dodać nasz element i zabrać się za kolejny wpis (continue)
        {
          try{
            lista.push_back(new CD(tytul,czas,wykonawca,rok,a));
          }catch(const char* wyjatek){
            plik.close(); //w razie problemów nie chcemy stracić całego pliku
            throw wyjatek;}

          continue;
        }
      plik.get(); //połkniemy { , żeby linię niżej połknąć \n
      for(plik.get();plik.peek()!='}';plik.get())
        {
          linia="";
          for(;plik.peek()!='\n';linia+=plik.get());

          try{
            b.push_back(Utwor(linia));
          }catch(const char* wyjatek){
            plik.close();
            throw wyjatek;}

        }
      plik.get(); // }
      plik.get(); // \n
      try{
        lista.push_back(new CC(tytul,czas,wykonawca,rok,a,b));
      }catch(const char* wyjatek){
        plik.close();
        throw wyjatek;}
    }
  plik.close();
}

void Kolekcja::Zapisz(const char* sciezka) const
{
  ofstream plik;
  plik.open(sciezka,ofstream::trunc|ofstream::out); //trunc czyści plik jeśli coś w nim było
  for(int i=0;i<lista.size();++i)
    plik<<lista[i]->Zapis();
  plik.close();
}

Nosnik* Kolekcja::operator [](int i)
{
  if(i>=lista.size())
    throw "Indeks poza zakresem";
  return lista[i];
}

int Kolekcja::Size() const
{
  return lista.size();
}

Kolekcja::Kolekcja(const Kolekcja& kopia)
{
  for(int i=0;i<kopia.Size();++i)
    {
      Nosnik* nowy=0;
      if(kopia.lista[i]->TypBool())
        nowy=new CD((CD&) (*kopia.lista[i])); //kopia.lista[i] wyciąga element typu Nosnik*. * zwracamy się do elemtu samego w sobie a nie wskaźnika, i rzutujemy do na referencję, żęby użyć konstruktora kopiującego klasy CD(domyślnego, bo nie ma tam wskaźników)
      else
        nowy=new CC( (CC&) (*kopia.lista[i]));
      
      lista.push_back(nowy);
    }
}

Kolekcja& Kolekcja::operator=(const Kolekcja& kopia)
{
  return *(new Kolekcja(kopia)); //tworzymy nowy element i zwracamy. * pozawala zrzutować na Kolekcja&
}

