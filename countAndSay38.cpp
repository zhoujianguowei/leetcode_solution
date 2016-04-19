#include"leetcode.h"
string getPre(string s)
{
	string res;
	int i, count = 1;
	char c, preC;

	for (i = 0; i < (signed)s.length(); i++)
	{
		c = s.at(i);
		if (i > 0)
		{
			if (preC == c)
				count++;
			else
			{
				res.append(1, count + '0');
				res.append(1, preC);
				count = 1;
			}
		}
		preC = c;
	}
	res.append(1, count + '0');
	res.append(1, preC);
	return res;
}
string countAndSay(int n)
{
	//return "11";
	string pre = "1";
	if (n <= 0)
		return "";
	while (--n)
		pre = getPre(pre);
	return pre;
}
