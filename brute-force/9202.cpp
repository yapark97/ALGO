//21-03-28 dfs solved

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int longest_idx = -1;
string W[300000];
bool F[300000];
bool V[4][4];
char B[4][4];
int w, b, grade, ans_num;

const int dirr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dirc[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int G[8] = {0, 0, 1, 1, 2, 3, 5, 11};

void found(int wI)
{
    if (F[wI]) return ;
    F[wI] = true;
    if (longest_idx == -1 || W[wI].length() > W[longest_idx].length())
        longest_idx = wI;
    else if (W[wI].length() == W[longest_idx].length() && W[wI] < W[longest_idx])
        longest_idx = wI;
    ans_num++;
    grade += G[W[wI].length()-1];
}

void dfs(int wI, int i, int r, int c)
{
    if (F[wI]) return ;
    if (i == (int)W[wI].length()-1) {
        found(wI);
        return ;
    }
    for (int d=0; d<8; d++) {
        int newr = r+dirr[d], newc = c+dirc[d];
        if (newr>=0 && newc>=0 && newr<4 && newc<4 && B[newr][newc] == W[wI][i+1] && !V[newr][newc]) {
            V[newr][newc] = true;
            dfs(wI, i+1, newr, newc);
            V[newr][newc] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>w;
    for (int i=0; i<w; i++) {
        cin>>W[i];
    }
    cin>>b;
    for (int i=0; i<b; i++) {
        //for each boggle
        memset(F, false, sizeof(F));
        for (int r=0; r<4; r++)
            for (int c=0; c<4; c++)
                cin>>B[r][c];
        grade = 0;
        ans_num = 0;
        longest_idx = -1;
        for (int r=0; r<4; r++)
            for (int c=0; c<4; c++) {
                for (int k=0; k<w; k++) {
                    if (W[k][0] == B[r][c] && !F[k]) {
                        memset(V, false, sizeof(V));
                        V[r][c] = true;
                        dfs(k, 0, r, c);
                    }
                }
            }
        cout<<grade<<" "<<W[longest_idx]<<" "<<ans_num<<endl;
    }
}