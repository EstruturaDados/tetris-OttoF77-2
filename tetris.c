#include <stdio.h>

// Desafio Tetris Stack
// Tema 3 - Integração de Fila e Pilha
// Este código inicial serve como base para o desenvolvimento do sistema de controle de peças.
// Use as instruções de cada nível para desenvolver o desafio.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef struct {
    char nome;
    int id;
} Peca;

typedef struct {
    Peca itens[MAX];
    int frente, tras, tamanho;
} Fila;

void inicializarFila(Fila *f) {
    f->frente = 0;
    f->tras = 0;
    f->tamanho = 0;
}

// Gera uma peça automaticamente com tipo aleatório e id sequencial
Peca gerarPeca(int id) {
    char tipos[] = {'I', 'O', 'T', 'L'};
    return (Peca){tipos[rand() % 4], id};
}

// Insere peça no final da fila (enqueue)
int enqueue(Fila *f, Peca p) {
    if (f->tamanho == MAX) return 0;
    f->itens[f->tras] = p;
    f->tras = (f->tras + 1) % MAX;
    f->tamanho++;
    return 1;
}

// Remove peça da frente da fila (dequeue)
int dequeue(Fila *f, Peca *p) {
    if (f->tamanho == 0) return 0;
    *p = f->itens[f->frente];
    f->frente = (f->frente + 1) % MAX;
    f->tamanho--;
    return 1;
}

void exibirFila(Fila *f) {
    printf("\nFila de pecas\n");
    if (f->tamanho == 0) {
        printf("(vazia)\n");
        return;
    }
    for (int i = 0; i < f->tamanho; i++)
        printf("[%c %d] ", f->itens[(f->frente + i) % MAX].nome, f->itens[(f->frente + i) % MAX].id);
    printf("\n");
}

int main() {

    // 🧩 Nível Novato: Fila de Peças Futuras
    //
    // - Crie uma struct Peca com os campos: tipo (char) e id (int).
    // - Implemente uma fila circular com capacidade para 5 peças.
    // - Crie funções como inicializarFila(), enqueue(), dequeue(), filaCheia(), filaVazia().
    // - Cada peça deve ser gerada automaticamente com um tipo aleatório e id sequencial.
    // - Exiba a fila após cada ação com uma função mostrarFila().
    // - Use um menu com opções como:
    //      1 - Jogar peça (remover da frente)
    //      0 - Sair
    // - A cada remoção, insira uma nova peça ao final da fila.
    srand(time(NULL));

    Fila fila;
    inicializarFila(&fila);

    int proximoId = 0;

    // Inicializa fila com 5 peças
    for (int i = 0; i < 5; i++)
        enqueue(&fila, gerarPeca(proximoId++));

    int opcao;
    do {
        exibirFila(&fila);
        printf("\n1 - Jogar peca (dequeue)\n2 - Inserir nova peca (enqueue)\n0 - Sair\nOpcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            Peca p;
            if (dequeue(&fila, &p))
                printf("Peca jogada: [%c %d]\n", p.nome, p.id);
            else
                printf("Fila vazia!\n");
        } else if (opcao == 2) {
            Peca p = gerarPeca(proximoId++);
            if (enqueue(&fila, p))
                printf("Peca inserida: [%c %d]\n", p.nome, p.id);
            else
                printf("Fila cheia!\n");
        }
    } while (opcao != 0);



    // 🧠 Nível Aventureiro: Adição da Pilha de Reserva
    //
    // - Implemente uma pilha linear com capacidade para 3 peças.
    // - Crie funções como inicializarPilha(), push(), pop(), pilhaCheia(), pilhaVazia().
    // - Permita enviar uma peça da fila para a pilha (reserva).
    // - Crie um menu com opção:
    //      2 - Enviar peça da fila para a reserva (pilha)
    //      3 - Usar peça da reserva (remover do topo da pilha)
    // - Exiba a pilha junto com a fila após cada ação com mostrarPilha().
    // - Mantenha a fila sempre com 5 peças (repondo com gerarPeca()).


    // 🔄 Nível Mestre: Integração Estratégica entre Fila e Pilha
    //
    // - Implemente interações avançadas entre as estruturas:
    //      4 - Trocar a peça da frente da fila com o topo da pilha
    //      5 - Trocar os 3 primeiros da fila com as 3 peças da pilha
    // - Para a opção 4:
    //      Verifique se a fila não está vazia e a pilha tem ao menos 1 peça.
    //      Troque os elementos diretamente nos arrays.
    // - Para a opção 5:
    //      Verifique se a pilha tem exatamente 3 peças e a fila ao menos 3.
    //      Use a lógica de índice circular para acessar os primeiros da fila.
    // - Sempre valide as condições antes da troca e informe mensagens claras ao usuário.
    // - Use funções auxiliares, se quiser, para modularizar a lógica de troca.
    // - O menu deve ficar assim:
    //      4 - Trocar peça da frente com topo da pilha
    //      5 - Trocar 3 primeiros da fila com os 3 da pilha


    return 0;
}

