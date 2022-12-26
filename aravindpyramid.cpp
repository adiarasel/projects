#include <iostream>
using namespace std;

int main()
{
int n;cin>>n;cout<<n<<endl;
int p=n*n;int k=1;int s=0;
int t=1;

    for(int i=0;i<p;k++)
    {  
        if(k<n)
        {cout<<" ";i++;}  
        
        else if(s<t){cout<<"*"<<" ";s++;i++;}
        
        else{
        n--;t++;cout<<endl;k=0;s=0;     
        }}
cout<<endl;
}


   