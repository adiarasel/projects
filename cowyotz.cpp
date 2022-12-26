#include <iostream>
#include <algorithm>
#include <cmath>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int n, s, e, sn, fn, a[10][30], freq[10], ans=0;
int number[8] = {1, 2, 3, 4, 5, 6, 7, 8};
string temp1;
void process()
{
    int value=0;
    bool okay;
    for(int i=0; i<n; i++){
        value = value * 10 + number[i];
    }
    temp1 = to_string(value);
    FOR(i, temp1.length()){
        freq[temp1[i]-'1']++;
    }
    // scan all rows & check
    FOR(row, e){
        okay = true;
        FOR(i, s){
            if(freq[i] < a[row][i]){
                okay = false;
            }
        }
        if(okay == true) ans++;
    }
}
void numgen(int e)
{
    if(e==s){
        process();
        return;
    }
    for(int i=0; i<s; i++){
        number[e] = freq[i];
        numgen(e+1);
    }
}
int main()
{
    cin>>n>>s>>e;
    string inp, temp="";
    FOR(i, e){
        cin>>inp;
        temp = "";
        FOR(i, inp.length()){
            if(inp[i]!= '+' && inp[i]!= 'x'){
                temp += inp[i];
            }
            if(inp[i] == 'x'){
                fn = stoi(temp);
                temp = "";
            }
            if(inp[i] == '+'){
                sn = stoi(temp);
                temp = "";
                a[i][sn] = fn;
            }
        }
    }
    numgen(0);
    cout<<ans<<endl;
}