// EvlidNOD.cpp : Defines the entry point for the application.
//

#include "EvlidNOD.h"
#include <vector>


using item_t = size_t;
using DRange_t = std::vector<item_t>;

#define PRINT_DRANGE(x) std::copy(x.begin(),x.end(),std::ostream_iterator<item_t>(std::cout," "))



int NOD(item_t m, item_t n) {
	if (!m && !n)
		throw;
	while (n != 0) {
		item_t r = m % n;
		m = n;
		n = r;
	}
	return m;
}

DRange_t eratosfetFiltr(DRange_t range) {
	DRange_t filtrRange;
	int n = range.size();
	int p = 0;
	for (int i = 2; i < n; i++)
	{
		if (range[i] != 0)
		{
			filtrRange.push_back(range[i]);
			for (p = 2 * i; p < n; p += i)
			{
				range[p] = 0;
			}
		}
	}
	return filtrRange;
}

DRange_t createRangeAB(size_t a, size_t b) {
	DRange_t range;
	range.resize(b - a);
	item_t i = a;
	std::for_each(range.begin(), range.end(), [&i](item_t& d) {
		d = i;
		++i;
	});
	return range;
}


size_t schoolMethodNOD(size_t a, size_t b) {
	DRange_t simple_dgt = eratosfetFiltr(createRangeAB(0, a > b ? a : b));
	for (size_t i = 0; i < simple_dgt.size(); i++) {
		if (a % simple_dgt[i] == 0 && b % simple_dgt[i] == 0)
			return simple_dgt[i];
	}
	return 1;
}

int main()
{
	size_t a, b;
	a = 15, b = 36;
	std::cout << "Evklid gcd(NOD) = " << NOD(a, b) << std::endl;
	std::cout << "Shool method NOD = " << schoolMethodNOD(a, b) << std::endl;

	return 0;
}
