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

void maxHeapify(int arr[100],int n,int i)
{
	if(i==0) return;
	if(i>n)	return;
	int largest=i;
	int right=2*largest+1;
	int left=right-1;
	if(right<=n)
		if(arr[largest]<arr[right])
			largest=right;
	
	if(arr[left]>arr[largest] && left<=n)
		largest=left;
	if(largest!=i)
	{
		swap(arr[largest],arr[i]);
		maxHeapify(arr,n,largest);
	}
	i--;
	maxHeapify(arr,n,i);
//	largest=i;
}

void print_in(int arr[100],int n,int i)
{
//	cout<<i<<" ";
	if(i>n) return ;
	print_in(arr,n,2*i);
	cout<<arr[i]<<" ";
	//cout<<i<<" ";
	print_in(arr,n,2*i+1);
}

void print_pre(int arr[100],int n,int i)
{
	if(i>n) return;
	cout<<arr[i]<<" ";

         print_pre(arr,n,2*i);
        
        print_pre(arr,n,2*i+1);
}


void print_post(int arr[100],int n,int i)
{
	if(i>n) return;
       	print_post(arr,n,2*i);
        
        print_post(arr,n,2*i+1);
	cout<<arr[i]<<" ";

}

void heapSort(int arr[100],int n)
{
	if(!n) return;
	maxHeapify(arr,n,n/2);
//	cout<<arr[1]<<" ";
	swap(arr[1],arr[n]);
	n--;
	heapSort(arr,n);
}
int main()
{
	int arr[100];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
//	maxHeapify(arr,n,n/2);
//	for(int i=1;i<=n;i++)
//	{
//		cout<<arr[i]<<" ";
//	}
//	cout<<endl;
	int i=1;
	cout<<endl<<endl<<"INORDER"<<endl;
	print_in(arr,n,i);
	//cout<<endl;
	cout<<endl<<endl<<"PREORDER"<<endl;
	print_pre(arr,n,i);
	cout<<endl<<endl<<"POSTORDER"<<endl;
	print_post(arr,n,i);

	heapSort(arr,n);
	cout<<endl<<endl<<"HEAPSORT"<<endl;
	for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
	cout<<endl;

	cout<<endl<<endl<<endl;
	cout<<endl<<endl<<"INORDER"<<endl;
        print_in(arr,n,i);
        //cout<<endl;
        cout<<endl<<endl<<"PREORDER"<<endl;
        print_pre(arr,n,i);
        cout<<endl<<endl<<"POSTORDER"<<endl;
        print_post(arr,n,i);

	return 0;
}

