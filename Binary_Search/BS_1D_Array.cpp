#include<bits/stdc++.h>
using namespace std;

// ===================================================================================================================================================
//1. Search X in sorted array
// ---------- Iterative Solution ----------
int search_iter(vector<int>& nums, int target) {
    /*TC - O(logN)
      SC - O(1)*/
    int n=nums.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid] < target)   low=mid+1;
        else high=mid-1;
    }
    return -1;
}
// ---------- Recursive Solution ----------
int recur(vector<int>& nums, int target, int low, int high){
    /*TC - O(logN)
      SC - O(1)*/
    int n=nums.size();
    if(low>high)    return -1;
    int mid = low + (high-low)/2;
    if(nums[mid]==target)   return mid;
    else if(nums[mid] < target) return recur(nums, target, mid+1, high);
    else return recur(nums, target, low, mid-1);
}
int searchh(vector<int>& nums, int target) {
    return recur(nums, target, 0, nums.size()-1);
}


// ===================================================================================================================================================
//2. Implement Lower Bound
// ---------- Solution ----------
int lower(vector<int> nums, int target){
    /*TC - O(logN)
      SC - O(1)*/
    int n=nums.size();
    int low=0,high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>=target){
            ans=mid;
            high = mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
// ---------- Optimal Solution ----------
auto lower_optional(vector<int> nums, int target){
    int n=nums.size();
    int it = lower_bound(nums.begin(),nums.end(), target) - nums.begin();
    return it;
}


// ===================================================================================================================================================
//3. Implement Upper Bound
// ---------- Brute Force ----------
int upper(vector<int> nums, int target){
    /*TC - O(logN)
      SC - O(1)*/
    int n=nums.size();
    int low=0, high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>target){
            ans=mid;
            high=mid-1;

        }
        else{
            low=mid+1;
        }
    }
    return ans;
}


// ===================================================================================================================================================
//4. Search Insert Position
// ---------- Optimal Solution ----------
int searchInsert(vector<int>& nums, int target) {
    /*TC - O(logN)
      SC - O(1)*/
    int n=nums.size();
    int low=0, high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>=target){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

// ===================================================================================================================================================
//5. Floor and Ceil in Sorted Array
// ---------- Ceil Solution ----------
int ceil(vector<int>& nums, int target) {
    /*TC - O(logN)
      SC - O(1)*/
    int n=nums.size();
    int low=0, high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>=target){
            ans=nums[mid];
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

// ---------- Floor Solution ----------
int floor(vector<int>& nums, int target) {
    /*TC - O(logN)
      SC - O(1)*/
    int n=nums.size();
    int low=0, high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]<=target){
            ans=nums[mid];
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
// ===================================================================================================================================================
//6. Find First and Last Position of Element in Sorted Array
// ---------- Brute Force ----------
vector<int> searchRange_brute(vector<int>& nums, int target) {
    /*TC - O(N)
      SC - O(1)*/
    int n=nums.size();
    int first=-1, last=-1;
    for(int i=0;i<n;i++){
        if(nums[i]==target){
            if(first==-1)   first=i;
            last=i;
        }
    }
    return {first, last};
}

// ---------- Better Solution ----------
int lower(vector<int> nums, int target){
    int n=nums.size();
    int low=0,high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>=target){
            ans=mid;
            high = mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int upper(vector<int> nums, int target){
    int n=nums.size();
    int low=0, high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>target){
            ans=mid;
            high=mid-1;

        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
vector<int> searchRange(vector<int>& nums, int target) {
    /*TC - O(2*logN)
      SC - O(1)*/
    int n=nums.size();
    int lb = lower(nums, target);
    if(lb==n || nums[lb]!=target)   return{-1,-1};
    return {lb, upper(nums, target)-1};
}

// ---------- Optimal Solution ----------
int firstoccur(vector<int>& nums, int n, int target){
    int low=0, high=n-1, first=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            first=mid;
            high=mid-1;
        }
        else if(nums[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return first;
}
int secondoccur(vector<int>& nums, int n, int target){
    int low=0, high=n-1, second=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            second=mid;
            low=mid+1;
        }
        else if(nums[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return second;
}
vector<int> searchRange(vector<int>& nums, int target) {
    /*TC - O(2*logN)
      SC - O(1)*/
    int n=nums.size();
    int first = firstoccur(nums, n, target);
    if(first==-1)   return{-1,-1};
    int second = secondoccur(nums, n, target);
    return {first, second};
}
// ===================================================================================================================================================
//7. Count Occurrences in Sorted Array
// ---------- Optimal Solution ----------
int firstoccur(vector<int>& nums, int n, int target){
    int low=0, high=n-1, first=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            first=mid;
            high=mid-1;
        }
        else if(nums[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return first;
}
int secondoccur(vector<int>& nums, int n, int target){
    int low=0, high=n-1, second=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            second=mid;
            low=mid+1;
        }
        else if(nums[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return second;
}
int cout_occur_optimal(vector<int>& nums, int target){
    /*TC - O(2*logN)
      SC - O(1)*/
    int n=nums.size();
    int first = firstoccur(nums, n, target);
    int second = secondoccur(nums, n, target);
    return (second-first+1);
}


// ===================================================================================================================================================
//8. Search Element in a Rotated Sorted Array
int search(vector<int>& nums, int target) {
    /*TC - O(logN)
      SC - O(1)*/
    int n=nums.size();
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target) return mid;
        if(nums[low]<=nums[mid]){
            if(nums[low]<=target && nums[mid]>=target){
                high=mid-1;
            }
            else    low=mid+1;
        }
        else{
            if(nums[mid]<=target && nums[high]>=target){
                low=mid+1;
            }
            else    high=mid-1;
        }
    }
    return -1;
}


// ===================================================================================================================================================
//9. Search Element in a Rotated Sorted Array II (Duplicates)
bool search_II(vector<int>& nums, int target) {
    /*TC - O(logN)
      SC - O(1)*/
    int n=nums.size();
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target)   return true;
        if(nums[low]==nums[mid] && nums[mid]==nums[high]){
            low=low+1;
            high=high-1;
            continue;
        }
        if(nums[low]<=nums[mid]){
            if(nums[low]<=target && nums[mid]>=target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(nums[mid]<=target && nums[high]>=target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return false;
}

// ===================================================================================================================================================
//10. Minimum in Rotated Sorted Array
int findMin(vector<int>& nums) {
    /*TC - O(logN)
      SC - O(1)*/
    int n=nums.size();
    int low=0, high=n-1;
    int ans=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[low]<=nums[high]){
            ans=min(ans,nums[low]);
            break;
        }
        if(nums[low]<=nums[mid]){
            ans=min(ans, nums[low]);
            low=mid+1;
        }
        else{
            ans=min(ans, nums[mid]);
            high=mid-1;
        }
    }
    return ans;
}


// ===================================================================================================================================================
//11. Find out how many times the array has been rotated
// Just find the smallest value, return its index, which will the result.
int findRotations(vector<int>& nums) {
    /*TC - O(logN)
      SC - O(1)*/
    int n=nums.size();
    int low=0, high=n-1;
    int ans=INT_MAX, index=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[low]<=nums[high]){
            if(nums[low]<ans){
                ans=nums[low];
                index=low;
            }
        }
        if(nums[low]<=nums[mid]){
            if(nums[low]<ans){
                ans=nums[low];
                index=low;
            }
            low=mid+1;
        }
        else{
            if(nums[mid]<ans){
                ans=nums[mid];
                index=mid;
            }
            high=mid-1;
        }
    }
    return index;
}


// ===================================================================================================================================================
//12. Search Single Element in a sorted array
// ---------- Brute Force ----------
int singleNonDuplicate(vector<int>& nums) {
    /*TC - O(N)
      SC - O(1)*/
    int n=nums.size();
    if(n==1)    return nums[0];
    for(int i=0;i<n;i++){
        if(i==0 && nums[i]!=nums[i+1]) return nums[i];
        else if(i==n-1 && nums[i]!=nums[n-2]) return nums[i];
        else{
            if(nums[i]!=nums[i+1] && nums[i]!=nums[i-1])    return nums[i];
        }
    }
    return -1;
}

// ---------- Optimal Solution ----------
int singleNonDuplicate_optimal(vector<int>& nums) {
    /*TC - O(logN)
      SC - O(1)*/
    int n=nums.size();
    if(n==1)    return nums[0];
    if(nums[0]!=nums[1])  return nums[0];
    if(nums[n-1]!=nums[n-2])    return nums[n-1];
    int low=1,high=n-2;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])    return nums[mid];
        if(mid%2==1 && nums[mid]==nums[mid-1] || mid%2==0 && nums[mid]==nums[mid+1]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}


// ===================================================================================================================================================
//13. Find Peak Element
// ---------- Brute Force ----------
int findPeakElement(vector<int>& nums) {
    /*TC - O(N)
      SC - O(1)*/
    int n=nums.size();
    for(int i=0;i<n;i++){
        if((i==0 || nums[i]>nums[i-1]) && (i==n-1 || nums[i]>nums[i+1]))    return i;
    }
    return -1;
}

// ---------- Optimal Solution ----------
int findPeakElement(vector<int>& nums) {
    /*TC - O(logN)
      SC - O(1)*/
    int n=nums.size();
    if(n==1)    return 0;
    if(nums[0]>nums[1]) return 0;
    if(nums[n-1]>nums[n-2]) return n-1;
    int low=1, high=n-2;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])  return mid;
        else if(nums[mid]>nums[mid-1])   low=mid+1;
        else if(nums[mid]>nums[mid+1])   high=mid-1;
        else   low=mid+1;
    }
    return -1;
}
