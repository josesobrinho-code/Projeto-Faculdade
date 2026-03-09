#ifndef CONTATOS_H
#define CONTATOS_H

// Limite máximo de contatos
#define MAX_CONTATOS 100

// Tamanhos dos campos
#define TAM_NOME 100
#define TAM_TELEFONE 20
#define TAM_EMAIL 100

// Struct que representa um contato
typedef struct {
    char nome[TAM_NOME];
    char telefone[TAM_TELEFONE];
    char email[TAM_EMAIL];
} Contato;

// Protótipos das funções
void cadastrarContato(Contato lista[], int *total);
void listarContatos(Contato lista[], int total);
int buscarContato(Contato lista[], int total, char *nomeBuscado);
void editarContato(Contato lista[], int total);
void excluirContato(Contato lista[], int *total);
int contarContatosRecursivo(Contato lista[], int total, int indice, char letra);
void exibirEstatisticas(Contato lista[], int total);
void limparBuffer();

#endif
