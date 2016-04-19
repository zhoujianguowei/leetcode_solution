#include"leetcode.h"
/*
67. Add Binary   My Submissions QuestionEditorial Solution
Total Accepted: 82044 Total Submissions: 300041 Difficulty: Easy
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
string addBinary(string a, string b)
{
	string res;
	int i = 0, j = 0;
	int isCarry = 0;
	for (i = a.length() - 1, j = b.length() - 1; i >= 0&&j >= 0; i--, j--)
	{
		isCarry += a.at(i) - '0' + b.at(j) - '0';
		res.append(1, (isCarry % 2 + '0'));
		isCarry /= 2;
	}
	if (i == -1)
	{
		while (j >= 0)
		{
			isCarry += b.at(j) - '0';
			res.append(1, (isCarry % 2 + '0'));
			isCarry /= 2;
			j--;
		}
	}
	else if (j == -1)
	{
		while (i >= 0)
		{
			isCarry += a.at(i) - '0';
			res.append(1, (isCarry % 2 + '0'));
			isCarry /= 2;
			i--;
		}
	}
	if (isCarry)
		res.append(1, isCarry + '0');
	return reverseString(res);
}
