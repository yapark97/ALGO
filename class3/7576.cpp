#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int M, N, ANS=1;
int T[1001][1001] = {0};
int dirx[4] = {-1, 0, 1, 0};
int diry[4] = {0, 1, 0, -1};
priority_queue<pair<int, int>> PQ;

bool all_riped()
{
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            if (T[i][j] == 0)
                return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>M>>N;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++) {
            cin>>T[i][j];
            if (T[i][j] == 1) PQ.push(make_pair(0, i*M+j));
        }
    while (!PQ.empty()) {
        int pos=PQ.top().second;
        ANS=-PQ.top().first;
        PQ.pop();
        for (int d=0; d<4; d++) {
            int newx=pos/M+dirx[d], newy = pos%M+diry[d];
            if (newx>=0 && newx<N && newy>=0 && newy<M && T[newx][newy] == 0) {
                T[newx][newy] = 1;
                PQ.push(make_pair(-ANS-1, newx*M+newy));
            }
        }
    }
    if (!all_riped()) cout<<"-1\n";
    else cout<<ANS<<"\n";
}