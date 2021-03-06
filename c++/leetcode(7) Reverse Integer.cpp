class Solution {
public:
	int reverse(int x) {
	    int flag = 0;
	    long long ret = 0;
        long long t = x;
	    if (t < 0)
	    {
		    t = -t;
		    flag = 1;
	    }
	    vector<long long> digits;
	    while (t)
	    {
		    digits.push_back(t % 10);
		    t /= 10;
	    }
	    auto end = digits.rend();
	    long long i = 0, j;
	    for (auto iter = digits.rbegin(); iter != end; ++iter)
	    {
		    for (j = 0; j != i; ++j)
			{
				*iter = 10 * (*iter);
			}
			    ret += *iter;
			    ++i;
		}
	    if (flag == 1)
	    {
		    ret = -ret;
	    }
        if((ret >= -2147483648)&&(ret <= 2147483647))
        {
            return ret;
        }
	    return 0;
    }
};