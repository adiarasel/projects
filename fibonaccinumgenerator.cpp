//#4 on handout
#include <iostream>
using namespace std;
int main()
{
    int f1=1 , f2=1 , n; 
    long long ans;
    cin >> n;
    if( n == 1 || n == 2 ){
        cout << f1<< endl;
    }
    else{
        for(int i=1; i < n-1 ; i++){
            ans= f1 + f2;
            f2 = f1;
            f1 = ans;
        }
        cout << ans << endl;
    }
}