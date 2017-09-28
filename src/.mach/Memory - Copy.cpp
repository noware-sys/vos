#include "Memory.h"

//template <typename Value, Key>
//LIB::Cluster::Memory<Value, Key>::Memory (void)
LIB::Cluster::Memory::Memory (void)
{
	//mpi.tcp.Port (2);
	//mpi.udp.Address ("239.255.1.1");
	//mpi.udp.Port (30002);

	mpi.tcp.port = 3;

	mpi.udp.address = "229.255.0.1";
	mpi.udp.port = 4;

	//bool copy = true;
	delimiter = ";";
	actionDelimiter = "^";

	timeout = 5;

	listenerBroadcast = new boost::thread (boost::bind (& LIB::Cluster::Memory::InitialListen, this));
	listenerDirect = new boost::thread (boost::bind (& LIB::Cluster::Memory::InitialReceive, this));

	timer = new boost::asio::deadline_timer (io);
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

LIB::Cluster::Memory::~Memory (void)
{
	listenerBroadcast -> join ();
	listenerDirect -> join ();

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

void LIB::Cluster::Memory::InitialListen (void)
{
	while (true)
	{
		//std::cout << "Listening..." << std::endl;
		//std::cout << "Listening: " << mpi.Listen () << std::endl;
		ActBroadcast (mpi.Listen ());
	}
}

void LIB::Cluster::Memory::InitialReceive (void)
{
	while (true)
	{
		//std::cout << "Receiving..." << std::endl;
		//std::cout << "Receiving: " << mpi.Receive () << std::endl;
		ActDirect (mpi.Receive ());
	}
}

void LIB::Cluster::Memory::Dummy (void)
{
	// Do not do anything.
}

//template <typename Value, Key>
//bool LIB::Cluster::Memory<Value, Key>::Search (const Key key, Value & value, std::string & host) const
bool LIB::Cluster::Memory::Search (Key key, Value & value, std::string & host)
{
	std::string msg;

	if (memory.Exists (key))
	{
		host = mpi.Localhost ();
		value = memory [key];
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

	// Ask if anyone has a variable by this key.
	else if (mpi.Broadcast (/*msg = */delimiter + mpi.Localhost () + actionDelimiter + std::to_string ((Mathematics::Number::Natural) Action::EXISTS) + delimiter + key + delimiter))
	{
		//std::string response;
		
		//response = mpi.Listen ();
		//response = mpi.Receive ();

		found = false;

		io.reset ();

		timer -> expires_from_now (boost::posix_time::seconds (timeout));
		timer -> async_wait (boost::bind (& LIB::Cluster::Memory::Dummy, this));
		
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
			//value = Get (key);
			//mpi.tcp.address = host;
			mpi.Send (delimiter + mpi.Localhost () + actionDelimiter + std::to_string ((Mathematics::Number::Natural) Action::GET) + delimiter + key + delimiter, host);
			//answer2 = mpi.Receive ();

			io.reset ();

			timer -> expires_from_now (boost::posix_time::seconds (timeout));
			timer -> async_wait (boost::bind (& LIB::Cluster::Memory::Dummy, this));
		
			io.run ();

			//value = Parse (data.ToString (), Content::DATA);
			value = data;
			data = "";
		}

		return found;
	}
	else
		return false;
}

//template <typename Value, Key>
//bool LIB::Cluster::Memory<Value, Key>::Search (const Key key, Value & value) const
bool LIB::Cluster::Memory::Search (const Key key, Value & value)
{
	std::string host;

	return Search (key, value, host);
}

//template <typename Value, Key>
//bool LIB::Cluster::Memory<Value, Key>::Search (const Key key) const
bool LIB::Cluster::Memory::Search (const Key key)
{
	Value value;
	std::string host;

	return Search (key, value, host);
}

//template <typename Value, Key>
//Value LIB::Cluster::Memory<Value, Key>::Get (const Key key) const
Value LIB::Cluster::Memory::Get (Key key)
{
	if (memory.Exists (key))
	{
		return memory [key];
	}
	else
	{
		Value value;

		// Request it from the members, if they may have it.
		if (Search (key, value))
		{
			return value;
		}
		else
		{
			Value temp;
			return temp;
		}
	}
}

//template <typename Value, Key>
//void LIB::Cluster::Memory<Value, Key>::Set (const Key key, const Value value)
void LIB::Cluster::Memory::Set (Key key, Value value)
{
	// Send the value to the member(s) having the variable

	std::string host;

	if (Search (key, value, host))
	{
		//mpi.tcp.address = host;
		mpi.Send (delimiter + mpi.Localhost () + delimiter + std::to_string ((Mathematics::Number::Natural) Action::SET) + delimiter + key + delimiter + value + delimiter, host);
	}
	else
	{
		// Distribute?
		memory [key] = value;
	}
}

//template <typename Value, Key>
//std::string LIB::Cluster::Memory<Value, Key>::Parse (const std::string input, const Content content, Mathematics::Number::Natural requestedDataIndex) const
std::string LIB::Cluster::Memory::Parse (std::string input, Content content, Mathematics::Number::Natural requestedDataIndex)
{
	if (input.empty ())
		return input;
	else if (input [0] != delimiter [0])
		return "";

	std::string ip, action = "";
	Mathematics::Number::Natural i = 1;
	Mathematics::Number::Natural dataIndex = 0;
	NAME_A<std::string, Mathematics::Number::Natural> data;

	// Determine where the IP address ends in the string.
	while (i < input.length () && input [i] != delimiter [0] && input [i] != actionDelimiter [0])
	{
		// Store the IP address in our local variable
		ip += input [i];
		++ i;
	}

	// Skip the DELIMITER or the ACTION_DELIMITER character.
	++ i;
	
	// Handle the IP address
	//cout << "Capacity: " << nodes.capacity () << endl;
	if (input [i - 1] == actionDelimiter)
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
			data [dataIndex] += input [i];
			//data += input [i];
			++ i;
		}

		++ dataIndex;	// Proceed to the next data part of the message.
		// Skip the DELIMITER character.
		++ i;
	}

	switch (content)
	{
		case Content::ACTION:
			return action;
		case Content::ADDRESS:
			return ip;
		case Content::DATA:
			return data [requestedDataIndex];
		default:
			return "";
	}
}

//template <typename Value, Key>
//void LIB::Cluster::Memory<Value, Key>::ActDirect (const std::string input)
void LIB::Cluster::Memory::ActDirect (const std::string input)
{
	if (input.empty ())
		return;

	std::string host, actionS, dataLocal, value;
	Content action;

	try
	{
		host = Parse (input, Content::ADDRESS);
		actionS = Parse (input, Content::ACTION);
		dataLocal = Parse (input, Content::DATA);

		action = (Content) atoi (actionS.c_str ());

		switch (action)
		{
			case Action::SET:
				value = Parse (input, Content::DATA, 1);
				memory [dataLocal] = value;
				break;
			case Action::GET:	// The remote host asked us for the data's value.
				if (memory.Exists (dataLocal))	// We must have the data in order to reply with its value.
				{
					//mpi.tcp.address = host;
					mpi.Send (delimiter + mpi.Localhost () + delimiter + memory [dataLocal] + delimiter, host);
				}
				break;
			case Action::ANSWER:
				if (!found && dataLocal == "1")
					found = true;

				io.stop ();
				break;
			case Action::GOT:	// I have just received some data.
				data = dataLocal;
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
void LIB::Cluster::Memory::ActBroadcast (const std::string input)
{
	if (input.empty ())
		return;

	std::string host, action, dataLocal;
	//Content action;

	try
	{
		host = Parse (input, Content::ADDRESS);
		action = Parse (input, Content::ACTION);
		dataLocal = Parse (input, Content::DATA);

		switch ((Content) stoi (action))
		{
			//case Action::ASK:
			case Action::GET:
				if (memory.Exists (dataLocal))
				{
					//mpi.tcp.address = host;
					// mpi.Send (delimiter + mpi.LocalHost () + delimiter + "1" + delimiter);	// ?
					mpi.Send (delimiter + mpi.Localhost () + delimiter + memory [dataLocal] + delimiter, host);
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
			case Action::EXISTS:
				if (memory.Exists (dataLocal))
				{
					mpi.Send (delimiter + mpi.Localhost () + actionDelimiter + std::to_string ((Mathematics::Number::Natural) Action::ANSWER) + delimiter + "1" + delimiter, host);
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

//void LIB::Cluster::Memory::ListMembers (void)
//{
//	LIB::NAME_A<bool, std::string> list = *(members.List ());
//
//	list.Reset ();
//
//	for (LIB::Mathematics::Number::Natural index = 0; index < list.Size (); ++ index)
//	{
//		std::cout << index + 1 << ". " << list.Next () << std::endl;
//		//members.at (index) = false;
//	}
//}
