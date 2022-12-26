#include <iostream>
#include <fstream>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
long inde;
string s;
char ind(long n){
    if(n <= s.length()){
        // cout<<"finallyyyy"<<endl;
        return s[n-1];
    }
    long length = s.length();
    while(2 * length < n){
        length *= 2;
    }
    // cout<<length<<endl;
    if(length + 1 != n){
        return ind(n - (length+1));
    }
    else return ind(n - 1);

}
int main()
{
    ifstream fin("cowcode.in");
    ofstream fout("cowcode.out");
    fin>>s>>inde;
    fout<<ind(inde)<<endl;
    fin.close();
    fout.close();
    return 0;
}