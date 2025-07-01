/*
 * heap.h
 * Definição da TAD heap_t (fila de prioridade mínima).
 * ATENÇÃO: implementação não eficiente.
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

#pragma once

#include "lista.h"
#include "grafo.h"

/* define o tipo heap_t, derivado da 'struct _heap' */
typedef struct _heap heap_t;

/* cria um heap vazio com n elementos de capacidade */
heap_t* heap_cria (int n);

/* constroi um heap mínimo a partir de uma lista de vértices */
void heap_constroi( heap_t* h, lista_t* l );

/* retira do heap o vértice com custo mínimo */
vertice_t* heap_retira_minimo( heap_t* h ); 

/* testa se o vértice v está contido no heap */
int heap_contido( heap_t* h, vertice_t* v );

/* atualiza o vértice v dentro do heap, porque v mudou de chave, 
 * e a condição do heap foi violada. */
void heap_muda( heap_t* h, vertice_t* v );

/* insere v no heap baseado em sua chave */
void heap_insere( heap_t* h, vertice_t* v );

/* assumindo que o heap foi violado, reconstroi o heap a partir da posição i */
void heap_reconstroi ( heap_t* h, int i );

bool heap_vazio( heap_t* h );

void heap_destroi( heap_t* h );

