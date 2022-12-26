#include <iostream> 
#include <fstream>
using namespace std;
int n, k, piece1, piece2, ans_x, ans_y;
char orig[8][8], pieces[10][8][8], a[8][8], b[8][8];
int hashcount, hashcounter[10];
char  t1[8][8], t2[8][8];
char c[8][8];
int main()
{
    ifstream fin("bcs.in");
    ofstream fout("bcs.out");
    fin>>n>>k;
    int horizontal1=-1*(n-1), vertical1=-1*(n-1), horizontal2=-1*(n-1), vertical2=-1*(n-1);
    // fout<<n<<" "<<k<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            fin>>orig[i][j];
            //fout<<orig[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            t1[i][j]='.';
            t2[i][j]='.';
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(orig[i][j]=='#'){
                hashcount++;
            }
        }
    }
    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++){
            for(int l=0; l<n; l++){
                fin>>pieces[i][j][l];
            }
        }
    }
    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++){
            for(int l=0; l<n; l++){
                if(pieces[i][j][l]=='#'){
                    hashcounter[i]++;
                }
            }
        }
    }
    for(piece1=0; piece1<k; piece1++){
        for(piece2=piece1+1; piece2<k; piece2++){
            if(hashcounter[piece1] + hashcounter[piece2] != hashcount){
                continue;
            }
            else{
                for(int r=0; r<n; r++){
                    for(int c=0; c<n; c++){
                        a[r][c]=pieces[piece1][r][c];
                        b[r][c]=pieces[piece2][r][c];
                    }
                }
                //place where conditions to go :)
                for(int r=0; r<n; r++){
                    for(int c=0; c<n; c++){
                        t1[r][c]=a[r+vertical1][c+horizontal1];//shifitng the first piece 
                        t2[r][c]=b[r+vertical2][c+horizontal2];//shifitng the second piece 
                    }
                }
                int counter=0;
                for(int i=0; i<n; i++){ //superimposing the matrices together
                    for(int j=0; j<n; j++){
                        if(t1[i][j]=='#'){
                            c[i][j]='#';
                        }
                        else if(t2[i][j]=='#'){
                            c[i][j]='#';
                        }
                        if(t1[i][j]=='.' && t2[i][j]=='.'){
                            c[i][j]='.';
                        }
                    }
                }
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        if(c[i][j]==orig[i][j]){//comparing the matrix to the original one
                            ans_x=piece1;
                            ans_y=piece2;
                            fout<<ans_x+1<<" "<<ans_y+1;
                            return 0;
                        }
                    }
                }
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        t1[i][j]='.';
                        t2[i][j]='.';
                    }
                }
            }
        }
    }
}
// condition setup
// for(int r=0; r<n; r++){
//     for(int c=0; c<n; c++){
//         t1[r][c]=a[r+vertical1][c+horizontal1];//shifitng the first piece 
//         t2[r][c]=b[r+vertical2][c+horizontal2];//shifitng the second piece 
//     }
// }