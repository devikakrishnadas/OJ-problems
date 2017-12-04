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
    int n=s.length();
    vi a;
    int cnt=1;
    int cnta=0,cntb=0;
    for(int i=1;i<n;i++)
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
    int st=0;
    if(s[0]=='b')
        st=1;
    if(a.size()<=2)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    if(a.size()==3)
    {
        if(s[0]=='b')
            cout<<s.length()-min(a[0],a[2])<<endl;
        else
            cout<<s.length()<<endl;
        return 0;
    }
    int ans=max(cnta,cntb);
    //aa....bb..
    vi ab(n+1,0);
    int st=0;
    int tans=n-cnta;
    if(s[0]=='b')
    {
        st=1;
        tans-=a[0];
    }
        //int tans=n-cnta;
        for(int i=st;i<a.size();i++)
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
            ab[i]=tans;
        }
    
    //bb....aa...
    st=0;
    vi ba(n+1,0);
    tans=n-cntb;
    if(s[0]=='a')
    {
        st=1;
    }
        //tans=n-cntb;
        for(int i=a.size();i>=0;i++)
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
            ba[i]=tans;
        }
    //aa..bb..aa..
    
    int en=a.size()-1;
    st=0;
    tans=n-cnta;
    if(s[0]=='b')
    {
        tans-=a[0];
        st=1;
    }
    if(s[n-1]=='b')
    {
        tans-=a[a.size()-1];
        en=en-1;
    }
    int cntat=0;
    for(int i=st;i<=en;i++)
    {
        if(i%2==st)
        {
            cntat+=a[i];
            ans=max(ans,cntat+ba[i]);
        }
        else
        {
            cntat-=a[i];
        }
    }
    cntat=0;
    for(int i=en;i>=0;i--)
    {
        if(i%2==st)
        {
            cntat+=st;
            ans=max(ans,cntat+ab[i]);
        }
    }
	return 0;
}

