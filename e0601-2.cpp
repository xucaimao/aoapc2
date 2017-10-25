//算法竞赛入门经典第二版 习题6-1 UVa673 Parentheses Balance
//write by xucaimao,20171025-10:30开始编程，20170114-20:50测试通过
//采用数组模拟栈
//数据输入是重点，不熟练
//scanf("%s",line)会忽略掉空行，造成程序错误
//输入数据最后要有一行空行
#include<cstdio>
char line[150];
char stack[150];	//用数组模拟栈
int p_stack=-1;		//栈空
int main(){
	int n;
	char ch;
	//freopen("e0601.in","r",stdin); //网上提交时需要注释掉
	scanf("%d",&n);
	ch=getchar();		//此处重点，忽略首行末尾的\n
	for(int l=1;l<=n;l++){
		//开始处理一行数据		
		int ok=1;
		p_stack=-1;
		gets(line);
		int i=0;
		while( line[i]){
				if(line[i]=='(' || line[i]=='[' ){
				//进栈
				p_stack++;
				stack[p_stack]=line[i];
				i++;
				}
				else 
					if( (line[i]==')' && stack[p_stack]=='(' ) || (line[i]==']' && stack[p_stack]=='[') ){
						//和栈顶元素匹配，出栈
						p_stack--;
						i++;
					}
					else{
						//和栈顶元素不匹配，跳出循环开始处理下一行
						ok=0;
						break;
					}
		}
		if(ok && p_stack==-1)printf("Yes\n");
			else printf("No\n");
	}
	return 0;
}