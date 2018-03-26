practica.tar: program.exe Client.o Conjunt_clients.o Producte.o Supermercat.o Conjunt_productes.o Temps.o
	tar -cvf practica.tar *txt *.cc *.hh *.exe *.pdf Makefile Doxyfile

program.exe: program.o Client.o Conjunt_clients.o Producte.o Supermercat.o Conjunt_productes.o Temps.o
	g++ -o program.exe program.o Client.o Conjunt_clients.o Producte.o Supermercat.o Conjunt_productes.o Temps.o

program.o: program.cc 
	g++ -c program.cc -D_GLIBCXX_DEBUG -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

Client.o: Client.cc 
	g++ -c Client.cc -D_GLIBCXX_DEBUG -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

Conjunt_clients.o: Conjunt_clients.cc
	g++ -c Conjunt_clients.cc -D_GLIBCXX_DEBUG -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

Producte.o: Producte.cc
	g++ -c Producte.cc -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

Conjunt_productes.o: Conjunt_productes.cc
	g++ -c Conjunt_productes.cc -D_GLIBCXX_DEBUG -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

Supermercat.o: Supermercat.cc
	g++ -c Supermercat.cc -D_GLIBCXX_DEBUG -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x
	
Temps.o: Temps.cc
	g++ -c Temps.cc -D_GLIBCXX_DEBUG -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x
	
clean:
	rm *.o
	rm *.exe
