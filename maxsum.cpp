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
int n;
int val[108][108], pref[108][108];
int main()
{
    // ifstream fin("CHANGE ME.in");
    // ofstream fout("CHANGE ME.out");
    cin>>n;
    FOR(i, n){
        FOR(j, n){
            cin>>val[i][j];
        }
    }
    // FOR(i, n){
    //     FOR(j, n){
    //         cout<<val[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    FORR(i, n){
        FORR(j, n){
            pref[i][j] = val[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
        }
    }
    // FORR(i, n){
    //     FORR(j, n){
    //         cout<<pref[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int ans = -1;
    FORR(x1, n){
        FORR(y1, n){
            FORR(x2, n){
                FORR(y2, n){
                    if(x2 >= x1 && y2 >= y1)
                        ans = max(ans, pref[x2][y2] - pref[x1-1][y2] - pref[x2][y1-1] + pref[x1-1][y1-1]);
                    // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
                }
            }
        }
    }
    cout<<ans<<endl;
    // fin.close();
    // fout.close();
    return 0;
}