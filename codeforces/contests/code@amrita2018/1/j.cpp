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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vi a(1000023,0);
        vi b;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            b.pb(x);
        }
/*        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                a[abs(b[i]-b[j])]=1;
            }
        }
*/      cout<<"YES"<<endl;
        int cnt=1;
        for(int i=1;i<=n;i++)
        {
            while(a[cnt])
            {
                cnt++;
                continue;
            }
            cout<<cnt<<" ";
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    int val = cnt + b[j] - b[k];
                    if(val >=1 and val <= 1000000) 
                        a[val]=1;
                }
            }
        }
        cout<<endl;
    }
	
    return 0;
}

