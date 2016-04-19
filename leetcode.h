/*
 * leetcode.h
 *
 *  Created on: 2016年4月19日
 *      Author: hadoop
 */

//#ifndef LEETCODE_H_
//#define LEETCODE_H_
#include<iostream>
#include<vector>
#include<set>
#include<stack>
#include<map>
#include<cstring>
#include<algorithm>
#include<stdio.h>
#include<list>
#include<time.h>
#include<cmath>
#include<iomanip>



using namespace std;
//template<class T> class DigitsOperand
//{
//public:
//
//	//DigitsOperand(vector<T> arr) :array(arr) {};
//	void quickSort(vector<T>& array,int ,int );
//	//
//private :
//	vector<T> array;
//
//};
/*template<class T>T  min(T x, T y)
{
	return x < y ? x : y;
}*/
template<class T> T max(T x, T y)
{
	return x > y ? x : y;
}
void quick_sort(vector<int>&);
void quick_sort(vector<int>&, int, int);
vector<int> reverseVector(vector<int>&);
void nextPermutation(vector<int>& nums);
vector<vector<int> > permute(vector<int>&nums);
int reverse(int);

/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line : "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows :

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
*/
string convert(string, int);
/* 15
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)
*/
vector<vector<int> > threeSum(vector<int>& nums);
/*
Find the Duplicate Number My Submissions Question Solution
Total Accepted: 7849 Total Submissions: 23220 Difficulty: Hard
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/
int findDuplicate(vector<int>&);
/*
146
LRU Cache My Submissions Question Solution
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/
class LRUCache
{

	struct ValueNode
	{
		int key;
		int value;
		struct ValueNode *pre;
		struct ValueNode *next;
	};

public:
	LRUCache(int capacity)
	{
		size = capacity;
		head = tail = NULL;
	};
	ValueNode* addNode(int key, int value);
	int get(int key);
	void set(int key, int value);

private:
	unsigned int size;
	ValueNode *head;
	ValueNode *tail;
	map<int, ValueNode*> lruMap;
	map<int, ValueNode*>::iterator lruIterator;

};
/*
77
Combinations My Submissions Question Solution
Total Accepted: 56176 Total Submissions: 177364 Difficulty: Medium
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
[2,4],
[3,4],
[2,3],
[1,2],
[1,3],
[1,4],
]
*/
vector<vector<int> > combine(int n, int k);
/*
69
Sqrt(x) My Submissions Question Solution
Total Accepted: 69855 Total Submissions: 294360 Difficulty: Medium
Implement int sqrt(int x).

Compute and return the square root of x.
*/
int mySqrt(int);
/*
57
Insert Interval My Submissions Question Solution
Total Accepted: 43998 Total Submissions: 198983 Difficulty: Hard
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/
struct Interval
{
	int start;
	int end;
};
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval);
/*
5
Longest Palindromic Substring My Submissions Question Solution
Total Accepted: 75290 Total Submissions: 357148 Difficulty: Medium
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/
string longestPalindrome(string);

/*
Merge k Sorted Lists My Submissions Question Solution
Total Accepted: 61498 Total Submissions: 285982 Difficulty: Hard
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {};

};

class Node
{
public:
	/*Node(int x) :val(x), next(NULL) {}
	;*/
	Node *next;
	Node()
	{

	}
	Node(int x)
	{
		val = x;
		//next = NULL;
	}
	int val;
};



/*
39
Combination Sum My Submissions Question Solution
Total Accepted: 65399 Total Submissions: 228461 Difficulty: Medium
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]
*/
vector<vector<int> > combinationSum(vector<int>& candidates, int target);
/*

40
Combination Sum II My Submissions Question Solution
Total Accepted: 50038 Total Submissions: 194257 Difficulty: Medium
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
*/
vector<vector<int> > combinationSum2(vector<int>& candidates, int target);



ListNode* mergeKLists(vector<ListNode*>& lists);

int searchInsert(vector<int>& nums, int target);

/*
176
Largest Number My Submissions Question
Total Accepted: 32634 Total Submissions: 191709 Difficulty: Medium
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/
string largestNumber(vector<int>& nums);
/*
11
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/
int maxArea(vector<int>& height);

/*
reverse specify linked list from m to n (array index begins at 1)
*/
ListNode* reverseBetween(ListNode* head, int m, int n);
/*
56
Merge Intervals My Submissions Question
Total Accepted: 49748 Total Submissions: 213553 Difficulty: Hard
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/
vector<Interval> merge(vector<Interval>& intervals);
ListNode * getListNode(vector<int> nums);
ListNode *getListNode(int nums[], int n);
/*
对节点链表的排序，排序方式是快速排序
*/
ListNode* sortList(ListNode* head);
/*
使用二路归并对链表进行排序
*/
ListNode *divide_binary_sort(ListNode *head);
ListNode * getListNodeTail(ListNode *head);

/*
Subsets My Submissions Question
Total Accepted: 70737 Total Submissions: 243021 Difficulty: Medium
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]
*/
vector<vector<int> > subsets(vector<int>& nums);
/*
155
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/
class MinStack
{

private:
	list<int> nodeList;
	list<int> minList;
public:
	void push(int x);


	void pop();


	int top();

	int getMin();
};
bool containsNearbyDuplicate(vector<int>& nums, int k);
/*
得到小于n的素数的个数
*/
int cout_prime(int n);
/*
删除排序数组中的重复元素
*/
ListNode* deleteDuplicates(ListNode* head);
ListNode* reverseList(ListNode *head);
bool isPalindrome(ListNode* head);
/*
将integer的各个数字提取转换成为字符串
*/
string intParseStr(int num);
/*
Shortest Palindrome My Submissions Question
Total Accepted: 12322 Total Submissions: 69813 Difficulty: Hard
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Thanks to @Freezen for additional test cases.

Subscribe to see which companies asked this question
*/
string shortestPalindrome(string s);
/*
Combination Sum III My Submissions Question
Total Accepted: 17712 Total Submissions: 55946 Difficulty: Medium
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
*/
vector<vector<int> > combinationSum3(int k, int n);
/*
连接两个有序链表
*/
ListNode *mergeTwoLists(ListNode *head1, ListNode *head2);
ListNode *divide_binary_sort(ListNode *head);
/*

Sort Colors
My Submissions
Question

Total Accepted: 75265 Total Submissions: 226291 Difficulty: Medium





Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem

*/
void sortColors(vector<int>& nums);
vector<int> getVec(int  nums[], int n);

/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space
*/
int firstMissingPositive(vector<int>& nums);
int singleNumber(vector<int>& nums);
bool search(vector<int>& nums, int target);
int nthUglyNumber(int n);
int numSquares(int n);
/*
path sum II
*/
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
vector<vector<int> > pathSum(TreeNode* root, int sum);
/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

1
/   \
2     3
\
5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/
int strParseInt(string s);
vector<string> binaryTreePaths(TreeNode* root);
TreeNode* createTree(vector<string> nums);
int numSquares(int n);
int numDistinct(string s, string t);
bool isMatch(string s, string p);
bool isPointerMatch(char *s, char *p);
/*
remove a sorted array in which the number of elements is no more than two
*/
int removeDuplicates(int* nums, int numsSize);
char* longestCommonPrefix(char** strs, int strsSize);
char * getTail(char *head);
int getDistinctCombination(int n, int k);
int getDistinctPermutation(int n, int k);
int countDigitOne(int n);
int strStr(char* haystack, char* needle);
int threeSumClosest(vector<int>& nums, int target);
vector<int> searchRange(vector<int>& nums, int target);
vector<int> singleNumberIII(vector<int>& nums);
int binarySearch(vector<int> nums, int left, int right, int target);
int findMin(vector<int>& nums);
void reverseWords(string &s);
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
int longestConsecutive(vector<int>& nums);
struct RandomListNode
{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) :label(x), next(NULL), random(NULL) {}
};
RandomListNode *copyRandomList(RandomListNode *head);
ListNode *mergeTwoLists(ListNode *head1, ListNode *head2);
string getHint(string secret, string guess);
/**
17. Letter Combinations of a Phone Number
**/
vector<string> letterCombinations(string digits);
void printVec(vector<int> nums);
vector<vector<int> > threeSum(vector<int> &nums, int target);
/**
18. 4Sum My Submissions QuestionEditorial Solution
Total Accepted: 68373 Total Submissions: 290097 Difficulty: Medium
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

A solution set is:
(-1,  0, 0, 1)
(-2, -1, 1, 2)
(-2,  0, 0, 2)
*/
vector<vector<int> > fourSum(vector<int>& nums, int target);
/**
20. Valid Parentheses My Submissions QuestionEditorial Solution
Total Accepted: 102420 Total Submissions: 351089 Difficulty: Easy
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Subscribe to see which companies asked this question
*/
bool isValid(string s);
/**
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"k
*/
vector<string> generateParenthesis(int n);
ListNode *getPointer(int nums[], int n);
/**
25. Reverse Nodes in k-Group My Submissions QuestionEditorial Solution
Total Accepted: 57153 Total Submissions: 208691 Difficulty: Hard
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/
ListNode* reverseKGroup(ListNode* head, int k);
ListNode *reverseList(ListNode *head, int n);

/*
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/
vector<int> findSubstring(string s, vector<string>& words);

/*
32. Longest Valid Parentheses
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/
int longestValidParentheses(string s);
/*
get max common divisor
*/
int getGcd(int a, int b);
/*
get min common mul
*/
int getLcm(int a, int b);
/*
get unique reciprocal of ax=1mod(m),which requires they are relative prime
*/
int getUniqueReciprocal(int a, int m);
int fastExponention(int a, int b, int n);
string isPrime(int n, int choice);
int isPrime(int n);
/*
38. Count and Say   My Submissions QuestionEditorial Solution
Total Accepted: 78510 Total Submissions: 272181 Difficulty: Easy
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/
string countAndSay(int n);
string multiply(string num1, string num2);
string reverseString(string s);
string addBinary(string a, string b);

//#include<unordered_map>
//#endif /* LEETCODE_H_ */
