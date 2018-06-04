cmake_minimum_required(VERSION 3.10)
project(trabalho_grafos)

set(CMAKE_CXX_STANDARD 11)

add_executable(trabalho_grafos br.ufjf/main.cpp br.ufjf/grafo/Grafo.cpp br.ufjf/grafo/Grafo.h br.ufjf/grafo/Vertice.cpp br.ufjf/grafo/Vertice.h br.ufjf/grafo/Aresta.cpp br.ufjf/grafo/Aresta.h)