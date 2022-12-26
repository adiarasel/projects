#include <iostream>
#include <cmath>
#include <fstream>
#define FOR(i, n) for(int i=0; i<n; i++)
#define FoR(i, n) for(int i=1; i<=n; i++)
#define ll long long
using namespace std;
ll n, maxsize = -1;
ll pref[50006], inp[50006], prefmod[50006], freq[7], firpos[7];
int main()
{
    ifstream fin("div7.in");
    ofstream fout("div7.out");
    fin>>n;
    FOR(i, n){
        fin>>inp[i];
    }
    FoR(i, n){
        pref[i] = inp[i-1] + pref[i-1];
        prefmod[i] = pref[i] % 7;
    }
    // FOR(i, n+1){
    //     cout<<prefmod[i]<<endl;
    // }
    /*so the goal is once you have the mods, if you can subtract any positions a and b to get 0, then
    the numbers from positions a<x<=b sum up to a multiple of 7
    */
    FoR(i, n){
        freq[prefmod[i]]++;
        if(freq[prefmod[i]] == 1){
            firpos[prefmod[i]] = i; // marks first position of a number
        }
        if(freq[prefmod[i]] > 1){
            maxsize = max(maxsize, i - firpos[prefmod[i]]);
        }
        // cout<<"freq[prefmod["<<i<<"]] = "<<freq[prefmod[i]]<<" prefmod["<<i<<"] = "<<prefmod[i]<<" firpos[prefmod["<<i<<"]] = "<<firpos[prefmod[i]]<<endl;
    }
    fout<<maxsize<<endl;
    fin.close();
    fout.close();
    return 0;
}