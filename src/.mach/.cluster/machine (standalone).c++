#include <iostream>
#include <fstream>
#include <string>

#include "machine.h++"

LIB::cluster::machine::machine (void)
{
	machines = NULL;
	running = false;
	
	main_timeout_timer_running = NULL;
	timeout_timer_running = false;
	responded = false;
	
	t = type::literal;
	
	// Needed?
	id = 0;
	
	scanning = NULL;
	timeout_timer_wait_thread = NULL;
	mpi = NULL;
	mutex_timeout_timer = NULL;
	condition_variable_timeout_timer = NULL;
	
	keepalive = 15000000;
	timeout = 10000000;
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
}

LIB::cluster::machine::~ machine (void)
{
	// Only delete if owned.
	if (t == type::literal)
	{
		if (scanning != NULL)
		{
			delete scanning;
		}
		
		if (machines != NULL)
		{
			delete machines;
		}
		
		if (mpi != NULL)
		{
			delete mpi;
		}
		
		if (mutex_timeout_timer != NULL)
		{
			delete mutex_timeout_timer;
		}
		
		if (condition_variable_timeout_timer != NULL)
		{
			delete condition_variable_timeout_timer;
		}
		
		if (timeout_timer_wait_thread != NULL)
		{
			delete timeout_timer_wait_thread;
		}
		
		if (main_timeout_timer_running != NULL)
		{
			delete main_timeout_timer_running;
		}
	}
	
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
}

const bool LIB::cluster::machine::run (const bool & active)
{
	// Only an actual machine can be managed.
	if (t != type::literal)
	{
		return true;
	}
	
	LIB::communication::message message;
	
	if (active && ! running)
	{
		// Start.
		
		/*
		if (id == 0)
		{
			id = 1;
		}
		*/
		
		if (mutex_timeout_timer == NULL)
		{
			mutex_timeout_timer = new boost::mutex ();
		}
		
		if (condition_variable_timeout_timer == NULL)
		{
			condition_variable_timeout_timer = new boost::condition_variable ();
		}
		
		if (main_timeout_timer_running == NULL)
		{
			main_timeout_timer_running = new bool ();
		}
		
		if (machines == NULL)
		{
			machines = new LIB::NAME_A <machine *, mathematics::numbers::natural> ();
		}
		
		if (mpi == NULL)
		{
			mpi = new LIB::network::mpi ();
		}
		
		// Add the handlers.
		mpi -> receive_async (boost::bind (boost::mem_fn (& LIB::cluster::machine::receive), this, _1));
		mpi -> listen_async (boost::bind (boost::mem_fn (& LIB::cluster::machine::listen), this, _1));
		
		//LIB::communication::message message;
		//std::string serial_message;
		
		message.content ["addresses"] = network::ip::addresses ();
		message.content ["action"] = "presence";
		message.content ["function"] = "interrogation";
		//message.content ["value"] = true;
		
		mpi -> broadcast (message);
		/*
		id = next_id ();
		
		// Start polling after the ID is obtained.
		if (scanning == NULL)
		{
			scanning = new boost::thread (boost::bind (& LIB::cluster::machine::scan, this));
		}
		*/
		running = true;
		
		return true;
	}
	else if (! active && running)
	{
		// Stop.
		
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
		
		if (mutex_timeout_timer != NULL)
		{
			delete mutex_timeout_timer;
		}
		
		if (condition_variable_timeout_timer != NULL)
		{
			delete condition_variable_timeout_timer;
		}
		
		if (main_timeout_timer_running != NULL)
		{
			delete main_timeout_timer_running;
		}
		
		if (timeout_timer_wait_thread != NULL)
		{
			delete timeout_timer_wait_thread;
		}
		
		if (mpi != NULL)
		{
			// Remove the handlers.
			mpi -> receive_async_stop (boost::bind (boost::mem_fn (& LIB::cluster::machine::receive), this, _1));
			mpi -> listen_async_stop (boost::bind (boost::mem_fn (& LIB::cluster::machine::listen), this, _1));
			
			message.content ["addresses"] = network::ip::addresses ();
			message.content ["action"] = "presence";
			message.content ["function"] = "declaration";
			message.content ["value"] = false;
			
			mpi -> broadcast (message);
		}
		
		if (machines != NULL)
		{
			delete machines;
		}
		
		id = 0;
		
		clear ();
		
		running = false;
		
		return true;
	}
	else
	{
		// Nothing needs to be done.
		
		return true;
	}
	
	return false;
}

const LIB::cluster::machine::type & LIB::cluster::machine::get_type (void) const
{
	return t;
}

const LIB::network::mpi * & LIB::cluster::machine::get_mpi (void) const
{
	return mpi;
}

const LIB::NAME_A <LIB::cluster::machine *, LIB::mathematics::numbers::natural> * LIB::cluster::machine::peers (const bool & recursive)
{
	/*
	switch (recursive)
	{
		case false:
			LIB::NAME_A <machine *, mathematics::numbers::natural> nodes;
			
			for (auto & element : machines)
			{
				// Add the direct peers.
				if (element.v -> path.size () <= 1)
				{
					nodes += element.v;
				}
			}
			
			return nodes;
			
			break;	// Backup; in case the control was not returned from this block.
		case true:
		default:
			return machines;
	}
	*/
	return machines;
}

const LIB::NAME_A <LIB::machine::resource> LIB::cluster::machine::resources (const bool & recursive)
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
	return rscs;
}

void LIB::cluster::machine::receive (const std::string & message_serial)
{
	LIB::communication::message message, message_outgoing;
	//LIB::entity <> outgoing_address;
	
	if (message.deserialize (message_serial))
	{
		//LIB::communication::message message;
		//std::string serial_message;
		
		//message.content ["addresses"] = network::ip::addresses ();
		// Peer probing.
		if (message.content ["action"] == "presence")
		{
			if (message.content ["function"] == "declaration"/* && message.content ["value"] == true*//* Ensure obtaining the intended meaning of the condition by forcing type coercion by explicitly comparing. */)
			{
				// Validate.
				if (message.content ["id"] != ""/* && message.content ["id"] != 0*/)
				{
					/*
					if (id == message.content ["id"])
					{
						message_outgoing.content ["addresses"] = network::ip::addresses ();
					 
						send (message_outgoing, message_outgoing.content ["addresses"]);
						//mpi -> send ();
					}
					else if (machines.exist (message.content ["id"]))
					{
						// Update the element.
					}
					*/
					/*
					if (! message.content.exist ("value") || message.content ["value"] == true)
					{
						// Keep.
					 
					}
					else 
					*/
					
					if (message.content ["id"] == 0)
					{
						// Add.
					}
					else if (machines -> exist (message.content ["id"]))
					{
						if (message.content.exist ("value"))
						{
							if (message.content ["value"])
							{
								// Prevent removal.
								machines -> operator [] (message.content ["id"]) -> responded = true;
								machines -> operator [] (message.content ["id"]) -> io_service.stop ();
							}
							else
							{
								// Explicit removal.
								// Remove.
								
								rscs.unset (message.content ["id"]);
								
								//if (machines -> exist (message.content ["id"]))
								//{
									delete machines -> operator [] (message.content ["id"]);
								//}
								
								machines -> unset (message.content ["id"]);
								
								// TODO: Pass on this message to indirectly connected peers, to notify them of this removal request too.
								//broadcast ();
							}
						}
					}
				}
			}
			//else if (message.content ["function"] == "interrogation")
			//{}
		}
	}
}

void LIB::cluster::machine::listen (const std::string & message_serial)
{
	LIB::communication::message message;
	
	if (message.deserialize (message_serial))
	{
		
	}
}

const bool send (const mathematics::numbers::natural &, const communication::message & message) const
{}

const bool broadcast (const mathematics::numbers::natural &, const communication::message & message) const
{}

void LIB::cluster::machine::scan (void)
{
	LIB::communication::message message;
	std::string message_serial;
	
	message.content ["addresses"] = network::ip::addresses ();
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
				boost::unique_lock <boost::mutex> lock (* mutex_timeout_timer);
				* main_timeout_timer_running = false;
				//condition_variable_timeout_timer -> notify_all ();
			}
			
			for (auto & element : peers)
			{
				if (! element.v -> timeout_timer_running)
				{
					element.v -> io_service.reset ();
					
					//element.v -> timeout = element.v -> timeout;
					element.v -> scanning_timer.expires_from_now (boost::posix_time::microseconds (element.v -> timeout));
					
					element.v -> mutex_timeout_timer = mutex_timeout_timer;
					element.v -> condition_variable_timeout_timer = condition_variable_timeout_timer;
					element.v -> main_timeout_timer_running = main_timeout_timer_running;
					element.v -> responded = false;
					element.v -> timeout_timer_running = true;
					
					//if (element.v -> timeout_timer_wait_thread == NULL)
					//{
						//element.v -> timeout_timer_wait_thread = new boost::thread (boost::bind (& element.v -> timeout_pause), element.v));
						element.v -> timeout_timer_wait_thread = new boost::thread (boost::bind (& LIB::cluster::machine::timeout_pause), element.v));
					//}
				}
			}
			
			// Start the timeout timer on all peers.
			* main_timeout_timer_running = true;
			condition_variable_timeout_timer -> notify_all ();
			
			//time_run ();
			io_service.run ();
		}
	}
}

/*
void LIB::cluster::machine::timeout_time_run (void)
{
	{
		boost::unique_lock <boost::mutex> lock (mutex_timeout_timer);
		running_timeout_timer = false;
	}
	
	condition_variable_timeout_timer.notify_all ();
}
*/

void LIB::cluster::machine::timeout_pause (void)
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
		machine * m = machines -> operator [] (id);	// Try first.
		machines -> unset (id);
		delete m;
	}
}

void LIB::cluster::machine::clear (void)
{
	resources.clear ();
	machines_clear ();
}

const bool LIB::cluster::machine::machines_clear (void)
{
	for (auto & element : * machines)
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
	
	machines -> clear ();
	
	return true;
}

const LIB::mathematics::numbers::natural LIB::cluster::machine::next_id (void) const
{
	return 1;
}
