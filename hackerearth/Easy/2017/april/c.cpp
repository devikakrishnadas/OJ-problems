#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

/*


int  _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);
 

int mergeSort(int arr[], int array_size)
{
    int *temp = (int *)malloc(sizeof(int)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}
 

int _mergeSort(int arr[], int temp[], int left, int right)
{
  int mid, inv_count = 0;
  if (right > left)
  {
    
    mid = (right + left)/2;
 
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);
 
    
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}
int merge(int arr[], int temp[], int left, int mid, int right)
{
  int i, j, k;
  int inv_count = 0;
 
  i = left; * i is index for left subarray
  j = mid;  /* j is index for right subarra
  k = left; /* k is index for resultant merged subarray
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
 
     /*this is tricky -- see above explanation/diagram for merge()
      inv_count = inv_count + (mid - i);
    }
  }
 
  /* Copy the remaining elements of left subarray
   (if there are any) to temp
  while (i <= mid - 1)
    temp[k++] = arr[i++];
 
  /* Copy the remaining elements of right subarray
   (if there are any) to temp
  while (j <= right)
    temp[k++] = arr[j++];
 
  /*Copy back the merged elements to original array
  for (i=left; i <= right; i++)
    arr[i] = temp[i];
 
  return inv_count;
}*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	int x;
	cin>>n;
	vi a,b;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		a.pb(x);
		b.pb(x);
	}
	sort(all(b));
	int cnt=0;
	int h=a[n-1],l;
	for(int i=n-2;i>=0;i--)
	{
		if(a[i]<h )
		{
			cnt++;
			if(!enter)
			{
				enter=1;
				l=a[i];
			}
			else
			{
				if(a[i]>l)
				{
					
				}
			}
		}
		else 
		{
			h=a[i];
			enter=0;
		{
	}
	cout<<cnt<<endl;
	return 0;
}

