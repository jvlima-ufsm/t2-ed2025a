/*
 * lista.h
 * Definição da TAD lista_t.
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
#include <stdlib.h>

/* define a struct TAD lista_t */
typedef struct _lista {
  void* dado;	      /* ponteiro para o dado (tipo void*) */
  struct _lista *prox; /* ponteiro para o proximo elemento */
} lista_t;


/* cria uma lista vazia, ou seja, retorna NULL */
lista_t* lista_cria(void);

/* insere no começo da lista, retorna a lista atualizada,
 * ou seja, o novo 1o elemento da lista.
 */
lista_t* lista_insere( lista_t* l, void* dado );

/* retorna se a lista esta vazia (true), ou false caso contrario */
int lista_vazia( lista_t* l );

/* remove da lista o elemento que contem 'dado'.
   Se lista ficar vazia, retorna NULL.
   Se encontrou, o elemento da lista deve ser liberado com free(). ATENCAO: nao liberar o dado.
   Se nao encontrou, retorna a lista 'l'.

   Use o exemplo da função lista_busca para fazer esta função.
*/
lista_t* lista_remove( lista_t* l, void* dado, int (*f)(void*, void*)  );

/* libera a memória de cada nó da lista.
 * ATENÇÃO: não libera memória dos dados.
 */
void lista_destroi( lista_t* l );

/* busca um elemento na lista por meio da funcao f():
  bool f(void* a, void* b) {}
  que retonar 'true' caso a e b sejam iguais.
  TODO
*/
int lista_busca( lista_t* l, void* dado, int (*compara)(void*, void*)  );

/* imprime todos os elementos da lista usando a função f 
   TODO
 */
void lista_imprime( lista_t* l, void (*imprime)(void*)  );

