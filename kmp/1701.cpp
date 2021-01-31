//21-01-26 kmp success

#include <iostream>
#include <string>

using namespace std;

string str;
int len;

int getPi(int idx) // start index
{
    string S = str.substr(idx, len - idx);
    int n = S.length();
    int *p = new int[n];
    for (int i = 0; i < n; i++)
        p[i] = 0;
    int i = 0, j = 0;
    while (++i < n) {
        while (j>0 && S[i] != S[j])
            j = p[j-1];
        if (S[i] == S[j])
            p[i] = ++j;
    }
    int ret = 0;
    for (int i = 0; i < n; i++)
        ret = ret > p[i] ? ret : p[i];
    delete[] p;
    return ret;
}

int main()
{
    getline(cin, str);
    int max = 0;
    len = str.length();
    for (int i = 0; i < len; i++) {
        int temp = getPi(i);
        max = temp > max ? temp : max;
    }
    cout<<max<<endl;
}