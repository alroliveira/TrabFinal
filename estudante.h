#ifndef _H_ESTUDANTE
#define _H_ESTUDANTE

#define MAX1E 10 //ver os valores
#define MAX2E 10

/* Tipos do TAD estudante */
typedef struct _estudante * estudante;
/* Protótipos das funções associadas a um estudante */

estudante criaEstudante(char* login, char* nomeEstudante, int idade, char* localidade, char* universidade);
void destroiEstudante(estudante e);
void destroiEstudanteGen (void* e);




#endif