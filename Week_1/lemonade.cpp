#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <queue>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;

int n, w[100000], linelen = 0;

bool comp(int a , int b) //custom sorts in reverse
{
    if(a > b){
        return true;
    }
    else return false;
}
int main()
{
    ifstream fin("lemonade.in");
    ofstream fout("lemonade.out");
    
    //Read the varaiables
    // DO NOT use cin, use fin instead
    fin>>n;
    FOR(i, n){
        fin>>w[i];
    }
    sort(w, w + n, comp); // sorts in reverse
    FOR(i, n){
        if(w[i] >= linelen){
            linelen++;
        }
    }
    //close the program
    fout<<linelen<<endl;
    fin.close();
    fout.close();
    return 0;
}