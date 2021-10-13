/*
* author : Vaibhav Gupta
*/


#include <bits/stdc++.h>
#include <chrono> 
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
using namespace chrono;

//template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag ,  tree_order_statistics_node_update >;

#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define read(x) for(auto &inps: x) cin>>inps
#define all(v) v.begin(),v.end()

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)

const int mod = 1e9+7;
const int smod = 1e5+1;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

bool isPowerOfTwo(ll n) {return!(n&&(n&(n-1)));}
int setBits(ll n){ll ans = 0; while(n>0){n = (n&(n-1)); ans++; } return ans; }

void init_code(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r", stdin);
  freopen("output.txt","w", stdout);
  #endif
}

vector<vll> edges;

// <----------DSU IMPLEMENTATION----------------->
vector<ll> parent(smod);
vector<ll> sz(smod);

void make_set(ll n){
  parent[n]= n;
  sz[n] = 1;
}

ll find_set(ll a){
  if(a == parent[a]){
    return a;
  }

  return parent[a] = find_set(parent[a]);
}

void union_sets(ll a,ll b){
  a = find_set(a);
  b = find_set(b);
  if(a!=b){
    if(sz[a]<sz[b]) swap(a,b);
    parent[b] = a;
    sz[a] += sz[b];
  }
}
// <----------DSU IMPLEMENTATION ENDS----------------->
vector<vll> edd;
//<---------GRAPH ALOGORITHMS------------>
void kruskals(ll &cost){
  for(ll i = 0; i<smod; i++){
    make_set(i);
  }
  sort(edges.begin(),edges.end(),[&](vector<ll> a, vector<ll> b){
    return a[2]<=b[2];
  });
  for(auto i:edges){
    ll u = i[0]; ll v = i[1]; ll w = i[2];
    ll x = find_set(u); ll y = find_set(v);
    if(x==y){
      continue;
    }else{ 
      // cout << u << " " << v << endl;
      edd.push_back({u,v});
      cost += w;
      union_sets(u,v);
    }
  }
}

// <--------- GRAPH ALOGORITHM ENDS------------------->

void solve()
{
    ll n,m; cin >> n >> m;
    for(ll i = 0; i<m; i++){
        ll u,v,w; cin >> u >> v >> w;
        edges.pb({u,v,w});
    }

    ll cost = 0;
    kruskals(cost);
    if(edd.size()!=n-1){
        cout << "IMPOSSIBLE" << endl;
    }else
    cout << cost << endl;
}

int main()
{
    init_code();
    auto start = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    float timeCount = duration.count();
    timeCount /= 1000000;
    debug("Time Taken",timeCount);
    return 0;
}