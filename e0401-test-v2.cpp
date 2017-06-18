//�㷨�������ž���ڶ��� ϰ��4-1 UVa589����
//write by xucaima,20161125,13:20
//ͬһ���������ַ����������������Ƚ��鷳
//����cin���룬����ֱ�������ո񡢻��С��Ʊ����ֱ�������ǿ��ַ�������Ҳ����ֱ����������
//��Ŀ��ȷ����֤����Ϸ��Һ췽�Ѿ�����
//����Ӧ�����ƶ��ڽ����ٽ����жϡ��ƶ���ʱ��Ҫ���ǿ��ܰѺ���Ե������

#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

struct POS{ int r,c;}; 
 
//����һ��״̬���飬0��0�в�ʹ�á���ԪΪ0��˵����λ�öԺڷ�����ȫ 
int kill[11][10]; 
//����һ���������飬��Ԫ������Ϊ���ӵ���ĸ��д,0��0�в�ʹ�� 
//��д��ĸΪ�췽��Сд��ĸΪ�ڷ���'\0'˵��û������ 
//�����кڷ�˧�����ڴ������� 
char board[11][10];
char boardswap[11][10];//����һ����ʱ���̣���������п��ܵĳ��Ӳ���

//�����˧��ÿ��λ�ÿ��Ե��߷�
//������(2,5)��4���߷��⣬����8��λ�ã�ÿ��λ�ö���Ӧ�����������߷�
//ͳһ����4���߷��ı����ٱ�̵ĸ��Ӷ�
//���ֺ������߷��ģ���(0,0)�����ĸ�,�����н����жϣ�����(0,0)����ǰ
POS gway[36]={
{2,4},{1,5},{0,0},{0,0},   {1,4},{2,5},{1,6},{0,0},   {1,5},{2,6},{0,0},{0,0},  //��Ӧ(1,4)...(1,6)
{1,4},{2,5},{3,4},{0,0},   {1,5},{2,4},{2,6},{3,5},   {2,5},{1,6},{3,6},{0,0},  //��Ӧ(2,4)...(2,6)
{2,4},{3,5},{0,0},{0,0},   {3,4},{2,5},{3,6},{0,0},   {3,5},{2,6},{0,0},{0,0}   //��Ӧ(3,4)...(3,6)
 };
 

//���ڴ�ӡ���ĺ���
void myprint(){
    printf("   ");
    for(int j=1;j<=9;j++)
        printf(" %d ",j);
    printf("       ");
    for(int j=1;j<=9;j++)
        printf(" %d ",j);
    printf("\n");
    for(int i=1;i<=10;i++){
        printf("%2d ",i);
        for(int j=1;j<=9;j++)
            if(boardswap[i][j]=='\0')printf(" + ");
            else printf(" %c ",boardswap[i][j]);
        printf("    %2d ",i);
        for(int j=1;j<=9;j++)
            printf(" %d ",kill[i][j]);
        printf("\n");
    }
}

//�췽����ɱ�˺������복ͬ��ͬ�У������ڶ�������֮ǰ(�ڽ�'g'����)��ȫ���ó�1 
void Rkill(char bd[11][10],int r,int c){ 
	for(int i=c+1;i<=9;i++) //������������ 
		if(bd[r][i]=='\0' || bd[r][i]=='g' )kill[r][i]+=1; 
		else break; 
	for(int i=c-1;i>=1;i--)//������������ 
		if(bd[r][i]=='\0' || bd[r][i]=='g')kill[r][i]+=1; 
		else break; 
	for(int i=r+1;i<=10;i++)//������������ 
		if(bd[i][c]=='\0' || bd[i][c]=='g')kill[i][c]+=1; 
		else break; 
	for(int i=r-1;i>=1;i--)//������������ 
		if(bd[i][c]=='\0' || bd[i][c]=='g')kill[i][c]+=1; 
		else break; 
} 
 
//�췽˧��ɱ�˺�������˧ͬ�����ϣ������ڶ�������֮ǰ��ȫ���ó�1 
void Gkill(char bd[11][10],int r,int c){ 
	for(int i=r-1;i>=1;i--)//������������ 
		if(bd[i][c]=='\0' || bd[i][c]=='g')kill[i][c]+=1; 
		else break; 
} 
 
//�췽�ڵ�ɱ�˺��� 
void Ckill(char bd[11][10],int r,int c){ 
	//���ڼ�,�ڽ�������Ϊ�ڼ� 
	bool pj=false;//�ڼ�״̬ 
	int c_pj=c,r_pj=r;//�ڼ�λ��,��ʼ��Ϊ�ڵ�λ�� 
	for(int i=c+1;i<=9;i++) //������������ 
		if(bd[r][i]!='\0' && bd[r][i]!='g'){ 
			c_pj=i; 
			r_pj=r; 
			break; 
		} 
	if(c_pj>c){//�ҵ��ڼ� 
		for(int i=c_pj+1;i<=9;i++) //���ڼ������� 
            if(bd[r][i]=='\0' || bd[r][i]=='g')kill[r][i]+=1;
            else break; 
	} 
	for(int i=c-1;i>=1;i--)//������������ 
		if(bd[r][i]!='\0' && bd[r][i]!='g'){ 
			c_pj=i; 
			r_pj=r; 
			break; 
		} 
	if(c_pj<c){//�ҵ��ڼ� 
        for(int i=c_pj-1;i>=1;i--) //���ڼ������� 
            if(bd[r][i]=='\0' || bd[r][i]=='g')kill[r][i]+=1;
            else break; 
	} 
	for(int i=c+1;i<=10;i++)//������������ 
		if(bd[i][c]!='\0' && bd[i][c]!='g'){ 
			c_pj=c; 
			r_pj=i; 
			break; 
		} 
	if(r_pj>r){//�ҵ��ڼ� 
        for(int i=r_pj+1;i<=10;i++)//���ڼ������� 
		if(bd[i][c]=='\0' || bd[i][c]=='g')kill[i][c]+=1; 
		else break; 
	} 
	for(int i=c-1;i>=1;i--)//������������ 
		if(bd[i][c]!='\0' && bd[i][c]!='g'){ 
			c_pj=c; 
			r_pj=i; 
			break; 
		} 
	if(r_pj<r){//�ҵ��ڼ� 
        for(int i=r_pj-1;i>=1;i--)//���ڼ������� 
		if(bd[i][c]=='\0' || bd[i][c]=='g')kill[i][c]+=1; 
		else break; 
	} 
}

//�췽���ɱ�˺���
void Hkill(char bd[11][10],int r,int c){
    if(bd[r-1][c]=='\0' && r>=3 && c>=2 && c<=9){ //�������ߣ�������
        kill[r-2][c-1]+=1;
         kill[r-2][c+1]+=1;
    }
     if(bd[r+1][c]=='\0' && r<=8 && c>=2 && c<=9){ //�������ߣ�������
        kill[r+2][c-1]+=1;
         kill[r+2][c+1]+=1;
    }
     if(bd[r][c-1]=='\0' && r>=2 && r<=9 && c>=3){ //�������ߣ�������
        kill[r-1][c-2]+=1;
         kill[r+1][c-2]+=1;
    }
    if(bd[r][c+1]=='\0' && r>=2 && r<=9 && c<=7){ //�������ߣ�������
        kill[r-1][c+2]+=1;
         kill[r+1][c+2]+=1;
    }

}

//��ʼ�����̺�ɱ������
void initkill(char bd[11][10]){
    memset(kill,0,sizeof(kill));//��ʼ��
    //���������������ɿ�kill����
    for(int r=1;r<=10;r++)
        for(int c=1;c<=9;c++){
            switch(bd[r][c]){
                case'G':
                    Gkill(bd,r,c);
                    break;
                case'R':
                    Rkill(bd,r,c);
                    break;
                case'C':
                    Ckill(bd,r,c);
                    break;
                case'H':
                    Hkill(bd,r,c);
                    break;
            }
        }
}


//�жϺڷ����Ƿ񱻽�����r��c�Ǻڽ�������
//����Ҫ�жϺڽ��ĸ��ֿ����߷�
int movejudge(int r,int c){
    int life=0;
    //����������ת��Ϊһά�������Ӧ�±�
    //�ҵ���ǰ�ڽ����߷�������
    int n=((r-1)*3+(c-4))*4;
    for(int i=0;i<4;i++){   //����4������λ��
        memcpy(boardswap,board,sizeof(board));//����һ������
        int rnew=gway[n+i].r;
        int cnew=gway[n+i].c;
        if(rnew==0) break;  //����(0,0)��ǰ����ѭ��
        boardswap[r][c]='\0';
        boardswap[rnew][cnew]='g';  //�ƶ��ڽ�
        initkill(boardswap);
        if(kill[rnew][cnew]==0){
            life++;
            printf("move to %d,%d\n",rnew,cnew);
            myprint();
        }

    }
    //myprint();
    return life;
}


int main(){
    int N,r_bg,c_bg;//����췽������������˧��λ������
    freopen("e0401.in","r",stdin);
    while(cin>>N>>r_bg>>c_bg  && N!=0){
        //printf("%d %d %d\n",N,r_bg,c_bg);
        memset(board,'\0',sizeof(board));//��ʼ������
        board[r_bg][c_bg]='g';//����ڽ�
        for(int i=0;i<N;i++){ //����췽��������
            int r,c;
            char p;
            cin>>p>>r>>c;
            printf("%c %d %d \n",p,r,c);
            board[r][c]=p;
        }

        //myprint();

        if(movejudge(r_bg,c_bg)==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
