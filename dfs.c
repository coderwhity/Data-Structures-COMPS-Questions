#include <stdio.h>

void DFS(int i);

int am[100][100];
int visited[100];
int n;

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d, %d",i,j);
            scanf("%d", &am[i][j]);
        }
    }
    int ch;
    // while(ch != 0){
        int startVer;
        printf("Enter starting vertex: ");
        scanf("%d", &startVer);
        
        for(int i = 0; i < n; i++) {
            visited[i] = 0;
        }
    
        DFS(startVer);
    // }

    return 0;
}

void DFS(int i) {
    visited[i] = 1;
    printf("%d ", i);

    for(int j = 0; j < n; j++) {
        if(visited[j] == 0 && am[i][j] == 1) {
            DFS(j);
        }
    }
}
