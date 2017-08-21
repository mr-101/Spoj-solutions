/*
spoj - PIGBANK - Piggy-Bank
unbounded knapsack - dynamic programming
*/

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

int t , n , e , f;
int w[505] , val[505] , dp[505][10005];

int solve(int i , int rem) {
      if(i == n) 
            return rem != 0? (int)1e9 : 0;

      if(dp[i][rem] != -1)
            return dp[i][rem];

      int s1 = solve(i+1 , rem);
      int s2 = (int)1e9;

      if(rem >= w[i])
            s2 = solve(i , rem - w[i]) + val[i];

      return dp[i][rem] = min(s1 , s2);
}

int main() {
      #ifndef ONLINE_JUDGE
            freopen("in.in", "r", stdin);
            freopen("out.in", "w", stdout);
      #endif
      cin >> t;
      while(t--) {
            memset(dp , -1 , sizeof dp);
            cin >> e >> f;
            cin >> n;
            for(int i = 0; i < n; ++i)
                  cin >> val[i] >> w[i];
            int ans = solve(0 , f-e);
            if(ans == (int)1e9)
                  puts("This is impossible.");
            else 
                  printf("The minimum amount of money in the piggy-bank is %d.\n" , ans);
      }
      return 0;
}
