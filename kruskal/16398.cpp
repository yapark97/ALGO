//21-02-05 kruskal solved

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct path {
    path(int s, int d, int c) {
        src = s; dst = d; cost = c;
    }
    int src;
    int dst;
    long cost;
};

bool compare(path &p1, path &p2) {
        return p1.cost < p2.cost;
}

int parent[1001] = {0};
int N;
int E = 0;
long ans = 0;

vector<path> v;

int _find(int a)
{
    if (!parent[a]) return a;
    int root = _find(parent[a]);
    parent[a] = root;
    return root;
}

void _union(int a, int b)
{
    a = _find(a);
    b = _find(b);
    if (a != b) parent[a] = b;
}

int main()
{
    cin>>N;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++) {
            int cost;
            cin>>cost;
            if (i<j) 
                v.push_back(path(i, j, cost));
        }
    sort(v.begin(), v.end(), compare);
    int i = 0;
    while (E<N-1) {
        int a = v[i].src, b = v[i].dst, cost=v[i].cost;
        if (_find(a) == _find(b)) {i++; continue ;}
        ans += cost;
        _union(a, b);
        E++;
        i++;
    }
    cout<<ans<<endl;
}