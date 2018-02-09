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

using namespace std;

vi a(100023);
int n,m;
vi segTree[21];
vi pow2(21,1);
vi lazyTree[21];
void fill(int ind,int tp)
{
    for(int i=0;i<=20;i++)
    {
        segTree[i][tp] = (pow2[i] & a[ind] ? 1 : 0) ;
    }
}

void sumIt(int cur,int l,int r)
{
    for(int i=0;i<=20;i++)
    {
        segTree[i][cur] = segTree[i][l] + segTree[i][r];
    }
}

void pushDown(int tp,int l,int r,int ind)
{
    if(l!=r)
    {
        lazyTree[ind][2*tp+1] = 1 - lazyTree[ind][2*tp+1];
        lazyTree[ind][2*tp+2] = 1 - lazyTree[ind][2*tp+2];
    }
    lazyTree[ind][tp] = 0;
    segTree[ind][tp] = r - l + 1 - segTree[ind][tp];
}
void makeSegTree(int l,int r,int tp)
{
    if(l==r)
    {
        fill(l,tp);
        return;
    }
    int mid = (l+r)/2;
    makeSegTree(l,mid,2*tp+1);
    makeSegTree(mid+1,r,2*tp+2);
    sumIt(tp,2*tp+1,2*tp+2);
}

int querySumUtil(int ql,int qr,int l,int r,int tp,int ind)
{
    if(r<ql || l>qr)
    {
        return 0;
    }

    if(lazyTree[ind][tp])
    {
        pushDown(tp,l,r,ind);
    }
    if(l>=ql and r<=qr)
    {
        return segTree[ind][tp];
    }
    int mid = (l+r)/2;
    int val =  querySumUtil(ql,qr,l,mid,2*tp+1,ind) + querySumUtil(ql,qr,mid+1,r,2*tp+2,ind);
    segTree[ind][tp] = segTree[ind][2*tp+1] + segTree[ind][2*tp+2];
    cerr<<"return from [l,r] = ["<<l<<","<<r<<"] = "<<val<<endl;
    cout<<val<<endl;
}

int querySum(int ql,int qr)
{
    ll ans = 0;
    for(int i=0;i<=20;i++)
    {
        int val = querySumUtil(ql,qr,0,n-1,0,i);
        ans = ans + pow2[i] * val;
    }

    return ans;
}

void flip(int ql,int qr,int l,int r,int tp,int ind)
{
    if(r<ql || l>qr)
        return;
    if(l>=ql and r<=qr)
    {
        lazyTree[ind][2*tp+1] = 1 - lazyTree[ind][2*tp+1];
        lazyTree[ind][2*tp+2] = 1 - lazyTree[ind][2*tp+2];
        segTree[ind][tp] = r-l+1 - segTree[ind][tp];
        return;
    }
    int mid = (l+r)/2;
    flip(ql,qr,l,mid,2*tp+1,ind);
    flip(ql,qr,mid+1,r,2*tp+2,ind);
    segTree[ind][tp] = segTree[ind][2*tp+1] + segTree[ind][2*tp+2];
}
void xorUpd(int ql,int qr,int x)
{
    for(int i=0;i<=20;i++)
    {
        if(x & pow2[i])
        {
            flip(ql,qr,0,n-1,0,i);
        }
    }
}
int getval(int tp)
{
    ll ans = 0;
    for(int i=0;i<=20;i++)
    {
        ans = ans + pow2[i] * segTree[i][tp];
    }
    return ans;
}
void print(int l,int r,int tp)
{
    for(int i=0;i<=20;i++)
    {
        if(lazyTree[i][tp])
        {
            pushDown(tp,l,r,i);
        }
    }
    if(l==r)
    {
        cout<<"Val @ ind = "<<l<<endl;
        cout<<getval(tp)<<endl;
        return;
    }
        
    int mid = (l+r)/2;
    print(l,mid,2*tp+1);
    print(mid+1,r,2*tp+2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=20;i++)
    {
        pow2[i] = pow2[i-1]*2;
    }
    for(int i=0;i<=20;i++)
    {
        segTree[i].resize(1000000,0);
        lazyTree[i].resize(1000000,0);
    }

    makeSegTree(0,n-1,0);

    cin>>m;
    while(m--)
    {
        int t,l,r;
        cin>>t>>l>>r;
        l--;
        r--;
        if(t==1)
        {
            cout<<querySum(l,r)<<endl;
        }
        else
        {
            int x;
            cin>>x;
            xorUpd(l,r,x);
        }
        print(l,r,0);
    }
	return 0;
}

