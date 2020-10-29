// https://leetcode.com/problems/sort-colors/

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        quicksort(nums, 0, nums.size() - 1);
    }

    void quicksort(vector<int> &nums, int left, int right)
    {
        if (left < right)
        {
            int pivotIndex = partition(nums, left, right);
            quicksort(nums, left, pivotIndex - 1);
            quicksort(nums, pivotIndex, right);
        }
    }

    int partition(vector<int> &nums, int left, int right)
    {
        int pivotIndex = left + (right - left) / 2;
        int pivotValue = nums[pivotIndex];
        int i = left, j = right;
        int temp;
        while (i <= j)
        {
            while (nums[i] < pivotValue)
            {
                i++;
            }
            while (nums[j] > pivotValue)
            {
                j--;
            }
            if (i <= j)
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
        }
        return i;
    }
};