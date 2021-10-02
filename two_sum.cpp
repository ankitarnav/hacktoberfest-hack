/*Link Of Question : https://leetcode.com/problems/two-sum/

1. Two sum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Sample Input : nums = [2,7,11,15], target = 9
Sample output : [0.1]
Time Complexity : O(N)
Space Complexity : O(N)

*/

// code

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<pair<int, int>> a;
    for (int i = 0; i < nums.size(); i++)
        a.push_back({nums[i], i});
    sort(a.begin(), a.end());
    int l = 0, r = a.size() - 1;
    while (l < r)
    {
        if (a[l].first + a[r].first == target)
            return {a[l].second, a[r].second};
        else if (a[l].first + a[r].first < target)
            l++;
        else
            r--;
    }
    return {-1, -1};
}

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> ans = twoSum(a, target);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}
