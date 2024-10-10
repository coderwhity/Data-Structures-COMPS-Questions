#include <stdio.h>

#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;
int am[MAX][MAX];
int visited[MAX];
int n;

void enqueue(int i) {
    if (rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = i;
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int d = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    return d;
}

void BFS(int start) {
    enqueue(start);
    visited[start] = 1;

    while (front != -1) {
        int current = dequeue();
        printf("%d ", current);

        for (int j = 0; j < n; j++) {
            if (visited[j] == 0 && am[current][j] == 1) {
                enqueue(j);
                visited[j] = 1;
            }
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &am[i][j]);
        }
    }
    
    int ch =1;
    while(ch==1){
    int startVer;
    printf("\nEnter starting vertex: ");
    scanf("%d", &startVer);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    BFS(startVer);
                printf("\nDo you want to continue ? (0/1) : ");
        scanf("%d",&ch);
    }
    return 0;
}
