#include "utils.hpp"
#include <sstream>

using std::string;
using std::stringstream;

string Int2Str(int a)
{
  stringstream conv;
  conv << a;
  return conv.str();
}

ushort Str2Czas(const string& c)
{
  ushort raz=0,dwa=0,trzy=0,i=0;
  bool dlugi=false;
  for(;c[i]!=':';++i) //dopóki nie spotkamy ':' zliczamy pierwszą liczbę
    {
      raz*=10;     //liczbe czytamy od lewej, wiec trzeba przemnożyć poprzednio uzyskaną liczbę przez 10
      raz+=c[i]-'0'; //c[i] to char, wiec aby otrzymać ilczbę odejmujemy '0'
    }
  for(++i;c[i]!=':'&&i<c.size();++i)
    {
      dwa*=10;
      dwa+=c[i]-'0';
    }
  for(++i;i<c.size();++i) //jeśli string nie ma 3 członu w ogóle nie wejdziemy do tej pętli pozostawiajac zmienną dlugi==false
    {
      dlugi=true;
      trzy*=10;
      trzy+=c[i]-'0';
    }
  if(dlugi)
    {
      if(dwa>=60||trzy>=60)
        throw "Błedny czas utworu";
      return raz*3600+dwa*60+trzy;
    }
  else
    {
      if(raz>=60||dwa>=60)
        throw "Błędny czas utworu";
      return 60*raz+dwa;
    }
}

string Int2Czas(int c)
{
  ushort godziny=0,minuty=0,sekundy=0;
  godziny=c/3600;
  c%=3600;
  minuty=c/60;
  c%=60;
  sekundy=c;
  if(godziny>0)
    return Int2Str(godziny)+":"+Int2Str(minuty)+":"+Int2Str(sekundy);
  return Int2Str(minuty)+":"+Int2Str(sekundy);
}
