//21-01-31 kmp solved

#include <iostream>
#include <string>

using namespace std;

int L;
string S;

int *getPi()
{
    int *p = new int[L];
    for (int i = 0; i < L; i++)
        p[i] = 0;
    int i = 0, j = 0;
    while (++i < L) {
        while (j > 0 && S[i] != S[j])
            j = p[j-1];
        if (S[i] == S[j])
            p[i] = ++j;
    }
    return p;
}

int main()
{
    cin>>L;
    cin.ignore();
    getline(cin, S);
    int *p = getPi();

    cout<<L - p[L-1]<<endl;
}