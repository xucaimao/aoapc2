//算法竞赛入门经典第二版 例题6-14 UVa816 Abbott的复仇
//write by xucaimao,20170204-22:30开始编程，20170207-20:30测试通过
//多维数组表示的静态图。对多维数组的理解是我最大的障碍
//其实，此程序只是把多维数组的多个下标当成多个状态量，便于访问检索，在空间上很浪费，以空间换效率。
//本程序采用BFS算法

#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

struct NODE{
	int r,c,dir;//位于(r,c)朝向dir(0~3分别代N、E、S、W四个方向)
	NODE(int r=0,int c=0,int dir=0):r(r),c(c),dir(dir){}//构造函数
};

const int maxn=10;//最多9个节点
const char* dirs="NESW";//四个方向按顺时针排列
const char* turns="FLR";//三种允许的运动方式
const int dr[]={-1,0,1,0};//向北:r-1,c+0;向东:r+0,c+1
const int dc[]={0,1,0,-1};//向南:r+1,c+0;向西:r+0,c-1

int r0,c0,dir;//入口坐标与方向
int r1,c1,r2,c2;//实际出发点与结束点
int dist[maxn][maxn][4];//表示初始状态到(r,c,dir)的最短路径的长度
NODE pre[maxn][maxn][4];//用于记录(r,c,dir)的父节点
int has_edge[maxn][maxn][4][3];//表示当前状态(r,c,dir)是否可以沿着转弯方向turn行走


int dir_id(char c){return strchr(dirs,c)-dirs;}//把四种方向由字符转变为数字0~3
int turn_id(char c){return strchr(turns,c)-turns;}//把三种运动由字符转变为数字0~2

NODE walk(const NODE& u,int turn){
	int dir=u.dir;
	if(turn==1) dir=(dir+3)%4;//L转向
	if(turn==2) dir=(dir+1)%4;//R转向
	return NODE(u.r+dr[dir],u.c+dc[dir],dir);//行走
}

//读取r0,c0,dir,计算出r1,c1;然后读取各节点数据存入has_edge数组
bool readcase(){
	char s[25],s2[25];
	if(scanf("%s%d%d%s%d%d",s,&r0,&c0,s2,&r2,&c2)!=6)return false;
	printf("%s\n",s);//打印迷宫名称
	dir=dir_id(s2[0]);//
	r1=r0+dr[dir];//计算实际出发位置坐标
	c1=c0+dc[dir];
	
	memset(has_edge,0,sizeof(has_edge));//
	for(;;){//读入各节点路标数据
		int r,c;
		scanf("%d",&r);
		if(r==0)break;//数据结束标志
		scanf("%d",&c);
		while(scanf("%s",s)==1 && s[0]!='*'){
			for(int i=1;i<strlen(s);i++)
				has_edge[r][c][dir_id(s[0])][turn_id(s[i])]=1;
		}
	}
	return true;
}

//判断是否越界，感觉此判断多余，后面要测试一下
bool inside(int r,int c){
	return r>=1 && r<=9 && c>=1 && c<=9;
}

//从终点逆序追溯到起点
void print_ans(NODE u){
	vector<NODE> p;
	for(;;){
		p.push_back(u);
		if(dist[u.r][u.c][u.dir]==0)break;//节点u与实际起点的距离为0，说明u就是实际起点
		u=pre[u.r][u.c][u.dir];//查找u的父节点
	}
	p.push_back(NODE(r0,c0,dir));//插入入口点
	
	int cnt=0;
	for(int i=p.size()-1;i>=0;i--){
		if(cnt==0 )printf(" ");//打印行首空格
		printf(" (%d,%d)",p[i].r,p[i].c);
		cnt++;
		if(cnt==10){printf("\n");cnt=0;}
	}
	if(cnt!=0)printf("\n");
}

void bfs(){
	queue<NODE> q;
	memset(dist,-1,sizeof(dist));//初始化最短路径长度
	NODE u(r1,c1,dir);//生成根节点
	dist[u.r][u.c][u.dir]=0;
	q.push(u);//根节点入栈
	while(!q.empty()){
		u=q.front();q.pop();//队首元素出队
		if(u.r==r2 && u.c==c2){print_ans(u);return;}//到终点，打印结果并返回
		for(int i=0;i<3;i++){//遍历三种行走方式的子节点
			NODE v=walk(u,i);//生成一种子节点
			//规则允许这种走法 && 未越界 && 节点u到实际起点的距离小于0(说明该节点未被访问过)
			if(has_edge[u.r][u.c][u.dir][i] && inside(v.r,v.c) && dist[v.r][v.c][v.dir]<0){
				dist[v.r][v.c][v.dir]=dist[u.r][u.c][u.dir]+1;//子节点的距离在父节点的距离基础上加1
				pre[v.r][v.c][v.dir]=u;
				q.push(v);
			}
		}
	}
	printf("  No Solution Possible\n");//队列为空且没有打印返回，说明没有路径到达终点
}

int main(){
	freopen("f0614.in","r",stdin);
	while(readcase()){
		bfs();
	}
	return 0;
}
