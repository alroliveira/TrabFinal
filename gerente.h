#ifndef _H_GERENTE
#define _H_GERENTE

#define MAX1 10 //ver os valores


/* Tipos do TAD estudante */
typedef struct _gerente * gerente;
/* Protótipos das funções associadas a um gerente */

gerente criaGerente(char login, char nomeGerente, char universidade);
void destroiGerente(gerente g);
void destroiGerenteGen (void* g);



#endif