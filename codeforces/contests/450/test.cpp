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
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ans=0;
    int ansi=-1;
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        for(int j=1;j<n;j++)
        {
            if(j==i) continue;
            bool no=0;
            for(int k=0;k<j;k++)
            {
                if(k==i) continue;
                if(a[k] > a[j])
                {
                    no=1;
                    break;
                }
            }
            if(!no)
            {
                cnt++;
            }
        }
        if(cnt >= ans)
        {
        
            ans=cnt;
            if(ansi==-1)
            {
                ansi=i;
                continue;
            }
            if(cnt==ans && a[ansi] > a[i]) continue;
            ansi = i;
        }
    }
//    cout<<ansi<<endl;
    cout<<a[ansi]<<endl;
	return 0;
}

