#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 10
#define MAX_TITULO 50
#define MAX_AUTOR 100

typedef struct {
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    int ativo; // 1 = existe, 0 = removido
} Livro;

// Função para listar os livros existentes
void listarLivros(Livro livros[], int tamanho) {
    printf("\nLista de Livros:\n");
    
    int encontrou = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (livros[i].ativo) {
            printf("%d. Título: %s | Autor: %s\n", i+1, livros[i].titulo, livros[i].autor);
            encontrou = 1;
        }
    }
    if (!encontrou) printf("Nenhum livro cadastrado.\n");
}

// Função para cadastrar um novo livro
void cadastrarLivro(Livro livros[], int tamanho) {
    int pos = -1;
    for (int i = 0; i < tamanho; i++) {
        if (!livros[i].ativo) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        printf("Limite de livros atingido!\n");
        return;
    }
    printf("Título do livro: ");
    getchar(); // Limpar buffer
    fgets(livros[pos].titulo, MAX_TITULO, stdin);
    livros[pos].titulo[strcspn(livros[pos].titulo, "\n")] = 0;

    printf("Autor do livro: ");
    fgets(livros[pos].autor, MAX_AUTOR, stdin);
    livros[pos].autor[strcspn(livros[pos].autor, "\n")] = 0;

    livros[pos].ativo = 1;
    printf("Livro cadastrado com sucesso!\n");
}

// Função para remover livro
void removerLivro(Livro livros[], int tamanho) {
    listarLivros(livros, tamanho);
    printf("Digite o número do livro a remover: ");
    int num;
    scanf("%d", &num);
    if (num < 1 || num > tamanho || !livros[num-1].ativo) {
        printf("Livro inválido!\n");
        return;
    }
    livros[num-1].ativo = 0;
    printf("Livro removido com sucesso!\n");
}

// Função para editar título de um livro
void editarTitulo(Livro livros[], int tamanho) {
    listarLivros(livros, tamanho);
    printf("Digite o número do livro a editar: ");
    int num;
    scanf("%d", &num);
    if (num < 1 || num > tamanho || !livros[num-1].ativo) {
        printf("Livro inválido!\n");
        return;
    }
    printf("Novo título: ");
    getchar(); // Limpar buffer
    fgets(livros[num-1].titulo, MAX_TITULO, stdin);
    livros[num-1].titulo[strcspn(livros[num-1].titulo, "\n")] = 0;
    printf("Título atualizado com sucesso!\n");
}

int main() {
    Livro livros[MAX_LIVROS] = {
        {"O Hobbit", "J.R.R. Tolkien", 1},
        {"Dom Quixote", "Miguel de Cervantes", 1},
        {"1984", "George Orwell", 1},
        {"A Revolução dos Bichos", "George Orwell", 1},
        {"A Menina que Roubava Livros", "Markus Zusak", 1},
        {"O Pequeno Príncipe", "Antoine de Saint-Exupéry", 1},
        {"Harry Potter e a Pedra Filosofal", "J.K. Rowling", 1},
        {"O Senhor dos Anéis", "J.R.R. Tolkien", 1},
        {"O Alquimista", "Paulo Coelho", 1},
        {"Capitães da Areia", "Jorge Amado", 1}
    };

    int opcao;
    do {
        printf("\n=== Menu ===\n");
        p);rintf("1. Listar Livros\n"
        printf("2. Cadastrar Novo Livro\n");
        printf("3. Remover Livro\n");
        printf("4. Editar Título do Livro\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: listarLivros(livros, MAX_LIVROS); break;
            case 2: cadastrarLivro(livros, MAX_LIVROS); break;
            case 3: removerLivro(livros, MAX_LIVROS); break;
            case 4: editarTitulo(livros, MAX_LIVROS); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while(opcao != 0);

    return 0;
}