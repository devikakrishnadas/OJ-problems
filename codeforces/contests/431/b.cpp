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
    vector<pair<int,int> >A;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        A.pb(mp(x,i+1));
    }
    sort(all(A));
    vi l1,l2;
    l1.pb(A[0].ff);
    bool one=1;
    int cnt=0;
    for(int i=1;i<n;i++)
    {
        //cout<<A[i].ss<<"-"<<A[i-1].ss<<endl;
        if(A[i].ss>A[i-1].ss && one == 1)
        {
            one=1;
        }
        else 
        {
            one=0;
            if(A[i].ss<A[i-1].ss)
            {
                cnt++;
            }
        }
        if(cnt>1)
        {
            cout<<"No"<<endl;
            return 0;
        }
        //cout<<A[i].ff<<"**"<<one<<endl;
        if(one)
        {
          //  cout<<A[i].ff<<"*"<<endl;
            l1.pb(A[i].ff);
        }
        else
        {
            l2.pb(A[i].ff);
        }
    }
    if(one)
    {
        cout<<"No"<<endl;
        return 0;
    }
    
    
    int diff=-1;
    for(int i=1;i<l1.size();i++)
    {
//        cout<<l1[i]<<" ";
        if(i==1)
        {
            diff=l1[i]-l1[i-1];
        }
        else
        {
            if(l1[i]-l1[i-1]!=diff)
            {
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
  //  cout<<endl;
    for(int i=1;i<l2.size();i++)
    {
        //cout<<l2[i]<<" ";
        if(i==1 && diff==-1)
        {
            diff=l2[i]-l2[i-1];
        }
        else
        {
            if(l2[i]-l2[i-1]!=diff)
            {
                //cout<<l2[i]<<" "<<l2[i-1]<<" "<<diff<<endl;
               // cout<<"Size"<<l1.size()<<" "<<l2.size()<<endl;
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    //cout<<endl;
    cout<<"Yes"<<endl;
	return 0;
}

