#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (int k = 1; k < argc; k++)
	{
		for (int l = 0; argv[k][l]; l++)
		{
			if (argv[k][l] >= 'a' && argv[k][l] <= 'z')
				std::cout << (char)(argv[k][l] + ('A' - 'a'));
			else
				std::cout << argv[k][l];
		}
	}
	std::cout << std::endl;
	return (0);
}