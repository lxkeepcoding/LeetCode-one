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
	{  // ѭ��ֱ���������Ҷ˵���ͬ
		int mid = left + (right - left) / 2;  // ��ֹ����ʱ���
		if (isBadVersion(mid))
		{
			right = mid;  // �������� [left, mid] ��
		}
		else
		{
			left = mid + 1;  // �������� [mid+1, right] ��
		}
	}
	// ��ʱ�� left == right��������Ϊһ���㣬��Ϊ��
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
