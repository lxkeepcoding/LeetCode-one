#define _CRT_SECURE_NO_WARNINGS   1

int search(int* nums, int numsSize, int target)
{
	int left = 0;
	int right = numsSize - 1;
	int mid;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (target>nums[mid])
		{
			left = mid + 1;
		}
		if (target<nums[mid])
		{
			right = mid - 1;
		}
		if (target == nums[mid])
		{
			return mid;
		}
	}
	return -1;
}


int firstBadVersion(int n)
{
	int left = 1, right = n;
	while (left < right)
	{  // 循环直至区间左右端点相同
		int mid = left + (right - left) / 2;  // 防止计算时溢出
		if (isBadVersion(mid))
		{
			right = mid;  // 答案在区间 [left, mid] 中
		}
		else
		{
			left = mid + 1;  // 答案在区间 [mid+1, right] 中
		}
	}
	// 此时有 left == right，区间缩为一个点，即为答案
	return left;
}


int searchInsert(int* nums, int numsSize, int target)
{
	int left = 0, right = numsSize;

	while (left < right)
	{
		int mid = left + (right - left) / 2;

		if (nums[mid] >= target)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	return left;
}
