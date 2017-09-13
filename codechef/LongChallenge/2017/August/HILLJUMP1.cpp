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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n,q;
    cin>>n>>q;
    vi a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vi len(n,0);
    vi last(n,-1);
    vi next(n,-1);
    vi nMax(n/100 + 1,0);
    vi nMaxIndex(n/100 + 1,-1);
    last[n-1]=n-1;
    for(int i=n-2;i>=0;i--)
    {
        for(int j=i+1;j<min(n,i+100);j++)
        {
            if(a[j]>a[i])
            {
                next[i]=j;
            }
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        last[i]=i;
        for(int j=i+1;j<min(n,i+100);j++)
        {
            if(j%100==0)
                break;
            if(a[j]>a[i])
            {
                //next[i]=j;
                len[i]=len[j]+1;
                last[i]=last[j];
            }
        }
    }
    int cnt=0;
    while(1)
    {
        for(int j=cnt*100;j<min(cnt*100 + 100,n);j++)
        {
            if(nMax[cnt]<a[j])
            {
                nMax[cnt]=a[j];
                nMaxIndex[cnt]=j;
            }
        }
        cnt++;
    }
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int i,k;
            cin>>i>>k;
            
        }
        else
        {
            int l,r,v;
            cin>>l>>r>>v;
            for(int i=r-1;i>=max(l-1,r-100);i--)
            {
                
            }
        }
    }
	return 0;
}

