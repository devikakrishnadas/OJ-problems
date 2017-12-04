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
int A[1001][1001]={0};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int k,n;
    cin>>k>>n;
    int B[1001]={0};
    int no=0;
    vi a(k);
    for(int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        if(x==-1) 
            no++;
        else
            B[x]++;
        a.pb(x);
    }
    int ineach=k/n;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(B[i]%ineach!=0)
        {
            int tt=ineach-B[i]%ineach;
            if(no>=tt)
            {
                no=no-tt;
                B[i]+=tt;
                
            }
            else
            {
                cout<<"No"<<endl;
                return 0;
            }
        }
        cnt+=(B[i]/ineach);
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            A[i][j]=min(B[i],B[j]);
            B[i]-=A[i][j];
            B[j]-=A[i][j];
            A[j][i]=A[i][j];
        }
    }
    vector<pair<int,int> >C;
    for(int i=0;i<k;i++)
    {
        bool enter=0;
        for(int j=1;j<=n;j++)
        {
            if(A[a[i]][j])
            {
                C.pb(mp(a[i],j));
                enter=1;
                break;
            }
            else if(A[j][a[i]])
            {
                C.pb(mp(j,a[i]));
                enter=1;
                break;
            }
        }
        if(!enter)
        {
            cout<<i;
            cout<<"No"<<endl;
            return 0;
        }
    }
	return 0;
}

