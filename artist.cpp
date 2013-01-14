#include "artist.hpp"

Artist::Artist(const std::string& name)
{
  Name=name;
}

std::ostream& operator<<(std::ostream& out, const Artist& artist)
{
  out<<artist.Name<<std::endl;
}
