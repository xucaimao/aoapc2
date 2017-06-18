//算法竞赛入门经典第二版 例题6-4 UVa11988 并行程序模拟
//write by xucaimao,20161231-14：20开始编程，20161218-测试通过

#include<cstdio>
#include<cstring>
const int MAXN=50;
char s[MAXN];
int next[MAXN];
int cur,last;

int main(){
	freopen("f0604.in","r",stdin);
	while(scanf("%s",s+1)==1){//字符串读入，从s[1]开始储存
		cur=last=0;
		next[0]=0;
		int len=strlen(s+1);
		
		for(int i=1;i<=len;i++){
			char ch=s[i];
			if(ch=='[')cur=0;
			else if(ch==']')cur=last;
			else{
				next[i]=next[cur];
				next[cur]=i;
				if(cur==last) last=i;
				cur=i;
			}
		}
		for(int i=next[0];i!=0;i=next[i])
			printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}