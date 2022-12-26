#include <iostream>
using namespace std;
int adjmat[251][251], n, m, c1, c2;
bool visited[251];
void dfs(int curnode)
{
    visited[curnode]=true;
    for(int newnode = 1; newnode <= n; newnode++){
        if(adjmat[curnode][newnode] == 1 && visited[newnode] != true){
            dfs(newnode);
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>c1>>c2;
        adjmat[c1][c2] = 1;
        adjmat[c2][c1] = 1;
    }
    dfs(1);
    bool ok = true;
    for(int i=1; i<=n; i++){
        if(visited[i] != true){
            ok  = false;
            cout<<i<<endl;
        }
    }
    if(ok == true){
        cout<<0;
    }
}