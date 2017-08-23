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

int k , n;
int dp[2][2*M] , w[505] , val[505];

int main() {
      cin.tie(0);
      ios::sync_with_stdio(false);
      
      cin >> k >> n;
      for(int i = 0; i < n; ++i)
            cin >> val[i] >> w[i];

      dp[0][0] = dp[1][0] = 0;
      int p = 1;
      for(int i = n-1; i >= 0; --i) {
            p = !p;
            for(int j = k; j >= 0; --j) 
                  dp[p][j] = max(dp[!p][j] , j >= w[i]? dp[!p][j-w[i]] + val[i] : 0);            
      }
      cout << max(dp[0][k] , dp[1][k]) << endl;
      return 0;
}
