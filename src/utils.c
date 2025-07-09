#include "../include/utils.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void retirar_enter(string str)
{
    *(str+strlen(str)-1) = '\0';
}

void to_upper(string str) 
{
    for (size_t i = 0; i < strlen(str); i++) {
        *(str+i) = toupper(*(str+i));
    }
}

void limpar_tela()
{
    system("clear");
}

void msg_press_enter()
{
    printf("\n-----------------------------------------------\n");
    printf("Pressione ENTER para retornar ao MENU RELATORIOS\n");
    getchar();
}

void msg_cabecalho(string msg)
{
    printf("----------------------------------------------\n");
    printf("%s\n", msg);
    printf("----------------------------------------------\n\n");
}

void ordenar_em_ordem_alfabetica(lista_t * lista_rh){
    if(lista_rh->cabeca==NULL || lista_rh->cabeca->proximo==NULL) return;
    
    no_t * aux = lista_rh->cabeca, *aux2, temp;

    while(aux){
        aux2=aux->proximo;
        while(aux2){
            if(strcmp(aux->dados.nome,aux2->dados.nome)>0){
                temp.dados=aux->dados;
                aux->dados=aux2->dados;
                aux2->dados=temp.dados;
            }
            aux2=aux2->proximo;
        }
        aux=aux->proximo;
    }
}