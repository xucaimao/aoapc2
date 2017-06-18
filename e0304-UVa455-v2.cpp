//算法竞赛入门经典第二版 e0304.cpp UVa455周期串
//write by xucaima,20161109,15:00.20161115,12:44测试通过.
//时间限制:3s
//输入数据：第一行整数N，说明有多少组测试数据
//后面的每一行数据都是一个空行，再加一行不包含空格的小于等于80个字符的字符串
//没有子串，类似"abcdefga",应返回字符串总长。被这个坑的不浅，折腾了许久

#include<cstdio>
#include<cstring>

//此函数网上提交通不过
int judge2(char* s)
{
	int len=strlen(s);
	int k;
	for(k=1;k<=len/2;k++){ //注意此处的<=;对于极端的类似“abcdeabcde”串
		bool EQ=true;
		for(int i=k;i+k<=len;i+=k)//判断s[0]与以后间隔k的所有字符是否相等
			if(s[0]!=s[i])
				{EQ=false;break;}//如果不相等，跳出循环，k加1再次循环执行判断
		if(EQ)return k;//一个循环结束没有出现不相等的情况，则返回k
	}
	return len;//没有子串，类似"abcdefga"返回字符串总长
}

int judge(char* s)
{
	int len=strlen(s);
	int k;
	for(k=1;k<=len/2;k++){ //注意此处的<=;对于极端的类似“abcdeabcde”串
		bool EQ=true;
		if(len%k==0){//次判断很好
			int t=len/k; //有t个假设相等的子串
			for(int i=0;i<k;i++)//对子串内的每个字符都进行判断
				for(int j=1;j<t;j++)//执行t-1次判断
					if(s[i]!=s[j*k+i]){EQ=false;break;}//如果不相等，跳出循环，k加1再次循环执行判断
			if(EQ) return k;//循环结束没有出现不相等的情况，则返回k
		}
	}
	return len;//没有子串，类似"abcdefga"返回字符串总长
}

int main()
{
	char ss[81];
	int N;
	//freopen("e0304.in","r",stdin);
	scanf("%d",&N);
	for(int n=1;n<=N;n++){
		getchar();//读入空行
		scanf("%s",ss);//读入字符串行
		int kk=judge(ss);
		if(n>1)printf("\n");//避免头尾出现多余的空行
		printf("%d\n",kk);
	}	
	return 0;
}