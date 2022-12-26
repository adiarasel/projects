#include <iostream>
#include <fstream>
#include <string>
using namespace std;
char s[20000], ss[20000];
int slen, sslen;
int maxp, maxq, maxl = 0;
int findpal (int p, int q) {
    int i, j;
    while (ss[p] == ss[q] && p >= 0 && q < sslen){
        i = p;
        j = q;
        p--;
        q++;
    }
    if (j - i + 1 > maxl){
        maxp = i;
        maxq = j;
        maxl = j - i + 1;
    }
}
int main()
{
        char c;
    slen = 0;
    sslen = 0;
    while (cin.get(c)) {
        s[slen] = c;
        slen++;
        if (isalpha(c)) {
            ss[sslen] = tolower(c);
            sslen++;
        }
    }
    for (int i = 1; i < sslen; i++){
        //odd palindrome
        findpal (i - 1, i + 1);
        //even palindrome
        findpal (i - 1, i);
    }
    string output = "";
    int alpha = -1;
    for (int i = 0; i < slen && maxq >= alpha + 1; i++) {
        if (isalpha (s[i]))
            alpha++;
        if (maxp <= alpha && maxq >= alpha)
            output += s[i];
    }
    
    cout << maxl << endl;
    cout << output << endl;
}