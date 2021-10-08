#include <bits/stdc++.h>
#include <chrono> 
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
using namespace chrono;

#define ll long long int
#define vi vector<int>
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

const int mod = 1e9+7;
const int smod = 1e5+1;

//template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag ,  tree_order_statistics_node_update >;


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

vector<vector<int>> adj[smod+1];
vi dist(smod,mod);
vi parent(smod,-1);

//<---------GRAPH ALOGORITHMS------------>


void dik(int start){
    dist[start] = 0;
    set<vector<int>> s;
    s.insert({0,start});
    while(!s.empty()){
        auto x = *s.begin(); // {0,start}
        s.erase(x);
        for(auto i:adj[x[1]]){
            if(dist[i[0]] > i[1]+dist[x[1]] ){
                s.erase({dist[i[0]], i[0]});
                dist[i[0]] = dist[x[1]] + i[1];
                s.insert({dist[i[0]], i[0]});
                parent[i[0]] = x[1];
            }
        }
    }
}

// <--------- GRAPH ALOGORITHM ENDS------------------->

void solve()
{
    int n,m; cin >> n >> m;
    for(int i = 0; i<m; i++){
        int x,y; cin >> x >> y;
        adj[x].pb({y,1});
        adj[y].pb({x,1});
    }

    dik(1);
    if(dist[n] == mod){
        cout << "IMPOSSIBLE" << endl;
        return;
    }else{
        cout << dist[n]+1 << endl;
    }
    int cr = n;
    vi ans;
    for(int i = 0; i<dist[n]+1; i++){
        // cout << cr << " ";
        ans.pb(cr);
        assert(parent[cr]);
        cr = parent[cr];
    }
    reverse(all(ans));
    for(auto i:ans){
        cout << i << " ";
    }
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