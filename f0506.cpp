//算法竞赛入门经典第二版 例题5-6 UVa540 团体队列 网上程序
//write by xucaimao,20161207,16:15
//与书上给的示例不同，队员编号与小队的编号是没有数学上的逻辑关系的
//因而只能采用map来建立二者的对应关系。数据应保证队员编号的唯一性

#include<cstdio>
#include<queue>
#include<map>
using namespace std;

const int maxt=1000+10;//最多有1000个小队

int main(){
	freopen("f0506.in","r",stdin);
	int T,kase=1;
	while(scanf("%d",&T)==1 && T){
		printf("Scenario #%d\n",kase);
		map<int,int> team; //team[x]表示编号为x的人所在的小队的编号
		for(int i=0;i<T;i++){ //读入t个小队的数据
			int n,x;
			scanf("%d",&n);
			while(n--){
				scanf("%d",&x);
				team[x]=i; //建立队员编号与小队编号的映射关系
			}
		}
		
		queue<int> q_all,q_sub[maxt];//q_all是小队编号的队列，q_sub[i]是小队i成员的队列
		for(;;){ //重复执行命令
			int x;
			char cmd[10];
			scanf("%s",cmd);
			if(cmd[0]=='S') break;
			else if(cmd[0]=='D'){//出对
							int t=q_all.front();//取得首先出队的小队编号
							printf("%d\n",q_sub[t].front());//根据小队编号找到小队内首先出队的队员编号
							q_sub[t].pop();//小队队员出队
							if(q_sub[t].empty())//小队t的全部成员都已经出队
								q_all.pop();//总队内改小队编号出队
						}
						else if(cmd[0]=='E'){ //入队
							scanf("%d",&x);//读入出对队员的编号
							int t=team[x];//查找该队员的小队编号
							if(q_sub[t].empty())	//遇到该小队的第一个队员入列
								q_all.push(t);//小队编号进入总团队队列
							q_sub[t].push(x);//小队队员进入自己的小队
						}
		}
		printf("end of #%d\n",kase);
		printf("\n");	

	}
	return 0;
}