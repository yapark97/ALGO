//168page CLOCKSYNC solved

#include <iostream>
#include <vector>

using namespace std;

int T, ANS;
vector<vector<int>> S = {{0, 1, 2}, {3, 7, 9, 11}, \
{4, 10, 14, 15}, {0, 4, 5, 6, 7}, {6, 7, 8, 10, 12}, {0, 2, 14, 15}, \
{3, 14, 15}, {4, 5, 7, 14, 15}, {1, 2, 3, 4, 5}, {3, 4, 5, 9, 13}};

void bf(int n, int c[], int s)
{
    if (n == 10)
    {
        for (int i=0; i<16; i++)
            if (c[i] != 12) return ;
        ANS = min(ANS, s);
        return ;
    }
    bf(n+1, c, s);
    for (unsigned int i=0; i<S[n].size(); i++)
        c[S[n][i]]  = c[S[n][i]] == 12 ? 3 : c[S[n][i]] + 3;
    bf(n+1, c, s+1);
    for (unsigned int i=0; i<S[n].size(); i++)
        c[S[n][i]]  = c[S[n][i]] == 12 ? 3 : c[S[n][i]] + 3;
    bf(n+1, c, s+2);
    for (unsigned int i=0; i<S[n].size(); i++)
        c[S[n][i]]  = c[S[n][i]] == 12 ? 3 : c[S[n][i]] + 3;
    bf(n+1, c, s+3);
    for (unsigned int i=0; i<S[n].size(); i++)
        c[S[n][i]]  = c[S[n][i]] == 12 ? 3 : c[S[n][i]] + 3;
}

int main()
{
    int c[16];
    cin>>T;
    for (int t=0; t<T; t++)
    {
        for (int i=0; i<16; i++)
            cin>>c[i];
        ANS = 100;
        bf(0, c, 0);
        if (ANS == 100) ANS = -1;
        cout<<ANS<<endl;
    }
}