#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    long long n, k;
    cin>>s>>n;
    k=s.length();
    while (n>k){
        k = k * 2;
    }
    //cout<<k<<endl;
    while(n > s.length()){
        if(n == k/2 + 1){
            n = k/2;
        }
        else{
            n = n - (k/2 +1);
            if(n < 0){
                n = n + (k/2 +1);
            }
        }
        //cout<<n<<endl;
        k = k / 2;
    }
    cout<<s[n-1]<<endl;
}