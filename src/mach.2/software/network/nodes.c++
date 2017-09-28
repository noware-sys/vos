////#ifndef MEMBERS_CPP
////#define MEMBERS_CPP
//
#include "nodes.h"
//
////void LIB::Cluster::InitialBroadcast::operator () (void)
////{
////}
////
////void LIB::Cluster::InitialListen::operator () (void)
////{
////}
//
//LIB::Cluster::Members::Members (void)
//{
//	//mpi.tcp.Port (1);
//	//mpi.udp.Address ("239.255.0.1");
//
//	//mpi.udp.Port (2);
//
//	//running = true;
//	keepalive = 5;
//	t = new boost::asio::deadline_timer (io);
//	//t.basic_io_object (io);
//	//boost::asio::deadline_timer t (io);
//	//initializationThread.thread ();
////	initializationThreadBroadcast = new boost::thread (boost::bind (& InitialBroadcast, this, boost::asio::placeholders::error));
////	initializationThreadListen = new boost::thread (boost::bind (& InitialListen, this, boost::asio::placeholders::error));
//
//	//mpi.Refresh ();
//
//	initializationThreadBroadcast = new boost::thread (boost::bind (& LIB::Cluster::Members::InitialBroadcast, this));
//	initializationThreadListen = new boost::thread (boost::bind (& LIB::Cluster::Members::InitialListen, this));
//
//	//#pragma omp parallel num_threads (3)
//	//{
//	//	//std::cout << omp_get_thread_num () << std::endl;
//
//	//	switch (omp_get_thread_num ())
//	//	{
//	//	// The main thread (#0) should return from the function.
//	//	case 0:
//	//		std::cout << "Breaking out..." << std::endl;
//	//		return;
//	//		break;
//	//	case 1:
//	//		std::cout << omp_get_thread_num () << std::endl;
//	//		while (true)
//	//		{
//	//			t.expires_from_now (boost::posix_time::seconds (discovery_delay));
//
//	//			t.async_wait (boost::bind (& LIB::Cluster::Members::Broadcast, this, boost::asio::placeholders::error));
//	//			io.run ();
//	//			io.reset ();
//
//	//			//std::cout << "Calling function & Broadcast..." << std::endl;
//	//			Clear ();
//	//		}
//
//	//		break;
//	//	case 2:
//	//		std::cout << omp_get_thread_num () << std::endl;
//	//		while (true)
//	//		{
//	//			Acknowledge (mpi.Listen ());
//	//			//std::cout << "Acknowledging Broadcast..." << std::endl;
//	//		}
//	//	}
//
//	//	std::cout << "This is thread " << omp_get_thread_num () << std::endl;
//
//	//}
//
//	//std::cout << "This is thread again " << omp_get_thread_num () << std::endl;
//}
//
//LIB::Cluster::Members::~Members (void)
//{
//	//running = false;
//	initializationThreadBroadcast -> join ();
//	initializationThreadListen -> join ();
//}
//
////void LIB::Cluster::Members::InitialBroadcast (const boost::system::error_code & e)
//void LIB::Cluster::Members::InitialBroadcast (void)
//{
//	t -> expires_from_now (boost::posix_time::seconds (0));
//	t -> async_wait (boost::bind (& LIB::Cluster::Members::Broadcast, this/*, boost::asio::placeholders::error*/));
//
//	io.run ();
//	io.reset ();
//
//	while (true)
//	{
//		t -> expires_from_now (boost::posix_time::seconds (keepalive));
//		Clear ();
//		t -> async_wait (boost::bind (& LIB::Cluster::Members::Broadcast, this/*, boost::asio::placeholders::error*/));
//
//		io.run ();
//		io.reset ();
//
//		//std::cout << "Calling function Broadcast..." << std::endl;
//
//		//peers.Reset ();
//
//		//std::cout << "Members: " << std::endl;
//		//for (LIB::Mathematics::Number::Natural index = 0; index < peers.Size (); ++ index)
//		//{
//		//	std::cout << index + 1 << ". " << peers.Next () << std::endl;
//		//	//peers.at (index) = false;
//		//}
//	}
//}
//
////void LIB::Cluster::Members::InitialListen (const boost::system::error_code & e)
//void LIB::Cluster::Members::InitialListen (void)
//{
//	while (true)
//	{
//		Acknowledge (mpi.Listen ());
//		//std::cout << "Acknowledging Broadcast..." << std::endl;
//	}
//}
//void LIB::Cluster::Members::KeepaliveBroadcast (void)
//{
//
//
//	#pragma omp parallel num_threads (peers.Size ()) private member
//	{
//		mpi.tcp.Address (peers [member]);
//
//		if (mpi.Send (mpi.LocalHost ()) && mpi.Receive () == "")
//		{
//
//		}
//	}
//}
//
//void LIB::Cluster::Members::KeepaliveListen (void)
//{
//
//}
//
//void LIB::Cluster::Members::Acknowledge (std::string ip)
//{
//	if (ip != mpi.LocalHost ())
//	{
//		peers [ip] = true;
//	}
//}
//
//void LIB::Cluster::Members::Broadcast (/*const boost::system::error_code & e*/)
//{
//	mpi.Broadcast (mpi.LocalHost ());
//}
//
//void LIB::Cluster::Members::Clear (void)
//{
//	peers.Reset ();
//
//	for (LIB::Mathematics::Number::Natural index = 0; index < peers.Size (); ++ index)
//	{
//		peers [peers.Next ()] = false;
//		//peers.at (index) = false;
//	}
//}
//
////void LIB::Cluster::Members::Refresh (void)
////{
////	localhost = LIB::Network::Protocols::IP::Value ();
////}
//
//LIB::Mathematics::Number::Natural LIB::Cluster::Members::Size (void) const
//{
//	return peers.Size ();
//}
//
//bool LIB::Cluster::Members::Empty (void) const
//{
//	return peers.Size () == 0;
//}
//
////LIB::Mathematics::Number::Natural LIB::Cluster::Members::operator [] (void)
////{
////	return peers.Size ();
////}
//
////LIB::NAME_A <bool, std::string> * LIB::Cluster::Members::List (void)
////{
////	return & peers;
////}
//
////#endif MEMBERS_CPP

LIB::Cluster::Peers::Peers (void)
{
	delimiter = ";";
	actionDelimiter = "^";

	keepalive = 5;
	//timeout = 5;
	delay = 5;

	mpiKeepalive.udp.port = 2;
	mpiKeepalive.udp.address = "239.255.0.1";
	mpiKeepalive.tcp.port = 3;

	mpiDiscovery.udp.port = 4;
	mpiDiscovery.udp.address = "229.1.1.1";
	mpiDiscovery.tcp.port = 5;

	timerKeepalive = new boost::asio::deadline_timer (ioKeepalive);
	timerDiscovery = new boost::asio::deadline_timer (ioDiscovery);

	keepaliveThreadBroadcast = new boost::thread (boost::bind (& LIB::Cluster::Peers::KeepaliveAsk, this));
	discoveryThreadBroadcast = new boost::thread (boost::bind (& LIB::Cluster::Peers::Discover, this));

	keepaliveListener = new boost::thread (boost::bind (& LIB::Cluster::Peers::KeepaliveListen, this));
	discoveryListener = new boost::thread (boost::bind (& LIB::Cluster::Peers::DiscoveryListen, this));

	keepaliveReceiver = new boost::thread (boost::bind (& LIB::Cluster::Peers::KeepaliveReceive, this));
	discoveryReceiver = new boost::thread (boost::bind (& LIB::Cluster::Peers::DiscoveryReceive, this));
}

LIB::Cluster::Peers::~Peers (void)
{
	keepaliveThreadBroadcast -> join ();
	discoveryThreadBroadcast -> join ();

	keepaliveListener -> join ();
	discoveryListener -> join ();
}

void LIB::Cluster::Peers::Clear (void)
{
	peers.Reset ();

	for (Mathematics::Number::Natural i = 0; i < peers.Size (); ++ i)
	{
		peers [peers.Current ()] = false;
		peers.Next ();
	}
}

void LIB::Cluster::Peers::Clean (void)
{
	peers.Reset ();
	std::string member;

	for (Mathematics::Number::Natural i = 0; i < peers.Size (); ++ i)
	{
		member = peers.Current ();

		if (! peers [member])
			peers.Delete (member);

		peers.Next ();
	}
}

bool LIB::Cluster::Peers::Empty (void) const
{
	return peers.Empty ();
}

LIB::Mathematics::Number::Natural LIB::Cluster::Peers::Size (void) const
{
	return peers.Size ();
}

void LIB::Cluster::Peers::KeepaliveAsk (void)
{
	timerKeepalive -> expires_from_now (boost::posix_time::seconds (0/*Start running as soon as the object is declared.*/));
	timerKeepalive -> async_wait (boost::bind (& LIB::Cluster::Peers::KeepaliveAskDo, this));

	ioKeepalive.run ();
	ioKeepalive.reset ();

	while (true)
	{
		timerKeepalive -> expires_from_now (boost::posix_time::seconds (keepalive));
		//Clear ();
		timerKeepalive -> async_wait (boost::bind (& LIB::Cluster::Peers::KeepaliveAskDo, this));

		ioKeepalive.run ();
		ioKeepalive.reset ();

		//std::cout << "Calling function Broadcast..." << std::endl;

		//peers.Reset ();

		//std::cout << "Peers: " << std::endl;
		//for (LIB::Mathematics::Number::Natural index = 0; index < peers.Size (); ++ index)
		//{
		//	std::cout << index + 1 << ". " << peers.Next () << std::endl;
		//	//peers.at (index) = false;
		//}
	}
}

void LIB::Cluster::Peers::KeepaliveAskDo (void)
{
	// General format of an request message:	Delimiter + IP + ActionDelimiter + Action +	Data (Message) + Delimiter
	// General format of a response message:	Delimiter + IP + Delimiter	+				Data (Response) + Delimiter
	// Demand if the nodes are still there.
	//Mathematics::Number::Natural member;
	//peers.Reset ();

	mpiKeepalive.Broadcast (delimiter + mpiKeepalive.Localhost () + actionDelimiter + std::to_string ((Mathematics::Number::Natural) Action::KEEPALIVE) + delimiter);
	//if (mpiKeepalive.Broadcast (delimiter + mpiKeepalive.Localhost () + std::to_string ((Mathematics::Number::Natural) Action::KEEPALIVE) + delimiter))
	//{
		//std::string msg;
		//peers.Clear ();
		Clear ();

		//#pragma omp parallel num_threads (peers.Size ()) private msg
		//{
		//	//mpiKeepalive.tcp.Address (peers.Next ());

		//	//mpiKeepalive.Broadcast (delimiter + mpiKeepalive.LocalHost () + std::to_string ((Mathematics::Number::Natural) Action::KEEPALIVE) + delimiter);
		//	msg = mpiKeepalive.Receive ();

		//	if (msg.empty ())
		//	{

		//	}
		//	else
		//	{
		//		peers [Parse (msg, LIB::Cluster::Peers::Content::ADDRESS)] = true;
		//	}

		//	//if (mpiKeepalive.Send (mpiKeepalive.LocalHost ()) && mpiKeepalive.Receive () == "")
		//	//{

		//	//}
		//}
	//}
}

void LIB::Cluster::Peers::KeepaliveListen (void)
{
	while (true)
	{
		//std::cout << "Receiving..." << std::endl;
		//std::cout << "Receiving: " << mpi.Receive () << std::endl;
		ActBroadcastKeepalive (mpiKeepalive.Listen ());
	}
}

void LIB::Cluster::Peers::ActBroadcastKeepalive (std::string input)
{
	if (input.empty ())
		return;

	std::string host, actionS, dataLocal, value;
	Action action;

	try
	{
		host = Parse (input, Content::ADDRESS);
		actionS = Parse (input, Content::ACTION);
		dataLocal = Parse (input, Content::DATA);

		action = (Action) atoi (actionS.c_str ());

		switch (action)
		{
			case Action::KEEPALIVE:
				if (mpiKeepalive.Localhost () != host)
					mpiKeepalive.Send (delimiter + mpiKeepalive.Localhost () + actionDelimiter + std::to_string ((Mathematics::Number::Natural) Action::ACKNOWLEDGE) + delimiter, host);
				break;
			//case Action::ACKNOWLEDGE:
			//	peers [host] = true;
			//	break;
			//case Action::DISCOVERED:

			//	break;
			//default:
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

void LIB::Cluster::Peers::KeepaliveReceive (void)
{
	while (true)
	{
		//std::cout << "Receiving..." << std::endl;
		//std::cout << "Receiving: " << mpi.Receive () << std::endl;
		ActDirectKeepalive (mpiKeepalive.Receive ());
	}
}

void LIB::Cluster::Peers::ActDirectKeepalive (std::string input)
{
	if (input.empty ())
		return;

	std::string host, actionS, dataLocal, value;
	Action action;

	try
	{
		host = Parse (input, Content::ADDRESS);
		actionS = Parse (input, Content::ACTION);
		dataLocal = Parse (input, Content::DATA);

		action = (Action) atoi (actionS.c_str ());

		switch (action)
		{
			//case Action::KEEPALIVE:
			//	mpiKeepalive.Send (delimiter + mpiKeepalive.Localhost () + actionDelimiter + std::to_string ((Mathematics::Number::Natural) Action::ACKNOWLEDGE) + delimiter, host);
			//	break;
			case Action::ACKNOWLEDGE:
				//if (mpiKeepalive.Localhost () != host)
					peers [host] = true;
				break;
			//case Action::DISCOVERED:

			//	break;
			//default:
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

void LIB::Cluster::Peers::DiscoveryReceive (void)
{
	while (true)
	{
		//std::cout << "Receiving..." << std::endl;
		//std::cout << "Receiving: " << mpi.Receive () << std::endl;
		ActDirectDiscovery (mpiDiscovery.Receive ());
	}
}

void LIB::Cluster::Peers::ActDirectDiscovery (std::string input)
{
	if (input.empty ())
		return;

	std::string host, actionS, dataLocal, value;
	Action action;

	try
	{
		host = Parse (input, Content::ADDRESS);
		actionS = Parse (input, Content::ACTION);
		dataLocal = Parse (input, Content::DATA);

		action = (Action) atoi (actionS.c_str ());

		switch (action)
		{
			case Action::DISCOVERED:
				//if (mpiDiscovery.Localhost () != host)
					//mpiDiscovery.Send (delimiter + mpiKeepalive.Localhost () + actionDelimiter + std::to_string ((Mathematics::Number::Natural) Action::DISCOVERED) + delimiter, host);
				//if (mpiDiscovery.Localhost () != host)
					peers [host] = true;
				break;
			//default:
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

void LIB::Cluster::Peers::Discover (void)
{
	timerDiscovery -> expires_from_now (boost::posix_time::seconds (0/*Start running as soon as the object is declared.*/));
	timerDiscovery -> async_wait (boost::bind (& LIB::Cluster::Peers::DiscoverDo, this));

	ioDiscovery.run ();
	ioDiscovery.reset ();

	while (true)
	{
		timerDiscovery -> expires_from_now (boost::posix_time::seconds (delay));
		//Clear ();
		timerDiscovery -> async_wait (boost::bind (& LIB::Cluster::Peers::DiscoverDo, this));

		ioDiscovery.run ();
		ioDiscovery.reset ();

		//std::cout << "Calling function Broadcast..." << std::endl;

		//peers.Reset ();

		//std::cout << "Peers: " << std::endl;
		//for (LIB::Mathematics::Number::Natural index = 0; index < peers.Size (); ++ index)
		//{
		//	std::cout << index + 1 << ". " << peers.Next () << std::endl;
		//	//peers.at (index) = false;
		//}
	}
}

void LIB::Cluster::Peers::DiscoverDo (void)
{
	mpiDiscovery.Broadcast (delimiter + mpiDiscovery.Localhost () + actionDelimiter + std::to_string ((Mathematics::Number::Natural) Action::DISCOVERY) + delimiter);
}

void LIB::Cluster::Peers::DiscoveryListen (void)
{
	while (true)
	{
		//std::cout << "Receiving..." << std::endl;
		//std::cout << "Receiving: " << mpi.Receive () << std::endl;
		ActBroadcastDiscovery (mpiDiscovery.Listen ());
	}
}

void LIB::Cluster::Peers::ActBroadcastDiscovery (std::string input)
{
	if (input.empty ())
		return;

	std::string host, actionS, dataLocal, value;
	Action action;

	try
	{
		host = Parse (input, Content::ADDRESS);
		actionS = Parse (input, Content::ACTION);
		dataLocal = Parse (input, Content::DATA);

		action = (Action) atoi (actionS.c_str ());

		switch (action)
		{
			case Action::DISCOVERY:
				if (mpiDiscovery.Localhost () != host)
					mpiDiscovery.Send (delimiter + mpiDiscovery.Localhost () + actionDelimiter + std::to_string ((Mathematics::Number::Natural) Action::DISCOVERED) + delimiter, host);
				break;
			//default:
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

std::string LIB::Cluster::Peers::Parse (std::string input, Content content, Mathematics::Number::Natural requestedDataIndex)
{
	if (input.empty ())
		return input;
	else if (input [0] != delimiter [0])
		return "";

	std::string ip, action = "";
	Mathematics::Number::Natural i = 1;
	Mathematics::Number::Natural dataIndex = 0;
	NAME_A <std::string, Mathematics::Number::Natural> data;

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

LIB::NAME_A <bool, std::string> & LIB::Cluster::Peers::List (void)
{
	return peers;
}
