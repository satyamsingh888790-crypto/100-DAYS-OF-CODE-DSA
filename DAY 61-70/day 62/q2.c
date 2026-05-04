void dfs(int** rooms, int roomsSize, int* roomsColSize, int* visited, int room) {
    visited[room] = 1;

    for(int i = 0; i < roomsColSize[room]; i++) {
        int next = rooms[room][i];
        if(!visited[next]) {
            dfs(rooms, roomsSize, roomsColSize, visited, next);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int visited[roomsSize];

    for(int i = 0; i < roomsSize; i++)
        visited[i] = 0;

    dfs(rooms, roomsSize, roomsColSize, visited, 0);

    for(int i = 0; i < roomsSize; i++) {
        if(!visited[i])
            return false;
    }

    return true;
}