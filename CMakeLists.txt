cmake_minimum_required(VERSION 3.9)
project(trabalho_grafos)

set(CMAKE_CXX_STANDARD 11)

add_executable(trabalho_grafos main.cpp Grafo/Grafo.cpp Grafo/Grafo.h Grafo/No.cpp Grafo/No.h Grafo/Aresta.cpp Grafo/Aresta.h IO/Interface.cpp IO/Interface.h IO/ManipuladorArquivo.h IO/ManipuladorArquivo.cpp Grafo/GrafoColoracao.cpp Grafo/ListaNo.cpp Grafo/ListaNo.h Grafo/ListaNoItem.cpp Grafo/ListaNoItem.h)