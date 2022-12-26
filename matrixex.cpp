#include <iostream>
using namespace std;
int freq[10], x=0;
int main()
{
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            freq[a[i][j]]++;
        }
    }
    for(int i=1; i<=9; i++){
        if(freq[i]>1){
            x++;
            break;
        }
    }
    if(x>0){
        cout<<"bad";
    }
    else{
        cout<<"good";
    }
    cout<<endl;
}