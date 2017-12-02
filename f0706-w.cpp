/*算法竞赛入门经典第二版 例题7-6 UVa140 带宽 网络程序
这题有些小技巧可以简化代码的编写。
本题的实现参考了刘汝佳老师的源码，的确给了我许多启发，感谢刘老师。
思路：

    1.建立双射关系：从字符A到字符Z遍历输入的字符串，用strchr函数将输入中出现的字符找出，并将找
    出的字符进行编号，用letter和id分别存储字符和对应的编号
    2.降维：输入中给出的，是类似于邻接表形式的二维形式，如果我们用二维数据结构，将增加处理时对于
    输出细节的处理难度，用 2个 vector将输出降低到1维，简化了计算Bandwidth时的代码，实际上让我
    们更加有的放矢
    3.存储必要信息——位置：数组pos每个下标代表字母编号，存储的是对应的位置下标，便于计算时寻找位置。
    剪枝：减去不必要的计算(虽然对于本题而言不是必须的)
    库函数的使用：memcpy，strchr，strlen，next_permutation的使用简化了代码，突出了逻辑部分。

*/

#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm> 
using namespace std;

const int maxn=10,inf=0x7fffffff;
char letter[maxn], s[100];//出现的字母,输入序列 
int id[256]; //字母的编号 
int p[maxn]; //全排列的遍历数组 ,存储的是每个字母的编号 
int pos[maxn];//记录每个字母的位置，避免频繁使用strchr 

int main(){
    while(scanf(" %s",&s),s[0]!='#'){
        int len=strlen(s),n=0;
        for(char ch='A';ch<='Z';ch++)if(strchr(s,ch)!=NULL){
            letter[n]=ch;
            id[ch]=n++;
        }
        vector<int> u,v;
        for(int i=0;i<len;i++){
            int t=i;//记录起始节点 
            i+=2;
            while(i<len && s[i]!=';'){
                u.push_back(id[s[t]]);//加入起始节点 
                v.push_back(id[s[i]]);//加入起始节点的相邻节点 
                i++;
            }
        }
        //遍历+剪枝
        int bandwidth=0,res=inf;
        int bestP[maxn];//存储最终结果 
        for(int i=0;i<n;i++)p[i]=i;
        do{
            bandwidth=0;//初始化别忘了 
            for(int i=0;i<n;i++)pos[p[i]]=i;//记录编号为pi的节点的位置 
            for(int i=0;i<u.size();i++){
                bandwidth=max(bandwidth,abs(pos[u[i]]-pos[v[i]]));
                if(bandwidth>=res)break;//剪枝
            }
            if(bandwidth<res){
                memcpy(bestP,p,sizeof(p));//memcpy比较快 
                res=bandwidth;
            }
        }while(next_permutation(p,p+n));
        for(int i=0;i<n;i++)printf("%c ",letter[bestP[i]]);
        printf("-> %d\n",res);
    }
}