#include <algorithm>
#include <iostream>
#include <vector>
#include <format>
#include <optional>
using namespace std;

auto gcd(const int a, const int b) -> int
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}

auto binary_search(const vector<int>& arr, const int target) -> optional<size_t>
{
	size_t start = 0;
	size_t end = arr.size() - 1;

	while (start <= end)
	{
		size_t mid = (start + end) / 2;
		if (arr[mid] == target)
		{
			return mid;
		}

		if (target < arr[mid])
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return nullopt;
}

auto is_sorted(const vector<int>& arr, const size_t start, const size_t end) -> bool
{
	for (size_t i = start + 1; i <= end; ++i)
	{
		if (arr[i - 1] > arr[i])
		{
			return false;
		}
	}
	return true;
}

auto insertion_sort(vector<int>& arr, const ptrdiff_t start, const ptrdiff_t end) -> void
{
	for (ptrdiff_t i = start + 1; i <= end; i++)
	{
		int key = arr[i];
		ptrdiff_t j = i - 1;
		while (j >= start && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

auto quick_sort_helper(vector<int>& arr, const size_t start, const size_t end) -> void
{
	constexpr size_t min_size = 20;

	if (is_sorted(arr, start, end))
	{
		return;
	}
	if (end - start < min_size)
	{
		insertion_sort(arr, static_cast<ptrdiff_t>(start), static_cast<ptrdiff_t>(end));
		return;
	}

	const int pivot_value = arr[(start + end) / 2];
	auto l = start, r = end;
	while (l <= r)
	{
		while (arr[l] < pivot_value)
		{
			++l;
		}
		while (arr[r] > pivot_value)
		{
			--r;
		}
		if (l <= r)
		{
			std::swap(arr[l], arr[r]);
			++l;
			--r;
		}
	}
	if (start < r)
	{
		quick_sort_helper(arr, start, r);
	}
	if (l < end)
	{
		quick_sort_helper(arr, l, end);
	}
}

auto quick_sort(vector<int>& arr) -> void
{
	if (arr.size() > 1)
	{
		quick_sort_helper(arr, 0, arr.size() - 1);
	}
}


int main()
{
	auto unsorted = vector<int>({3, 5, 1, 3, 9, 6});
	quick_sort(unsorted);
	for (auto i : unsorted)
	{
		cout << i << " ";
	}
}
