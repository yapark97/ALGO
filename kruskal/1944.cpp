//21-02-05 kruskal success

#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string.h>


using namespace std;
int N, M;
char map[50][50];
int key[251][2];
const int dirx[4] = {-1, 0, 1, 0};
const int diry[4] = {0, 1, 0, -1};
int parent[251];

struct path
{
    path(int _k1, int _k2, int _dist) {
        k1 = _k1; k2=_k2; dist=_dist;
    }
    int k1;
    int k2;
    int dist;
};

bool compare(path &p1, path &p2) {
    return p1.dist < p2.dist;
}

vector<path> v;

void bfs(int x, int y, int value, int dist[50][50])
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    dist[x][y] = 0;
    while (!q.empty()) {
        int curx = q.front().first, cury = q.front().second;
        q.pop();
        for (int dir = 0; dir<4; dir++) {
            int newx = curx + dirx[dir], newy = cury + diry[dir];
            if (newx < 0 || newy < 0 || newx >= N || newy >= N || map[newx][newy] == '1' || dist[newx][newy] != -1)
                continue ;
            q.push(make_pair(newx, newy));
            dist[newx][newy] = dist[curx][cury] + 1;
        }
    }
}

int _find(int k)
{
    if (parent[k]<0) return k;
    int root = _find(parent[k]);
    parent[k] = root;
    return root;
}

void _union(int k1, int k2)
{
    k1 = _find(k1);
    k2 = _find(k2);
    if (k1 == k2) return ;
    k1[parent] = k2;
}

int main()
{
    memset(parent, -1, sizeof(parent));
    cin>>N>>M;
    int keyCount=1;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++) {
            cin>>map[i][j];
            if (map[i][j] == 'S') {
                key[0][0] = i;
                key[0][1] = j;
            }
            else if (map[i][j] == 'K') {
                key[keyCount][0] = i;
                key[keyCount][1] = j;
                keyCount++;
            }
        }
    for (int i=0; i<=M; i++) {
        int dist[50][50];
        memset(dist, -1, sizeof(dist));
        bfs(key[i][0], key[i][1], 0, dist);
        for (int j=i-1; j>=0; j--) {
            v.push_back(path(i, j, dist[key[j][0]][key[j][1]]));
            if (dist[key[j][0]][key[j][1]] < 0) {
                cout<<"-1"<<endl;
                return 0;
            }
        }
    }
    sort(v.begin(), v.end(), compare);
    int i=0;
    int E=0, ans = 0, len = v.size();
    while (E<M && i<len) {
        int k1 = v[i].k1, k2 = v[i].k2, dist = v[i].dist;
        if (_find(k1) == _find(k2)) { i++; continue ; }
        _union(k1, k2);
        E++;
        i++;
        ans+=dist;
    }
    if (E == M)
        cout<<ans<<endl;
    else
        cout<<"-1"<<endl;
}