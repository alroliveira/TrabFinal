/*
 * gestor.h
 */

#ifndef _H_GESTOR
#define _H_GESTOR

/* Tipo de dados: gestor */
typedef struct _gestor * gestor;

/* Protótipos das funções */

gestor criaGestor();
void destroiGestor(gestor g);
void destroiGestorEElems(gestor g);

// 1 - caso exista o aluno
// 0 - caso não exista o aluno
int existeEstudanteGestor(gestor g,char login);

// 1 - caso exista o aluno
// 0 - caso não exista o aluno
int existeGerenteGestor(gestor g,char login);

#endif /* _H_GESTOR */