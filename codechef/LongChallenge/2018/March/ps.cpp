#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
#define M 1000000007
#define ss second
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)

using namespace std;

int n,q;
vi a(n);
class seg
{
    public:
    vi m;
    int l1,l2,l3;
    int tot;
    seg()
    {
        m1=m2=m3=l1=l2=l3=0;
        tot=0;
    }
};

seg segTree[300023];

void merge(int l,int r,int c)
{
    

}
void make_tree(int s,int e,int tp)
{
    if(s==e)
    {
        segTree[tp].m.pb(a[s]);
        tot=a[s];
        return;
    }
    int mid=(s+e)/2;
    make_tree(s,mid,2*tp+1);
    make_tree(mid+1,e,2*tp+2);
    merge(2*tp+1,2*tp+2,tp);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>q;
    REP(i,n) cin>>a[i];
	return 0;
}

