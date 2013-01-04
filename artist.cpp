#include "artist.hpp"

Artist::Artist(const QString& name):Name(name)
{
  setText(Name);
}

std::ostream& operator<<(std::ostream& out, const Artist& artist)
{
  out<<artist.Name.toStdString();
  return out;
}

