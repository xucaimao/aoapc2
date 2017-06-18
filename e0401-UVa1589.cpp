#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

struct POS{ int r,c;};
int kill[11][10];

char board[11][10];
char boardswap[11][10];//定义一个零时棋盘，在上面进行可能的吃子操作

POS gway[36]={
{2,4},{1,5},{0,0},{0,0},   {1,4},{2,5},{1,6},{0,0},   {1,5},{2,6},{0,0},{0,0},  //对应(1,4)...(1,6)
{1,4},{2,5},{3,4},{0,0},   {1,5},{2,4},{2,6},{3,5},   {2,5},{1,6},{3,6},{0,0},  //对应(2,4)...(2,6)
{2,4},{3,5},{0,0},{0,0},   {3,4},{2,5},{3,6},{0,0},   {3,5},{2,6},{0,0},{0,0}   //对应(3,4)...(3,6)
 };
int r_bg,c_bg,r_bg_new,c_bg_new;//定义黑将的原始位置，及可能走到的新位置

void Rkill(char bd[11][10],int r,int c){
	for(int i=c+1;i<=9;i++) //在行内向右找,直至遇到第一个棋子
		{kill[r][i]+=1;if(bd[r][i]!='\0')break;}
	for(int i=c-1;i>=1;i--)//在行内向左找
		{kill[r][i]+=1;if(bd[r][i]!='\0')break;}
	for(int i=r+1;i<=10;i++)//在列内向下找
        {kill[i][c]+=1;if(bd[i][c]!='\0')break;}
	for(int i=r-1;i>=1;i--)//在列内向上找
        {kill[i][c]+=1;if(bd[i][c]!='\0')break;}
}

void Gkill(char bd[11][10],int r,int c){
    for(int i=r-1;i>=1;i--)//在列内向上找,直至遇到第一个棋子
        {kill[i][c]+=1;if(bd[i][c]!='\0')break;}
}

void Ckill(char bd[11][10],int r,int c){
	bool pj;//炮架状态
	int c_pj=c,r_pj=r;//炮架位置,初始设为炮的位置
	int dir_c=1,dir_r=1;//定义查找的方向，初始往右
    if(r==r_bg_new){  //炮与黑将同行
        if(c>c_bg_new) //炮在将右侧,往左计算
            dir_c=-1;
        pj=false;//炮架状态
        for(int i=c+dir_c;i<=9 && i>=1;i+=dir_c) //在行内向查找炮架
            if(bd[r][i]!='\0'){
                c_pj=i;
                r_pj=r;
                pj=true;
                break;    //找到炮架，记录位置并跳出
            }
        if(pj)
            for(int i=c_pj+dir_c;i<=9 && i>=1;i+=dir_c)
                {kill[r][i]+=1;if(bd[r][i]!='\0') break;}
    }
    if(c==c_bg_new){  //炮与黑将同列
        if(r>r_bg_new) //炮在将下方,往上计算
            dir_r=-1;
        pj=false;//炮架状态
        for(int i=r+dir_r;i<=10 && i>=1;i+=dir_r) //在行内向查找炮架
            if(bd[i][c]!='\0'){
                c_pj=i;
                r_pj=r;
                pj=true;
                break;    //找到炮架，记录位置并跳出
            }
        if(pj)
            for(int i=c_pj+dir_r;i<=9 && i>=1;i+=dir_r)
                {kill[i][c]+=1;if(bd[i][c]!='\0') break;}
    }

}

void Hkill(char bd[11][10],int r,int c){
    if(bd[r-1][c]=='\0' && r>=3 && c>=2 && c<=9){ //马往上走，不别腿
        kill[r-2][c-1]+=1;
         kill[r-2][c+1]+=1;
    }
     if(bd[r+1][c]=='\0' && r<=8 && c>=2 && c<=9){ //马往下走，不别腿
        kill[r+2][c-1]+=1;
         kill[r+2][c+1]+=1;
    }
     if(bd[r][c-1]=='\0' && r>=2 && r<=9 && c>=3){ //马往左走，不别腿
        kill[r-1][c-2]+=1;
         kill[r+1][c-2]+=1;
    }
    if(bd[r][c+1]=='\0' && r>=2 && r<=9 && c<=7){ //马往右走，不别腿
        kill[r-1][c+2]+=1;
         kill[r+1][c+2]+=1;
    }

}

//对于黑将移动位置后的新棋盘，生成杀伤数组
void initkill(char bd[11][10]){
    memset(kill,0,sizeof(kill));//初始化
    for(int r=1;r<=10;r++)
        for(int c=1;c<=9;c++){
            switch(bd[r][c]){
                case'G':
                    Gkill(bd,r,c);
                    break;
                case'R':
                    Rkill(bd,r,c);
                    break;
                case'C':
                    Ckill(bd,r,c);
                    break;
                case'H':
                    Hkill(bd,r,c);
                    break;
            }
        }
}

int movejudge(){
    int life=0;
    int n=((r_bg-1)*3+(c_bg-4))*4;
    for(int i=0;i<4;i++){   //遍历4个可能位置
        memcpy(boardswap,board,sizeof(board));//拷贝一个棋盘
        r_bg_new=gway[n+i].r;  //黑将移动到的新位置
        c_bg_new=gway[n+i].c;
        if(r_bg_new==0) break;  //遇到(0,0)提前结束循环
        boardswap[r_bg][c_bg]='\0';
        boardswap[r_bg_new][c_bg_new]='g';  //移动黑将修改棋盘
        initkill(boardswap);
        if(kill[r_bg_new][c_bg_new]==0){
            life++;
        }
    }
    return life;
}

int main(){
    int N;//定义红方棋子数量及黑帅的位置坐标
	int gamenum=0;
    freopen("e0401.in","r",stdin);
    while(cin>>N>>r_bg>>c_bg  && N!=0){
		gamenum++;
        memset(board,'\0',sizeof(board));//初始化棋盘
        board[r_bg][c_bg]='g';//保存黑将
        for(int i=0;i<N;i++){ //读入红方棋子数据
            int r,c;
            char p;
            cin>>p>>r>>c;

            board[r][c]=p;
        }

		if(gamenum>1) printf("\n");
        if(movejudge()==0) printf("YES");
        else printf("NO");
    }
    return 0;
}
