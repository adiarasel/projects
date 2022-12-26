#include <iostream>
using namespace std;
int main()
{
    int a[5][5], sum=0, n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    for(int u=0; u < n; u++){
        for(int v=0; v<n; v++){
            if(u==0 || u==n-1 || v==0 || v==n-1){
                sum+=a[u][v];
            }
        }
    }
    cout<<sum;
}
/*
input code yeet
1 12 44 56 1
1 67 78 34 1
1 34 45 56 1
1 24 23 45 1
1 12 34 76 1
*/