#include <iostream>
#include <fstream>
#define FOR(i, n) for(int i=0; i<n; i++)
#define ll long long
using namespace std;
ll w[100003], ow[100003], ans;
ll n;
string input;
int main()
{
    ifstream fin("cow.in");
    ofstream fout("cow.out");
    fin>>n;
    fin>>input;
    for(int i = n-1; i >= 0; i--){
        w[i] = w[i+1];
        if(input[i] == 'W'){
            w[i]++;
        }
    }
    for(int i = n-1; i >= 0; i--){
        ow[i] = ow[i+1];
        if(input[i] == 'O'){
            ow[i]+=w[i];
        }
    }
    for(int i = n-1; i >= 0; i--){
        if(input[i] == 'C'){
            ans+=ow[i];
        }
    }
    fout<<ans<<endl;
    fin.close();
    fout.close();
    return 0;
}