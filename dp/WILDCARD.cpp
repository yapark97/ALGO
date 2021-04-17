//21-04-10 WILDCARD solved

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int T, N;
string W, S;
vector<string> ANS;
int DP[100][100];

int match(int wi, int si)
{
    if (DP[wi][si] != -1)
        return DP[wi][si];
    int ret;
    if (W[wi] != '*' && W[wi] != '?') {
        if (W[wi] != S[si])
            ret = 0;
        else if (wi == 0 && si == 0)
            ret = 1;
        else if (wi > 0 && si > 0)
            ret = match(wi-1, si-1);
        else if (si == 0 && W[wi-1] == '*')
            ret = match(wi-1, si);
        else
            ret = 0;
    }
    else if (W[wi] == '*') {
        if (wi == 0)
            ret = 1;
        else {
            int i;
            for (i=si; i>=0; i--)
                if (match(wi-1, i))
                    break;
            ret = i==-1?0:1;
        }
    }
    else {
        if (wi == 0 && si == 0)
            ret = 1;
        else if (wi == 0 || si == 0)
            ret = 0;
        else
            ret = match(wi-1, si-1);
    }
    DP[wi][si] = ret;
    return DP[wi][si];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    for (int t=0; t<T; t++)
    {
        ANS.clear();
        cin>>W;
        cin>>N;
        int Wlen = W.length();
        for (int i=0; i<N; i++)
        {
            memset(DP, -1, sizeof(DP));
            cin>>S;
            int Slen = S.length();
            if (match(Wlen-1, Slen-1))
                ANS.push_back(S);
        }
        sort(ANS.begin(), ANS.end());
        for (unsigned int i=0; i<ANS.size(); i++)
            cout<<ANS[i]<<"\n";
    }
}