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

int main() {

    ifstream file("../entradas/parametros.txt");
    int grauGrafo,v1,v2,p;


    char url[]="../entradas/parametros.txt";

    FILE *arq;

    arq = fopen(url, "r");
    if(arq == NULL)
        printf("Erro, nao foi possivel abrir o arquivo\n");
    else


        mostrarMenuPrincipal();

        fscanf(arq,"%d", &grauGrafo);
        Grafo *grafo = new Grafo(grauGrafo);
            while( (fscanf(arq,"%d %d %d\n", &v1, &v2, &p))!=EOF ) {

                grafo->addVertice(v1,v2,p);
            }

        cout<<"Grau do grafo: "<<grafo->getTamanho()<<endl;


    fclose(arq);

    return 0;
}

void mostrarMenuPrincipal() {
    int opcao = 0;
    while(opcao != 10){
        cout << "Selecione uma das opções abaixo: \n";
        cout << "01. Grau do grafo\n";
        cout << "02. Ordem do grafo\n";
        cout << "10. Sair\n\n";
        cout << "Opcao escolhida: ";
        cin >> opcao;
    }

    switch (opcao) {
        case 2 || 02: {
            cout << "O grafo tem a ordem -> " << g1->ordemGrafo() << " !!\n" << endl;
            break;
        }
    }

}
