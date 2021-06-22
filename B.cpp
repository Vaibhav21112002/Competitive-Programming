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
typedef multiset<int> s;
typedef multiset<int,greater<int>> sg;	 

void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt","w", stdout);
	#endif
}

void solve()
{
	int r,c;
	cin >> r >> c;
	int a[r][c];
	For(i,0,r){
		For(j,0,c){
			cin >> a[i][j];
		}
	}
	int count = 0;
	For(i,0,r){
		For(j,0,c){
			int n = 0,e = 0,w = 0,s = 0;
			for (int h = j; h  < c; h++){
				if (a[i][h] == 1){
					e ++;
				}else{
					break;
				}
				// cout << e << endl;
			}

			for (int h = j; h  >= 0; h--){
				if (a[i][h] == 1){
					w ++;
				}else{
					break;
				}
			}
			for (int h = i; h  >= 0; h--){
				if (a[h][j] == 1){
					e ++;
				}else{
					break;
				}
			}
			for (int h = i; h  < r; h++){
				if (a[h][j] == 1){
					s ++;
				}else{
					break;
				}
			}

			if ((n >= 2*e or e >= 2*n) and (e > 1 and n > 1)){
				count ++;
			}

			if (n >= 2*e or w >= 2*n and (w > 1 and n > 1)){
				count ++;
			}
			if (w >= 2*e or s >= 2*n and (w > 1 and s > 1)){
				count ++;
			}
			if (s >= 2*e or e >= 2*n and (e > 1 and s > 1)){
				count ++;
			}

			
		}
	}

	cout << count << endl;


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
		solve();
	}
	return 0;
}