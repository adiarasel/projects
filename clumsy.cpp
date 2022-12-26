#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int n, counter;
string inp;
int pref[100003];
int main()
{
    ifstream fin("clumsy.in");
    ofstream fout("clumsy.out");
    fin>>inp;
    n = inp.size();
    for(int i = 0; i < n; i++){
        pref[i+1] = pref[i];
        if(inp[i] == '(') pref[i+1]++;
        if(inp[i] == ')') pref[i+1]--;
        if(pref[i+1] < 0){
            pref[i+1] += 2;
            counter++;
        }
        if(pref[n] > 0){
            counter += pref[n] / 2;
        } 
    }
    fout<<counter<<endl;
    fin.close();
    fout.close();
    return 0;
}