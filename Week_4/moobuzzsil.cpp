#include <iostream>
#include <fstream>
using namespace std; 
int main()
{
    ifstream fin("moobuzz.in");
    ofstream fout("moobuzz.out");
    long long n;
    fin>>n;
    long long x[8] = {1, 2, 4, 7, 8, 11, 13, 14};
    long long answer = (n/8)*15 + x[n%8 - 1];
    if(n % 8 == 0) answer = (n/8 - 1)*15 + x[7];
    fout<< answer;
}

/*
917588616
*/