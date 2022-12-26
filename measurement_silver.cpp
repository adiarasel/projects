#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
using namespace std;
struct measurement{
    int day;
    int cow;
    int delta;
};
bool comp(measurement a, measurement b)
{
    return a.day < b.day;
}
int main()
{
    ifstream fin("measurement_silver.in");
    ofstream fout("measurement_silver.out");
    int N, G;
    fin>>N>>G;
    vector<measurement> A(N);
    for(auto& m : A){
        fin>>m.day>>m.cow>>m.delta;
    }
    sort(A.begin(), A.end()/*, (const measurement& a, const measurement& b) {
        return a.day < b.day;
    }*/, comp);
    map<int, int, greater<int> > cnts;
    cnts[0] = N + 1;
    int result = 0; 
    map<int ,int> mp;
    for(auto& m : A){
        int& ref = mp[m.cow];
        bool wastop = ref == cnts.begin()->first;
        int wascnt = cnts[ref]--;
        if(wascnt == 1){
            cnts.erase(ref);
        }
        ref += m.delta;
        int iscnt = ++cnts[ref];
        bool istop = ref == cnts.begin()->first;
        if(wastop){
            if(!istop || wascnt != 1 || iscnt != 1){
                ++result;
            }
        }
        else if(istop){
                ++result;
        }
    }
    fout<<result<<endl;
}
/*
4 10
7 3 +3
4 2 -1
9 3 -1
1 1 +2

2 1
1 1 +1
2 1 +1
*/