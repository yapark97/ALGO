//21-02-09 위상정렬 solved

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

list<int> L[1001];
int order[1001] = {0};

int main()
{
    cin>>N>>M;
    for (int i=0; i<M; i++)
    {
        int lec1, lec2;
        cin>>lec1>>lec2;
        L[lec2].push_back(lec1);
    }
    int sem = 1;
    int sum = 0;
    vector<int> temp;
    while (sum < N)
    {
        for (int i=1; i<=N; i++)
        {
            if (!L[i].empty() || order[i]) continue;
            order[i] = sem;
            sum++;
            temp.push_back(i);
        }
        while (!temp.empty()) {
            int i = temp.back();
            temp.pop_back();
            for (int j=i+1; j<=N; j++)
            {
                list<int>::iterator iter = find(L[j].begin(), L[j].end(), i);
                if (iter != L[j].end()) L[j].erase(iter);
            }
        }
        sem++;
    }
    for (int i=1; i<=N; i++)
        cout<<order[i]<<" ";
    cout<<endl;
}