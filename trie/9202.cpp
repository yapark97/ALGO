//21-02-02 failed

#include <iostream>
#include <string>

using namespace std;

struct Trie
{
    int wIdx = -1;
    Trie *next[26] = {0};
};

//인접 문자 체크
const int dirx[8] = {-1, -1, -1, 0, 1, 1, 1, 0}; //왼쪽위부터 시계방향
const int diry[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

string words[300000];
char board[4][4];
Trie *trie;
int W, B;
int maxGrade, longestWord;

void foundWord(int wIdx, int *found)
{
    found[wIdx] = true;
    unsigned int len = words[wIdx].length();
    if (longestWord == -1 || words[longestWord].length() < len ||
        (words[longestWord].length() == len && words[longestWord] > words[wIdx]))
        longestWord = wIdx;
    if (len == 3 || len == 4)
        maxGrade += 1;
    if (len == 5)
        maxGrade += 2;
    if (len == 6)
        maxGrade += 3;
    if (len == 7)
        maxGrade += 5;
    if (len == 8)
        maxGrade += 11;
}

void bf(int x, int y, Trie *cur, int *found, bool visited[4][4])
{
    visited[x][y] = true;
    if (cur->wIdx != -1 && !found[cur->wIdx])
        foundWord(cur->wIdx, found);
    else if (cur->wIdx != -1)
        return ;
    for (int dir = 0; dir < 8; dir++)
    {
        int newx = x + dirx[dir];
        int newy = y + diry[dir];
        if (newx < 0 || newy < 0 || newx > 3 || newy > 3)
            continue;
        if (cur->next[board[newx][newy] - 'A'] && !visited[newx][newy])
        {
            bf(newx, newy, cur->next[board[newx][newy] - 'A'], found, visited);
            visited[newx][newy] = false;
        }
    }
}

void start(int x, int y, int *found)
{
    if (trie->next[board[x][y] - 'A'])
    {
        bool visited[4][4];
        for (int i=0; i<4; i++)
            for (int j=0; j<4; j++)
                visited[i][j] = false;
        bf(x, y, trie->next[board[x][y] - 'A'], found, visited);
    }
}

void addWord(string s, int idx)
{
    int i = -1;
    Trie *cur = trie;
    while (s[++i])
    {
        if (!cur->next[s[i] - 'A'])
            cur->next[s[i] - 'A'] = new Trie();
        cur = cur->next[s[i] - 'A'];
    }
    cur->wIdx = idx;
}

int main()
{
    //cin.tie(NULL);
    //ios::sync_with_stdio(false);
    trie = new Trie();
    cin >> W;
    for (int i = 0; i < W; i++)
    {
        cin >> words[i];
        addWord(words[i], i);
    }
    cin >> B;
    for (int i = 0; i < B; i++)
    {
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                cin >> board[j][k];
        int num = 0;
        maxGrade = 0;
        longestWord = -1;
        int *found = new int[W];
        for (int i = 0; i < W; i++)
            found[i] = false;
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                start(j, k, found);
        for (int i = 0; i < W; i++)
            if (found[i])
                num++;
        cout << maxGrade << " " << words[longestWord] << " " << num << endl;
        delete[] found;
    }
}