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
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
    int n,m,c;
    cin>>n>>m>>c;
    vi a(n,0);
    int empty=n;
    int p;
    while(m--)
    {
        cin>>p;
        if(p<=(c/2))
        {
            for(int i=0;i<n;i++)
            {
                if(a[i]==0 || a[i]>p)
                {
                    if(!a[i]) empty--;
                    a[i]=p;
                    cout<<i+1<<endl;
                    break;
                }
            }
        }
        else
        {
            for(int i=n-1;i>=0;i--)
            {
                if(a[i]<p)
                {
                    if(a[i]==0) empty--;
                    a[i]=p;
                    cout<<i+1<<endl;
                    break;
                }
            }
        }
        fflush(stdout);
        if(!empty) break;
    }   
	return 0;
}

