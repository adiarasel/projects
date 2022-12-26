#include <iostream>
#include <fstream>
#include <vector>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
struct thing{
    int to;
    char cha;
};
vector<thing> a[100003];
vector<int> cc;
int n, m, ans, color[100003];
bool violation, marked[100003];
void ff(int pos)
{
    FOR(i, a[pos].size()){
        if(!marked[a[pos][i].to]){
            marked[a[pos][i].to] = true;
            cc.push_back(a[pos][i].to);
            ff(a[pos][i].to);
        }
    }
}
int main()
{
    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");
    fin>>n>>m;
    char ch;
    int t1, t2;
    thing d;
    FOR(i, m){
        fin>>ch>>t1>>t2;
        t1--;
        t2--;
        d.cha = ch;
        d.to = t1;
        a[t2].push_back(d);
        d.to = t2;
        a[t1].push_back(d);
    }
    FOR(i, n){
        if(!marked[i]){
            cc.clear();
            marked[i] = true;
            cc.push_back(i);
            ans++;
            ff(i);
            color[i] = 1;
            FOR(j, cc.size()){
                FOR(k, a[cc[j]].size()){
                    if(color[a[cc[j]][k].to] == 0){
                        if(a[cc[j]][k].cha == 'S'){
                            color[a[cc[j]][k].to] = color[cc[j]];
                        }
                        else color[a[cc[j]][k].to] = 3 - color[cc[j]];
                    }
                    else{
                        if(a[cc[j]][k].cha == 'S'){
                            if(color[a[cc[j]][k].to] != color[cc[j]]) violation = true;
                        }
                        else{
                            if(color[a[cc[j]][k].to] == color[cc[j]]) violation = true;
                        }
                    }
                }
            }
        }
        if(violation) break;
    }
    if(violation){
        fout<<0;
        return 0;
    }
    fout<<1;
    FOR(i, ans){
        fout<<0;
    }
    fout<<endl;
}