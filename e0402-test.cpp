//算法竞赛入门经典第二版 习题4-2 UVa201正方形
//write by xucaima,20161128,19：40开始编程,21:50提交通过
//本题的重点，是用两个二维数组，分别存放行和列的”线段“，
//数据读入是，V i,j到数组V[j][i]的转变是重点
#include<iostream>
#include<cstring>
using namespace std;
const int NMAX=20;
int h[NMAX][NMAX];
int v[NMAX][NMAX];

//打印输入的数据
void myprint(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<(h[i][j]==1?" -":"  ");
		cout<<endl;
		for(int j=1;j<=n;j++)
			cout<<(v[i][j]==1?"| ":"  ");
		cout<<endl;
	}
}
//在nxn的阵列中查找边长为len的正方形数量
int check(int n,int len){
	int sum=0;
	for(int i=1;i<=n-len;i++) 
		for(int j=1;j<=n-len;j++){//遍历所有节点
			bool issquare=true;
			for(int k=0;k<len && issquare;k++){ //遍历节点(i,j)的各个边
				if(h[i][j+k]==0 || h[i+len][j+k]==0)//看横边
					{issquare=false;break;}
				if(v[i+k][j]==0 || v[i+k][j+len]==0)//看竖边
					{issquare=false;break;}
			}
			if(issquare) sum++;
			}		
	return sum;
}

int main(){
	int n,m,datanum=0;
	int num[NMAX];//存放每一种边长的正方形的数量
	freopen("e0402.in","r",stdin);
	while(cin>>n){
		datanum++;
		memset(num,0,sizeof(num));
		memset(h,0,sizeof(h));//初始化
		memset(v,0,sizeof(v));
		cin>>m;
		for(int k=0;k<m;k++){//读入数据
			char ch;
			int i,j;
			cin>>ch>>i>>j;
			if(ch=='H') h[i][j]=1;
			if(ch=='V') v[j][i]=1;//坐标交换,最重要的一点
		}
	//myprint(n);
	int total=0;//总正方形数量
	for(int len=1;len<=n;len++){ //遍历边长为i的可能性
		num[len]=check(n,len);
		total+=num[len];
	}
	//开始打印
	if(datanum>1)
		cout<<endl<<"**********************************"<<endl<<endl;
	cout<<"Problem #"<<datanum<<endl<<endl;
	if(total>0){
		for(int len=1;len<=n-1;len++)//遍历边长为i的可能性
			if(num[len]>0)
				cout<<num[len]<<" square (s) of size "<<len<<endl;
	}else 
		cout<<"No completed squares can be found."<<endl;
	
	}//end while
	return 0;
}