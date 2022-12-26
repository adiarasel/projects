#include <iostream>
#include <vector>
#include <queue>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int n, m, t1, t2, dist[1001];
bool visited[1001];
vector<int> a[1001];
queue<pair<int, int> > q;
int main()
{
    cin >> n >> m;
    FOR(i, m){
        cin>>t1>>t2;
        t1--; t2--;
        a[t1].push_back(t2);
        a[t2].push_back(t1);
        // cout<<t1<<"        "<<t2<<endl;
    }
    cout<<"begin adjlist"<<endl;
    FOR(i, m){
        FOR(j, a[i].size()){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"end adjlist"<<endl;
    FOR(i, n){
        dist[i] = 100000;
    }
    // -------- BFS ALGORITHM
    visited[0] = true;
    q.push(make_pair(0, 0));
    int cur, d;
    while(!q.empty()){
        cout<<"---------------------------------------"<<endl;
        cur = q.front().first;
        d = q.front().second;
        cout<<"cur = "<<cur<<" d = "<<d<<endl;
        q.pop();
        dist[cur] = min(dist[cur], d);
        // cout<<dist[cur]<<endl;
        cout<<"a[cur].size = "<<a[cur].size()<<endl;
        FOR(i, a[cur].size()){
            cout<<"before if cur = "<<cur<<" i = "<<i<<endl;
            if(!visited[a[cur][i]]){
                cout<<"cur = "<<cur<<" i = "<<i<<endl;
                cout<<"a[cur][i] = "<<a[cur][i]<<endl;
                visited[a[cur][i]] = true;
                cout<<"i = "<<i<<" d + 1 = "<< d+1<<endl;
                if(i == 0 && d + 1 > 0) continue;
                q.push(make_pair(a[cur][i], d+1));
            }
        }
    }
    // -------- FINDING ANSWER
    int maxans = -1, counter = 0, firstinstance = -1;
    FOR(i, n){
        // cout<<"hi"<<endl;
        cout<<dist[i]<<endl;
    }
    FOR(i, n){
        maxans = max(maxans, dist[i]);
    }
    FOR(i, n){
        if(dist[i] == maxans) counter++;
    }
    FOR(i, n){
        if(dist[i] == maxans){
            firstinstance = i + 1;
            break;
        }
    }
    cout<<firstinstance<<" "<<maxans<<" "<<counter<<endl;
}
/*
6 7
3 6
4 3
3 2
1 3
1 2
2 4
5 2
*/