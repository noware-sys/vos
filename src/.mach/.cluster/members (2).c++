#include "members.h++"

LIB::cluster::members::conflict::conflict (void)
{
	timer = NULL;
	response = false;
}

LIB::cluster::members::conflict::~conflict (void)
{
	if (timer != NULL)
	{
		delete timer;
	}
}

LIB::cluster::members::members (void/*const LIB::mathematics::numbers::natural & ka*/)
{
	//_active = false;
	// keepalive = 15000;
	
	//_local = NULL;
	//local_machine = NULL;
	// distribution = new boost::thread (boost::bind (& LIB::cluster::members::distribute, this));
	mpi.receive_async (boost::bind (boost::mem_fn (& LIB::cluster::members::input), this, _1, _2));
	mpi.listen_async (boost::bind (boost::mem_fn (& LIB::cluster::members::input), this, _1, _2));
}

LIB::cluster::members::~members (void)
{
	// delete distribution;
	//mpi.receive_async_stop (boost::bind (boost::mem_fn (& LIB::cluster::members::input), this, _1, _2));
	//mpi.listen_async_stop (boost::bind (boost::mem_fn (& LIB::cluster::members::input), this, _1, _2));
}

/*
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
*/

const LIB::mathematics::numbers::natural LIB::cluster::members::size (void) const
{
	return _members.size ();
}

const bool LIB::cluster::members::empty (void) const
{
	return size () <= 0;
}

template <typename archive>
void serialize (archive & arch, const unsigned int & version)
{
	arch & keepalive;
	arch & delay_max;
	arch & _members;
}

const LIB::NAME_A <LIB::cluster::machine, LIB::mathemathics::numbers::natural> & LIB::cluster::members::operator * (void) const
{
	return _members;
}

const LIB::NAME_A <LIB::cluster::machine, LIB::mathemathics::numbers::natural> & LIB::cluster::members::operator -> (void) const
{
	return operator * ();
}

const LIB::NAME_A <LIB::cluster::machine, LIB::mathemathics::numbers::natural> & LIB::cluster::members::operator () (void) const
{
	return operator * ();
}

const LIB::NAME_A <LIB::cluster::machine, LIB::mathemathics::numbers::natural> & LIB::cluster::members::list (void) const
{
	return operator * ();
}

void LIB::cluster::members::distribute (void)
{
	LIB::communication::message message;
	//std::string message_serial;
	
	////message.content ["addresses"] = network::ip::addresses ();
	//message.content ["id"] = local;
	
	message.content ["action"] = "presence";
	message.content ["function"] = "declaration";
	message.content ["value"] = true;
	//message.content ["endpoint"] ["port"] ["tcp"] = static_cast <LIB::network::ip::mpi> (mpi -> connections ()).;
	//message.content ["endpoint"] ["udp"] = mpi -> addrs.listen;
	//message.content ["endpoint"] ["tcp"] = mpi -> addrs.receive;
	
	//message.content ["id"] = * _local;
	//message.content ["id:next"] = nodes.sequence_next ();
	//message.content ["machines"] = nodes;
	
	//LIB::NAME_V * __id = & (message.content ["id"]);
	
	// message_serial = message;
	
	//message.content.clear ();
	
	//io.reset ();
	
	while (true)
	{
		//if (/*_local != NULL && */(* __id) != (* _local))
		//{
			//(* __id) = (* _local);
			message.content ["id"] = _local;
			message.content ["id:next"] = nodes.sequence_next ();
			message.content ["machines"] = nodes;
			message.content ["endpoint"] ["udp"] = mpi -> addrs.listen;
			message.content ["endpoint"] ["tcp"] = mpi -> addrs.receive;
			message.content ["time"] ["keepalive"] = keepalive;
			
			//message_serial = message;
		//}
		
		mpi.broadcast (message);
		
		//timer.expires_from_now (boost::posix_time::milliseconds (keepalive));
		
		//io.run ();
		boost::this_thread::sleep (boost::posix_time::milliseconds (keepalive));
	}
	
	//distribution = NULL;
}
/*
const LIB::mathematics::numbers::natural & LIB::cluster::members::local_id (void) const
{
	if (local == NULL)
		return 0;
	else
		return * local;
}

const bool LIB::cluster::members::run (const bool & state)
{
	if (state && ! active)
	{
		// Start.
		
		if (mpi == NULL)
		{
			return false;
		}
		
		//if (! nodes [local].run (state))
		//{
		//	return false;
		//}
		
		/*
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
		* /
		
		mathematics::numbers::natural __local;
		
		// Create the local machine.
		machine mach;
		
		mach.t = machine::type::literal;
		// Only the reference (address) is copied here.
		mach.mpi = mpi;
		mach.cluster = cluster;
		
		if (! nodes.enqueue (mach, __local))
		{
			nodes.clear ();
			
			return false;
		}
		
		// Prevent having multiple copies: refer to one copy.
		nodes [__local].id = _local = & nodes.get_key (__local);
		
		if (! nodes [__local].run ())
		{
			return false;
		}
		
		//local_machine = & nodes [__local];
		
		active = true;
		
		if (distribution == NULL)
		{
			distribution = new boost::thread (boost::bind (& LIB::cluster::members::distribute, this));
		}
		
		return true;
	}
	else if (! state && active)
	{
		// Stop.
		
		//if (! nodes [local].run (state))
		//{
		//	return false;
		//}
		nodes.clear ();
		
		//mpi = NULL;
		
		if (distribution != NULL)
		{
			try
			{
				delete distribution;
			}
			catch (...)
			{
			}
			
			distribution = NULL;
		}
		
		active = false;
		
		return true;
	}
	// There is nothing to be done.
	else
	{
		return true;
	}
	
	// Just in case.
	return false;
}

const bool & LIB::cluster::members::active (void) const
{
	return _active;
}
*/

void LIB::cluster::members::input (LIB::entity <> remote_endpoint, const std::string & message_serial)
{
	LIB::communication::message message/*, message_outgoing*/;
	LIB::entity <> address_outgoing/*, address_source*/;
	LIB::cluster::peer /*member_source, */member_destination;
	
	if (message.deserialize (message_serial))
	{
		//LIB::communication::message message;
		//std::string serial_message;
		
		// Validate.
		//if (message.content ["id"] != ""/* && message.content ["id"] != 0*/)
		if (message.content.exist ("id")/* && !message.content ["id"].empty ()*/ && message.content ["id"] != 0)
		{
			// if (message.content.exist ("endpoint") && message.content ["endpoint"].exist ("tcp"))
			// {
			// 	remote_endpoint ["port"] = message.content ["endpoint"] ["tcp"] ["port"];
			// }
			
			//LIB::entity <> remote_endpoint = remote_endpoint_received;
			//remote_endpoint.unset ("port");
			std::cout << std::endl;
			std::cout << '(' << LIB << "::cluster::cluster::input ()) Remote Endpoint [\"port\"] == " << remote_endpoint ["port"] << std::endl;
			std::cout << std::endl;
			
			//address_outgoing ["address"] = remote_endpoint ["address"];
			// address_source ["port"] = mpi.receive ["port"];
			
			//member_source.deserialize (message.content ["meta"] ["member_source"]);
			
			if (/*message.content.exist ("meta") && message.content ["meta"].exist ("member_destination") && */member_destination.deserialize (message.content ["meta"] ["member_destination"]) && !member_destination.path.empty ())
			{
				//machine_source = message.content ["meta"] ["machine_source"];
				
				//machine_source.path.push (remote_endpoint);
				address_outgoing = member_destination.path.beginning ();
				//address_outgoing ["address"] = remote_endpoint ["address"];
				
				member_destination.path.dequeue ();
				// member_source.path.enqueue (address_source);
				
				message.content ["meta"] ["member_destination"] = member_destination;
				// message.content ["meta"] ["member_source"] = member_source;
				//message.content ["endpoint"] ["tcp"] ["port"]= remote_endpoint ["port"];
				//message.content ["meta"] ["machine_source"] = machine_source;
				//message.content ["meta"] ["machine_destination"] = machine_destination;
				
				// Try to transmit.
				mpi.transmit (message, address_outgoing);
				
				return;
			}
			
			//message.content ["addresses"] = network::ip::addresses ();
			// Peer probing.
			if (message.content ["action"] == "presence")
			{
				if (message.content ["function"] == "declaration"/* && message.content ["value"] == true*//* Ensure obtaining the intended meaning of the condition by forcing type coercion by explicitly comparing. */)
				{
					//machines.nodes.exist (message.content ["id"])
					LIB::NAME_A <LIB::cluster::member, LIB::mathemathics::numbers::natural/* id*/> __members;
					LIB::mathematics::numbers::natural id;
					bool exist;
					
					__members = message.content ["members"];
					exist = false;
					
					for (auto & __member : __members)
					{
						if (__members.exist (__member.k))
						{
							id = __member.k;
							exist = true;
							
							break;
						}
					}
					
					if (exist)
					{
						//conflicts [id] [remote_endpoint ["address"]].response = false;
						
						//conflicts.io [id] [remote_endpoint ["address"]];	// Create an io_service.
						conflicts [id] [remote_endpoint ["address"]].timer = new boost::asio::deadline_timer (conflicts [id] [remote_endpoint ["address"]].io);
						
						//LIB::tools::randomizer randomizer;
						
						//delay = randomizer.generate (delay_max);
						
						conflicts [id] [remote_endpoint ["address"]].timer -> expires_from_now (boost::posix_time::milliseconds (randomizer.generate (delay_max)));
						conflicts [id] [remote_endpoint ["address"]].timer -> async_wait (boost::bind (& LIB::cluster::members::dummy, this));
						
						conflicts [id] [remote_endpoint ["address"]].io.run ();
						
						if (!conflicts [id] [remote_endpoint ["address"]].response)
						{
							LIB::communication::message message_response;
							
							message_response.content ["action"] = "resolution";
							message_response.content ["function"] = "response";
							message_response.content ["topic"] = "id";
							
							if (mpi.transmit (message_response, remote_endpoint))
							{
								mathematics::numbers::natural next_available_location;
								
								next_available_location = _members.sequence_next ();
								
								if (id > next_available_location)
								{
									next_available_location = id;
								}
								
								// Try to rename.
								if (_members.rename (local, next_available_location))
								{
									local = next_available_location;
								}
								
								/*
								message_demand.content ["id"] = machines ().nodes.local;
								//message_demand.content ["addresses"] = network::ip::addresses (0, false);
								message_demand.content ["action"] = "rename";
								message_demand.content ["function"] = "interrogation";
								message_demand.content ["proposed_id"] = machines ().nodes.next_id ();
								*/
								
								//mpi.transmit (message_demand, remote_endpoint);
							}
						}
						
						conflicts [id].unset (remote_endpoint ["address"]);
						//conflicts [id].io.unset (remote_endpoint ["address"]);
						//delete conflicts [id].timer [remote_endpoint ["address"]];
						//conflicts [id].timer.unset (remote_endpoint ["address"]);
						
						if (conflicts [id].empty ()/* The rest (io, timer) should also be empty. */)
						{
							conflicts.unset (id);
							//// The rest should also be empty.
							//conflicts [id].io.unset (id);
							//conflicts [id].timer.unset (id);
						}
					}
					else
					{
						/*for (auto & mach : machs)
						{
							// Refer to the actual key, to prevent having another copy.
							machines ().nodes [mach.k].id = & machines ().nodes.get_key (mach.k);
							machines ().nodes [mach.k].cluster = machines ().cluster;
							machines ().nodes [mach.k].mpi = machines ().mpi;
							machines ().nodes [mach.k].path = mach.path;
							machines ().nodes [mach.k].path.push (remote_endpoint);
							//machines ().nodes [message.content ["id"]].timeout = message.content ["timeout"];
							
							machines ().nodes [mach.k].run ();
						}*/
						
						LIB::cluster::peer member;
						//peer = message.content ["member"];
						
						if (member.deserialize (message.content ["member"])/* && member.id != 0*/)
						{
							_members [member.id] = member;
						}
						
						// Refer to the actual key, to prevent having another copy.
						//machines.nodes [message.content ["id"]].id = & machines.nodes.get_key (message.content ["id"]);
						//machines.nodes [message.content ["id"]].path = message.content ["path"];
						//machines.nodes [message.content ["id"]].timeout = message.content ["timeout"];
					}
				}
			}
			else if (message.content ["action"] == "resolution")
			{
				if (message.content ["function"] == "response")
				{
					if (message.content ["topic"] == "id")
					{
						conflicts [id] [remote_endpoint ["address"]].response = true;
					}
				}
			}
			else if (message.content ["action"] == "memory:presence")
			{
				if (message.content ["function"] == "demand")
				{
					LIB::cluster::machine machine;
					LIB::communication::message message_response;
					
					machine = message.content ["meta"] ["machine_source"];
					
					message_response.content ["action"] = "memory:presence";
					message_response.content ["function"] = "response";
					
					message_response.content ["value"] = static_cast <LIB::resources::memory> (machines () () [machines ().local_id ()].resources () ["memory"]).exist (message.content ["entity"] ["name"], message.content ["entity"] ["group"]);
					
					transmit (message_response, machine);
				}
			}
			else if (message.content ["action"] == "memory:presence")
			{
				if (message.content ["function"] == "response")
				{
					LIB::resources::memory * memory = & static_cast <LIB::resources::memory> (machines () () [machines ().local_id ()].resources () ["memory"]);
					
					if (message.content ["meta"].exist ("communication") && message.content ["meta"] ["communication"].exist ("id"))
					{
						if (communications.exist (message.content ["meta"] ["communication"] ["id"]))
						{
							communications [message.content ["meta"] ["communication"] ["id"]].data = message.content ["value"];
							communications [message.content ["meta"] ["communication"] ["id"]].lock.unlock ();
						}
					}
					else if (message.content.exist ("search") && message.content ["search"].exist ("id"))
					{
						memory -> searches [message.content ["search"] ["id"]].machines [message.content ["id"]].found = message.content ["value"];
						memory -> searches [message.content ["search"] ["id"]].machines [message.content ["id"]].responded = true;
						
						if (memory -> searches [message.content ["search"] ["id"]].responded ())
						{
							memory -> searches [message.content ["search"] ["id"]].lock.unlock ();
						}
					}
				}
			}
			else if (message.content ["action"] == "memory:variable")
			{
				if (message.content ["function"] == "demand")
				{
					if (message.content.exist ("machine_source"))
					{
						LIB::cluster::machine mach = message.content ["machine_source"];
						
						if (mach.active ())
						{
							LIB::machine::resources::memory * memory = & static_cast <LIB::resources::memory> (machines () () [machines ().local_id ()].resources () ["memory"]);
							LIB::machine::resources::memory::keys k;
							
							if (message.content.exist ("value") && message.content.exist ["value"].exist ("name") && message.content ["value"].exist ("group"))
							{
								k.name = message.content ["value"] ["name"];
								k.group = message.content ["value"] ["group"];
								
								if (memory -> variables.exist (k))
								{
									LIB::communication::message message_response;
									
									message_response.content ["value"] = memory -> variables.get (k);;
									
									transmit (message_response, mach);
								}
							}
						}
					}
				}
			}
		}
	}
}

void LIB::cluster::members::dummy (void) const
{
	// Do not do anything.
}
