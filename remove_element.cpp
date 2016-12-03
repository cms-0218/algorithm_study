#include <iostream>
#include <vector>
using namespace std;
/*
 *
 *Given an array and a value, remove all instances of that value in place and return the new length.
 *Do not allocate extra space for another array, you must do this in place with constant memory.
 *The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 *Example:
 *Given input array nums = [3,2,2,3], val = 3
 *Your function should return length = 2, with the first two elements of nums being 2.
 *
*/
//my code
int removeElement_01(int* nums, int numsSize, int val) 
{
	int begin = 0;
	int tail = numsSize-1;
	while(begin <= tail)
	{
		if(nums[begin] == val)
		{
			if(nums[tail] == val)
				tail--;
			else
				nums[begin] = nums[tail--];
		}
		else
			begin++;
	}
	return begin;
}

//this is more pithy
int removeElement_02(int *nums,int numsSize, int val)
{
	for(int i = 0; i < numsSize; i++)
	{
		if(nums[i] == val)
		{
			nums[i] = nums[numsSize-1];
			--i;
			--numsSize;
		}
	}
	return numsSize;
}

int removeElement_03(vector<int>& nums,int val)
{
	for(vector<int>::iterator iter = nums.begin(); iter < nums.end(); ++iter)
	{
		if(*iter == val)
		{
			iter = nums.erase(iter);
			--iter;
		}
	}
	return nums.size();
}
