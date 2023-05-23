/*
 * gestor.h
 */

#ifndef _H_GESTOR
#define _H_GESTOR

#define CAP_ESTUDANTES 20000
#define CAP_GERENTES 1000
#define CAP_QUARTOS 10000

/* Tipo de dados: gestor */
typedef struct _gestor * gestor;

/* Protótipos das funções */

gestor criaGestor();

void destroiGestor(gestor g);

void destroiGestorEElems(gestor g);

// 1 - caso exista o aluno
// 0 - caso não exista o aluno
int existeEstudanteGestor(gestor g,char* login);

// 1 - caso exista o aluno
// 0 - caso não exista o aluno
int existeGerenteGestor(gestor g,char* login);

//Retorna 1 se adicionar, e 0, caso contrário
int novoEstudanteGestor (gestor g,char* login, char* nomeEstudante, int idade, char* localidade, char* universidade);


#endif /* _H_GESTOR */