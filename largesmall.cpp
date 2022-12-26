//#7 on handout
#include <iostream>
using namespace std;
int counter;
int main()
{
    long long n;
    int c=0;
    int p, q, ma=0, mi=100000000;
    cin>>n;
    long long dum = n;
    p = n % 10;
    q = p;
    for(int i=1; dum>0;i++){
        p = dum % 10;
            if(p > ma){
                ma = p;
            }
            q=p;
            if(q <= mi){
                mi = q;
            }
        dum = dum / 10;
    }
    cout<<ma<<endl<<mi<<endl;
}