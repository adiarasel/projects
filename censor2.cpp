#include <iostream>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
string s, t, result = "";
int main()
{
    cin>>s>>t;
    FOR(i, s.size()){
        result = result + s[i];
        if(result.size()>= t.size() && result.substr(result.size()-t.size()) == t){
            result.resize(result.size() - t.size());
        }
    }
    cout<<result<<endl;
}