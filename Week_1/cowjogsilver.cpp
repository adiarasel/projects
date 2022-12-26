#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#define FOR(i, n) for(int i=0; i<n; i++)
#define FoR(i, n) for(int i=1; i<n; i++)
using namespace std;
int n;
long long t, group_end = INFINITY, endd[100000];
int ans = 0;
struct cow{
    int pos;
    int sped;
};
cow cows[1000000];
bool comp(cow a , cow b) //custom sorts in reverse
{
    if(a.pos > b.pos){
        return true;
    }
    else return false;
}

int main()
{
    ifstream fin("cowjog.in");
    ofstream fout("cowjog.out");
    //Read the variables
    fin>>n>>t;
    FOR(i, n){
        fin>>cows[i].pos>>cows[i].sped;
    }
    sort(cows, cows + n, comp); // checked it works
    FOR(i, n){
        endd[i] = cows[i].pos + t * cows[i].sped;
    }
    FOR(i, n){
        if(endd[i] < group_end){
            ans++;
            group_end = endd[i];
        }
    }
    fout<<ans<<endl;
    fin.close();
    fout.close();
    return 0;
}