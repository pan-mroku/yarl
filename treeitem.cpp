#include "treeitem.hpp"

#include<iostream>

TreeItem::TreeItem(TreeItem* parent)
{
  Parent=parent;
  if(Parent!=NULL)
    Parent->Children.push_back(const_cast<TreeItem*>(this));
}

TreeItem::TreeItem(const std::initializer_list<std::string>& data, TreeItem* parent)
{
  for(const std::string& data_element:data)
    Data.push_back(new std::string(data_element));
  Parent=parent;
  if(Parent!=NULL)
    Parent->Children.push_back(const_cast<TreeItem*>(this));
}

TreeItem::~TreeItem()
{
  for(TreeItem* child:Children)
    delete child;
  Children.clear();

  /*  for(std::string* data_element:Data)
      delete data_element;*/
  Data.clear();
}

int TreeItem::Row() const
{
  if (Parent!=NULL)
    for(int i=0;i<Parent->Children.size();i++)
      if(Parent->Children[i]==this)
        return i;

  return 0;
}

QString TreeItem::QData() const
{
  QString out;
  for(const std::string* element:Data)
    out+=QString::fromStdString(*element)+" ";
  return out;
}

std::ostream& operator<<(std::ostream& out, const TreeItem& item)
{
  for (const std::string* data:item.Data)
    out<<*data<<" ";

  if(item.Children.size()>0)
    {
      out<<std::endl<<"--->"<<std::endl;
      for(const TreeItem* child : item.Children)
        out<<"\t"<<*child;
      out<<std::endl<<"<---"<<std::endl;
    }

  return out;
}
