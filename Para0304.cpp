#include <algorithm>
#include <iostream>
#include <vector>
#include <format>
#include <optional>
using namespace std;

auto gcd(int a, int b) -> int
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


auto quick_sort_helper(vector<int>& arr, const size_t start, const size_t end) -> void
{
	int pivot_value = arr[(start + end) / 2];
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

auto insertion_sort(vector<int>& arr) -> void
{
	for (size_t i = 1; i < arr.size(); ++i)
	{
		int key = arr[i];
		ptrdiff_t j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

//void insertion_sort(std::vector<int>& arr, int start, int end) {
//    for (size_t i = start + 1; i <= end; i++) {
//        int key = arr[i];
//        ptrdiff_t j = i - 1;
//        while (j >= start && arr[j] > key) {
//            arr[j + 1] = arr[j];
//            j--;
//        }
//        arr[j + 1] = key;
//    }
//}

int main()
{
	//cout << format("{}\n", gcd(252, 105));
	//cout << "\nBinary Search\n";
	//auto arr = vector<int>({1, 2, 3, 4, 6, 7, 8, 9, 10});
	//cout << binary_search(arr, 1).value_or(-1) << "\n";
	//cout << binary_search(arr, 10).value_or(-1) << "\n";
	//cout << binary_search(arr, 3).value_or(-1) << "\n";
	//cout << binary_search(arr, 5).value_or(-1) << "\n";

	auto unsorted = vector<int>({3, 5, 1});
	insertion_sort_wrong(unsorted); //, 0, unsorted.size() - 1);
	for (auto i : unsorted)
	{
		cout << i << " ";
	}
}
