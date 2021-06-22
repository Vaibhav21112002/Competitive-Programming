#include <bits/stdc++.h>
using namespace std;

#define For(i,a,n) for(int i = a; i < n; i++)
#define case(n) while(n--)
#define ll long long int
#define read(a) for(int i = 0; i < n; i++) cin >> a[i];
#define print(a) for(int i = 0; i < n; i++) cout << a[i] << " ";
#define lb cout<<"\n";

typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;
typedef pair<int,int> pi;

void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt","w", stdout);
	#endif
} 

struct node{
	int data;
	node* left;
	node* right;

	node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};


void preorder(node* root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(node* root)
{
	if (root != NULL)
	{
		
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}
void postorder(node* root)
{
	if (root != NULL)
	{
		
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
}
int nodenumber(node* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return (1 + nodenumber(root->left) + nodenumber(root->right));
}
int nodesum(node* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return (root->data + nodesum(root->left) + nodesum(root->right));
}

int height(node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int l = height(root->left);
	int r = height(root->right);
	return max(l,r) + 1;

}
int diameter(node* root){
	if (root==NULL){
		return 0;
	}
	int lh = height(root->left);
	int rh = height(root->right);
	int curr = lh+rh+1;
	return max(curr,max(diameter(root->right),diameter(root->left)));
}
void sumReplace(node* root){
	if (root == NULL){
		return;
	}
	sumReplace(root->left);
	sumReplace(root->right);

	if (root->left != NULL){
		root->data += root->left->data;
	}

	if (root->right != NULL){
		root->data += root->right->data;
	}
}

bool isBht(node* root){
	if (root == NULL){
		return true;
	}
	if (isBht(root->left)==false){
		return false;
	}

	if (isBht(root->right) == false){
		return false;
	}

	int lh = height(root->left);
	int rh = height(root->right);

	if (abs(lh-rh)<= 1){
		return true;
	}else{
		return false;
	}
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
			q.pop();

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

void leftview(struct node* root)
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
			q.pop();

			if (i == 0){
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
bool getpath(node* root, int n, vector<int> &p){
	if (root == NULL){
		return false;
	}

	p.push_back(root->data);
	if (root->data == n){
		return true;
	}

	if (getpath(root->left,n,p) || getpath(root->right,n,p)){
		return true;
	}

	p.pop_back();
	return false;
}
// void flatten(node* root){
// 	if (root == NULL or root->left == NULL and root->right == NULL)
// 	if (root->left != NULL){
// 		flatten(root->left);
// 		node* temp = root->right;
// 		root->right = root->left;
// 		root->left = NULL;
// 		node* tl = root->right;
// 		while(tl->right != NULL){
// 			tl = tl->right;
// 		}
// 		tl->right = temp;
// 	}
// 	flatten(tl->right);
// }
bool isInBST(node* root, int key){
	if (root != NULL){
		if (root->data == key){
			return true;
		}else{
			if (isInBST(root->left,key)||isInBST(root->right,key)){
				return true;
			}
		}

		
	}
	return false;
}
int main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	/*
				05
			   /  \
			  3    8
			 / \  / \
			2   4 7  9
		   /	   \  \
		  1         11 12 
	*/

	// Tree Contruction
	node* root = new node(5);
	root->left = new node(3);
	root->right = new node(8);	
	root->left->left = new node(2);
	root->left->right = new node(4);
	root->left->left->left = new node(1);
	root->right->left = new node(7);
	root->right->left->right = new node(11);
	root->right->right = new node(9);
	root->right->right->right = new node(12);
	// Tree Contruction Ends


	preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	postorder(root);
	cout << endl;
	cout << nodenumber(root) << endl;
	cout << nodesum(root) << endl;
	cout << height(root) << endl;
	cout << diameter(root) << endl;
	// sumReplace(root);
	// preorder(root);
	// cout << endl;
	cout << isBht(root) << endl;
	rightview(root);lb;
	leftview(root);lb;
	vector<int> p1,p2;
	if (getpath(root, 2,p1) && getpath(root, 4,p2)){
		for (int i = 0; i < p1.size() && p2.size(); i++){
			if (p1[i] != p2[i]){
				cout << p1.size()-i+p2.size() -i  << endl;
				break;
			}
		}
	}	
	cout <<  isInBST(root, 13) << endl;

	return 0;
}



// import java.util.*;
// import java.lang.*;
// import java.io.*;

// public class Main
// {
// 	public static void main (String[] args) throws java.lang.Exception
// 	{
// 		System.out.println("Hello World");
// 	}
// }
