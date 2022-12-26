#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <queue>
#define FOR(i, n) for(int i=0; i<n; i++)
#define FORR(i, n) for(int i=1; i<=n; i++)
using namespace std;
int n, k;
int val[1003][1003]; // ONE INDEXED
int main()
{
    ifstream fin("paintbarn.in");
    ofstream fout("paintbarn.out");
    int x1, y1, x2, y2;
    fin>>n>>k;
    FOR(i, n){
        fin>>x1>>y1>>x2>>y2;
        val[x1+1][y1+1]++;
        val[x1+1][y2+1]--;
        val[x2+1][y1+1]--;
        val[x2+1][y2+1]++;
    }
    FORR(i ,1003){
        FORR(j, 1003){
            val[i][j] += val[i-1][j] + val[i][j-1] - val[i-1][j-1];
        }
    }
    // FORR(i ,9){
    //     FORR(j, 9){
    //         cout<<val[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int ans = 0;
    FOR(i, 1003){
        FOR(j, 1003){
            if(val[i][j] == k) ans++;
        }
    }
    fout<<ans<<endl;
    // fin.close();
    // fout.close();
    return 0;
}