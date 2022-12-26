#include <iostream>
#include <fstream>
using namespace std;
int better, worse, ans;
int main()
{
    ifstream fin("gymnastics.in");
    ofstream fout("gymnastics.out");
    int k, n;
    int c, d, cpos, dpos;
    fin>>k>>n;
    int ranks[10][20];
    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++){
            fin>>ranks[i][j];
        }
    }
    /*for(int i=0; i<k; i++){
        for(int j=0; j<n; j++){
            fout<<ranks[i][j]<<" ";
        }
        fout<<endl;
    }*/
    for(c=1; c<=n; c++){
        for(d=c+1; d<=n; d++){
            //fout<<"c = "<<c<<" d = "<<d<<endl;
            for(int a=0; a<k; a++){
                for(int j=0; j<n; j++){
                    if(ranks[a][j]==c){
                        cpos=j;
                    }
                }
                for(int l=0; l<n; l++){
                    if(ranks[a][l]==d){
                        dpos=l;
                        }
                }
                //fout<<"cpos = "<<cpos<<" dpos = "<<dpos<<endl;
                if(cpos < dpos){
                    better++;
                }
                if(cpos > dpos){
                    worse++;
                }
                //fout<<"better = "<<better<<" worse = "<<worse<<endl;
            }
            if(better!=0 && worse !=0);
            else{
                ans++;
            }
            better=0;
            worse=0;
        }
    }
    fout<<ans;
}