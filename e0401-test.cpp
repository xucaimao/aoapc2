//�㷨�������ž���ڶ��� ϰ��4-1 UVa589����
//write by xucaima,20161125,13:20
//ͬһ���������ַ����������������Ƚ��鷳
//����cin���룬����ֱ�������ո񡢻��С��Ʊ����ֱ�������ǿ��ַ�������Ҳ����ֱ����������
//��Ŀ��ȷ����֤����Ϸ��Һ췽�Ѿ�����
//����Ӧ�����ƶ��ڽ����ٽ����ж�

#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

struct PCS{
    char p;
    int r,c;
};
struct POS{ int r,c;};

//����һ��״̬���飬0��0�в�ʹ�á���ԪΪ0��˵����λ�öԺڷ�˧��ȫ
int kill[11][10];
//����һ���������飬��Ԫ������Ϊ���ӵ���ĸ��д,0��0�в�ʹ��
//��д��ĸΪ�췽��Сд��ĸΪ�ڷ���'\0'˵��û������
//�����кڷ�˧�����ڴ�������
char board[11][11];
//�췽��������
PCS pieces[8];
//�����˧��ÿ��λ�ÿ��Ե��߷�
//������(2,5)��8���߷��⣬����8��λ�ã�ÿ��λ�ö���Ӧ�����������߷�
//ͳһ���������߷��ı����ٱ��
//���ַ����ģ�����һ����������λ��
POS gway[27]={
{2,4},{1,5},{1,4},  {1,4},{1,5},{1,6},  {1,5},{1,6},{2,6},
{1,4},{2,5},{3,4},  {0,0},{0,0},{0,0},  {2,5},{1,6},{3,6},
{2,4},{3,4},{3,5},  {3,4},{2,5},{3,6},  {3,5},{3,6},{2,6}
 };
//������(2,5)��4���߷�
POS gway25[4]={ {1,5},{2,4},{2,6},{3,5} };

//�췽����ɱ�˺������복ͬ��ͬ�У������ڶ�������֮ǰ��ȫ���ó�1
void Rkill(int r,int c){
	for(int i=c+1;i<=9;i++) //������������
		if(board[r][i]=='\0')kill[r][i]+=1;
		else break;
	for(int i=c-1;i>=1;i--)//������������
		if(board[r][i]=='\0')kill[r][i]+=1;
		else break;
	for(int i=r+1;i<=10;i++)//������������
		if(board[i][c]=='\0')kill[i][c]+=1;
		else break;
	for(int i=r-1;i>=1;i--)//������������
		if(board[i][c]=='\0')kill[i][c]+=1;
		else break;
}

//�췽˧��ɱ�˺�������˧ͬ�����ϣ������ڶ�������֮ǰ��ȫ���ó�1
void Gkill(int r,int c){
	for(int i=r-1;i>=1;i--)//������������
		if(board[i][c]=='\0')kill[i][c]+=1;
		else break;
}

//�췽�ڵ�ɱ�˺���
void Ckill(int r,int c){
	//���ڼ�
	bool pj=false;//�ڼ�״̬
	int c_pj=c,r_pj=r;//�ڼ�λ��,��ʼ��Ϊ�ڵ�λ��
	for(int i=c+1;i<=9;i++) //������������
		if(board[r][i]!='\0'){
			c_pj=i;
			r_pj=r;
			break;
		}
	if(c_pj>c){//�ҵ��ڼ�
		for(int i=c_pj+1;i<=9;i++) //���ڼ�������
            if(board[r][i]=='\0')kill[r][i]+=1;
            else break;
	}
	for(int i=c-1;i>=1;i--)//������������
		if(board[r][i]!='\0'){
			c_pj=i;
			r_pj=r;
			break;
		}
	if(c_pj<c){//�ҵ��ڼ�
        for(int i=c_pj-1;i>=1;i--) //���ڼ�������
            if(board[r][i]=='\0')kill[r][i]+=1;
            else break;
	}
	for(int i=c+1;i<=10;i++)//������������
		if(board[i][c]!='\0'){
			c_pj=c;
			r_pj=i;
			break;
		}
	if(r_pj>r){//�ҵ��ڼ�
        for(int i=r_pj+1;i<=10;i++)//���ڼ�������
		if(board[i][c]=='\0')kill[i][c]+=1;
		else break;
	}
	for(int i=c-1;i>=1;i--)//������������
		if(board[i][c]!='\0'){
			c_pj=c;
			r_pj=i;
			break;
		}
	if(r_pj<r){//�ҵ��ڼ�
        for(int i=r_pj-1;i>=1;i--)//���ڼ�������
		if(board[i][c]=='\0')kill[i][c]+=1;
		else break;
	}
}

//�췽���ɱ�˺���
void Hkill(int r,int c){
    if(board[r-1][c]=='\0' && r>=3 && c>=2 && c<=9){ //�������ߣ�������
        kill[r-2][c-1]+=1;
         kill[r-2][c+1]+=1;
    }
     if(board[r+1][c]=='\0' && r<=8 && c>=2 && c<=9){ //�������ߣ�������
        kill[r+2][c-1]+=1;
         kill[r+2][c+1]+=1;
    }
     if(board[r][c-1]=='\0' && r>=2 && r<=9 && c>=3){ //�������ߣ�������
        kill[r-1][c-2]+=1;
         kill[r+1][c-2]+=1;
    }
    if(board[r][c+1]=='\0' && r>=2 && r<=9 && c<=7){ //�������ߣ�������
        kill[r-1][c+2]+=1;
         kill[r+1][c+2]+=1;
    }

}

//��ʼ�����̺�ɱ������
void init(){
    memset(board,'\0',sizeof(board));
    memset(kill,0,sizeof(kill));
}

//�жϺڽ����˧�Ƿ�ֱ����ԡ����ֱ����ԣ���ڽ���ʤ��Ҳ�����ܱ�����
bool gface(int r,int c){
    return true;
}

//�жϺڷ����Ƿ񱻽�����r��c�Ǻڽ�������
//����Ҫ�жϺڽ��ĸ��ֿ����߷�
int judge(int r,int c){
    int life=0;
    if(r==2 && c==5){  //��˧��(2,5),��������8���߷�
        for(int i=0;i<4;i++)  //����8��λ��
            if(kill[gway25[i].r][gway25[i].c]==0) {
                life++;
                printf("move to %d,%d\n",gway25[i].r,gway25[i].c);
            }
    }
    else{
        int n=((r-1)*3+(c-4))*3;//����������ת��Ϊһά�������Ӧ�±�
        for(int i=0;i<3;i++)  //����3������λ��
            if(kill[gway[n+i].r][gway[n+i].c]==0){
                life++;
                printf("move to %d,%d\n",gway[n+i].r,gway[n+i].c);
            }
    }
    return life;
}

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
            if(board[i][j]=='\0')printf(" + ");
            else printf(" %c ",board[i][j]);
        printf("    %2d ",i);
        for(int j=1;j<=9;j++)
            printf(" %d ",kill[i][j]);
        printf("\n");
    }
}


int main(){
    int N,r_bg,c_bg;//����췽������������˧��λ������
    int gamenum=0;
    freopen("e0401.in","r",stdin);
    while(cin>>N>>r_bg>>c_bg  && N!=0){
        //printf("%d %d %d\n",N,r_bg,c_bg);
        gamenum++;
        init();
        for(int i=0;i<N;i++){ //����췽��������
            cin>>pieces[i].p>>pieces[i].r>>pieces[i].c;
            printf("%c %d %d \n",pieces[i].p,pieces[i].r,pieces[i].c);
            board[pieces[i].r][pieces[i].c]=pieces[i].p;
        }

        bool gface=true;
        for(int i=0;i<N;i++){//���ݺ췽�������ɿ�kill����
            switch(pieces[i].p){
                case'G':
                    if(pieces[i].c==c_bg){  //���ӽ�˧ֱ��������ж�
                        for(int j=pieces[i].r-1;j>r_bg;j--)
                            if(board[j][c_bg]!='\0'){ //����˧�м�������
                                gface=false;
                                break;
                            }
                    }
                    else gface=false;

                    Gkill(pieces[i].r,pieces[i].c);
                    break;
                case'R':
                    Rkill(pieces[i].r,pieces[i].c);
                    break;
                case'C':
                    Ckill(pieces[i].r,pieces[i].c);
                    break;
                case'H':
                    Hkill(pieces[i].r,pieces[i].c);
                    break;
            }
        }
        myprint();
        //if(gamenum>1)printf("\n");
        if(judge(r_bg,c_bg)==0 && !gface) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
