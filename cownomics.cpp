#include <iostream>
#include <cmath>
using namespace std;
int n, m;
string spots[500], nosp[500];
int s[500][50], p[500][50], a[64];
bool checkloc(int x, int y, int z) //taking base 4 bc 4 digits is better than 4 chars
{
    bool ok = true;
    for(int i=0; i<n; i++){
        a[s[i][x]*16 + s[i][y]* 4 + s[i][z]] = 1;
    }
    for(int i=0; i<n; i++){
        if (a[p[i][x]*16 + p[i][y]*4 + p[i][z]]) ok = false;
    }
    for(int i=0; i<n; i++){
        a[s[i][x]*16 + s[i][y]*4 + s[i][z]] = 0;
    }
    return ok;
}
int main()
{
    
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        cin >> spots[i];
        for (int j=0; j<m; j++) { // assigning base 4 digits for spots
            if (spots[i][j]=='A') s[i][j] = 0;
            if (spots[i][j]=='C') s[i][j] = 1;
            if (spots[i][j]=='G') s[i][j] = 2;
            if (spots[i][j]=='T') s[i][j] = 3;
        }
    }
    for(int i=0; i<n; i++) {
        cin >> nosp[i];
        for (int j=0; j<m; j++) { // assigning base 4 digits for no spots
            if (nosp[i][j]=='A') p[i][j] = 0;
            if (nosp[i][j]=='C') p[i][j] = 1;
            if (nosp[i][j]=='G') p[i][j] = 2;
            if (nosp[i][j]=='T') p[i][j] = 3;
        }
    }
    int ans = 0;
    for (int i=0; i<m; i++){
        for (int j=i+1; j<m; j++){
            for (int k=j+1; k<m; k++){
                if (checkloc(i,j,k)){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
}