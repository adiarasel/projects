#include <iostream>
#include <algorithm>
using namespace std;
int n, prefixsum[100005], freq[100005], firpos[100005], secpos[100005];
struct cow{
    int pos;
    char breed;
};
cow cows[100002];
bool comp(cow a, cow b)
{
    if(a.pos < b.pos){
        return true;
    }
    return false;
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>cows[i].pos>>cows[i].breed;
    }
    sort(cows, cows + n, comp);
    // cout<<endl;
    // for(int i=0; i<n; i++){
    //     cout<<cows[i].pos<<" "<<cows[i].breed<<endl;
    // }
    for(int i=1; i<=n; i++){
        if(cows[i-1].breed == 'G'){
            prefixsum[i] = prefixsum[i-1] + 1;
        }
        if(cows[i-1].breed == 'H'){
            prefixsum[i] = prefixsum[i-1] - 1;
        }
    }
    cout<<endl<<"  ";
    for(int i=0; i<n; i++){
        cout<<cows[i].breed<<" ";
    }
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<prefixsum[i]<<" ";
    }
    int sum, maxsum=0;
    for(int i=0; i<=n; i++){
        if(freq[prefixsum[i]] > 0){
            sum = cows[i].pos - cows[firpos[prefixsum[i]]].pos;
            cout<<"cows[i].pos = "<<endl;
        }
        if(freq[prefixsum[i]] == 0){
            firpos[prefixsum[i]] = cows[i].pos;
            cout<<firpos[prefixsum[i]]<<"  "<<"i = "<<i<<endl;
            freq[prefixsum[i]]++;
        }
        maxsum = max(sum, maxsum);
        cout<<"firpos[prefixsum[i]] = "<<firpos[prefixsum[i]]<<endl;
    }
    cout<<maxsum<<endl;
}
/*
6
4 G
10 H
7 G
16 G
1 G
3 H
*/