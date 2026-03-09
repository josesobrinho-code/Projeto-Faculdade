#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contatos.h"

// ─────────────────────────────────────────────
// PESSOA 1 – Menu principal e controle do sistema
// ─────────────────────────────────────────────

int main() {
    Contato lista[MAX_CONTATOS]; // Array de contatos (até 100)
    int total = 0;               // Quantidade atual de contatos
    int opcao;

    printf("========================================\n");
    printf("   GERENCIADOR DE CONTATOS - Versão 1.0 \n");
    printf("========================================\n");

    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Cadastrar contato\n");
        printf("2. Listar contatos\n");
        printf("3. Buscar contato pelo nome\n");
        printf("4. Editar contato\n");
        printf("5. Excluir contato\n");
        printf("6. Estatísticas (recursivo)\n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer(); // Limpa o '\n' que sobra após o scanf

        switch (opcao) {
            case 1:
                cadastrarContato(lista, &total);
                break;

            case 2:
                listarContatos(lista, total);
                break;

            case 3: {
                if (total == 0) {
                    printf("\nNenhum contato cadastrado.\n");
                    break;
                }
                char nomeBusca[TAM_NOME];
                printf("\n--- BUSCAR CONTATO ---\n");
                printf("Digite o nome: ");
                fgets(nomeBusca, TAM_NOME, stdin);
                nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

                int indice = buscarContato(lista, total, nomeBusca);
                if (indice == -1) {
                    printf("\nContato '%s' não encontrado.\n", nomeBusca);
                } else {
                    printf("\nContato encontrado:\n");
                    printf("  Nome:     %s\n", lista[indice].nome);
                    printf("  Telefone: %s\n", lista[indice].telefone);
                    printf("  Email:    %s\n", lista[indice].email);
                }
                break;
            }

            case 4:
                editarContato(lista, total);
                break;

            case 5:
                excluirContato(lista, &total);
                break;

            case 6:
                exibirEstatisticas(lista, total);
                break;

            case 7:
                printf("\nSaindo do sistema. Até logo!\n");
                break;

            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }

    } while (opcao != 7);

    return 0;
}
