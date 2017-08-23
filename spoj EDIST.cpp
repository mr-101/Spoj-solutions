#include <bits/stdc++.h>
 
#define ll long long
#define pb push_back
#define mp make_pair
#define fs first
#define sec second
#define N 100005
#define M 1000005
#define inf 1000000005
#define mod 1000000007
 
using namespace std;
 
typedef pair<int,int> ii;
typedef pair<ll,ll> lii;
typedef vector<int> vi;
typedef vector<ii> vii;
const double pi = acos(-1);

int t , dp[2005][2005];
string s1 , s2;
int solve(int i , int j) {
      if(i == (int)s1.size())
            return (int)s2.size() - j;
      if(j == (int)s2.size())
            return (int)s1.size() - i;
      if(dp[i][j] != -1)
            return dp[i][j];
      if(s1[i] == s2[j])
            return solve(i+1 , j+1);
      int c1 = 0 , c2 = 0 , c3 = 0;
      c1 = solve(i+1 , j+1) + 1;
      c2 = solve(i+1 , j) + 1;
      c3 = solve(i , j+1) + 1;

      return dp[i][j] = min(c1 , min(c2 , c3));
}
int main() {
      cin.tie(0);
      ios::sync_with_stdio(false);

      #ifndef ONLINE_JUDGE
            freopen("in.in", "r", stdin);
            freopen("out.in", "w", stdout);
      #endif
      cin >> t;
      while(t--) {
            memset(dp , -1 , sizeof dp);
            cin >> s1 >> s2;
            cout << solve(0 , 0) << endl;
      }

      return 0;
}
