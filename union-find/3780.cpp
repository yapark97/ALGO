//21-01-31 union-find solved

#include <iostream>

using namespace std;

int T, N, I, J;
char cmd;
int parent[20001][2]; //1~N

int _find(int i, int *cost)
{
    if (!parent[i][0]) return i;
    int j = parent[i][0];
    int root = _find(j, cost);
    
    *cost += parent[i][1];
    parent[i][0] = root;
    parent[i][1] = *cost;
    return root;
}

void _union(int i, int j)
{
    parent[i][0] = j;
    parent[i][1] = j > i ? (j-i)%1000 : (i-j)%1000;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>T;
    for (int t=0; t<T; t++)
    {
        cin>>N;
        for (int i=1; i<=N; i++)
        {
            parent[i][0] = 0;
            parent[i][1] = 0;
        }
        while (true)
        {
            cin>>cmd;
            if (cmd == 'O')
                break ;
            if (cmd == 'E')
            {
                cin>>I;
                int len = 0;
                _find(I, &len);
                cout<<len<<"\n";
            }
            if (cmd == 'I')
            {
                cin>>I>>J;
                _union(I, J);
            }
        }
    }
}