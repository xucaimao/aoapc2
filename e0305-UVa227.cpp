//算法竞赛入门经典第二版 习题3-5 UVa227 谜题
//write by xucaimao,20161113,20：30开始;20161118,22：58测试通过
//fgets()会把\n读入，计算数组长度
//getchar()对’\n‘，’\r‘的处理需要谨慎
//另外本题对输出格式的要求比较严格，需要注意
//每行字符之间需要有空格，行首行尾不能有空格。
//每个puzzle之间用空行分开，但首尾不能有多余的空行。

#include<cstdio>
#include<cstring>

const int MAXN=100005;
char pz[5][7];  //谜题
char ord[MAXN];  //指令


//读入数据网格
int readpz()
{
    fgets(pz[0],7,stdin);  //读入谜题第一行，7就是把\n 和\0的长度都加进去的结果。
    if(pz[0][0]=='Z') return 1;
    for(int i=1;i<5;i++)
        fgets(pz[i],7,stdin); //读入谜题后四行
    return 0;
}

void readord()
{
    int i=0,ch;
    while((ch=getchar())!='0'){ //读入指令序列，滤掉'\n','\r'和'0'
        if(ch!='\n' && ch!='\r')
            {ord[i]=ch;i++;}
    }
    ord[i]='\0';//增加字符串结尾标志，便于后期编程
    getchar();//读入行尾的\n,否则会对后面的输入造成影响
}

int puzzle()
{
    int rs=0,cs=0;//定义空格的位置坐标
    for(int i=0;i<5;i++)  //查找空格的位置
        for(int j=0;j<5;j++)
            if(pz[i][j]==' '){
                rs=i;
                cs=j;
                break;
            }

    int err=0;  //定义非法指令状态，针对每一次游戏都做初始化
    int len=strlen(ord);
    for(int i=0;i<len && !err;i++){  //处理指令
        switch(ord[i]){
            case 'A':
                if(rs-1<0) {err=1;break;}
                else {pz[rs][cs]=pz[rs-1][cs];pz[rs-1][cs]=' ';rs--;}
                break;
            case 'B':
                if(rs+1>4) {err=1;break;}
                else {pz[rs][cs]=pz[rs+1][cs];pz[rs+1][cs]=' ';rs++;}
                break;
            case 'L':
                if(cs-1<0) {err=1;break;}
                else {pz[rs][cs]=pz[rs][cs-1];pz[rs][cs-1]=' ';cs--;}
                break;
            case 'R':
                if(cs+1>4) {err=1;break;}
                else {pz[rs][cs]=pz[rs][cs+1];pz[rs][cs+1]=' ';cs++;}
                break;
            default:
                {err=1;break;}
        }//end of swith
    } //end for一行指令处理结束
    return err;
}

int main()
{
    freopen("e0305.in","r",stdin);
    int pn=0;  //定义游戏次数
    for(;;){
        if(readpz()==1) break;
        pn++;
        readord();
        int err=puzzle();  //定义非法指令状态，针对每一次游戏都做初始化

        //开始输出
        if(pn>1)printf("\n");
        printf("Puzzle #%d:\n",pn);
        if(err) printf("This puzzle has no final configuration.\n");
        else {
            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    if(j>0) printf(" ");
                    printf("%c",pz[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}

