#include<iostream>
using namespace std;


int partition(int *a,int s,int e){

	//Inplace(Can't take extra array)
	int i = s-1;
	int j = s;

	int pivot = a[e];

	for( ;j<=e; ){
		if(a[j]<=pivot){
			//merge smaller element in the region 1
			i=i+1;
			swap(a[i],a[j]);
		}
		//expand the larger region
		j = j+1;
	}

	//place the pivot element in the correct index
	swap(a[i+1],a[e]);
	return i+1;

};


void quicksort(int *arr,int s,int e){

	//base case
	if(s>=e){
		return;
	}


	//recursive case
	int p = partition(arr,s,e);
	//left part
	quicksort(arr,s,p-1);
	//right part
	quicksort(arr,p+1,e);

};



int main(){
//quicksort
	int arr[] = {2,7,8,6,1,5,4}; 
	int n = sizeof(arr)/sizeof(int);

	quicksort(arr,0,n-1);

	//print the array
	for(int i=0;i<=n-1;i++){
		cout<< arr[i]<<" ";
	}


	return 0;
}
