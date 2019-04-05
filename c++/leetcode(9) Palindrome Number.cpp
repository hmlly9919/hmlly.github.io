class Solution {
public:
    bool isPalindrome(int x) {
        long t = x;
	    string integer;
	    string standard;
	    string::iterator begin = integer.begin();
	    if (t < 0)
	    {
		    integer.insert(begin, '-');
		    t = -t;
	    }
	    while (t)
	    {
		    integer.insert(begin, '0' + t % 10);
		    t /= 10;
	    }
	    standard = integer;
	    reverse(begin, integer.end());
	    if (standard == integer)
	    {
	    	return true;
	    }
	    else
	    {
		    return false;
	    }
    }
};