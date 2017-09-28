#include "members.h++"

LIB::cluster::members::members (const LIB::mathematics::numbers::natural & ka)
{
	running = false;
	keepalive = ka;
}

LIB::cluster::members:: ~ members (void)
{
}

const LIB::mathematics::numbers::natural LIB::cluster::members::count (void) const
{
	return size ();
}

const LIB::mathematics::numbers::natural LIB::cluster::members::cardinality (void) const
{
	return size ();
}

const LIB::mathematics::numbers::natural LIB::cluster::members::magnitude (void) const
{
	return size ();
}

const LIB::mathematics::numbers::natural LIB::cluster::members::size (void) const
{
	return nodes.size ();
}

const bool LIB::cluster::members::empty (void) const
{
	return nodes.empty ();
}

const LIB::NAME_A <LIB::cluster::machine, LIB::mathemathics::numbers::natural> & LIB::cluster::members::operator * (void)
{
	return nodes;
}

const LIB::NAME_A <LIB::cluster::machine, LIB::mathemathics::numbers::natural> & LIB::cluster::members::operator -> (void)
{
	return operator * ();
}

const LIB::NAME_A <LIB::cluster::machine, LIB::mathemathics::numbers::natural> & LIB::cluster::members::operator () (void)
{
	return operator * ();
}

void LIB::cluster::members::scan (void)
{
	LIB::communication::message message;
	std::string message_serial;
	
	message.content ["addresses"] = network::ip::addresses ();
	message.content ["id"] = local;
	
	message.content ["action"] = "presence";
	message.content ["function"] = "interrogation";
	//message.content ["value"] = true;
	
	message_serial = message;
	
	while (true)
	{
		if (mpi -> broadcast (message_serial))
		{
			io_service.reset ();
			scanning_timer.expires_from_now (boost::posix_time::microseconds (keepalive));
			
			{
				boost::unique_lock <boost::mutex> lock (mutex_timeout_timer);
				timeout_timer_running = false;
				//condition_variable_timeout_timer -> notify_all ();
			}
			
			for (auto & element : nodes)
			{
				if (! element.v.timeout_timer_running)
				{
					element.v.io_service.reset ();
					
					//element.v -> timeout = element.v -> timeout;
					element.v.timeout_timer.expires_from_now (boost::posix_time::microseconds (element.v.timeout));
					
					element.v.mutex_timeout_timer = & mutex_timeout_timer;
					element.v.condition_variable_timeout_timer = & condition_variable_timeout_timer;
					element.v.main_timeout_timer_running = & timeout_timer_running;
					element.v.responded = false;
					element.v.timeout_timer_running = true;
					
					//if (element.v -> timeout_timer_wait_thread == NULL)
					//{
						//element.v -> timeout_timer_wait_thread = new boost::thread (boost::bind (& element.v -> timeout_pause), element.v));
						element.v.timeout_timer_wait_thread = new boost::thread (boost::bind (& LIB::cluster::machine::timeout_pause), & element.v));
					//}
				}
			}
			
			// Start the timeout timer on all peers.
			timeout_timer_running = true;
			condition_variable_timeout_timer.notify_all ();
			
			//time_run ();
			io_service.run ();
		}
	}
}

const LIB::mathematics::numbers::natural & LIB::cluster::members::get_local (void) const
{
	return local;
}

const LIB::mathematics::numbers::natural & LIB::cluster::members::run (const bool & active)
{
	if (active && ! running)
	{
		// Start.
		
		if (mpi == NULL)
		{
			return false;
		}
		
		//if (! nodes [local].run (active))
		//{
		//	return false;
		//}
		
		// Get the list of (directly connected) peers.
		communication::message message;
		
		//message.content ["addresses"] = network::ip::addresses (0, false);
		message.content ["id"] = local;
		message.content ["action"] = "presence";
		message.content ["function"] = "interrogation";
		message.content ["recursive"] = false;//true;
		message.content ["machines"] = nodes;
		
		if (! mpi -> broadcast (message))
		{
			return false;
		}
		
		// Wait for all machines to respond.
		// Use the existing variables, as they are not in use now.
		io_service.reset ();
		scanning_timer.expires_from_now (boost::posix_time::microseconds (keepalive));
		io_service.run ();
		
		// Now, the list should have been, in normal conditions, populated.
		// Create the local machine.
		machine mach;
		
		mach.t = machine::type::literal;
		mach.mpi = mpi;	// Only the reference (address) is copied here.
		
		if (! nodes.enqueue (mach, local))
		{
			nodes.clear ();
			
			return false;
		}
		
		// Refer to the actual key, to prevent having another copy.
		nodes [local].id = & nodes.get_key (local);
		
		
		if (scanning == NULL)
		{
			scanning = new boost::thread (boost::bind (& LIB::cluster::members::scan, this));
		}
		
		return true;
	}
	else if (! active && running)
	{
		// Stop.
		
		//if (! nodes [local].run (active))
		//{
		//	return false;
		//}
		nodes.clear ();
		
		//mpi = NULL;
		
		if (scanning != NULL)
		{
			try
			{
				delete scanning;
			}
			catch (...)
			{
			}
			
			scanning = NULL;
		}
		
		return true;
	}
	
	return false;
}
