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
    string a;
    cin>>a;
    n=a.length();
    ll open=0,close=0,q=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]=='(') open++;
        else if(a[i]==')') close++;
        else q++;
    }
    if(n%2==1)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    int ot=n/2 - open;
    int op=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==')')
        {
            op--;
            if(op<0)
            {
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
        else if(a[i]=='(')
        {
            op++;
        }
        else
        {
//            if(i==1)
  //              cout<<"r1"<<endl;
            if(ot>0)
            {
                
                a[i]='(';
                ot--;
                op++;
            }
            else
            {
                a[i]=')';
                op--;
            }
            if(op<0)
            {
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    cout<<a<<endl;
	return 0;
}

