/*
 * grafo.c
 * Implementação da TAD grafo_t.
 *
 * The MIT License (MIT)
 * 
 * Copyright (c) 2025 João Vicente, UFSM
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>

#include "grafo.h"
#include "lista.h"
#include "heap.h"


/* Cria uma árvore geradora mínima com o algoritmo de Prim.
 * TODO
 */
void grafo_dijkstra(grafo_t* g, vertice_t* fonte)
{
  lista_t* l; /* lista de vertices */
  heap_t* heap; /* heap de prioridade mínima */
  vertice_t* u;
  vertice_t* v;
  lista_t* adj; /* lista de adjacentes */

  /* inicializa vértices */
  l = g->vertices;
  while(lista_vazia(l) == 0){
    v = (vertice_t*)l->dado;
    v->ant = NULL;
    v->chave = FLT_MAX;
    /* próximo vértice */
    l = l->prox;
  }
  
  fonte->chave = 0;
  heap = heap_cria(g->nvertices);
  heap_constroi(heap, g->vertices);

  /* 
  TODO resto do código aqui 
  */

  heap_destroi(heap);
}


/* cria um grafo vazio */
grafo_t* grafo_cria(void)
{
  grafo_t* g = (grafo_t*)malloc(sizeof(grafo_t));
  g->vertices = lista_cria(); /* lista vazia */
  g->nvertices = 0;
  g->narestas = 0;
  return g;
}

/* retorna um vértice associado a um nome */
vertice_t* grafo_busca_vertice(grafo_t* g, int nome)
{
  lista_t* l;
  vertice_t* v;
  assert(nome >= 0);
  assert(g != 0);

  l = g->vertices;
  while(lista_vazia(l) == 0){
    v = (vertice_t*)l->dado;
    if(v->nome == nome)
      return v;

    /* próximo vértice */
    l = l->prox;
  }
  return NULL;
}

/* insere um vértice no grafo.
 *  Se vértice existe, retorna false, senão true.  */
int grafo_insere_vertice(grafo_t* g, int nome)
{
  vertice_t* v;
  v = grafo_busca_vertice(g, nome);
  if(v != NULL)
    return 0;

  v = (vertice_t*)malloc(sizeof(vertice_t));
  v->nome = nome;
  v->adjacentes = lista_cria();
  v->chave = FLT_MAX;
  v->ant = NULL;

  g->vertices = lista_insere(g->vertices, v);
  g->nvertices++;

  return 1;
}

/* Insere uma aresta entre os vértices v1 e v2.
 * Se um dos vértices não existe, retorna false.
 * Caso sucesso, retorna true. */
int grafo_insere_aresta(grafo_t* g, int nome1, int nome2, float peso)
{
  vertice_t* v1;
  vertice_t* v2;
  aresta_t* a1;
  aresta_t* a2;

  v1 = grafo_busca_vertice(g, nome1);
  v2 = grafo_busca_vertice(g, nome2);
  if(v1 == NULL || v2 == NULL)
    return 0;

  /* insere v2 no v1 */
  a1 = (aresta_t*)malloc(sizeof(aresta_t));
  a1->v = v2;
  a1->peso = peso;
  v1->adjacentes = lista_insere(v1->adjacentes, a1);

  /* insere v1 no v2 */
  a2 = (aresta_t*)malloc(sizeof(aresta_t));
  a2->v = v1;
  a2->peso = peso;
  v2->adjacentes = lista_insere(v2->adjacentes, a2);

  return 1;
}

void grafo_importa(grafo_t* g, char* arquivo)
{
  int nvertices, narestas;
  int i, v1, v2;
  float peso;
  FILE* f = fopen(arquivo, "r");

  fscanf(f, "%d", &nvertices);
  fscanf(f, "%d", &narestas);
//  g->nvertices = nvertices;
  g->narestas = narestas;

  for(i = 0; i < narestas; i++){
    fscanf(f, "%d %d %f", &v1, &v2, &peso);
    grafo_insere_vertice(g, v1);
    grafo_insere_vertice(g, v2);
    if(grafo_insere_aresta(g, v1, v2, peso) == 0){
      printf("ERRO: ao inserir aresta, um vertice nao existe: %d -> %d\n", v1, v2);
      assert(0);
    }
  }
  fclose(f);
}

void grafo_destroi(grafo_t* g)
{
  lista_t* l; /* lista de vertices */
  lista_t* adj; /* lista de adjacentes */

  l = g->vertices;
  while(lista_vazia(l) == 0){
    vertice_t* v = (vertice_t*)l->dado;
    adj = v->adjacentes;
    while(lista_vazia(adj) == 0){
      aresta_t* a = (aresta_t*)adj->dado;
      free(a);
      /* próxima aresta */
      adj = adj->prox;
    }
    lista_destroi(v->adjacentes);
    free(v);
    /* próximo vértice */
    l = l->prox;
  }
  lista_destroi(g->vertices);
  free(g);
}


float grafo_caminho_curto(grafo_t* g, vertice_t* u, vertice_t* v)
{
#if 1
  float custo = 0.0;
  vertice_t* curr = NULL;
  if(v->ant == NULL)
    return 0.0;
  
  curr= v;
  while(curr->ant != NULL){
    custo += curr->chave;
    curr = curr->ant;
  }
  if(curr->nome != u->nome)
    return 0.0;

  return custo;
#else  
  if(u->nome == v->nome){
    printf("%d ", u->nome);
    return;
  }
  if(v->ant == NULL){
    printf("ERRO: Nao existe caminho de %d a %d!\n", u->nome, v->nome);
  } else {
    grafo_caminho_curto( g, u, v->ant );
    printf("%d(%.2f) ", v->nome, v->chave);
  }
#endif
}

