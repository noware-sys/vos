#include "memory.hpp"
#include "../network/ip.hpp"

//template <typename Value, Key>
//LIB::Cluster::Memory<Value, Key>::Memory (void)
LIB::cluster::memory::memory (void)
{
	//mpi.tcp.Port (2);
	//mpi.udp.Address ("239.255.1.1");
	//mpi.udp.Port (30002);

	mpi.tcp.port = 7;

	mpi.udp.address = "229.255.0.1";
	mpi.udp.port = 6;

	//bool copy = true;
	delimiter = ";";
	action_delimiter = "^";

	timeout = 50000;	// In microseconds (1 µs = 0.000 001 s).
	running = true;

	listener_broadcast = new boost::thread (boost::bind (& LIB::cluster::memory::initial_listen, this));
	//listener_broadcast = NULL;
	listener_direct = new boost::thread (boost::bind (& LIB::cluster::memory::initial_receive, this));
	//listener_direct = NULL;

	timer = new boost::asio::deadline_timer (io);

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
	//			ActDirect (mpi.Receive ());
	//			std::cout << "Receiving..." << std::endl;
	//		}
	//		break;
	//	case 2:
	//		while (true)
	//		{
	//			ActBroadcast (mpi.Listen ());
	//		}
	//	}
	//}
}

LIB::cluster::memory::~memory (void)
{
	running = false;

	// mpi.~interface ();
	
	std::string ip = LIB::network::ip::address ();

	mpi.send (delimiter + ip + action_delimiter + LIB::cluster::memory::action::EXISTS + (std::string) "," + delimiter, ip);
	
	// mpi.broadcast ();

	mpi.cancel ();

	//listener_broadcast -> join ();
	//listener_direct -> join ();

	//delete listener_broadcast, listener_direct, timer;
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

	if (timer != NULL)
	{
		delete timer;
		timer = NULL;
	}
	//members.~Members ();
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

void LIB::cluster::memory::initial_listen (void)
{
	while (running)
	{
		//std::cout << "Listening..." << std::endl;
		//std::cout << "Listening: " << mpi.Listen () << std::endl;
		act_broadcast (mpi.listen ());
	}
}

void LIB::cluster::memory::initial_receive (void)
{
	while (running)
	{
		//std::cout << "Receiving..." << std::endl;
		//std::cout << "Receiving: " << mpi.Receive () << std::endl;
		act_direct (mpi.receive ());
	}
}

void LIB::cluster::memory::dummy (void)
{
	// Do not do anything.
}

//template <typename Value, Key>
//bool LIB::Cluster::Memory<Value, Key>::Search (const Key key, Value & value, std::string & host) const
bool LIB::cluster::memory::search (const key _key, value & _value, std::string & host)
{
	//std::string msg;

	if (variables.exists (_key))
	{
		host = LIB::network::ip::address ();
		//host = "localhost";
		_value = variables [_key];

		return true;
	}
	//else if (! members.Empty ())
	//{
	//	bool found;
	//	LIB::NAME_V answer, answer2;
	//	std::string response;

	//	// Ask if anyone has a variable by this key.
	//	if (mpi.Broadcast (delimiter + mpi.Localhost () + actionDelimiter + std::to_string ((Mathematics::Number::Natural) Action::ASK) + delimiter + key + delimiter))
	//	{
	//		response = mpi.Listen ();

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
	//		mpi.tcp.address = host;
	//		mpi.Send (delimiter + mpi.Localhost () + actionDelimiter + std::to_string ((Mathematics::Number::Natural) Action::GET) + delimiter + key + delimiter);
	//		answer2 = mpi.Receive ();
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
	else if (mpi.broadcast (/*msg = */delimiter + LIB::network::ip::address () + action_delimiter + std::to_string ((mathematics::numbers::natural) action::EXISTS) + delimiter + _key + delimiter))
	{
		//std::string response;
		
		//response = mpi.Listen ();
		//response = mpi.Receive ();

		found = false;

		io.reset ();

		timer -> expires_from_now (boost::posix_time::microseconds (timeout));
		timer -> async_wait (boost::bind (& LIB::cluster::memory::dummy, this));
		
		io.run ();

		//if (response.empty ())
		//	return false;

		//bool found;
		//LIB::NAME_V answer, answer2;

		//answer = Parse (response, Content::DATA);
		//host = Parse (response, Content::ADDRESS);
		//found = answer.ToNumber ();

		if (found)
		{
			////value = Get (key);
			////mpi.tcp.address = host;
			//mpi.Send (delimiter + mpi.Localhost () + actionDelimiter + std::to_string ((Mathematics::Number::Natural) Action::GET) + delimiter + key + delimiter, host);
			////answer2 = mpi.Receive ();

			//io.reset ();

			//timer -> expires_from_now (boost::posix_time::seconds (timeout));
			//timer -> async_wait (boost::bind (& LIB::Cluster::Memory::Dummy, this));
		
			//io.run ();

			//value = Parse (data.ToString (), Content::DATA);
			_value = data;
			//data = "";
		}

		return found;
	}
	else
		return false;
}

//template <typename Value, Key>
//bool LIB::Cluster::Memory<Value, Key>::Search (const Key key, Value & value) const
bool LIB::cluster::memory::search (const key _key, value & _value)
{
	std::string host;

	return search (_key, _value, host);
}

//template <typename Value, Key>
//bool LIB::Cluster::Memory<Value, Key>::Search (const Key key) const
bool LIB::cluster::memory::search (const key _key)
{
	value _value;
	std::string host;

	return search (_key, _value, host);
}

//template <typename Value, Key>
//Value LIB::Cluster::Memory<Value, Key>::Get (const Key key) const
value LIB::cluster::memory::get (key _key)
{
	if (variables.exists (_key))
	{
		return variables [_key];
	}
	else
	{
		value _value;

		// Request it from the members, if they may have it.
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
	}
}

//template <typename Value, Key>
//void LIB::Cluster::Memory<Value, Key>::Set (const Key key, const Value value)
bool LIB::cluster::memory::set (key _key, value _value)
{
	// send the value to the member(s) having the variable

	std::string local_address = LIB::network::ip::address ();
	std::string host;
	value val;

	if (search (_key, val, host) && host != local_address)
	{
		//mpi.tcp.address = host;
		return mpi.send (delimiter + local_address + delimiter + std::to_string ((mathematics::numbers::natural) action::SET) + delimiter + _key + delimiter + _value + delimiter, host);
	}
	else
	{
		// Distribute to other peers?
		variables [_key] = _value;

		return variables [_key] == _value;
	}
}

bool LIB::cluster::memory::unset (const key & _key)
{
	if (variables.exists (_key))
	{
		return variables.unset (_key);
	}
	else
	{
		std::string local_address = LIB::network::ip::address ();
		std::string host;
		value _value;

		// Request it from the members, if they may have it.
		if (search (_key, _value, host) && host != local_address)
			return mpi.send (delimiter + local_address + delimiter + std::to_string ((mathematics::numbers::natural) action::UNSET) + delimiter + _key + delimiter, host);
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

bool LIB::cluster::memory::rename (const key & current_key, const key & new_key)
{
	if (variables.exists (current_key))
	{
		return variables.rename (current_key, new_key);
	}
	else
	{
		std::string local_address = LIB::network::ip::address ();
		std::string host;
		value _value;

		// Request it from the members, if they may have it.
		if (search (current_key, _value, host) && host != local_address)
			return mpi.send (delimiter + local_address + delimiter + std::to_string ((mathematics::numbers::natural) action::RENAME) + delimiter + current_key + delimiter + new_key + delimiter, host);
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
std::string LIB::cluster::memory::parse (std::string input, const content _content, const mathematics::numbers::natural requested_data_index)
{
	if (input.empty ())
		return input;
	else if (input [0] != delimiter [0])
		return "";

	std::string ip = "", action = "";
	mathematics::numbers::natural i = 1;
	mathematics::numbers::natural data_index = 0;
	NAME_A <std::string, mathematics::numbers::natural> data;

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
	if (input [i - 1] == action_delimiter)
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
		while (input [i] != delimiter [0])
		//while (i < input.length () && input [i] != delimiter)
		{
			data [data_index] += input [i];
			//data += input [i];
			++ i;
		}

		++ data_index;	// Proceed to the next data part of the message.
		// Skip the DELIMITER character.
		++ i;
	}

	switch (_content)
	{
		case content::ACTION:
			return action;
		case content::ADDRESS:
			return ip;
		case content::DATA:
			return data [requested_data_index];
		default:
			return "";
	}
}

//template <typename Value, Key>
//void LIB::Cluster::Memory<Value, Key>::ActDirect (const std::string input)
void LIB::cluster::memory::act_direct (const std::string input)
{
	if (input.empty ())
		return;

	std::string host, action_string, data_local, value;
	content _action;

	try
	{
		host = parse (input, content::ADDRESS);
		action_string = parse (input, content::ACTION);
		data_local = parse (input, content::DATA);

		_action = (content) atoi (action_string.c_str ());

		switch (_action)
		{
			case action::SET:
				value = parse (input, content::DATA, 1);
				variables [data_local] = value;

				break;
			case action::GET:	// The remote host asked us for the data's value.
				if (variables.exists (data_local))	// We must have the data in order to reply with its value.
				{
					//mpi.tcp.address = host;
					mpi.send (delimiter + LIB::network::ip::address () + delimiter + variables [data_local] + delimiter, host);
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
			//	if (!found && dataLocal == "1")
					found = true;

			//	io.stop ();
			//	break;
			//case Action::GOT:	// I have just received some data.
				data = data_local;
				io.stop ();
		}

		//switch (atoi (action.c_str ()))
		//{
		////case Action::ASK:
		////	if (memory.Exists (data))
		////	{
		////		mpi.tcp (host);
		////		mpi.Send (delimiter + mpi.LocalHost () + delimiter + "1" + delimiter);
		////	}

		////	break;
		//case Action::SET:
		//	std::string value = Parse (input, Content::DATA, 1);
		//	memory [data] = value;

		//	break;
		//case Action::GET:
		//	if (memory.Exists (data))
		//	{
		//		mpi.tcp (host);
		//		mpi.Send (delimiter + mpi.LocalHost () + delimiter + memory [data] + delimiter);
		//	}
		//}
	}
	catch (...)
	{

	}
}

//template <typename Value, Key>
//void LIB::Cluster::Memory<Value, Key>::ActBroadcast (const std::string input)
void LIB::cluster::memory::act_broadcast (const std::string input)
{
	if (input.empty ())
		return;

	std::string host, action, data_local;
	//Content action;

	try
	{
		host = parse (input, content::ADDRESS);
		action = parse (input, content::ACTION);
		data_local = parse (input, content::DATA);

		switch ((content) stoi (action))
		{
			//case Action::ASK:
			case action::GET:
				if (variables.exists (data_local))
				{
					//mpi.tcp.address = host;
					// mpi.Send (delimiter + mpi.LocalHost () + delimiter + "1" + delimiter);	// ?
					mpi.send (delimiter + LIB::network::ip::address () + delimiter + variables [data_local] + delimiter, host);
				}

				break;
			//case Action::SET:
			//	std::string value = Parse (input, Content::DATA, 1);
			//	memory [data] = value;

			//	break;
			//case Action::GET:
			//	if (memory.Exists (data))
			//	{
			//		mpi.tcp (host);
			//		mpi.Send (delimiter + mpi.LocalHost () + delimiter + memory [data] + delimiter);
			//	}
			case action::EXISTS:
				if (variables.exists (data_local))
				{
					mpi.send (delimiter + LIB::network::ip::address () + action_delimiter + std::to_string ((mathematics::numbers::natural) action::ANSWER) + delimiter + variables [data_local] + delimiter, host);
					//mpi.Broadcast (delimiter + mpi.Localhost () + delimiter + "1" + delimiter, host);
				}
				//else
				//{
				//	mpi.Broadcast (delimiter + mpi.Localhost () + delimiter + "0" + delimiter, host);
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
//const value & LIB::cluster::memory::operator [] (const key & _key) const
//{
//	//return const_cast <value &> (get (_key));
//	return get (_key);
//}
//
//// Setter
//value &	LIB::cluster::memory::operator [] (const key & _key)
//{
//	value _val;
//	set (_key, _val);
//
//	return get (_key);
//}
