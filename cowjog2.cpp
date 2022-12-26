#include <iostream>
using namespace std;
long long group, counter;
long long p, n, pos;
long long cowspd[100002];
int main()
{
    cin>>n;
    pos=n-1;
    for(int i=n; i>0; i--){
        cin>>p>>cowspd[i];
    }
    cowspd[0]=10e9;
    for(int i=1; i<=n; i++){
        if(cowspd[i-1]<cowspd[i]){
            cowspd[i]=cowspd[i-1];
        }
        else{
            group++;
        }
    }
    cout<<group<<endl;
}