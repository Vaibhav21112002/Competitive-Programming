#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define vb vector<bool>
#define vll vector<ll>
#define vc vector<char>
#define pii pair<int,int>
#define pci pair<char,int>
#define vpii vector<pii>
#define mpii map<int,int>
#define mpci map<char,int>
#define pqi priority_queue<int,vi>
#define pqmi priority_queue<int,vi,greater<int>>
#define qi queue<int>
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
#define arrsort(a,n) sort(a,a+n)
#define mod 1000000007
#define smod 10001

int dp[smod][smod];

int main()
{
    int n; cin >> n;
    set<vector<int>> s;
    for(int i = 0; i<n; i++){
        int a,b; cin >> a >> b;
        s.insert({2*a, 1});
        s.insert({2*b+1, -1});
    }
    int ans =0, c = 0;
    vector<int> v;
    for(auto i:s){
        c += i[1];
        if(i[1]==1){
            v.push_back(c);
        }
        ans = max(c,ans);
    }

    cout << ans << endl;
    for(auto i:v)cout << i << " ";
    return 0;
}
