//21-04-13 NUMB3RS solved

#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

int T, N, D, P;
vector<int> Village[50];
double DP[50][100];

double dp(int v, int d)
{
    if (DP[v][d] >= 0) return DP[v][d];
    double ret = 0;
    for (unsigned int i=0; i<Village[v].size(); i++)
    {
        double p = dp(Village[v][i], d-1);
        ret += p / Village[Village[v][i]].size();
    }
    DP[v][d] = ret;
    return DP[v][d];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    for (int t=0; t<T; t++)
    {
        cin>>N>>D>>P;
        for (int i=0; i<N; i++)
            Village[i].clear();
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++) {
                int temp;
                cin>>temp;
                if (temp) {
                    Village[i].push_back(j);
                    Village[j].push_back(i);
                }
            }
        int num;
        cin>>num;
        memset(DP, -1, sizeof(DP));
        for (int i=0; i<N; i++)
            DP[i][0] = 0;
        DP[P][0] = 1;
        for (int i=0; i<num; i++) {
            int q;
            cin>>q;
            cout<<fixed<<setprecision(8)<<dp(q, D)<<" ";
        }
        cout<<"\n";
    }
}