#include <cstdio>
#include<iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define Pb push_back
#define MP make_pair
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
  ll n, a, b;
  cin>>n>>a>>b;
  vector<pll> v;
  for(ll i=0; i<n; i++) {
    char buf[100];
    ll w;
    cin>>buf>>w;
    v.Pb(MP(w, buf[0]=='S' ? 1 : 0));
  }
  ll INF = ll(1000)*1000*1000*1000;
  v.Pb(MP(-INF, 0));
  v.Pb(MP(INF, 0));
  sort(v.begin(), v.end());

  ll ans = 0;
  for(ll i=0; i+1<v.size(); i++) {
    ll S = v[i].X;
    ll E = v[i+1].X;
    ll M = (S+E)/2;

    if(v[i].Y==1) {
      ll s = max(a, S+1);
      ll e = min(b, M);
      if(e >= s) {
        ans += e-s+1;
      }
    }
    if(v[i+1].Y==1) {
      ll s = max(a, M+1);
      ll e = min(b, E);
      if(e >= s) {
        ans += e-s+1;
      }
    }
    if(v[i+1].Y==1 && v[i].Y==0 && (S%2)==(E%2) && a<=M && M<=b) {
      ans++;
    }
  }
  cout<<ans<<endl;
}