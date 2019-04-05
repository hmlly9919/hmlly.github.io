class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
	    vector<int>::iterator iter1 = nums1.begin(), iter2 = nums2.begin();
	    for (; (iter1 != nums1.end()) && (iter2 != nums2.end()); )
	    {
		    if (*iter1 <= *iter2)
		    {
		    	++iter1;
		    }
		    else
		    {
		    	iter1 = nums1.insert(iter1, *iter2);
		    	++iter1;
		    	++iter2;
		    }
	    }
	    if (iter1 == nums1.end())
	    {
	    	for (; iter2 != nums2.end(); ++iter2)
	    	{
	    		nums1.insert(nums1.end(), *iter2);
	    	}
	    }
	    if (size % 2)
	    {
    		return static_cast<double>(nums1[size / 2]);
	    }
    	else
    	{
	    	return static_cast<double>((nums1[size / 2] + nums1[size / 2 - 1]) / static_cast<double>(2));
    	}
    }
};