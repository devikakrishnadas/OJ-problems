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
    int n,m;
    cin>>n>>m;
    vi a(200,0);
    for(int i=0;i<m;i++)
    {
        int k,f;
        cin>>k>>f;
        a[k]=f;
    }
    int cnt=0,loc=0,locf=0;
    for(int i=1;i<=100;i++)
    {
        bool no=0;
        int t=1;
        for(int j=1;j<=100;j++)
        {
            if(a[j]!=t && a[j]!=0)
            {
                no=1;
                break;
            }
            if(j==n)
                loc=t;
            if(j%i==0)
            {
                t++;
            }
            
        }
        if(!no) 
        {
  //          cout<<i<<endl;
            locf=loc;
            cnt++;
        }
    }
//    cout<<cnt<<endl;
    if(cnt==1)
    {
        cout<<locf<<endl;
    }
    else
        cout<<-1<<endl;
	return 0;
}

