//21-03-28 dfs solved

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int T, N, M, ANS;
vector<int> F[10];

void dfs(bool visited[], int left)
{
    if (left == 0) {
        ANS++;
        return ;
    }
    int next = -1;
    while (visited[++next]) continue ;
    visited[next] = true;
    for (unsigned int i=0; i<F[next].size(); i++) {
        if (visited[F[next][i]]) continue ;
        visited[F[next][i]] = true;
        dfs(visited, left-2);
        visited[F[next][i]] = false;
    }
    visited[next] = false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    for (int t=0; t<T; t++)
    {
        for (int i=0; i<10; i++)
            F[i].clear();
        cin>>N>>M;
        for (int i=0; i<M; i++)
        {
            int a, b;
            cin>>a>>b;
            if (a<b)
                F[a].push_back(b);
            else
                F[b].push_back(a);
        }
        bool visited[10];
        memset(visited, false, sizeof(visited));
        ANS = 0;
        dfs(visited, N);
        cout<<ANS<<endl;
    }
}