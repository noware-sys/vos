#ifndef MEMBERS
#define MEMBERS

#include <string>
#include <map>
//#include <list>
//#include <omp.h>

//#include <boost/any.hpp>
//#include <boost/exception/all.hpp>
//#include <boost/system/error_code.hpp>
//#include <boost/system/system_error.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include "../containers/array.h++"
#include "../mathematics.h++"
#include "../default.h++"
#include "../containers/variable.h++"
#include "../network/mpi.h++"
#include "../network/ip.h++"

namespace LIB
{
	class cluster
	{
		public:
			//class InitialBroadcast
			//{
			//public:
			//	void operator () (void);
			//};
		
			//class InitialListen
			//{
			//public:
			//	void operator () (void);
			//};
		
			class members
			{
				public:
					members (void);
					~members (void);
					
					LIB::mathematics::numbers::natural
						keepalive,	// Seconds between online checks among nodes.
						timeout,	// Seconds to wait before a node is declared offline.
						delay		// Discovery delay.
					;
					
					//void Refresh (void);
					LIB::mathematics::numbers::natural count (void) const;
					bool empty (void) const;
					//LIB::NAME_A <bool, std::string> * List (void);
					
					LIB::network::mpi mpi_keepalive, mpi_discovery;
					
					//LIB::NAME_A <bool, std::string> & List (void);
				protected:
					//std::string localhost;
					//std::map<std::string, bool> members;
					//bool running;
					//std::map<std::string, bool> members;
					// LIB::NAME_A <bool /*Value (Online/Offline)*/, std::string /*Key (IP address)*/> peers;
					LIB::NAME_A <member /*Value ("member" entity)*//*, std::string *//*Key (Name (Unique))*/> _members;
					//map <std::string, bool> peers;
					//LIB::NAME_A <std::string /*Value (IP address)*/, Mathematics::Number::Natural /*Key: Index*/> members;
					//LIB::NAME_A <Mathematics::Number::Natural, > members;
					// bool confirm;
					// string answer;
					
					//bool copy;
					//std::string delimiter;			// Delimits parts of the message
					//std::string actionDelimiter;	// Delimits parts of the message
//					
//					boost::asio::io_service io_keepalive;
//					boost::asio::io_service io_discovery;
//					
//					boost::asio::deadline_timer * timer_keepalive;
//					boost::asio::deadline_timer * timer_discovery;
//				
//					//boost::asio::deadline_timer t (io);
//				
//					boost::thread * keepalive_thread_broadcast;
//					boost::thread * keepalive_listener;
//				
//					boost::thread * discovery_thread_broadcast;
//					boost::thread * discovery_listener;
//				
//					boost::thread * discovery_receiver;
//					boost::thread * keepalive_receiver;
//				
//					//enum Content {ADDRESS, ACTION, DATA};
//					//enum Action {KEEPALIVE, ACKNOWLEDGE, DISCOVERY, DISCOVERED};
//
//					void acknowledge (std::string);
//					void broadcast (/*const boost::system::error_code & e*/);
//					void clear (void);
//					void clean (void);
//					//void InitialBroadcast (const boost::system::error_code & e);
//					//void InitialListen (const boost::system::error_code & e);
//				
//					//std::string parse (std::string/*Message*/, content/*What is being asked*/, mathematics::numbers::natural = 0/*Data index*/);	// Parse the message.
//
//					void discover (void);
//					void discover_do (void);
//
//					void discovery_receive (void);
//					void discovery_listen (void);
//					//
					void keepalive_request (void);
					void keepalive_respond (void);
//					void keepalive_ask (void);
//					void keepalive_ask_do (void);
//
//					void Keepalive_receive (void);
//					void keepalive_listen (void);
//					//
//					void act_direct_keepalive (std::string /*Received message.*/);
//					void act_broadcast_keepalive (std::string /*Received message.*/);
//
//					void act_direct_discovery (std::string /*Received message.*/);
//					void act_broadcast_discovery (std::string /*Received message.*/);
			};
	};
}

#endif
