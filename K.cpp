#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int i = a; i < n; i++)
#define ll long long int
#define read(a)               \
  for (int i = 0; i < n; i++) \
  cin >> a[i]
#define print(a)              \
  for (int i = 0; i < n; i++) \
  cout << a[i] << " "
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define vb vector<bool>
#define vll vector<ll>
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
#define pob pop_back
#define pof pop_front
#define visort(v) sort(v.begin(),v.end())
#define arrsort(a,n) sort(a,a+n)
#define br cout<<"\n";
#define mod 1000000007
#define smod 100006
vi adj[smod];
bool vis[smod];
vi dfsvector;
int artree[smod]; int tree[4*smod];

bool isLetter(char c) { return (c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'Z');}
bool isUpperCase(char c) {return c >= 'A' and c <= 'Z';}
bool isLowerCase(char c) {    return c >= 'a' and c <= 'z';}
bool isDigit(char c) {return c >= '0' and c <= '9';}
bool isVowel(char c) {return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';}
bool isConsonant(char c){    return !isVowel(c); }
bool isPrime(ll n) {if(n<=1){return false; } if(n==2){return true; } for(int i = 2; i*i<=n; i++){if(n%i==0){return false; } } return true; }
bool isPowerOfTwo(ll n) {return!(n&&(n&(n-1)));}
int setBits(ll n){ll ans = 0; while(n>0){n = (n&(n-1)); ans++; } return ans; }

void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    #endif
}

struct Node{
public:
  int data;
  struct Node* left;
  struct Node* right;

  Node(int val){
    data = val;
    left = NULL;
    right = NULL;
  }

};

void preorder(Node* root){
  if(root==NULL){
    return;
  }

  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

void inorder(Node* root){
  if(root==NULL){
    return;
  }

  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

void postorder(Node* root){
  if(root==NULL){
    return;
  }

  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

int search(int in[], int start, int end, int curr){
  for(int i = start; i<=end; i++){
    if(in[start]==end) return i;
  }

  return -1;
}

Node* buildFromPreAndIn(int pre[], int in[], int start, int end){
  static int idx = 0;

  if(start>end){
    return NULL;
  }
  int curr = pre[idx];idx++;
  Node* node = new Node(curr);

  if(start == end){
    return node;
  }
  int pos = search(in,start,end,curr);
  node->left = buildFromPreAndIn(pre,in,start,pos-1);
  node->right = buildFromPreAndIn(pre,in,start+1,end);


  return node;

}


Node* levelorder(Node* root){
  if(root==NULL){
    return NULL;
  }

  queue<Node*> q;
  q.push(root); q.push(NULL);
  while(!q.empty()){
    Node* node = q.front();q.pop();
    if(node!=NULL){
      cout << node->data <<" ";
      if(node->left!=NULL){
        q.push(node->left);
      }
      if(node->right!=NULL){
        q.push(node->right);
      }
    }else if(q.empty()){
      q.push(NULL);
    }
  }
}


void countNode(Node* root,int &ans){
  if(root!=NULL){
    ans+=1;
    countNode(root->left,ans);
    countNode(root->right,ans);
  }
}
void sumNode(Node* root, int &ans){
  if(root!=NULL){
    ans+=(root->data);
    sumNode(root->left,ans);
    sumNode(root->right,ans);
  }
}

int treeHeight(Node* root){
  if(root==NULL){
    return 0;
  }

  int lh = treeHeight(root->left);
  int rh = treeHeight(root->right);

  return (max(lh,rh)+1);
}

int treeDiamter(Node* root){
  if(root==NULL){
    return 1;
  }

  int lh = treeHeight(root->left);
  int rh = treeHeight(root->right);
  int currDia = lh + rh + 1;
  int ld = treeDiamter(root->left);
  int rd = treeDiamter(root->right);


  return max(currDia,max(ld,rd));
}


Node* replaceSum(Node* root){
  if(root==NULL){
    return NULL;
  }
  replaceSum(root->left);
  replaceSum(root->right);

  if(root->left!=NULL){
    root->data+= root->left->data;
  }

  if(root->right!=NULL){
    root->data+= root->right->data;
  }

  return root;
}



bool isBalancedHeightTree(Node* root){
  if(root==NULL){
    return true;
  }

  bool ok1 = isBalancedHeightTree(root->left);
  bool ok2 = isBalancedHeightTree(root->right);

  int lh = treeHeight(root->left);
  int rh = treeHeight(root->right);

  return((abs(lh-rh)<=1)&&ok1&&ok2);
}

void rightViewOfBinaryTree(Node* root){
  if(root==NULL){
    return;
  }

  queue<Node*> q;
  q.push(root);
  // cout << root->data << " ";
  while(!q.empty()){
    int n = q.size();
    for(int i = 0; i<n; i++){
      Node* node = q.front();
      q.pop();
      if(i==n-1){
        cout << node->data <<" ";
      }
      if(node->left!=NULL){
        q.push(node->left);
      }
      if(node->right!=NULL){
        q.push(node->right);
      }
    }
  }
}

void leftViewOfBinaryTree(Node* root){
  if(root==NULL){
    return;
  }

  queue<Node*> q;
  q.push(root);
  // cout << root->data << " ";
  while(!q.empty()){
    int n = q.size();
    for(int i = 0; i<n; i++){
      Node* node = q.front();
      q.pop();
      if(i==0){
        cout << node->data <<" ";
      }
      if(node->left!=NULL){
        q.push(node->left);
      }
      if(node->right!=NULL){
        q.push(node->right);
      }
    }
  }
}

void flattenABinaryTree(Node* &root){
  if(root==NULL || (root->left==NULL && root->right==NULL)){
    return;
  }
  if(root->left!=NULL){
    flattenABinaryTree(root->left);
    Node* temp = root->right;
    root->right = root->left;
    root->left = NULL;
    Node* t = root->right;
    while(t->right!=NULL){
      t= t->right;
    }
    t->right = temp;
    
  }

  flattenABinaryTree(root->left);
}
bool checkBST(Node* root){
  if(root==NULL||(root->left==NULL && root->right==NULL)){
    return true;
  }

  bool ok1 = checkBST(root->left);
  bool ok2 = checkBST(root->right);
  bool ok3 = ((root->left!=NULL?(root->data>root->left->data):true)&&(root->right!=NULL?(root->data<root->right->data):true));
  return (ok1&&ok2&&ok3);
}
void solve()
{
    /*
        05
       /  \
      3    8
     / \  / \
    2   4 7  9
   /       \  \
  1         11 12 
  */

  // Tree Contruction
  Node* root = new Node(5);
  root->left = new Node(3);
  root->right = new Node(8);  
  root->left->left = new Node(2);
  root->left->right = new Node(4);
  root->left->left->left = new Node(1);
  root->right->left = new Node(7);
  root->right->left->right = new Node(11);
  root->right->right = new Node(9);
  root->right->right->right = new Node(12);
  preorder(root);br
  inorder(root);br
  postorder(root);br
  levelorder(root);br
  int ans = 0,ans1 = 0;
  countNode(root,ans);
  cout << ans << endl;
  sumNode(root,ans1);
  cout << ans1 << endl;
  cout << treeHeight(root) << endl;
  cout << treeDiamter(root) << endl;
  // preorder(replaceSum(root));br
  cout << isBalancedHeightTree(root) << endl;
  rightViewOfBinaryTree(root);br
  leftViewOfBinaryTree(root);br
  // flattenABinaryTree(root);
  // inorder(root);
  cout << checkBST(root);
  
}
int main()
{
  init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  solve();
  return 0;
}