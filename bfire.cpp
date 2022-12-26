#include <iostream>
using namespace std;
int picked[255];
int main()
{
    int n, counter=1;
    cin>>n;
    while(true){
        counter = counter * 2;
        if(counter > n){
            counter = counter - n;
        }
        if(picked[counter] == 1){
            counter += n;
            counter /= 2;
            break;
        }
        if(counter == 1){
            counter += n;
            counter /= 2;
            break;
        }
        picked[counter] = 1;
    }
    cout<<counter;
}