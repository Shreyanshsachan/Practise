#include<bits/stdc++.h>
using namespace std;

// ===================================================================================================================================================
//1. Find the Largest element in an array
// ---------- Brute Force ----------
int sortArr(vector<int>& arr) {
    /*TC - O(NlogN)  for sorting
      SC - O(1)*/
    sort(arr.begin(), arr.end());
    return arr[arr.size() - 1];
}
// ---------- Optimal Solution ----------
int findLargestElement(int arr[], int n) {
    /*TC - O(N)
      SC - O(1)*/
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    return max;
}


// ===================================================================================================================================================
//2. Find Second Smallest and Second Largest Element in an array
// ---------- Brute Force ----------
void getElements(int arr[], int n)
{    
    /*TC - O(NlogN)  for sorting
      SC - O(1)*/
    if(n == 0 || n == 1)
        cout << -1 << " " << -1 << endl;
    sort(arr, arr + n);
    int small = arr[1]; 
    int large = arr[n - 2]; 
    cout << "Second smallest is " << small << endl;
    cout << "Second largest is " << large << endl;
}
// ---------- Optimal Solution ----------
void getElements(int arr[], int n)
{
    /*TC - O(2N)  for two linear traversals
      SC - O(1)*/
    if (n == 0 || n == 1)
        cout << -1 << " " << -1 << endl;
    int small = INT_MAX, second_small = INT_MAX;
    int large = INT_MIN, second_large = INT_MIN;
    int i;
    for (i = 0; i < n; i++) {
        small = min(small, arr[i]);
        large = max(large, arr[i]);
    }
    for (i = 0; i < n; i++) {
        if (arr[i] < second_small && arr[i] != small)
            second_small = arr[i];
        if (arr[i] > second_large && arr[i] != large)
            second_large = arr[i];
    }
    cout << "Second smallest is " << second_small << endl;
    cout << "Second largest is " << second_large << endl;
}


// ===================================================================================================================================================
//3. Check if an Array is Sorted
// ---------- Brute Force ----------
bool isSorted(int arr[], int n) 
{
    /*TC - O(N²)
      SC - O(1)*/
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) 
                return false;
        }
    }

    return true;
}
// ---------- Optimal Solution ----------
bool isSorted(int arr[], int n) 
{
     /*TC - O(N)
      SC - O(1)*/
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1])
            return false;
    }

    return true;
}
//Part 2 Check if Array Is Sorted and Rotated
bool check(vector<int>& nums) 
{
    /*TC - O(N)
      SC - O(1)*/
    int count=0;
    int size = nums.size();
    for(int i=0;i<size;i++){
        if(nums[i]>nums[(i+1)%size])    count++;
    }
    return count<=1;
}

// ===================================================================================================================================================
//4. Remove Duplicates in-place from Sorted Array
int removeDuplicates(vector<int>& nums) {
    /*TC - O(N)
      SC - O(1)*/
    int k=1;
    int size = nums.size();
    for(int i=1;i<size;i++){
        if(nums[i]!=nums[i-1]){
            nums[k]=nums[i];
            k++;
        }
    }
    return k;
}

// ===================================================================================================================================================
//5. Left Rotate the Array by One

// ===================================================================================================================================================
//6. Rotate array by K elements
// ---------- Brute Force ----------
void rotate(vector<int>& nums, int k) {
    /*TC - O(N)
      SC - O(k)*/
    vector<int> nums2(nums.size());
    k=k%nums.size();
    int j=0;
    for(int i=nums.size()-k;i<nums.size();i++){
        nums2[j] = nums[i];
        j++;
    }
    for(int i=0;i<nums.size()-k;i++){
        nums2[j] = nums[i];
        j++;
    }
    for(int i=0;i<nums.size();i++){
        nums[i] = nums2[i];
    }
}
void reverse(vector<int>& nums, int start, int end){
    while(start<end){
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}
void rotate(vector<int>& nums, int k) {
    int size = nums.size();
    k=k%size;
    reverse(nums, 0, nums.size()-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, nums.size()-1);
}
