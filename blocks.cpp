#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int n;
int freq[26];
int main()
{
    ifstream fin("blocks.in");
    ofstream fout("blocks.out");
    fin>>n;
    string s, r;
    for(int i=0; i< n; i++){
        fin>>s>>r;
        for(int i=0; i<20; i++){
            if(s[i] == r[i]){
                //fout<<"entered if"<<endl;
                freq[s[i]-'a']++;
            }
            else if(s[i] != r[i]){
                //fout<<"entered else if"<<endl;
                freq[s[i]-'a']++;
                freq[r[i]-'a']++;
            }
        }
    }
    for(int a=0; a<26; a++){
        fout<<freq[a]<<endl;
    }
}