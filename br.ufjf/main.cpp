#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <iostream>
#include <vector>
#include "grafo/Grafo.h"

using namespace std;
void mostrarMenuPrincipal();

Grafo *grafo;

int main() {

    ifstream file("../entradas/parametros.txt");
    int grauGrafo,v1,v2,p;


    string url="../entradas/parametros.txt";

    grafo = new Grafo(url);

    mostrarMenuPrincipal();
    return 0;
}

void mostrarMenuPrincipal() {
    int opcao = 0;
    while(opcao != 10){
        cout << "Selecione uma das opções abaixo:" << endl;
        cout << "01. Grau do grafo" << endl;
        cout << "02. Ordem do grafo"<< endl;
        cout << "10. Sair\n"<< endl;
        cout << "Opcao escolhida: ";
        cin >> opcao;


        switch (opcao) {
            case 1 || 01 : {
                cout<<"Grau do grafo: "<< grafo->getTamanho()<<endl;
                break;

            }

        }
    }

}
