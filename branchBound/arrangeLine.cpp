#include <iostream>
#include <queue>
using namespace std;

typedef struct Position
{
    int x;
    int y;
}Position;

int m,n;        //m表示行数，n表示列数
int grid[102][102];     //表示电路板
Position ans[100];

bool findPath(Position first, Position finish, int &pathLen){
    if(first.x == finish.x && first.y == finish.y){     //如果起始位置和结束位置相同，则路径长为0
        pathLen = 0;
        return true;
    }
    for(int i =0;i<=m+1;i++){           //初始化
        grid[0][i] = grid[n+1][i] = -1;
    }
    for(int i=0;i<=n+1;i++){
        grid[i][0] = grid[i][m+1] = -1;
    }

    Position offset[4];     //四个方向的偏移量
    offset[0].x = 0;        //上
    offset[0].y = 1;
    offset[1].x = 1;        //右
    offset[1].y = 0;
    offset[2].x = 0;        //下
    offset[2].y = -1;
    offset[3].x = -1;        //左
    offset[3].y = 0;

    int numsOfNbrs = 4;     //总共有四个方向
    Position now, nerb;     //now是当前结点，nerb是相邻结点
    now = first;
    grid[first.x][first.y] = 0;
    queue <Position> q;

    while(1){
        for(int i=0;i<numsOfNbrs;i++){
            nerb.x = now.x + offset[i].x;
            nerb.y = now.y + offset[i].y;
            if(grid[now.x][now.y] + 1 < grid[nerb.x][nerb.y]){
                grid[nerb.x][nerb.y] = grid[now.x][now.y] + 1;
                if(nerb.x == finish.x && nerb.y == finish.y){
                    pathLen = grid[finish.x][finish.y];
                    break;
                }
                q.push(nerb);
            }
        }
        if(nerb.x == finish.x && nerb.y == finish.y){
            break;
        }
        if(q.empty()){return false;}        //没有找到一条通路
        now = q.front();
        q.pop();
    }
    return true;
}

void findAns(Position start, Position finish, int pathLen){
    Position offset[4];     //四个方向的偏移量
    offset[0].x = 0;        //上
    offset[0].y = 1;
    offset[1].x = 1;        //右
    offset[1].y = 0;
    offset[2].x = 0;        //下
    offset[2].y = -1;
    offset[3].x = -1;        //左
    offset[3].y = 0;

    Position now, nerb;
    now = finish;
    ans[pathLen--] = finish;
    while(pathLen > 0){
        for(int i=0;i<4;i++){
            nerb.x = now.x + offset[i].x;
            nerb.y = now.y + offset[i].y;
            if(grid[nerb.x][nerb.y] == pathLen){
                Position temp;
                temp.x = nerb.x;
                temp.y = nerb.y;
                ans[pathLen--] = temp;
                now = temp;     //注意这里要更新
                break;
            }
        }
    }
    Position temp;
    temp.x = start.x;
    temp.y = start.y;
    ans[0] = temp;
}

int main(){
    int m,n;
    Position a,b;
    int num;
    cout << "请输入行数和列数："<<endl;
    cin >> m >> n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            grid[i][j] = 10000;
        }
    }
    cout << "请输入起始坐标x y："<<endl;
    cin >> a.x >> a.y;
    cout << "请输入结束坐标x y" << endl;
    cin >> b.x >> b.y;
    cout << "请输入有障碍物的数量：" << endl;
    cin >> num;
    for(int i=0;i<num;i++){
        cout << "请输入第" << i+1 << "个障碍物的坐标x y：" << endl;
        int x,y;
        cin >> x >> y;
        grid[x][y] = -1;
    }
    int len = 0;
    findPath(a,b,len);
    cout << "路径长度为：" << len << endl;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    findAns(a,b,len);
    for(int i=0;i<=len;i++){
        cout << "(" << ans[i].x << "," << ans[i].y << ")" << endl;
    }

    system("pause");
    return 0;
}

/*
7 7
3 2
4 6
11
5 1
6 1
6 2
6 3
1 3
2 3
2 4
3 5
4 4
4 5
5 5
*/