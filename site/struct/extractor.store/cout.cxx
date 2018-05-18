#include <fstream>
#include <iostream>

int main (int argc, char * argv [], char * env [])
{
	for (/*unsigned long long */int i = 0; i < argc; ++i)
		std::cout << argv [i] << ' ';
	std::cout << std::endl;
	std::cout << "argc [" << argc << ']' << std::endl;
	
	if (argc < 2)
	{
		std::cerr << "'" << argv [0] << "'" << " '<file.txt>'" << std::endl;
		
		return EXIT_FAILURE;
	}
	
	
	std::ifstream file;
	//char c;
	unsigned long int i;
	
	file.open (argv [1], std::ios::in);
	
	if (!file.is_open ())
	{
		std::cerr << "'" << argv [0] << "'::error::could not open file '" << argv [1] << "'" << std::endl;
		
		return EXIT_FAILURE;
	}
	std::cout << "'" << argv [0] << "'::success::opened file '" << argv [1] << "'" << std::endl;
	
	//c = 72;
	//std::cout << c;
	
	while (file >> i)
	{
		//c = i;
		std::cout << ((char) i);
	}
	
	std::cout << std::endl;
	
	file.close ();
}
