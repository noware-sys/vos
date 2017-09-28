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
//#include "../../communication/messaging.h++"
//#include "../network/peers.h++"
// #include "../../network/mpi.h++"
//#include "../network/ip.h++"
//#include "../threads.h++"
// #include "../../cluster/machine.h++"
#include "../../cluster/members.h++"
#include "../resource.h++"

//typedef std::string value, key;

//#include "../../containers/entity-pre.h++"

namespace LIB
{
	namespace machine
	{
		namespace resources
		{
			class memory : LIB::machine::resource//, LIB::communication::messaging //, LIB::NTT <value, key>
			{
				public:
					//typedef std::string value, key;
					//typedef std::string key;
					//typedef boost::any value;
					//typedef std::string value;
					//typedef std::string value_cast;
					
					//typedef NTT registry, directory, folder;
					
					// friend class LIB::cluster::cluster;
					//friend class LIB::cluster::members;
					
//					typedef NTT registry, directory, folder;
					
					
					// The container.
					//LIB::NAME_A <value, key> variables;
					LIB::containers::memory container;
					
					LIB::cluster::members members;
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
					
					//LIB::NAME_A <search, LIB::mathematics::numbers::natural> searches;
					
					// std::string delimiter;	// Delimits parts of the request message 
					// std::string action_delimiter;	// Delimits parts of the response message 
					//std::string partner;	// Only valid and only used when "copy == true", as this variable holds the localhost's redundant host to pair with.
					
					//// The container.
					////LIB::NAME_A <value, key> variables;
					//LIB::memory container;
					
					//LIB::NAME_A<LIB::NAME_A<std::string, Mathematics::Number::Natural>/*Value*/, Mathematics::Number::Natural/*Key*/> redundancyGroups, stripedGroups;
					
					
					//bool _active;
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
					const bool _search (const LIB::containers::memory::key &, LIB::cluster::machine &/* machine*/) const;
					//bool search (const key, value &, std::string &/*IP address of the host which has the variable.*/);
					
					memory & _get_all (LIB::containers::memory::key);
					LIB::containers::memory::value & first_value (void);
					//threads listeners;
					//std::string _local_address;
					
					// LIB::network::mpi * mpi;
					//LIB::cluster::cluster * cluster;
					//LIB::Cluster::Peers peers;
					// LIB::cluster::members * machines;
				public:
					//mathematics::numbers::natural timeout;	// In microseconds (1 µs = 0.000 001 s).
					//mathematics::numbers::natural network_device;
					
					// In microseconds (0.000 001 s = 1 µs).
					/*unsigned int*/LIB::mathematics::numbers::natural timeout;
					
					//unsigned short int network_device;
					//float timeout;
					
					memory (void);
					memory (const memory &/* other*/);
					//memory (const LIB::cluster::cluster * &);
					~memory (void);
					
					// General purpose functions:
					// Functions which provide communication with the purpose of organizing nodes:
					// Functions which provide communication with the purpose of working with data:
					//void Broadcast (void);	// Notifies peers of a change in the memory (variable).
					//bool/*Success/Failure*/ Synchronize (const NAME_V/*One variable in memory.*/);
					
					// Set the activity state.
					//const bool run (const bool &/* active(_running)_state*/ = true);
					//const bool & run (void) const;
					
					//Value & operator [] (const Key &);
					//const bool exist (const key &) const;
					const bool exists (const key &, const key & = LIB::containers::memory::default_group) const;
					
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

//#include "../../cluster.h++"
