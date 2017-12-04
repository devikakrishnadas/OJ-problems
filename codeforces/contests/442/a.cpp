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


int noExist(string a,string b)
{
    if(a.length()>b.length()) return 0;
    int ans=0;
    for(int i=0;i<b.length()-a.length()+1;i++)
    {
        int cnt=0;
        for(int j=0;j<a.length() && i+j<b.length();j++)
        {
            if(b[i+j]==a[j])
            {
                cnt++;
            }
            else break;
        }
        if(cnt==a.length())
            ans++;
    }
    return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    string A[]={"Danil","Olya","Slava","Ann","Nikita"};
    string s;
    cin>>s;
    int a=noExist(A[0],s);
    int b=noExist(A[1],s);
    int c=noExist(A[2],s);
    int d=noExist(A[3],s);
    int e=noExist(A[4],s);
    
    if(a==1 && b==0 && c==0 && d==0 && e==0 )
    {
        cout<<"YES"<<endl;
    }
    else if(a==0 && b==1 && c==0 && d==0 && e==0 )
    {
        cout<<"YES"<<endl;
    }
    else if(a==0 && b==0 && c==1 && d==0 && e==0 )
    {
        cout<<"YES"<<endl;
    }
    else if(a==0 && b==0 && c==0 && d==1 && e==0 )
    {
        cout<<"YES"<<endl;
    }
    else if(a==0 && b==0 && c==0 && d==0 && e==1 )
    {
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
	return 0;
}

