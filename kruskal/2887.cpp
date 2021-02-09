//21-02-09 solved

#include <iostream>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct path
{
    path(int _src, int _dst, int _cost) {
        src = _src; dst = _dst; cost = _cost;
    }
    int src;
    int dst;
    int cost;
};

struct cmp
{
    bool operator()(path &p1, path &p2) {
        return p1.cost > p2.cost;
    }
};

int N;
int pos[100000][3];
int parents[100000];
vector<pair<int, int>> X, Y, Z;

int _find(int p)
{
    if (parents[p]<0) return p;
    int root = _find(parents[p]);
    parents[p] = root;
    return root;
}

void _union(int p1, int p2)
{
    p1 = _find(p1);
    p2 = _find(p2);
    p1[parents] = p2;
}

int main()
{
    cin>>N;
    memset(parents, -1, sizeof(parents));
    priority_queue<path, vector<path>, cmp> pq;
    for (int i=0; i<N; i++)
    {
        cin>>pos[i][0]>>pos[i][1]>>pos[i][2];
        X.push_back(make_pair(pos[i][0], i));
        Y.push_back(make_pair(pos[i][1], i));
        Z.push_back(make_pair(pos[i][2], i));
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());
    for (int k=0; k<N-1; k++)
    {
        int i = X[k].second, j = X[k+1].second;
        pq.push(path(i, j, min(abs(pos[i][0]-pos[j][0]), min(abs(pos[i][1]-pos[j][1]), abs(pos[i][2]-pos[j][2])))));
        i = Y[k].second, j = Y[k+1].second;
        pq.push(path(i, j, min(abs(pos[i][0]-pos[j][0]), min(abs(pos[i][1]-pos[j][1]), abs(pos[i][2]-pos[j][2])))));
        i = Z[k].second, j = Z[k+1].second;
        pq.push(path(i, j, min(abs(pos[i][0]-pos[j][0]), min(abs(pos[i][1]-pos[j][1]), abs(pos[i][2]-pos[j][2])))));
    }
    int E = 0;
    int ans = 0;
    while (E < N-1) {
        path cur = pq.top();
        pq.pop();
        if (_find(cur.src) != _find(cur.dst)) {
            _union(cur.src, cur.dst);
            E++;
            ans += cur.cost;
        }
    }
    cout<<ans<<endl;
}