#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#define FOR(i, n) for(int i=0; i<n; i++)
#define FoR(i, n) for(int i=0; i<n; i+=2)
#define FOr(i, n) for(int i=1; i<=n; i++)
int n;
using namespace std;
struct poind{
    int id; // number of lifeguard
    int pos;// identifies where the poind is
    int label; // idenitfies type (start = 1/end = -1)
};
vector<poind> poinds(200000);
bool comp(poind a, poind b)
{
    return a.pos < b.pos;
}
set<int> cows;
int alonetime[100000];
int main()
{
    ifstream fin("lifeguards_silver.in");
    ofstream fout("lifeguards_silver.out");
    fin>>n;
    int c, d;
    long long ans = 0;
    FoR(i, 2 * n){
        fin>>c>>d;
        poinds[i].pos = c;
        poinds[i+1].pos = d;
        poinds[i].label = 1;
        poinds[i+1].label = -1;
        poinds[i].id = i/2 + 1;
        poinds[i+1].id = i/2 + 1;
    }
    sort(poinds.begin(), poinds.begin()+2*n, comp);
    long long x = 0; //total region of at least one lifeguard working
    long long onduty = 0;
    FOR(i, 2 * n){ 
        // fout<<onduty<<endl;
        if(poinds[i].label == 1){
            cows.insert(poinds[i].id);
        }
        if(poinds[i].label == -1){
            cows.erase(poinds[i].id);
        }
        onduty = cows.size();
        if(onduty > 0){
            x += poinds[i + 1].pos - poinds[i].pos;
        }
    }
    auto it = cows.begin();
    onduty = 0;
    FOR(i, 2 * n){
        if(poinds[i].label == 1){
            cows.insert(poinds[i].id);
        }
        if(poinds[i].label == -1){
            cows.erase(poinds[i].id);
        }
        onduty = cows.size();
        if(onduty == 1){
            it = cows.begin();
            alonetime[*it] += poinds[i + 1].pos - poinds[i].pos;
        }
    }
    int minthing = 100000000;
    FOr(i, n){
        minthing = min(minthing, alonetime[i]);
    }
    fout<<x - minthing<< endl;
}