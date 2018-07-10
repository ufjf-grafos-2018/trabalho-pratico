//
// Created by maxjf1 on 10/07/18.
//

#ifndef TRABALHO_GRAFOS_LISTANO_H
#define TRABALHO_GRAFOS_LISTANO_H

#include "../Grafo/No.h"
#include "ListaNoItem.h"


class ListaNo {
private:
    ListaNoItem *inicio = nullptr;

    void setInicio(ListaNoItem *inicio);

public:

    ListaNo();

    ListaNoItem *getInicio();

    void insert(No *no);

    void insertEnd(No *no);

    No *getNo(int index);

    void remove(int index);

    int getSize();
};


#endif //TRABALHO_GRAFOS_LISTANO_H
