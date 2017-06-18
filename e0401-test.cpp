//算法竞赛入门经典第二版 习题4-1 UVa589象棋
//write by xucaima,20161125,13:20
//同一行先输入字符，再输入整数，比较麻烦
//采用cin输入，可以直接跳过空格、换行、制表符，直到遇到非空字符。这样也可以直接跳过空行
//题目明确：保证局面合法且红方已经将军
//所以应该先移动黑将，再进行判断

#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

struct PCS{
    char p;
    int r,c;
};
struct POS{ int r,c;};

//定义一个状态数组，0行0列不使用。单元为0，说明此位置对黑方帅安全
int kill[11][10];
//定义一个棋盘数组，单元格内容为棋子的字母缩写,0行0列不使用
//大写字母为红方，小写字母为黑方。'\0'说明没有棋子
//本例中黑方帅不放在此数组内
char board[11][11];
//红方棋子数组
PCS pieces[8];
//定义黑帅在每个位置可以的走法
//除了在(2,5)有8种走法外，其他8个位置，每个位置都对应有两至三种走法
//统一采用三种走法的表达，减少编程
//两种方法的，增加一种它的自身位置
POS gway[27]={
{2,4},{1,5},{1,4},  {1,4},{1,5},{1,6},  {1,5},{1,6},{2,6},
{1,4},{2,5},{3,4},  {0,0},{0,0},{0,0},  {2,5},{1,6},{3,6},
{2,4},{3,4},{3,5},  {3,4},{2,5},{3,6},  {3,5},{3,6},{2,6}
 };
//定义在(2,5)的4种走法
POS gway25[4]={ {1,5},{2,4},{2,6},{3,5} };

//红方车的杀伤函数，与车同行同列，遇到第二个棋子之前，全部置成1
void Rkill(int r,int c){
	for(int i=c+1;i<=9;i++) //在行内向右找
		if(board[r][i]=='\0')kill[r][i]+=1;
		else break;
	for(int i=c-1;i>=1;i--)//在行内向左找
		if(board[r][i]=='\0')kill[r][i]+=1;
		else break;
	for(int i=r+1;i<=10;i++)//在列内向下找
		if(board[i][c]=='\0')kill[i][c]+=1;
		else break;
	for(int i=r-1;i>=1;i--)//在列内向上找
		if(board[i][c]=='\0')kill[i][c]+=1;
		else break;
}

//红方帅的杀伤函数，与帅同列向上，遇到第二个棋子之前，全部置成1
void Gkill(int r,int c){
	for(int i=r-1;i>=1;i--)//在列内向上找
		if(board[i][c]=='\0')kill[i][c]+=1;
		else break;
}

//红方炮的杀伤函数
void Ckill(int r,int c){
	//找炮架
	bool pj=false;//炮架状态
	int c_pj=c,r_pj=r;//炮架位置,初始设为炮的位置
	for(int i=c+1;i<=9;i++) //在行内向右找
		if(board[r][i]!='\0'){
			c_pj=i;
			r_pj=r;
			break;
		}
	if(c_pj>c){//找到炮架
		for(int i=c_pj+1;i<=9;i++) //从炮架向右找
            if(board[r][i]=='\0')kill[r][i]+=1;
            else break;
	}
	for(int i=c-1;i>=1;i--)//在行内向左找
		if(board[r][i]!='\0'){
			c_pj=i;
			r_pj=r;
			break;
		}
	if(c_pj<c){//找到炮架
        for(int i=c_pj-1;i>=1;i--) //从炮架向左找
            if(board[r][i]=='\0')kill[r][i]+=1;
            else break;
	}
	for(int i=c+1;i<=10;i++)//在列内向下找
		if(board[i][c]!='\0'){
			c_pj=c;
			r_pj=i;
			break;
		}
	if(r_pj>r){//找到炮架
        for(int i=r_pj+1;i<=10;i++)//从炮架向下找
		if(board[i][c]=='\0')kill[i][c]+=1;
		else break;
	}
	for(int i=c-1;i>=1;i--)//在列内向上找
		if(board[i][c]!='\0'){
			c_pj=c;
			r_pj=i;
			break;
		}
	if(r_pj<r){//找到炮架
        for(int i=r_pj-1;i>=1;i--)//从炮架向上找
		if(board[i][c]=='\0')kill[i][c]+=1;
		else break;
	}
}

//红方马的杀伤函数
void Hkill(int r,int c){
    if(board[r-1][c]=='\0' && r>=3 && c>=2 && c<=9){ //马往上走，不别腿
        kill[r-2][c-1]+=1;
         kill[r-2][c+1]+=1;
    }
     if(board[r+1][c]=='\0' && r<=8 && c>=2 && c<=9){ //马往下走，不别腿
        kill[r+2][c-1]+=1;
         kill[r+2][c+1]+=1;
    }
     if(board[r][c-1]=='\0' && r>=2 && r<=9 && c>=3){ //马往左走，不别腿
        kill[r-1][c-2]+=1;
         kill[r+1][c-2]+=1;
    }
    if(board[r][c+1]=='\0' && r>=2 && r<=9 && c<=7){ //马往右走，不别腿
        kill[r-1][c+2]+=1;
         kill[r+1][c+2]+=1;
    }

}

//初始化棋盘和杀伤数组
void init(){
    memset(board,'\0',sizeof(board));
    memset(kill,0,sizeof(kill));
}

//判断黑将与红帅是否直接面对。如果直接面对，则黑将获胜，也即不能被将死
bool gface(int r,int c){
    return true;
}

//判断黑方将是否被将死。r与c是黑将的坐标
//首先要判断黑将的各种可能走法
int judge(int r,int c){
    int life=0;
    if(r==2 && c==5){  //黑帅在(2,5),它可以有8种走法
        for(int i=0;i<4;i++)  //遍历8个位置
            if(kill[gway25[i].r][gway25[i].c]==0) {
                life++;
                printf("move to %d,%d\n",gway25[i].r,gway25[i].c);
            }
    }
    else{
        int n=((r-1)*3+(c-4))*3;//把行列坐标转换为一维数组的相应下标
        for(int i=0;i<3;i++)  //遍历3个可能位置
            if(kill[gway[n+i].r][gway[n+i].c]==0){
                life++;
                printf("move to %d,%d\n",gway[n+i].r,gway[n+i].c);
            }
    }
    return life;
}

//用于打印检查的函数
void myprint(){
    printf("   ");
    for(int j=1;j<=9;j++)
        printf(" %d ",j);
    printf("       ");
    for(int j=1;j<=9;j++)
        printf(" %d ",j);
    printf("\n");
    for(int i=1;i<=10;i++){
        printf("%2d ",i);
        for(int j=1;j<=9;j++)
            if(board[i][j]=='\0')printf(" + ");
            else printf(" %c ",board[i][j]);
        printf("    %2d ",i);
        for(int j=1;j<=9;j++)
            printf(" %d ",kill[i][j]);
        printf("\n");
    }
}


int main(){
    int N,r_bg,c_bg;//定义红方棋子数量及黑帅的位置坐标
    int gamenum=0;
    freopen("e0401.in","r",stdin);
    while(cin>>N>>r_bg>>c_bg  && N!=0){
        //printf("%d %d %d\n",N,r_bg,c_bg);
        gamenum++;
        init();
        for(int i=0;i<N;i++){ //读入红方棋子数据
            cin>>pieces[i].p>>pieces[i].r>>pieces[i].c;
            printf("%c %d %d \n",pieces[i].p,pieces[i].r,pieces[i].c);
            board[pieces[i].r][pieces[i].c]=pieces[i].p;
        }

        bool gface=true;
        for(int i=0;i<N;i++){//根据红方棋子生成看kill数组
            switch(pieces[i].p){
                case'G':
                    if(pieces[i].c==c_bg){  //增加将帅直接碰面的判断
                        for(int j=pieces[i].r-1;j>r_bg;j--)
                            if(board[j][c_bg]!='\0'){ //将和帅中间有棋子
                                gface=false;
                                break;
                            }
                    }
                    else gface=false;

                    Gkill(pieces[i].r,pieces[i].c);
                    break;
                case'R':
                    Rkill(pieces[i].r,pieces[i].c);
                    break;
                case'C':
                    Ckill(pieces[i].r,pieces[i].c);
                    break;
                case'H':
                    Hkill(pieces[i].r,pieces[i].c);
                    break;
            }
        }
        myprint();
        //if(gamenum>1)printf("\n");
        if(judge(r_bg,c_bg)==0 && !gface) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
