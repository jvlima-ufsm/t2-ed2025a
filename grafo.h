/*
 * grafo.h
 * Definição da TAD grafo_t.
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

#pragma once

#include "lista.h"

/* o tipo vértice com lista de adjacencia */
typedef struct vertice {
	int nome;            /* nome/número do vértice */
	lista_t* adjacentes; /* lista com os vértices adjacentes (vizinhos),
                        * cada elemento é aresta_t */
} vertice_t;

/* o tipo aresta com um ponteiro para o vértice */
typedef struct aresta {
  vertice_t* v;       /* vértice que a aresta liga */
  float peso;           /* peso da aresta (quando tem)*/
} aresta_t;

typedef struct {
  lista_t* vertices;  /* vertices do grafo, cada elemento é vertice_t */
	int nvertices;      /* numero de vértices */
  int narestas;       /* numero de arestas */
} grafo_t;

void grafo_dijkstra(grafo_t* g, vertice_t* fonte);

/* cria um grafo vazio */
grafo_t* grafo_cria(void);

/* insere um vértice no grafo.
 *  Se vértice existe, retorna 0, senão 1.  */
int grafo_insere_vertice(grafo_t* g, int nome);

/* Insere uma aresta entre os vértices v1 e v2.
 * Se um dos vértices não existe, retorna false.
 * Caso sucesso, retorna true. */
int grafo_insere_aresta(grafo_t* g, int nome1, int nome2, float peso);

/* retorna um vértice associado a um nome */
vertice_t* grafo_busca_vertice(grafo_t* g, int nome);

/* 
 * Retorna o peso total do caminho curto quando existir, 0 caso contrario
*/
float grafo_caminho_curto(grafo_t* g, vertice_t* u, vertice_t* v)

/* Importa um grafo a partir de um arquivo texto */
void grafo_importa(grafo_t* g, char* arquivo);

/* destroi e libera memória de um grafo */
void grafo_destroi(grafo_t* g);
