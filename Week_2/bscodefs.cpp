#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int l=0, r=1e6, mid = 0, x = 0;
    string s;
    while(l<r){
        mid=(l+r+1)/2;
        cout<<mid<<endl;
        cin>>s;
        if(s == "<"){
            r = mid-1;
        }
        else if(s == ">="){
            l = mid;
        }
        if(r == l){
            cout<<"! "<<r<<endl;
            break;
        }
        if(r<l){
            return -1;
        }
    }
    return 0;
}