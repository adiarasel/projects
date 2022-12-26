#include <iostream>
#include <algorithm>
using namespace std;
int n, matrix[201][201];
//ZERO INDEXED PROBLEM
int calcrows(int i) // takes input of which row, calculates MAX sum in that row
{
    int sum = 0, maxsum = -100000, num;
    for(int len=1; len <= n; len++){ //length of sum string
        for(int j=0; j<n; j++){ //index of col that you start with
            num=j;
            for(int counter=0; counter < len; counter++){
                sum += matrix[i][num];
                num++;
                if(num == n) num = 0;
            }
            maxsum = max(maxsum, sum);
            sum = 0;
        }
    }
    return maxsum;
}
int calccols(int j) // takes input of which col, calculates MAX sum in that col
{
    int sum = 0, maxsum = -10000000, num;
    for(int len=1; len <= n; len++){ //length of sum string
        for(int i=0; i<n; i++){ //index of row that you start with
            num=i;
            for(int counter=0; counter < len; counter++){
                sum += matrix[num][j];
                num++;
                if(num == n) num = 0;
            }
            maxsum = max(maxsum, sum);
            sum = 0;
        }
    }
    return maxsum;
}
int calcupdiag(int row, int col) // diagonal goes up from left to right; take input on which point to start from
{
    int sum = 0, maxsum = -1000000, num;
    int dummyi = row, dummyj = col;
    for(int len=1; len <= n; len++){ //length of sum string
        dummyi = row, dummyj = col;
        for(int i=0; i<n; i++){
            for(int counter=0; counter < len; counter++){
                sum += matrix[dummyi][dummyj];
                dummyi--;
                dummyj++;
                if(dummyi == -1) dummyi = n-1;
                if(dummyj == n) dummyj = 0;
            }
            maxsum = max(maxsum, sum);
            sum = 0;
            row--;
            col++;
            if(row == -1) row = n-1;
            if(col == n) col = 0;
        }
    }
    return maxsum;
}
int calcdowndiag(int row, int col) // diagonal goes down from left to right; take input on which point to start from
{
    int sum = 0, maxsum = -1000000, num;
    int dummyi = row, dummyj = col;
    for(int len=1; len <= n; len++){ //length of sum string
        dummyi = row, dummyj = col;
        for(int i=0; i<n; i++){
            for(int counter=0; counter < len; counter++){
                sum += matrix[dummyi][dummyj];
                dummyi--;
                dummyj--;
                if(dummyi == -1) dummyi = n-1;
                if(dummyj == -1) dummyj = n-1;
            }
            maxsum = max(maxsum, sum);
            sum = 0;
            row--;
            col++;
            if(row == -1) row = n-1;
            if(col == n) col = 0;
        }
    }
    return maxsum;
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>matrix[i][j];
        }
    }
    int totalmaxsum = -10000000;
    for(int i=0; i<n; i++){
        totalmaxsum = max(calcrows(i), totalmaxsum);
        totalmaxsum = max(calccols(i), totalmaxsum);
    }
    for(int i=0; i<n; i++){
        totalmaxsum = max(calcupdiag(0,i), totalmaxsum);
        totalmaxsum = max(calcdowndiag(0,i), totalmaxsum);
    }
    for(int i=0; i<n; i++){
        totalmaxsum = max(calcupdiag(i,n-1), totalmaxsum);
        totalmaxsum = max(calcdowndiag(i,n-1), totalmaxsum);
    }
    cout<<totalmaxsum;
}