#ifndef CDITEM_HPP
#define CDITEM_HPP

#include "albumitem.hpp"
#include "cd.hpp"

class CDItem:public CD, public AlbumItem
{
public:
  CDItem(const CD& cd);

  virtual void AddTrack(const std::string& title, const int duration, const int index=0){CD::AddTrack(title, duration);}
  virtual Album::Types Type() const{return CD::Type();}
  virtual bool Persist(odb::database& db) const{return CD::Persist(db);}

  virtual QString QData() const{return AlbumItem::QData();}
  
protected:
private:
};

#endif
