#include "../include/consultas.h"
#include <string.h>

no_t *consulta_pessoa_por_nome(string nome, no_t *lista){
    // Se a lista estiver vazia retorna nulo
    if (lista == NULL) {
        return NULL;
    }

    // Se o nome for encontrado retorna o nó
    if (strcmp(nome, lista->dados.nome) == 0) return lista;

    // Chama a função para o próximo nó da lista
    return consulta_pessoa_por_nome(nome, lista->proximo);
}