// file      : access/person.hpp
// copyright : not copyrighted - public domain

#ifndef PERSON_HPP
#define PERSON_HPP

#include <QStandardItem>
#include <string>
#include <cstddef> // std::size_t

#include <odb/core.hxx>

#pragma db object
class person:public QStandardItem
{
public:
  person (const QString& first,
          const QString& last,
          unsigned short age)
      : first_ (first), last_ (last), age_ (age)
  {

      setText(first+" "+last+" "+QString::number(age));
  }

  const QString&
  first () const
  {
    return first_;
  }

  const QString&
  last () const
  {
    return last_;
  }

  unsigned short
  age () const
  {
    return age_;
  }

  void
  age (unsigned short age)
  {
    age_ = age;
  }

private:
  friend class odb::access;

  person () {}

  #pragma db id auto
  unsigned long id_;

  QString first_;
  QString last_;
  unsigned short age_;

};

#endif // PERSON_HPP
