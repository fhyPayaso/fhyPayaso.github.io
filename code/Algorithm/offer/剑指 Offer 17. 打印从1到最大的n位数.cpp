#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<int> printNumbers(int n)
    {

        vector<int> res;
        unsigned long long l = pow(10, n);
        for (int i = 1; i < l; i++)
            res.push_back(i);
        return res;
    }
};