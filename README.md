yarl
====

yarl - Yet Another Record Library

Projekt na przedmioty "Obiekty i Bazy Danych" oraz "Architektura Oprogramowania".


Plan
----

* Stworzyć klasy obiektów przechowywanych w bazie. OiBD wymaga dziedziczenia, stąd wymysły w klasie Album.
  * Artist 
  * Album: CD, MCD [odb_manual#inheritance](http://www.codesynthesis.com/products/odb/doc/manual.xhtml#8)
  * Song 
* Model ma listy tych klas z ODB, QStandardItemModel
* View ma treeView
* Controller ma przyciski
* GUI będzie View i Controller jednocześnie.
