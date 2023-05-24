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

//Retorna 1 se adicionar, e 0, caso contrário
int novoGerenteGestor (gestor g, char* login, char* nomeGerente, char* universidade);


/*//RETORNA A INFORMAÇAO DE UM UTILIZADOR ESTUDANTE
char * LoginEstudante(gestor g, int login);*/
void *EstudanteGestor(gestor g, char*ch);

void *GerenteGestor(gestor g, char* ch);

// 1 - caso exista o aluno
// 0 - caso não exista o aluno
int existeQuartoGestor(gestor g, char* codigo);


#endif /* _H_GESTOR */