#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <vector>
#define FOR(i, n) for(int i=0; i<n; i++)
#define size first
#define pos second
using namespace std;
int n;
pair<int, int> bales[1000]; // first is size, then pos
bool comp(pair<int, int> a, pair<int, int> b){ // sorts by second, not first
    if(a.pos < b.pos) return true;
    else return false;
}
int main()
{
    ifstream fin("trapped.in");
    ofstream fout("trapped.out");
    cin>>n;
    FOR(i, n){
        cin>>bales[i].size>>bales[i].pos;
    }
    sort(bales, bales + n, comp);
    int start, endd;
    int counter = 0, area, left, right, curdist;
    for(int i = 0; i < n-1; i++) {
        area = bales[i+1].pos - bales[i].pos;
        left = i;
        right = i+1;
        // while Bessie could still be trapped
        while(left >= 0 && right <= n-1) {
            bool broken = false;
            curdist = bales[right].pos - bales[left].pos;
            if(curdist > bales[left].size) {
                left--;
                broken = true;
            }
            if(curdist > bales[right].size) {
                right++;
                broken = true;
            }
            if(!broken) {
                break;
            }
        } 
        // Bessie couldn't break out
        if(left >= 0 && right <= n-1) {
            counter += area;
        }
    }
    cout<<counter<<endl;
    fin.close();
    fout.close();
    return 0;
}