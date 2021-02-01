//21-02-01 trie success

#include <iostream>

using namespace std;

struct Trie
{
    bool end = false;
    Trie *next[26] = {0};
};

int N, M;
Trie *trie;
string str;
int ans = 0;

void add(string s)
{
    int i = -1;
    Trie *t = trie;
    while (s[++i])
    {
        if (!t->next[s[i] - 'a'])
            t->next[s[i] - 'a'] = new Trie();
        t = t->next[s[i] - 'a'];
    }
    t->end = true;
}

bool _find(string s)
{
    int i = -1;
    Trie *t = trie;
    while (s[++i])
    {
        if (!t->next[s[i] - 'a'])
            break ;
        t = t->next[s[i] - 'a'];
    }
    if (!s[i] && t->end)
        return true;
    return false;
}

int main()
{
    cin>>N>>M;
    trie = new Trie();
    for (int i=0; i<N; i++)
    {
        cin>>str;
        add(str);
    }
    for (int i=0; i<M; i++)
    {
        cin>>str;
        if (_find(str))
            ans++;
    }
    cout<<ans<<endl;
}