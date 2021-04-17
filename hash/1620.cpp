//0405 solved

#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> MAP;
string P[100000];
int N, M;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    cin.ignore();
    for (int i=0; i<N; i++) {
        string s;
        getline(cin, s);
        MAP.insert(make_pair(s, i));
        P[i] = s;
    }
    for (int i=0; i<M; i++) {
        string s;
        getline(cin, s);
        if (s[0]>='1'&&s[0]<='9') {
            int idx = atoi(s.c_str());
            cout<<P[idx-1]<<"\n";
        }
        else 
            cout<<MAP.find(s)->second + 1<<"\n";
    }
}