//21-02-01 trie success

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Trie
{
    string name;
    vector<struct Trie *> next;
};

bool compare(const Trie *t1, const Trie *t2)
{
    return (t1->name < t2->name);
}

int N, K;
string str;
Trie *trie;

void print(Trie *t, int depth)
{
    sort(t->next.begin(), t->next.end(), compare);
    if (depth >= 0)
    {
        for (int i=0; i<depth*2; i++)
            cout<<"-";
        cout<<t->name<<"\n";
    }
    int nsize = t->next.size();
    for (int i=0; i<nsize; i++)
        print(t->next[i], depth+1);
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>N;
    trie = new Trie();
    for (int i=0; i<N; i++)
    {
        cin>>K;
        Trie *cur = trie;
        for (int j=0; j<K; j++)
        {
            cin>>str;
            //next중 string 찾음
           
            int nlen = cur->next.size(), k;
            for (k=0; k<nlen; k++)
                if (cur->next[k]->name == str)
                    break ;
            if (k == nlen) //없으면
            {
                Trie *newtrie = new Trie();
                newtrie->name = str;
                cur->next.push_back(newtrie);
            }
            cur = cur->next[k];
        }
    }
    //출력
    print(trie, -1);
}