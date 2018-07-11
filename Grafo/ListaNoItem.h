/**
 * Classe para item de listas de nós
 */

#ifndef TRABALHO_GRAFOS_LNITEM_H
#define TRABALHO_GRAFOS_LNITEM_H


#include "No.h"

class ListaNoItem {
private:
    No *content = nullptr;
    ListaNoItem *prox = nullptr;
public:
    /**
     * Construtor
     * @param content No do item da lista
     */
    ListaNoItem(No *content);

    /**
     * Obtém o próximo item
     * @return
     */
    ListaNoItem *getProx();

    /**
     * Atualiza o próximo item
     * @param prox
     */
    void setProx(ListaNoItem *prox);

    /**
     * Obtém o conteúdo
     * @return
     */
    No *getContent();

    /**
     * Obtém um item pelo indice
     *
     * Navega de forma recursiva nos descendentes
     * @param index
     * @return
     */
    ListaNoItem *get(int index);

    /**
     * Obtém o conteúdo de uma busca pelo índice
     * @param index
     * @return
     */
    No *getNo(int index);

    /**
     * Insere no fim da lista
     * @param no
     */
    void insertEnd(No *no);

    /**
     * Insere no descendente imediato do item
     * @param no
     */
    void insert(No *no);

    /**
     * Remove item da lista
     *
     * Navega de forma recursiva
     * @param index
     * @return
     */
    ListaNoItem *remove(int index);

    /**
     * Obtém o tamanho da lista
     * @return
     */
    int getSize();
};


#endif //TRABALHO_GRAFOS_LNITEM_H
