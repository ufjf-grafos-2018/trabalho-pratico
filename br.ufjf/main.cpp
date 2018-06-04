#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <iostream>
#include <vector>
#include "grafo/Grafo.h"

using namespace std;

int main() {

    ifstream file("/home/rodolpho/Documentos/parametros.txt");
    int grauGrafo,v1,v2,p;


    char url[]="/home/rodolpho/Documentos/parametros.txt";

    FILE *arq;

    arq = fopen(url, "r");
    if(arq == NULL)
        printf("Erro, nao foi possivel abrir o arquivo\n");
    else

        fscanf(arq,"%d", &grauGrafo);
        Grafo *grafo = new Grafo(grauGrafo);
            while( (fscanf(arq,"%d %d %d\n", &v1, &v2, &p))!=EOF ) {

                grafo->addVertice(v1,v2,p);
            }

        cout<<"Grau do grafo: "<<grafo->getTamanho()<<endl;


    fclose(arq);

    return 0;
}
