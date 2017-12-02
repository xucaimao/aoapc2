/*
	算法竞赛入门经典第二版 例题7-6 UVa140 带宽
	write by xucaimao,20171201-14：25开始编程，20171130-23:50测试通过
	本程序虽然用了最笨的办法，不过全部是自己实现，顺带复习了图的领接表
*/

#include<cstdio>
#include <cstring>
const int maxn=30;//字母A~Z,最多26个
bool vis[maxn];//判断字母是否被使用过
char letter[10];//记录具体出现的字母
int G[maxn][10];
int G2len[maxn];//对应每一个G第二维的有效长度
char ans[10],minans[10];//节点数最多只有8个
int bandwidth=0,minbandwidth=100;//带宽,最小带宽

int vertexBandWidth(int ans[],int len,int v){
	//对有len个元素的数组ans，计算节点v的最大带宽
	int width=0;
	for(int i=0;i<G2len[v];i++){
		int w=G[v][i];//取得节点v的一个相邻节点
		int p=0;
		int cw=1;
		while(ans[p]!=v && ans[p]!=w)p++;//找到第一个v或者w
		p++;//定位到下一个字符
		while( p<len && ans[p]!=v && ans[p]!=w ){cw++;p++;}
		if(cw>width)width=cw;
	}
	return width;
}

int stringBandWidth(int ans[],int len){
	//对有len个元素的数组ans，计算其总带宽
	int width=0;
	for(int i=0;i<len;i++){
		int cw=vertexBandWidth(ans,len,ans[i]);
		if(cw>width)width=cw;
	}
	return width;
}


void dfs(int vetexnum,int cur){
	//有vetexnum个节点的图，ans[0...cur-1]是一个最小带宽排列，
	//在ans[cur]中加入一个字符，使得ans的带宽最小
	//增加剪枝，提升速度10陪
	if(cur==vetexnum){
		//记录最小值
		int bd=stringBandWidth(ans,cur);
		if(bd<minbandwidth){
			minbandwidth=bd;
			memcpy(minans,ans,sizeof(ans));
		}	
	}
	else{
		for(int ch=0;ch<vetexnum;ch++)
			//枚举出现的有效字符
			if(!vis[ch]){
				ans[cur]=letter[ch];
				if(vertexBandWidth(ans,cur,ch-'A')<minbandwidth){//剪枝
					vis[ch]=1;
					dfs(vetexnum,cur+1);
					vis[ch]=0;	
				}		
			}
	}
}

bool hasedge(int v,int w){
	//判断边vw是否存在，若存在返回true
	for(int i=0;i<G2len[v];i++)
		if(G[v][i]==w)return true;
	return false;
}

int main(){
	char v,w;
	freopen("f0706.in","r",stdin);
	bool endinput=false;
	while(!endinput){
		int vnum=0;//本行数据有效的节点数
		memset(G,0,sizeof(G));
		memset(ans,0,sizeof(ans));
		memset(G2len,0,sizeof(G2len));
		memset(vis,0,sizeof(vis));
		bandwidth=0;
		minbandwidth=100;//初始化
		bool endline=false;
		while(!endline){//开始读入一组数据
			scanf("%c",&v);
			if(v=='#'){endinput=true;break;}
			getchar();//忽略':'
			while(1){//读入一个节点的相邻节点
				w=getchar();
				if(w==';')break;
				if(w=='\n'){endline=true;break;}
				//此处的重复判断必不可少
				if(!hasedge(v-'A',w-'A'))
					G[v-'A'][ G2len[v-'A']++ ]=w-'A';//记录无向图
				if(!hasedge(w-'A',v-'A'))
					G[w-'A'][ G2len[w-'A']++ ]=v-'A';
			}
		}
		if(!endinput){
			for(int i=0;i<maxn;i++)//统计节点数
				if(G2len[i]>0)vnum++;

			dfs2(vnum,0);
			for(int i=0;i<vnum;i++)
				printf("%c ",minans[i]+'A' );
			printf("-> %d\n",minbandwidth );
		}
	}
	return 0;
}