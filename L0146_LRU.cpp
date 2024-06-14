#include "ut.hpp"
using namespace std;
using namespace boost::ut;

constexpr auto sum(auto... args) { return (args + ...); }

int main()
{
	"sum"_test = []
	{
		expect(sum(0) == 0_i);
		expect(sum(1, 2) == 3_i);
	};
}
