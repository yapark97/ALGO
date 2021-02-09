//21-01-25 kmp solved

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string T, P;
int n, m;
vector<int> ans_pos; //문자열 위치
int ans_num = 0; //문자열 개수

int *getPi()
{
    int *p = new int[m];
    for (int i = 0; i < m; i++)
        p[i] = 0;
    int i = 0, j = 0;
    while (++i < m) {
        while (j > 0 && P[i] != P[j])
            j = p[j-1];
        if (P[i] == P[j])
            p[i] = ++j;
    }
    return p;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    getline(cin, T);
    getline(cin, P);
    n = T.length(); m = P.length();
    int *p = getPi();

    int i = 0, j = 0;
    while (i < n) {
        while (i < n && j < m &&T[i] == P[j]) {
            i++;
            j++;
        }
        if (j == m) {
            ans_num++;
            ans_pos.push_back(i - j);
        }
        if (j == 0)
            i++;
        else
            j = p[j-1];
    }
    cout<<ans_num<<"\n";
    for (int i = 0; i < ans_pos.size(); i++)
    {
        cout<<ans_pos[i]+1;
        if (i == ans_pos.size() - 1) cout<<"\n";
        else cout<<" ";  
    }
}