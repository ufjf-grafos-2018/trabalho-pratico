//
// Created by maxjf1 on 10/07/18.
//

#include "ListaNoItem.h"


ListaNoItem *ListaNoItem::getProx() {
    return this->prox;
}

void ListaNoItem::setProx(ListaNoItem *prox) {
    this->prox = prox;
}

No *ListaNoItem::getContent() {
    return this->content;
}

ListaNoItem *ListaNoItem::get(int index) {
    if (index == 0)
        return this;
    if (!getProx())
        return nullptr;
    return getProx()->get(index - 1);
}

void ListaNoItem::insert(No *no) {
    ListaNoItem *aux = new ListaNoItem(no);
    aux->setProx(getProx());
    setProx(aux);
}

void ListaNoItem::insertEnd(No *no) {
    if (!getProx())
        insert(no);
    else
        getProx()->insertEnd(no);
}

ListaNoItem::ListaNoItem(No *content) : content(content) {}

No *ListaNoItem::getNo(int index) {
    ListaNoItem *no = get(index);
    return no ? no->getContent() : nullptr;
}

ListaNoItem *ListaNoItem::remove(int index) {
    if (index == 0)
        return getProx();
    if (getProx())
        setProx(getProx()->remove(index - 1));
    return this;
}

int ListaNoItem::getSize() {
    return getProx() ? getProx()->getSize() + 1 : 1;
}
