#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 10
#define MAX_TITULO 50  
#define MAX_AUTOR 100
#define MAX_LOGIN 20

typedef struct {
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    int ativo; // 1 = existe, 0 = removido
    int emprestado; // 1 = emprestado, 0 = disponível
} Livro;

typedef struct {
    char login[MAX_LOGIN];
    int tipo; // 0 = Usuário, 1 = Administrador
} Perfil;

void listarLivros(Livro livros[], int tamanho) {
    printf("\nLista de Livros:\n");
    int encontrou = 0; // Forma de assumir que não há livros inicialmente
    for (int i = 0; i < tamanho; i++) {
        if (livros[i].ativo) {
            // Esse printf trás três informações no prompt: o título, o autor e o status do livro
            printf("%d. Título: %s | Autor: %s | Status: %s\n", i+1, livros[i].titulo, livros[i].autor, 
                livros[i].emprestado ? "Emprestado" : "Disponível");
            encontrou = 1; // Se encontrar um livro, a variável é atualizada para 1, e valida como livro ativo
        }
    }
    // Caso o bloco anterior não seja executado, o programa imprime a mensagem abaixo
    if (!encontrou) printf("Nenhum livro cadastrado.\n");
}

void cadastrarLivro(Livro livros[], int tamanho) {
    int pos = -1; // Quando um elemento não é encontrado em um array, ele retorna -1
    for (int i = 0; i < tamanho; i++) {
        if (!livros[i].ativo) { // Verifica se o livro na posição 'i' está inativo
            pos = i; // Caso encontre uma posição livre, ele armazena o novo livro no índice
            break; // Saída do laço for
        }
    }
    // Validação caso o limite seja atingido
    if (pos == -1) {
        printf("Limite de livros atingido!\n");
        return;
    }
    // No caso de uma posição livre, é executado o cadastro abaixo
    printf("Título do livro: ");
    getchar(); // Limpar buffer - Evita conflito com entradas anteriores
    fgets(livros[pos].titulo, MAX_TITULO, stdin); // Leitura do livro digitado, e se respeita o tamanho máx do título
    livros[pos].titulo[strcspn(livros[pos].titulo, "\n")] = 0;
    printf("Autor do livro: ");
    fgets(livros[pos].autor, MAX_AUTOR, stdin); // Leitura do autor digitado, e se respeita o tamanho máx do autor
    livros[pos].autor[strcspn(livros[pos].autor, "\n")] = 0;
    livros[pos].ativo = 1;
    livros[pos].emprestado = 0;
    printf("Livro cadastrado com sucesso!\n");
}

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

void emprestarLivro(Livro livros[], int tamanho) {
    listarLivros(livros, tamanho);
    printf("Digite o número do livro para empréstimo: ");
    int num;
    scanf("%d", &num);
    if (num < 1 || num > tamanho || !livros[num-1].ativo) {
        printf("Livro inválido!\n");
        return;
    }
    if (livros[num-1].emprestado) {
        printf("Livro já está emprestado!\n");
        return;
    }
    livros[num-1].emprestado = 1;
    printf("Livro emprestado com sucesso!\n");
}

void devolverLivro(Livro livros[], int tamanho) {
    printf("\nLivros emprestados:\n");
    int encontrou = 0;
    for (int i = 0; i < tamanho; i++) {
        if (livros[i].ativo && livros[i].emprestado) {
            printf("%d. Título: %s | Autor: %s\n", i+1, livros[i].titulo, livros[i].autor);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nenhum livro emprestado.\n");
        return;
    }
    printf("Digite o número do livro devolvido: ");
    int num;
    scanf("%d", &num);
    if (num < 1 || num > tamanho || !livros[num-1].ativo || !livros[num-1].emprestado) {
        printf("Livro inválido!\n");
        return;
    }
    livros[num-1].emprestado = 0;
    printf("Livro devolvido com sucesso!\n");
}

int main() {
    Livro livros[MAX_LIVROS] = {
        {"O Hobbit", "J.R.R. Tolkien", 1, 0},
        {"Dom Quixote", "Miguel de Cervantes", 1, 0},
        {"1984", "George Orwell", 1, 0},
        {"A Revolução dos Bichos", "George Orwell", 1, 0},
        {"A Menina que Roubava Livros", "Markus Zusak", 1, 0},
        {"O Pequeno Príncipe", "Antoine de Saint-Exupéry", 1, 0},
        {"Harry Potter e a Pedra Filosofal", "J.K. Rowling", 1, 0},
        {"O Senhor dos Anéis", "J.R.R. Tolkien", 1, 0},
        {"O Alquimista", "Paulo Coelho", 1, 0},
        {"Capitães da Areia", "Jorge Amado", 1, 0}
    };

    Perfil usuario = {"usuario", 0};
    Perfil admin = {"admin", 1};
    Perfil *perfilAtual = NULL;

    char login[MAX_LOGIN];
    printf("Login: ");
    scanf("%s", login);

    if (strcmp(login, usuario.login) == 0) {
        perfilAtual = &usuario;
    } else if (strcmp(login, admin.login) == 0) {
        perfilAtual = &admin;
    } else {
        printf("Login inválido!\n");
        return 1;
    }

    int opcao;
    do {
        printf("\n=== Menu ===\n");
        printf("1. Listar Livros\n");
        printf("2. Emprestar Livro\n");
        printf("3. Dar Baixa (Devolver Livro)\n");
        if (perfilAtual->tipo == 1) {
            // Administrador
            printf("4. Cadastrar Novo Livro\n");
            printf("5. Remover Livro\n");
            printf("6. Editar Título do Livro\n");
        }
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: listarLivros(livros, MAX_LIVROS); break;
            case 2: emprestarLivro(livros, MAX_LIVROS); break;
            case 3: devolverLivro(livros, MAX_LIVROS); break;
            case 4: 
                if (perfilAtual->tipo == 1) cadastrarLivro(livros, MAX_LIVROS); 
                else printf("Acesso negado!\n");
                break;
            case 5: 
                if (perfilAtual->tipo == 1) removerLivro(livros, MAX_LIVROS); 
                else printf("Acesso negado!\n");
                break;
            case 6: 
                if (perfilAtual->tipo == 1) editarTitulo(livros, MAX_LIVROS); 
                else printf("Acesso negado!\n");
                break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while(opcao != 0);

    return 0;
}