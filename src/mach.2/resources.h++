#ifndef RESOURCES
#define RESOURCES

// Standard:
#include <string>
/*
#include <queue>
#include <stack>

// Boost:
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include <boost/serialization/serialization.hpp>

// Boost serialization:
//#include <boost/archive/binary_oarchive.hpp>
//#include <boost/archive/binary_iarchive.hpp>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>	//
#include <boost/date_time/posix_time/posix_time.hpp>
*/

// This class:
//#include "../default.h++"
#include "../containers/array.h++"
//#include "../mathematics.h++"
//#include "../containers/variable.h++"
//#include "../tools.h++"
//#include "memory.h++"
//#include "../serialization.h++"
#include "./resource.h++"

namespace LIB
{
	class cluster
	{
		public:
			class peer
			{
				public:
					class resources
					{
						public:
							/*
							class processors : public resource
							{
								public:
									processors (void);
							
									LIB::mathematics::numbers::natural total (void);
									LIB::mathematics::numbers::natural general (void);
									LIB::mathematics::numbers::natural graphic (void);
								protected:
									LIB::mathematics::numbers::natural _general, _graphic, _total;
							};
							*/
							resources (void);
							//~resources (void);
							
							LIB::NAME_A <resource/*, std::string*/> _resources;
					};
			};
	};
}

#endif
