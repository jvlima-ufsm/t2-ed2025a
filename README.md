
# Grafo não-direcionado, sem pesos, lista de adjacências

Este é o código exemplo do trabalho usando TDD (*Test Driven Development*) com o framework C++ [Catch2](https://github.com/catchorg/Catch2/tree/v2.x).

O framework Catch2 consegue ser utilizado apenas com o arquivo header [catch.hpp](catch.hpp) sem necessidade de instalação.

**NÃO MODIFIQUE OS TESTES** 

Todos os testes estão prontos no arquivo [testes.cpp](testes.cpp). A compilação e teste pode ser feita com o comando `make`:
```
> make
gcc -Wall -g -O2   -c -o lista.o lista.c
g++ -Wall -g -O2   -c -o catch_amalgamated.o catch_amalgamated.cpp
g++ -Wall -g -O2   -c -o testes.o testes.cpp
g++ -Wall -g -O2 -o a.out grafo.o lista.o catch_amalgamated.o testes.o -lm
> valgrind --leak-check=full ./a.out --reporter compact --success
```

