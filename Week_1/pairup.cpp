#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <utility>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int n; // n is at most 100000
pair<int, int> cows[100000];
int startlist = 0, endlist, maxtime = -1;
bool comp(pair<int, int> a, pair<int, int> b){
    if(a.second < b.second) return true;
    else return false;
}
int main()
{
    ifstream fin("pairup.in");
    ofstream fout("pairup.out");
    fin>>n;
    FOR(i, n){
        fin>>cows[i].first>>cows[i].second;
    }
    sort(cows, cows + n, comp);
    // FOR(i, n){
    //     cout<<cows[i].first<<" "<<cows[i].second<<endl;
    // }
    endlist = n-1;
    for(int i = 0; endlist >= startlist; i++){
        if(cows[startlist].first < cows[endlist].first){
            cows[endlist].first -= cows[startlist].first;
            maxtime = max(maxtime, cows[startlist].second + cows[endlist].second);
            startlist++;
            // cout<<"less"<<endl;
        }
        else if(cows[startlist].first > cows[endlist].first){
            cows[startlist].first -= cows[endlist].first;
            maxtime = max(maxtime, cows[startlist].second + cows[endlist].second);
            endlist--;
            // cout<<"more"<<endl;
        }
        else{
            cows[startlist].first = 0;
            cows[endlist].first = 0;
            maxtime = max(maxtime, cows[startlist].second + cows[endlist].second);
            endlist--;
            startlist++;
            // cout<<"equal numbers"<<endl;
        }
        if(endlist == startlist){
            maxtime = max(maxtime, 2 * cows[startlist].first);
            // cout<<"pretty near the end?"<<endl;
        }
    }
    fout<<maxtime<<endl;
    fin.close();
    fout.close();
    return 0;
}