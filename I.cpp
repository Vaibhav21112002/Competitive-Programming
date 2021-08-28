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
#define pie 3.1415926536
vi adj[smod];
vvi prismGraph[smod];
vvi edges;
vector<bool> vis(smod,0);

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

class item{
  int cost;
  int number;
  public:
    void getData(int a, int b);
    void putData();
};

void item :: getData(int a, int b){
  cost = a;
  number = b;
}

void item :: putData(){
  cout << "Number: " << number << endl;
  cout << "Cost: " << cost << endl;
}

void solve()
{
  item x;
  x.getData(4,5);
  x.putData();
}
int main()
{
  init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  solve();
  return 0;
}