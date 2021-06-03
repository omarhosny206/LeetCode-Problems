// https://leetcode.com/problems/numbers-with-same-consecutive-differences/

class Solution
{
    vector<int> result;

public:
    vector<int> numsSameConsecDiff(int n, int k)
    {
        DFS(n, k, 0);
        return result;
    }

    void DFS(int n, int k, int current)
    {
        if (n == 0)
        {
            result.push_back(current);
            return;
        }

        int start = (current == 0) ? 1 : 0;

        for (int i = start; i <= 9; ++i)
        {
            if (current == 0)
                DFS(n - 1, k, current * 10 + i);

            else
            {
                int last = current % 10;

                if (abs(i - last) == k)
                    DFS(n - 1, k, current * 10 + i);
            }
        }
    }
};