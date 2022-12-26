#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int n;
string bessie, elsie, mother[100], daughter[100];
string findamother(string cow) //i means yes, 0 means no
{
    for(int i=0; i<n; i++){
        if(cow == daughter[i]){
            return mother[i];
        }
    }
    return "";
}
int is_ancestor(string c1, string c2)
{
    int counter = 0;
    while(c2 != ""){
        if(c1 == c2){
            return counter;
        }
        c2 = findamother(c2);
        counter++;
    }
    return -1;
}
int main()
{
    ifstream fin("family.in");
    ofstream fout("family.out");
    fin>>n>>bessie>>elsie;
    for(int i=0; i<n; i++){
        fin>>mother[i]>>daughter[i];
    }
    string cow=bessie;
    int b=0;
    while(cow != ""){
        if(is_ancestor(cow , elsie) != -1){
            break;
        }
        cow=findamother(cow);
        b++;
    }
    if(cow == ""){
        fout<<"NOT RELATED\n";
        return 0;
    }
    int a = is_ancestor(cow, elsie);
        if (a==1 && b==1){
            fout<<"SIBLINGS\n";
            return 0;
        }
        else if(a>1 && b>1){
            fout<<"COUSINS\n";
            return 0;
        }
        else{
            if(a>b){
                swap(elsie, bessie);
                swap(a,b);
            }
            fout<<elsie<<" is the ";
            for(int i=0; i<b-2; i++){
                fout<<"great-";
            }
            if(b > 1 && a==0){
                fout<<"grand-";
            }
            if(a==0){
                fout<<"mother of ";
            }
            else{
                fout<<"aunt of ";
            }
            fout<<bessie;
        }
}
// 13 GGAUNT AA
// MOTHER AA
// GGMOTHER GMOTHER
// MOTHER SISTER
// GMOTHER MOTHER
// GMOTHER AUNT
// AUNT COUSIN
// GGMOTHER GAUNT
// GGGMOTHER GGAUNT
// GGMOTHER GMOTHER
// GGAUNT OCOUSIN
// OCOUSIN OOCOUSIN
// UNRELATEDM UNRELATED
// GGGMOTHER GGMOTHER
// 7 AA BB
// MOTHER AA
// GGMOTHER BB
// MOTHER SISTER
// GMOTHER MOTHER
// GMOTHER AUNT
// AUNT COUSIN
// GGMOTHER GMOTHER