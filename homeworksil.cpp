#include <iostream>
#include <algorithm>
#include <fstream>
#define FOR(i, n) for(int i=0; i<n; i++)
using namespace std;
int n, score[100003], sufsum[100003], sufmin[100003];
long long bestsum, bestnum;
int main()
{
    ifstream fin("homework.in");
    ofstream fout("homework.out");
    fin>>n;
    for(int i=1; i<=n; i++){
        fin>>score[i];
    }
    sufsum[n] = score[n];
    sufmin[n] = score[n];
    for(int i = n-1; i >= 1; i--){
        sufsum[i] = sufsum[i+1] + score[i];
        sufmin[i] = min(sufmin[i+1], score[i]);
    }
    bestsum = 0;
    bestnum = 1;
    for(int k = 1; k <= n-2; k++){
        long long sum = sufsum[k+1]-sufmin[k+1];
        long long num = n-k-1;
        if(bestnum * sum > num * bestsum){
            bestsum = sum;
            bestnum = num;
        }
    }
    for(int i = 1; i <= n-2; i++){
        long long sum = sufsum[i+1]-sufmin[i+1]; 
        long long num = n-i-1;
        if(bestnum * sum == num * bestsum){
            fout<<i<<endl;
        }
    }
}
/*
5
3 1 9 2 7
*/