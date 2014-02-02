#include <string>
#include <iostream>



int main()
{
	std::string hani = "hi,sk";
	std::string haha = removePunc(hani);
	std::cout << haha << std::endl;

	system("pause");
	return 0;
}