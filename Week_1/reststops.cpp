#include <iostream>
#include <fstream>
#include <algorithm>
#define FOR(i, n) for(int i=0; i<n; i++)
#define rFOR(i, n) for(int i = n - 1; i>=0; i--)
using namespace std;
long long l, n, rf, rb, lastx;
bool maxx[100000];
int x[100000], c[100000];
int main()
{
    ifstream fin("reststops.in");
    ofstream fout("reststops.out");
    fin>>l>>n>>rf>>rb;
    for(int i=0; i<n; i++){
        fin>>x[i]>>c[i];
    }
    int mx = 0;
    for(int i = n-1; i>=0; i--){
        if(c[i] > mx){
            maxx[i] = true;
            mx = c[i];
        }
    }
    long long tf = 0, tb = 0, ans = 0;
    for(int i=0; i<n; i++){
        if(maxx[i] == true){    
            tf += (x[i] - lastx) * rf;
            tb += (x[i] - lastx) * rb;
            ans += (tf - tb) * c[i];
            tb = tf;
            lastx = x[i];
        }
    }
    fout<<ans<<endl;
    fin.close();
    fout.close();
    return 0;
}