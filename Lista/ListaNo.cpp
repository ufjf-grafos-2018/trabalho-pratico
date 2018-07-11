//
// Created by maxjf1 on 10/07/18.
//

#include "ListaNo.h"

ListaNo::ListaNo() {}

ListaNoItem *ListaNo::getInicio() {
    return this->inicio;
}

void ListaNo::setInicio(ListaNoItem *inicio) {
    this->inicio = inicio;
}

void ListaNo::insert(No *no) {
    ListaNoItem *item = new ListaNoItem(no);
    item->setProx(this->getInicio());
    this->setInicio(item);
}

void ListaNo::insertEnd(No *no) {
    if (getInicio())
        this->inicio->insertEnd(no);
    else
        insert(no);
}

No *ListaNo::getNo(int index) {
    return getInicio() ? getInicio()->getNo(index) : nullptr;
}

void ListaNo::remove(int index) {
    if (getInicio())
        setInicio(getInicio()->remove(index));
}

int ListaNo::getSize() {
    return getInicio() ? getInicio()->getSize() : 0;
}
