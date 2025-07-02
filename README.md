
# Algoritmo de Dijkstra

Este trabalho consiste na implementação de caminhos mínimos com o algoritmo de
Dijstra em um grafo não-direcionado, com pesos nas arestas, com listas de
adjacência.
O algoritmo de Dijkstra gera uma árvore de caminhos mínimos de um vértice origem
para todos os vértices alcançáveis a partir da origem.
As TADs de grafo, vértice, aresta (grafo.h), lista (lista.h) e heap (heap.h) já
estão definidas.
Cada vértice agora possui:
- ant: vértice anterior no caminho encontrado.
- chave: menor custo da origem até este vértice, usado no heap como chave.
Cada aresta agora possui:
- peso: peso da aresta

Nesse algoritmo também é necessário o uso de uma fila de prioridade mínima, ou
heap mínimo, que mantem o elemento de menor chave no topo do heap.
As função necessárias estão em heap.h.

O exercício consiste em 
- implementar a função `grafo_dijkstra()` no arquivo grafo.c 

O algoritmo de Dijkstra é dado abaixo:
```
// recebe o grafo, o vertice de fonte 'fonte'
void grafo_dijkstra(grafo_t* g, vertice_t* fonte){
  inicializa todos vertices do grafo G com chave infinita (FLT_MAX)
  cria heap mínimo H (heap_cria)
  inicia chave da fonte com valor 0 (fonte->chave = 0)
  insere todos os vértices de g no heap (heap_constroi)
  
  while( heap_vazio(H) == false ){
      u = retira do heap H o vértice mínimo  (heap_retira_minimo)
      for( cada vertice adjacente v de u ) {
        if( é possível melhorar o caminho entre (u,v) ? (v->chave > u->chave + a->peso) ){
          v->ant = u
          v->chave = peso da aresta (u, v) mais chave de u (u->chave + a->peso)
          atualiza o heap com a chave nova de v (heap_muda)
        }
      }
  }
}
```

# Testes 

Este é o código exemplo do trabalho usando TDD (*Test Driven Development*) com o framework C++ [Catch2](https://github.com/catchorg/Catch2/tree/v2.x).

O framework Catch2 consegue ser utilizado apenas com o arquivo header [catch.hpp](catch.hpp) sem necessidade de instalação.

**NÃO MODIFIQUE OS TESTES** 

Todos os testes estão prontos no arquivo [testes.cpp](testes.cpp). A compilação e teste pode ser feita com o comando `make`:
```
> make
gcc -Wall -g -O2   -c -o grafo.o grafo.c
gcc -Wall -g -O2   -c -o lista.o lista.c
gcc -Wall -g -O2   -c -o heap.o heap.c
g++ -Wall -g -O2   -c -o catch_amalgamated.o catch_amalgamated.cpp
g++ -Wall -g -O2   -c -o testes.o testes.cpp
> valgrind --leak-check=full ./a.out --reporter compact --success
```

