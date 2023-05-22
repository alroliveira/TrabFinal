#ifndef _H_ESTUDANTE
#define _H_ESTUDANTE

#define MAX1 10 //ver os valores
#define MAX2 10

/* Tipos do TAD estudante */
typedef struct _estudante * estudante;
/* Protótipos das funções associadas a um estudante */

estudante criaEstudante(char login, char nomeEstudante, int idade, char localidade, char universidade);
void destroiEstudante(estudante e);
void destroiEstudanteGen (void* e);




#endif