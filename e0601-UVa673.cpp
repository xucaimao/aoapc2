//算法竞赛入门经典第二版 习题6-1 UVa673 Parentheses Balance
//write by xucaimao,20171025-10:30开始编程，20171025-14:30测试通过
//采用数组模拟栈
//数据输入是重点，不熟练
//scanf("%s",line)会忽略掉空行，造成程序错误.可以采用gets()函数
//输入数据最后要有一行空行
#include<cstdio>
char stack[150];	//用数组模拟栈
int s_top=-1;		//栈空
int main(){
	int n;
	char ch;
	freopen("e0601.in","r",stdin);
	scanf("%d",&n);
	ch=getchar();		//此处重点，忽略首行末尾的\n
	for(int i=1;i<=n;i++){
		//开始处理一行数据		
		int ok=1;
		s_top=-1;
		
		while( (ch=getchar()) !='\n' && ch!=EOF ){
			if(ok){
				//前面已经碰到不匹配的情况，就不处理接着读字符
				if(ch=='(' || ch=='[' ){
				//进栈
				s_top++;
				stack[s_top]=ch;
				}
				else 
					if( (ch==')' && stack[s_top]=='(' ) || (ch==']' && stack[s_top]=='[') ){
						//和栈顶元素匹配，出栈
						s_top--;
					}
					else{
						//和栈顶元素不匹配
						ok=0;
						//break;这里不能用break，必须接着读完一行
					}
			}
		}
		if(ok && s_top==-1)printf("Yes\n");
			else printf("No\n");
	}
	return 0;
}