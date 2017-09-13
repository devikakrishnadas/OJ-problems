#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin,V.end

using namespace std;

bool subset[3][7000*7000]={0};
bool isSubsetSum(vi set, int n, int sum)
{
    
 
    for (int i = 0; i <= 2; i++)
      subset[i][0] = true;
 
    for (int i = 1; i <= sum; i++)
      subset[0][i] = false;
 
     
     for (int i = 1; i <= sum; i++)
     {
       for (int j = 1; j <= n; j++)
       {

         subset[j%2][i] = subset[(j-1)%2][i];
	
         if (i >= set[j-1])
           subset[j%2][i] = subset[j%2][i] || 
                                 subset[(j-1)%2][i - set[j-1]];
       }
     }
	
     return subset[n%2][sum];
}
int main()
{
	int n;
	cin>>n;
	int k1,k2,x;
	vi ricky,morty;
	int ri[7007]={0},mo[7007]={0};
	int r=0,m=0;
	cin>>k1;
	for(int j=0;j<k1;j++)
	{
		cin>>x;
		ri[x]=1;
		ricky.pb(x);
	}
	cin>>k2;
	for(int j=0;j<k2;j++)
	{
		cin>>x;
		mo[x]=1;
		morty.pb(x);
	}
	isSubsetSum(ricky,k1,n*(n-1)+1);
	for(int j=2;j<=n;j++)
	{
		int win=0,loop=0,lose=0;
		for(int i=1+n;i<=(n*(n-1)+1);i+=n)
		{
			if(subset[n%2][i-j])
			{
				win=1;
				cout<<i-j<<endl;
				break;
			}
			else if(subset[n%2][n-j])
			{
				loop=1;
				
			}
			else {lose=1;}
		}
		if(win)
			cout<<"Win ";
		else if(loop)
			cout<<"Loop ";
		else cout<<"Lose ";
	}
	cout<<endl;
	for(int i=0;i<7000*7000;i++)
	{
		for(int j=0;j<=1;j++)
		{
			//cout<<subset[j][i]<<" ";	
			subset[j][i]=0;
		}
		//cout<<endl;
	}
	isSubsetSum(morty,k2,n*(n-1)+1);
	for(int j=2;j<=n;j++)
	{
		int win=0,loop=0,lose=0;
		for(int i=i+n;i<=(n*(n-1))+1;i+=n)
		{
			/* if(subset[i-j][n%2])
                        {
                                cout<<"Win ";
                        }
                        else if(subset[n-j][n%2])
                        {
                                cout<<"Loop ";
                        }
                      
			if(subset[n%2][i-j])
                        {
                                cout<<"Win ";
                        }
                        else if(subset[n%2][n-j])
                        {
                                cout<<"Loop ";
                        }
                        else cout<<"Lose ";
			*/
			if(subset[n%2][i-j])
                        {
                                win=1;
                                break;
                        }
                        else if(subset[n%2][n-j])
                        {
                                loop=1;

                        }
                        else {lose=1;}


		}
		if(win)
                        cout<<"Win ";
                else if(loop)
                        cout<<"Loop ";
                else cout<<"Lose ";

	}
	cout<<endl;
	return 0;
}

