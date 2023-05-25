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

// 1 - caso exista o estudante
// 0 - caso não exista o estudante
int existeEstudanteGestor(gestor g,char* login);

// 1 - caso exista o gerente
// 0 - caso não exista o gerente
int existeGerenteGestor(gestor g,char* login);

//Retorna 1 se adicionar, e 0, caso contrário
int novoEstudanteGestor (gestor g,char* login, char* nomeEstudante, int idade, char* localidade, char* universidade);

//Retorna 1 se adicionar, e 0, caso contrário
int novoGerenteGestor (gestor g, char* login, char* nomeGerente, char* universidade);

int novoQuartoGestor (gestor g, char* codigo, char* loginGerente, char* nomeResidencia, char* universidade, char* localidade, char* descricao, int andar);

/*//RETORNA A INFORMAÇAO DE UM UTILIZADOR ESTUDANTE
char * LoginEstudante(gestor g, int login);*/
estudante EstudanteGestor(gestor g, char*ch);

gerente GerenteGestor(gestor g, char* ch);

quarto QuartoGestor(gestor g, char* ch);

// 1 - caso exista o quarto
// 0 - caso não exista o quarto
int existeQuartoGestor(gestor g, char* codigo);


#endif /* _H_GESTOR */