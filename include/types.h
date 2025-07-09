#ifndef TYPES_H
#define TYPES_H

#include <stddef.h>
#include <stdint.h>

#define T_STR   100
#define T_CPF   15

// Define tipo string
typedef char string[T_STR];

// Define tipo CPF
typedef char cpf_t[T_CPF];

// Define tipo status
typedef enum {ATIVO = 1, INATIVO = 2} status_t;

// Define data
typedef struct data {
    int dia;
    int mes;
    int ano;
} data_t;

// Define o tipo dados funcionario
typedef struct dados_func {
    uint8_t codigo;
    string nome;
    string email;
    cpf_t cpf;
    string funcao;
    float salario;
    data_t admissao;
    data_t demissao;
    status_t status;
} dados_func_t;

// Define membro da lista (no/nodo)
typedef struct no {
    dados_func_t dados;
    struct no *proximo;
} no_t;

// Define tipo lista;
typedef struct lista {
    no_t *cabeca;
    uint8_t nr_nos;
} lista_t;


#endif