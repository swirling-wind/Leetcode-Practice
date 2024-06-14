#include "ut.hpp"
#include <vector>
using namespace std;
using namespace boost::ut;

constexpr auto sum(auto... args) { return (args + ...); }

size_t find_min_index(const vector<int>& unsorted)
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

int main()
{
	"sum"_test = []
	{
		expect(sum(0) == 0_i);
		expect(sum(1, 2) == 3_i);
	};
	std::cout << std::format("Hello");
}
