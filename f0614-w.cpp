
  1 #include<cstdio>
  2 #include<cstring>
  3 #include<vector>
  4 #include<queue>
  5 using namespace std;
  6 
  7 struct Node {
  8   int r, c, dir; // 位于(r,c)朝向dir(0~3表示四个方向N, E, S, W)
  9   Node(int r=0, int c=0, int dir=0):r(r),c(c),dir(dir) {}
 10 };
 11 
 12 const int maxn = 10;
 13 const char* dirs = "NESW"; // 顺时针旋转。 
 14 const char* turns = "FLR";//“三种转弯方式”。 
 15 
 16 int has_edge[maxn][maxn][4][3];// 表示当前状态（r，c，dir），是否可以沿着转弯方向[trun]行走。 
 17 int d[maxn][maxn][4];          //表示初始状态到（r，c，dir）的最短路长度。 
 18 Node p[maxn][maxn][4];          //同时用p[r][c][dir]保存了状态(r, c, dir)在BFS树中的父结点。 
 19 int r0, c0, dir, r1, c1, r2, c2;
 20 
 21 //把四个方向和3种“转弯方式”编号0~3和0~2. 
 22 int dir_id(char c) { return strchr(dirs, c) - dirs; }
 23 int turn_id(char c) { return strchr(turns, c) - turns; }
 24 //用于转弯。 
 25 const int dr[] = {-1, 0, 1, 0};
 26 const int dc[] = {0, 1, 0, -1};
 27 
 28 Node walk(const Node& u, int turn) { 
 29   int dir = u.dir;                    //直行， 方向不变 
 30   if(turn == 1) dir = (dir + 3) % 4; // 逆时针 ，转向 
 31   if(turn == 2) dir = (dir + 1) % 4; // 顺时针 ，转向 
 32   return Node(u.r + dr[dir], u.c + dc[dir], dir);//下一步可能的状态 
 33 }
 34 
 35 //判断是否出界 
 36 bool inside(int r, int c) {
 37   return r >= 1 && r <= 9 && c >= 1 && c <= 9;
 38 }
 39 
 40 //读取r0，c0，dir，并计算出r1，c1， 然后读入has_edge数组。 
 41 bool read_case() {
 42   char s[99], s2[99];
 43   if(scanf("%s%d%d%s%d%d", s, &r0, &c0, s2, &r2, &c2) != 6) return false;
 44   printf("%s\n", s);
 45 
 46   dir = dir_id(s2[0]);
 47   r1 = r0 + dr[dir];
 48   c1 = c0 + dc[dir];
 49 
 50   memset(has_edge, 0, sizeof(has_edge));
 51   for(;;) {
 52     int r, c;
 53     scanf("%d", &r);
 54     if(r == 0) break;
 55     scanf("%d", &c);
 56     while(scanf("%s", s) == 1 && s[0] != '*') {
 57       for(int i = 1; i < strlen(s); i++)
 58         has_edge[r][c][dir_id(s[0])][turn_id(s[i])] = 1;
 59     }
 60   }
 61   return true;
 62 }
 63 
 64 void print_ans(Node u) {
 65   // 从目标结点逆序追溯到初始结点。 
 66   vector<Node> nodes;
 67   for(;;) {
 68     nodes.push_back(u);
 69     if(d[u.r][u.c][u.dir] == 0) break;
 70     u = p[u.r][u.c][u.dir];
 71   }
 72   nodes.push_back(Node(r0, c0, dir));
 73 
 74   //打印解， 每行 10 个。 
 75   int cnt = 0;
 76   for(int i = nodes.size()-1; i >= 0; i--) {
 77     if(cnt % 10 == 0) printf(" ");
 78     printf(" (%d,%d)", nodes[i].r, nodes[i].c);
 79     if(++cnt % 10 == 0) printf("\n");
 80   }
 81   if(nodes.size() % 10 != 0) printf("\n");
 82 }
 83 
 84 //BFS主过程。 
 85 void solve() {
 86   queue<Node> q;
 87   memset(d, -1, sizeof(d));
 88   Node u(r1, c1, dir);
 89   d[u.r][u.c][u.dir] = 0;
 90   q.push(u);
 91   while(!q.empty()) {
 92     Node u = q.front(); q.pop();
 93     if(u.r == r2 && u.c == c2) { print_ans(u); return; }//到达目的地 
 94     for(int i = 0; i < 3; i++) {//所有可能的转向，（直行，逆时针转， 顺时针转） 
 95       Node v = walk(u, i);      //下一步的状态 
 96       if(has_edge[u.r][u.c][u.dir][i] && inside(v.r, v.c) && d[v.r][v.c][v.dir] < 0) {//分别判断
 97                 //从这一步是否可以达到下一步，下一步是否出界， 下一步是否被走过（同方向）。 
 98         d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;//最短长度加 1. 
 99         p[v.r][v.c][v.dir] = u;//记录父结点。 
100         q.push(v);  
101       }
102     }
103   }
104   printf("  No Solution Possible\n");//走了所有可以走的可能， 无法到达终点。 
105 }
106 
107 int main() {
108   while(read_case()) {
109     solve();
110   }
111   return 0;
112 }