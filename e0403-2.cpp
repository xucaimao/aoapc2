//�㷨�������ž���ڶ��� ϰ��4-3 UVa220�ڰ���
//write by xucaima,20161129,11:20��ʼ���.   ����ͨ��
//������β�Ĵ�������Ҫ����׼����������벻Ҫ����
//scanf����β��\n��������������ڣ�������������getchar������Ҫ����\n�Ĵ���
#include<cstdio>
#include<cstring>
char board[10][10];
struct DIRECTION{
	int dr,dc;
};

struct POS{
	int r,c;
};
//����˸�����������������������Ҳ࿪ʼ˳ʱ��һȦ
DIRECTION drc[8]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
//����һ����ά���飬������ű���ס�ĶԷ����ӵ�λ��
POS ppos[64];
//���屻��ס���ӵ�����
int pnum=0;

void myprint(){
	for(int i=1;i<=8;i++){
		for(int j=0;j<=9;j++)
			printf("%c",board[i][j]);
		printf("\n");
	}	
}

//�ҵ�ĳһλ��(r,c)�Ϸ��߷�������
//���Լ򻯣����ҵ��Ϸ��߷���ʱ���ֱ�ӷ���
//��e0403-1������ͬ����¼����ס���ӵĹ���
int findlegal(char player,int r,int c){
	if(board[r][c]!='-')return 0;//��ǰλ���Ѿ���������
	int result=0;
	pnum=0;//����ס���ӵ�����
	memset(ppos,0,sizeof(ppos));//���������0
	for(int i=0;i<8;i++){ //�˸�����Ѱ��
		int dr=drc[i].dr,dc=drc[i].dc;
		int rn,cn;
		rn=r+dr;
		cn=c+dc;
		int op=0;//���ֶԷ���������
		bool fp=false;
		while(rn>=1 && rn<=8 && cn>=1 && cn<=8 ){
			if(board[rn][cn]=='-') break;
			else if(board[rn][cn]!=player)//�����ŵ��ǶԷ�����
					{
						ppos[pnum].r=rn;ppos[pnum].c=cn;
						pnum++;
						op++;
						rn=rn+dr;  //��ʼѰ����һ������
						cn=cn+dc;
					}
			else{  //�����Լ�����
				if(op>0){result++; fp=true;}//�ҵ�һ�ֺϷ��߷���������չ���򣬼�¼λ��
				break; //����֮����������Լ�����ʱop=0����˵�������������ӽ���һ��
				}
		}//end of while
		if(!fp) pnum-=op;//������������û���ҵ��Ϸ�λ�ã�ָ���λ
	}//end of for
	return result;
}

void printlist(char player){
	int tot=0;
	for(int i=1;i<=8;i++)
		for(int j=1;j<=8;j++){
			int t=findlegal(player,i,j);
			tot+=t;
			if(t>0) printf("(%d,%d) ",i,j);
		}
	if(tot==0) printf("No legal move.\n");
	else printf("\n");
}

void mymove(char* order,char player){
	printf("mymove\n");
}

int main(){
	int gamenum;
	char player[10];
	char order[10];
	freopen("e0403.in","r",stdin);
	scanf("%d",&gamenum);
	for(int gn=1;gn<=gamenum;gn++){ //��ʼһ����Ϸ
		memset(board,' ',sizeof(board));//��ʼ��
		for(int i=1;i<=8;i++){  //��������
			scanf("%s",order);
			for(int j=0;j<8;j++)
				board[i][j+1]=order[j];
		}
		myprint();
		scanf("%s",player);
		printf("%s\n",player);
		
		int a=findlegal(player[0],4,6);
		printf("legal of (4,6) is: %d .\n",a);
		printf("will be changed pices position is: \n");
		for(int i=1;i<=pnum;i++)
			printf(" (%d,%d) ",ppos[pnum].r,ppos[pnum].c);
		//while(scanf("%s",order) && order[0]!='Q'){
		//	if(order[0]=='L') printlist(player[0]);
		//	if(order[0]=='M') mymove(order,player[0]);
		//}			
	}
	return 0;
}