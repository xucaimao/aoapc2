//算法竞赛入门经典第二版 习题4-5 UVa1590 IP NETWORKS
//write by xucaima,20161202,10:30开始编程.测试通过.
#include<cstdio>
#include<algorithm>
using namespace std;

struct IP{
	int ip[4];
	IP(){  //定义一个构造函数
		ip[0]=ip[1]=ip[2]=ip[3]=0;
	}
	
	bool operator<(const IP & ipp) const{  //重载<运算符,少了最后的const会出错
		for(int i=0;i<4;i++)
			if(ip[i]!=ipp.ip[i])
				return ip[i]<ipp.ip[i];
		return false;
	}
	void printip(){
		printf("%d.%d.%d.%d\n",ip[0],ip[1],ip[2],ip[3]);
	}
};
IP myip[1010];


int bitnum(int n){  //给定一个十进制整数，得到整数的二进制位数
	int num=0;
	while(n>0){n/=2;num++;}
	return num;
}

int main(){
	int n;
	freopen("e0405.in","r",stdin);
	while(scanf("%d",&n)==1){
		for(int i=0;i<n;i++)  //读入n组ip地址
			scanf("%d.%d.%d.%d",&myip[i].ip[0],&myip[i].ip[1],&myip[i].ip[2],&myip[i].ip[3]);
		sort(myip,myip+n);//从小到大排序
		IP mn=myip[0],mx=myip[n-1];//取出最小和最大
		IP mask,minip;//定义掩码及最小IP
		int i=0;
		while(mn.ip[i]==mx.ip[i] && i<4){
			mask.ip[i]=255;
			i++;
		}//跳出循环后，i存储的是IP地址开始不同的位置
		int mm=mn.ip[i]^mx.ip[i];//查找两个不同数字中不同的二进制位
		int m=bitnum(mm);
		mask.ip[i]=(255>>m)<<m;
		//255（11111111）先右移m位再左移m位即可得8-m个1和m个0，经过此步即可得子网掩码		
		for(int j=0;j<4;j++)
			minip.ip[j]=mask.ip[j]&myip[0].ip[j];
		minip.printip();
		mask.printip();
	}
	return 0;
}
