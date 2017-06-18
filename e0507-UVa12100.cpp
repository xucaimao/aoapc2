//算法竞赛入门经典第二版 习题5-7 UVa12100 打印队列
//write by xucaimao,20161220-19:25开始编程，20161218-20:50测试通过
//queue不支持遍历，因本题需要找到最大优先级的任务，因而改用deque
//可以改用vector

#include<cstdio>
#include<deque>

using namespace std;

struct Node{
	int name,pri;
};

//判断队首任务优先级是否最高
bool front_is_max(deque<Node> & prn){ 
	deque<Node>::iterator it;
	int maxx=prn.front().pri;
	for(it=prn.begin();it!=prn.end();it++)
		if(it->pri > maxx) return false;
	return true;
}

int main(){
	int T;
	freopen("e0507.in","r",stdin);
	scanf("%d",&T);
	while(T--){//T组运算
		int N,NAME;
		scanf("%d%d",&N,&NAME);
		deque<Node> prn;
		for(int i=0;i<N;i++){//读入队列
			Node nod;
			int t;
			scanf("%d",&t);
			nod.name=i;//把数据的顺序作为打印任务的名字
			nod.pri=t;//读入优先级
			prn.push_back(nod);//进入队列
		}
		int time=0;
		bool printed=false;
		while(!printed){
			Node nod=prn.front();//取队首元素
			if(front_is_max(prn)){//队首元素优先级最高
				prn.pop_front();//打印队首元素
				time++;//计时
				if(nod.name==NAME) printed=true;
			}
			else{ //队首元素去除进入队尾
				prn.pop_front();
				prn.push_back(nod);
			}
		}
		printf("%d\n",time);
	}
	return 0;
}