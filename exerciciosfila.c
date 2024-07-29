#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó da lista ligada
struct Node {
    int data;
    struct Node* next;
};

// Estrutura para representar a fila
struct Queue {
    struct Node *front, *rear;
};

// Função para criar um novo nó
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Função para criar uma fila vazia
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Função para adicionar um elemento à fila
void enqueue(struct Queue* q, int data) {
    // Cria um novo nó
    struct Node* temp = newNode(data);

    // Se a fila está vazia, então o novo nó é tanto o front quanto o rear
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    // Adiciona o novo nó no final da fila e muda o rear
    q->rear->next = temp;
    q->rear = temp;
}

// Função para remover um elemento da fila
void dequeue(struct Queue* q) {
    // Se a fila está vazia, não há nada para remover
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    // Armazena o nó anterior do front e move o front um nó à frente
    struct Node* temp = q->front;
    q->front = q->front->next;

    // Se o front se torna NULL, então mude o rear também para NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }

    // Libera a memória do nó removido
    free(temp);
}

// Função para verificar se a fila está vazia
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Função para obter o valor do elemento no início da fila
int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

// Função para imprimir todos os elementos da fila
void printQueue(struct Queue* q) {
    struct Node* temp = q->front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("Queue elements: ");
    printQueue(q);

    printf("Front element is %d\n", peek(q));
    dequeue(q);

    printf("Queue elements after dequeue: ");
    printQueue(q);

    printf("Front element is %d\n", peek(q));

    return 0;
}
