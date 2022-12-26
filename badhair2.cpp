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
        if(){
            while(!thing.empty()){
                anss[i] += anss[thing.top()] + 1;
                thing.pop();
            }
        }
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