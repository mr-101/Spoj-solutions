#include <bits/stdc++.h>
 
#define ll long long
#define pb push_back
#define mp make_pair
#define fs first
#define sz(s) (int)s.size()
#define sec second
#define all(x) x.begin(), x.end()

using namespace std;
 
typedef pair<int,int> ii;
typedef pair<ll,ll> lii;
typedef vector<int> vi;
typedef vector<ii> vii;
const double pi = acos(-1);

const int N = 1e4+5, M = 2e5+5;
int head[N], nxt[M], to[M], vis[N], n, ne;

void init() {
    ne = 0;
    memset(head, -1, n*sizeof head[0]);
}

void addEdge(int f, int t) {
    to[ne] = t;
    nxt[ne] = head[f];
    head[f] = ne++;
}

void addBi(int a, int b) {
    addEdge(a, b);
    addEdge(b, a);
}

void dfs(int u) {
    vis[u] = 1;
    for(int e = head[u]; ~e; e = nxt[e]) {
        int v = to[e];
        if(!vis[v]) dfs(v);
    }
}

int main() { 
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
        freopen("out.in", "w", stdout);
    #endif
    int m, a, b;
    scanf("%d%d", &n, &m);
    init();
    if(n != m+1) return puts("NO"), 0;
    while(m--) {
        scanf("%d%d", &a, &b);
        addBi(a, b);
    }
    dfs(1);
    for(int i = 2; i <= n; ++i) 
        if(!vis[i]) return puts("NO"), 0;
    puts("YES");

    return 0;
}

