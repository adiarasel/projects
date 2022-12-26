#include <iostream>
#include <fstream>
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
            visited[a[i][j]] = 1;
            color[a[i][j]] = reg;
            ff(a[i][j], ch);
        }
    }
}
int main()
{
    ifstream fin("milkvisits.in");
    ofstream fout("milkvisits.out");
    fin>>n>>m;
    fin>>s;
    char c;
    int t1, t2;
    FOR(i, n-1){
        fin>>t1>>t2;
        a[t1-1].push_back(t2-1);
        a[t2-1].push_back(t1-1);
    }
    FOR(i, n){
        if(!visited[i]){
            visited[i] = true;
            color[i] = reg;
            ff(i, s[i]);
            reg++;
        }
        // cout<<color[i]<<endl;
    }
    FOR(i, m){
        fin>>t1>>t2>>c;
        t1--;
        t2--;
        if(color[t1] != color[t2]) fout<<1; 
        else if(s[t1] == c) fout<<1;
        else fout<<0;
    }
}