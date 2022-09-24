#include "../../libs/smart_ptr/smart_ptrs.h"
#include <string>
#include <iostream>

/*int main()
{
	shared_ptr<shared_ptr<int[]>[]> t(new shared_ptr<int[]>[10]);

	for (int i = 0; i < 10; i++)
	{
		t[i] = shared_ptr<int[]>(new int[10]);

		for (int j = 0; j < 10; j++)
		{
			t[i][j] = j;
		}
	}

	for (int i = 0; i < 100; i++)
	{
		std::cout << t[i / 10][i % 10] << " ";
	}

	std::cout << t->use_count() << " " << t[1].use_count();

	std::cout << t;

	auto p = make_shared<int[]>(5);

	for (int i = 0; i < 5; ++i)
	{
		p[i] = i;
		std::cout << p[i] << std::endl;
	}

	std::cout << p;


	shared_ptr<int> t(new int(5)), y(new int(234));
	std::cout << t << " " << y << '\n';
	t = std::move(y);
	std::cout << t << " " << y << '\n';

	t.reset(new int(10000));
	std::cout << *t

};*/

int main()
{
	shared_ptr<int[]> p1(new int[42]);
	shared_ptr<int[]> p2(new int[42]);

	std::cout << std::boolalpha
		<< "(p1 == p1)       : " << (p1 == p1) << '\n'
		//	<< "(p1 <=> p1) == 0 : " << ((p1 <=> p1) == 0) << '\n' // Since C++20

		// p1 and p2 point to different memory locations, so p1 != p2
		<< "(p1 == p2)       : " << (p1 == p2) << '\n'
		<< "(p1 < p2)        : " << (p1 < p2) << '\n' << (bool)p1;
		//<< "(p1 <=> p2) < 0  : " << ((p1 <=> p2) < 0) << '\n'   // Since C++20
		//<< "(p1 <=> p2) == 0 : " << ((p1 <=> p2) == 0) << '\n'; // Since C++20
}