#include <iostream>
#include <fstream>
#include <string>

#include "machine.h++"

LIB::machine::machine::machine (const LIB::mathematics::numbers::natural & to)
//LIB::machine::machine::machine (void)
{
	//t = type::reference;
	//_active = false;
	//mpi = NULL;
	
	//// Needed?
	//id = 0;
	//id = NULL;
	
	/*
	scanning = NULL;
	timeout_timer_wait_thread = NULL;
	mpi = NULL;
	mutex_timeout_timer = NULL;
	condition_variable_timeout_timer = NULL;
	*/
	//keepalive = 15000000;
	timeout = to;
	//tries = 3;
	
	//mpi = new LIB::network::mpi ();
	// Register the handlers.
	//mpi -> ;
	
	// error ["message"] = "";
	// error ["code"] = "0";
	//std::cout << "message: " << error ["message"] << std::endl;
	//std::cout << "code: " << error ["code"] << std::endl;
	
	//devs ["cpu"] = new LIB::machine::devices::processor ();
	//error.tolerant = false;
	//error.set ((std::string) "message", "");
	//error.set ((std::string) "code", "0");
	
	// rsrc ["memory"] = new LIB::machine::resources::memory ();
	// rsrc ["processor"] = new LIB::machine::resources::processor ();
}

LIB::machine::machine::machine (const std::string & serial)
{
	operator = (serial);
}

LIB::machine::machine::machine (const machine & other)
{
	operator= (other);
}

LIB::machine::machine::~machine (void)
{
	// Only delete if owned.
	if (t == type::literal)
	{
		//if (timeout_timer_wait_thread != NULL)
		//{
		//	delete timeout_timer_wait_thread;
		//}
	}
	
	//mpi = NULL;
	
	clear ();
	
	/*
	for (auto & element : resources)
	{
		if (element.v != NULL)
		{
			try
			{
				delete element.v;
			}
			catch (...)
			{
			}
		}
	}
	
	for (auto & element : peers)
	{
		if (element.v != NULL)
		{
			try
			{
				delete element.v;
			}
			catch (...)
			{
			}
		}
	}
	*/
	
	delete rsrc ["memory"];
	delete rsrc ["processor"];
}

LIB::machine::machine::machine (const machine & mach)
{
	operator = (mach);
}

template <typename archive>
void LIB::machine::machine::serialize (archive & arch, const unsigned int & version)
{
	arch & t;
	//arch & l;
	arch & _active;
	arch & timeout;
	arch & id;
}

/*
template <typename archive>
void save (archive & arch, const unsigned int & version) const
{
	type tp = type::reference;
	
	arch << tp;
	arch << timeout;
	
	if (id != NULL)
	{
		arch << * id;
	}
}

template <typename archive>
void load (archive & arch, const unsigned int & version)
{
	arch >> t;
	arch >> timeout;
}
*/
const LIB::machine::machine & operator = (const std::string & serial)
{
	deserialize (serial);
	
	return * this;
}

operator const std::string (void)
{
	return serialize ();
}

const std::string serialize (void)
{
	return LIB::serialize <LIB::machine::machine> (* this);
}

const bool deserialize (const std::string & serial)
{
	return LIB::deserialize <LIB::machine::machine> (serial, * this);
}

const LIB::machine::machine LIB::machine::machine::operator = (const machine & other)
{
	if (t == type::literal)
	{
		// Do not overwrite a real machine.
		// It must be turned into a reference, first.
		if (! run (false))
		{
			// Could not stop it.
			return * this;
		}
	}
	
	//t = other.t;
	t = type::reference;
	// timeout = other.timeout;
	//rsrc = other.rsrc;
	//path = other.path;
	
	return * this;
}

const bool LIB::machine::machine::run (const bool & state)
{
	// Only an actual machine may be managed.
	if (t != type::literal)
	{
		// Consider that it is a literal, but do not actually modify anything.
		_active = state;
		
		return true;
	}
	
	//LIB::communication::message message;
	
	if (state && !_active)
	{
		// Start.
		
		// Add the handlers.
		//mpi -> receive_async (boost::bind (boost::mem_fn (& LIB::machine::machine::receive), this, _1));
		//mpi -> listen_async (boost::bind (boost::mem_fn (& LIB::machine::machine::listen), this, _1));
		
		//LIB::communication::message message;
		//std::string serial_message;
		
		//message.content ["addresses"] = network::ip::addresses ();
		//message.content ["action"] = "presence";
		//message.content ["function"] = "interrogation";
		//message.content ["value"] = true;
		
		//mpi -> broadcast (message);
		/*
		id = next_id ();
		
		// Start polling after the ID is obtained.
		if (scanning == NULL)
		{
			scanning = new boost::thread (boost::bind (& LIB::machine::machine::scan, this));
		}
		*/
		
		if (mpi == NULL)
		{
			return false;
		}
		
		for (auto & _resource: rsrc)
		{
			if (! _resource.v.run ())
			{
				return false;
			}
		}
		
		_active = state;
		
		return true;
	}
	else if (! state && _active)
	{
		// Stop.
		
		
		//if (timeout_timer_wait_thread != NULL)
		//{
		//	delete timeout_timer_wait_thread;
		//}
		
		//id = NULL;
		
		clear ();
		
		_active = state;
		
		return true;
	}
	else
	{
		// Nothing needs to be done.
		
		return true;
	}
	
	return false;
}

const LIB::machine::machine::type & LIB::machine::machine::get_type (void) const
{
	return t;
}

const bool & LIB::machine::machine::active (void) const
{
	return _active;
}

/*
const LIB::NAME_A <LIB::machine::machine, LIB::mathematics::numbers::natural> LIB::machine::machine::peers (const bool & recursive)
{
	switch (recursive)
	{
		case false:
			//LIB::NAME_A <machine *, mathematics::numbers::natural> nodes;
			LIB::NAME_A <LIB::machine::machine, LIB::mathematics::numbers::natural> nodes;
			
			for (auto & element : machines)
			{
				// Add the direct peers.
				//if (element.v -> path.size () <= 1)
				if (element.v -> path.size () == 1)
				{
					nodes += element.v;
				}
			}
			
			return nodes;
			
			break;	// Backup; in case the control was not returned from this block.
		//case true:
		default:
			return machines;
	}
	
	//return machines;
}
*/

const LIB::NAME_A <LIB::machine::resource *, std::string> LIB::machine::machine::resources (void) const
{
	/*
	switch (recursive)
	{
		case false:
			LIB::NAME_A <machine::resource> src;
			
			for (auto & element : machines)
			{
				// Add the direct peers.
				if (element.v -> path.size () <= 1)
				{
					src += element.v;
				}
			}
			
			return src;
			
			break;	// Backup; in case the control was not returned from this block.
		case true:
		default:
			return rscs;
	}
	*/
	return rsrc;
}

/*
void LIB::machine::machine::timeout_pause (void)
{
	boost::unique_lock <boost::mutex> lock (* mutex_timeout_timer);
	
	while (! * main_timeout_timer_running)
	{
		condition_variable_timeout_timer -> wait (lock);
	}
	
	io_service.run ();
	
	timeout_timer_running = false;
	
	timeout_timer_wait_thread = NULL;
	
	if (! responded)
	{
		// Remove self from list.
		//machine * m = machines -> operator [] (id);	// Try first.
		//machines -> unset (id);
		//delete m;
	}
}
*/

/*
const LIB::NAME_A <LIB::network::ip::address, LIB::mathematics::numbers::natural> & LIB::machine::machine::addresses (void)
{
	return LIB::network::ip::addresses ();
}
*/
/*
void LIB::machine::machine::clear (void)
{
	for (auto & rsc : rsrc)
	{
		delete rsc.v;
	}
	
	rsrc.clear ();
	//machines_clear ();
}
*/
//const bool LIB::machine::machine::operator == (const machine & other) const
//{
//	//return rsrc == other.rsrc;
//	return false;
//}
