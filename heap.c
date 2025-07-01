/*
 * fila.c
 * Implementação da TAD fila_t - fila (FIFO).
 *
 * The MIT License (MIT)
 * 
 * Copyright (c) 2025 João V. Lima, UFSM
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

#include "heap.h"
#include "lista.h"
#include "grafo.h"

/* define a struct TAD heap */
struct _heap {
  int tam;
  vertice_t** A;
};


heap_t* heap_cria (int n)
{
  heap_t* h = (heap_t*)malloc(sizeof(heap_t));
  h->tam= 0;
  h->A = (vertice_t**)malloc(n*sizeof(vertice_t*));
  return h;
}

void heap_muda( heap_t* h, vertice_t* v )
{
  int i;
  for(i = (int)h->tam/2; i >= 0; i--)
    heap_reconstroi( h, i );
}

void heap_insere( heap_t* h, vertice_t* v )
{
  h->A[h->tam] = v;
  h->tam++;
  heap_muda(h, v);
}

void heap_constroi( heap_t* h, lista_t* l )
{
  lista_t* tmp = l;
  int i;
  while(lista_vazia(tmp) == false){
    vertice_t* v = (vertice_t*)tmp->dado;
    h->A[h->tam] = v;
    h->tam++;
    tmp = tmp->prox;
  }
  for(i = (int)h->tam/2; i >= 0; i--)
    heap_reconstroi( h, i );
}

int heap_vazio( heap_t* h )
{
  if(h->tam == 0)
    return 1;
  return 0;
}

void heap_reconstroi ( heap_t* h, int i )
{
  int esq = 2*i+1;
  int dir = 2*i+2;
  int menor= -1;
  if( (esq < h->tam) && (h->A[esq]->chave < h->A[i]->chave) )
    menor = esq;
  else
    menor = i;
  if( (dir < h->tam) && (h->A[dir]->chave < h->A[menor]->chave) )
    menor = dir;

  if(menor != i){
    vertice_t* tmp = h->A[i];
    h->A[i] = h->A[menor];
    h->A[menor] = tmp;
    heap_reconstroi( h, menor );
  }
}

bool heap_contido( heap_t* h, vertice_t* v )
{
  int i;
  for(i= 0; i < h->tam; i++)
    if(h->A[i]->nome == v->nome)
      return true;

  return false;
}

vertice_t* heap_retira_minimo( heap_t* h ) 
{
  vertice_t* v;
#if 0
  int i;
  printf("RETIRA ");
  for(i=0; i < h->tam; i++)
    printf("%d(%f) ", h->A[i]->nome, h->A[i]->chave);
  printf("\n");
#endif
  v = h->A[0];
  h->tam--;
  /* insere o último na primeira posição */
  h->A[0] = h->A[h->tam];
  /* reconstroi o heap */
  heap_reconstroi( h, 0 );
  return v;
}

void heap_destroi( heap_t* h )
{
  if(h->A != NULL)
    free(h->A);
  free(h);
}
