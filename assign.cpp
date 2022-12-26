#include <iostream>
using namespace std;
int n, k, arr[16][16], curval[16], ans=0;
void countpos(int x)
{
    if(x == n){
        ans++;
        return;
    }
    bool ok;
    for(int c=1; c<=3; c++){
        ok=true;
        for(int i=0; i<x; i++){
            if(arr[i][x] == 1 && curval[i] != c){
                ok = false;
            }
            if(arr[i][x] == 2 && curval[i] == c){
                ok = false;
            }
        }
        if(ok==true){
            curval[x] = c;
            countpos(x+1);
        }
    }
}
int main()
{
    cin>>n>>k;
    char ch;
    int cow1,cow2;
    for(int i=0; i<k; i++){
        cin>>ch>>cow1>>cow2;
        if(ch=='S'){
            arr[cow1-1][cow2-1] = 1;
            arr[cow2-1][cow1-1] = 1;
        }
        else if(ch=='D'){
            arr[cow1-1][cow2-1] = 2;
            arr[cow2-1][cow1-1] = 2;
        }
        else{
            arr[cow1-1][cow2-1] = 0;
            arr[cow2-1][cow1-1] = 0;
        }
    }
    countpos(0);
    cout<<ans<<endl;
}