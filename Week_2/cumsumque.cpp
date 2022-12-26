#include <iostream>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int n, q;
int prefixsums[100001], val[100001];
int main()
{
    cin>>n;
    FOR(i, n){
        cin>>val[i];
        prefixsums[i+1] = prefixsums[i] + val[i];
    }
    cin>>q;
    FOR(i ,q){
        int a, b;
        cin>>a>>b;
        a++;
        b++;
        cout<<prefixsums[b] - prefixsums[a-1]<<endl;
    }
    return 0;
}