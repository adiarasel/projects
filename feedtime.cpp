#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
bool vis[751][751];
char farm[751][751];
int w, h, cursize=0, ans = 0;
int dx[8] = {0,-1, 1, 0, 1,-1, 1,-1};
int dy[8] = {1, 0, 0,-1, 1, 1,-1,-1};
void DFS(int row, int col)
{
    int newrow, newcol;
    vis[row][col] = true;
    cursize++;
    for(int i=0; i<8; i++){
        newrow = row + dx[i];
        newcol = col + dy[i];
        if(newrow < h && newrow >= 0 && newcol < w && newcol >= 0 && farm[newrow][newcol] != '*' && vis[newrow][newcol] != true){
            DFS(newrow, newcol);
        }
    }
}
int main()
{
    cin>>w>>h;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>farm[i][j];
        }
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(vis[i][j] == false && farm[i][j] != '*'){
                cursize = 0;
                DFS(i, j);
                //cout<<cursize<<endl;
                ans = max(ans, cursize);
            }
        }
    }
    cout<<ans<<endl;
}