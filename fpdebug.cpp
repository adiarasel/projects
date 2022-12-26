#include <iostream>
#include <algorithm>
using namespace std;
int n, prefixsum[100005], freq[100005], firpos[100005],secpos[100005];
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
    prefixsum[0] = 0;
    for(int i=1; i<=n; i++){
        if(cows[i-1].breed == 'G'){
            prefixsum[i] = prefixsum[i-1] + 1;
        }
        if(cows[i-1].breed == 'H'){
            prefixsum[i] = prefixsum[i-1] - 1;
        }
    }
    // cout<<endl<<"  ";
    // for(int i=0; i<n; i++){
    //     cout<<cows[i].breed<<" ";
    // }
    // cout<<endl;
    // for(int i=0; i<=n; i++){
    //     cout<<prefixsum[i]<<" ";
    // }
    int sum=0, maxsum=0;
    for(int i=0; i<=n; i++){
        // cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        // cout<<"loop = "<<i<<endl;
        // cout<<"before sum = " <<sum<<endl;
        // cout<<"before if = "<<firpos[i]<<"  "<<cows[i].pos<<"   "<<endl;
        if(freq[prefixsum[i]] == 0){
            firpos[prefixsum[i]] = cows[i-1].pos;
            secpos[prefixsum[i]] = cows[i].pos;
            // cout<<"After if cows[i].pos = "<<cows[i-1].pos<<endl;
            // cout<<"After if firpos[prefixsum[i]] = " <<firpos[prefixsum[i]]<<endl;
        } 
        if(freq[prefixsum[i]] > 0){
            sum = cows[i-1].pos - secpos[prefixsum[i]];// NEEDS TO BE FIXED, LAST DAY TO FIX IT
            // cout<<"i = "<<i<<endl;
            // cout<<"after cows[i].pos = "<<cows[i-1].pos<<endl;
            // cout<<"prefixsum[i] = " <<prefixsum[i]<<endl;
            // cout<<"firpos[prefixsum[i]] = " <<firpos[prefixsum[i]]<<endl;
            // cout<<"After sum = " <<sum<<endl;
        }
        // cout<<"before cows[i].pos = "<<cows[i-1].pos<<endl;
        // cout<<"freq[prefixsum[i]] = " <<freq[prefixsum[i]]<<endl;
        // cout<<"after if = "<<firpos[i]<<"  "<<cows[i].pos<<"   "<<endl; 
        freq[prefixsum[i]]++; 
        maxsum = max(sum, maxsum);
        sum = 0;
        // cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    }
    // for(int i=0; i<n; i++){
    //     cout<<firpos[i]<<"  "<<cows[i].pos<<"   "<<endl; 
    // }
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