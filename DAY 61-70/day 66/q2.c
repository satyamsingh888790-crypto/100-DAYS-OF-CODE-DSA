#include <stdlib.h>
#include <stdbool.h>

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    
    int* indegree = (int*)calloc(numCourses, sizeof(int));

    int** adj = (int**)malloc(sizeof(int*) * numCourses);
    int* adjSize = (int*)calloc(numCourses, sizeof(int));

    for(int i = 0; i < numCourses; i++)
        adj[i] = (int*)malloc(sizeof(int) * numCourses);

    // build graph
    for(int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        adj[b][adjSize[b]++] = a;
        indegree[a]++;
    }

    int* queue = (int*)malloc(sizeof(int) * numCourses);
    int front = 0, rear = 0;

    for(int i = 0; i < numCourses; i++) {
        if(indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;

    while(front < rear) {
        int node = queue[front++];
        count++;

        for(int i = 0; i < adjSize[node]; i++) {
            int v = adj[node][i];
            indegree[v]--;

            if(indegree[v] == 0)
                queue[rear++] = v;
        }
    }

    return count == numCourses;
}