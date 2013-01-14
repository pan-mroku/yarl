#include "albumitem.hpp"

AlbumItem::AlbumItem(const Album& album):Album(album)
{
  Year_str=std::to_string(Year);
  Data.push_back(&Year_str);
  Data.push_back(&Title);
  //for

}
