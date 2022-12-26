#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#define FOR(i, n) for(int i=0; i<n; i++)
int n, ans = 0;
char grid[6][6]; // actual horseshoe grid
bool vis[6][6]; // checks if spot in grid is visited, default false
int dx[4] = {0,-1, 1, 0}; // all possible x directions
int dy[4] = {1, 0, 0,-1}; // all possible y directions
void DFS(int row, int col, int numopen, int numclose)
{
    int newrow, newcol;
    if(numopen == numclose){ // perfectly balanced, but may not be the max possible 
        ans = max(ans, numopen + numclose);
        return;
    }
    if(numopen > n * n / 2){ // if number of ( exceeds half the grid there's no way to make it perfectly balanced
        return;
    }
    vis[row][col] = true;
    FOR(i, 4){
        newrow = row + dx[i];
        newcol = col + dy[i];
        if(newcol >= n || newcol<0 || newrow >= n || newrow < 0 || vis[newrow][newcol] != true){
            // if out of bounds or already visited
            continue;
        }
        if(grid[newrow][newcol] == '(' && numclose == 0){ // dfsing the open part
            DFS(newrow, newcol, numopen + 1, numclose);
        }
        if(grid[newrow][newcol] == ')'){ //dfsing the closed part
            DFS(newrow, newcol, numopen, numclose + 1);
        }
    }
    vis[row][col] = false; // after dfsing when it's true, have to set it back to false so that can visit other paths
}
int main()
{
    ifstream fin("hshoe.in");
    ofstream fout("hshoe.out");
    fin>>n;
    FOR(i, n){
        FOR(j, n){
            fin>>grid[i][j];
        }
    }
    if(grid[0][0] == '('){ // has to start with ( or else no perfectly balanced string
        DFS(0, 0, 1, 0);
        fout<<ans<<endl;
    }
    else{
        fout<<0<<endl;
    }
}