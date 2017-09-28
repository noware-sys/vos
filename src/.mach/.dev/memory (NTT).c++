#include "memory.h++"
#include "../../network/ip.h++"
#include <boost/mem_fn.hpp>
#include <boost/ref.hpp>

/*
LIB::machine::resources::memory::NTT::NTT (void)
{
	//current_group = "";
}

NTT & LIB::machine::resources::memory::NTT::operator [] (const key &)
{
	
}

const NTT & LIB::machine::resources::memory::NTT::operator [] (const key &) const
{
	
}
*/
LIB::machine::resources::memory::keys::keys (void)
{
	grouped = false;
	
	name = "";
	group = "";
}

LIB::machine::resources::memory::keys::keys (const keys & other)
{
	grouped = other.grouped;
	
	name = other.name;
	group = other.group;
}

LIB::machine::resources::memory::keys::operator== (const keys & other) const
{
	if (grouped || other.grouped)
		return group == other.group;
	else
		return name == other.name && group == other.group;
}

LIB::machine::resources::memory::keys::operator!= (const keys & other) const
{
	return !operator== (other);
}

LIB::machine::resources::memory::research::response::response (void)
{
	found = false;
	responded = false;
}


const LIB::NAME_A <LIB::mathematics::numbers::natural, LIB::mathematics::numbers::natural> LIB::machine::resources::memory::research::owners (void) const
{
	LIB::NAME_A <LIB::mathematics::numbers::natural, LIB::mathematics::numbers::natural> list;
	
	for (auto & mach : machines)
	{
		if (mach.v.found)
		{
			list.enqueue (mach.k);
		}
	}
	
	return list;
}

const LIB::NAME_A <LIB::mathematics::numbers::natural, LIB::mathematics::numbers::natural> LIB::machine::resources::memory::research::owner (void) const
{
	LIB::NAME_A <LIB::mathematics::numbers::natural, LIB::mathematics::numbers::natural> list = owners ();
	
	for (auto & mach : machines)
	{
		if (mach.v.found)
		{
			list.enqueue (mach.k);
		}
	}
	
	return list;
}

LIB::machine::resources::memory::research::~research (void) const
{
	lock.unlock ();
}

const bool LIB::machine::resources::memory::research::found (void) const
{
	for (auto & mach : machines)
	{
		if (mach.v.found)
		{
			return true;
		}
	}
	
	return false;
}

const bool LIB::machine::resources::memory::research::responded (void) const
{
	for (auto & mach : machines)
	{
		if (!mach.v.responded)
		{
			return false;
		}
	}
	
	return true;
}

//template <typename Value, Key>
//LIB::Cluster::Memory<Value, Key>::Memory (void)
LIB::machine::resources::memory::memory (void)
{
	//active = false;
	
	t = type::memory;
	//l = location::local;
	
	//mpi_.tcp.Port (2);
	//mpi_.udp.Address ("239.255.1.1");
	//mpi_.udp.Port (30002);
	
	//mpi_.udp.address = "229.255.0.1";
	//mpi_.udp_listen.address = "239.255.1.1";
	//mpi_.udp_broadcast.address = "239.255.1.1";
	//mpi_.udp_listen.address = "0.0.0.0";
	//mpi_.udp_broadcast.address = "";
	
	
	// mpi_.tcp_port (5);
	// mpi_.udp_port (4);
	
	//bool copy = true;
	// delimiter = ";";
	// action_delimiter = "^";
	
	//network_device = 0;	// A local interface is expected to exists.
	
	//timeout = 	
				//100000
	//			1000000
				//100
			;
	//active = true;
	//started = false;
	//active = false;

	//listeners.add (initial_listen);
	//listener_broadcast = new boost::thread (boost::bind (& LIB::machine::resources::memory::initial_listen, this));
//	/*boost::thread * */listener = new boost::thread (boost::bind (& LIB::machine::resources::memory::initial_listen, this));
	////listener_broadcast = NULL;
	
	//listener_direct = new boost::thread (boost::bind (& LIB::machine::resources::memory::initial_receive, this));
//	/*boost::thread * */receiver = new boost::thread (boost::bind (& LIB::machine::resources::memory::initial_receive, this));
	//listener_direct = NULL;
	
	// mpi_.receive_async (& /*LIB::machine::resources::memory::*/act_direct);
	// mpi_.listen_async (& /*LIB::machine::resources::memory::*/act_broadcast);
	
	//listener -> detach ();
	//receiver -> detach ();
	
	//timer = new boost::asio::deadline_timer (io);
	
	//listener_broadcast = NULL;
	//listener_direct = NULL;

	//timer = NULL;

	//#pragma omp parallel num_threads (3)
	//{
	//	switch (omp_get_thread_num ())
	//	{
	//	// The main thread (#0) should return from the function.
	//	case 1:
	//		while (true)
	//		{
	//			ActDirect (mpi_.Receive ());
	//			std::cout << "Receiving..." << std::endl;
	//		}
	//		break;
	//	case 2:
	//		while (true)
	//		{
	//			ActBroadcast (mpi_.Listen ());
	//		}
	//	}
	//}
}

LIB::machine::resources::memory::~memory (void)
{
	//active = false;

	// mpi_.~interface ();
/*	
	if (receiver != NULL)
	{
		try
		{
			receiver -> interrupt ();
		}
		catch (...)
		{
		}
	}
*/	
/*	
	std::string ip = LIB::network::ip::addresses () [network_device].to_string ();

	mpi_.transmit (delimiter + ip + action_delimiter + std::to_string ((mathematics::numbers::natural) LIB::machine::resources::memory::action::EXISTS) + delimiter + (std::string) "0_0" + delimiter, ip);
	
	// mpi_.broadcast ();

	mpi_.cancel ();
*/
	//listener_broadcast -> join ();
	//listener_direct -> join ();

	//delete listener_broadcast, listener_direct, timer;
	/*
	if (listener_broadcast != NULL)
	{
		listener_broadcast -> join ();
		delete listener_broadcast;
		listener_broadcast = NULL;
	}

	if (listener_direct != NULL)
	{
		listener_direct -> join ();
		delete listener_direct;
		listener_direct = NULL;
	}
	*/
	
	/*
	if (timer != NULL)
	{
		delete timer;
		timer = NULL;
	}
	*/
	//members.~Members ();
	
	//mpi_.receive_async_stop (boost::bind (boost::mem_fn (& LIB::machine::resources::memory::act_direct), this, _1));
	//mpi_.listen_async_stop (boost::bind (boost::mem_fn (& LIB::machine::resources::memory::act_direct), this, _1));
	run (false);
}

const bool LIB::machine::resources::memory::run (const bool & state)
{
	if (state && !_active)
	{
		//mpi_.receive_async (& LIB::machine::resources::memory::act_direct);
		// mpi_.receive_async (boost::bind (boost::mem_fn (& LIB::machine::resources::memory::act_direct), this, _1));
		//mpi_.receive_async (boost::bind (boost::mem_fn (& LIB::machine::resources::memory::act_direct), this, _1));
		//mpi_.listen_async (& LIB::machine::resources::memory::act_broadcast);
		// mpi_.listen_async (boost::bind (boost::mem_fn (& LIB::machine::resources::memory::act_broadcast), this, _1));
		//mpi_.listen_async (boost::bind (boost::mem_fn (& LIB::machine::resources::memory::act_broadcast), this, _1));
		
		_active = state;
	}
	else if (!state && _active)
	{
		//mpi_.receive_async (& LIB::machine::resources::memory::act_direct);
		// mpi_.receive_async (boost::bind (boost::mem_fn (& LIB::machine::resources::memory::act_direct), this, _1));
		//mpi_.receive_async (boost::bind (boost::mem_fn (& LIB::machine::resources::memory::act_direct), this, _1));
		//mpi_.listen_async (& LIB::machine::resources::memory::act_broadcast);
		// mpi_.listen_async (boost::bind (boost::mem_fn (& LIB::machine::resources::memory::act_broadcast), this, _1));
		//mpi_.listen_async (boost::bind (boost::mem_fn (& LIB::machine::resources::memory::act_broadcast), this, _1));
		
		_active = state;
	}
	else
	{
		return true;
	}
	
	return false;
}

//template <typename Value, Key>
//Value LIB::Cluster::Memory<Value, Key>::operator [] (const Key)
//{
//	if (memory.Exists (Key))
//	{
//		return memory [Key];
//	}
//	else
//	{
//		// Request it from the members, if they may have it.
//		return Search (Key);
//	}
//}

//void LIB::machine::resources::memory::initial_listen (void)
//{
//	//while (active)
//	//{
//		/// std::cout << "Memory.cpp: \'initial_listen\': Listening..." << std::endl;
//		//std::cout << "Listening..." << std::endl;
//		//std::cout << "Listening: " << mpi_.Listen () << std::endl;
//		act_broadcast (mpi_.listen ());
//	//}
//}
//
//void LIB::machine::resources::memory::initial_receive (void)
//{
//	//while (active)
//	//{
//		///std::cout << "Memory.cpp: \'initial_receive\': Receiving..." << std::endl;
//		//std::cout << "Receiving: " << mpi_.Receive () << std::endl;
//		//boost::this_thread::interruption_point ();
//		act_direct (mpi_.receive ());
//	//}
//}
//
//void LIB::machine::resources::memory::dummy (void)
//{
//	// Do not do anything.
//	/// std::cout << "Dummy (Memory.search ()): Done waiting." << std::endl;
//}

//template <typename Value, Key>
//bool LIB::Cluster::Memory<Value, Key>::Search (const Key key, Value & value, std::string & host) const
const bool LIB::machine::resources::memory::search (const key & k, LIB::cluster::machine & machine/*, const key & group*/) const
{
	//std::string msg;
	//key k;
	LIB::communication::message message_demand, message_obtain, message_obtained;
	
	//k.name = name;
	//k.group = group;
	
	//message_demand.content ["id"] = ;
	
	message_demand.content ["action"] = "memory:presence";
	//message_demand.content ["function"] = "exist";
	message_demand.content ["function"] = "demand";
	
	message_demand.content ["entity"] ["name"] = k.name;
	message_demand.content ["entity"] ["group"] = k.group;
	
	//message_demand.content ["function"] = "exist";
	
	if (variables.exist (k))
	{
		//host = get_local_address ();	//LIB::network::ip::addresses () [network_device].to_string ();
		// host = _local_address;	//LIB::network::ip::addresses () [network_device].to_string ();
		//host = "localhost";
		// _value = variables [_key];
		
		machine = machines -> local_machine ();
		//machine = machines [machines -> local ()];
		//_value = variables [k];
		
		//machines -> broadcast ();
		/// std::cout << "Memory.search (): Found Locally: Key=[" << _key << "] Value=[" << _value << "]" << std::endl;
		
		return true;
	}
	else if (machines -> size () <= 1)
	{
		return false;
	}
	//else if (! members.Empty ())
	//{
	//	bool found;
	//	LIB::NAME_V answer, answer2;
	//	std::string response;

	//	// Ask if anyone has a variable by this key.
	//	if (mpi_.Broadcast (delimiter + mpi_.Localhost () + actionDelimiter + std::to_string ((Mathematics::Number::Natural) Action::ASK) + delimiter + key + delimiter))
	//	{
	//		response = mpi_.Listen ();

	//		if (response.empty ())
	//			return false;
	//	}
	//	else
	//		return false;

	//	answer = Parse (response, Content::DATA);
	//	host = Parse (response, Content::ADDRESS);
	//	found = answer.ToNumber ();

	//	if (found)
	//	{
	//		//value = Get (key);
	//		mpi_.tcp.address = host;
	//		mpi_.Send (delimiter + mpi_.Localhost () + actionDelimiter + std::to_string ((Mathematics::Number::Natural) Action::GET) + delimiter + key + delimiter);
	//		answer2 = mpi_.Receive ();
	//		value = Parse (answer2.ToString (), Content::DATA);
	//	}

	//	return found;
	////}
	////else
	////{
	////	return false;
	//}
	//
	//return false;
	//else if (peers.Empty ())
	//{
	//	return false;
	//}
	
	// Ask if anyone has a variable by this key.
	//else if (mpi_.broadcast (delimiter + (LIB::network::ip::addresses () [network_device].to_string ()) + action_delimiter + std::to_string ((mathematics::numbers::natural) action::EXISTS) + delimiter + _key + delimiter))
	// else if (mpi_.broadcast (delimiter + _local_address + action_delimiter + std::to_string ((unsigned short int) action::EXISTS) + delimiter + _key + delimiter))
	else
	{
		bool _found;
		//std::string response;
		
		//response = mpi_.Listen ();
		//response = mpi_.Receive ();
		
		// Temporary access ID.
		LIB::mathematics::numbers::natural id;
		research rsearch;	// eLeMeNt
		
		if (searches.enqeue (rsearch, id))
		{
			return false;
		}
		
		message_demand.content ["search"] ["id"] = id;
		
		searches [id].lock.lock ();
		
		if (cluster -> transmit (message_demand))
		{
			/// std::cout << "Memory.search (): Not Found Locally: Key=[" << _key << "]" << std::endl;
			/// std::cout << "\t" << "Searching amongst peers..." << std::endl;
			
			// This is when peers should respond.
			
			// Wait for response.
			searches [id].lock.lock ();
			
			// The lock is not needed anymore.
			//searches [id].lock.unlock ();
			
			_found = searches [id].found ();
			
			if (_found)
			{
				LIB::cluster::machine mach;
				
				mach = searches [id].owner ();
				
				//mach.run (true);
				
				message_obtained = cluster -> communicate (message_obtain, mach);
				//_value = message_obtained.content ["value"];
				machine = message_obtained.content ["meta"] ["machine_source"];
				////value = Get (key);
				////mpi_.tcp.address = host;
				//mpi_.Send (delimiter + mpi_.Localhost () + actionDelimiter + std::to_string ((Mathematics::Number::Natural) Action::GET) + delimiter + key + delimiter, host);
				////answer2 = mpi_.Receive ();
				
				//io.reset ();
				
				//timer -> expires_from_now (boost::posix_time::seconds (timeout));
				//timer -> async_wait (boost::bind (& LIB::Cluster::Memory::Dummy, this));
				
				//io.run ();
				
				//value = Parse (data.ToString (), Content::DATA);
				// _value = searches [id].data;
				//machine = ;
				//data = "";
				//searches.unset (id);
			}
			
			//searches.found.unset (id);
			
			//searches.locks [id].unlock ();
			searches.unset (id);
			
			return _found;
		}
		else
		{
			return false;
		}
	}
	//else
	//{
	//	return false;
	//}
}

//template <typename Value, Key>
//bool LIB::Cluster::Memory<Value, Key>::Search (const Key key, Value & value) const
/*bool LIB::machine::resources::memory::search (const key _key, value & _value)
{
	std::string host;

	return search (_key, _value, host);
}
*/

//template <typename Value, Key>
//bool LIB::Cluster::Memory<Value, Key>::Search (const Key key) const
const bool LIB::machine::resources::memory::exist (const key & k) const
{
	//value _value;
	//std::string host;
	LIB::cluster::machine mach;
	
	//return search (name, _value, group);
	return search (k, mach);
}

//template <typename Value, Key>
//Value LIB::Cluster::Memory<Value, Key>::Get (const Key key) const
const value LIB::machine::resources::memory::get (const key & k) const
{
/*
	if (variables.exists (_key))
	{
		return variables [_key];
	}
	else
	{
*/
		/// std::cout << "Trying to get value of key " << "[" << _key << "] ..." << std::endl;
		value _value = "";
		LIB::cluster::machine mach;
//		// Request it from the members, returning it if they may have it.
		if (search (name, mach, group))
		{
			LIB::communication::message message_obtain, message_obtained;
			
			message_obtain.content ["action"] = "memory:variable";
			message_obtain.content ["function"] = "demand";
			message_obtain.content ["value"] ["name"] = name;
			message_obtain.content ["value"] ["group"] = group;
			
			message_obtained = cluster -> communicate (message_obtain, mach);
			
			_value = message_obtained.content ["value"];
		}
		
		return _value;
		
		//if (search (_key, _value))
		//{
		//	return _value;
		//}
		//else
		//{
		//	value temp;

		//	return temp;
		//}
//	}
}

//template <typename Value, Key>
//void LIB::Cluster::Memory<Value, Key>::Set (const Key key, const Value value)
const bool LIB::machine::resources::memory::set (const key & name, const value & _value, const key & group)
{
	if (!run ())
	{
		return false;
	}
	
	keys k;
	machine mach;
	//LIB::communication::message message_demand, message_obtain, message_obtained;
	
	k.name = name;
	k.group = group;
	
	search (name, mach, group);
	
	if (!mach.active ())
	{
		return false;
	}
	
	if (mach.l == location::local)
	{
		variables [k] = _value;
		
		return true;
	}
	else
	{
		//mach.rsrc ["memory"] -> set (name, _value, group);
		LIB::communication::message message_demand, message_response;
		
		message_demand.content ["action"] = "memory";
		message_demand.content ["function"] = "set";
		
		message_demand.content ["key"] ["name"] = name;
		message_demand.content ["key"] ["group"] = group;
		message_demand.content ["value"] = _value;
		
		message_response = cluster -> communicate (message_demand, mach);
		
		return message_response.content.exist ("value") && message_response.content ["value"];
	}
	
	return false;
	
//	// send the value to the member(s) having the variable
//	
//	/// std::cout << "Trying to set value of key " << "[" << _key << "]" << " to value [" << _value << "] ..." << std::endl;
//	
//	//std::string local_address = LIB::network::ip::addresses () [network_device].to_string ();
//	//std::string host;
//	value val;
//	
//	if (search (_key, val, host) && host != _local_address)
//	{
//		/// std::cout << "\t" << "Host " << host << "] has key [" << _key << "]" << " with value [" << val << "]" << std::endl;
//		/// std::cout << "\t" << "Trying to set it to [" << _value << "] ..." << std::endl;
//		//mpi_.tcp.address = host;
//		// if (mpi_.transmit (delimiter + _local_address + delimiter + std::to_string ((mathematics::numbers::natural) action::SET) + delimiter + _key + delimiter + _value + delimiter, (LIB::entity <>) host))
//		if (mpi_.transmit (delimiter + _local_address + delimiter + std::to_string ((unsigned short int) action::SET) + delimiter + _key + delimiter + _value + delimiter, (LIB::entity <>) host))
//		{
//			/// std::cout << "\t" << "Succeeded." << std::endl;
//			
//			return true;
//		}
//		else
//		{
//			/// std::cout << "\t" << "Failed." << std::endl;
//			
//			return false;
//		}
//	}
//	else
//	{
//		/// std::cout << "Not found Remotely ... Setting (locally) key " << "[" << _key << "]" << " to value [" << _value << "] ..." << std::endl;
//		
//		// Distribute to other peers?
//		variables [_key] = _value;
//
//		return variables [_key] == _value;
//	}
}

const bool LIB::machine::resources::memory::unset (const key & k)
{
	if (!run ())
	{
		return false;
	}
	
	keys k;
	machine mach;
	
	k.name = name;
	k.group = group;
	
	search (name, mach, group);
	
	if (!mach.active ())
	{
		return false;
	}
	
	if (mach.l == location::local)
	{
		return variables.unset (k);
	}
	else
	{
		LIB::communication::message message_demand, message_response;
		
		message_demand.content ["action"] = "memory";
		message_demand.content ["function"] = "unset";
		
		message_demand.content ["key"] ["name"] = name;
		message_demand.content ["key"] ["group"] = group;
		
		message_response = cluster -> communicate (message_demand, mach);
		
		return message_response.content.exist ("value") && message_response.content ["value"];
	}
	
	return false;
}

const bool LIB::machine::resources::memory::rename (const key & old_key, const key & new_key)
{
	if (!run ())
	{
		return false;
	}
	
	keys k_new, k_old;
	machine mach;
	
	k_old.name = old_name;
	k_old.group = old_group;
	
	search (old_name, mach, old_group);
	
	if (!mach.active ())
	{
		return false;
	}
	
	if (mach.l == location::local)
	{
		return variables.rename (k_old, k_new);
	}
	else
	{
		LIB::communication::message message_demand, message_response;
		
		message_demand.content ["action"] = "memory";
		message_demand.content ["function"] = "move";
		
		message_demand.content ["key"] ["old"] ["name"] = old_name;
		message_demand.content ["key"] ["old"] ["group"] = old_group;
		
		message_demand.content ["key"] ["new"] ["name"] = new_name;
		message_demand.content ["key"] ["new"] ["group"] = new_group;
		
		message_response = cluster -> communicate (message_demand, mach);
		
		return message_response.content.exist ("value") && message_response.content ["value"];
	}
	
	return false;
}

////template <typename Value, Key>
////std::string LIB::Cluster::Memory<Value, Key>::Parse (const std::string input, const Content content, Mathematics::Number::Natural requestedDataIndex) const
//std::string LIB::machine::resources::memory::parse (std::string input, const content _content, const unsigned short int & requested_data_index)
//{
//	if (input.empty ())
//		return input;
//	else if (input [0] != delimiter [0])
//		return "";
//
//	std::string ip = "", action = "";
//	unsigned int i = 1;
//	unsigned int data_index = 0;
//	NAME_A <std::string, mathematics::numbers::natural> data;
//	NAME_V temp;
//	std::string data_temp;
//
//	// Determine where the IP address ends in the string.
//	while (i < input.length () && input [i] != delimiter [0] && input [i] != action_delimiter [0])
//	{
//		// Store the IP address in our local variable
//		ip += input [i];
//		++ i;
//	}
//
//	// Skip the DELIMITER or the ACTION_DELIMITER character.
//	++ i;
//	
//	// Handle the IP address
//	//cout << "Capacity: " << nodes.capacity () << endl;
//	if ((NAME_V) input [i - 1] == action_delimiter)
//	{
//		// Determine the ACTION:
//		while (i < input.length () && input [i] != delimiter [0])
//		{
//			// Store the action in our local variable.
//			action += input [i];
//			++ i;
//		}
//	}
//
//	// Skip the DELIMITER character.
//	++ i;
//	
//	while (i < input.length ())
//	{
//		data [data_index] = "";
//		//data_temp = "";
//
//		while (input [i] != delimiter [0])
//		//while (i < input.length () && input [i] != delimiter)
//		{
//			//temp = input [i];
//			//data [data_index];
//
//			//data [data_index] += (LIB::NAME_V) (input [i]);
//			//data [data_index] += temp;
//			//data [data_index] = data [data_index] + (LIB::NAME_V) (input [i]);
//			//data [data_index] = data [data_index] + temp;
//			//data += input [i];
//			data [data_index] += input [i];
//			//data_temp += input [i];
//			
//			++ i;
//		}
//
//		//data [data_index] = data_temp;
//
//		// Proceed to the next data part of the message:
//		++ data_index;
//
//		// Skip the DELIMITER character:
//		++ i;
//	}
//
//	//NAME_V t;
//
//	switch (_content)
//	{
//		case content::ACTION:
//			return action;
//		case content::ADDRESS:
//			return ip;
//		case content::DATA:
//			//std::cout << data [requested_data_index];
//			//data_temp = (data [requested_data_index]);
//			//data_temp = "blah";
//
//			//return data_temp;
//			return data [requested_data_index];
//			//return /*(std::string) */(data [requested_data_index]);
//		default:
//			return "";
//	}
//}
//
////template <typename Value, Key>
////void LIB::Cluster::Memory<Value, Key>::ActDirect (const std::string input)
//void LIB::machine::resources::memory::act_direct (const std::string input)
//{
//	/// std::cout << "memory.cpp: act_direct" << std::endl;
//
//	//if (active)
//	//	/*boost::thread * */receiver = new boost::thread (boost::bind (& LIB::machine::resources::memory::initial_receive, this));
//	
//	if (input.empty ())
//	{
//		/// std::cout << "\t" << "\'input\' is empty ()." << std::endl;
//		return;
//	}
//	
//	std::string host, action_string, data_local, value;
//	action _action;
//	
//	try
//	{
//		host = parse (input, content::ADDRESS);
//		action_string = parse (input, content::ACTION);
//		data_local = parse (input, content::DATA);
//		
//		_action = (action) atoi (action_string.c_str ());
//
//		/// std::cout << "\t" << "host [" << host << "]" << std::endl;
//		/// std::cout << "\t" << "action_string [" << action_string << "]" << std::endl;
//		/// std::cout << "\t" << "data_local [" << data_local << "]" << std::endl;
//		
//		switch (_action)
//		{
//			case action::SET:
//				/// std::cout << "\t\t" << "action::SET" << std::endl;
//				
//				value = parse (input, content::DATA, 1);
//				variables [data_local] = value;
//				
//				/// std::cout << "\t\t" << "data_local [" << data_local << "]" << std::endl;
//				/// std::cout << "\t\t" << "value [" << value << "]" << std::endl;
//				
//				break;
//			case action::GET:	// The remote host asked us for the data's value.
//				/// std::cout << "\t\t" << "action::GET" << std::endl;
//				if (variables.exist (data_local))	// We must have the data in order to reply with its value.
//				{
//					/// std::cout << "\t\t\t" << "Found." << std::endl;
//					/// std::cout << "\t\t\t" << "Transmitting..." << std::endl;
//					//mpi_.tcp.address = host;
//					if (mpi_.transmit (delimiter + _local_address + delimiter + variables [data_local] + delimiter, (LIB::entity <>) host))
//					{
//						/// std::cout << "\t\t\t" << "Succeeded." << std::endl;
//					}
//					else
//					{
//						/// std::cout << "\t\t\t" << "Failed." << std::endl;
//					}
//				}
//				else
//				{
//					/// std::cout << "\t\t\t" << "Not found." << std::endl;
//				}
//
//				break;
//			case action::UNSET:
//				variables.unset (data_local);
//
//				break;
//			case action::RENAME:
//				value = parse (input, content::DATA, 1);
//
//				if (!data_local.empty () && !value.empty ())
//					variables.rename (data_local, value);
//
//				break;
//			case action::ANSWER:
//				/// std::cout << "\t\t" << "Answering/Answered..." << std::endl;
//				value = parse (input, content::DATA, 1);
//				
//				/// std::cout << "\t\t" << "data_local [" << data_local << "]" << std::endl;
//				/// std::cout << "\t\t" << "value [" << value << "]" << std::endl;
//			//	if (!found && dataLocal == "1")
//					found [value] = true;
//
//			//	io.stop ();
//			//	break;
//			//case Action::GOT:	// I have just received some data.
//				data [value] = data_local;
//				
//				try
//				{
//					if (timers.exist (value))
//					{
//						delete timers [value];
//					}
//				}
//				catch (...)
//				{
//				}
//				
//				timers.unset (value);
//				
//				try
//				{
//					if (io_services.exist (value))
//					{
//						delete io_services [value];
//					}
//				}
//				catch (...)
//				{
//				}
//				
//				//io_services [value] -> stop ();
//				io_services.unset (value);
//		}
//
//		//switch (atoi (action.c_str ()))
//		//{
//		////case Action::ASK:
//		////	if (memory.Exists (data))
//		////	{
//		////		mpi_.tcp (host);
//		////		mpi_.Send (delimiter + mpi_.LocalHost () + delimiter + "1" + delimiter);
//		////	}
//
//		////	break;
//		//case Action::SET:
//		//	std::string value = Parse (input, Content::DATA, 1);
//		//	memory [data] = value;
//
//		//	break;
//		//case Action::GET:
//		//	if (memory.Exists (data))
//		//	{
//		//		mpi_.tcp (host);
//		//		mpi_.Send (delimiter + mpi_.LocalHost () + delimiter + memory [data] + delimiter);
//		//	}
//		//}
//	}
//	catch (...)
//	{
//
//	}
//}
//
////template <typename Value, Key>
////void LIB::Cluster::Memory<Value, Key>::ActBroadcast (const std::string input)
//void LIB::machine::resources::memory::act_broadcast (const std::string input)
//{
//	/// std::cout << "memory.cpp: act_broadcast()" << std::endl;
//	
//	//if (active)
//	//	/*boost::thread * */listener = new boost::thread (boost::bind (& LIB::machine::resources::memory::initial_listen, this));
//	
//	if (input.empty ())
//	{
//		/// std::cout << "\t" << "\'input\' is empty ()." << std::endl;
//		return;
//	}
//	
//	std::string host, action_, data_local;
//	//Content action;
//	
//	try
//	{
//		host = parse (input, content::ADDRESS);
//		action_ = parse (input, content::ACTION);
//		data_local = parse (input, content::DATA);
//		
//		/// std::cout << "\t" << "host [" << host << "]" << std::endl;
//		/// std::cout << "\t" << "action_ [" << action_ << "]" << std::endl;
//		/// std::cout << "\t" << "data_local [" << data_local << "]" << std::endl;
//		
//		switch ((action) std::stoi (action_))
//		{
//			//case Action::ASK:
//			case action::GET:
//				/// std::cout << "\t\t" << "action::GET" << std::endl;
//				if (variables.exist (data_local))
//				{
//					/// std::cout << "\t\t\t" << "Found." << std::endl;
//					/// std::cout << "\t\t\t" << "Transmitting..." << std::endl;
//					//mpi_.tcp.address = host;
//					// mpi_.Send (delimiter + mpi_.LocalHost () + delimiter + "1" + delimiter);	// ?
//					if (mpi_.transmit (delimiter + _local_address + delimiter + variables [data_local] + delimiter, (LIB::entity <>) host))
//					{
//						/// std::cout << "\t\t\t" << "Succeeded." << std::endl;
//					}
//					else
//					{
//						/// std::cout << "\t\t\t" << "Failed." << std::endl;
//					}
//				}
//
//				break;
//			/*
//			case action::SET:
//				std::cout << "\t\t" << "action::SET" << std::endl;
//				
//				value = parse (input, content::DATA, 1);
//				variables [data_local] = value;
//				
//				std::cout << "\t\t" << "data_local [" << data_local << "]" << std::endl;
//				std::cout << "\t\t" << "value [" << value << "]" << std::endl;
//				
//				break;
//			*/
//			//case Action::SET:
//			//	std::string value = Parse (input, Content::DATA, 1);
//			//	memory [data] = value;
//
//			//	break;
//			//case Action::GET:
//			//	if (memory.Exists (data))
//			//	{
//			//		mpi_.tcp (host);
//			//		mpi_.Send (delimiter + mpi_.LocalHost () + delimiter + memory [data] + delimiter);
//			//	}
//			case action::EXISTS:
//				/// std::cout << "\t\t" << "action::EXISTS" << std::endl;
//				if (variables.exist (data_local))
//				{
//					/// std::cout << "\t\t\t" << "Found." << std::endl;
//					/// std::cout << "\t\t\t" << "Transmitting..." << std::endl;
//					if (mpi_.transmit (delimiter + _local_address + action_delimiter + std::to_string ((unsigned short int) action::ANSWER) + delimiter + variables [data_local] + delimiter + data_local + delimiter, (LIB::entity <>) host))
//					//mpi_.Broadcast (delimiter + mpi_.Localhost () + delimiter + "1" + delimiter, host);
//					{
//						/// std::cout << "\t\t\t" << "Succeeded." << std::endl;
//					}
//					else
//					{
//						/// std::cout << "\t\t\t" << "Failed." << std::endl;
//					}
//				}
//				//else
//				//{
//				//	mpi_.Broadcast (delimiter + mpi_.Localhost () + delimiter + "0" + delimiter, host);
//				//}
//
//		}
//	}
//	catch (...)
//	{
//
//	}
//}
/*
LIB::Mathematics::Number::Natural LIB::Cluster::Memory::Size (void) const
{
	return peers.Size ();
}

void LIB::Cluster::Memory::List (void)
{
	//LIB::NAME_A<bool, std::string> list = *(members.List ());

	peers.List ().Reset ();

	for (LIB::Mathematics::Number::Natural index = 0; index < peers.Size (); ++ index)
	{
		std::cout << index + 1 << ". " << peers.List ().operator * () << ": " << peers.List () [peers.List ().operator * ()] << std::endl;
		//members.at (index) = false;
		peers.List ().operator ++ ();
	}
}
*/

//// Getter
//const value & LIB::machine::resources::memory::operator [] (const key & _key) const
//{
//	//return const_cast <value &> (get (_key));
//	return get (_key);
//}
//
//// Setter
//value &	LIB::machine::resources::memory::operator [] (const key & _key)
//{
//	value _val;
//	set (_key, _val);
//
//	return get (_key);
//}

LIB::machine::resources::memory LIB::machine::resources::memory::operator [] (const key & k)
{
	memory mem (cluster);
	
	if (! mem.run ())
	{
		return mem;
	}
	
}

const LIB::machine::resources::memory LIB::machine::resources::memory::operator [] (const key & k) const
{
	
}
