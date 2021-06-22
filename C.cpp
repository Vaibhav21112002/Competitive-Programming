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
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			cin >> a[i][j];
		}
	}
	int count = 0;
	for (int asd = 0; asd < r*c; asd++){
		int mx = -1;
		// pair<int,int> p= {0,0};
		int x ,y;
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				if (a[i][j] >= mx){
					x = i;
					y = j;
					mx = a[i][j];
				}
			}	
		}
		// int x = p.first, y = p.second;
		if (x == 0 and y == 0){
			if (a[x][y] >= a[x][y+1] and a[x][y+1] != -1){
				count += a[x][y]-a[x][y+1] - 1;
			}
			if (a[x][y] >= a[x+1][y] and a[x+1][y] != -1){
				count += a[x][y]-a[x+1][y] - 1;
			}

		}
		if (x == 0 and y == c-1){
			if (a[x][y] >= a[x][y-1] and a[x][y-1] != -1){
				count += a[x][y]-a[x][y-1] - 1;
			}
			if (a[x][y] >= a[x+1][y] and a[x+1][y] != -1){
				count += a[x][y]-a[x+1][y] - 1;
			}
		}
		if (x == r-1 and y == 0){
			if (a[x][y] >= a[x][y+1] and a[x][y+1] != -1){
				count += a[x][y]-a[x][y+1] - 1;
			}
			if (a[x][y] >= a[x-1][y] and a[x-1][y] != -1){
				count += a[x][y]-a[x-1][y] - 1;
			}
		}
		if (x == r-1 and y == c-1){
			if (a[x][y] >= a[x][y-1] and a[x][y-1] != -1){
				count += a[x][y]-a[x][y-1] - 1;
			}
			if (a[x][y] >= a[x-1][y] and a[x-1][y] != -1){
				count += a[x][y]-a[x-1][y] - 1;
			}
		}

		if (x == 0 and y > 0 and y < c-1){
			if (a[x][y] > a[x+1][y] and a[x+1][y] != -1){
				count+= a[x][y] - a[x+1][y];
			}
			if (a[x][y] > a[x][y+1] and a[x][y+1] != -1){
				count+= a[x][y] - a[x][y+1];
			}
			if (a[x][y] > a[x][y-1] and a[x][y-1] != -1){
				count+= a[x][y] - a[x][y-1];
			}
		}
		if (x == r-1 and y > 0 and y < c-1){
			if (a[x][y] > a[x-1][y] and a[x-1][y] != -1){
				count+= a[x][y] - a[x-1][y];
			}
			if (a[x][y] > a[x][y+1] and a[x][y+1] != -1){
				count+= a[x][y] - a[x][y+1];
			}
			if (a[x][y] > a[x][y-1] and a[x][y-1] != -1){
				count+= a[x][y] - a[x][y-1];
			}
		}
		if (y == 0 and x > 0 and x < r-1){
			if (a[x][y] > a[x+1][y] and a[x+1][y] != -1){
				count+= a[x][y] - a[x+1][y];
			}
			if (a[x][y] > a[x-1][y] and a[x-1][y] != -1){
				count+= a[x][y] - a[x-1][y];
			}
			if (a[x][y] > a[x][y+1] and a[x][y+1] != -1){
				count+= a[x][y] - a[x][y+1];
			}
		}
		if (y == 0 and x > 0 and x < r-1){
			if (a[x][y] > a[x+1][y] and a[x+1][y] != -1){
				count+= a[x][y] - a[x+1][y];
			}
			if (a[x][y] > a[x-1][y] and a[x-1][y] != -1){
				count+= a[x][y] - a[x-1][y];
			}
			if (a[x][y] > a[x][y-1] and a[x][y-1] != -1){
				count+= a[x][y] - a[x][y-1];
			}
		}

		if(x > 0 and y > 0 and x < r-1 and y < c-1){
			if (a[x][y] > a[x+1][y] and a[x+1][y] != -1){
				count+= a[x][y] - a[x+1][y];
			}
			if (a[x][y] > a[x-1][y] and a[x-1][y] != -1){
				count+= a[x][y] - a[x-1][y];
			}
			if (a[x][y] > a[x][y-1] and a[x][y-1] != -1){
				count+= a[x][y] - a[x][y-1];
			}
			if (a[x][y] > a[x][y+1] and a[x][y+1] != -1){
				count+= a[x][y] - a[x][y+1];
			}
		}
		a[x][y] = -1;
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