class Solution
{
public:
    vector<int> preGreaterEle(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> result(n, -1);
        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (arr[j] > arr[i])
                {

                    result[i] = arr[j];
                    break;
                }
            }
        }

        return result;
    }
};