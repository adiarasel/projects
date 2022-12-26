#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n, ans = 0;
char grid[6][6];
bool vis[6][6];
int dx[4] = {0,-1, 1, 0};
int dy[4] = {1, 0, 0,-1};
void DFS(int row, int col, int numopen, int numclose)
{
    int newrow, newcol;
    if(numopen == numclose){
        ans = max(ans, numopen + numclose);
        return;
    }
    if(numopen > n * n / 2){
        return;
    }
    vis[row][col] = true;
    for(int i = 0; i < 4; i++){
        newrow = row + dx[i];
        newcol = col + dy[i];
        if(newcol >= n || newcol<0 || newcol >= n || newcol < 0 || vis[newrow][newcol] != true){
            continue;
        }
        if(grid[newrow][newcol] == '(' && numclose == 0){
            DFS(newrow, newcol, numopen + 1, numclose);
        }
        if(grid[newrow][newcol] == ')'){
            DFS(newrow, newcol, numopen, numclose + 1);
        }
    }
    vis[row][col] = false;
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    if(grid[0][0] == '('){
        DFS(0, 0, 1, 0);
        cout<<ans<<endl;
    }
    else{
        cout<<0<<endl;
    }
}