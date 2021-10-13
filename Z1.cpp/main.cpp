#include <bits/stdc++.h>
using namespace std;

#define ll double
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define all(v) v.begin(),v.end()
#define inp(x) for(auto &inps: x) cin>>inps
#define zr(a) memset(a,0,sizeof(a))
#define mod 1000000007
#define smod 10001

const int mxN = 2e5+1;
int dp[mxN];

int main()
{
    int n; cin >> n;
    vi v(n); inp(v);
    dp[0] = 1;
    for(int i = 1; i<n; i++){
        dp[i] = 1;
        for(int j = 0; j<i; j++){
            if(v[i] > v[i-1]){
                dp[i] = max(dp[i], dp[i-1]+1);
            }
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}

