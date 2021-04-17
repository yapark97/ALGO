//21-04-07 FENCE solved

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int Fence[20000];
vector<pair<int, int>> F;
set<int> V; //visited fence index
int T, N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    for (int t=0; t<T; t++)
    {
        F.clear();
        V.clear();
        cin>>N;
        for (int i=0; i<N; i++)
        {
            cin>>Fence[i];
            F.push_back(make_pair(Fence[i], i));
        }
        sort(F.begin(), F.end());
        int ans = 0;
        V.insert(-1);
        V.insert(N);
        for (int i=0; i<N; i++)
        {
            int h=F[i].first, idx=F[i].second;
            set<int>::iterator right, left, copy;
            right = V.insert(idx).first;
            copy = right;
            if (idx > 1 && Fence[idx-1] == h && Fence[idx-2] == h)
                V.erase(--copy);
            copy = right;
            left = --copy;
            if (idx > 0 && Fence[idx-1] == h)
                left--;
            right++;
            ans = max(ans, (*right - *left - 1) * h);
        }
        cout<<ans<<"\n";
    }
}