#include <iostream>
#include <algorithm>
using namespace std;
int s, n, l[100000], ans;
int UB(int x){
    int L=0,  R=n, mid;
    while (L<R){
        mid = (R+L)/2; // <-------------- This is integer division
        if  (x >= l[mid]){
            L = mid + 1;
        }
        else{
            R = mid;
        }
    }
    return L;
}
int main()
{
    cin>>n>>s;
    for(int i=0;i<n; i++){
        cin>>l[i];
    }
    sort(l ,l + n);
    int x;
    for(int i=0; i<n; i++){
        x=l[i];
        ans+=UB(s-x)- UB(0);
    }
    cout<<ans/2 -1<<endl;
}
/*
Sample Case:	
10 20
2
5
6
18
11
8
8
3
12
11
*/