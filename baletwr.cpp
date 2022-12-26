#include <iostream>
using namespace std;
void solve()
{
    int n, ans = -1;
    pair<int, int> haybales[22];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>haybales[i].first>>haybales[i].second;
    }
    sort(haybales, haybales + n);
    bool ok = true;
    int prevb = -1;
    for(int mask = 0; mask < (1<<n); mask++){
        ok = true;
        prevb = -1;
        for(int i=0; i<n; i++){
            if((1<<i) & mask){
                if(haybales[i].second < prevb){
                    ok = false;
                }
                prevb = haybales[i].second;
            }
        }
        if(ok){
            ans = max(ans, __builtin_popcount(mask));
        }
    }
    cout<<ans<<endl;
}
int main()
{
    solve();
}