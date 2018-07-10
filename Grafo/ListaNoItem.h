//
// Created by maxjf1 on 10/07/18.
//

#ifndef TRABALHO_GRAFOS_LNITEM_H
#define TRABALHO_GRAFOS_LNITEM_H


#include "No.h"

class ListaNoItem {
private:
    No *content = nullptr;
    ListaNoItem *prox = nullptr;
public:
    ListaNoItem(No *content);

    ListaNoItem *getProx();

    void setProx(ListaNoItem *prox);

    No *getContent();

    ListaNoItem *get(int index);

    No *getNo(int index);

    void insertEnd(No *no);

    void insert(No *no);

    ListaNoItem *remove(int index);

    int getSize();
};


#endif //TRABALHO_GRAFOS_LNITEM_H
