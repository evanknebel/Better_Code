#include <iostream>

// template function definition
//  - this MUST occur in the header
template<typename T>
T add(T lhs, T rhs)
{
	// as long as T implements the addition operator, this template can be used
	return lhs + rhs;
}
template<typename T>
void print(T value)
{
	std::cout << value << std::endl;
}

template<typename T>
T max(T lhs, T rhs)
{
	if (lhs > rhs)
	{
		return lhs;
	}
	else
	{
		return rhs;
	}
}

template<typename T>
T min(T lhs, T rhs)
{
	if (lhs < rhs)
	{
		return lhs;
	}
	else
	{
		return rhs;
	}
}

template<typename T>
T clamp(T clamperLow, T clampee, T clamperHigh)
{
	if (clampee >= clamperLow && clampee <= clamperHigh)
	{
		return clampee;
	}
	else if (clampee > clamperHigh)
	{
		return clamperHigh;
	}
	else if (clampee < clamperLow)
	{
		return clamperLow;
	}
}

template<typename T>
T swap(T lhs, T rhs)
{
	print(lhs);
	print(rhs);
	T temp = lhs;
	lhs = rhs;
	rhs = temp;
	print(lhs);
	print(rhs);
	return NULL;
}

//class person
//{
//public:
//	char name;
//	int age;
//	float hight;
//
//};
//
//person Joe
//{
//	
//
//}

int main()
{
	// template arg deduced from arguments
	int implInt = add(5, 5);
	float implFlt = add(2.1f, 3.2f);

	// template arg provided
	int explInt = add<int>(5, 5);

	// print results
	std::cout << implInt << std::endl; // 10
	std::cout << implFlt << std::endl; // 5.3
	std::cout << explInt << std::endl; // 10

	print("hello");
	print(5.2f);
	print(9);
	print(false);

	print(max(15, 12));
	print(min(15, 12));

	print(clamp(1, 3, 5));

	print(swap("g", "Q"));


	while (true) {}	// keep the window open
	return 0;
}