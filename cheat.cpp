#include <iostream>
#include <algorithm>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int n, k, p, arr[1100008], bess[1000003];
int player = 0, dtop = 0, dbottom = 0, nbess = 0;
int main()
{
    cin>>n>>k>>p;
    FOR(i, k){
        arr[i] = i;
    }
    player = dtop = 0;
    dbottom = k-1;
    FOR(i, k){
        if(player == n-1){
            bess[nbess++] = arr[dtop] + 1;
        }
        player = (player + 1) % n;
        dtop++;
        FOR(j, p){
            arr[++dbottom] = arr[dtop++];
        }
    }
    sort(bess, bess + k/n);
    FOR(i, k/n){
        cout<<bess[i]<<endl;
    }
}