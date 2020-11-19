/* ------------------------------------------------------------------|
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:

必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/move-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	双指针法
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：8.1 MB, 在所有 C++ 提交中击败了81.94%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void moveZeroes(vector<int>& nums) {
    /*  12ms    49.15%
    *   9.1MB   25.00%
    */
    //int k = 0;
    //for (int i = nums.size() - 1; i >= 0; i--) {
    //    if (nums[i] == 0) {
    //        nums.erase(nums.begin() + i);
    //        nums.emplace_back(k);
    //    }
    //}

    /*  20ms    13.36%
    *   9.2MB   18.16%
    */  
    //int count = 0;
    //int i = 0;
    //while (i < nums.size()) {
    //    if (!nums[i]) {
    //        nums.erase(nums.begin() + i);
    //        count++;
    //    }
    //    else {
    //        i++;
    //    }
    //}
    //nums.insert(nums.end(), count, 0);

    /*  8ms    91.02%
    *   9MB   33.60%
    */
    int i = 0;
    for (int j = 0; j < nums.size(); j++) {
        if (nums[j]) {
            nums[i++] = nums[j];
        }
    }
    while (i < nums.size()) {
        nums[i++] = 0;
    }

    /*  4ms    99.51%
    *   9.1MB   25.42%
    */
    //stable_partition(nums.begin(), nums.end(), [](const int& u) {
    //    return u != 0;
    //    });
}

int main() {
    vector<int> nums = { 0,1,0,2,12 };
    moveZeroes(nums);
}