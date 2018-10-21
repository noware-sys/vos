//#include <Poco/any.h>
#include <string>
#include <iostream>
//#include <sstream>
//#include <fstream>
//#include <algorithm>	// For for_each ()
//#include <omp.h>
//#include <unordered_map>
//#include <typeinfo>
//#include <list>
//#include <string>
//#include <stack>

// #include <cln/cln.h>

//
//// Boost:
//#include <boost/any.hpp>
//#include <boost/thread.hpp>
//// Boost serialization:
//#include <boost/serialization/serialization.hpp>
//#include <boost/serialization/split_member.hpp>	// For separating reading and writing.
//#include <boost/serialization/list.hpp>
//#include <boost/archive/text_oarchive.hpp>
//#include <boost/archive/text_iarchive.hpp>
////#include <boost/archive/binary_oarchive.hpp>
////#include <boost/archive/binary_iarchive.hpp>

#include <noware/container/variable.h++>
#include <noware/container/entity.h++>
//////#include <noware/containers/entity.h++>
////#include <noware/containers/variable-undefine.h++>
//#include <noware/math.h++>
//#include <noware/serialization.h++>

//#include <noware/containers/text.h++>
//#include <noware/containers/any.hpp>
//#include <NoWare/Container/Variable.h>
//#include <noware/containers/array.hpp>
//#include <NoWare/Containers/Dynamic.h>
//#include <NoWare/Containers/Dynamic.cpp>
//#include "MPI.h"
//#include <noware/cluster.h++>
//#include "Memory.h"
//#include "HPC.cpp"
//#include "Numerical Strings.h"
//#include <vector>
//struct My
//{
//	int x, y;
//};

int main (unsigned long long int argc, char * argv [])
{
	//using boost::any_cast;
	using namespace std;
	using namespace noware;
	
	for (unsigned long long int i = 0; i < argc; ++ i)
		std::cout << argv [i] << ' ';
	std::cout << std::endl;
	std::cout << "Argument Count: " << argc << std::endl;
	
	
	//noware::container::variable option;
	noware::container::entity <> ntt1, ntt2;
	//noware::container::array <> arr;
	//noware::container::variable v;
	
	/*
	do
	{
		cout << "0. Exit" << endl;
		cout << "!0. Repeat" << endl;
		
		getline (cin, option);
		
		if (option != 0)
		{
			ntt ["one"] ["two"] ["three"] = 1234567;
			ntt ["one"] ["two"] ["second"] ["another"] = 12345;
			
			cout << "==========" << endl;
			cout << "Content:" << endl;
			
			cout << ntt ["one"] ["two"] ["three"] << endl;
			cout << ntt ["one"] ["two"] ["second"] ["another"] << endl;
			
			cout << ntt.serialize () << endl;
			
			cout << "==========" << endl;
			cout << endl;
		}
	}
	while (option != 0);
	*/
	
	//ntt = 12345;
	//arr ["NUMBER"] = 123;
	//v = 543;
	
	//cout << ntt.serialize () << endl;
	//cout << arr.serialize () << endl;
	//cout << v.serialize () << endl;
	
	//ntt1 [111] = 111;
	//ntt2 = ntt1;
	//cout << ntt2 [111] << endl;
	
	ntt1 ["ONE"] ["TWO"] = "VALUE";
	ntt2 ["ONE"] ["TWO"] = ntt1 ["ONE"] ["TWO"];
	cout << ntt2 ["ONE"] ["TWO"] << endl;
	
	//noware::container::entity <> ntt3 (ntt1);
	//cout << ntt3 ["ONE"] ["TWO"] << endl;
	
	return EXIT_SUCCESS;
}

