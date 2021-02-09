//21-02-09 위상정렬

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int tasks[10001][4] = {0}; //걸리는 시간, 선행작업 개수, 선행관계가 언제 끝나는지, 해당작업이 언제 끝나는지
vector<int> nextTasks[10001]; //다음에 오는..
int N;

int main()
{
    cin>>N;
    for (int i=1; i<=N; i++)
    {
        cin>>tasks[i][0]>>tasks[i][1];
        tasks[i][2] = tasks[i][3] = -1;
        for (int j=0; j<tasks[i][1]; j++)
        {
            int preTask;
            cin>>preTask;
            nextTasks[preTask].push_back(i);
        }
    }

    queue<int> q;
    for (int i=1; i<=N; i++)
        if (!tasks[i][1]) {
            q.push(i);
            tasks[i][3] = tasks[i][0];
        }
    int finished = 0, finishTime = 0;
    
    while (finished < N)
    {
        int curTask = q.front();
        q.pop();
        finishTime = max(finishTime, tasks[curTask][3]);
        finished++;
        
        for (unsigned i=0; i<nextTasks[curTask].size(); i++)
        {
            int nextTask = nextTasks[curTask][i];
            tasks[nextTask][1]--;
            tasks[nextTask][2] = max(tasks[nextTask][2], tasks[curTask][3]);
            if (!tasks[nextTask][1]) {
                q.push(nextTask);
                tasks[nextTask][3] = tasks[nextTask][0] + tasks[nextTask][2];
            }
        }
    }
    cout<<finishTime<<endl;
}