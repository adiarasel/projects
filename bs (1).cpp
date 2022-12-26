#include <iostream>
#include <algorithm>
using namespace std;
int a[100000], n;
int bs(int x)
{
    int l=0, r=n-1, mid;
    while(l<r){
        mid=(l+r)/2;
        // cout<<" mid = "<<mid<<endl;
        if(x <= a[mid]){
            r=mid;
            // cout<<" mid = r = "<<mid<<endl;
        }
        else if (x > a[mid]){
            l = mid;
            // cout<<" mid = l = "<<mid<<endl;
        }
        if(r-l<=1){
            if(a[l] == x) return l;
            if(a[r] == x) return r;
            break;
        }
        if(r<l){
            return -1;
        }
        // cout<<" l = "<<l<<" r = "<<r<<endl;
    }
    return -1;
}
int main()
{
    int q, query;
    cin>>n>>q;
    for(int b=0; b<n; b++){
        cin>>a[b];
    }
    sort(a, a + n);
    for(int c=0; c<q; c++){
        cin>>query;
        cout<<"query = "<<query<<endl;
        cout<<bs(query)<<endl;
    }
}