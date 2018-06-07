#include <iostream>
#include <fstream>
#include <cstring>
#include "Grafo/Grafo.h"

using namespace std;

Grafo *grafo = new Grafo();

void mostrarMenuPrincipal();

int main() {
    int grauGrafo, v1, v2, p;
    string nomeArquivoEntrada ="../Arquivos/entrada.txt";

    ifstream file(nomeArquivoEntrada);
    char *url = new char[nomeArquivoEntrada.length() + 1];
    strcpy(url, nomeArquivoEntrada.c_str());

    FILE *arq;

    arq = fopen(url, "r");
    if (arq == NULL)
        printf("Erro, nao foi possivel abrir o arquivo\n");
    else
        fscanf(arq, "%d", &grauGrafo);

    grafo->setTamanho(grauGrafo);

    while ((fscanf(arq, "%d %d %d\n", &v1, &v2, &p)) != EOF) {

        grafo->addAresta(v1, v2, p);
    }

    mostrarMenuPrincipal();


    fclose(arq);
    grafo->print();

    grafo->printSequenciaGraus();

    return 0;
}

void mostrarMenuPrincipal() {
    int opcao = 0;
    int no=0;
    cout << "    ******  TRABALHO DE GRAFOS ******" << endl<< endl;

    while(opcao != 16) {
        cout << "Selecione uma das opções abaixo (número): " << endl << endl;
        cout << "1. Imprimir o Grafo" << endl;
        cout << "2. Grau do grafo" << endl;
        cout << "3. Grau do nó: " << endl;
        cout << "4. Ordem do grafo" << endl;
        cout << "5. O gafo é trivial?" << endl;
        cout << "6. O gafo é nulo?" << endl;
        cout << "7. O gafo é um multigrafo?" << endl;
        cout << "8. O gafo é completo?" << endl;
        cout << "9. O gafo é bipartido?" << endl;
        cout << "10. Sequência de graus" << endl;
        cout << "11. Excluir nó: " << endl;
        cout << "12. Excluir aresta: " << endl;
        cout << "13. Vizinhança aberta do nó: " << endl;
        cout << "14. Vizinhança fechada do nó: " << endl;
        cout << "15. Verificar k-regularidade: (k informado pelo usuário) " << endl;

        cout << "16. Sair\n" << endl;
        cout << "Opcao escolhida: ";
        cin >> opcao;


        switch (opcao) {
            case 1: {
                grafo->print();
                break;
            }
            case 2: {
                //número max de arestas de um vértice
                cout << "Grau do grafo: " <<  grafo->getGrau() << endl;
                break;
            }
            case 3: {
                cout << "Digite o nó desejado: " << endl;
                cin >> no;
                if(grafo->getGrauNo(no)){
                    cout << "Grau do nó " << no << " é: " << grafo->getGrauNo(no) << endl;
                }
                else {
                    cout << "Nó " << no << " não encontrado!" << endl;
                }
                break;
            }
            case 4: {
                //numero de vértices
                cout << "Ordem do grafo: " << grafo->getOrdem() << endl;
                break;
            }
            case 5: {
                break;
            }
            case 6: {
                break;
            }
            case 7: {
                break;
            }
            case 8: {
                break;
            }
            case 9: {
                break;
            }
            case 10: {
                cout << "Sequência de graus do grafo: \n" << grafo->getSequenciaGraus() << endl;
                break;
            }
            case 11: {
                break;
            }
            case 12: {
                break;
            }
            case 13: {
                break;
            }
            case 14: {
                break;
            }
            case 15: {
                break;
            }
        }
    }
}