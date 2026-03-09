# 📋 Gerenciador de Contatos em C

Sistema simples de gerenciamento de contatos desenvolvido em linguagem C, funcionando no terminal.

## 👥 Integrantes
- **José Henrique Sobrinho Santos** – Estrutura do projeto e menu
- **Emanuel Andrade** – Cadastro e listagem
- **João Carlos Leite** – Busca, edição e exclusão
- **Lucas Moreira** – Recursividade, testes e apresentação

## 📁 Estrutura dos Arquivos

```
gerenciador-contatos/
├── main.c        → Menu principal e controle do programa
├── contatos.c    → Implementação de todas as funções
├── contatos.h    → Struct e protótipos das funções
└── README.md     → Este arquivo
```

## ⚙️ Requisitos

- Compilador GCC instalado
- Sistema operacional: Linux, macOS ou Windows (com MinGW ou WSL)

## 🚀 Como Compilar e Executar

### Linux / macOS
```bash
gcc main.c contatos.c -o contatos
./contatos
```

### Windows (com MinGW)
```bash
gcc main.c contatos.c -o contatos.exe
contatos.exe
```

## 🧩 Funcionalidades

| Opção | Função |
|-------|--------|
| 1 | Cadastrar contato (nome, telefone, email) |
| 2 | Listar todos os contatos |
| 3 | Buscar contato pelo nome |
| 4 | Editar contato existente |
| 5 | Excluir contato |
| 6 | Exibir estatísticas com função recursiva |
| 7 | Sair do programa |

## 📌 Conceitos Utilizados

- `struct` para representar cada contato
- `ponteiros` para manipulação direta dos dados
- `funções` separadas por responsabilidade
- `strings` com `fgets`, `strcpy`, `strcasecmp`
- `função recursiva` para contar contatos por letra inicial
- Organização em múltiplos arquivos (`.c` e `.h`)
