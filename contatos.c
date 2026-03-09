#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contatos.h"

// Limpa o buffer do teclado após leituras
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// ─────────────────────────────────────────────
// PESSOA 2 – Cadastrar contato
// ─────────────────────────────────────────────
void cadastrarContato(Contato lista[], int *total) {
    if (*total >= MAX_CONTATOS) {
        printf("\nLista cheia! Não é possível cadastrar mais contatos.\n");
        return;
    }

    Contato *novo = &lista[*total];

    printf("\n--- CADASTRAR CONTATO ---\n");

    printf("Nome: ");
    fgets(novo->nome, TAM_NOME, stdin);
    novo->nome[strcspn(novo->nome, "\n")] = '\0'; // remove o '\n'

    printf("Telefone: ");
    fgets(novo->telefone, TAM_TELEFONE, stdin);
    novo->telefone[strcspn(novo->telefone, "\n")] = '\0';

    printf("Email: ");
    fgets(novo->email, TAM_EMAIL, stdin);
    novo->email[strcspn(novo->email, "\n")] = '\0';

    (*total)++;
    printf("\nContato cadastrado com sucesso!\n");
}

// ─────────────────────────────────────────────
// PESSOA 2 – Listar contatos
// ─────────────────────────────────────────────
void listarContatos(Contato lista[], int total) {
    printf("\n--- LISTA DE CONTATOS (%d/%d) ---\n", total, MAX_CONTATOS);

    if (total == 0) {
        printf("Nenhum contato cadastrado.\n");
        return;
    }

    int i;
    for (i = 0; i < total; i++) {
        printf("\n[%d] Nome:     %s\n", i + 1, lista[i].nome);
        printf("    Telefone: %s\n", lista[i].telefone);
        printf("    Email:    %s\n", lista[i].email);
    }
}

// ─────────────────────────────────────────────
// PESSOA 3 – Buscar contato por nome
// Retorna o índice do contato ou -1 se não encontrar
// ─────────────────────────────────────────────
int buscarContato(Contato lista[], int total, char *nomeBuscado) {
    int i;
    for (i = 0; i < total; i++) {
        // Comparação sem diferenciar maiúsculas/minúsculas
        if (strcasecmp(lista[i].nome, nomeBuscado) == 0) {
            return i;
        }
    }
    return -1;
}

// ─────────────────────────────────────────────
// PESSOA 3 – Editar contato
// ─────────────────────────────────────────────
void editarContato(Contato lista[], int total) {
    if (total == 0) {
        printf("\nNenhum contato para editar.\n");
        return;
    }

    char nomeBusca[TAM_NOME];
    printf("\n--- EDITAR CONTATO ---\n");
    printf("Digite o nome do contato a editar: ");
    fgets(nomeBusca, TAM_NOME, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    int indice = buscarContato(lista, total, nomeBusca);

    if (indice == -1) {
        printf("\nContato '%s' não encontrado.\n", nomeBusca);
        return;
    }

    Contato *c = &lista[indice];
    printf("\nContato encontrado. Deixe em branco para manter o valor atual.\n");

    char temp[TAM_NOME];

    printf("Nome atual [%s]: ", c->nome);
    fgets(temp, TAM_NOME, stdin);
    temp[strcspn(temp, "\n")] = '\0';
    if (strlen(temp) > 0) strcpy(c->nome, temp);

    printf("Telefone atual [%s]: ", c->telefone);
    fgets(temp, TAM_TELEFONE, stdin);
    temp[strcspn(temp, "\n")] = '\0';
    if (strlen(temp) > 0) strcpy(c->telefone, temp);

    printf("Email atual [%s]: ", c->email);
    fgets(temp, TAM_EMAIL, stdin);
    temp[strcspn(temp, "\n")] = '\0';
    if (strlen(temp) > 0) strcpy(c->email, temp);

    printf("\nContato editado com sucesso!\n");
}

// ─────────────────────────────────────────────
// PESSOA 3 – Excluir contato
// ─────────────────────────────────────────────
void excluirContato(Contato lista[], int *total) {
    if (*total == 0) {
        printf("\nNenhum contato para excluir.\n");
        return;
    }

    char nomeBusca[TAM_NOME];
    printf("\n--- EXCLUIR CONTATO ---\n");
    printf("Digite o nome do contato a excluir: ");
    fgets(nomeBusca, TAM_NOME, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    int indice = buscarContato(lista, *total, nomeBusca);

    if (indice == -1) {
        printf("\nContato '%s' não encontrado.\n", nomeBusca);
        return;
    }

    // Confirmação antes de excluir
    char confirmacao;
    printf("Tem certeza que deseja excluir '%s'? (s/n): ", lista[indice].nome);
    scanf("%c", &confirmacao);
    limparBuffer();

    if (confirmacao != 's' && confirmacao != 'S') {
        printf("Exclusão cancelada.\n");
        return;
    }

    // Desloca os elementos para preencher o espaço do excluído
    int i;
    for (i = indice; i < (*total) - 1; i++) {
        lista[i] = lista[i + 1];
    }

    (*total)--;
    printf("\nContato excluído com sucesso!\n");
}

// ─────────────────────────────────────────────
// PESSOA 4 – Função recursiva
// Conta quantos contatos têm nome começando com uma letra
// ─────────────────────────────────────────────
int contarContatosRecursivo(Contato lista[], int total, int indice, char letra) {
    // Caso base: percorreu todos os contatos
    if (indice == total) return 0;

    // Verifica se o nome atual começa com a letra (ignorando maiúsculas)
    int encontrou = (tolower((unsigned char)lista[indice].nome[0]) == tolower((unsigned char)letra)) ? 1 : 0;

    // Chama recursivamente para o próximo
    return encontrou + contarContatosRecursivo(lista, total, indice + 1, letra);
}

// ─────────────────────────────────────────────
// PESSOA 4 – Exibir estatísticas
// ─────────────────────────────────────────────
void exibirEstatisticas(Contato lista[], int total) {
    printf("\n--- ESTATÍSTICAS ---\n");

    if (total == 0) {
        printf("Nenhum contato cadastrado.\n");
        return;
    }

    printf("Total de contatos: %d/%d\n", total, MAX_CONTATOS);
    printf("Slots disponíveis: %d\n", MAX_CONTATOS - total);

    // Usa a função recursiva para contar por letra
    printf("\nContatos por letra inicial (recursivo):\n");
    char letra;
    for (letra = 'A'; letra <= 'Z'; letra++) {
        int quantidade = contarContatosRecursivo(lista, total, 0, letra);
        if (quantidade > 0) {
            printf("  %c: %d contato(s)\n", letra, quantidade);
        }
    }
}
