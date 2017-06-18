#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

struct POS{ int r,c;};
int kill[11][10];

char board[11][10];
char boardswap[11][10];//����һ����ʱ���̣���������п��ܵĳ��Ӳ���

POS gway[36]={
{2,4},{1,5},{0,0},{0,0},   {1,4},{2,5},{1,6},{0,0},   {1,5},{2,6},{0,0},{0,0},  //��Ӧ(1,4)...(1,6)
{1,4},{2,5},{3,4},{0,0},   {1,5},{2,4},{2,6},{3,5},   {2,5},{1,6},{3,6},{0,0},  //��Ӧ(2,4)...(2,6)
{2,4},{3,5},{0,0},{0,0},   {3,4},{2,5},{3,6},{0,0},   {3,5},{2,6},{0,0},{0,0}   //��Ӧ(3,4)...(3,6)
 };
int r_bg,c_bg,r_bg_new,c_bg_new;//����ڽ���ԭʼλ�ã��������ߵ�����λ��

void Rkill(char bd[11][10],int r,int c){
	for(int i=c+1;i<=9;i++) //������������,ֱ��������һ������
		{kill[r][i]+=1;if(bd[r][i]!='\0')break;}
	for(int i=c-1;i>=1;i--)//������������
		{kill[r][i]+=1;if(bd[r][i]!='\0')break;}
	for(int i=r+1;i<=10;i++)//������������
        {kill[i][c]+=1;if(bd[i][c]!='\0')break;}
	for(int i=r-1;i>=1;i--)//������������
        {kill[i][c]+=1;if(bd[i][c]!='\0')break;}
}

void Gkill(char bd[11][10],int r,int c){
    for(int i=r-1;i>=1;i--)//������������,ֱ��������һ������
        {kill[i][c]+=1;if(bd[i][c]!='\0')break;}
}

void Ckill(char bd[11][10],int r,int c){
	bool pj;//�ڼ�״̬
	int c_pj=c,r_pj=r;//�ڼ�λ��,��ʼ��Ϊ�ڵ�λ��
	int dir_c=1,dir_r=1;//������ҵķ��򣬳�ʼ����
    if(r==r_bg_new){  //����ڽ�ͬ��
        if(c>c_bg_new) //���ڽ��Ҳ�,�������
            dir_c=-1;
        pj=false;//�ڼ�״̬
        for(int i=c+dir_c;i<=9 && i>=1;i+=dir_c) //������������ڼ�
            if(bd[r][i]!='\0'){
                c_pj=i;
                r_pj=r;
                pj=true;
                break;    //�ҵ��ڼܣ���¼λ�ò�����
            }
        if(pj)
            for(int i=c_pj+dir_c;i<=9 && i>=1;i+=dir_c)
                {kill[r][i]+=1;if(bd[r][i]!='\0') break;}
    }
    if(c==c_bg_new){  //����ڽ�ͬ��
        if(r>r_bg_new) //���ڽ��·�,���ϼ���
            dir_r=-1;
        pj=false;//�ڼ�״̬
        for(int i=r+dir_r;i<=10 && i>=1;i+=dir_r) //������������ڼ�
            if(bd[i][c]!='\0'){
                c_pj=i;
                r_pj=r;
                pj=true;
                break;    //�ҵ��ڼܣ���¼λ�ò�����
            }
        if(pj)
            for(int i=c_pj+dir_r;i<=9 && i>=1;i+=dir_r)
                {kill[i][c]+=1;if(bd[i][c]!='\0') break;}
    }

}

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

//���ںڽ��ƶ�λ�ú�������̣�����ɱ������
void initkill(char bd[11][10]){
    memset(kill,0,sizeof(kill));//��ʼ��
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

int movejudge(){
    int life=0;
    int n=((r_bg-1)*3+(c_bg-4))*4;
    for(int i=0;i<4;i++){   //����4������λ��
        memcpy(boardswap,board,sizeof(board));//����һ������
        r_bg_new=gway[n+i].r;  //�ڽ��ƶ�������λ��
        c_bg_new=gway[n+i].c;
        if(r_bg_new==0) break;  //����(0,0)��ǰ����ѭ��
        boardswap[r_bg][c_bg]='\0';
        boardswap[r_bg_new][c_bg_new]='g';  //�ƶ��ڽ��޸�����
        initkill(boardswap);
        if(kill[r_bg_new][c_bg_new]==0){
            life++;
        }
    }
    return life;
}

int main(){
    int N;//����췽������������˧��λ������
	int gamenum=0;
    freopen("e0401.in","r",stdin);
    while(cin>>N>>r_bg>>c_bg  && N!=0){
		gamenum++;
        memset(board,'\0',sizeof(board));//��ʼ������
        board[r_bg][c_bg]='g';//����ڽ�
        for(int i=0;i<N;i++){ //����췽��������
            int r,c;
            char p;
            cin>>p>>r>>c;

            board[r][c]=p;
        }

		if(gamenum>1) printf("\n");
        if(movejudge()==0) printf("YES");
        else printf("NO");
    }
    return 0;
}
