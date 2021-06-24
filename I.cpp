#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int i = a; i < n; i++)
#define ll long long int
#define read(a)               \
  for (int i = 0; i < n; i++) \
  cin >> a[i]
#define print(a)              \
  for (int i = 0; i < n; i++) \
  cout << a[i] << " "
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
#define visort(v) sort(v.begin(),v.end())
#define arrsort(a,n) sort(a,a+n)
#define br cout<<"\n";
#define mod 1000000007
#define smod 100006
vi adj[smod];
vvi edges;
bool vis[smod];
vi dfsvector;
int artree[smod]; int tree[4*smod];

bool isLetter(char c) { return (c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'Z');}
bool isUpperCase(char c) {return c >= 'A' and c <= 'Z';}
bool isLowerCase(char c) {    return c >= 'a' and c <= 'z';}
bool isDigit(char c) {return c >= '0' and c <= '9';}
bool isVowel(char c) {return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';}
bool isConsonant(char c){    return !isVowel(c); }
bool isPrime(ll n) {if(n<=1){return false; } if(n==2){return true; } for(int i = 2; i*i<=n; i++){if(n%i==0){return false; } } return true; }
bool isPowerOfTwo(ll n) {return!(n&&(n&(n-1)));}
int setBits(ll n){ll ans = 0; while(n>0){n = (n&(n-1)); ans++; } return ans; }

void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    #endif
}

void bfs(vi &bfsvector, int start){
  for(int i = 0; i < smod; i++){
    vis[i] = false;
  }

  qi q;
  q.push(start);
  bfsvector.pb(start);
  vis[start] = true;
  while(!q.empty()){
    int a = q.front();
    q.pop();
    for(auto x: adj[a]){
      if(!vis[x]){
        q.push(x);
        bfsvector.pb(x);
        vis[x] = true;
      }
    }
  }
}

void dfs(vi &dfsvector, int start){
  vis[start] = true;
  dfsvector.pb(start);
  for(auto i: adj[start]){
    if(!vis[i]){
      dfs(dfsvector,i);
    }
  }

}

void build(int node, int st, int end){
  if(st==end){
    tree[node] = artree[st];
    return;
  }

  int mid = (st+end)/2;
  build(2*node, st,mid);
  build(2*node+1,mid+1,end);

  tree[node] = tree[2*node] + tree[2*node+1];
}


vector<int> parent(smod);
vector<int> sz(smod);


void make_set(int n){
  parent[n]= n;
  sz[n] = 1;
}


int find_set(int a){
  if(a == parent[a]){
    return a;
  }

  return parent[a] = find_set(parent[a]);
}

void union_sets(int a,int b){
  a = find_set(a);
  b = find_set(b);
  if(a!=b){
    if(sz[a]<sz[b]) swap(a,b);
    parent[b] = a;
    sz[a] += sz[b]; 
  }
}

void kruskals(int &cost){
  sort(edges.begin(),edges.end(),[&](vector<int> a, vector<int> b){
    return a[2]<=b[2];
  });
  for(auto i:edges){
    int u = i[0]; int v = i[1]; int w = i[2];
    int x = find_set(u); int y = find_set(v);
    if(x==y){
      continue;
    }else{ 
      cout << u << " " << v << endl;
      cost += w;
      union_sets(u,v);
    }
  }
}

vi dist(smod);

void primsMST(int source,int &cost){
  for(int i = 0; i<n; i++){
    dist[i] = 1000000000;
  }

  dist[source] = 0;
  set<vector<int>> s;
  s.insert({0,source});
  while(!s.empty()){
    auto x = *s.begin();
    s.erase(x);
    vis[x[1]] = true;
    int u = x[1];
    int v = parent[x[1]];
    int w = x[0];
    cout << u << " " << v << " " << w << "\n";
    cost += w;
    for(auto it: edges[x[1]]){
      if(vis[it][0]){
        continue;
      }
      if(dist[it[0]]>it[1]){
        s.erase({dist[it[0]],it[0]});
        dist[it[0]] = it[1];
        s.insert({dist[]})
      }
    }
  }
}
void solve()
{
  for(int i = 0; i<smod; i++){
    make_set(i) ;
  }

  int  n,m; cin >> n >> m;
  
  for(int i = 0; i<m; i++){
    int u,v,w; cin >> u >> v>>w;
    edges.pb({u,v,w});
  }
  int cost = 0;
  primsMST(0,cost);
  cout << cost << endl;
}
int main()
{
  init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  solve();
  return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// #define rep(i,a,n) for(int i = a; i < n; i++)
// #define ll long long int
// #define read(a)               \
//   for (int i = 0; i < n; i++) \
//   cin >> a[i]
// #define print(a)              \
//   for (int i = 0; i < n; i++) \
//   cout << a[i] << " "
// #define vi vector<int>
// #define vvi vector<vi>
// #define vs vector<string>
// #define vb vector<bool>
// #define vll vector<ll>
// #define vc vector<char>
// #define pii pair<int,int>
// #define pci pair<char,int>
// #define vpii vector<pii>
// #define mpii map<int,int>
// #define mpci map<char,int>
// #define pqi priority_queue<int,vi>
// #define pqmi priority_queue<int,vi,greater<int>>
// #define qi queue<int>
// #define pb push_back
// #define pf push_front
// #define pob pop_back
// #define pof pop_front
// #define visort(v) sort(v.begin(),v.end())
// #define arrsort(a,n) sort(a,a+n)
// #define br cout<<"\n";
// #define mod 1000000007
// #define smod 100006
// vi adj[smod];
// vector<vector<pii>> graph(smod);
// vector<bool> vis(smod,0);
// vi dfsvector;
// int artree[smod]; int tree[4*smod];

// bool isLetter(char c) { return (c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'Z');}
// bool isUpperCase(char c) {return c >= 'A' and c <= 'Z';}
// bool isLowerCase(char c) {    return c >= 'a' and c <= 'z';}
// bool isDigit(char c) {return c >= '0' and c <= '9';}
// bool isVowel(char c) {return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';}
// bool isConsonant(char c){    return !isVowel(c); }
// bool isPrime(ll n) {if(n<=1){return false; } if(n==2){return true; } for(int i = 2; i*i<=n; i++){if(n%i==0){return false; } } return true; }
// bool isPowerOfTwo(ll n) {return!(n&&(n&(n-1)));}
// int setBits(ll n){ll ans = 0; while(n>0){n = (n&(n-1)); ans++; } return ans; }

// void init_code(){
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r", stdin);
//     freopen("output.txt","w", stdout);
//     #endif
// }



// void build(int node, int st, int end){
//   if(st==end){
//     tree[node] = artree[st];
//     return;
//   }

//   int mid = (st+end)/2;
//   build(2*node, st,mid);
//   build(2*node+1,mid+1,end);

//   tree[node] = tree[2*node] + tree[2*node+1];
// }

// //<---------GRAPH ALOGORITHMS------------>
// void bfs(vi &bfsvector, int start){
//   for(int i = 0; i < smod; i++){
//     vis[i] = false;
//   }

//   qi q;
//   q.push(start);
//   bfsvector.pb(start);
//   vis[start] = true;
//   while(!q.empty()){
//     int a = q.front();
//     q.pop();
//     for(auto x: adj[a]){
//       if(!vis[x]){
//         q.push(x);
//         bfsvector.pb(x);
//         vis[x] = true;
//       }
//     }
//   }
// }

// void dfs(vi &dfsvector, int start){
//   vis[start] = true;
//   dfsvector.pb(start);
//   for(auto i: adj[start]){
//     if(!vis[i]){
//       dfs(dfsvector,i);
//     }
//   }

// }


// // <----------DSU IMPLEMENTATION----------------->
// vector<int> parent(smod);
// vector<int> sz(smod);


// void make_set(int n){
//   parent[n]= n;
//   sz[n] = 1;
// }


// int find_set(int a){
//   if(a == parent[a]){
//     return a;
//   }

//   return parent[a] = find_set(parent[a]);
// }

// void union_sets(int a,int b){
//   a = find_set(a);
//   b = find_set(b);
//   if(a!=b){
//     if(sz[a]<sz[b]) swap(a,b);
//     parent[b] = a;
//     sz[a] += sz[b];
//   }
// }
// // <----------DSU IMPLEMENTATION ENDS----------------->
// // <--------- GRAPH ALOGORITHM ENDS------------------->
// const int INF = 1e9;
// void solve()
// {
//     int n,m; cin >> n >> m;
//     vi dist(n+1,INF);
//     for(int i = 0; i<m; i++){
//       int u,v,w; cin >> u>>v>>w;
//       graph[u].pb({v,w});
//       graph[v].pb({u,w});
//     }
//     int source; cin >> source;
//     dist[souce] = 0;
//     set<pair<int,int>> s;
//     s.insert({0,source});

//     while(!s.empty()){
//       auto x = *s.begin();
//       s.erase();

//     }

// }
// int main()
// {
//   init_code();
//   ios_base::sync_with_stdio(false);
//   cin.tie(0); cout.tie(0);
//   solve();
//   return 0;
// }