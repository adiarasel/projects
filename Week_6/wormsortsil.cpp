#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int n, m, cows[10005], startt, endd, visited[10005];
int cur;
vector<pair<int ,int> > adjlist[10005];
void dfs(int pos, int k) //FF
{
    //look for all connections of i
    //if pos is connected to i with a width >= k then useable else continue
    // useable means dfs it
    FOR(i, adjlist[pos].size()){
        if(adjlist[pos][i].second >=k){
            dfs(i, k);
        }
        else{
            continue;
        }
    }
}
bool issok(int k)
{
    FOR(i, 10005){
        visited[i] = -1;
    }
    FOR(i, n){
        if(!visited[i]){
            cur = i;
            visited[i] = cur;
            dfs(i, k);
        }
    }
    FOR(i, n){
        if(visited[i] != i-1) return false; //CHECK IF ONE-INDEXED/ZERO-INDEXED
    }
    return true;
}
int main()
{
    ifstream fin("wormsort.in");
    ofstream fout("wormsort.out");
    fin>>n>>m;
    FOR(i, 10005){
        visited[i] = -1;
    }
    FOR(i, n){
        fin>>cows[i];
    }
    int t1, t2, t3;
    FOR(i, m){
        fin>>t1>>t2>>t3;
        adjlist[t1].push_back(make_pair(t2, t3));
        adjlist[t2].push_back(make_pair(t1, t3));
        endd = max(endd, t3);
    }
    int mid;
    while(startt < endd){
        mid = (startt + endd + 1)/2;
        // cout<<startt<<" "<<mid<<" "<<endd<<endl;
        // cout<<"issok(mid) = "<<issok(mid)<<endl;
        if(issok(mid)){
            startt = mid;
        }
        else{
            endd = mid - 1;
        }
    }
    fout<<startt<<endl;
}
/*
4 4
3 2 1 4
1 2 9
1 3 7
2 3 10
2 4 3
*/