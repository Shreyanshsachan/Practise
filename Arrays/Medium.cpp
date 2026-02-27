#include<bits/stdc++.h>
using namespace std;

// ===================================================================================================================================================
//1. Two Sum : Check if a pair with given sum exists in Array
// ---------- Better Solution ----------
vector<int> twosum_better(vector<int> arr, int k){
    /*TC - O(N)
      SC - O(N)*/
    unordered_map<int, int> mpp;
    for(int i=0;i<arr.size();i++){
        int rem = k-arr[i];
        if(mpp.find(rem)!=mpp.end()){
            return {mpp[rem],i};
        }
        mpp[arr[i]] = i;
    }
    return {-1,-1};
}
// ---------- Optimal Solution ----------
vector<int> twosum_optimal(vector<int> arr, int k){
    /*TC - O(N log N)
      SC - O(N)*/
    int i=0, j=arr.size()-1;
    vector<pair<int, int>> original;
    for(int i=0;i<arr.size();i++){
        original.push_back({arr[i],i});
    }
    sort(original.begin(), original.end());
    while(i<j){
        if(original[i].first + original[j].first==k)    return {original[i].second,original[j].second};
        else if(original[i].first + original[j].first>k)    j--;
        else i++;
    }
    return {-1,-1};
}


// ===================================================================================================================================================
//2. Sort an array of 0s, 1s and 2s
// ---------- Brute Force ----------
void sortZeroOneTwo(vector<int>& nums) {
    /*TC - O(N)
    SC - O(1)*/
    int count0 = 0, count1 = 0, count2 = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == 0) count0++;
        else if(nums[i] == 1) count1++;
        else count2++;
    }
    int index = 0;
    while(count0--) {
        nums[index++] = 0;
    }
    while(count1--) {
        nums[index++] = 1;
    }
    while(count2--) {
        nums[index++] = 2;
    }
}
// ---------- Optimal Solution ----------
void sortColors(vector<int>& nums) {
    /*TC - O(N)
    SC - O(1)*/
    int low = 0, mid =0, high = nums.size()-1;
    while(mid<=high){
        if(nums[mid]==2){
            swap(nums[mid], nums[high]);
            high--;
        }
        else if(nums[mid]==0){
            swap(nums[mid], nums[low]);
            low++; mid++;
        }
        else {
            mid++;
        }
    }
}


// ===================================================================================================================================================
//3. Find the Majority Element that occurs more than N/2 times
// ---------- Brute Force ----------
int majority(vector<int>& nums){
    /*TC - O(N²)
    SC - O(1)*/
    for(int i=0;i<nums.size();i++){
        int count=0;
        for(int j=0;j<nums.size();j++){
            if(nums[i]==nums[j]){
                count++;
            }
        }
        if(count>nums.size()/2) return nums[i];
    }
    return -1;
}
// ---------- Better Solution ----------
int majority_better(vector<int>& nums){
    /*TC - O(N)
    SC - O(N)*/
    unordered_map<int,int> mpp;
    for(int i=0;i<nums.size();i++){
        mpp[nums[i]]++;
        if(mpp[nums[i]]>nums.size()/2)    return nums[i];
    }
    return -1;
}
// ---------- Optimal Solution / Moore Voting Algorithm ----------
int majority_optional(vector<int>& nums){
    /*TC - O(N)
    SC - O(1)*/
    int ele;
    int cnt=0;
    for(int i=0;i<nums.size();i++){
        if(cnt==0){
            ele=nums[i];
            cnt++;
        }
        else if(ele==nums[i])    cnt++;
        else if(ele!=nums[i])    cnt--;
    }
    int cnt1=0;
    for(int i=0;i<nums.size();i++){
        if(ele==nums[i])    cnt1++;
    }
    if(cnt1>nums.size()/2)  return ele;
    return -1;
}


// ===================================================================================================================================================
//4. Kadane's Algorithm : Maximum Subarray Sum in an Array
// ---------- Brute Force ----------
int kadane_better(vector<int>& nums){
    /*TC - O(N²)
    SC - O(1)*/
    int maxi=INT_MIN;
    for(int i=0;i<nums.size();i++){
        int sum=0;
        for(int j=i;j<nums.size();j++){
            sum+=nums[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}
// ---------- Optimal Solution ----------
int kadane_optimal(vector<int>& nums){
    /*TC - O(N)
    SC - O(1)*/
    int maxi=INT_MIN;
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        maxi=max(maxi,sum);
        if(sum<0)   sum=0;
    }
    return maxi;
}


// ===================================================================================================================================================
//5. Kadane's Algorithm : Maximum Subarray Sum in an Array (print the subarray that has the maximum sum)
// ---------- Brute Force ----------
void kadane_sub(vector<int>& nums){
    /*TC - O(N)
    SC - O(1)*/
    int maxi=INT_MIN;
    int sum=0;
    int st=-1, end=-1;
    int start=0;
    for(int i=0;i<nums.size();i++){
        if(sum==0)  start = i;
        sum+=nums[i];
        if(sum>maxi){
            maxi=sum;
            end=i;
            st=start;
        }
        if(sum<0){
            sum=0;
        }
    }
    cout << "The subarray is: [";
    for (int i = st; i <= end; i++) {
        cout << nums[i] << " ";
    }
    cout << "]" << endl;
}


// ===================================================================================================================================================
//6. 	Stock Buy and Sell
// ---------- Brute Force ----------
int stock_brute(vector<int>& prices){
    /*TC - O(N²)
    SC - O(1)*/
    int maxi=0;
    for(int i=0;i<prices.size()-1;i++){
        for(int j=i+1;j<prices.size();j++){
            maxi=max(maxi, prices[j]-prices[i]);
        }
    }
    if(maxi<=0) return 0;
    return maxi;
}
// ---------- Optimal Solution ----------
int stock_optimal(vector<int>& prices){
    /*TC - O(N)
    SC - O(1)*/
    int minprice = INT_MAX;
    int maxi = 0;
    for(int price:prices){
        if(price<minprice){
            minprice = price;
        }
        maxi=max(maxi, price-minprice);
    }
    return maxi;
}


// ===================================================================================================================================================
//7. Rearrange Array Elements by Sign
// ---------- Brute Force ----------
void rearrange_brute(vector<int>& nums){
    /*TC - O(N+N/2)
    SC - O(N/2 + N/2) = O(N)*/
    vector<int> neg,pos;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>=0)  pos.push_back(nums[i]);
        else neg.push_back(nums[i]);
    }
    for(int i=0;i<nums.size()/2;i++){
        nums[2*i]=pos[i];
        nums[2*i+1]=neg[i];
    }
}
// ---------- Optimal Solution ----------
vector<int> rearrange_optimal(vector<int>& nums){
    /*TC - O(N)
    SC - O(N)*/
    int n=nums.size();
    vector<int> ans(n,0);
    int pos=0, neg=1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>0){
            ans[pos]=nums[i];
            pos+=2;
        }
        else{
            ans[neg]=nums[i];
            neg+=2;
        }
    }
    return ans;
}

// ===================================================================================================================================================
//8. next_permutation : find next lexicographically greater permutation
// ---------- Brute Force ----------
vector<int> nextper_brute(vector<int>& nums){
    /*TC - O(N!*N)
    SC - O(N!)*/
    vector<int> org = nums;
    vector<vector<int>> all;
    sort(nums.begin(),nums.end());
    do{
        all.push_back(nums);
    }while(next_permutation(nums.begin(),nums.end()));
    for(int i=0;i<all.size();i++){
        if(all[i]==org){
            if(i==all.size()-1){
                return all[0];
            }
            return all[i+1];
        }
    }
    return nums;
}
// ---------- Optimal Solution ----------
void nextper_optimal(vector<int>& nums){
    /*From right, find breaking point
    If breaking point exists: swap with just next greater and reverse suffix.
    Else: reverse entire array.*/
    /*TC - O(N!)
    SC - O(1)*/
    int ind = -1;
    int n = nums.size();
    for(int i=n-2;i>0;i--){
        if(nums[i]>nums[i-1]){
            ind=i-1;
            break;
        }
    }
    if(ind==-1){
        reverse(nums.begin(), nums.end());
        return;
    }
    for(int j=n-2;j>=0;j--){
        if(nums[j]>nums[ind]){
            swap(nums[j], nums[ind]);
            break;
        }
    }
    reverse(nums.begin()+ind+1, nums.end());
}
// ---------- Optimal Solution 2 ----------
vector<int> nextper_better(vector<int>& nums){
    /*TC - O(N)
    SC - O(1)*/
    next_permutation(nums.begin(), nums.end());
    return nums;
}

// ===================================================================================================================================================
//9. Leaders in an Array
// ---------- Brute Force ----------
vector<int> leader_brute(vector<int>& nums){
    /*TC - O(N²)
    SC - O(1)*/
    vector<int> lead;
    for(int i=0;i<nums.size();i++){
        bool leader=true;
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]<nums[j]){
                leader=false;
                break;
            }
        }
        if(leader==true)    lead.push_back(nums[i]);
    }
    return lead;
}
// ---------- Optimal Solution ----------
vector<int> leader_optimal(vector<int>& nums){
    /*TC - O(N)
    SC - O(1)*/
    int n=nums.size();
    int great=nums[n-1];
    vector<int> ans;
    ans.push_back(great);
    for(int i=n-2;i>=0;i--){
        if(nums[i]>great){
            ans.push_back(nums[i]);
            great=nums[i];
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


// ===================================================================================================================================================
//10. Longest Consecutive Sequence in an Array
// ---------- Brute Force ----------
bool linearsearch(vector<int>& nums, int val){
    /*TC - O(N²)
    SC - O(1)*/
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]==val)    return true;
    }
    return false;
}
int longestConsecutive_brute(vector<int>& nums) {
    int n=nums.size();
    if(n==0)    return 0;
    int lon = 1;
    for(int i=0;i<n;i++){
        int val=nums[i];
        int cnt=1;
        while(linearsearch(nums, val+1)==true){
            cnt++;
            val=val+1;
        }
        lon = max(lon,cnt);
    }
    return lon;
}
// ---------- Better Solution ----------
int longestConsecutive_better(vector<int>& nums) {
    /*TC - O(n log n)
    SC - O(1)*/
    int n=nums.size();
    if(n==0)    return 0;
    int lon=1;
    int cnt=0;
    int lastsmall=INT_MIN;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(nums[i]-1==lastsmall){
            cnt+=1;
            lastsmall=nums[i];
        }
        else if(nums[i]!=lastsmall){
            cnt=1;
            lastsmall=nums[i];
        }
        lon = max(lon,cnt);
    }
    return lon;
}
// ---------- Optimal Solution ----------
int longestConsecutive_optimal(vector<int>& nums) {
    /*TC - O(N)
    SC - O(N)*/
    int n=nums.size();
    if(n==0)    return 0;
    unordered_set<int> se;
    int lon=1,x;
    for(int i=0;i<n;i++){
        se.insert(nums[i]);
    }
    for(auto it:se){
        int cnt=1;
        if(se.find(it-1)==se.end()){
            cnt=1;
            x=it;
        }
        while(se.find(x+1)!=se.end()){
            cnt+=1;
            x+=1;
        }
        lon=max(lon,cnt);
    }
    return lon;          
}

// ===================================================================================================================================================
//11. Set Matrix Zero
// ---------- Brute Force ----------
void setZeroes(vector<vector<int>>& matrix) {
    /*TC - O(m * n * (m + n))
    SC - O(N)*/
    int m=matrix.size();
    int n=matrix[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j] == 0){
                for(int col=0;col<n;col++){
                    if (matrix[i][col] != 0)
                    matrix[i][col]=-1;
                }
                for(int row=0;row<m;row++){
                    if (matrix[row][j] != 0)
                    matrix[row][j]=-1;
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j] == -1){
                matrix[i][j]=0;
            }
        }
    }
}
// ---------- Better Solution ----------
void setZeroes_better(vector<vector<int>>& matrix) {
    /*TC - O(m × n)
    SC - O(m × n)*/ 
    int m=matrix.size();
    int n=matrix[0].size();
    vector<int> row(m,1);
    vector<int> col(n,1);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j] == 0){
                row[i]=0;
                col[j]=0;          
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(row[i]==0 || col[j]==0){
                matrix[i][j]=0;
            }
        }
    }
}
// ---------- Optimal Solution ----------
void setZeroes_optimal(vector<vector<int>>& matrix) {
    /*TC - O(m × n)
    SC - O(1)*/ 
    int m=matrix.size();
    int n=matrix[0].size();
    int col0=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j] == 0){
                matrix[i][0]=0;
                if(j!=0)
                    matrix[0][j]=0;
                else
                    col0=0;
            }
        }
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(matrix[0][j]==0 || matrix[0][j]==0){
                matrix[i][j]=0;
            }
        }
    }
    if(matrix[0][0]==0){
        for(int j=0;j<n;j++) matrix[0][j]=0;
    }
    if(col0==0){
        for(int i=0;i<n;i++){
            matrix[i][0]=0;
        }
    }
}


// ===================================================================================================================================================
//12. Rotate Image by 90 degree
// ---------- Brute Force ----------
vector<vector<int>> rotate(vector<vector<int>>& matrix) {
    /*TC - O(N²)
    SC - O(N²)*/
    int n=matrix.size();
    vector<vector<int>> ans(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[j][n-1-i] = matrix[i][j];
        }
    }
    return ans;
}
// ---------- Optimal Solution ----------
void rotate(vector<vector<int>>& matrix) {
    /*TC - O(N²)
    SC - O(1)*/
    int n=matrix.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}


// ===================================================================================================================================================
//13. Spiral Traversal of Matrix
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    /*TC - O(m × n)
    SC - O(1)*/
    int n=matrix.size();
    int m=matrix[0].size();
    int top=0,bottom=n-1,left=0,right=m-1;
    vector<int> ans;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[bottom][i]);
                }
            }
            bottom--;
            if(left<=right)
            {
                for(int i=bottom;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left--;
            }
    }
    return ans;
}


// ===================================================================================================================================================
//14. Count Subarray sum Equals K
// ---------- Brute Force ----------
int subarraySum(vector<int>& nums, int k) {
    /*TC - O(N²)
    SC - O(1)*/
    int count=0;
    for(int i=0;i<nums.size();i++){
        int sum=0;
        for(int j=i;j<nums.size();j++){
            sum+=nums[j];
            if(sum==k)  count++;
        }
    }
    return count;
}
// ---------- Optimal Solution ----------
int subarraySum(vector<int>& nums, int k) {
    /*TC - O(N)
    SC - O(N)*/
    unordered_map<int, int> mpp;
    mpp[0]=1;
    int count=0,presum=0;
    for(int i=0;i<nums.size();i++){
        presum+=nums[i];
        int remove=presum-k;
        count+=mpp[remove];
        mpp[presum]+=1;
    }
    return count;
}
