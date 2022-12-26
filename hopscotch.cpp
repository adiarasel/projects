#include <iostream>
using namespace std;
int counter = 0, r, c;
char color[16][16];
void dfs(int locx, int locy)
{
    if(locx == r && locy == c){
        counter++;
        return;
    }
    if(locx == r || locy == c){
        return;
    }
    for(int i = locx + 1; i<=r; i++){
        for(int j = locy + 1; j<=c; j++){
            if(color[i][j] != color[locx][locy]){
                dfs(i,j);
            }
        }
    }
}
int main()
{
    cin>>r>>c;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cin>>color[i][j];
        }
    }
    dfs(1, 1);
    cout<<counter<<endl;
}