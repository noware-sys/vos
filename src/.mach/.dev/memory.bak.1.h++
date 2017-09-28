#pragma once
//#ifndef __MEMORY
//#define __MEMORY

#include <string>
//#include <map>
#include <mutex>

// Intel Treading Bulding Blocks:
//#include <tbb/tbb.h>

// Boost:
//#include <boost/any.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>	//
//#include <boost/thread/detail/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

/*
#include <Poco/Net/TCPServer.h>
#include <Poco/Net/TCPServerParams.h>
#include <Poco/Net/TCPServerConnectionFactory.h>
#include <Poco/Net/TCPServerConnection.h>
#include <Poco/Net/Socket.h>
#include <Poco/Data/DataException.h>
#include <Poco/Util/Timer.h>
#include <Poco/Util/TimerTask.h>
#include <Poco/Util/TimerTaskAdapter.h>
*/

#include "../../default.h++"
#include "../../mathematics.h++"
#include "../../containers/array.h++"
#include "../../containers/variable.h++"
#include "../../containers/entity.h++"
//#include "../network/peers.h++"
// #include "../../network/mpi.h++"
//#include "../network/ip.h++"
//#include "../threads.h++"
#include "../../cluster/machine.h++"
#include "../resource.h++"

//typedef std::string value, key;

//#include "../../containers/entity-pre.h++"

namespace LIB
{
	namespace cluster
	{
		class cluster;
	}

	//namespace machine
	//{
		//class NTT;
		
//		class container
//		{
//			public:
//				container (void);
//				~ container (void);
//				
//				//std::string text;
//				//bool reference;
//				LIB::NAME_V literal;
//				
//				LIB::array <LIB::NTT, LIB::NAME_V> group;
//		};
		
	//template <typename value = LIB::NAME_V, typename key = LIB::NAME_V>
	//class NTT;
	
	namespace machine
	{
		namespace resources
		{
			//typedef std::string key, value;
			
			//template <typename Value = std::string, Key = std::string>
			class memory : public resource//, public LIB::communication::messaging //, LIB::NTT <value, key>
			{
				public:
					//typedef std::string value, key;
					//typedef std::string key;
					//typedef boost::any value;
					typedef std::string value;
					//typedef std::string value_cast;
					
					//typedef NTT registry, directory, folder;
					
					friend class LIB::cluster::cluster;
					//friend class LIB::cluster::members;
					
					class keys //: LIB::NTT <value, key>::container
					{
						public:
							friend class memory;
							friend class LIB::NTT <>;
							
							keys (void);
							keys (const keys &);
							
							const bool operator == (const keys &) const;
							const bool operator != (const keys &) const;
						//protected:
							bool grouped;
							
							//value name;
							//value group;
							std::string name;
							std::string group;
					};
					
					/*
					class container //: LIB::NTT <value, key>::container
					{
						public:
							//friend class memory;
							
							typedef std::string value;
							
							container (void);
							container (const container &);
							
							const bool operator == (const container &) const;
							const bool operator != (const container &) const;
							
							// Getter
							operator const value & (void) const;
							// Setter
							const value & operator = (const value &);
						protected:
							//bool grouped;
							
							value content;
							
							//value group;
					};
					*/
					
					//typedef container value;
					typedef keys key;
					
					// Used when searching for data:
					class research
					{
						public:
							class response
							{
								public:
									response (void);
									
									bool found;
									bool responded;
							};
							
							//research (void);
							~research (void);
							
							std::mutex lock;
							//value data;
							const LIB::NAME_A <LIB::cluster::machine, LIB::mathematics::numbers::natural> owners (void) const;
							//const LIB::cluster::machine owner (void) const;
							
							const bool found (void) const;
							const bool responded (void) const;
							
							// List of machines which should respond.
							LIB::NAME_A <response, LIB::mathematics::numbers::natural/* id*/> machines;
							//LIB::NAME_A <response, LIB::cluster::machine> machines;
					};
					
//					//template <typename v = value, typename k = key>
//					class NTT :/* public*/ LIB::NTT <value, key>
//					{
//						public:
//							friend class LIB::cluster::cluster;
//							
//							class container : LIB::NTT <value, key>::container
//							{
//								public:
//									//container (void);
//									//~container (void);
//								protected:
//									LIB::cluster::cluster * cluster;
//							};
//							
//							//NTT (void);
//							NTT (const LIB::cluster::cluster * &);
//							//~NTT (void);
//							
//							//const memory::value get (const LIB::NTT <> & = "");
//							//const bool create (const memory::key &);
//							NTT & operator [] (const key &);
//							const NTT & operator [] (const key &) const;
//							
//							const value & operator () (void);
//							const value & operator () (void) const;
//						protected:
//							// Current group.
//							value group;
//							//memory _memory;
//							LIB::cluster::cluster * cluster;
//					};
//					
//					typedef NTT registry, directory, folder;
					
					/*
					class new_connection : public Poco::Net::TCPServerConnection
					{
						public:
							new_connection (const Poco::Net::StreamSocket & s) : Poco::Net::TCPServerConnection (s)
							{
							}

							void run ()
							{
								std::cout << "New connection from: " << socket ().peerAddress ().host ().toString () << std::endl << std::flush;
								bool isOpen = true;
								Poco::Timespan timeOut (10, 0);
								unsigned char incommingBuffer [1000];
					
								while (isOpen)
								{
									if (socket ().poll (timeOut, Poco::Net::Socket::SELECT_READ) == false)
									{
										std::cout << "TIMEOUT!" << std::endl << std::flush;
									}
									else
									{
										std::cout << "RX EVENT!!! ---> " << std::flush;
										int nBytes = -1;

										try
										{
											nBytes = socket ().receiveBytes (incommingBuffer, sizeof (incommingBuffer));
										}
										catch (Poco::Exception & exc)
										{
											//Handle your network errors.
											std::cerr << "Network error: " << exc.displayText () << std::endl;
											isOpen = false;
										}

										if (nBytes == 0)
										{
											std::cout << "Client closes connection!" << std::endl << std::flush;
											isOpen = false;
										}
										else
										{
											std::cout << "Receiving nBytes: " << nBytes << std::endl << std::flush;
										}
									}
								}

								std::cout << "Connection finished!" << std::endl << std::flush;
							}
					};
					*/
				/*
					To do:

					Allow variables to be found when not all nodes are interconnected (re-broadcast).
				*/
				protected:
					// To be returned in default cases:
					//value v;
					//memory * m;
					
					// General format of an request message:	Delimiter + IP + ActionDelimiter	+ Action	+	Delimiter	+	Data (Message)	+ Delimiter
					// General format of a response message:	Delimiter + IP									+	Delimiter	+	Data (Response)	+ Delimiter
					
					// enum /*class */content {ADDRESS, ACTION, DATA};
					// enum /*class */action {ASK, ANSWER, GET, GOT, SET, UNSET, EXISTS, RENAME};
					//bool copy;
					// bool group;	// True == This memory object holds multiple values; False == This memory object holds a single value.
					//boost::asio::io_service io;
					//boost::asio::deadline_timer * timer;
					
					//boost::thread * listener, * receiver;
					
					LIB::NAME_A <research, LIB::mathematics::numbers::natural> searches;
					
					// std::string delimiter;	// Delimits parts of the request message 
					// std::string action_delimiter;	// Delimits parts of the response message 
					//std::string partner;	// Only valid and only used when "copy == true", as this variable holds the localhost's redundant host to pair with.
					LIB::NAME_A <value, key> variables;	// The container.
					//LIB::NAME_A<LIB::NAME_A<std::string, Mathematics::Number::Natural>/*Value*/, Mathematics::Number::Natural/*Key*/> redundancyGroups, stripedGroups;
					
					
					bool _active;
					//boost::thread * listener_broadcast;
					//boost::thread * listener_direct;
					
					// void initial_listen (void);
					// void initial_receive (void);
					
					//LIB::Cluster::Members members;
					
					// std::string parse (std::string/*Message*/, const content/*What is being asked*/, const unsigned short int & = 0/*Data index*/);	// Parse the message.
				//public:
					// void act_direct (std::string);
					// void act_broadcast (std::string);
				//protected:
					// void dummy (void);	// Used by the timer.
					//bool active;
					
					// const bool search (const key &/* name*/, /*value*/LIB::mathematics::numbers::natural &, const key &/* group*/ = "") const;
					// const bool search (const key &/* name*/, LIB::cluster::machine &/* machine*/, const key &/* group*/ = "") const;
					const bool search (const key &, LIB::cluster::machine &/* machine*/) const;
					//bool search (const key, value &, std::string &/*IP address of the host which has the variable.*/);
					
					memory & _get_all (key);
					value & first_value (void);
					//threads listeners;
					//std::string _local_address;
					
					// LIB::network::mpi * mpi;
					LIB::cluster::cluster * cluster;
					//LIB::Cluster::Peers peers;
					// LIB::cluster::members * machines;
				public:
					//mathematics::numbers::natural timeout;	// In microseconds (1 µs = 0.000 001 s).
					//mathematics::numbers::natural network_device;
					
					// In microseconds (1 µs = 0.000 001 s).
					/*unsigned int*/LIB::mathematics::numbers::natural timeout;
					
					//unsigned short int network_device;
					//float timeout;
					
					memory (void);
					memory (const memory &/* other*/);
					memory (const LIB::cluster::cluster * &);
					~memory (void);
					
					// General purpose functions:
					// Functions which provide communication with the purpose of organizing nodes:
					// Functions which provide communication with the purpose of working with data:
					//void Broadcast (void);	// Notifies peers of a change in the memory (variable).
					//bool/*Success/Failure*/ Synchronize (const NAME_V/*One variable in memory.*/);
					
					// Set the activity state.
					const bool run (const bool &/* active(_running)_state*/ = true);
					//const bool & run (void) const;
					
					//Value & operator [] (const Key &);
					const bool exist (const key &) const;
					
					memory & get_all (const key &);
					const memory & get_all (const key &) const;
					
					//const value get (const key &) const;
					value & get (key);
					const value & get (key) const;
					const bool set (key, const value &);
					
					const bool unset (key);
					const bool move (key/* old*/, key/* new*/);
					
					const LIB::mathematics::numbers::natural size (void) const;
					const bool empty (void) const;
					//const value & operator [] (const key &) const;	// Getter
					//value & operator [] (const key &);				// Setter
					memory operator [] (const key &);				// Getter and Setter
					//const memory operator [] (const key &) const;	// Getter
					
					//operator value (void);
					operator const value (void) const;
					
					const memory & operator = (const memory &);
					//const memory & operator = (const LIB::NTT <value, key> &);
					//const memory & operator = (const LIB::NTT <value, value> &);
					const memory & operator = (const value &);
					
					const bool content_clear_group (const key &);
					//Mathematics::Number::Natural Size (void) const;
					//void List (void);
					//bool refresh_local_address (const LIB::mathematics::numbers::natural &/* network_device*/);
					//bool refresh_local_address (void);
					//std::string get_local_address (void);
					//std::string refresh_and_get_local_address (const LIB::mathematics::numbers::natural &/* network_device*/);
					//std::string refresh_and_get_local_address (void);
			};
		}
	}
}

#include "../../cluster.h++"

//template <typename Value, Key>
//LIB::Cluster::Memory<Value, Key>::Memory (void)
//{
//	mpi.tcp.Port (2);
//	mpi.udp.Address ("239.255.1.1");
//	mpi.udp.Port (30002);
//	//bool copy = true;
//	delimiter = ";";
//	actionDelimiter = "^";
//
//	#pragma omp parallel num_threads (3)
//	{
//		switch (omp_get_thread_num ())
//		{
//		// The main thread (#0) should return from the function.
//		case 1:
//			while (true)
//			{
//				ActDirect (mpi.Receive ());
//			}
//			break;
//		case 2:
//			while (true)
//			{
//				ActBroadcast (mpi.Listen ());
//			}
//		}
//	}
//}
//
////template <typename Value, Key>
////Value LIB::Cluster::Memory<Value, Key>::operator [] (const Key)
////{
////	if (memory.Exists (Key))
////	{
////		return memory [Key];
////	}
////	else
////	{
////		// Request it from the members, if they may have it.
////		return Search (Key);
////	}
////}
//
//template <typename Value, Key>
//bool LIB::Cluster::Memory<Value, Key>::Search (const Key key, Value & value, std::string & host) const
//{
//	if (memory.Exists (key))
//	{
//		return true;
//	}
//	else if (! members.Empty ())
//	{
//		bool found;
//		LIB::NAME_V answer, answer2;
//		std::string response;
//
//		// Ask if anyone has a variable by this key.
//		if (mpi.Broadcast (delimiter + mpi.LocalHost () + actionDelimiter + to_string (Content::ASK) + delimiter + key + delimiter))
//			response = mpi.Listen ();
//		else
//			return false;
//
//		answer = Parse (response, Content::DATA);
//		host = Parse (response, Content::ADDRESS);
//		found = (bool) answer;
//
//		if (found)
//		{
//			//value = Get (key);
//			mpi.tcp.Address (host);
//			mpi.Send (delimiter + mpi.LocalHost () + actionDelimiter + to_string (Content::GET) + delimiter + key + delimiter);
//			answer2 = mpi.Receive ();
//			value = Parse (answer2, Content::DATA);
//		}
//
//		return found;
//	//}
//	//else
//	//{
//	//	return false;
//	}
//}
//
//template <typename Value, Key>
//bool LIB::Cluster::Memory<Value, Key>::Search (const Key key, Value & value) const
//{
//	std::string host;
//
//	return Search (key, value, host);
//}
//
//template <typename Value, Key>
//bool LIB::Cluster::Memory<Value, Key>::Search (const Key key) const
//{
//	Value value;
//	std::string host;
//
//	return Search (key, value, host);
//}
//
//template <typename Value, Key>
//Value LIB::Cluster::Memory<Value, Key>::Get (const Key key) const
//{
//	if (memory.Exists (key))
//	{
//		return memory [key];
//	}
//	else
//	{
//		// Request it from the members, if they may have it.
//		Value value;
//
//		if (Search (key, value))
//		{
//			return value;
//		}
//		else
//		{
//			Value tmp;
//			return temp;
//		}
//	}
//}
//
//template <typename Value, Key>
//void LIB::Cluster::Memory<Value, Key>::Set (const Key key, const Value value)
//{
//	// Send the value to the member(s) having the variable
//
//	std::string host;
//
//	if (Search (key, value, host))
//	{
//		mpi.tcp.Address (host);
//		mpi.Send (delimiter + mpi.LocalHost () + delimiter + Action::SET + delimiter + key + delimiter + value + delimiter);
//	}
//	else
//	{
//		// Distribute?
//		memory [key] = value;
//	}
//}
//
//template <typename Value, Key>
//std::string LIB::Cluster::Memory<Value, Key>::Parse (const std::string input, const Content content, Mathematics::Number::Natural requestedDataIndex) const
//{
//	if (input.empty ())
//		return input;
//	else if (input [0] != delimiter [0])
//		return "";
//
//	std::string ip, action = "";
//	Mathematics::Number::Natural i = 1;
//	Mathematics::Number::Natural dataIndex = 0;
//	NAME_A<std::string, Mathematics::Number::Natural> data;
//
//	// Determine where the IP address ends in the string.
//	while (i < input.length () && input [i] != delimiter [0])
//	{
//		// Store the IP address in our local variable
//		ip += input [i];
//		++ i;
//	}
//
//	// Skip the DELIMITER character.
//	++ i;
//	
//	// Handle the IP address
//	//cout << "Capacity: " << nodes.capacity () << endl;
//	if (input [i - 1] == actionDelimiter)
//	{
//		// Determine the ACTION:
//		while (i < input.length () && input [i] != delimiter [0])
//		{
//			// Store the IP address in our local variable.
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
//		while (input [i] != delimiter [0])
//		//while (i < input.length () && input [i] != delimiter)
//		{
//			data [dataIndex] += input [i];
//			//data += input [i];
//			++ i;
//		}
//
//		++ dataIndex;	// Proceed to the next data part of the message.
//		// Skip the DELIMITER character.
//		++ i;
//	}
//
//	switch (content)
//	{
//		case Content::ACTION:
//			return action;
//		case Content::ADDRESS:
//			return ip;
//		case Content::DATA:
//			return data [requestedDataIndex];
//	}
//}
//
//template <typename Value, Key>
//void LIB::Cluster::Memory<Value, Key>::ActDirect (const std::string input)
//{
//	std::string host, action, data;
//	//Content action;
//
//	host = Parse (input, Content::ADDRESS);
//	action = Parse (input, Content::ACTION);
//	data = Parse (input, Content::DATA);
//
//	switch (atoi (action))
//	{
//	//case Action::ASK:
//	//	if (memory.Exists (data))
//	//	{
//	//		mpi.tcp (host);
//	//		mpi.Send (delimiter + mpi.LocalHost () + delimiter + "1" + delimiter);
//	//	}
//
//	//	break;
//	case Action::SET:
//		std::string value = Parse (input, Content::DATA, 1);
//		memory [data] = value;
//
//		break;
//	case Action::GET:
//		if (memory.Exists (data))
//		{
//			mpi.tcp (host);
//			mpi.Send (delimiter + mpi.LocalHost () + delimiter + memory [data] + delimiter);
//		}
//	}
//}
//
//template <typename Value, Key>
//void LIB::Cluster::Memory<Value, Key>::ActBroadcast (const std::string input)
//{
//	std::string host, action, data;
//	//Content action;
//
//	host = Parse (input, Content::ADDRESS);
//	action = Parse (input, Content::ACTION);
//	data = Parse (input, Content::DATA);
//
//	switch (atoi (action))
//	{
//	case Action::ASK:
//		if (memory.Exists (data))
//		{
//			mpi.tcp (host);
//			mpi.Send (delimiter + mpi.LocalHost () + delimiter + "1" + delimiter);
//		}
//
//		break;
//	//case Action::SET:
//	//	std::string value = Parse (input, Content::DATA, 1);
//	//	memory [data] = value;
//
//	//	break;
//	//case Action::GET:
//	//	if (memory.Exists (data))
//	//	{
//	//		mpi.tcp (host);
//	//		mpi.Send (delimiter + mpi.LocalHost () + delimiter + memory [data] + delimiter);
//	//	}
//	}
//}

//#include "../../containers/entity.h++"
//#endif
