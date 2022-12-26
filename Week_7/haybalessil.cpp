#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int n, q;
vector<int>a;
int main()
{
    ifstream fin("haybales.in");
    ofstream fout("haybales.out");
    fin>>n>>q;
    int x;
    FOR(i, n){
        fin>>x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    int s, e, w;
    FOR(i, q){
        fin>>s>>e;
        w = upper_bound(a.begin(), a.end(), e) - a.begin() - (lower_bound(a.begin(), a.end(), s) - a.begin());
        fout/*<<upper_bound(a.begin(), a.end(), e) - a.begin()<<" "<<lower_bound(a.begin(), a.end(), s) - a.begin()<<" "*/<<w<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}