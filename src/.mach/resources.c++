/*
//#include <vector>
#include <sstream>
//#include <fstream>
#include <sstream>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/thread/detail/thread.hpp>
//#include <boost/thread/exceptions.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
//#include <boost/algorithm/string.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
*/

#include "resources.h++"

LIB::machine::resources::resource::resource (void)
{
	dev = NULL;
}

LIB::machine::resources::resource::resource (const resource & other)
{
	* (dev) = * (other.dev);
}

LIB::machine::resources::resource::~resource (void)
{
	try
	{
		if (dev != NULL)
		{
			delete dev;
		}
	}
	catch (...)
	{
	}
}

