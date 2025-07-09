#include "../include/cadastros.h"
#include "../include/utils.h"
#include <stdlib.h>
#include <stdio.h>

bool is_lista_rh_vazia(no_t *ptr_lista_rh){
    if (ptr_lista_rh) return false;  // Lista não vazia
    
    return true; // Lista vazia
}

void inicializa_lista_rh(lista_t *lista_rh){
    lista_rh->cabeca = NULL;
    lista_rh->nr_nos = 0;
}

no_t *localizar_ultimo_registro_rh(no_t *ptr_lista_rh){
    while (ptr_lista_rh->proximo) {
        ptr_lista_rh = ptr_lista_rh->proximo;
    }
    
    return ptr_lista_rh;
}

no_t *novo_registro_rh() {
    no_t *novo;

    // Aloca um novo registro na heap
    novo = (no_t*)malloc(sizeof(no_t));

    if (!novo) return NULL;

    // Interage com o usuário

    // Código (provisório)
    novo->dados.codigo = 0;

    // Nome
    printf("Nome da pessoa.............: ");
    fgets(novo->dados.nome, T_STR, stdin);
    retirar_enter(novo->dados.nome);
    to_upper(novo->dados.nome);

    // Email
    printf("Email da pessoa............: ");
    fgets(novo->dados.email, T_STR, stdin);
    retirar_enter(novo->dados.email);
    to_upper(novo->dados.email);

    // CPF
    printf("CPF da pessoa..............: ");
    fgets(novo->dados.cpf, T_CPF, stdin);
    retirar_enter(novo->dados.cpf);

    // Função
    printf("Funcao.....................: ");
    fgets(novo->dados.funcao, T_STR, stdin);
    retirar_enter(novo->dados.funcao);
    to_upper(novo->dados.funcao);

    // Salario
    printf("Salario....................: ");
    scanf("%f", &novo->dados.salario);

    // Data da admissao
    printf("Data da admissao...........: ");
    scanf("%d/%d/%d", &novo->dados.admissao.dia, &novo->dados.admissao.mes, &novo->dados.admissao.ano);

    // Preenche demissão com zeros
    novo->dados.demissao.dia = 0;
    novo->dados.demissao.mes = 0;
    novo->dados.demissao.ano = 0;

    // Status
    novo->dados.status = ATIVO;

    // Inicializar o ponteiro proximo
    novo->proximo = NULL;

    return novo;
}

void insere_registro_inicio_rh(no_t *novo, lista_t *lista_rh) {
    // Define o codigo
    novo->dados.codigo = ++lista_rh->nr_nos;

    if (is_lista_rh_vazia(lista_rh->cabeca)) {
        lista_rh->cabeca = novo;
        return;
    }

    novo->proximo = lista_rh->cabeca;
    lista_rh->cabeca = novo;
}

void insere_registro_fim_rh(no_t *novo, lista_t *lista_rh) {
    if (!novo || !lista_rh) {
        printf("Funcionário ou lista inválidos\n");
        return; }

    // Atribui o código ao funcionário e incrementa o contador de nós da lista
    novo->dados.codigo = ++lista_rh->nr_nos;
    novo->dados.codigo = NULL;

    //verifica se a lista está vazia
    if (is_lista_rh_vazia(lista_rh->cabeca)) {
        lista_rh->cabeca = novo;
    }   else { //encontar o ultimo registro e atribui o fim a ele 
        no_t *ultimo = localizar_ultimo_registro_rh(lista_rh->cabeca);
        ultimo->proximo = novo;
    }
}

void excluir_registro_rh(string nome , no_t *registro, lista_t *lista_rh) {
    no_t *anterior = NULL , *atual = registro;

    if (!registro || !lista_rh) {
        printf("Funcionário ou lista inválidos\n");
        return; }
    
    // encontrar o nó e o seu anterior
        while (atual != NULL && strcmp(nome, atual->dados.nome) != 0) {
        anterior = atual;       
        atual = atual->proximo; 
    }

    // Verifica se a pessoa foi encontrada
    if (atual == NULL) {
        printf("Funcionário %s não foi encontrado na lista para exclusão.\n", nome);
        return NULL; 
    }

    // Excluir o nó encontrado
    if (anterior == NULL) {
        registro = atual->proximo; // A cabeça da lista precisa ser atualizada para o próximo nó
    } else {
        anterior->proximo = atual->proximo; // O nó anterior aponta para o próximo do nó atual 
    }

    // Libera a memória do nó excluído
    printf("Funcionário %s foi excluído da lista com sucesso.\n", atual->dados.nome);
    free(atual); 

    return registro; 
}

void inativar_funcionario(no_t *registro, data_t data) {
    registro->dados.status = INATIVO;
    registro->dados.demissao = data;
}
