#include <iostream>
#include <vector>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
vector<int> a[100008];
int n, m, reg, color[100008];
bool visited[100008];
string s;
void ff(int i, char ch)
{
    // cout<<"entered function"<<endl;
    FOR(j, a[i].size()){
        // cout<<"j = "<<j<<endl;
        if(!visited[a[i][j]] && s[a[i][j]] == ch){
            // cout<<"a[i][j] = "<<a[i][j]<<endl;
            visited[a[i][j]] = 1;
            color[a[i][j]] = reg;
            ff(a[i][j], ch);
        }
    }
}
int main()
{
    cin>>n>>m;
    cin>>s;
    char c;
    int t1, t2;
    FOR(i, n){
        cin>>t1>>t2;
        a[t1-1].push_back(t2-1);
        a[t2-1].push_back(t1-1);
    }
    FOR(i, n){
        if(!visited[i]){
            visited[i] = true;
            color[i] = reg;
            // cout<<"i = "<<i<<endl;
            ff(i, s[i]);
            reg++;
        }
    }
    // FOR(i, m){
    //     cout<<color[i]<<endl;
    // }
    FOR(i, m){
        cin>>t1>>t2>>c;
        if(color[t1] != color[t2]) cout<<1; 
        else if(color[t1] == c) cout<<0;
        else cout<<0;
    }
}
/*
5 5
HHGHG
1 2
2 3
2 4
1 5
1 4 H
1 4 G
1 3 G
1 3 H
5 5 H
*/