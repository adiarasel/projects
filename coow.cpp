#include <iostream>
#include <string>
using namespace std;
long long c, co, cow;
int main()
{
    string s;
    int n, counter=0;
    cin>>n>>s;
    for(int i = 0; i < n; i++){
        if(s[i] == 'C'){
            c++;
        }
        if(s[i] == 'O'){
            co += c;
        }
        if(s[i] == 'W'){
            cow += co;
        }
    }
    cout<<cow<<endl;
}