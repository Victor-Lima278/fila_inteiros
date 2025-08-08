#include <stdio.h>
#include <stdbool.h>
#define MAX 5

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int qtd;
} Fila;

void inicializa(Fila* f) {
    f->inicio = 0;
    f->fim = 0;
    f->qtd = 0;
}

bool fila_vazia(Fila* f) {
    return (f->qtd == 0);
}

bool fila_cheia(Fila* f) {
    return (f->qtd == MAX);
}

bool inserir(Fila* f, int valor) {
    if (fila_cheia(f)) return false;
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX;
    f->qtd++;
    return true;
}

bool remover(Fila* f, int* removido) {
    if (fila_vazia(f)) return false;
    *removido = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->qtd--;
    return true;
}

bool consultar_inicio(Fila* f, int* valor) {
    if (fila_vazia(f)) return false;
    *valor = f->dados[f->inicio];
    return true;
}

void mostrar(Fila* f) {
    if (fila_vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Fila: ");
    int i = f->inicio;
    for (int c = 0; c < f->qtd; c++) {
        printf("%d ", f->dados[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Fila f;
    inicializa(&f);
    int opcao, valor, removido;

    do {
        printf("\n--- Menu da Fila Circular ---\n");
        printf("1. Inserir no fim da fila\n");
        printf("2. Remover do inicio da fila\n");
        printf("3. Consultar o inicio da fila\n");
        printf("4. Indicar se a fila esta vazia\n");
        printf("5. Indicar se a fila esta cheia\n");
        printf("6. Mostrar fila\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Valor para inserir: ");
                scanf("%d", &valor);
                if (inserir(&f, valor))
                    printf("Inserido com sucesso!\n");
                else
                    printf("Fila cheia! Nao foi possivel inserir.\n");
                break;
            case 2:
                if (remover(&f, &removido))
                    printf("Removido do inicio: %d\n", removido);
                else
                    printf("Fila vazia! Nao ha o que remover.\n");
                break;
            case 3:
                if (consultar_inicio(&f, &valor))
                    printf("Inicio da fila: %d\n", valor);
                else
                    printf("Fila vazia!\n");
                break;
            case 4:
                printf("A fila %s esta vazia.\n", fila_vazia(&f) ? "" : "NAO");
                break;
            case 5:
                printf("A fila %s esta cheia.\n", fila_cheia(&f) ? "" : "NAO");
                break;
            case 6:
                mostrar(&f);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcão invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
