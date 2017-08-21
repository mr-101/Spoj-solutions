#include <bits/stdc++.h>
 
#define ll long long
#define pb push_back
#define mp make_pair
#define fs first
#define sec second
#define N 100005
#define M 1000005
#define inf 1000000005
 
using namespace std;
 
typedef pair<int,int> ii;
typedef pair<ll,ll> lii;
typedef vector<int> vi;
typedef vector<ii> vii;
const double pi = acos(-1);
const ll mod = 1000000007;

int n;
int a[4500] , b[4500] , c[4500] , d[4500];
vi v1 , v2;
int main() {
      #ifndef ONLINE_JUDGE
            freopen("in.in", "r", stdin);
            freopen("out.in", "w", stdout);
      #endif
      scanf("%d" , &n);
      for(int i = 0; i < n; ++i)
            scanf("%d %d %d %d" , a+i , b+i , c+i , d+i);
      for(int i = 0; i < n; ++i) 
            for(int j = 0; j < n; ++j)
                  v1.pb(a[i] + b[j]);
      
      for(int i = 0; i < n; ++i) 
            for(int j = 0; j < n; ++j)
                  v2.pb(c[i] + d[j]);
      sort(v2.begin() , v2.end());
      ll ans = 0;
      for(int i = 0; i < (int)v1.size(); ++i) {
            ans += (upper_bound(v2.begin() , v2.end() , -v1[i]) - 
            lower_bound(v2.begin() , v2.end() , -v1[i]));
      } 
      printf("%lld\n" , ans);
      return 0;
}
