#include <iostream>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int n, m, bespos[1000000], elspos[1000000], ans, pos=1;
int main()
{
    cin>>n>>m;
    int c, d;
    FOR(i ,n){
        cin>>c>>d;
        for(int j = 1; j<=d; j++){
            bespos[pos] = bespos[pos-1] + c;
            pos++;
        }
    }
    pos = 1;
    FOR(i ,m){
        cin>>c>>d;
        for(int j = 1; j<=d; j++){
            elspos[pos] = elspos[pos-1] + c;
            pos++;
        }
    }
    for(int i=1; bespos[i] != 0; i++){
        if(i == 1) continue;
        if(bespos[i] > elspos[i] && bespos[i-1] <= elspos[i-1]){
            ans++;
        }
        if(bespos[i] < elspos[i] && bespos[i-1] >= elspos[i-1]){
            ans++;
        }
    }
    cout<<ans<<endl;
}