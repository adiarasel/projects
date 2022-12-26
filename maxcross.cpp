#include <iostream>
#include <algorithm>
using namespace std;
//ONE INDEXED PROBLEM
int n, k, b;
int brok[100002], prefsum[100004], marked[100004];
int main()
{
    cin>>n>>k>>b;
    int minsum=1000000;
    for(int i=0; i<b; i++){
        cin>>brok[i];
        marked[brok[i]] = 1;
    }
    sort(brok, brok+b);
    for(int i=1; i<=n ;i++){
        prefsum[i] = prefsum[i-1];
        if(marked[i] == 1) prefsum[i]++;
    }
    for(int i=1; i+k<=n; i++){
        //cout<<"minsum = "<<minsum<<endl;
        minsum = min(minsum, prefsum[i+k] - prefsum[i]);
    }
    cout<<minsum<<endl;
    for(int i=0; i<=n; i++){
        //cout<<i<<" "<<prefsum[i]<<endl;
    }
}