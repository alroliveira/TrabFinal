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



#endif /* _H_GESTOR */