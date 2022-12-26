#include <iostream>
#include <algorithm>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int n, a[100000], sum1, sum2, sum3, maxi, ans=1000000;
void solve(int pos)
{
    if(pos == n){
        maxi = max(sum1, max(sum2, sum3));
        ans = min(ans, maxi);
        return;
    }
    for(int group=1; group<=3; group++){
        if(group == 1){
            sum1+=a[pos];
        }
        else if(group == 2){
            sum2+=a[pos];
        }
        else if(group == 3){
            sum3+=a[pos];
        }
        if(group == 1 && sum1 <= ans){
            solve(pos+1);
        }
        else if(group == 2 && sum2 <= ans){
            solve(pos+1);
        }
        else if(group == 3 && sum3 <= ans){
            solve(pos+1);
        }
        if(group == 1){
            sum1-=a[pos];
        }
        else if(group == 2){
            sum2-=a[pos];
        }
        else if(group == 3){
            sum3-=a[pos];
        }
    }
}
int main()
{
    cin>>n;
    FOR(i, n){
        cin>>a[i];
    }
    sum1=a[0];
    solve(1);
    cout<<ans<<endl;
}
/*
8
14
2
5
15
8
9
20
4
*/