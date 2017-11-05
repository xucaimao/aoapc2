//算法竞赛入门经典第二版 习题6-6 UVa12166 Equilibrium Mobile
//write by xucaimao,20171102-22:50开始编程，20171103-22:20测试通过
//由题，重量<10^9,二者相加会不会越界
//[[2,5],[2,1]]同一层的两对叶子要能比较

#include<cstdio>
#include<cstring>
char s[10000];			//存储一行输入的字符串
int change=0;			//修改的次数
int pos=0;				//指向当前字符

long long int solve(){
	//错误程序，不能判断同层的叶子
	long long int nl=0,nr=0;
	if(s[pos]=='['){
		pos++;			//跳过'['
		nl=solve();		//读入左节点
		pos++;			//跳过','
		nr=solve();		//读入右节点
		pos++;			//跳过']'
		if(nl!=nr){		//返回小值
			change++;
			if(nl<nr)return 2*nl;
			else return 2*nr;
		}
		else return 2*nl; 

	}
	else{				//一个节点的字符串转整数
		long long int n=0;
		while(s[pos]!=',' && s[pos]!=']'){//计算节点
			n+=(s[pos]-'0');
			pos++;
		}
		return n;	
	}
}

int main(){
	freopen("e0606.in","r",stdin);
	int T;
	scanf("%d",&T);
	getchar();
	while(T--){
		memset(s,0,sizeof(s));
		change=0;
		scanf("%s",s);
		if(s[0]!='[') printf("0\n");
		else {
			pos=0;
			solve();
			printf("%d\n",change);
		}
	}
	return 0;
}