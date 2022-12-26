// #2 on handout
#include <iostream>
using namespace std;
int main()
{
    int a , b , n;
    cin >> a >> b ;
    if( a >= b ){
      n = 10 * a + b ;
    }
    else{
        n = 10 * b + a ;
    }
    cout << n << endl ;
}