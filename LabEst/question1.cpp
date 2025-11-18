class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        freq[0] = 1;
        int prefix = 0;
        int count = 0;
        for (int x : nums)
        {
            prefix += x;
            int need = prefix - k;

            if (freq.find(need) != freq.end())
            {
                count += freq[need];
            }
            freq[prefix]++;
        }
        return count;
    }
};
