#ifndef _H_QUARTO
#define _H_QUARTO

#define MAX1Q 50 // nomes de estudantes, gerentes, residˆencias, universidades e localidades
#define MAX2Q 20 // restante
#define MAX3Q 200// descricao
#define MAX_CANDIDATURAS 200 // n tem limite, apenas exemplo
#define LIVRE "livre"
#define OCUPADO "ocupado"

/* Tipos do TAD quarto */
typedef struct _quarto *quarto;
/* Protótipos das funções associadas a um quarto */


quarto criarQuarto(char* codigo, void* gerente, char* nomeResidencia, char* universidade, char* localidade, int andar, char* descricao);


void destroiQuarto(quarto q);

void destroiQuartoGen(void* q);






#endif