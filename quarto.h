#ifndef _H_QUARTO
#define _H_QUARTO

#define MAX1 10 //ver os valores


/* Tipos do TAD estudante */
typedef struct _quarto * quarto;
/* Protótipos das funções associadas a um quarto */

quarto criarQuarto(char codigo[MAX2], gerente g, char nomeResidencia[MAX1], char universidade[MAX1], char localidade[MAX1], int andar, char descricao[MAX3]);
void destroiQuarto(quarto q);
void destroiQuartoGen(void* q);






#endif