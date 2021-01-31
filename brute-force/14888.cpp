//21-01-31 brute-force success

#include <iostream>

using namespace std;

int N;
int A[11];
int OP[4]; //덧셈, 뺄셈, 곱셈, 나눗셈 개수
int _max, _min;
bool found = false;

void cal(int *Aop)
{
    int res = A[0];
    for (int i=0; i<N-1; i++)
    {
        if (Aop[i] == 0)
            res += A[i+1];
        else if (Aop[i] == 1)
            res -= A[i+1];
        else if (Aop[i] == 2)
            res *= A[i+1];
        else if (Aop[i] == 3)
            res /= A[i+1];
    }
    if (!found) {
        _max = res;
        _min = res;
        found = true;
    }
    else {
        _max = max(res, _max);
        _min = min(res, _min);
    }
}

void bf(int op, int count, int idx, int *Aop)
{
    if (op == 3 && count == OP[3]) {
        cal(Aop);
        return ;
    }
    else if (count == OP[op]) {
        bf(op+1, 0, -1, Aop);
        return ;
    }
    while (++idx < N-1)
    {
        if (Aop[idx] == -1) {
            Aop[idx] = op;
            bf(op, count+1, idx, Aop);
            Aop[idx] = -1;
        }
    }
}

int main()
{
    cin>>N;
    for (int i=0; i<N; i++)
        cin>>A[i];
    for (int i=0; i<4; i++)
        cin>>OP[i];
    int Aop[N-1];
    for (int i=0; i<N-1; i++)
        Aop[i] = -1;
    bf(0, 0, -1, Aop); //덧셈을 0개까지 넣었음. 이전에 넣은 덧셈은 -1인덱스에.
    cout<<_max<<endl<<_min<<endl;
}