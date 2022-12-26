#include <iostream>
using namespace std;
void solve()
{
    int n, b;
    cin>>n>>b;
    int cows[23];
    for(int i=0; i<n; i++){
        cin>>cows[i];
    }
    int ans = 1e9;
    for(int mask = 0; mask<(1<<n); mask++){
        int sum = 0;
        for(int i=0; i<n; i++){
            if((1<<i)&mask){
                sum += cows[i];
            }
        }
        if(sum >= b){
            ans = min(ans, sum - b);
        }
    }
    cout<<ans;
}
int main()
{
    solve();
}