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
// ---------- Part 2 Check if Array Is Sorted and Rotated ----------
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
// ---------- Optimal Solution ----------
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
// ---------- Optimal Solution ----------
void reverse(vector<int>& nums, int start, int end){
    /*TC - O(N)
    SC - O(k)*/
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


// ===================================================================================================================================================
//7. Move all Zeros to the end of the array
// ---------- Brute Force ----------
vector<int> moveZeroes(vector<int>& arr) {
    /*TC - O(N)
    SC - O(N)*/
    vector<int> temp(arr.size(), 0);
    int index = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            temp[index] = arr[i];
            index++;
        }
    }
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = temp[i];
    }
    return arr;
}
// ---------- Optimal Solution ----------
void moveZeroes(vector<int>& nums) {
    /*TC - O(N)
    SC - O(1)*/
    int pos=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=0){
            nums[pos]=nums[i];
            if(i!=pos)
                nums[i]=0;
            pos++;
        }
    }
}


// ===================================================================================================================================================
//8. Linear Search
int linear_search(vector<int>& nums, int k){
    /*TC - O(N)
    SC - O(1)*/
    for(int i=0;i<nums.size();i++){
        if(nums[i]==k){
            return i;
        }
    }
    return -1;
}


// ===================================================================================================================================================
//9. Union of Two Sorted Arrays
// ---------- Approach 1- Using Map ----------
vector<int> FindUnion(int arr1[], int arr2[], int n, int m) {
    /*TC - O( (m+n)log(m+n) )
    SC - O(m+n)*/
    map<int, int> freq;
    vector<int> Union;
    for (int i = 0; i < n; i++)
        freq[arr1[i]]++;
    for (int i = 0; i < m; i++)
        freq[arr2[i]]++;
    for (auto &it : freq)
        Union.push_back(it.first);
    return Union;
}
// ---------- Approach 2- Using Set ----------
vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
    /*TC - O( (m+n)log(m+n) )
    SC - O(m+n)*/
    set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++) {
        st.insert(arr2[i]);
    }
    vector<int> unionArr(st.begin(), st.end());
    return unionArr;
}
// ---------- Optimal Approach - Two Pointers ----------
vector<int> union1(vector<int>& nums, vector<int>& nums1){
    /*TC - O(m+n)
    SC - O(1)*/
    vector<int> res;
    int i=0,j=0;
    while(i<nums.size() && j<nums1.size()){
        if(nums[i]<nums1[j]){
            if(res.empty() || res.back()!=nums[i]){
                res.push_back(nums[i]);
            }
            i++;
        }
        else if(nums[i]>nums1[j]){
            if(res.empty() || res.back()!=nums1[j]){
                res.push_back(nums1[j]);
            }
            j++;
        }
        else{
            if(res.empty() || res.back()!=nums[i]){
                res.push_back(nums[i]);
            }
            i++; j++;
        }
    }
    while(i<nums.size()){
        if(res.empty() || res.back()!=nums[i]){
            res.push_back(nums[i]);
        }
        i++;
    }
    while(j<nums1.size()){
        if(res.empty() || res.back()!=nums1[j]){
            res.push_back(nums1[j]);
        }
        j++;
    }
    return res;
}


// ===================================================================================================================================================
//10. Find the Missing Number
// ---------- Approach 1- Using Map ----------


// ===================================================================================================================================================
//11. Count Maximum Consecutive One's in the array
int findMaxConsecutiveOnes(vector<int>& nums) {
    /*TC - O(N)
    SC - O(1)*/
    int cnt=0;
    int maxi=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==1)  cnt++;
        else    cnt=0;
        maxi = max(maxi,cnt);
    }
    return maxi;
}


// ===================================================================================================================================================
//12. Find the number that appears once, and the other numbers twice
// ---------- Brute Force ----------
int getSingleElement(vector<int>& arr) {
    /*TC - O(N²)
    SC - O(1)*/
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == num)
                cnt++;
        }
        if (cnt == 1) return num;
    }
    return -1;
}
// ---------- Optimal Solution ----------
int getSingleElement(vector<int>& arr) {
    /*TC - O(N) + O(N) + O(N)
    SC - O(1)*/
    int n = arr.size();
    int maxi = arr[0];
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i]);
    }
    vector<int> hash(maxi + 1, 0);
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (hash[arr[i]] == 1)
            return arr[i];
    }
    return -1;
}


// ===================================================================================================================================================
//13. Longest Subarray with given Sum K(Positives)
// ---------- Brute Force ----------
