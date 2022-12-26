#include <iostream>
#include <fstream>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int a[1005], b[1005],n, k, ans; 
int main()
{
    ifstream fin("photo.in");
    ofstream fout("photo.out");
    fin>>n>>k;
    FOR(i, k){
        fin>>a[i]>>b[i];
        if(a[i] > b[i]) swap(a[i], b[i]);
    }
    long long left = 1, right = n;
    for(int i = 0; left <=n ; i++){
        right = n;
        FOR(j, k){
            if(left <= a[j] && right >= b[j]){
                right = b[j] - 1;
            }
        }
        ans++;
        left = right + 1;
    }
    fout<<ans<<endl;
    fin.close();
    fout.close();
    return 0;
} 