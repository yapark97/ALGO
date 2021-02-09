//21-01-26 implementation solved

#include <iostream>
#define G 0
#define B 1

using namespace std;

int N;
int blocks[10001][3];
int board[2][6][4] = {0};
int grade = 0;

void setBlock(int idx, int type)
{
    int x = blocks[idx][1], y = blocks[idx][2];
    if (type == G) {
        board[type][0][y] = idx;
        if (blocks[idx][0] == 2) board[type][0][y+1] = idx;
        if (blocks[idx][0] == 3) board[type][1][y] = idx;
    }
    else {
        board[type][0][x] = idx;
        if (blocks[idx][0] == 2) board[type][1][x] = idx;
        if (blocks[idx][0] == 3) board[type][0][x+1] = idx;
    }
}

void moveRow(int empty, int type)
{
    for (int x = empty-1; x>=-1; x--)
        for (int y=0; y<4; y++)
            board[type][x+1][y] = x == -1 ? 0 : board[type][x][y];
}

void moveBlock(int i, int type) {
    bool moved = false;
    for (int x=0; x<5; x++) {
        for (int y=0; y<4; y++) {
            if (board[type][x][y] != i) continue ;
            if (!(y < 3 && board[type][x][y+1] == i) && \
                !(y > 0 && board[type][x][y-1] == i) && \
                !(x > 0 && board[type][x-1][y] ==i) && \
                !(x < 4 && board[type][x+1][y] ==i) && \
                board[type][x+1][y] == 0) {//(1, 1)이동 왼쪽이랑 위도 체크해야?
                board[type][x][y] = 0;
                board[type][x+1][y] = i;
                moved = true;
                break;
            }
            if ((y < 3 && board[type][x][y+1] == i) && \
                board[type][x+1][y] == 0 && \
                board[type][x+1][y+1] == 0) {
                board[type][x][y] = 0;
                board[type][x][y+1] = 0;
                board[type][x+1][y] = i;
                board[type][x+1][y+1] = i;
                moved = true;
                break ;
            }
            if (x < 4 && board[type][x+1][y] == i && \
                board[type][x+2][y] == 0) {
                board[type][x][y] = 0;
                board[type][x+2][y] = i;
                moved = true;
                break ;
            }
        }
        if (moved) break;
    }
    if (moved) moveBlock(i, type);
}

void getGrade(int idx, int type)
{
    for (int x=5; x>=0; x--) {
        bool isFull = true;
        for (int y=0; y<4; y++)
            if (!board[type][x][y])
                isFull = false;
        if (isFull) {
            grade++;
            for (int y=0; y<4; y++)
                board[type][x][y] = 0;
            moveRow(x, type);
            getGrade(idx, type);
        }
    }
}

void specialBlock(int idx, int type)
{
    bool hasBlock1 = false, hasBlock2 = false;
    for (int y=0; y<4; y++) {
        if (board[type][1][y])
            hasBlock1 = true;
        if (board[type][0][y])
            hasBlock2 = true;
    }
    if (hasBlock1) moveRow(5, type);
    if (hasBlock2) moveRow(5, type);
}

int count()
{
    int ret = 0;
    for (int type = 0; type<2; type++)
        for (int x=0; x<6; x++)
            for (int y=0; y<4; y++)
                if (board[type][x][y]) ret++;
    return ret;
}

int main()
{
    cin>>N;
    for (int i=1; i<=N; i++) {
        cin>>blocks[i][0]>>blocks[i][1]>>blocks[i][2];
        setBlock(i, B); setBlock(i, G);
        moveBlock(i, B); moveBlock(i, G);
        getGrade(i, B); getGrade(i, G);
        specialBlock(i, B); specialBlock(i, G);
        getGrade(i, B); getGrade(i, G);
    }
    cout<<grade<<endl;
    cout<<count()<<endl;
}