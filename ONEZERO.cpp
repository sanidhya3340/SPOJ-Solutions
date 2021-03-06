/*My First Template :D*/
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define MOD (ll)1000000007
#define pb   push_back
#define EPS 1e-9
#define FOR(i,n)  for(int i = 0;i < n; i++)
#define FORE(i,a,b) for(int i = a;i <= b; i++)
#define pi(a)   printf("%d\n", a)
#define all(c)  c.begin(), c.end()
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define gc getchar_unlocked
#define sdi(a, b)   si(a);si(b)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

void si(int &x){
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int visited[20005];
// string output;
string solve(int n1){
    // cout<<n1<<endl;
    queue<pair<int, string> > q;
    q.push(make_pair(1, "1"));
    while(!q.empty()){
        int value = q.front().first;
        string current = q.front().second;
        // cout<<value<<' '<<current<<endl;
        q.pop();
        if(value == 0){
            return current;
        }
        string output1 = current+"0";
        string output2 = current+"1";
        int rem1 = (value*10)%n1;
        if(!visited[rem1]){
            q.push(make_pair(rem1,output1));
            visited[rem1] = 1;
        }
        int rem2 = (value*10+1)%n1;
        if(!visited[rem2]){
            q.push(make_pair(rem2,output2));
            visited[rem2] = 1;
        }
    }
}


int main(){
    io;
    int t;
    cin>>t;
    while(t--){
        memset(visited, 0, sizeof(visited));
        int n1;
        cin>>n1;
        if(n1 == 1){
            cout<<1<<endl;
        }else{
            string output = solve(n1);
            cout<<output<<endl;
        }
    }
    return 0;
}




