#include <string>
using namespace std;
class Solution
{
public:
    string replaceSpace(string s)
    {
        string t = "%20";
        string res = "";

        for (int i = 0; i < s.length(); i++)
            if (s[i] == ' ')
                res += t;
            else
                res += s[i];

        return res;
    }
};