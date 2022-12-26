#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int n, x[100000], y[100000];
int dist(int a, int b)
{
    return abs(x[b]-x[a]) + abs(y[b]-y[a]);
}
int main()
{
    int sum=0, ans=0, cur_val=0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i];
    }
    for(int i=1; i<=n-1; i++){
        sum+=dist(i, i+1);
    }
    ans = sum;
    for(int i=2; i<=n-1; i++){
        cur_val = sum - dist(i-1, i) - dist(i, i+1) + dist(i-1, i+1);
        ans = min(ans, cur_val);
    }
    cout<<ans<<endl;
}