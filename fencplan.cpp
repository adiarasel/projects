#include <iostream>
#include <vector>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int n, m;
// DFS FLOODFILL
typedef pair<int,int> pii;
vector<pii> c;
vector<int> adjlist[100000];
int moonet[100000];
struct thing { 
    int x1;
    int x2;
    int y1;
    int y2; 
};
void visit(int i, int k, thing things)
{
    moonet[i] = k;
    things.x1 = min(things.x1, c[i].first);
    things.x2 = max(things.x2, c[i].first);
    things.y1 = min(things.y1, c[i].second);
    things.y2 = max(things.y2, c[i].second);
    for (int j : adjlist[i]) // range based for loop to go through adjacency list
    if (moonet[j]==0) visit(j, k, things);
}
int main()
{
    cin >> n >> m;
    pii p;
    FOR(i, n){
        cin >> p.first >> p.second;
        c.push_back(p);
    }
    FOR(i, m){
        cin >> p.first >> p.second;
        adjlist[p.first-1].push_back(p.second-1);
        adjlist[p.second-1].push_back(p.first-1);    
    }
    int k = 0, best = 9999999;
    for (int i=0; i<n; i++){     
        if (moonet[i] == 0) {
        thing thingies = {999999,0,999999,0};
        visit(i, ++k, thingies);
        best = min(best, 2*(thingies.x2-thingies.x1+thingies.y2-thingies.y1));
        }
    }
    cout << best << endl;
    return 0;
}