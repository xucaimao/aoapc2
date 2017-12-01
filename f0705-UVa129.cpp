//算法竞赛入门经典第二版 例题7-5 UVa129 困难的串
//write by xucaimao,20171130-23:00开始编程，20171130-23:50测试通过


#include<cstdio>
#include <cstring>
char ans[90];
int ansnum=0;

int dfs(int n,int L,int cur){
	//ans
	if(ansnum==n){
		for(int i=0;i<cur;i++){
			if(i>0 && i%64==0)printf("\n");
			else if(i>0 && i%4==0)printf(" ");
			printf("%c",ans[i]+'A');
		}
		printf("\n%d\n",cur);
		return 0;
	}
	for(int ch=0;ch<L;ch++){//枚举前L个字母
		ans[cur]=ch;
		int ok=1;
		//从串尾开始，比较各个len长度的相邻子串
		//子串的最大长度等于当前串长度(cur+1)的一半
		for(int len=1;len*2<=cur+1;len++){
			int equal=1;
			for(int k=0;k<len;k++)//比较子串上的倒数第k个字符
				if(ans[cur-k]!=ans[cur-len-k]){
					//有一个字母不相同，说明子串不同
					equal=0;
					break;
				}
			if(equal){ok=0;break;}
		}
		if(ok){//当前字符正确
			ansnum++;
			int stat=dfs(n,L,cur+1);//查找下一个字符
			if(stat==0)return 0;
		}
	}
	return 1;
}

int main(){
	int n,L;
	freopen("f0705.in","r",stdin);
	while(1){
		scanf("%d%d",&n,&L);
		ansnum=0;//必须要初始化
		if(n==0 && L==0)break;
		dfs(n,L,0);
	}
	return 0;
}