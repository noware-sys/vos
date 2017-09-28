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

//#include "device.h++"
#include ".device/*.cxx"

unsigned short int noware::machine::device::instance_count = 0;
//noware::net::cluster * noware::machine::device::cluster = nullptr;

LIB::machine::device::device (void)
{
	//_active = false;
	
	//l = location::literal;
	//t = type::other;
	
	++ instance_count;
	
	if (instance_count == 1)
	{
		cluster = new noware::net::cluster;
		
		// Set up:
		cluster -> receive_async (boost::bind (boost::mem_fn (&noware::machine::device::handler), this));
	}
}

LIB::machine::device::~device (void)
{
	-- instance_count;
	
	if (instance_count == 0)
	{
		delete cluster;
		//cluster = nullptr;	// Not necessary (not checked for).
	}
}

/*
LIB::machine::device::device (const device & other)
{
	* this = other;
}
*/

const bool LIB::machine::device::operator == (const LIB::machine::device & other) const
{
	if (t != other.t)
	{
		return false;
	}
	
	return true;
}
/*
const LIB::machine::device::type & LIB::machine::device::get_type (void) const
{
	return t;
}

const LIB::machine::device::location & LIB::machine::device::get_location (void) const
{
	return l;
}
*/
/*
const bool LIB::machine::device::run (const bool & state)
{
	if (state && !_active)
	{
		_active = state;
	}
	else if (!state && _active)
	{
		_active = state;
	}
	else
	{
		return true;
	}
	
	return false;
}

const bool LIB::machine::device::active (void) const
{
	return _active;
}
*/

void handler (const noware::container::set <> & message, const noware::container::set <> & remote_endpoint) const
{
	//type t = message ["meta"] ["type"];
	
	if (message.exist ("meta") && message ["meta"].exist ("type"))
		for (const auto & t : message ["meta"] ["type"])
			if (receivers.exist (t) && !receivers [t].empty ())
				receivers [t] (message, remote_endpoint);
}

const bool transmit (const noware::container::set <> & message, const noware::container::array <noware::math::numbers::natural/*, noware::math::numbers::natural*/> & nodes) const
{
	return cluster -> transmit (message, nodes);
}

const bool broadcast (const noware::container::set <> & message) const
{
	return cluster -> broadcast (message);
}

