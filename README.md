yarl
====

yarl - Yet Another Record Library

Projekt na przedmioty "Obiekty i Bazy Danych" oraz "Architektura Oprogramowania".


Plan
----

* Stworzyć klasy obiektów przechowywanych w bazie. OiBD wymaga dziedziczenia, stąd wymysły w klasie Album.
  Wszystkie klasy niech dziedziczą po QStandardItem
  * Artist 
  * Album: CD, MCD [odb_manual#inheritance](http://www.codesynthesis.com/products/odb/doc/manual.xhtml#8)
  * Song 
* Model ma listy tych klas z ODB, dziedziczy po QStandardItemModel [QStandardItemModel#details] (https://qt-project.org/doc/qt-4.8/qstandarditemmodel.html#details)
* View ma treeView
* Controller ma przyciski
* GUI będzie View i Controller jednocześnie.

Zależności
----------

* [ODB](http://codesynthesis.com/products/odb/doc.xhtml)(2.1.0)
* [Qt] (https://qt.digia.com/)(4.8)
* [SQLite](https://sqlite.org/)(3.7)
* [C++11](https://en.wikipedia.org/wiki/C%2B%2B11)(gcc-4.6)

