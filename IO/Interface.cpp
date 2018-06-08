#include <fstream>
#include <cstring>
#include <iostream>
#include "Interface.h"

/**
 * Inicializa menu interativo
 * @param grafo
 */
void Interface::iniciaMenu(Grafo *grafo) {
    int opcao = 1;
    int aux1 = 0, aux2 = 0;

    while (opcao != 0) {
        imprimeMenu();
        cin >> opcao;
        limpaTela();
        switch (opcao) {
            case 1: {
                grafo->print();
                break;
            }
            case 2: {
                //número max de arestas de um vértice
                cout << "Grau do grafo: " << grafo->getGrau() << endl;
                break;
            }
            case 3: {
                cout << "Digite o nó desejado: " << endl;
                cin >> aux1;
                if (grafo->getGrauNo(aux1)) {
                    cout << "Grau do nó " << aux1 << " é: " << grafo->getGrauNo(aux1) << endl;
                } else {
                    cout << "Nó " << aux1 << " não encontrado!" << endl;
                }
                break;
            }
            case 4: {
                //numero de vértices
                cout << "Ordem do grafo: " << grafo->getOrdem() << endl;
                break;
            }
            case 5: {
                cout << "O grafo " << (grafo->isTrivial() ? "E" : "NAO E") << " trivial." << endl;
                break;
            }
            case 6: {
                cout << "O grafo " << (grafo->isNulo() ? "E" : "NAO E") << " nulo." << endl;
                break;
            }
            case 7: {
                break;
            }
            case 8: {
                cout << "O grafo " << (grafo->isCompleto() ? "E" : "NAO E") << " completo." << endl;
                break;
            }
            case 9: {
                break;
            }
            case 10: {
                cout << "Sequência de graus do grafo: ";
                grafo->printSequenciaGraus();
                cout << endl;
                break;
            }
            case 11: {
                cout << "Digite o nó desejado: " << endl;
                cin >> aux1;
                grafo->removeNo(aux1);
                cout << "Nó " << aux1 << " removido" << endl;
                grafo->print();
                break;
            }
            case 12: {
                cout << "Digite vertice de origem: " << endl;
                cin >> aux1;

                cout << "Digite vertice de destino: " << endl;
                cin >> aux2;
                grafo->removeAresta(aux1, aux2);
                cout << "Aresta removida" << endl;
                grafo->print();
                break;
            }
            case 13: {
                cout << "Digite o ID do nó: ";
                cin >> aux1;
                grafo->vizinhoAberto(aux1)->print();
                break;
            }
            case 14: {
                cout << "Digite o ID do nó: ";
                cin >> aux1;
                grafo->vizinhoFechado(aux1)->print();
                break;
            }
            case 15: {
                aux1 = grafo->kRegular();
                if (aux1 >= 0)
                    cout << "O grafo e " << aux1 << "-regular." << endl;
                else
                    cout << "O grafo nao e K-regular." << endl;
                break;
            }
            case 0: {
                cout << "Finalizando programa..." << endl;
                break;
            }
            default: {

                cout << "OPCAO INVALIDA!" << endl;
            }
        }
        pauseMenu();
    }
}

/**
 * Imprime o menu
 */
void Interface::imprimeMenu() {
    limpaTela();
    cout << "    ******  TRABALHO DE GRAFOS ******" << endl << endl;
    cout << "Selecione uma das opções abaixo (número): " << endl << endl;
    cout << "1.  Imprimir o Grafo" << endl;
    cout << "2.  Grau do grafo" << endl;
    cout << "3.  Grau do nó: " << endl;
    cout << "4.  Ordem do grafo" << endl;
    cout << "5.  O gafo é trivial?" << endl;
    cout << "6.  O gafo é nulo?" << endl;
    cout << "7.  O gafo é um multigrafo?" << endl;
    cout << "8.  O gafo é completo?" << endl;
    cout << "9.  O gafo é bipartido?" << endl;
    cout << "10. Sequência de graus" << endl;
    cout << "11. Excluir nó: " << endl;
    cout << "12. Excluir aresta: " << endl;
    cout << "13. Vizinhança aberta do nó: " << endl;
    cout << "14. Vizinhança fechada do nó: " << endl;
    cout << "15. Verificar k-regularidade: " << endl;
    cout << "0.  Sair\n" << endl;
    cout << "Opcao escolhida: ";
}

/**
 * Faz uma pausa no menu
 * TODO: tratar enter
 */
void Interface::pauseMenu() {
    cout << "Aperte qualquer tecla para continuar..." << endl;
    cin.get(); // captura ultimo enter...
    cin.get(); // captura novo enter...
}

/**
 * Limpa tela do menu
 * TODO: limpeza do SO
 */
void Interface::limpaTela() {
    for (int i = 0; i < 20; i++)
        cout << endl;
    cout.flush();
}
