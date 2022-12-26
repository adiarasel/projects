#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#define FOR(i, n) for(int i=0; i<n; i++)
#define A first
#define B second
using namespace std;
int n, q;
int prehol[100004], pregue[100004], prejer[100004];
int cows[100000];
pair<int, int> queries[100000];

int main()
{
    ifstream fin("bcount.in");
    ofstream fout("bcount.out");
    fin>>n>>q;
    int a, b, c;
    FOR(i, n){
        fin>>cows[i];
    }
    FOR(i, q){
        fin>>queries[i].A>>queries[i].B;
    }
    for(int i=1; i<=n; i++){
        if(cows[i-1] == 1){
            prehol[i] = prehol[i-1] + 1;
            pregue[i] = pregue[i-1];
            prejer[i] = prejer[i-1];
        }
        if(cows[i-1] == 2){
            prehol[i] = prehol[i-1];
            pregue[i] = pregue[i-1] + 1;
            prejer[i] = prejer[i-1];
        }
        if(cows[i-1] == 3){
            prehol[i] = prehol[i-1];
            pregue[i] = pregue[i-1];
            prejer[i] = prejer[i-1] + 1;
        }
    }
    FOR(i, q){
        fout<<prehol[queries[i].B] - prehol[queries[i].A - 1]<<" ";
        fout<<pregue[queries[i].B] - pregue[queries[i].A - 1]<<" ";
        fout<<prejer[queries[i].B] - prejer[queries[i].A - 1]<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}