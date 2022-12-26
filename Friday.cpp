#include <iostream>
#include <algorithm>
using namespace std;
int x[1000], y[1000], marked[1000];
int dist(int a , int b)
{
    int m;
    m = (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
    return m;
}
int main()
{
    int n;
    cin>>n;
    for(int a=1; a<=n; a++){
        cin>>x[a]>>y[a];
    }
    int left=n;
    int pos=1; //pos is the one who is playing
    //minpos is the position of minimum position;
    int minpos;
    while (left>1) {
        minpos=pos;
        int distance=200000000;
        for (int i=1; i<=n; i++){
            if (marked[i]==1);   //0 means in , 1 means out
            else{
               int temp = dist(pos,i);
               if (temp < distance) {
                   distance=temp;
                   minpos=i;
                   cout<<"temp = " << temp<<" distance = "<<distance;
                }
            }
        }
        left--;
        marked[minpos]=1;
        pos=(pos+1)%n;

    }
    for(int j=1; j<=n; j++){
        if(marked[j]==0){
            cout<<j;
        }
    }
}
