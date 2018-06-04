//
// Created by rodolpho on 18/05/18.
//

#include <clocale>
#include "Grafo.h"
#include <fstream>
#include <iostream>
#include <cstring>

Grafo::Grafo(string nomeArquivoEntrada){//popula o grafo com o numero de arestas apresentado no arquivo
    lerArquivo(nomeArquivoEntrada);

}

void Grafo::lerArquivo(string nomeArquivoEntrada) {

    int grauGrafo,v1,v2,p;

    ifstream file(nomeArquivoEntrada);
    char * url = new char [nomeArquivoEntrada.length()+1];
    strcpy(url, nomeArquivoEntrada.c_str());

    FILE *arq;

    arq = fopen(url, "r");
    if(arq == NULL)
        printf("Erro, nao foi possivel abrir o arquivo\n");
    else

        fscanf(arq,"%d", &grauGrafo);
        this->setInicio(NULL);
        this->tamanho = grauGrafo;
        Vertice *vertice = new Vertice();

        vertice->setNome(1);
        vertice->setProximo(NULL);
        vertice->setGrau(0);
        this->inicio = vertice;

        for (int i = 2; i <= this->tamanho; ++i) {

            Vertice *aux = new Vertice();
            aux->setGrau(0);
            aux->setNome(i);
            aux->setNeighbor(NULL);
            vertice->setProximo(aux);
            vertice = aux;
        }


    while( (fscanf(arq,"%d %d %d\n", &v1, &v2, &p))!=EOF ) {

        this->addVertice(v1,v2,p);
    }

    fclose(arq);

}

void Grafo::addVertice(int vertice1, int vertice2,int peso) {
    Vertice * vert1 = new Vertice();
    Vertice * vert2 = new Vertice();
    Aresta *aresta = new Aresta();
    bool existe =false;

    if(this->inicio == NULL)
    {
        this->inicio = vert1;
    }

    Vertice * aux = this->inicio;
    Vertice * vertAux = aux;
    Vertice * verticeAux;

    while(aux->getNome()!= vertice1){
        if(aux->getNome() == vertice2){
            vert2 =aux;
            existe = true;
        }else if (aux->getProximo() == NULL && !existe){
            vert2->setNome(vertice2);
            vert2->setNeighbor(NULL);
            vert2->setProximo(NULL);
            this->tamanho++;
        }
        aux =aux->getProximo();
        vertAux =aux;


        if(aux->getProximo() == NULL && aux->getNome()!=vertice1){
            aresta->setPeso(peso);
            aresta->setNomeVertice(vertice2);
            aresta->setDestino(vert2);
            aresta->setOrigem(vert1);
            vert1->setNome(vertice1);
            if (existe){
                vert1->setProximo(NULL);
            }else
                vert1->setProximo(vert2);

            vert1->setNeighbor(aresta);
            aux->setProximo(vert1);
            this->tamanho++;

            return;


        }

    }

    while(aux!=NULL){


        if(aux->getNome() == vertice2){
            vert2 =aux;
            existe = true;
        }
        verticeAux = aux;
        aux =aux->getProximo();
    }
    if (aux == NULL && !existe){
        vert2->setNome(vertice2);
        vert2->setNeighbor(NULL);
        vert2->setProximo(NULL);
        verticeAux->setProximo(vert2);
        this->tamanho++;
    }

    if(vertAux->getNeighbor() == NULL){
        aresta->setNomeVertice(vertice2);
        aresta->setPeso(peso);
        aresta->setVizinho(NULL);
        aresta->setOrigem(vertAux);
        aresta->setDestino(vert2);
        vertAux->setNeighbor(aresta);
    }else{
        Aresta *arestaAux =vertAux->getNeighbor();

        while(arestaAux->getVizinho()!=NULL){
            arestaAux = arestaAux->getVizinho();
        }
        aresta->setNomeVertice(vertice2);
        aresta->setPeso(peso);
        aresta->setVizinho(NULL);
        aresta->setOrigem(vertAux);
        aresta->setDestino(vert2);

        arestaAux->setVizinho(aresta);


    }

    
    }





Vertice *Grafo::getInicio() const {
    return inicio;
}

void Grafo::setInicio(Vertice *inicio) {
    Grafo::inicio = inicio;
}

int Grafo::getTamanho() const {
    return tamanho;
}

void Grafo::setTamanho(int tamanho) {
    Grafo::tamanho = tamanho;
}

void getline(char *str)
{
    scanf("%[^\n]s", str);
    fflush(stdin);
}



