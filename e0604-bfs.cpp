//算法竞赛入门经典第二版 习题6-1 UVa439 Knight Moves 
//采用BFS算法
//write by xucaimao,20171027-20:00开始编程，20171027-21:00测试通过

#include<cstdio>
#include<cstring>
#include<queue> 
using namespace std;

struct Point{int x,y,deep;};
int vis[8][8];//走过点的状态数组
Point target;//目标点坐标
//八个方向移动，每一个方向[x,y]的增量值
int dir[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int minstep;

void bfs(Point p){
	queue<Point> q;
	p.deep=0;
	q.push(p);//根节点入队列
	while(!q.empty()){
		Point u=q.front();//取队首节点
		q.pop();
		
		if(u.x==target.x && u.y==target.y){
			if(u.deep<minstep)minstep=u.deep;
			if(minstep==0)return;
			continue;
		}
		if(u.deep>=minstep)continue;//剪枝

		for(int i=0;i<8;i++){
			int nx=u.x+dir[i][0];
			int ny=u.y+dir[i][1];
			int ndeep=u.deep+1;
			if(nx<0 || nx>7 || ny<0 || ny>7)continue;
			if(vis[nx][ny])continue;
			Point nu;
			nu.x=nx;
			nu.y=ny;
			nu.deep=ndeep;
			q.push(nu);
			vis[nx][ny]=1;
		}
	}
	return;	
}

int main(){
	char ss[5];//初始位置字符串
	char ts[5];//目标位置字符串
	Point start;//初始位置xy坐标
	freopen("e0604-2.in","r",stdin);
	while( scanf("%s%s",ss,ts)==2 ){
		start.x=ss[0]-'a';//字母变成x坐标[0...7]
		start.y=ss[1]-'1';//数字变成y坐标[0...7]
		start.deep=0;
		target.x=ts[0]-'a';
		target.y=ts[1]-'1';
		minstep=6;
		memset(vis,0,sizeof(vis));
		bfs(start);
		printf("To get from %s to %s takes %d knight moves.\n",ss,ts,minstep);
	}
	return 0;
}