//可以进行优化
#include <cstdio>
#include <algorithm>
using namespace std;
struct  IP	//定义 IP类，四个部分
{	int part[4];
	IP()	//默认构造方法，全为0	
		{part[0]=part[1]=part[2]=part[3]=0;}	
	void print()	//把输出定义成了成员函数	
		{printf("%d.%d.%d.%d/n",part[0],part[1],part[2],part[3]);}	
	bool operator < (const  IP a)const //重载小于运算，方便用sort排序找到最大最小	
		{	for(int i=0;i<4;i++)			
			if(part[i]!=a.part[i])				
				return part[i]<a.part[i];
			return false;
		}
}add[1010];
				
int toBit(int n);
int getMinBit( IP a, IP b);	//求子网掩码连续1的位数

int main()
{
	int n;
	while(~scanf("%d",&n)){
		 IP minn,mask;
		for(int i=0;i<n;i++)
			scanf("%d.%d.%d.%d",&add[i].part[0],&add[i].part[1],&add[i].part[2],&add[i].part[3]);//这种输入方式很特别
		sort(add,add+n);
		int bit=getMinBit(add[0],add[n-1]);	//将IP最大和最小值传入函数求出子网掩码连续1的个数		
		int site=(bit-1)/8;	//得到子网掩码第一个0所在的部分（点分十进制四部分）		
		for(int i=0;i<site;i++)	//这部分之前的部分都是255（即11111111）	
			mask.part[i]=255;		
		int m=8-bit+(site*8);	//m为第一个0所在部分那8位中有几个0
		mask.part[site]=(255>>m)<<m;	//重点255（11111111）先右移m位再左移m位即可得8-m个1和m个0，经过此步即可得子网掩码		
		for(int i=0;i<4;i++)			
			minn.part[i]=add[0].part[i]&mask.part[i];	//子网掩码与任意IP每部分按位与运算得到子网内最小IP		
		minn.print();		
		mask.print();	
	}	
	return 0;
}

int toBit(int n)	//给定一个十进制整数，得到整数的二进制位数
{	
	int res;	
	for(res=0;n;res++)
		n/=2;	
	return res;
}

//a.part[i]==b.part[i]时，直接把掩码msk[i]=255
//再对不等的位进行特殊处理。后续的msk[i+1]=0
int getMinBit( IP a, IP b)
{	
	int res=32;	
	for(int i=0;i<4;i++)		
		if(a.part[i]!=b.part[i]){	//对应部分不等，则找出二进制位从第几位开始出现不等		
			res=8-toBit(a.part[i]^b.part[i]);	//异或运算，两操作数对应二进制位不等得1，反之得0，根据异或结果可知出现不等的最左位置
			res+=(i*8);	//得到子网掩码连续1的个数			
			break;	
		}	
	return res;
}