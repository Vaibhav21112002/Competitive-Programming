#include <bits/stdc++.h>
using namespace std;

#define For(i,a,n) for(int i = a; i < n; i++)
#define case(n) while(n--)
#define ll long long int
#define vi vector <int>;
#define vs vector <string>;
#define vc vector <char>;
#define vpi vector <pair<int,int>>
#define mul multiset<int>
#define mulg multiset <int,greater<int>>
#define read(a) for(int i = 0; i < n; i++) cin >> a[i];
#define print(a) for(int i = 0; i < n; i++) cout << a[i] << " ";


void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt","w", stdout);
	#endif
}

ll a[1005][1005], b[1005][1005];
bool check(ll a[1005][1005],ll b[1005][1005], ll r, ll c){
	ll i,j;
	for (i = 0; i<r; i++){
		for (j = 0; j<c; j++){
			if (a[i][j] != b[i][j]){
				return false;
			}
		}
	}
	return true;
}
int main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll t,x,r,c;
	cin >> t;
	while(t--)
	{
		cin >> r >> c >> x;
		ll i,j,k,diff;
		for (i = 0; i < r; i++){
			for (j = 0; j<c; j++){
				cin >> a[i][j];
			}
		}
		for (i = 0; i < r; i++){
			for (j = 0; j<c; j++){
				cin >> b[i][j];
			}
		}

		if (r<x&&c<x){
			if (check(a,b,r,c)){
				cout << "Yes" << endl;
			}else{
				cout <<"No" << endl;
			}
		}else if (r < x){
			for (i = 0; i < r; i++){
				for (j = 0; j <= (c-x); j++){
					if (a[i][j] == b[i][j]){
						continue;
					}else{
						diff = (b[i][j] - a[i][j]);
						a[i][j] += diff;
						k = 1;
						while(k < x){
							a[i][j+k] += diff;
							k++;
						}
					}
				}
			}
			if (check(a,b,r,c)){
				cout << "Yes" << endl;
			}else{
				cout << "No" << endl;
			}
		}else if (c<x){
			for (i = 0; i < c; i++){
				for (j = 0; j <= (r-x); j++){
					if (a[j][i] == b[j][i]){
						continue;
					}else{
						diff = (b[j][i] - a[j][i]);
						a[j][i] += diff;
						k = 1;
						while(k < x){
							a[j+k][i] += diff;
							k++;
						}
					}
				}
			}
			if (check(a,b,r,c)){
				cout << "Yes" << endl;
			}else{
				cout << "No" << endl;
			}
		}else if (c >=x && r>= x){
			for (i = 0; i < r; i++){
				for (j = 0; j <= (c-x); j++){
					if (a[i][j] == b[i][j]){
						continue;
					}else{
						diff = b[i][j] - a[i][j];
						a[i][j] += diff;
						k = 1;
						while(k<x){
							a[i][j+k] += diff;
							k++;
						}
					}
				}
			}

			for (i = 0; i < c; i++){
				for (j = 0; j <= (r-x); j++){
					if (a[j][i] == b[j][i]){
						continue;
					}else{
						diff = (b[j][i] - a[j][i]);
						a[j][i] += diff;
						k = 1;
						while(k < x){
							a[j+k][i] += diff;
							k++;
						}
					}
				}
			}
			if (check(a,b,r,c)){
				cout << "Yes" << endl;
			}else{
				cout << "No" << endl;
			}	
		}
	}
	return 0;
}