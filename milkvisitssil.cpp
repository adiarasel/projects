#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <queue>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int n, m;
char type[100001];
vector<int> adj[1000001];
int visited[100001];
int main()
{
    ifstream fin("milkvisits_silver.in");
    ofstream fout("milkvisits_silver.out");
    fin>>n>>m;
    fin>>type;
    FOR(i ,n-1){
        int x, y;
        fin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    FOR(i,n){
        visited[i] = -1;
    }
    queue<int> q;
    int group = 0;
    FOR(i, n){
        if(visited[i] == -1){
            q.push(i);
            char curtype = type[i];
            while(!q.empty()){
                int x = q.front();
                q.pop();
                visited[x] = group;
                for(int j: adj[x]){
                    if(visited[j] == -1 && type[j] == curtype){
                        q.push(j);
                    }
                }
            }
        }
        group++;
    }
    FOR(i, m){
        int a, b;
        char c;
        fin>>a>>b>>c;
        if(type[a-1] != type[b-1]){
            fout<<1;
        }
        else{
            if(type[a-1] == c){
                fout<<1;
            }
            else{
                if(visited[a-1] != visited[b-1]){
                    fout<<1;
                }
                else{
                    fout<<0;
                }
            }
        }
    }
}