#include <iostream>
#include <string>
#include "../nomer_1(unique_ptr)/unique_ptr.h"


/*int main()
{
	unique_ptr<unique_ptr<int[]>[]> t(new unique_ptr<int[]>[10]);

	for (int i = 0; i < 10; i++)
	{
		t[i] = unique_ptr<int[]>(new int[10]);

		for (int j = 0; j < 10; j++)
		{
			t[i][j] = j;
		}
	}

	for (int i = 0; i < 100; i++)
	{
		std::cout << t[i / 10][i % 10] << " ";
	}




	unique_ptr<int> x(new int(3)), y(new int(5));

	std::cout << x << " " << y << '\n';

	x.swap(y);

	std::cout << x << " " << y << '\n';

	x.release();

	std::cout << (x.get() == nullptr) << " " << (x == nullptr)<< '\n

	
	unique_ptr<int> t(new int(4));
	shared_ptr<int> e(std::move(t));

	std::cout << t << " " << e << e.use_count();
}';*/

int main()
{
	std::unique_ptr<int[]> p1(new int[42]);
	std::unique_ptr<int[]> p2(new int[42]);

	std::cout << std::boolalpha
		<< "(p1 == p1)       : " << (p1 == p1) << '\n'
		//	<< "(p1 <=> p1) == 0 : " << ((p1 <=> p1) == 0) << '\n' // Since C++20

		// p1 and p2 point to different memory locations, so p1 != p2
		<< "(p1 == p2)       : " << (p1 == p2) << '\n'
		<< "(p1 < p2)        : " << (p1 < p2) << '\n' << (bool)p1;
	//<< "(p1 <=> p2) < 0  : " << ((p1 <=> p2) < 0) << '\n'   // Since C++20
	//<< "(p1 <=> p2) == 0 : " << ((p1 <=> p2) == 0) << '\n'; // Since C++20
}
