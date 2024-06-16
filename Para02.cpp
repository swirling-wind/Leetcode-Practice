//#include "ut.hpp"
//using namespace boost::ut;

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

constexpr auto sum(auto... args) { return (args + ...); }

auto find_min_index(const vector<int>& unsorted) -> size_t
{
	size_t min_idx = 0;
	for (size_t i = 1; i < unsorted.size(); ++i)
	{
		if (unsorted[i] < unsorted[min_idx])
		{
			min_idx = i;
		}
	}
	return min_idx;
}

auto select_sort(const vector<int>& unsorted) -> vector<int>
{
	vector<int> input(unsorted);
	vector<int> sorted;
	sorted.reserve(unsorted.size());
	for (size_t i = 0; i < unsorted.size(); ++i)
	{
		const auto target_idx = find_min_index(input);
		sorted.emplace_back(input[target_idx]);
		input[target_idx] = INT_MAX;
	}
	return sorted;
}


int main()
{
	auto unsorted = vector<int>{3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

	for (auto sorted = select_sort(unsorted); auto i : sorted)
	{
		cout << i << " ";
	}
}
