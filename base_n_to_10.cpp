#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int a,base,ans,res;
    cout<< "Enter a number: ";
    cin>> a;
    cout<< "Enter a base: ";
    cin>> base;
//    ans=convert(a,base);
    int sum=a%10;
    cout<<"sum="<<sum<<endl;
    res = a/10;
    cout<<"a="<<a<<endl;
    cout<<"res="<<res<<endl;
    res%=10;
        for(int i=base;res!=0;i*=base)
        {
            res%=10;
          cout<<"inside for a="<<a<<endl;
          cout<<"inside for res="<<res<<endl;
          cout<<"inside for i="<<i<<endl;
          sum+=res*i;
          a/=10;
          res=a/10;
          cout<<"sum="<<sum<<endl;
          cout<<"for end a="<<a<<endl;
          cout<<"for end res="<<res<<endl;
        }

    cout<< "the converted base 10 is"<<sum;
//    getch();
    return 0;
}

