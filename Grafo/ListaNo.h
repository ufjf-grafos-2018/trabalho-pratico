/**
 * Classe para criação de listas encadeadas de nós
 */

#ifndef TRABALHO_GRAFOS_LISTANO_H
#define TRABALHO_GRAFOS_LISTANO_H

#include "No.h"
#include "ListaNoItem.h"


class ListaNo {
private:
    /**
     * Início da lista
     */
    ListaNoItem *inicio = nullptr;

    /**
     * Atualiza o início da lista
     * @param inicio
     */
    void setInicio(ListaNoItem *inicio);

public:

    ListaNo();

    /**
     * Obtém o início da lista
     * @return
     */
    ListaNoItem *getInicio();

    /**
     * Insere um nó na lista
     * @param no
     */
    void insert(No *no);

    /**
     * Insere um nó no fim da lista
     * @param no
     */
    void insertEnd(No *no);

    /**
     * Obtém um nó pelo indice de ordem da lista
     * @param index
     * @return
     */
    No *getNo(int index);

    /**
     * Remove nó pelo indice de ordem da lista
     * @param index
     */
    void remove(int index);

    /**
     * Obtém o tamanho da lista
     * @return
     */
    int getSize();
};


#endif //TRABALHO_GRAFOS_LISTANO_H
