//21-04-07 FENCE solved

#include <iostream>

using namespace std;

int T, N;
int Fence[20000];

int find_ans(int first, int last)
{
    if (last - first <= 1)
        return Fence[first];
    int mid = (first + last) / 2;
    int ans = max(find_ans(first, mid), find_ans(mid, last));
    int left = mid-1, right = mid, height = min(Fence[left], Fence[right]);
    ans = max(ans, height*2);
    while (left > first || right < last-1)
    {
        if (left > first && (right >= last-1 || Fence[left-1] >= Fence[right+1])) {
            left--;
            height = min(height, Fence[left]);
        }
        else {
            right++;
            height = min(height, Fence[right]);
        }
        ans = max(ans, height * (right - left + 1));
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    for (int t=0; t<T; t++)
    {
        cin>>N;
        for (int i=0; i<N; i++)
            cin>>Fence[i];
        int ans = find_ans(0, N);
        cout<<ans<<"\n";
    }
}