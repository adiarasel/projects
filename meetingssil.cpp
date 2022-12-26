#include <fstream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
struct cow{
    int x;
    int w;
    int d;
    int t;
};

bool compx(cow a, cow b){
    return a.x < b.x;
}

bool cmpt(cow a, cow b){
    return a.t < b.t;
}

int n, l, t, ans;
long long total = 0;
long long sum = 0;
queue<int> q;
vector<cow> cows;
int main()
{
    ifstream fin("meetings.in");
    ofstream fout("meetings.out");
    fin >> n >> l;
    cows.resize(n);
    for (int i = 0; i < n; i++){
        fin >> cows[i].w >> cows[i].x >> cows[i].d;
    }
    sort(cows.begin(), cows.end(), compx);
    vector<cow> lcows, rcows;
    for (int i=0; i<cows.size(); i++){
        if (cows[i].d == -1){
            lcows.push_back(cows[i]);
        }
        else{
            rcows.push_back(cows[i]);
        }
    }
    for(int i = 0; i < lcows.size(); i++){
        cows[i].t = lcows[i].x;
    }
    for(int i = 0; i < rcows.size(); i++){
        cows[n - i - 1].t = l - rcows[rcows.size() - i - 1].x;
    }
    for (int i=0; i<cows.size(); i++){
        total += cows[i].w;
    }
    sort(cows.begin(), cows.end(), cmpt);
    for(int i = 0; total > 0 && i < n; i++){
        total -= 2*cows[i].w;
        t = cows[i].t;
    }
    sort(cows.begin(), cows.end(), compx);
    int countl = 0, countR = 0;
    for (int i=0; i<cows.size(); i++) {
        if (cows[i].d == 1){
            q.push(cows[i].x);
            continue;
        }
        while (!q.empty() && cows[i].x - q.front() > 2 * t){
            q.pop();
        }
        ans += q.size();
    }
    fout << ans << endl;
}