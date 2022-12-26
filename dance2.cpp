#include <iostream>
#include <algorithm>
using namespace std;
int bal;
string cow[1000];
int main()
{
    int n, k[1000];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>k[i]>>cow[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<k[i]; j++){
            if(cow[i][j] == '>'){
                bal++;
            }
            if(cow[i][j]== '<'){
                bal--;
            }
            cout<<bal<<endl;
        }
        if(bal==0){
            cout<<"legal"<<endl;
        }
        else{
            cout<<"illegal"<<endl;
        }
        bal=0;
    }
}
