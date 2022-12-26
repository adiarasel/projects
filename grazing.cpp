#include <iostream>
#include <algorithm>
using namespace std;
int k, answer;
bool vis[6][6];
char field[6][6];
int dx[4] = {0,-1, 1, 0};
int dy[4] = {1, 0, 0,-1};
void DFS(int row, int col, int counter)
{
    int newrow, newcol;
    if(row == 5 && col == 25){
        if(counter == 25 - k){
            answer++;
        }
        return;
    }
    visited[row][col] = true;
    for(int i=0; i<4; i++){
        newrow = row + dx[i];
        newcol = col + dy[i];
        if(field[newrow][newcol] == '.' && visited[newrow][newcol] != true){
            DFS(newrow, newcol, counter + 1);
        }
    }
    visited[row][col] = false;
}
int main()
{
    cin>>k;
    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            field[i][j] = '.';
        }
    }
    int i1, i2;
    for(int i=0; i<k; i++){
        cin>>i1>>i2;
        field[i1][i2] = 'x';
    }
    dfs(1, 1, 1);
    cout<<answer<<endl;
}