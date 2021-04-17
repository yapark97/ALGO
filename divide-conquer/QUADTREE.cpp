//21-04-06 QUADTREE solved

#include <iostream>
#include <string>

using namespace std;

int T;

string reverseTree(string ot)
{
    if (ot[0] != 'x') return ot;

    string st[4]; //subtrees
    int i=1;
    for (int stidx=0; stidx<4; stidx++)
    {
        int start = i, stack = 0;
        if (ot[i] == 'x')
            stack += 4;
        i++;
        while (stack) {
            if (ot[i] == 'x')
                stack += 3;
            else
                stack--;
            i++;
        }
        st[stidx] = reverseTree(ot.substr(start, i-start));
    }
    return "x"+st[2]+st[3]+st[0]+st[1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    cin.ignore();
    for (int t=0; t<T; t++)
    {
        string ot;
        getline(cin, ot);
        cout<<reverseTree(ot)<<"\n";
    }
}