#include <iostream>
using namespace std;
int n, m, visited[100][100];
string path;
int dx[4] = {1, 0,-1, 0};
int dy[4] = {0, 1, 0,-1};
char ch[4] = {'R', 'D', 'L', 'U'};
char maze[101][101];
bool dfs(int a, int b, string c)
{
    if(maze[a][b] == 'F'){
        return true;
    }
    if(maze[a][b] != 'S' && maze[a][b] != '.'){
        return false;
    }
    visited[a][b] = 1;
    path[c] = 'L';
    if(dfs(a, b-1, c + 1)){
        return true;
    }
    path[c] = 'R';
    if(dfs(a, b + 1, c + 1)){
        return true;
    }
    path[c] = 'U';
    if(dfs(a - 1, b, c + 1)){
        return true;
    }
    path[c] = 'D';
    if(dfs(a + 1, b, c + 1)){
        return true;
    }
    path[c] = '0';
    return false;
}
string solve()
{
    int startx, starty; 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 'S'){
                startx = i;
                starty = j;
            }
        }
    }
    dfs(a, b, 0);
    return path;
}
int main()
{
    // main function given in problem :>
}