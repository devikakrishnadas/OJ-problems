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

vi arr(200023,0);
void Z(vc A,int n)//Failure function
{
        
        int l=0,r=0;
        for(int i=1;i<n;)
        {
                int k=r-i;
                if(k<0)
                        k=0;
                while(A[i+k]==A[k] && i+k<n)//Runs until the first mismatch with the prefix
                {

                        k++;
                }
                arr[i]=k;
                l=i;
                r=k+i;
                if(k)
                {
                        r=r-1;
                }
                bool enter=0;
                for(int j=1;j<r-l+1;j++)
                {
                        arr[i+j]=arr[j];
                        if(arr[j]+i+j>=r)
                        {
                                i=i+j;
                                enter=1;
                                break;
                        }
                }
                if(!enter)
                {
                        i=r+1;
                }
        }	
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	vc A,B;
	for(int i=0;i<s.length();i++)
	{
		B.pb(s[i]);
	}
	B.pb('$');
	for(int i=0;i<s.length();i++)
        {
                B.pb(s[i]);
        }
	Z(B,B.size());
	int val=0;
	vi calc;
	for(int i=s.length()+2;i<B.size();i++)
	{
		if(i+arr[i]==B.size())
		{
			calc.pb(B.size()-i);
		}
	}
	val=calc[0];
	cout<<calc.size()<<endl;
	//cout<<calc[0]<<endl;
	//cout<<"VAL "<<val<<endl;
	if(val==0 || val==s.length())
	{
		//cout<<"abc"<<endl;
		cout<<1<<endl;
		cout<<s.length()<<" "<<1<<endl;
		return 0;
	}
	for(int i=0;i<val;i++)
        {
                arr[i]=0;
                A.pb(s[i]);
        }
	A.pb('$');
	arr[val]=0;
	for(int i=0;i<s.length();i++)
	{
		A.pb(s[i]);
		arr[i+val+1]=0;
	}
	arr[A.size()]=0;
	Z(A,A.size());
/*	
	for(int i=val+1;i<A.size();i++)
	{
		if(arr[i]==0)
			continue;
		calc.pb(arr[i]);
		//cout<<arr[i]<<endl;
	}
*/	vector<pair<int,int> >ans;
	sort(all(calc));
	reverse(all(calc));
	int cnt[200023]={0};
	for(int i=0;i<calc.size();i++)
	{
		cnt[calc[i]];
	}	
	int count=0;
	for(int i=s.length();i>=1;i--)
	{
		if(cnt[i])
		{
			count+=cnt[i];
			ans.pb(mp(i,count));
		}
	}
	ans.pb(mp(s.length(),1));
	sort(all(ans));
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
	}
	return 0;
}

