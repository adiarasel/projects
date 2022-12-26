#include <iostream>
#include <cmath>
using namespace std;
int sumdiv(int n)
{
    int sum=0;
    for(int i=1; i<n; i++){
        if(n % i == 0){
            sum+=i;
            // cout<<"sum = "<< sum <<endl;
        }
    }
    return sum;
}
int main()
{
    int s, s1, s2;
    cin>>s;
    s1=s+1;
    while(true){
        s2 = sumdiv(s1);
        if(sumdiv(s2) == s1 && s1!=s2){
            cout<<s1<<" "<<s2<<endl;
            break;
        }
        s1++;
    }
    return 0;
}
//100/100