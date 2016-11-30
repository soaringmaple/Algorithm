#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <limits>
#include <string>
#include <map>


using namespace std;

#define SHOW(a) cout << #a << ":" << a <<endl


int merge_count(vector<int>& arr, int start, int end){
	if(end-start==1){
		return 0;
	}
	else{
		int mid = (start+end)/2;
		int num1 = merge_count(arr, start, mid);
		int num2 = merge_count(arr, mid, end);
		vector<int> arr1(mid-start, 0);
		vector<int> arr2(end-mid, 0);
		copy(arr.begin()+start, arr.begin()+mid, arr1.begin());
		copy(arr.begin()+mid, arr.begin()+end, arr2.begin());
		
		if(false){
			for(int i=0; i<arr1.size(); i++){
				cout << arr1[i] << " " <<endl;
			}
		}
		
		int len1 = mid-start;
		int len2 = end-mid;
		int num3 = 0;
		int idx1 = 0, idx2 = 0, idx0 = 0;
		while(idx1<len1 && idx2<len2){
			if(arr1[idx1]<=arr2[idx2]){
				arr[start+idx0]=arr1[idx1];
				idx1++;
				idx0++;
			}
			else{
				arr[start+idx0]=arr2[idx2];
				num3+=(len1-idx1);
				idx2++;
				idx0++;
			}
		}
		while(idx1<len1){
			arr[start+idx0]=arr1[idx1];
			idx1++;
			idx0++;
		}
		while(idx2<len2){
			arr[start+idx0]=arr2[idx2];
			idx2++;
			idx0++;
		}
		return num1+num2+num3;
	}
}


int main(int argc, char *argv[]) {
	
	cout << "Input length of array: " <<endl;
	int N=0;
	cin >> N;
	vector<int> arr(N,0);
	
	// Step 1: generate random interger array with length N
	for(int i=0; i<N; i++){
		arr[i] = rand()%10000;
	}
	
	// Step 2: return results by brute force algorithm
	cout << "Number of Reversions by Brute Force Algorithm is : ";
	int res = 0;
	for(int i=0; i<N-1; i++){
		for(int j=i+1; j<N; j++){
			if(arr[i]>arr[j]){
				res++;
			}
		}
	}
	cout << res <<endl;
	
	// Step 3: return results calculated by recursive algorithm
	cout << "Number of Reversions by Recusive Algorithm is: ";
	cout << merge_count(arr, 0, arr.size()) <<endl;
	for(int i=0; i<arr.size(); i++){
		cout << arr[i] << " ";
	}
	cout <<endl;
	
	
}