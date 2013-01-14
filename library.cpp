#include "library.hpp"

Library::Library(std::string name)
{
  Name=name;
}

Library::Library(const Library& library)
{
  id=library.id;
  Name=library.Name;
  for(const Artist* artist:library.Artists)
    Artists.push_back(new Artist(*artist));
}

Library::~Library()
{
  for(Artist* artist:Artists)
    delete artist;
  Artists.clear();
}

/*std::ostream& operator<<(std::ostream& out, const Library& library)
{
  if(library.Name!="")
    out<<library.Name<<std::endl;
  for(const Artist* artist:library.Artists)
    out<<"\t"<<*artist<<std::endl;

  return out;
  }*/
