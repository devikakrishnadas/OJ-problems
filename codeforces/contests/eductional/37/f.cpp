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


struct node
{
    int up;
    int cursum;
};
int n;
vi a(300023);
node segTree[2000000];
vi divi(1000023,0);


void makeSegTree(int s,int e,int tp)
{
    if(s==e)
    {
        segTree[tp].cursum = a[s];
        return;
    }
    int mid = (s+e)/2;
    makeSegTree(s,mid,2*tp+1);
    makeSegTree(mid+1,e,2*tp+2);
    segTree[tp].cursum = segTree[2*tp+1].cursum + segTree[2*tp+2].cursum;
}

void upd(int s,int e,int qs,int qe,int tp)
{
    if(e<qs or s>qe)
        return;
	while(segTree[tp].up)
    {
        segTree[2*tp+1].up++;
        segTree[2*tp+2].up++;
        segTree[tp].up--;
        segTree[tp].cursum = divi[segTree[tp].cursum];
    }
    if(s>=qs and e<=qe)
    {
        segTree[2*tp+1].up++;
        segTree[2*tp+2].up++;
        segTree[tp].cursum = divi[segTree[tp].cursum];
        return;
    }
    int mid = (s+e)/2;
    upd(s,mid,qs,qe,2*tp+1);
    upd(mid+1,e,qs,qe,2*tp+2);
    segTree[tp].cursum = segTree[2*tp+1].cursum + segTree[2*tp+2].cursum; 
}

int sum_query(int s,int e,int qs,int qe,int tp)
{
    if(e<qs or s>qe)
        return 0;
    while(segTree[tp].up)
    {
        segTree[2*tp+1].up++;
        segTree[2*tp+2].up++;
        segTree[tp].up--;
        segTree[tp].cursum = divi[segTree[tp].cursum];
    }
    if(s>=qs and e<=qe)
    {
        return segTree[tp].cursum;
    }
    int mid = (s+e)/2;
    return sum_query(s,mid,qs,qe,2*tp+1) + sum_query(mid+1,e,qs,qe,2*tp+2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    for(int i=2;i<=1000000;i++)
    {
        for(int j=i;j<=1000000;j+=i)
        {
            divi[j]++;
        }
    }
    for(int i=1;i<=1000000;i++)
    {
        divi[i]++;
    }
    int m;
    cin>>n>>m;
    REP(i,n)
        cin>>a[i];
    makeSegTree(0,n-1,0);
    while(m--)
    {
        int t,l,r;
        cin>>t>>l>>r;
        l--;
        r--;
        if(t==1)
        {
            upd(0,n-1,l,r,0);
        }
        else
        {
            cout<<sum_query(0,n-1,l,r,0)<<endl;
        }
    }
	return 0;
}

