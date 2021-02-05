//21-02-05 Kruskal success

#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

struct path
{
    path(int s, int ds, double di) {
        src = s; dst = ds; dist = di;
    }
    int src;
    int dst;
    double dist;
};

struct compare
{
    bool operator() (path &p1, path &p2)
    {
        return p1.dist > p2.dist;
    }
};

priority_queue<path, vector<path>, compare> pq;

int N, M;
int edges = 0;
int pos[1001][2];
double ans = 0;
int parents[1001];

int _find(int idx) {
    if (!parents[idx]) return idx;
    return _find(parents[idx]);
}

void _union(int i, int j) {
    i = _find(i);
    j = _find(j);
    if (i != j)
        parents[i] = j;
}

int main()
{
    cin>>N>>M;
    for (int i=1; i<=N; i++)
    {
        cin>>pos[i][0]>>pos[i][1];
        for (int j=i-1; j>=1; j--)
        {
            double dist = sqrt(pow(pos[i][0] - pos[j][0], 2) + pow(pos[i][1] - pos[j][1], 2));
            pq.push(path(i, j, dist));
        }
    }
    for (int i=0; i<M; i++)
    {
        int p1, p2;
        cin>>p1>>p2;
        if (_find(p1) != _find(p2))
        {
            _union(p1, p2);
            edges++;
        }
    }
    while (edges < N-1) {
        path cur = pq.top();
        pq.pop();
        if (_find(cur.src) == _find(cur.dst))
            continue;
        _union(cur.src, cur.dst);
        edges++;
        ans += cur.dist;
    }
    cout<<fixed;
    cout.precision(2);
    cout<<ans<<endl;
}