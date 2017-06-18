//算法竞赛入门经典第二版 例题6-13 UVa1103 古代象形符号
//write by xucaimao,20170203-22:00开始编程，20170204-20:07测试通过
//本程序采用DFS递归算法
//本程序在我的macair上测试时遇到特殊样例会出现segmentation fault :11错误。但是提交UVa可以AC。
//分析此样例的数据基本全0，造成递归层次过多，dfszero程序段溢出。

#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>//sort
using namespace std;

const int maxn=200+10;
int h,w;
string pic[maxn];//用于储存输入数据的图
string hex2bin[16]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
string ancient[6]={"W","A","K","J","S","D"};//象形符号索引表
string ans;//答案
int cnt;//白洞数量

//对白色像素进行连通并标记为‘b’
void dfszero(int r,int c){
	if(r<0 || r>h+1 || c<0 || c>w*4+1) return;
	if(pic[r][c]!='0') return;
	pic[r][c]='b';//标记
	dfszero(r-1,c);//查找相邻的四个方向
	dfszero(r,c-1);
	dfszero(r+1,c);
	dfszero(r,c+1);	
}

//对黑色像素进行连通并标记为‘f’,同时找出内部白洞的数量cnt
void dfs(int r,int c){
	if(r<0 || r>h+1 || c<0 || c>w*4+1) return;
	if(pic[r][c]=='0') {cnt++;dfszero(r,c);}
	if(pic[r][c]!='1') return;
	pic[r][c]='f';//标记
	dfs(r-1,c);//查找相邻的四个方向
	dfs(r,c-1);
	dfs(r+1,c);
	dfs(r,c+1);	
}

void myinit(){
	for(int i=0;i<maxn;i++)
		pic[i]="0";
	ans.clear();//初始化答案序列
}

int main(){
	int cas=0;
	freopen("f0613.in","r",stdin);
	while(scanf("%d%d",&h,&w)==2 && h && w){
		myinit();
		cas++;
		string s;
		for(int i=0;i<=w*4+1;i++)s+="0";
		pic[0]=s;
		pic[h+1]=s;//上下加边界
		for(int i=1;i<=h;i++){//读入h行
			cin>>s;
			pic[i]="0";//加左边界
			for(int j=0;j<w;j++){//十六进制转换成二进制字符串
				int t=0;
				if(s[j]>='0' && s[j]<='9') t=s[j]-'0';
				else t=10+s[j]-'a';
				pic[i]+=hex2bin[t];
			}
			pic[i]+="0";//加右边界
		}
		
		//for(int i=0;i<=h+1;i++)cout<<pic[i]<<endl;
		//cout<<"end of input"<<endl;
		dfszero(0,0);//背景连通，如果不加边界此处会很麻烦
		//cout<<"end of dfszero"<<endl;
		//for(int i=0;i<=h+1;i++)cout<<pic[i]<<endl;
		
		for(int i=0;i<=h+1;i++)//遍历黑色像素
			for(int j=0;j<=w*4+1;j++)
				if(pic[i][j]=='1'){
					cnt=0;
					dfs(i,j);//对黑色像素进行连通并找出其内部白洞的数量cnt
					if(cnt<0 || cnt>5) printf("ERROR!!!\n\n");
					ans+=ancient[cnt];
				}
		
		//cout<<endl;
		//for(int i=0;i<=h+1;i++)cout<<pic[i]<<endl;
				
		sort(ans.begin(),ans.end());//排序		
	
		//begin to output
		cout<<"Case "<<cas<<": "<<ans<<endl;
	}//end of while
	return 0;
}