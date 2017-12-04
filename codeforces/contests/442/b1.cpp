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
    string s;
    cin>>s;
    vi a;
    int n=s.length();
    int cnt=1;
    int cnta=0;
    int cntb=0;
    if(s[0]=='a') cnta++;
    else cntb++;
    for(int i=1;i<s.length();i++)
    {
        if(s[i]!=s[i-1])
        {
            a.pb(cnt);
            cnt=1;
        }
        else cnt++;
        if(s[i]=='a') cnta++;
        else cntb++;
    }
    a.pb(cnt);
    if(a.size()==2)
    {
        cout<<s.length()<<endl;
        return 0;
    }
    int st=0;
    if(s[0]=='b') st=1;
    int ans=max(cnta,cntb);
    int tans=n-cnta;

    for(int i=0;i<a.size();i++)
    {
        if(i%2!=st)
        {
            tans-=a[i];
        }
        else
        {
            tans+=a[i];
            ans=max(ans,tans);
        }
        int ttans=tans;
        for(int j=a.size()-1;j>i;j--)
        {
            if(j%2!=st)
            {
                ttans-=a[j];
            }
            else
            {
                ttans+=a[j];
                ans=max(ans,ttans);
            }
        }
    }
    tans=n-cnta;
    for(int i=a.size()-1;i>=0;i--)
    {
        if(i%2!=st)
        {
            tans-=a[i];
        }
        else
        {
            tans+=a[i];
            ans=max(ans,tans);
        }
        int ttans=tans;
        for(int j=0;j<i;j++)
        {
            if(j%2!=st)
            {
                ttans-=a[j];
            }
            else
            {
                ttans+=a[j];
                ans=max(ans,ttans);
            }
        }
    }
//    int st=0;
    if(s[0]=='a')
    {
        st=1;
    }
    tans=n-cntb;
    for(int i=a.size();i>=0;i--)
        {
            if(i%2==st)
            {
                tans+=a[i];
                ans=max(ans,tans);
            }
            else
            {
                tans=tans-a[i];
            }
            //ba[i]=tans;
        }
    cout<<ans<<endl;
	return 0;
}

