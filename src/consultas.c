#include "../include/consultas.h"
#include <string.h>

no_t *consulta_pessoa_por_nome(string nome, no_t *lista)
{
    while (lista) {

        if (strcmp(nome, lista->dados.nome) == 0) {
            return lista;
        }
        
        lista = lista->proximo;
    }

    return NULL;
}