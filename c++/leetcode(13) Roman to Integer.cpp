class Solution {
public:
	int romanToInt(string s) 
	{
		int result = 0;
	    map<char, int> trans = { {'I' , 1}, {'V' , 5}, {'X', 10}, {'L', 50}, {'C',100},     {'D', 500}, {'M', 1000} };
	    string::iterator begin = s.begin();
	    string::iterator end = s.end();
	    string::iterator iter;
	    for (iter = begin; iter != end; ++iter)
	    {
	    	if (iter + 1 != end)
		    {
			    if (trans[*(iter + 1)] > trans[*iter])
		    	{
		    		result += trans[*(iter + 1)] - trans[*iter];
		    		++iter;
		    	}
		    	else
		    	{
		    		result += trans[*iter];
		    	}
	    	}
	    	else
	    	{
	    		result += trans[*iter];
	    	}
	    }
    	return result;
	}
};