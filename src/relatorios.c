#include "../include/relatorios.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void listar_todos_registros_rh(no_t *ptr_lista_rh)
{
    limpar_tela();

    msg_cabecalho("Relatorio de Funcionarios");

    while (ptr_lista_rh) {
        mostrar_dados_registro_rh(ptr_lista_rh);
        ptr_lista_rh = ptr_lista_rh->proximo;
        printf("\n");
    }
    msg_press_enter();
}

void mostrar_dados_registro_rh(no_t *registro)
{
    
    printf("Codigo.....................: %hhi\n", registro->dados.codigo);
    printf("Nome da pessoa.............: %s\n", registro->dados.nome);
    printf("Email da pessoa............: %s\n", registro->dados.email);
    printf("CPF da pessoa..............: %s\n", registro->dados.cpf);
    printf("Funcao.....................: %s\n", registro->dados.funcao);
    printf("Salario....................: %.2f\n", registro->dados.salario);
    printf("Data da admissao...........: %d/%d/%d\n", registro->dados.admissao.dia, registro->dados.admissao.mes, registro->dados.admissao.ano);
    if (registro->dados.status == INATIVO) {
        printf("Data da demissao...........: %d/%d/%d\n", registro->dados.demissao.dia, registro->dados.demissao.mes, registro->dados.demissao.ano);
    }
    printf("Status.....................: %d\n", registro->dados.status);

}

void relatorio_faixa_salarial(no_t *ptr_lista_rh, float minSal, float maxSal)
{
    no_t *ptr_atual = ptr_lista_rh;
    int contador = 0;

    printf("Funcionarios com salario entre R$ %.2f e R$ %.2f: \n\n", minSal, maxSal);

    //percorrer a lista
    while(ptr_atual)
    {
        //verificar se o salario esta dentro da faixa
        if (ptr_atual->dados.salario >= minSal && ptr_atual->dados.salario <= maxSal)
        {
            mostrar_dados_registro_rh(ptr_atual);
            printf("\n======================================\n");
            contador++;
        }
        ptr_atual = ptr_atual->proximo;
    }

    if (contador<1)
    {
        printf("Nenhum funcionario encontrado dentro desta faixa\n");
        msg_press_enter();
    }
}

void mostrar_funcionarios_ativos(no_t *ptr_lista_rh)
{
    limpar_tela();

    msg_cabecalho("Relatorio de Funcionarios Ativos");

    while (ptr_lista_rh) {

        if(ptr_lista_rh->dados.status == ATIVO){
            mostrar_dados_registro_rh(ptr_lista_rh);            
            printf("\n");
        }

        ptr_lista_rh = ptr_lista_rh->proximo;
    }

    msg_press_enter();
}

void listar_funcionarios_por_funcao(string funcao, no_t *ptr_lista_rh)
{
    bool flag = false;

    limpar_tela();

    msg_cabecalho("Relatorio de Funcionarios por Funcao");

    while (ptr_lista_rh) {

        if(strcmp(funcao, ptr_lista_rh->dados.funcao) == 0){
            mostrar_dados_registro_rh(ptr_lista_rh);            
            printf("\n");

            flag = true;
        }

        ptr_lista_rh = ptr_lista_rh->proximo;
    }

    if (!flag) {
        printf("Nao ha funcionarios exercendo a funcao %s\n", funcao);
    }

    msg_press_enter();

}
