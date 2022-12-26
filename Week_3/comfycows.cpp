#include <iostream>
#include <algorithm>
#include <vector>
#define FOR(i, n) for(int i=0; i<n; i++)
#define pii pair<int, int>
using namespace std;
int n;
pii points[100000];
bool field[3003][3003];
int ans = 0;
vector<pii > getcells(int x, int y){
    return {{x + 1, y}, {x - 1, y}, {x, y}, {x, y + 1}, {x, y - 1}};
}
void recurse(int x, int y){
    if(!field[x][y]) return;
    vector<pii > neighbors = {{x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}};
    int comf = 0;
    FOR(i, 4){
        if(field[neighbors[i].first][neighbors[i].second]) comf++;
    }
    if(comf == 3){
        FOR(i, 4){
            if(!field[neighbors[i].first][neighbors[i].second]){
                field[neighbors[i].first][neighbors[i].second] = true;
                ans++;
                for(pii q:getcells(neighbors[i].first, neighbors[i].second)){
                    recurse(q.first, q.second);
                }
                return;
            }
        }
    }
}
int main()
{
    cin>>n;
    FOR(i, n){
        cin>>points[i].first>>points[i].second;
        points[i].first+=1000;
        points[i].second+=1000;

    }
    FOR(i, n){
        if(!field[points[i].first][points[i].second]){
            field[points[i].first][points[i].second] = true;
        }
        else ans--;
        for(pii p: getcells(points[i].first, points[i].second)){
            recurse(p.first, p.second);
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
9
0 1
1 0
1 1
1 2
2 1
2 2
3 1
3 2
4 1
*/