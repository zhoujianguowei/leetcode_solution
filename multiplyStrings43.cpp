#include"leetcode.h"
/*
43. Multiply Strings   My Submissions QuestionEditorial Solution
Total Accepted: 59850 Total Submissions: 255864 Difficulty: Medium
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note:
The numbers can be arbitrarily large and are non-negative.
Converting the input string to integer is NOT allowed.
You should NOT use internal library such as BigInteger.
*/
string omitString(string num)
{
	bool isNegative = false;
	if (num.length() == 0)
		return num;
	if (num.at(0) == '-')
	{
		isNegative = true;
		num = num.substr(1,num.size() - 1);
	}
	else if (num.at(0) == '+')
		num = num.substr(1,num.size() - 1);
	while (num.length()>0&&num.at(0) == '0')
		num = num.substr(1,num.size() - 1);
	return num;
}
string getPerLine(string num1, char digit)
{
	vector<char> resVec;
	int isCarry = 0;
	for (int i = num1.length()-1; i>=0; i--)
	{
		resVec.push_back(((num1.at(i) - '0')*(digit - '0') + isCarry) % 10);
		isCarry = ((num1.at(i) - '0')*(digit - '0') + isCarry) / 10;
	}
	if (isCarry)
		resVec.push_back(isCarry);
	string res;
	for (int i = resVec.size() - 1; i >= 0; i--)
		res.append(1, resVec[i]+'0');
	return res;

}
string fillZero(string perLine, int beginZeroNum, int endZeroNum)
{
	string res;
	int i = 0;
	while (i++ < beginZeroNum)
		res.append(1, '0');
	res.append(perLine);
	i = 0;
	while (i++ < endZeroNum)
		res.append(1, '0');
	return res;
}

string multiply(string num1, string num2)
{
	num1 = omitString(num1);
	num2 = omitString(num2);
	if (num1.length() == 0 || num2.length() == 0)
		return "0";
	string res, perLine;
	vector<string> sVec;
	//sVec.resize(num2.length());
	int maxPerLineLength = num2.length() - 1 + getPerLine(num1, num2.at(0)).length();
	int i = 0,j=0;
	for (; i < (signed)num2.length();i++)
	{
		perLine = getPerLine(num1, num2.at(i));
		int beginZeroNum = maxPerLineLength - (num2.length() - 1 - i) - perLine.length();
		int endZeroNum = maxPerLineLength - beginZeroNum - perLine.length();
		sVec.push_back(fillZero(perLine, beginZeroNum, endZeroNum));
	}
	int carry = 0;
	for (int i = maxPerLineLength - 1; i >= 0; i--)
	{
		for (j = 0; j < (signed)sVec.size(); j++)
			carry += sVec[j].at(i) - '0';
		res.append(1, carry % 10 + '0');
		carry = carry / 10;
	}
	if (carry > 0)
		res.append(intParseStr(carry));
	return reverseString(res);
}
