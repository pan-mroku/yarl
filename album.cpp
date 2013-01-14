#include "album.hpp"

Album::Album(const int year, const std::string& title):Year(year), Title(title)
{

}

Album::Album(const Album& other)
{
  id=other.id;
  Year=other.Year;
  Title=other.Title;
}
