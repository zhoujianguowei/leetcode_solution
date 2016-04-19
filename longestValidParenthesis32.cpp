#include"leetcode.h"
/*
use dp method to handle such question */
int longestValidParentheses(string s)
{
	int i;
	int *maxLength = new int[s.size() + 1];
	memset(maxLength, 0, (s.size() + 1)*sizeof(int));
	for (i = 0; i < (signed)s.size(); i++)
	{
		char current = s.at(i);
		if (current == '(')
			maxLength[i + 1] = 0;
		else if (current == ')'&&i - 1 >= 0)
		{
			/*if (i - 1 >= 0 && s.at(i - 1) == '(')
				maxLength[i + 1] = 2 + maxLength[i - 1];*/
			int matchIndex = i - 1 - maxLength[i];
			if (matchIndex >= 0 && s.at(matchIndex) == '(')
			{
				maxLength[i + 1] = maxLength[i] + 2 + (i - 2 - maxLength[i] >= 0 ?
					maxLength[i - 1 - maxLength[i]] : 0);
			}
			else
				maxLength[i + 1] = 0;
		}
	}
	int max = maxLength[0];
	for ( i = 0; i < (signed)s.size(); i++)
	{
		max = maxLength[i + 1] > max ? maxLength[i + 1] : max;
		cout << i + 1 << ":" << maxLength[i + 1] << "  ";
	}
	return max;

}
