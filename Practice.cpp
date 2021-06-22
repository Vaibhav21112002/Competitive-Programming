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

// void solve() { }


struct node{
public:
	int data;
	node* left;
	node* right;

	node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};
void preorder(struct node* root){
	if (root != NULL){
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(struct node* root){
	if (root != NULL){
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}
void postorder(struct node* root){
	if (root != NULL){
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
}
void levelorder(struct node* root)
{
	if (root == NULL)
	{	
		return;
	}

	queue <node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node* n = q.front();
		q.pop();
		if (n != NULL)
		{
			cout << n->data << " ";
			if (n->left){
				q.push(n->left);
			}

			if (n->right){
				q.push(n->right);
			}
		}
		else if (!q.empty()){
			q.push(NULL);
		}
	}
}
int search(vector<int> a, int st, int end, int curr){
	for (int i = st; i<= end; i++){
		if (a[i] == curr){
			return i;
		}
	}

	return -1;
}
node* buildTreeFromPreAndIn(vector<int> a, vector<int>b,int st,int end){
	static int idx = 0;
	if (st > end){
		return NULL;
	}
	int curr = a[idx];
	idx ++;
	node* root = new node(curr);
	if (st == end){
		return root;
	}
	int pos = search(b,st,end,curr);
	root->left = buildTreeFromPreAndIn(a,b,st,pos-1);
	root->right = buildTreeFromPreAndIn(a,b,pos+1,end);

	return root;
}
vector<int> nodes;
int countnode(node* root){	
	if (root != NULL){
		nodes.push_back(root->data);
		countnode(root->left);
		countnode(root->right);
	}

	return nodes.size();
}

int sumnode(node* root){	
	if (root != NULL){
		nodes.push_back(root->data);
		countnode(root->left);
		countnode(root->right);
	}

	int s = 0;
	for (auto &i: nodes){
		s += i;
	}

	return s;
}

int height(node* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int lh = height(root->left);
	int rh = height(root->right);

	return max(lh,rh) + 1;
}

int diameter(node* root)
{
	if (root == NULL)
	{
		return 0;
	}


	int lh = height(root->left);
	int rh = height(root->right);
	int curd = lh+rh+1;

	int ld = diameter(root->left);
	int rd = diameter(root->right);

	return max(curd,max(ld,rd));
}
bool balanced(node* root){
	
	if (root != NULL){
		if (balanced(root->left) == false or balanced(root->right) == false){
			return false;
		}

		balanced(root->left);
		balanced(root->right);
	}

	return true;
}
void rightview(struct node* root)
{
	if (root == NULL){
		return;
	}

	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		int n = q.size();
		for (int i = 0; i < n; i++){
			node* curr = q.front();
			q.pop()

			if (i == n-1){
				cout<< curr->data << " ";
			}

			if (curr->left != NULL){
				q.push(curr->left);
			}

			if (curr->right != NULL){
				q.push(curr->right);
			}
		}
	}
}


node* searchInBST(node* root, int key)
{
	if (root == NULL)
	{
		return root;
	}
	if (root->data == key)
	{
		return root;
	}

	if (root->data<key)
	{
		return searchInBST(root->right,key);
	}

	if (root->data>key)
	{
		return searchInBST(root->left,key);
	}

	return root;
}

bool validBst(node* root){
	if (root != NULL){
		if ((root->data > root->left->data) && (root->data < root->right->data)&& validBst(root->right)&& validBst(root->left)){
			return "YES";
		}else{
			return "NO";
		}
	}
}
int main()
{
	// CJJ
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	// solve();

	node* root = new node(3);
	root->left = new node(2);
	root->right = new node(7);
	root->left->left = new node(1);
	root->right->left = new node(5);
	root->right->right = new node(8);
	root->right->left->left = new node(4);
	root->right->left->right = new node(6);


	/*
                          3
                         / \
                        2   7
                       /   / \
                      1   5   8
                         /
                        4

	*/

	cout << validBst(root);

	return 0;
}

if (root == NULL){
            return true
        }
        if ((root->data > root->left->data) and (root->data < root->right->data) and isBST(root->left) and isBST(root->right)){
            return "YES";
        }
