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
int val=100000;
vi segTree(5*val,0);
vi ans(5*val,0);
vi left(5*n,0),right(5*n,0);
vi a(2*val,0);
int L,R;
void makeSegTree(int tp,int l,int r)
{
    if(l==r)
    {
        if(a[l]>=L && a[l]<=R)
        {
            ans[tp]+=1;
            left[tp]+=1;
            right[tp]+=1;
        }
        return ;
    }
    int mid=(l+r)/2;
    makeSegTree(2*tp+1,l,mid);
    makeSegTree(2*tp+2,mid+1,r);
    left[tp]=left[2*tp+1];
    if(left[tp]==mid-l+1)
    {
        left[tp]+=left[2*tp+2];
    }
    right[tp]=right[2*tp+2];
    if(right[tp]==r-(mid+1)+1)
    {
        right[tp]+=right[2*tp+1];
    }

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n,q,L,R;
    cin>>n>>q>>L>>R;
    vi a(n,0);
    
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            cin>>x>>y;
            if(y>=L && y<=R)
            {
                update(segTree,x,y,0,n-1,0);
            }
        }
    }
	return 0;
}

