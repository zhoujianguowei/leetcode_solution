#include"leetcode.h"
vector<int> findSubstring(string s, vector<string>& words)
{
	vector<int> res;
	map<string, int> uMap, uMapRef;
	if (words.empty() || words[0].size() == 0)
		return res;
	int wordsLength = words.size()*words[0].length(), perWordLength = words[0].length();
	if ((signed)s.size() < wordsLength)
		return res;
	int i, j, matchCount = 0;
	for (i = 0; i < (signed)words.size(); i++)
	{
		map<string, int>::iterator ite = uMapRef.find(words[i]);
		if (ite != uMapRef.end())
			ite->second++;
		else
			uMapRef.insert(make_pair(words[i], 1));
	}
	for (i = 0; i < (signed)s.size(); i++)
	{
		uMap = uMapRef;
		matchCount = 0;
		for (j = i; j < (signed)s.size() - perWordLength + 1; j += perWordLength)
		{
			string subStr = s.substr(j, perWordLength);
			map<string, int>::iterator ite = uMap.find(subStr);
			if (ite != uMap.end())
			{
				if (ite->second > 0)
				{
					ite->second--;
					matchCount++;
				}
				else
					break;
			}
			else
				break;
			if (matchCount ==(signed) words.size())
			{
				res.push_back(i);
				matchCount = 0;
				break;
			}
		}
	}
	return res;


}
