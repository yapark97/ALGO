#include <iostream>
#include <queue>

using namespace std;

int M, N, ANS=0;
priority_queue<int> pq;

int main()
{
    pq.push(1);
    pq.push(1);
    pq.pop();
    if (pq.empty()) {
        cout<<"here\n";
    }
    else {
        pq.pop();
        cout<<"there\n";
    }
}