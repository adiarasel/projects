#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;

set<string> input;
int n;
string cow1, cow2, cow3;
map<set<string>, int> freq;
int main()
{
    ifstream fin("records.in");
    ofstream fout("records.out");
    fin>>n;
    FOR(i, n){
        fin>>cow1>>cow2>>cow3;
        input.insert(cow1);
        input.insert(cow2);
        input.insert(cow3);
        freq[input]++;
        input.clear();
    }
    int maxs = -1;
    for(auto elem: freq){
        maxs = max(maxs, elem.second);
    }
    fout<<maxs<<endl;
    fin.close();
    fout.close();
    return 0;
}