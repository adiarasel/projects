#include <iostream>
#include <stack>
#define FOR(i, n) for(int i=0; i<n; i++)
#define rFOR(i, n) for(int i = n - 1; i>=0; i--)
using namespace std;
stack<int> thing;
int n, heights[80001], anss[80001], ans;
int main() 
{
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>heights[i];
    }
    thing.push(n-1);
    int counter = 0;
    for(int i = n-2; i>=0; i--){ // going from right to left
        if(!thing.empty()){
            counter = i;
            // cout<<"loop yes --------------------"<<endl;
            while(!thing.empty() || counter < n || heights[i] > thing.top()){
                anss[i] += (anss[counter + 1] + 1);
                cout<<i<<" "<<counter<<" "<<anss[i]<<endl;
                if(!thing.empty()) thing.pop();
                counter++;
            }
        }
        else if(thing.empty() || heights[i] < thing.top()){// NOT ENTERING AT ALL;-;
            // if(!thing.empty()) cout<<"thing.top = "<<thing.top()<<endl;
            cout<<i<<" "<<anss[i]<<endl;
            anss[i] = 0;
        }
        thing.push(i);
    }
    cout<<endl;
    for(int i=0; i<n; i++){ // coming up with the answer
        cout<<anss[i]<<endl;
        ans += anss[i];
    }
    cout<<ans<<endl;
}
/*
6
10
3
7
4
12
2
*/