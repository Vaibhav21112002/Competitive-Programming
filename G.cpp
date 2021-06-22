#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int i = a; i < n; i++)
#define ll long long int
#define read(a) for(int i = 0; i < n; i++) cin >> a[i];
#define print(a) for(int i = 0; i < n; i++) cout << a[i] << " ";
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
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
#define pu push
#define po pop
#define pob pop_back
#define pof pop_front
#define br cout<<"\n";
#define mod 1000000007
#define smod 100000

vi adj[smod];
bool vis[smod];
void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt","w", stdout);
	#endif
}
void solve()
{
	int n ,m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++){
		vis[i] = 0;
	}
	rep(i,0,m){
		int x,y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	qi q;
	q.push(1);
	vis[1]= true;
	while(!q.empty()){
		int node = q.front();
		q.po();
		cout << node; br
		vi :: iterator it;
		for (it = adj[node].begin(); it != adj[node].end(); ++it){
			if (!vis[*it]){
				vis[*it] = true;
				q.push(*it);
			}
		}
	}
}
int main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 1;
}