#include "../headers/solution.h"


class Solution
{

public:
    //Find Pivot Index
    int pivotIndex(vector<int> &nums);

    //Largest Number At Least Twice of Others
    int largestIndex(vector<int> &nums);

    //Plus One
    vector<int> plusOne(vector<int> &digits);

    //Binary search in a sorted array
    int search(vector<int> &nums, int target);

    //First Bad Version
    // int firstBadVersion(int n);

    // Diagonal Traverse
    vector<int> findDiagonalOrder(vector<vector<int>>& mat);

    //Add Two Numbers
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

    //Two Sum
    vector<int> twoSum(vector<int>& nums, int target);
};

//Find Pivot Index
int Solution::pivotIndex(vector<int> &nums)

{
    int right = 0, left = 0;
    for (int const &n : nums)
    {
        right += n;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        right -= nums[i];

        if (left == right)
        {
            return i;
        }
        else
        {
            left += nums[i];
        }
    }
    return -1;
}

//Largest Number At Least Twice of Others
int Solution::largestIndex(vector<int> &nums)
{
    const auto max = distance(nums.begin(), max_element(nums.begin(), nums.end()));
    for (int i = 0; i < nums.size(); i++)
    {
        if (i != max && 2 * nums[i] > nums[max])
        {
            return -1;
        }
    }
    return max;
}

//Plus One
vector<int> Solution::plusOne(vector<int> &digits)
{
    int carry = 1;
    for (int i = digits.size() - 1; 0 <= i && carry; --i)
    {
        carry += digits[i];
        digits[i] = carry % 10;
        carry /= 10;
    }
    if (carry)
    {
        digits.insert(digits.begin(), carry);
    }
    return digits;
}

//Binary search in a sorted array
int Solution::search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

//First Bad Version
// int firstBadVersion(int n) {
//     long long int beg,last,mid;
//     beg = 1 , last = n;
//     long int pos = 1;
//     while(beg<=last){
//         mid = beg + (last-beg)/2;
//         bool x = isBadVersion(mid);
//         if(x == true){
//             pos = mid;
//             last = mid-1;
//         }
//         else
//             beg = mid+1;
//     }
//     return pos;
// }

//Add Two Numbers
vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    
    vector<int> result;
    
    if(mat.size() == 0 || mat[0].size() == 0){
        return result;
    }
    
    int m = mat.size();
    int n = mat[0].size();
    
    vector<vector<int>> dirs = {{-1,1},{1,-1}};
    
    int row = 0; 
    int col = 0;
    int d = 0;
    
    for (int i = 0; i < m * n; i++){
        
        result.push_back(mat[row][col]);
        
        row += dirs[d][0];
        col += dirs[d][1];
        
        if (row >= m) { 
            row = m - 1; 
            col += 2; 
            d = 1 - d;
        }
        
        if (col >= n) { 
            col = n - 1; 
            row += 2; 
            d = 1 - d;
        }
        
        if (row < 0)  { 
            row = 0; 
            d = 1 - d;
        }
        
        if (col < 0)  { 
            col = 0; 
            d = 1 - d;
        }
    }
    
    return result;
}

//Add Two Numbers
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode head;
    ListNode* temp = &head;
    while (l1 || l2) {
        int val = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        carry = val/10;
        temp->next = new ListNode(val%10);
        temp = temp->next;
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    if (carry)
        temp->next = new ListNode(carry);
    return head.next;
}

//Two Sum
vector<int> twoSum(vector<int>& nums, int target) {
    int a=0;
    int b=0;
    for(int i=0;i<nums.size()-1;i++)
    {
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[i]+nums[j]==target)
            {
                a=i;
                b=j;
            }
        }
    }
    return {a,b};
}