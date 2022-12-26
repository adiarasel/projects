#include <iostream>
#include <vector>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int n, m, t1, t2, cup, cdown, ans, visited[101];
vector<int> up[101], down[101];
void dfsup(int pos)
{
    FOR(i, up[pos].size()){
        if(!visited[up[pos][i]]){
            visited[up[pos][i]] = 1;
            cup++;
            dfsup(up[pos][i]);
        }
    }
}
void dfsdown(int pos)
{
    FOR(i, down[pos].size()){
        if(!visited[down[pos][i]]){
            visited[down[pos][i]] = 1;
            cdown++;
            dfsdown(down[pos][i]);
        }
    }
}
int main()
{
    cin>>n>>m;
    FOR(i, m){
        cin>>t1>>t2;
        t1--;
        t2--;
        up[t1].push_back(t2);
        down[t2].push_back(t1);
    }
    FOR(i ,n){
        cup=0;
        cdown = 0;
        FOR(j ,101) visited[j] = 0;
        visited[i] = 1;
        dfsup(i);
        FOR(j ,101) visited[j] = 0;
        visited[i] = 1;
        dfsdown(i);
        FOR(j ,101) visited[j] = 0;
        if(cup + cdown == n-1) ans++;
    }
    cout<<ans<<endl;
}
/*
5 5
4 3
4 2
3 2
1 2
2 5
*/