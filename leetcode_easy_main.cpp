#include"leetcode.h"
int main()
{


   vector<int> nums;
   int i=0;
   for(;i<15;i++)
	   nums.push_back(rand()%100);
   vector<vector<int> >res=subsets(nums);
   for(i=0;i<(signed)res.size();i++)
	   printVec(res[i]);
	return 0;
}



























