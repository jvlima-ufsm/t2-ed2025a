/*
 * testes.cpp
 * Exercício sobre TAD lista.
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

/* NÃO MUDAR ESSSE ARQUIVO!!!*/

#include "catch_amalgamated.hpp"

#include <cstring>
#include <cstdlib>

extern "C" {
    #include "grafo.h"
}

TEST_CASE("Caso 1") {
    grafo_t* g;
    vertice_t* u;
    vertice_t* v;

    g= grafo_cria();
    grafo_importa(g, "tinyEWG.txt");
    u = grafo_busca_vertice(g, 4);
    grafo_dijkstra(g, u);

    v = grafo_busca_vertice(g, 6);
    REQUIRE(grafo_caminho_curto(g, u, v) == 0.93f);

    v = grafo_busca_vertice(g, 3);
    REQUIRE(grafo_caminho_curto(g, u, v) == 1.83f);

    grafo_destroi(g);
}

TEST_CASE("Caso 2") {
    grafo_t* g;
    vertice_t* u;
    vertice_t* v;

    g= grafo_cria();
    grafo_importa(g, "tinyEWG.txt");
    u = grafo_busca_vertice(g, 5);
    grafo_dijkstra(g, u);

    v = grafo_busca_vertice(g, 6);
    REQUIRE(grafo_caminho_curto(g, u, v) == 1.74f);

    grafo_destroi(g);
}
