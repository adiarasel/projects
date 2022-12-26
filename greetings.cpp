#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int b, e, bessloc=0, elsiloc=0;
int main()
{
    string bess, elsi;
    cin>>b>>e;
    char c;
    int x, y, maxt;
    for(int i = 0; i<b; i++){
        cin>>x>>c;
        if(c == 'L'){
            for(int j=0; j<x; j++){
                bess.push_back('L');
            }
        }
        if(c == 'R'){
            for(int j=0; j<x; j++){
                bess.push_back('R');
            }
        }
    }
    for(int i = 0; i<e; i++){
        cin>>x>>c;
        if(c == 'L'){
            for(int j=0; j<x; j++){
                elsi.push_back('L');
            }
        }
        if(c == 'R'){
            for(int j=0; j<x; j++){
                elsi.push_back('R');
            }
        }
    }
    //cout<<bess<<" "<<elsi<<endl;
    x = bess.length();
    y = elsi.length();
    maxt  = max(x, y);
    if(x>y){
        for(int i=y; i<x; i++){
            elsi.push_back('S');
        }
    }
    else if(x<y){
        for(int i=y; i<x; i++){
            bess.push_back('S');
        }
    }
    int ans=0, prevb = 0, preve = 0;
    for(int i=0; i < maxt; i++){
        if(bess[i] == 'L') bessloc--;
        if(bess[i] == 'R') bessloc++;
        if(elsi[i] == 'L') elsiloc--;
        if(elsi[i] == 'R') elsiloc++;
        //cout<<bessloc<<" "<<elsiloc<<endl;
        if(bessloc == elsiloc && prevb != preve) ans++;
        prevb = bessloc;
        preve = elsiloc;
    }
    cout<<ans;
}
//50/100