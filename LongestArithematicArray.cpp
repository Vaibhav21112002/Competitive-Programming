#include <bits/stdc++.h>
using namespace std;

#define For(i,a,n) for(int i = a; i < n; i++)
#define case(n) while(n--)
#define ll long long int
#define read(a) for(int i = 0; i < n; i++) cin >> a[i];
#define print(a) for(int i = 0; i < n; i++) cout << a[i] << " ";

typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;
typedef pair<int,int> pi;

void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt","w", stdout);
	#endif
}
int main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	for (int hg = 1; hg <= t; ++hg){
		cout << "Case #" << hg << ": ";
		ll n,k;
		cin >> n >> k;
		vector <pair<ll,ll>> v;
		for (int i = 0; i < n; i++){
			pair <ll,ll> p;
			cin >> p.first;
			cin >> p.second;
			v.push_back(p);
		}

		sort(v.begin(), v.end());
		ll ans = 0; 
		ll c = -1e9;
		pair<ll,ll> q;
		for (int i = 0; i <n ; i++){
			if (v[i].first - c >= k){
				if (i > 0 && v[i-1].first - q.first < k && v[i-1].first != q.first && v[i].second != q.second){
					ans += ((v[i-1].second-q.first)%k == 0)?(v[i-1].second-q.first)/k:((v[i-1].second-q.first)/k + 1);
				}
				ans  += ((v[i].second-v[i].first)%k == 0)?(v[i].second-v[i].first)/k:((v[i].second-v[i].first)/k + 1);
				q = {v[i].first,v[i].second};
				c = v[i].first;
			}
		}

		cout << ans << endl;
	}
	return 0;
}