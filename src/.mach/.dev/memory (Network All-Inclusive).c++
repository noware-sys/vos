#include "memory.h++"
#include "../../network/ip.h++"
#include <boost/mem_fn.hpp>
#include <boost/ref.hpp>

//template <typename Value, Key>
//LIB::Cluster::Memory<Value, Key>::Memory (void)
LIB::machine::devices::memory::memory (void)
{
	t = type::memory;
	
	//mpi_.tcp.Port (2);
	//mpi_.udp.Address ("239.255.1.1");
	//mpi_.udp.Port (30002);
	
	mpi_.tcp_port (5);
	
	//mpi_.udp.address = "229.255.0.1";
	//mpi_.udp_listen.address = "239.255.1.1";
	//mpi_.udp_broadcast.address = "239.255.1.1";
	//mpi_.udp_listen.address = "0.0.0.0";
	//mpi_.udp_broadcast.address = "";
	
	mpi_.udp_port (4);
	
	//bool copy = true;
	delimiter = ";";
	action_delimiter = "^";
	
	network_device = 0;	// A local interface is expected to exists.
	
	timeout = 	// In microseconds (1 �s = 0.000 001 s).
				//100000
				1000000
				//100
			;
	//running = true;
	started = false;

	//listeners.add (initial_listen);
	//listener_broadcast = new boost::thread (boost::bind (& LIB::machine::devices::memory::initial_listen, this));
//	/*boost::thread * */listener = new boost::thread (boost::bind (& LIB::machine::devices::memory::initial_listen, this));
	////listener_broadcast = NULL;
	
	//listener_direct = new boost::thread (boost::bind (& LIB::machine::devices::memory::initial_receive, this));
//	/*boost::thread * */receiver = new boost::thread (boost::bind (& LIB::machine::devices::memory::initial_receive, this));
	//listener_direct = NULL;
	
	// mpi_.receive_async (& /*LIB::machine::devices::memory::*/act_direct);
	// mpi_.listen_async (& /*LIB::machine::devices::memory::*/act_broadcast);
	
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

LIB::machine::devices::memory::~memory (void)
{
	//running = false;

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

	mpi_.transmit (delimiter + ip + action_delimiter + std::to_string ((mathematics::numbers::natural) LIB::machine::devices::memory::action::EXISTS) + delimiter + (std::string) "0_0" + delimiter, ip);
	
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
	
	//mpi_.receive_async_stop (boost::bind (boost::mem_fn (& LIB::machine::devices::memory::act_direct), this, _1));
	//mpi_.listen_async_stop (boost::bind (boost::mem_fn (& LIB::machine::devices::memory::act_direct), this, _1));
	stop ();
}

const bool & LIB::machine::devices::memory::start (void)
{
	if (! started)
	{
		//mpi_.receive_async (& LIB::machine::devices::memory::act_direct);
		mpi_.receive_async (boost::bind (boost::mem_fn (& LIB::machine::devices::memory::act_direct), this, _1));
		//mpi_.listen_async (& LIB::machine::devices::memory::act_broadcast);
		mpi_.listen_async (boost::bind (boost::mem_fn (& LIB::machine::devices::memory::act_broadcast), this, _1));
		
		started = true;
	}
	
	return true;
}

const bool & LIB::machine::devices::memory::stop (void)
{
	if (started)
	{
		//mpi_.receive_async (& LIB::machine::devices::memory::act_direct);
		mpi_.receive_async_stop (boost::bind (boost::mem_fn (& LIB::machine::devices::memory::act_direct), this, _1));
		//mpi_.listen_async (& LIB::machine::devices::memory::act_broadcast);
		mpi_.listen_async_stop (boost::bind (boost::mem_fn (& LIB::machine::devices::memory::act_broadcast), this, _1));
		
		started = false;
	}
	
	return true;
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

bool LIB::machine::devices::memory::refresh_local_address (void)
{
	return refresh_local_address (network_device);
}

bool LIB::machine::devices::memory::refresh_local_address (const LIB::mathematics::numbers::natural & device)
{
	LIB::NAME_A <LIB::network::ip::address, LIB::mathematics::numbers::natural> addresses = LIB::network::ip::addresses ();
	
	if (addresses.exists (device))
	{
		_local_address = addresses [device].to_string ();
		
		return true;
	}
	
	return false;
}

std::string LIB::machine::devices::memory::get_local_address (void)
{
	return _local_address;
}

std::string LIB::machine::devices::memory::refresh_and_get_local_address (void)
{
	refresh_local_address ();
	
	return _local_address;
}

std::string LIB::machine::devices::memory::refresh_and_get_local_address (const LIB::mathematics::numbers::natural & device)
{
	refresh_local_address (device);
	
	return _local_address;
}

void LIB::machine::devices::memory::initial_listen (void)
{
	//while (running)
	//{
		/// std::cout << "Memory.cpp: \'initial_listen\': Listening..." << std::endl;
		//std::cout << "Listening..." << std::endl;
		//std::cout << "Listening: " << mpi_.Listen () << std::endl;
		act_broadcast (mpi_.listen ());
	//}
}

void LIB::machine::devices::memory::initial_receive (void)
{
	//while (running)
	//{
		///std::cout << "Memory.cpp: \'initial_receive\': Receiving..." << std::endl;
		//std::cout << "Receiving: " << mpi_.Receive () << std::endl;
		//boost::this_thread::interruption_point ();
		act_direct (mpi_.receive ());
	//}
}

void LIB::machine::devices::memory::dummy (void)
{
	// Do not do anything.
	/// std::cout << "Dummy (Memory.search ()): Done waiting." << std::endl;
}

//template <typename Value, Key>
//bool LIB::Cluster::Memory<Value, Key>::Search (const Key key, Value & value, std::string & host) const
bool LIB::machine::devices::memory::search (const key _key, value & _value, std::string & host)
{
	//std::string msg;
	
	if (variables.exists (_key))
	{
		//host = get_local_address ();	//LIB::network::ip::addresses () [network_device].to_string ();
		host = _local_address;	//LIB::network::ip::addresses () [network_device].to_string ();
		//host = "localhost";
		_value = variables [_key];

		/// std::cout << "Memory.search (): Found Locally: Key=[" << _key << "] Value=[" << _value << "]" << std::endl;
		
		return true;
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
	else if (mpi_.broadcast (delimiter + _local_address + action_delimiter + std::to_string ((mathematics::numbers::natural) action::EXISTS) + delimiter + _key + delimiter))
	{
		/// std::cout << "Memory.search (): Not Found Locally: Key=[" << _key << "]" << std::endl;
		/// std::cout << "\t" << "Searching amongst peers..." << std::endl;
		
		bool _found;
		//std::string response;
		
		//response = mpi_.Listen ();
		//response = mpi_.Receive ();
		
		found [_key] = false;
		
		io_services [_key] = new boost::asio::io_service ();
		io_services [_key] -> reset ();
		timers [_key] = new boost::asio::deadline_timer (* (io_services [_key]));
		
		timers [_key] -> expires_from_now (boost::posix_time::microseconds (timeout));
		timers [_key] -> async_wait (boost::bind (& LIB::machine::devices::memory::dummy, this));
		
		try
		{
			io_services [_key] -> run ();
		}
		catch (...)
		{
		}
		//if (response.empty ())
		//	return false;

		//bool found;
		//LIB::NAME_V answer, answer2;

		//answer = Parse (response, Content::DATA);
		//host = Parse (response, Content::ADDRESS);
		//found = answer.ToNumber ();

		if (found [_key])
		{
			////value = Get (key);
			////mpi_.tcp.address = host;
			//mpi_.Send (delimiter + mpi_.Localhost () + actionDelimiter + std::to_string ((Mathematics::Number::Natural) Action::GET) + delimiter + key + delimiter, host);
			////answer2 = mpi_.Receive ();

			//io.reset ();

			//timer -> expires_from_now (boost::posix_time::seconds (timeout));
			//timer -> async_wait (boost::bind (& LIB::Cluster::Memory::Dummy, this));
			
			//io.run ();

			//value = Parse (data.ToString (), Content::DATA);
			_value = data [_key];
			//data = "";
			data.unset (_key);
		}
		
		_found = found [_key];
		
		found.unset (_key);
		
		try
		{
			if (timers.exists (_key))
			{
				delete timers [_key];
			}
		}
		catch (...)
		{
		}
		
		try
		{
			if (io_services.exists (_key))
			{
				delete io_services [_key];
			}
		}
		catch (...)
		{
		}
		
		timers.unset (_key);
		io_services.unset (_key);
		/// std::cout << "Memory.search (): ";
		/// if (! _found)
			/// std::cout << "Not ";
		/// std::cout << "Found Amongst Peers: Key=[" << _key << "]";
		///if (_found)
			/// std::cout << ": Value=[" << _value << "]";
		/// std::cout << std::endl;
		
		return _found;
	}

	else
	{
		return false;
	}
}

//template <typename Value, Key>
//bool LIB::Cluster::Memory<Value, Key>::Search (const Key key, Value & value) const
bool LIB::machine::devices::memory::search (const key _key, value & _value)
{
	std::string host;

	return search (_key, _value, host);
}

//template <typename Value, Key>
//bool LIB::Cluster::Memory<Value, Key>::Search (const Key key) const
bool LIB::machine::devices::memory::search (const key _key)
{
	value _value;
	std::string host;

	return search (_key, _value, host);
}

//template <typename Value, Key>
//Value LIB::Cluster::Memory<Value, Key>::Get (const Key key) const
LIB::machine::devices::memory::value LIB::machine::devices::memory::get (key _key)
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
		value _value;
		
//		// Request it from the members, if they may have it.
		search (_key, _value);
		
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
bool LIB::machine::devices::memory::set (key _key, value _value)
{
	// send the value to the member(s) having the variable
	
	/// std::cout << "Trying to set value of key " << "[" << _key << "]" << " to value [" << _value << "] ..." << std::endl;
	
	//std::string local_address = LIB::network::ip::addresses () [network_device].to_string ();
	std::string host;
	value val;
	
	if (search (_key, val, host) && host != _local_address)
	{
		/// std::cout << "\t" << "Host " << host << "] has key [" << _key << "]" << " with value [" << val << "]" << std::endl;
		/// std::cout << "\t" << "Trying to set it to [" << _value << "] ..." << std::endl;
		//mpi_.tcp.address = host;
		if (mpi_.transmit (delimiter + _local_address + delimiter + std::to_string ((mathematics::numbers::natural) action::SET) + delimiter + _key + delimiter + _value + delimiter, host))
		{
			/// std::cout << "\t" << "Succeeded." << std::endl;
			
			return true;
		}
		else
		{
			/// std::cout << "\t" << "Failed." << std::endl;
			
			return false;
		}
	}
	else
	{
		/// std::cout << "Not found Remotely ... Setting (locally) key " << "[" << _key << "]" << " to value [" << _value << "] ..." << std::endl;
		
		// Distribute to other peers?
		variables [_key] = _value;

		return variables [_key] == _value;
	}
}

bool LIB::machine::devices::memory::unset (const key & _key)
{
	if (variables.exists (_key))
	{
		return variables.unset (_key);
	}
	else
	{
		//std::string local_address = LIB::network::ip::addresses () [network_device].to_string ();
		std::string host;
		value _value;

		// Request it from the members, if they may have it.
		if (search (_key, _value, host) && host != _local_address)
			return mpi_.transmit (delimiter + _local_address + delimiter + std::to_string ((mathematics::numbers::natural) action::UNSET) + delimiter + _key + delimiter, host);
		else
			return false;
		//if (search (_key, _value))
		//{
		//	return _value;
		//}
		//else
		//{
		//	value temp;

		//	return temp;
		//}
	}
}

bool LIB::machine::devices::memory::rename (const key & current_key, const key & new_key)
{
	if (variables.exists (current_key))
	{
		return variables.rename (current_key, new_key);
	}
	else
	{
		//std::string local_address = LIB::network::ip::addresses () [network_device].to_string ();
		std::string host;
		value _value;
		
		// Request it from the members, if they may have it.
		if (search (current_key, _value, host) && host != _local_address)
			return mpi_.transmit (delimiter + _local_address + delimiter + std::to_string ((mathematics::numbers::natural) action::RENAME) + delimiter + current_key + delimiter + new_key + delimiter, host);
		else
			return false;
		//if (search (_key, _value))
		//{
		//	return _value;
		//}
		//else
		//{
		//	value temp;

		//	return temp;
		//}
	}
}

//template <typename Value, Key>
//std::string LIB::Cluster::Memory<Value, Key>::Parse (const std::string input, const Content content, Mathematics::Number::Natural requestedDataIndex) const
std::string LIB::machine::devices::memory::parse (std::string input, const content _content, const mathematics::numbers::natural requested_data_index)
{
	if (input.empty ())
		return input;
	else if (input [0] != delimiter [0])
		return "";

	std::string ip = "", action = "";
	mathematics::numbers::natural i = 1;
	mathematics::numbers::natural data_index = 0;
	NAME_A <std::string, mathematics::numbers::natural> data;
	NAME_V temp;
	std::string data_temp;

	// Determine where the IP address ends in the string.
	while (i < input.length () && input [i] != delimiter [0] && input [i] != action_delimiter [0])
	{
		// Store the IP address in our local variable
		ip += input [i];
		++ i;
	}

	// Skip the DELIMITER or the ACTION_DELIMITER character.
	++ i;
	
	// Handle the IP address
	//cout << "Capacity: " << nodes.capacity () << endl;
	if ((NAME_V) input [i - 1] == action_delimiter)
	{
		// Determine the ACTION:
		while (i < input.length () && input [i] != delimiter [0])
		{
			// Store the action in our local variable.
			action += input [i];
			++ i;
		}
	}

	// Skip the DELIMITER character.
	++ i;
	
	while (i < input.length ())
	{
		data [data_index] = "";
		//data_temp = "";

		while (input [i] != delimiter [0])
		//while (i < input.length () && input [i] != delimiter)
		{
			//temp = input [i];
			//data [data_index];

			//data [data_index] += (LIB::NAME_V) (input [i]);
			//data [data_index] += temp;
			//data [data_index] = data [data_index] + (LIB::NAME_V) (input [i]);
			//data [data_index] = data [data_index] + temp;
			//data += input [i];
			data [data_index] += input [i];
			//data_temp += input [i];
			
			++ i;
		}

		//data [data_index] = data_temp;

		// Proceed to the next data part of the message:
		++ data_index;

		// Skip the DELIMITER character:
		++ i;
	}

	//NAME_V t;

	switch (_content)
	{
		case content::ACTION:
			return action;
		case content::ADDRESS:
			return ip;
		case content::DATA:
			//std::cout << data [requested_data_index];
			//data_temp = (data [requested_data_index]);
			//data_temp = "blah";

			//return data_temp;
			return data [requested_data_index];
			//return /*(std::string) */(data [requested_data_index]);
		default:
			return "";
	}
}

//template <typename Value, Key>
//void LIB::Cluster::Memory<Value, Key>::ActDirect (const std::string input)
void LIB::machine::devices::memory::act_direct (const std::string input)
{
	/// std::cout << "memory.cpp: act_direct" << std::endl;

	//if (running)
	//	/*boost::thread * */receiver = new boost::thread (boost::bind (& LIB::machine::devices::memory::initial_receive, this));
	
	if (input.empty ())
	{
		/// std::cout << "\t" << "\'input\' is empty ()." << std::endl;
		return;
	}
	
	std::string host, action_string, data_local, value;
	action _action;
	
	try
	{
		host = parse (input, content::ADDRESS);
		action_string = parse (input, content::ACTION);
		data_local = parse (input, content::DATA);
		
		_action = (action) atoi (action_string.c_str ());

		/// std::cout << "\t" << "host [" << host << "]" << std::endl;
		/// std::cout << "\t" << "action_string [" << action_string << "]" << std::endl;
		/// std::cout << "\t" << "data_local [" << data_local << "]" << std::endl;
		
		switch (_action)
		{
			case action::SET:
				/// std::cout << "\t\t" << "action::SET" << std::endl;
				
				value = parse (input, content::DATA, 1);
				variables [data_local] = value;
				
				/// std::cout << "\t\t" << "data_local [" << data_local << "]" << std::endl;
				/// std::cout << "\t\t" << "value [" << value << "]" << std::endl;
				
				break;
			case action::GET:	// The remote host asked us for the data's value.
				/// std::cout << "\t\t" << "action::GET" << std::endl;
				if (variables.exists (data_local))	// We must have the data in order to reply with its value.
				{
					/// std::cout << "\t\t\t" << "Found." << std::endl;
					/// std::cout << "\t\t\t" << "Transmitting..." << std::endl;
					//mpi_.tcp.address = host;
					if (mpi_.transmit (delimiter + _local_address + delimiter + variables [data_local] + delimiter, host))
					{
						/// std::cout << "\t\t\t" << "Succeeded." << std::endl;
					}
					else
					{
						/// std::cout << "\t\t\t" << "Failed." << std::endl;
					}
				}
				else
				{
					/// std::cout << "\t\t\t" << "Not found." << std::endl;
				}

				break;
			case action::UNSET:
				variables.unset (data_local);

				break;
			case action::RENAME:
				value = parse (input, content::DATA, 1);

				if (!data_local.empty () && !value.empty ())
					variables.rename (data_local, value);

				break;
			case action::ANSWER:
				/// std::cout << "\t\t" << "Answering/Answered..." << std::endl;
				value = parse (input, content::DATA, 1);
				
				/// std::cout << "\t\t" << "data_local [" << data_local << "]" << std::endl;
				/// std::cout << "\t\t" << "value [" << value << "]" << std::endl;
			//	if (!found && dataLocal == "1")
					found [value] = true;

			//	io.stop ();
			//	break;
			//case Action::GOT:	// I have just received some data.
				data [value] = data_local;
				
				try
				{
					if (timers.exists (value))
					{
						delete timers [value];
					}
				}
				catch (...)
				{
				}
				
				timers.unset (value);
				
				try
				{
					if (io_services.exists (value))
					{
						delete io_services [value];
					}
				}
				catch (...)
				{
				}
				
				//io_services [value] -> stop ();
				io_services.unset (value);
		}

		//switch (atoi (action.c_str ()))
		//{
		////case Action::ASK:
		////	if (memory.Exists (data))
		////	{
		////		mpi_.tcp (host);
		////		mpi_.Send (delimiter + mpi_.LocalHost () + delimiter + "1" + delimiter);
		////	}

		////	break;
		//case Action::SET:
		//	std::string value = Parse (input, Content::DATA, 1);
		//	memory [data] = value;

		//	break;
		//case Action::GET:
		//	if (memory.Exists (data))
		//	{
		//		mpi_.tcp (host);
		//		mpi_.Send (delimiter + mpi_.LocalHost () + delimiter + memory [data] + delimiter);
		//	}
		//}
	}
	catch (...)
	{

	}
}

//template <typename Value, Key>
//void LIB::Cluster::Memory<Value, Key>::ActBroadcast (const std::string input)
void LIB::machine::devices::memory::act_broadcast (const std::string input)
{
	/// std::cout << "memory.cpp: act_broadcast()" << std::endl;
	
	//if (running)
	//	/*boost::thread * */listener = new boost::thread (boost::bind (& LIB::machine::devices::memory::initial_listen, this));
	
	if (input.empty ())
	{
		/// std::cout << "\t" << "\'input\' is empty ()." << std::endl;
		return;
	}
	
	std::string host, action_, data_local;
	//Content action;
	
	try
	{
		host = parse (input, content::ADDRESS);
		action_ = parse (input, content::ACTION);
		data_local = parse (input, content::DATA);
		
		/// std::cout << "\t" << "host [" << host << "]" << std::endl;
		/// std::cout << "\t" << "action_ [" << action_ << "]" << std::endl;
		/// std::cout << "\t" << "data_local [" << data_local << "]" << std::endl;
		
		switch ((action) std::stoi (action_))
		{
			//case Action::ASK:
			case action::GET:
				/// std::cout << "\t\t" << "action::GET" << std::endl;
				if (variables.exists (data_local))
				{
					/// std::cout << "\t\t\t" << "Found." << std::endl;
					/// std::cout << "\t\t\t" << "Transmitting..." << std::endl;
					//mpi_.tcp.address = host;
					// mpi_.Send (delimiter + mpi_.LocalHost () + delimiter + "1" + delimiter);	// ?
					if (mpi_.transmit (delimiter + _local_address + delimiter + variables [data_local] + delimiter, host))
					{
						/// std::cout << "\t\t\t" << "Succeeded." << std::endl;
					}
					else
					{
						/// std::cout << "\t\t\t" << "Failed." << std::endl;
					}
				}

				break;
			/*
			case action::SET:
				std::cout << "\t\t" << "action::SET" << std::endl;
				
				value = parse (input, content::DATA, 1);
				variables [data_local] = value;
				
				std::cout << "\t\t" << "data_local [" << data_local << "]" << std::endl;
				std::cout << "\t\t" << "value [" << value << "]" << std::endl;
				
				break;
			*/
			//case Action::SET:
			//	std::string value = Parse (input, Content::DATA, 1);
			//	memory [data] = value;

			//	break;
			//case Action::GET:
			//	if (memory.Exists (data))
			//	{
			//		mpi_.tcp (host);
			//		mpi_.Send (delimiter + mpi_.LocalHost () + delimiter + memory [data] + delimiter);
			//	}
			case action::EXISTS:
				/// std::cout << "\t\t" << "action::EXISTS" << std::endl;
				if (variables.exists (data_local))
				{
					/// std::cout << "\t\t\t" << "Found." << std::endl;
					/// std::cout << "\t\t\t" << "Transmitting..." << std::endl;
					if (mpi_.transmit (delimiter + _local_address + action_delimiter + std::to_string ((mathematics::numbers::natural) action::ANSWER) + delimiter + variables [data_local] + delimiter + data_local + delimiter, host))
					//mpi_.Broadcast (delimiter + mpi_.Localhost () + delimiter + "1" + delimiter, host);
					{
						/// std::cout << "\t\t\t" << "Succeeded." << std::endl;
					}
					else
					{
						/// std::cout << "\t\t\t" << "Failed." << std::endl;
					}
				}
				//else
				//{
				//	mpi_.Broadcast (delimiter + mpi_.Localhost () + delimiter + "0" + delimiter, host);
				//}

		}
	}
	catch (...)
	{

	}
}
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
//const value & LIB::machine::devices::memory::operator [] (const key & _key) const
//{
//	//return const_cast <value &> (get (_key));
//	return get (_key);
//}
//
//// Setter
//value &	LIB::machine::devices::memory::operator [] (const key & _key)
//{
//	value _val;
//	set (_key, _val);
//
//	return get (_key);
//}
