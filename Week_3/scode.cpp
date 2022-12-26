#include <iostream>
#include <fstream>
#include <vector>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int recurse (string s){
    int n = s.length();
    if(n == 1 || n % 2 == 0){
        return 1;
    }
    int h = n/2 + 1;
    string t1 = s.substr(0, h);
    int ways1 = 0;
    if(t1 + t1.substr(0, h-1) == s) ways1++;
    if(t1 + t1.substr(1, h-1) == s) ways1++;
    string t2 = s.substr(h-1, h); 
    int ways2 = 0;
    if(t2.substr(0, h-1) + t2 == s) ways2++;
    if(t2.substr(1, h-1) + t2 == s) ways2++;
    return 1 + ways1 * recurse(t1) + ways2 * recurse(t2);
}
int main()
{
    ifstream fin("scode.in");
    ofstream fout("scode.out");
    string s;
    fin>>s;
    fout<<recurse(s) - 1;
    fin.close();
    fout.close();
    return 0;
}