#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include "types.h"

void retirar_enter(string str);
void to_upper(string str);
void limpar_tela();
void msg_press_enter();
void msg_cabecalho(string msg);
void ordenar_em_ordem_alfabetica(lista_t * lista_rh);

#endif