#include <iostream> 
#include <fstream>
using namespace std;
int n;
char canvas[10][10];
int freq[10];
int overlap(char color1, char color2){// 0 if it doesn't overlap, 1 if it overlaps
    // cout << "Rectangle for color " << color1 << endl;
    // cout << "check" << color2 << endl;
    int minx=101, miny=101, maxx=-1, maxy=-1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(canvas[i][j]==color1){
                if(i<minx){
                    minx=i;
                }
                if(i>maxx){
                    maxx=i;
                }
                if(j<miny){
                    miny=j;
                }
                if(j>maxy){
                    maxy=j;
                }
            }
        }
    }
    // cout<<minx<<" "<<miny<<" "<<maxx<<" "<<maxy<<endl;
    for(int i=minx; i<=maxx; i++){
        for(int j=miny; j<=maxy; j++){
            // cout<<"Does "<<color2<<" overlap "<<color1<<"?"<<endl;
            if(canvas[i][j]==color2){
                // cout<<"1"<<endl;
                // cout << "    YES" << endl;
                return 1;
            }
            // cout << "    NO" << endl;
        }
    }
    // cout<<"0"<<endl;
    // cout << "    NO" << endl;
    return 0;
}
bool colorExists(char c) {
    for(int useless=0; useless<n; useless++){
        for(int haters=0; haters<n; haters++){
            if(canvas[useless][haters] == c) {
                return true;
            }
        }
        
    }
    return false;
}
int main()
{
    ifstream fin("art.in");
    ofstream fout("art.out");
    fin>>n;
    //fout<<n<<endl;
    int counter=0;
    for(int useless=0; useless<n; useless++){
        for(int haters=0; haters<n; haters++){
            fin>>canvas[useless][haters];
        }
    }
    for(char i='1'; i<='9'; i++){
        for(char j='1'; j<='9'; j++){
            //fout<<"entered loops"<<endl;
            if(i==j){
                continue;
            }
            if (colorExists(i) && colorExists(j)) {
                // fout<<"Does "<<j<<" overlap "<<i<<"?"<<endl;
                if(overlap(i,j)==0){
                    freq[j-'0']++;
                    // fout<<"freq["<<i<<"] = "<<freq[i-'0']<<endl;
                    // fout << "NO" << endl;
                } 
                else {
                    freq[j-'0']=0;
                    // fout<<"freq["<<i<<"] = "<<freq[i-'0']<<endl;
                    // fout << "YES" << endl;
                }
            }
        }
    }
    /*for(int i=0; i<n; i++){
        fout<<"freq["<<i<<"] = "<<freq[i]<<endl;
    }*/
    int temp=canvas[0][0];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            bool stupid=false;
            for(int k=1000; k>=1; k--){
                for(int l=1; l<=9; l++){
                    if(freq[l]==k){
                        counter++;
                        stupid=true;
                    }
                }
                if(stupid==true) break;
                counter=0;
                stupid=false;
            }
        }
    }
    int y;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(canvas[i][j]!=temp){
                y++;
            }
        }
    }
    if(y==0) counter=1;
    fout<<counter;
}
/*
harder sample case
6
987710
987710
987336
221335
401335
001336
easy checks
4 
9988
9988
7766
7766

another easy check
4
1122
1122
3344
3307

very stupid check
3
111
111
111

somewhat very hard sample case: ans is 6
10
0000005590
2222225590
2222225500
7773305500
7773305500
7773385511
7778880111
7778880111
7778880111
0008880440

sample case 10; ans is 4
10
0200000000
0218799900
0218499900
5238799930
5237799930
5337799930
5007799900
5007799900
6667700000
6660000000
*/
