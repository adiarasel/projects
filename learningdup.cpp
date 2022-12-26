#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <vector>
#include <utility>
#define in9f -1e9
#define inf 1e9
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int n;
ll a, b;
vector<pll> v;
int main()
{
    cin>>n>>a>>b;
    string s;
    ll sum = 0, w;
    bool ok = true;
    for(int i=0; i<n; i++){
        cin>>s>>w;
        if(s == "S"){
            v.PB(MP(w, 1));
        }
        else if(s == "NS"){
            v.PB(MP(w, 0));
        }
    }
    v.PB(MP(in9f, 0));
    v.PB(MP(inf, 0));
    sort(v.begin(), v.end());
    ll ans, st, en, mid;
    for(ll i=0; i+1<v.size(); i++){
        st = v[i].first;
        en = v[i+1].first;
        mid = (st+en)/2;
        if(v[i].second==1){
            ll news = max(a, st + 1);
            ll newe = min(b, mid);
            if(newe >= news){
                ans += newe - news + 1;
            }
        }
        if(v[i+1].second==1){
            ll news = max(a, st+1);
            ll newe = min(b, mid);
            if(newe >= news) {
                ans += newe - news + 1;
            }
        }
        if(v[i+1].second==1 && v[i].second==0 && (st%2)==(en%2) && a<=mid && mid<=b) {
            ans++; 
        }
    }
    cout<<ans<<endl;
}
/*
3 1 10
S 10
NS 4
S 1
*/