//
// Created by maxjf1 on 21/05/18.
//
#include <stdio.h>
#include <iostream>
#include <algorithm>

#include "Grafo.h"

using namespace std;

/**
 * Construtor
 * @param tamanho Tamanho do grafo
 */
Grafo::Grafo(int tamanho) {
    init(tamanho);
}

/**
 * Construtor
 * @param tamanho Tamanho do grafo
 * @param digrafo Se é digrafo
 */
Grafo::Grafo(int tamanho, bool digrafo) : digrafo(digrafo) {
    init(tamanho);
}

/**
 * Inicializa o grafo
 * @param tamanho Quantidade de nós a serem adicionadas
 */
void Grafo::init(int tamanho) {
    for (int i = 1; i <= tamanho; ++i) {
        addNo(i);
    }
}

/**
 * Adiciona um nó ao grafo
 * @param id ID do nó
 */
void Grafo::addNo(int id) {
    No *no = new No(id);
    if (!isNulo()) {
        no->setProx(inicioLista);
    }
    inicioLista = no;
    tamanho++;
}

/**
 * Remove um nó do grafo
 * @param id ID do nó
 */
void Grafo::removeNo(int id) {
    No *no = inicioLista, *anterior;
    if (no != NULL && no->getId() == id) {
        inicioLista = no->getProx();
        removeArestas(no);
        delete no;
    } else {
        while (no != NULL && no->getId() != id) {
            anterior = no;
            no = no->getProx();
        }
        if (no != NULL) {
            anterior->setProx(no->getProx());
            removeArestas(no);
            delete no;
        }
    }
}

/**
 * Adiciona Aresta ao grafo
 * @param inicio ID do nó de origem
 * @param fim ID do nó de destino
 * @param peso
 */
void Grafo::addAresta(int inicio, int fim, int peso) {
    No *noInicio = NULL, *noFim = NULL, *atual = inicioLista;
    while ((noInicio == NULL || noFim == NULL) && atual != NULL) {
        if (atual->getId() == inicio) {
            noInicio = atual;
        }
        if (atual->getId() == fim) {
            noFim = atual;
        }
        atual = atual->getProx();
    }

    if (noInicio && noFim) {
        noInicio->addAresta(noFim, peso);
        if (!digrafo) {
            noFim->addAresta(noInicio, peso);
        }
    }

}

/**
 * Remove Aresta do grafo
 * @param inicio ID do nó de origem
 * @param fim ID do nó de destino
 */
void Grafo::removeAresta(int inicio, int fim) {
    No *noInicio = NULL, *noFim = NULL, *atual = inicioLista;
    while ((noInicio == NULL || noFim == NULL) && atual != NULL) {
        if (atual->getId() == inicio) {
            noInicio = atual;
        }
        if (atual->getId() == fim) {
            noFim = atual;
        }
        atual = atual->getProx();
    }

    if (noInicio && noFim) {
        noInicio->removeAresta(noFim);
        if (!digrafo) {
            noFim->removeAresta(noInicio);
        }
    }
}

/**
 * Se o grafo é nulo
 * @return
 */
bool Grafo::isNulo() {
    return inicioLista == NULL;
}

/**
 * Se o grafo é trivial
 * @return
 */
bool Grafo::isTrivial() {
    return inicioLista && inicioLista->getArestas() == NULL;
}

/**
 * Imprime o grafo
 */
void Grafo::print() {
    No *no = inicioLista;
    Aresta *aresta;

    cout << "Ordem do grafo: " << getOrdem() << endl;
    cout << "Grau do grafo: " << getGrau() << endl;
    cout << "Vertices: " << endl << endl << "------" << endl << endl;

    while (no) {
        aresta = no->getArestas();
        cout << "ID: \t" << no->getId() << endl;
        cout << "Grau: \t" << no->getGrau()<< endl;
        cout << "Arestas: " << endl;

        while (aresta) {
            cout << "\t=>" << aresta->getDestino()->getId() << ": " << aresta->getPeso()
                 << endl;
            aresta = aresta->getProx();
        }
        no = no->getProx();
        cout << "------" << endl << endl;
    }

}

/**
 * Remove as arestas de um nó
 * @param no
 */
void Grafo::removeArestas(No *no) {
    if (digrafo) {
        /**
         * Digrafo - varrer grafo em busca de incidências
         * TODO: Remoção caso seja digrafo - varredura
         */
    } else {
        /**
         * Não digrafo - remover arestas dos nós conectados apenas
         */
        cout << "Removendo arestas de " << no->getId() << endl;
        Aresta *aresta = no->getArestas();
        while (aresta) {
            aresta->getDestino()->removeAresta(no);
            aresta = aresta->getProx();
        }
    }
}

/**
 * Retorna a ordem do grafo
 * @return
 */
int Grafo::getOrdem() {
    return tamanho;
}

/**
 * Retorna o grau do grafo
 * @return
 */
int Grafo::getGrau() {
    int grau = 0, grauAtual;
    No *no = inicioLista;
    while (no) {
        if (no->getGrau() > grau)
            grau = no->getGrau();
        no = no->getProx();
    }
    return grau;
}

/**
 * Retorna grau de um Nó
 * @param id ID do nó
 * @return
 */
int Grafo::getGrauNo(int id) {
    No *no = getNo(id);
    if (no) return no->getGrau();
    return 0;
}

/**
 * Obtém um nó
 * @param id
 * @return
 */
No *Grafo::getNo(int id) {
    No *no = inicioLista;
    while (no) {
        if (no->getId() == id)
            return no;
        no = no->getProx();
    }
    return nullptr;
}

/**
 * Obtém a sequência de graus do grafo
 * @return
 */
int *Grafo::getSequenciaGraus() {
    int *graus = new int[tamanho];
    int i = 0;
    No *no = inicioLista;
    while (no) {
        graus[i] = no->getGrau();
        i++;
        no = no->getProx();
    }
    // Ordenação do array
    sort(graus, graus +  tamanho, std::greater<int>());

    return graus;
}

/**
 * Imprime a sequencia de graus do grafo
 */
void Grafo::printSequenciaGraus() {
    int *graus = getSequenciaGraus();

    cout << "[";
    for (int i = 0; i < tamanho; i++) {
        cout << graus[i] << (i + 1 == tamanho ? "" : ",");
    }
    cout << "]" << endl;

}

/**
 * Obtém a K-regularidade do grafo ou -1 se não existir
 * @return
 */
int Grafo::kRegular() {
    int *graus = getSequenciaGraus();
    int k = graus[0];
    for (int i = 1; i < tamanho; ++i) {
        if (k != graus[i]) {
            //cout << "Não É K-regular" <<  endl;
            return -1;
        }
    }
    //cout << "É " << k << "-regular." << endl;
    return k;
}

/**
 * Informa se o grafo é K-regular, dado K
 * @param k
 * @return
 */
bool Grafo::isKRegular(int k) {
    return kRegular() == k;
}

/**
 * Informa se o grafo é K-regular
 * @return
 */
bool Grafo::isKRegular() {
    return kRegular() >= 0;
}

/**
 * Informa se o grafo é completo
 * @return
 */
bool Grafo::isCompleto() {
    int *graus = getSequenciaGraus();
    for (int i = 0; i < tamanho; ++i) {
        if (graus[i] != tamanho - 1) {
//            cout << "O grafo não é completo." << endl;
            return false;
        }
    }
//    cout << "O grafo é completo." << endl;
    return true;

}

/**
 * retorna a vizinhança de um nó
 * @param id ID do nó
 * @param fechado se é vizinhança fechada ou aberta
 * @return
 */
Grafo *Grafo::vizinhanca(int id, bool fechado) {
    No *noBuscado = getNo(id);

    if (!noBuscado) {
        cout << "No " << id << "nao encontrado!";
        return NULL;
    }

    int i = 0, tamanhoVizinhos = noBuscado->getGrau();

    if (fechado)
        tamanhoVizinhos++;

    No **vizinhos = new No *[tamanhoVizinhos], *noAux;
    Grafo *vizinhanca = new Grafo();
    Aresta *arestaAux = noBuscado->getArestas();

    if (fechado) {
        vizinhanca->addNo(noBuscado->getId());
        vizinhos[0] = noBuscado;
        i = 1;
    }

    while (arestaAux) {
        vizinhanca->addNo(arestaAux->getDestino()->getId());
        vizinhos[i] = arestaAux->getDestino();
        arestaAux = arestaAux->getProx();
        i++;
    }

    for (i = 0; i < tamanhoVizinhos; i++) {
        noAux = vizinhos[i];
        arestaAux = noAux->getArestas();
        while (arestaAux) {

            for (int j = 0; j < tamanhoVizinhos; j++) {
                if (vizinhos[j] && arestaAux->getDestino() == vizinhos[j]) {
                    vizinhanca->addAresta(arestaAux->getOrigem()->getId(), arestaAux->getDestino()->getId(),
                                          arestaAux->getPeso());
                }
            }
            arestaAux = arestaAux->getProx();
        }
        vizinhos[i] = NULL;
    }
    return vizinhanca;
}

/**
 * Obtém a vizinhança fechada de um nó
 * @param id
 * @return
 */
Grafo *Grafo::vizinhoFechado(int id) {
    return vizinhanca(id, true);
}

/**
 * Obtém a vizinhança aberta de um nó
 * @param id
 * @return
 */
Grafo *Grafo::vizinhoAberto(int id) {
    return vizinhanca(id, false);
}

bool Grafo::multigrafo() {

    No *auxNo = this->inicioLista;
    Aresta *auxAresta;
    Aresta *aux;
    int id;

    while(auxNo->getProx() != NULL)
    {
        auxAresta= auxNo->getArestas();

        while(auxAresta !=NULL){
            aux=auxAresta->getProx();
            id = auxAresta->getDestino()->getId();
            while(aux !=NULL){
                if(id == aux->getDestino()->getId()) {
                    cout<<"ID: "<< id<<"AUX: "<< aux->getDestino()->getId()<<endl;
                    return false;
                }

                aux = aux->getProx();

            }
            auxAresta= auxAresta->getProx();
        }

        auxNo = auxNo->getProx();
    }

    return true;


}

No *Grafo::getInicioLista() const {
    return inicioLista;
}


bool Grafo::ehBipartido() {

        No *noAux = getInicioLista();
        Aresta *arestaAux = noAux->getArestas();
        int  V = this->tamanho;
        int result[V];


        result[0]  = 0;


        for (int u = 1; u < V; u++)
            result[u] = -1;


        bool available[V];
        for (int cr = 1; cr < V; cr++)
            available[cr] = false;


        while(noAux !=NULL)
        {

                arestaAux = noAux->getArestas();
                while(arestaAux!=NULL)
             {
                if (result[arestaAux->getDestino()->getId()-1] != -1) {
                    available[result[arestaAux->getDestino()->getId()-1]] = true;

                }

                arestaAux = arestaAux->getProx();
            }

            int cr;
            for (cr = 0; cr < V; cr++)
                if (available[cr] == false)
                    break;

            result[noAux->getId()] = cr;


            arestaAux = noAux->getArestas();
            while(arestaAux!=NULL){
                if (result[arestaAux->getDestino()->getId()-1] != -1)
                    available[arestaAux->getDestino()->getId()-1] = false;

                arestaAux = arestaAux->getProx();
            }

            noAux = noAux->getProx();
        }


        for (int u = V; u > 0; u--){


            cout << "Vertice " << u << " --->  Cor " << result[u] << endl;
        }


        for (int u = V; u > 0;u--){
            if (result[u]>1)
                return false;

        }
    return true;
}