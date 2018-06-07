cmake_minimum_required(VERSION 3.10)
project(trabalho_grafos)

set(CMAKE_CXX_STANDARD 11)

add_executable(trabalho_grafos main.cpp Grafo.cpp Grafo.h No.cpp No.h Aresta.cpp Aresta.h IO/ManipuladorArquivo.cpp IO/ManipuladorArquivo.h)