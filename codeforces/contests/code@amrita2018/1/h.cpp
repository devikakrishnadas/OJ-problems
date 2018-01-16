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
    vector<double> win_prob(5005,0),lose_prob(5005,0);
    vi a(2002);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    //cerr<<"r1"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i]>a[j])
                win_prob[a[i]-a[j]]++;
            else
                lose_prob[a[j]-a[i]]++;
        }
    }
    //cerr<<"r2"<<endl;
    double tot = (n*(n-1))/2;
    for(int i=0;i<5005;i++)
    {
        win_prob[i]/=tot;
        lose_prob[i]/=tot;
    }
    //cerr<<"r3"<<endl;
    vector<double> fin_win(5005,0);
    for(int i=1;i<5005;i++)
    {
        for(int j=1;j<5005;j++)
        {
            if(i+j >= 5005) continue;
//            cerr<<i<<" "<<j<<endl;
            fin_win[i+j] += win_prob[i]*win_prob[j];
        }
    }
    //cerr<<"r4"<<endl;
    double ans=0.0;
    for(int i=0;i<=5005;i++)
    {
        for(int j=i+1;j<=5005;j++)
        {
            ans += ( fin_win[i]*lose_prob[j] );
        }
    }
    //cerr<<"r5"<<endl;
    cout<<fixed<<setprecision(20)<<ans<<endl;
	return 0;
}

