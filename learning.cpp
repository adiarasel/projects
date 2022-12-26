#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// ONLY RIGHT SIDE IS INCLUDED IN ALL INTERVALS, NO +1 ANYWHERE.
typedef long long ll;
typedef pair<ll, ll> pll;
int n;
ll a, b;
struct typecow{
    long long pos; // weight/position of the cow
    int spot; // 0 if not spotty, 1 if spotty
};
pll intervals[1000002];
typecow cows[50001]; 
bool comp(typecow a, typecow b)
{
    if(a.pos < b.pos) return true;
    return false;
}
int main()
{
    cin>>n>>a>>b;
    string s;
    for(int i=0; i<n; i++){
        cin>>s;
        if(s == "S") cows[i].spot = 1;
        else if(s == "NS") cows[i].spot = 0;
        cin>>cows[i].pos;
    }
    sort(cows, cows+n, comp);
    for(int i=0; i<n-1; i++){
        if(cows[i].spot == 1 && cows[i+1].spot == 0){
            intervals[i].first = cows[i].pos;
            intervals[i].second = (cows[i].pos + cows[i+1].pos) / 2;
        }
        else if(cows[i].spot == 0 && cows[i+1].spot == 1){
            intervals[i].first = (cows[i].pos + cows[i+1].pos) / 2;
            intervals[i].second = cows[i+1].pos;
        }
    }
    // for(int i=0; i<n; i++){
    //     cout<<intervals[i].first<<" "<<intervals[i].second<<endl;
    // }

}
//^^^^ BASE CODE. ONLY FINDS INTERVALS, DOESN'T DO ANYTHING WITH THEM.  