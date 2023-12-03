#include <iostream>
using namespace std;

int n;      //棋盘大小
int tile;   //骨牌编号
int board[100][100];

void chessBoard(int tr, int tc, int dr, int dc ,int size){
    if(size == 1){return;}
    int t = tile++;
    int s = size/2;
    //覆盖左上角
    if(dr < s + tr && dc < s + tc){
        chessBoard(tr,tc,dr,dc,s);
    }else{
        board[tr+s-1][tc+s-1] = t;
        chessBoard(tr,tc,tr+s-1,tc+s-1,s);
    }
    //覆盖右上角
    if(dr < s + tr && dc >= s + tc){
        chessBoard(tr,tc+s,dr,dc,s);
    }else{
        board[tr+s-1][tc+s] = t;
        chessBoard(tr,tc+s,tr+s-1,tc+s,s);
    }
    //覆盖左下角
    if(dr >= s + tr && dc < s + tc){
        chessBoard(tr+s,tc,dr,dc,s);
    }else{
        board[tr+s][tc+s-1] = t;
        chessBoard(tr+s,tc,tr+s,tc+s-1,s);
    }
    //覆盖右下角
    if(dr >= s + tr && dc >= s+ tc){
        chessBoard(tr+s,tc+s,dr,dc,s);
    }else{
        board[tr+s][tc+s] = t;
        chessBoard(tr+s,tc+s,tr+s,tc+s,s);
    }
}

int main(){
    cout << "请输入棋盘的大小（偶数）：" << endl;
    cin >> n;
    tile = 1;
    cout << "请输入特殊点的坐标：" << endl;
    int x,y;
    cin >> x >>y;
    chessBoard(1,1,x,y,n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    system("pause");
    return 0;
}