FLAGI=-Wall -Wextra
FLAGI=
katalog: katalog.o kolekcja.o plyty.o utwor.o utils.o
	g++ $(FLAGI) katalog.o kolekcja.o plyty.o utwor.o utils.o -o katalog

katalog.o: katalog.cpp kolekcja.o utwor.o plyty.o utils.o
	g++ $(FLAGI) -c katalog.cpp -o katalog.o

kolekcja.o: kolekcja.hpp kolekcja.cpp utwor.o plyty.o utils.o
	g++ $(FLAGI) -c kolekcja.cpp -o kolekcja.o

plyty.o: plyty.hpp plyty.cpp utwor.o utils.o
	g++ $(FLAGI) -c plyty.cpp -o plyty.o

utwor.o: utwor.hpp utwor.cpp utils.o
	g++ $(FLAGI) -c utwor.cpp -o utwor.o
utils.o: utils.hpp utils.cpp
	g++ $(FLAGS) -c utils.cpp -o utils.o
generator: generator.cpp utils.o
	g++ generator.cpp utils.o -o generator
clean:
	rm -f katalog generator *.o

