// main.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//Given an array of integers, return indices of the two numbers such that they add up to a specific target.

//You may assume that each input would have exactly one solution, and you may not use the same element twice.

//给定int数组，返回两个数字的下标，两者相加等于给定目标

//假设只有唯一解，数组内无重复数字，且不能使用同一个数字两次

#include <iostream>
#include <vector>
#include <map>

//该方法遍历两遍数组
//时间复杂度O(n²)
//空间复杂度O(1)
std::vector<int> twoNum(std::vector<int>& array, const int target)
{
	const int count = array.capacity();

	if (count < 2)
		return std::vector<int>();

	for (int i = 0; i < count; ++i)
	{
		for (int j = i + 1; j < count; ++j)
		{
			if (array[i] + array[j] == target)
				return std::vector<int>{i, j};
		}
	}

	return std::vector<int>();
}

//该方法使用哈希表保存数据，只需查询一遍
//时间复杂度O(n)
//空间复杂度O(n)
std::vector<int> twoNumByHashTable(std::vector<int>& array, const int target)
{
	const int count = array.capacity();

	if (count < 2)
		return std::vector<int>();

	std::map<int, int> hashMap = std::map<int, int>();

	for (int i = 0; i < count; ++i)
	{
		hashMap[array[i]] = i;
	}

	for (int i = 0; i < count; ++i)
	{
		auto findKey = hashMap.find(target - array[i]);
		if (findKey != hashMap.end() && findKey->second != i)
		{
			return std::vector<int>{i, findKey->second};
		}
	}

	return std::vector<int>();
}

//该方法边查询边存储哈希表
//时间复杂度O(n)
//空间复杂度O(n)
std::vector<int> twoNumByHashTableOnce(std::vector<int>& array, const int target)
{
	const int count = array.size();

	if (count < 2)
		return std::vector<int>();

	std::map<int, int> hashMap = std::map<int, int>();

	for (int i = 0; i < count; ++i)
	{
		if (hashMap.find(target - array[i]) != hashMap.end())
		{
			return std::vector<int>{hashMap[target - array[i]], i};
		}

		hashMap[array[i]] = i;
	}

	return std::vector<int>();
}

int main()
{
	const auto array = new std::vector<int>{ 2, 7, 11, 15 };

    const auto target = 26;

    for (int num : twoNumByHashTableOnce(*array, target))
    {
		std::cout << num << std::endl;
    }
}
