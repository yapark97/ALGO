//21-01-26 union find solved

#include <iostream>

using namespace std;

int N;
int R[1000][4];
int parents[1000];

bool crossed(int r1, int r2)
{
    if ((R[r1][0] > R[r2][0] && R[r1][2] < R[r2][2] && R[r1][1] > R[r2][1] && R[r1][3] < R[r2][3]) || \
        (R[r1][0] < R[r2][0] && R[r1][2] > R[r2][2] && R[r1][1] < R[r2][1] && R[r1][3] > R[r2][3])) {
        return false;
        }
    if (max(R[r1][0], R[r2][0]) > min(R[r1][2], R[r2][2]))
        return false;
    if (max(R[r1][1], R[r2][1]) > min(R[r1][3], R[r2][3]))
        return false;
    return true;
}

int _find(int r)
{
    if (parents[r] < 0)
        return r;
    int root = _find(parents[r]);
    parents[r] = root;
    return root;
}

void _union(int x1, int x2)
{
    int r1 = _find(x1);
    int r2 = _find(x2);
    if (r1 == r2)
        return;
    if (parents[r1] < parents[r2])
    {
        int temp = r1;
        r1 = r2;
        r2 = temp;
    }
    parents[r2] += parents[r1];
    parents[r1] = r2;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        parents[i] = -1; //초기값
        cin >> R[i][0] >> R[i][1] >> R[i][2] >> R[i][3];
        for (int j = i - 1; j >= 0; j--)
        {
            if (_find(i) == _find(j)) continue ;
            if (crossed(i, j)) {
                _union(i, j);
            }
        }
    }
    int count = 0;
    //0, 0에 직사각형을 그려야 하는지? 그려야 하면 count = -1
    for (int i = 0; i < N; i++) {
        if ((R[i][0] == 0 || R[i][2] == 0) && R[i][3] >= 0 && R[i][1] <= 0) {
            count--;
            break;
        }
        if ((R[i][1] == 0 || R[i][3] == 0) && R[i][2] >= 0 && R[i][0] <= 0) {
            count--;
            break;
        }
    }
    for (int i = 0; i < N; i++)
        if (parents[i] < 0)
            count++;
    cout << count <<endl;
}