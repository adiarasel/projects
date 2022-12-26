#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#define FOR(i, n) for(int i=0; i<n; i++)
#define FoR(i, n) for(int i=0; i<n; i+=2)
#define FOr(i, n) for(int i=1; i<=n; i++)
int n;
using namespace std;
struct point{
    int id; // number of lifeguard
    int pos;// identifies where the point is
    int label; // idenitfies type (start = 1/end = -1)
};
point points[200000];
bool comp1(point a, point b)
{
    if(a.pos < b.pos){
        return true;
    }
    if(a.pos == b.pos){
        if(a.label == 0 && b.label == 1){
            return true;
        }
        return false;
    }
    return false;
}
set<int> cows;
int alonetime[100000];
int main()
{
    cin>>n;
    int c, d;
    long long ans = 0;
    FoR(i, 2 * n){
        cin>>c>>d;
        points[i].pos = c;
        points[i+1].pos = d;
        points[i].label = 1;
        points[i+1].label = -1;
        points[i].id = i/2 + 1;
        points[i+1].id = i/2 + 1;
    }
    sort(points, points + 2*n, comp1);
    long long x = 0; //total region of at least one lifeguard working
    long long onduty = 0;
    FOR(i, 2 * n){ 
        // cout<<onduty<<endl;
        if(points[i].label == 1){
            cows.insert(points[i].id);
        }
        if(points[i].label == -1){
            cows.erase(points[i].id);
        }
        onduty = cows.size();
        if(onduty > 0){
            x += points[i + 1].pos - points[i].pos;
        }
    }
    auto it = cows.begin();
    onduty = 0;
    FOR(i, 2 * n){
        if(points[i].label == 1){
            cows.insert(points[i].id);
        }
        if(points[i].label == -1){
            cows.erase(points[i].id);
        }
        onduty = cows.size();
        if(onduty == 1){
            it = cows.begin();
            alonetime[*it] += points[i + 1].pos - points[i].pos;
        }
    }
    // FOR(i, n + 1){
    //     cout<<i<<"    "<<alonetime[i]<<endl;
    // }
    int minthing = 100000000;
    FOr(i, n){
        minthing = min(minthing, alonetime[i]);
    }
    // cout<<"x = "<<x<<endl;
    // cout<<minthing<<endl;
    cout<<x - minthing<< endl;
}
/*
3
1 10
12 16
2 3 

3
5 9
1 4
3 7
*/