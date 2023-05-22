#include <stdlib.h>
#include <string.h>

#include "quarto.h"
#include "iterador.h"
#include "sequencia.h"
#include "estudante.h"
#include "gerente.h"

#define MAX1 50 // nomes de estudantes, gerentes, residˆencias, universidades e localidades
#define MAX2 20 // restante
#define MAX3 200// descricao
#define MAX_CANDIDATURAS 200 // <-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define LIVRE "livre"
#define OCUPADO "ocupado"


/* Estrutura de dados do TAD ticket */
struct _quarto{
    char codigo[MAX2];
    gerente g;
    char nomeResidencia[MAX1];
    char universidade[MAX1];
    char localidade[MAX1];
    int andar;
    char descricao[MAX3];
    char estado[MAX1];
    sequencia estudantes;
};

quarto criarQuarto(char codigo[MAX2], gerente g, char nomeResidencia[MAX1], char universidade[MAX1], char localidade[MAX1], int andar, char descricao[MAX3]){
    quarto q;
    q = (quarto) malloc(sizeof(struct _quarto));
    if (q==NULL) return NULL;
    q->g = (gerente)malloc(sizeof(gerente));
    if (q->g == NULL){
        free (q);
        return NULL;
    }

    strcpy(q->codigo, codigo);
    q->g = g;
    strcpy(q->nomeResidencia, nomeResidencia);
    strcpy(q->universidade, universidade);
    strcpy(q->localidade, localidade);
    q->andar = andar;
    strcpy(q->descricao, descricao);
    strcpy(q->estado, LIVRE);
    q->estudantes = criaSequencia(MAX_CANDIDATURAS);
}

void destroiQuarto(quarto q){
    free(q->g);
    free(q);
}

void destroiQuartoGen(void* q){
    destroiQuarto((quarto) q);
}