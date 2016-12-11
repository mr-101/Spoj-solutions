#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define M 1000005
#define N 100005
#define EPS 1e-9
#define OO 200000
#define pb push_back

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const double pi = acos(-1);

//aggressive_cows-spoj #binary_search
//Ahmad-khalid   // mr-101

int T , n , c;

bool ok(int num , int arr[]) {
	int pos = arr[0] , cnt = 1;
	for(int i = 1; i < n; i++) {
		if((arr[i] - pos) >= num) { 
			cnt++;
			pos = arr[i];

			if(cnt == c)
				return true;
		}
	}
	return false;
}

int bs(int arr[]) {
	int lo = 0 , hi = arr[n-1] , ans = -1;
    
    while(lo < hi) {
    	int mid = lo + (hi - lo)/2;
    	if(ok(mid , arr)) {
    		if(mid > ans)
    			ans = mid;

    		lo = mid + 1;
    	}
    	else
    		hi = mid;
    }
    return ans;
}
int main() {
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
  #else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
  #endif

    scanf("%d" , &T);
    while(T--) {
    	scanf("%d%d" , &n , &c);
        
        int arr[n];
    	for(int i = 0; i < n; i++) 
    		scanf("%d" , &arr[i]);

    	sort(arr , arr+n);

        int a = bs(arr);
        printf("%d\n", a);

        //memset(arr , 0 , sizeof arr);
    }
   	return 0;
}