int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];

    int queue[10000][2];
    int front = 0, rear = 0;

    int fresh = 0;

    // push all rotten oranges
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 2) {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            }
            else if(grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    if(fresh == 0) return 0;

    int minutes = -1;

    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while(front < rear) {
        int size = rear - front;
        minutes++;

        for(int i = 0; i < size; i++) {
            int r = queue[front][0];
            int c = queue[front][1];
            front++;

            for(int d = 0; d < 4; d++) {
                int nr = r + dirs[d][0];
                int nc = c + dirs[d][1];

                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    queue[rear][0] = nr;
                    queue[rear][1] = nc;
                    rear++;
                    fresh--;
                }
            }
        }
    }

    return fresh == 0 ? minutes : -1;
}