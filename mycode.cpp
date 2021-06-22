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

class tree{
public:
	int data;
	tree* left;
	tree* right;
	tree(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};

void preorder(tree* root){
	if (root != NULL){
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(tree* root){
	if (root != NULL){
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
}
void inorder(tree* root){
	if (root != NULL){
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}
int main()
{
	init_code();
	cout << ((2|0)^(2&65535)) ;
	return 0;
}




// int t;
	// cin >> t;
	// for (int j = 1; j<= t; j++){
	// 	int l,r;
	// 	cin >> l >> r;
	// 	cout << "Case #" <<j << ": ";
	// 	ll counter = 1;
	// 	while(max(l,r) >= counter){
	// 		if (l >= r){
	// 			l -= counter;
	// 		}else{
	// 			r -= counter;
	// 		}
	// 		counter++;
	// 	}

	// 	cout << counter-1 << " " << l << " " << r ;	
	// 	cout << endl;
	// }