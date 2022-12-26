#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
char puzzle[50][50];
int n, m;
int checkrowcol(char c, char d){
    int row, col;
    int counter = 0;
    FOR(i, n){
        FOR(j, m){
            if(puzzle[i][j] == c){
                row = i;
                col = j;
                if(col + 2 < n && puzzle[row][col+1] == d && puzzle[row][col+2] == d){ // right
                    counter++;
                }
                if(col - 2 >= 0 && puzzle[row][col-1] == d && puzzle[row][col-2] == d){ // left
                    counter++;
                }
                if(row - 2 >= 0 && puzzle[row-1][col] == d && puzzle[row-2][col] == d){ // up
                    counter++;
                }
                if(row + 2 < n && puzzle[row+1][col] == d && puzzle[row+2][col] == d){ // down
                    counter++;
                }
            }
        }
    }
    return counter;
}

int checkdiags(char c, char d){
    int row, col;
    int counter = 0;
    FOR(i, n){
        FOR(j, m){
            if(puzzle[i][j] == c){
                row = i;
                col = j;
                if(col + 2 < n && row - 2 >= 0 && puzzle[row-1][col+1] == d && puzzle[row-2][col+2] == d){ // right and up
                    counter++;
                }
                if(col - 2 >= 0 && row + 2 < n && puzzle[row+1][col-1] == d && puzzle[row+2][col-2] == d){ // left and down
                    counter++;
                }
                if(col - 2 >= 0 && row - 2 >= 0 && puzzle[row-1][col-1] == d && puzzle[row-2][col-2] == d){ // left and up
                    counter++;
                }
                if(col + 2 < n && row + 2 < n && puzzle[row+1][col+1] == d && puzzle[row+2][col+2] == d){ // right and down
                    counter++;
                }
            }
        }
    }
    return counter;
}

int main()
{
    ifstream fin("moocrypt.in");
    ofstream fout("moocrypt.out");
    fin>>n>>m;
    FOR(i, n){
        FOR(j, m){
            fin>>puzzle[i][j];
        }
    }
    int ans = -1;
    for(char i = 'A'; i <= 'Z'; i++){
        for(char j = 'A'; j <= 'Z'; j++){
            if(i != j && i != 'M' && j != 'O') ans = max(ans, checkrowcol(i, j) + checkdiags(i, j));
        }
    }
    fout<<ans<<endl;
    fin.close();
    fout.close();
    return 0;
}