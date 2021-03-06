#include"leetcode.h"
/*
You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

For example:

Secret number:  "1807"
Friend's guess: "7810"
Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B".

Please note that both secret number and friend's guess may contain duplicate digits, for example:

Secret number:  "1123"
Friend's guess: "0111"
In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.
*/
string getHint(string secret, string guess)
{
	if (secret.size() == 0)
		return "0A0B";
	unsigned int bullNum = 0, cowNum = 0;
map<char, int> uMap;
map<char, int>::iterator iIte;
	unsigned int i = 0;
	string cowS;
	for (; i<secret.size(); i++)
		if (secret.at(i) == guess.at(i))
			bullNum++;
		else
		{
			cowS.append(string(1, guess.at(i)));
			iIte = uMap.find(secret.at(i));
			if (iIte != uMap.end())
			{
				int count = iIte->second;
				count++;
				uMap.erase(secret.at(i));
				uMap.insert(make_pair(secret.at(i), count));
			}
			else
				uMap.insert(make_pair(secret.at(i), 1));
		}
	for (i = 0; i<cowS.size(); i++)
	{
		iIte = uMap.find(cowS.at(i));
		if (iIte != uMap.end())
		{
			cowNum++;
			int count = iIte->second;
			count--;
			uMap.erase(cowS.at(i));
			if (count>0)
				uMap.insert(make_pair(cowS.at(i), count));
		}
	}
	string s;
	s.append(intParseStr(bullNum) + "A" + intParseStr(cowNum) + "B");
	return s;

}
