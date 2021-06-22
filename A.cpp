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

bool redundant(string s){
	stack <char> st;
	for (int i= 0; i < s.size(); i++){
		if (s[i] == '(' or s[i] == ')' or s[i] == '+' or s[i] == '-' or s[i] == '/' or s[i] == '*' ){
			if (!st.empty() and s[i] == ')' and st.top() == '('){
				return true;
			}

			if (!st.empty() and s[i] == ')' and (st.top() == '+' or st.top() == '-' or st.top() == '/' or st.top() == '*')){
				st.pop();
				st.pop();
			}else{
				st.push(s[i]);
			}
		}
	}

	if (st.empty()){
		return false;
	}else{
		return true;
	}
}
int main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s ;
	cin >> s;
	cout << redundant(s)<< endl;
	return 0;
}