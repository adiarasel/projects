#include <iostream>
using namespace std;
int n, ans;
string input;
void pathcount(int e)
{
    if(e == n-1){
        ans++;
        return;
    }
    if(e > n-1){
        return;
    }
    int newloc;
    for(int t=1; t<3; t++){
        newloc = e + t;
        if(input[e+t] == '-'){
            pathcount(newloc);
        }
    }
}
int main()
{
    cin>>input;
    n = input.length();
    pathcount(0);
    cout<<ans<<endl;
}