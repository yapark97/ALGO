//21-01-31 implementation solved

#include <iostream>

using namespace std;

int N, K;
int step = 1;
int A[201], R[201] = {0};
int up, down;

int prev(int idx)
{
    return (idx == 1 ? 2*N : idx -1);
}

int next(int idx)
{
    return (idx == 2*N ? 1 : idx+1);
}

void rotate()
{
    up = prev(up);
    down = prev(down);
    if (R[down]) R[down] = 0;
}

void addRobot()
{
    if (!R[up] && A[up]) {
        R[up] = 1;
        A[up]--;
    }
}

void move()
{
    if (R[down]) R[down] = 0; //내려가는 위치에 로봇이 있을때
    int next = down, cur = prev(down);
    while (next != up)
    {
        //cur이 down-1 ~ up 까지 반복
        if (!R[next] && A[next] && R[cur]) {
            R[cur] = 0;
            R[next] = 1;
            A[next]--;
        }
        next = cur;
        cur = prev(cur);
    }
    if (R[down]) R[down] = 0;
}

bool check()
{
    int isZero = 0;
    for (int i=1; i<=2*N; i++)
        if (!A[i]) isZero++;
    return (isZero >= K);
}

int main()
{
    cin>>N>>K;
    for (int i=1; i<=2*N; i++)
        cin>>A[i];
    up = 1;
    down = N;
    while (true)
    {
        rotate(); //벨트가 한칸 회전
        move(); //로봇이 이동
        addRobot(); //로봇 올리기
        if (check())
            break ;
        step++;
    }
    cout<<step<<endl;
}