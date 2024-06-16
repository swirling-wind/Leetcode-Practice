#include <algorithm>
#include <iostream>
#include <vector>
#include <format>
#include <optional>
using namespace std;

auto factorial(int n) -> int
{
	if (n == 1)
	{
		return 1;
	}
	return factorial(n - 1) * n;
}

auto gcd(int a, int b) -> int
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}

auto iter_sum(vector<int> arr) -> int
{
	if (arr.empty())
	{
		return 0;
	}
	auto last = arr.back();
	arr.pop_back();
	return iter_sum(arr) + last;
}

auto iter_count(vector<int> arr) -> size_t
{
	if (arr.empty())
	{
		return 0;
	}
	arr.pop_back();
	return iter_count(arr) + 1;
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

auto quick_sort(vector<int> arr) -> vector<int>
{
	if (arr.size() < 2)
	{
		return arr;
	}	
	const auto pivot = arr[0];
	vector<int> less;
	vector<int> greater;
	ranges::copy_if(arr.begin() + 1, arr.end(), back_inserter(less),
	                [pivot](int n) { return n <= pivot; });
	
	ranges::copy_if(arr.begin() + 1, arr.end(), back_inserter(greater),
	                [pivot](int n) { return n > pivot; });

	auto sorted_less = quick_sort(less);
	auto sorted_greater = quick_sort(greater);

	vector<int> sorted;
	ranges::copy(sorted_less, back_inserter(sorted));
	sorted.push_back(pivot);
	ranges::copy(sorted_greater, back_inserter(sorted));
	return sorted;
}

int main()
{
	//cout << format("{}\n", gcd(252, 105));
	//cout << iter_sum(vector<int>({1, 2, 3, 4})) << "\n";
	//cout << iter_count(vector<int>({2, 3, 1}));
	//// Test binary_search
	//cout << "\nBinary Search\n";
	//auto arr = vector<int>({1, 2, 3, 4, 6, 7, 8, 9, 10});
	//cout << binary_search(arr, 1).value_or(-1) << "\n";
	//cout << binary_search(arr, 10).value_or(-1) << "\n";
	//cout << binary_search(arr, 3).value_or(-1) << "\n";
	//cout << binary_search(arr, 5).value_or(-1) << "\n";

	auto unsorted = vector<int>({3,5,1,2,4});
	for (auto sorted = quick_sort(unsorted); auto i : sorted)
	{
		cout << i << " ";
	}
	
}
