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

// void insertInHeap (vector<int> h, int x){
// 	h.push_back(x);
// 	int s = v.size();
// 	while(s > 0 && x > h[s/2]){
// 		swap(h[s],h[s/2]);
// 	}
// 	return ;
// }


int main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	vector <int> h;
	h.push_back(10);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		h.push_back(x);
		int s = h.size();
		while(s > 0 && x > h[s/2]){
			swap(h[s],h[s/2]);
		}
	}
	for(auto x : h){
		cout << x << " ";
	}
	return 0;
}