#include<bits/stdc++.h>
using namespace std;

// ===================================================================================================================================================
//1. Program to generate Pascal's Triangle
// ---------- Brute Force ----------
vector<vector<int>> generate(int numRows) {
    /*TC - O(N²)
      SC - O(N²)*/
    vector<vector<int>> triangle;
    for (int i = 0; i < numRows; i++) {
        vector<int> row(i + 1, 1);
        for (int j = 1; j < i; j++) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle.push_back(row);
    }
    return triangle;
}
// ---------- Better Solution ----------
int findncr(int n, int r){
    /*TC - O(N²)
      SC - O(N²)*/
    if(r==0 || r==n)    return 1;
    long long res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i)/(i+1);
    }
    return res; 
}
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for(int i=0;i<numRows;i++){
        vector<int> ans1;
        for(int j=0;j<=i;j++){
            ans1.push_back(findncr(i,j));
        }
        ans.push_back(ans1);
    }
    return ans;
}
// ---------- Optimal Solution ----------
vector<int> getRow_optimal(int rowIndex) {
    /*TC - O(N)
      SC - O(N)*/
    vector<int> ans;
    ans.push_back(1);
    int res=1;
    for(int i=1;i<=rowIndex;i++){
        res=res*(rowIndex-i+1)/(i);
        ans.push_back(res);
    }
    return ans;
}
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for(int i=0;i<numRows;i++){
        ans.push_back(getRow_optimal(i));
    }
    return ans;
}


// ===================================================================================================================================================
//2. Majority Elements(&gt;N/3 times) | Find the elements that appears more than N/3 times in the array
// ---------- Brute Force ----------
vector<int> majorityElement(vector<int>& nums) {
    /*TC - O(N²)
      SC - O(1)*/
    vector<int> ans;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(ans.size()==0 || ans[0]!=nums[i])
        {
            int cnt=0;
            for(int j=i;j<n;j++){
                if(nums[i]==nums[j]){
                    cnt++;
                }
            }
            if(cnt>n/3) ans.push_back(nums[i]);
        }
        if(ans.size()==2) break;
    }
    return ans;
}
// ---------- Better Solution ----------
vector<int> majorityElement(vector<int>& nums) {
    /*TC - O(N*logN)
      SC - O(N)*/
    vector<int> ans;
    unordered_map<int, int> mpp;
    int n=nums.size();
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
        if(mpp[nums[i]]==(n/3+1)){
            ans.push_back(nums[i]);
        }
        if(ans.size()==2)   break;
    }
    return ans;
}
// ---------- Optimal Solution ----------
vector<int> majorityElement(vector<int>& nums) {
    /*TC - O(N)
      SC - O(1)*/
    int cnt1=0,cnt2=0;
    int el1=INT_MIN,el2=INT_MIN;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(cnt1==0 && nums[i]!=el2){
            el1=nums[i];
            cnt1=1;
        }
        else if(cnt2==0 && nums[i]!=el1){
            el2=nums[i];
            cnt2=1;
        }
        else if(el1==nums[i])   cnt1++;
        else if(el2==nums[i])   cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    vector<int> ans;
    cnt1=0;cnt2=0;
    for(int i=0;i<n;i++){
        if(el1==nums[i]) cnt1++;
        else if(el2==nums[i]) cnt2++;
    }
    if(cnt1 >= n/3+1)   ans.push_back(el1);
    if(cnt2 >= n/3+1 && el1 != el2)   ans.push_back(el2);
    return ans;
}


// ===================================================================================================================================================
//3. 3 Sum : Find triplets that add up to a zero
// ---------- Brute Force ----------
vector<vector<int>> threeSum(vector<int>& nums) {
    /*TC - O(N³ * log(no. of unique triplets))
      SC - O(2 * no. of the unique triplets)*/
    set<vector<int>> st;
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
// ---------- Better Solution ----------
vector<vector<int>> threeSum(vector<int>& nums) {
    /*TC - O(N² * log(no. of unique triplets))
      SC - O(2 * no. of the unique triplets) + O(N)*/
    set<vector<int>> st;
    int n=nums.size();
    for(int i=0;i<n;i++){
        set<int> k;
        for(int j=i+1;j<n;j++){
            int rem=-(nums[i]+nums[j]);
            if(k.find(rem)!=k.end()){
                vector<int> temp = {nums[i],nums[j],rem};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            k.insert(nums[j]);
        }
    }
    return vector<vector<int>> (st.begin(), st.end());
}
// ---------- Optimal Solution ----------
vector<vector<int>> threeSum(vector<int>& nums) {
    /*TC - O(N²)
      SC - O(no. of quadruplets) To store answers*/
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int j=i+1,k=n-1;
        while(j<k){
            if(nums[i]+nums[j]+nums[k] < 0){
                j++;
            }
            else if(nums[i]+nums[j]+nums[k] > 0){
                k--;
            }
            else{
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1])   j++;
                while(j<k && nums[k]==nums[k+1])   k--;
            }
        }
    }
    return ans;
}


// ===================================================================================================================================================
//4. 4 Sum | Find Quads that add up to a target value
// ---------- Brute Force ----------
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    /*TC - O(N⁴ * log(no. of unique triplets))
      SC - O(2 * no. of the unique triplets)*/
    int n=nums.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    long long sum = 1LL * nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum==target){
                        vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}
// ---------- Better Solution ----------
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    /*TC - O(N³ * log(no. of unique triplets))
      SC - O(2 * no. of the unique triplets) + O(N)*/
    set<vector<int>> st;
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<int> hashset;
            for(int k=j+1;k<n;k++){
                long long rem = (long long)target - (long long)nums[i] - (long long)nums[j] - (long long)nums[k];
                if(rem >= INT_MIN && rem <= INT_MAX && hashset.find(rem)!=hashset.end()){
                    vector<int> temp={nums[i], nums[j], nums[k], int(rem)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
// ---------- Optimal Solution ----------
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    /*TC - O(N³)
      SC - O(no. of quadruplets) To store answers*/
    int n=nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i=0;i<n;i++){
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for(int j=i+1;j<n;j++){
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int k=j+1;
            int l=n-1;
            while(k<l){
                long long sum =
                (long long)nums[i] +
                (long long)nums[j] +
                (long long)nums[k] +
                (long long)nums[l];
                if(sum < target){
                    k++;
                }
                else if(sum > target){
                    l--;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                    k++;
                    l--;
                    while(k<l && nums[k]==nums[k-1])    k++;
                    while(k<l && nums[l]==nums[l+1])    l--;
                }
            }
        }
    }
    return ans;
}


// ===================================================================================================================================================
//5. Length of the longest subarray with zero Sum

// ===================================================================================================================================================
//6. Count the number of subarrays with given xor K
// ---------- Brute Force ----------

// ---------- Optimal Solution ----------


// ===================================================================================================================================================
//7. Merge Overlapping Sub-intervals
// ---------- Brute Force ----------
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    /*TC - O(N²)
      SC - O(N)*/
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> ans;
    int n=intervals.size();
    for(int i=0;i<n;i++){
        int start=intervals[i][0];
        int end=intervals[i][1];
        if(!ans.empty() && end<=ans.back()[1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(intervals[j][0] <= end){
                end = max(end,  intervals[j][1]);

            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}
// ---------- Optimal Solution ----------
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    /*TC - O(N*logN) + O(N)
      SC - O(N)*/
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> ans;
    int n=intervals.size();
    for(int i=0;i<n;i++){
        if(ans.empty() || intervals[i][0] > ans.back()[1]){
            ans.push_back(intervals[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
}


// ===================================================================================================================================================
//8. Merge two Sorted Arrays Without Extra Space
// ---------- Optimal Solution ----------
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    /*TC - O(N+M)
      SC - O(1)*/
    for (int i=0;i<n;i++){
        nums1[i+m] = nums2[i];
    }
    sort(nums1.begin(),nums1.end());
}


// ===================================================================================================================================================
//9. Find the repeating and missing numbers
// ---------- Brute Force ----------
vector<int> repeatandmissing_brute(vector<int> nums){
    /*TC - O(N²)
      SC - O(1)*/
    int n=nums.size();
    int repeat=-1, miss=-1;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(i==nums[j]){
                cnt++;
            }  
        }
        if(cnt==2)  repeat=i;
        else if(cnt==0)  miss=i;
    }
    vector<int> ans={miss,repeat};
    return ans; 
}
// ---------- Better Solution ----------
vector<int> repeatandmissing_better(vector<int> nums){
    /*TC - O(2*N)
      SC - O(N)*/
    int n=nums.size();
    int repeat=-1, miss=-1;
    int hash[n+1]={0};
    for(int i=0;i<n;i++){
        hash[nums[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(hash[i]==2)  repeat=i;
        else if(hash[i]==0) miss=i;
        if(repeat!=-1 && miss !=-1) break;
    }
    return {miss,repeat};
}
// ---------- Optimal Solution ----------
vector<int> repeatandmissing_optimal(vector<int> nums){
    /*TC - O(N)
      SC - O(1)*/
    long long n=nums.size();
    long long Sn = (n*(n+1))/2;
    long long S2n = (n*(n+1)*(2*n+1))/6;
    long long S=0,S2=0;
    for(int i=0;i<n;i++){
        S+=nums[i];
        S2+=nums[i]*nums[i];
    }
    long long val1 = S - Sn;
    long long val2 = S2 - S2n;
    val2=val2/val1;
    long long x=(val2+val1)/2;
    long long y=x-val1;
    return {int(x),int(y)};
}


// ===================================================================================================================================================
//10. Count inversions in an array
// ---------- Brute Force ----------
int countinversion_brute(vector<int> nums){
    /*TC - O(N²)
      SC - O(1)*/
    int n=nums.size();
    int count=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]>nums[j]){
                count++;
            }
        }
    }
    return count;
}
// ---------- Optimal Solution ----------
int merge(vector<int>& a, int low, int mid, int high){
    /*TC - O(N*logN)
      SC - O(N)*/
    vector<int> temp;
    int left=low;
    int right=mid+1;
    int cnt=0;
    while(left<=mid && right <=high){
        if(a[left] <= a[right]){
            temp.push_back(a[left]);
            left++;
        }
        else{
            temp.push_back(a[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }
    while (left <= mid) {
        temp.push_back(a[left]);
        left++;
    }
    while (right <= high) { 
        temp.push_back(a[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        a[i] = temp[i - low];
    }
    return cnt;
}
int mergesort(vector<int>& a, int low, int high){
    int cnt=0;
    if(low>=high)   return cnt;
    int mid=(low+high)/2;
    cnt += mergesort(a, low, mid);
    cnt += mergesort(a, mid+1, high);
    cnt += merge(a, low, mid, high);
    return cnt;
}
int count_inversion_optimal(vector<int> nums){
    int n=nums.size();
    return mergesort(nums, 0, n-1);
}


// ===================================================================================================================================================
//11. Count Reverse Pairs
// ---------- Brute Force ----------
int reversePairs(vector<int>& nums) {
    /*TC - O(N²)
      SC - O(1)*/
    int n=nums.size();
    int cnt=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]>(long long)2*nums[j]){
                cnt++;
            }
        }
    }
    return cnt;
}
// ---------- Optimal Solution ----------



// ===================================================================================================================================================
//12. Maximum Product Subarray in an Array
// ---------- Brute Force ----------
int maxProduct(vector<int>& nums) {
    /*TC - O(N²)
      SC - O(1)*/
    int n=nums.size();
    int maxx=INT_MIN;
    for(int i=0;i<n;i++){
        int prod=nums[i];
        for(int j=i+1;j<n;j++){
            prod=prod*nums[j];
            maxx=max(maxx,prod);
        }
    }
    return maxx;
}
// ---------- Better Solution ----------
int maxProduct_better(vector<int>& nums) {
    /*TC - O(N)
      SC - O(1)*/
    int n=nums.size();
    int pre=1,suf=1;
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        if(pre==0)  pre=1;
        if(suf==0)  suf=1;
        pre*=nums[i];
        suf*=nums[n-1-i];
        ans=max(ans,max(pre,suf));
    }
    return ans;
}
// ---------- Optimal Solution ----------
int maxProduct_optimal(vector<int>& nums) {
    /*TC - O(N)
      SC - O(1)*/
    int n=nums.size();
    int res=nums[0];
    int maxx=nums[0],minn=nums[0];
    for(int i=0;i<n;i++){
        int cur=nums[i];
        if(cur<0)   swap(maxx,minn);
        maxx = max(cur, maxx*cur);
        minn = min(cur, minn*cur);
        res = max(res,maxx);
    }
    return res;
}
