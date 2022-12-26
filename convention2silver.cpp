#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
using namespace std;
int n;
typedef long long LL;
typedef pair<LL,LL> pll;
vector<pair<int, pll>> cows;
set<pll> waiting;  
LL solve(void)
{
    LL answer = 0, curfin;
    int nexcow = 1;
    sort(cows.begin(), cows.end());
    curfin = cows[0].first + cows[0].second.second;
    while (nexcow < n || waiting.size() > 0) {
        while (nexcow < n && cows[nexcow].first <= curfin) {
            waiting.insert(make_pair(cows[nexcow].second.first, nexcow));
            nexcow++;
        }
        if (waiting.size() == 0 && nexcow < n) {
            // Idle time; schedule next cow...
            curfin = cows[nexcow].first + cows[nexcow].second.second;
            nexcow++;
        } 
        else if (waiting.size() > 0) {
            // next-most-senior cow in waiting list scheduled next
            set<pll>::iterator mossen = waiting.begin();
            answer = max(answer, curfin - cows[mossen->second].first);
            curfin = curfin + cows[mossen->second].second.second;
            waiting.erase(mossen);
        }
    }
    return answer;
}
int main()
{
    int a, t;
    ifstream fin ("convention2.in");
    ofstream fout ("convention2.out");
    fin >> n;
    for (int i=0; i<n; i++) {
        fin >> a >> t;
        cows.push_back(make_pair(a,make_pair(i,t)));
    }
    fout << solve() << "\n";
    return 0;
}
