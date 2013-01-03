#include "artist.hpp"

Artist::Artist(const QString& Name):name(Name)
{
}

const QString& Artist::Name() const
{
  return name;
}


