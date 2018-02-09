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

int n;
vi a(300023);
class ST
{
    int bits[30];
    int curVal;
    int cnt;
    int getCurVal()
    {
        return curval;
    }
    int calcCurval()
    {
        int tt = 1;
        int ans=0;
        for(int i=0;i<30;i++)
        {
            ans = ans + tt*bits[i];
        }
        return ans;
    }
    void init(int val)
    {
        curval = val;
        cnt=0;
        int tt = 1;
        for(int i=0;i<30;i++)
        {
            if(tt & val)
            {
                cnt++;
                bits[i] = 1;
            }
            else bits[i] = 0;
        }
    }
    void value(ST a, ST b)
    {
        for(int i=0;i<30;i++)
        {
            this.bits[i] = a.bits[i] + b.bits[i];

        }
    }
};

ST segTree[5*300000];

void makeSegTree(int l,int r,int tp)
{
    if(l==r)
    {
        segTree[tp].init(val);
        return;
    }
    int mid = (l+r)/2;
    makeSegTree(l,mid,2*tp+1);
    makeSegTree(mid+1,r,2*tp+2);
    segTree[tp] =  
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
    int m;
    cin>>m;
    makeSegTree(0,n-1,0);
    while(m--)
    {
        int l,r,t;
        cin>>t>>l>>r;
        l--;
        r--;
        if(t==1)
        {
           cout<<querySum(ql,qr)<<endl; 
        }
        else
        {
            int x;
            cin>>x;
            updXor(ql,qr,x);
        }
    }
	return 0;
}

