#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int pref[100001], sufmin[100001], n; // so uh the prefix sum thing is one indexed, so is sufmin
string input; // input string
int main()
{
    ifstream fin("typo.in");
    ofstream fout("typo.out");
    fin>>input;
    n = input.size();
    int p = 0;
    FOR(i, n){ 
        if(input[i] == '('){
            p++;
        }
        else p--;
        pref[i] = p;
        // cout<<pref[i]<<endl;
    }
    sufmin[n-1] = pref[n-1];
    for(int i = n-2; i>=0; i--){
        sufmin[i] = min(sufmin[i+1], pref[i]);
    }
    int ans = 0;
    if(pref[n-1] == 2){
        FOR(i, n){
            if(input[i] == '(' && sufmin[i]>= 2){
                ans++;
            }
            if(pref[i] < 0){
                break;
            }
        }
    }
    else if(pref[n-1] == -2){
        FOR(i, n){
            if(input[i] == ')' && sufmin[i]>= -2){
                ans++;
            }
            if(pref[i] < 0){
                break;
            }
        }
    }
    else{
        fout<<0<<endl;
        return 0;
    }
    fout<<ans<<endl;
    fin.close();
    fout.close();
    return 0;
}