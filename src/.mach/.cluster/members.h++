#pragma once

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

#include "../default.h++"
#include "../mathematics.h++"
#include "../serialization.h++"
//#include "machine.h++"
//#include "../machine/device.h++"
//#include "../machine/resource.h++"
//#include "../machine/resources.h++"
#include "../containers/array.h++"
#include "../containers/variable.h++"
//#include "../containers/entity.h++"
//#include "../cluster.h++"

#include "../communication/messaging.h++"
// #include "../network/mpi.h++"
// #include "../network/ip.h++"
#include "member.h++"

namespace LIB
{
	namespace cluster
	{
		//class cluster;
		//class machine;
		
		//public:
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
					//#include "node.h++"
					
					//friend class boost::serialization::access;
					
					//template <typename archive>
					//void serialize (archive & /* Archive (stream). */, const unsigned int &/* Version. */);
					
					//template <typename Archive>
					//void save (Archive &/* Archive (stream). */, const unsigned int &/* Version. */) const;
					//
					//template <typename Archive>
					//void load (Archive &/* Archive (stream). */, const unsigned int &/* Version. */);
					
					members (void/*const LIB::mathematics::numbers::natural &*//* keepalive time (milliseconds)*//* = 15000*/);
					~members (void);
					
					//static const unsigned short int default_udp_port = 6;
					//static const unsigned short int default_tcp_port = 7;
					static const /*unsigned short int*/LIB::mathematics::numbers::natural default_udp_port;
					static const /*unsigned short int*/LIB::mathematics::numbers::natural default_tcp_port;
					
					//friend class LIB::cluster::cluster;
					
					static const LIB::mathematics::numbers::natural default_timeout;
					LIB::mathematics::numbers::natural
						//keepalive// = 10	// Time (seconds) between online checks among nodes.
						timeout		// Time (seconds) to wait before a node is declared offline (after it fails to respond).
						//delay		// Discovery delay.
						//delay_max = 3 // seconds
					;
					
					//void Refresh (void);
					//const LIB::mathematics::numbers::natural cardinality (void) const;
					//const LIB::mathematics::numbers::natural count (void) const;
					//const LIB::mathematics::numbers::natural magnitude (void) const;
					const LIB::mathematics::numbers::natural size (void) const;
					
					const bool empty (void) const;
					//const bool run (const bool &/* = true*/);
					//LIB::NAME_A <bool, std::string> * List (void);
					//const bool & active/*ning*/ (void) const;
					
					// LIB::network::mpi mpi_keepalive, mpi_discovery;
					
					//LIB::NAME_A <bool, std::string> & List (void);
					
					//operator;
					//const LIB::mathematics::numbers::natural local_id (void) const;
					//const LIB::cluster::machine local (void) const;
					
					// Dereference; get the list.
					// const LIB::NAME_A <LIB::cluster::member, LIB::mathemathics::numbers::natural> & operator * (void) const;
					// const LIB::NAME_A <LIB::cluster::member, LIB::mathemathics::numbers::natural> & operator -> (void) const;
					// const LIB::NAME_A <LIB::cluster::member, LIB::mathemathics::numbers::natural> & operator () (void) const;
					const LIB::containers::NAME_A <member, LIB::mathemathics::numbers::natural> & list (void) const;
					
					// receive, listen, handle, manage
					void receive (LIB::containers::NTT <>/* remote_endpoint*/, const LIB::communication::message &/* message*/);
					//void dummy (void) const;
					
					//LIB::tools::randomizer randomizer;
					LIB::network::mpi mpi;
				protected:
					LIB::mathematics::numbers::natural id_local;	// The ID of the local (literal) machine.
					//LIB::cluster::machine * local_machine;	// The local machine.
					
					//LIB::NAME_A <conflict, LIB::mathematics::numbers::natural> conflicts;
					//LIB::NAME_A <communication, LIB::mathematics::numbers::natural> communications;
					
					const LIB::mathematics::numbers::natural id_generate (void) const;
					static const std::string network_received (const LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_A <std::string, std::string>, LIB::mathematics::numbers::natural>, std::string> &/* addresses*/, const std::string &/* address*/)/* const*/;
					const LIB::containers::NAME_A <std::string, LIB::mathematics::numbers::natural> networks_disconnected (void) const;
					
					// Communication interface.
					// This should be set from LIB::cluster::cluster::cluster.
					//LIB::network::mpi * mpi;
					//LIB::cluster::cluster * cluster;
					
					//std::string localhost;
					//std::map<std::string, bool> members;
					//bool running;
					//std::map<std::string, bool> members;
					// LIB::NAME_A <bool /*Value (Online/Offline)*/, std::string /*Key (IP address)*/> peers;
					LIB::containers::NAME_A <member/* Member. */, LIB::mathemathics::numbers::natural/* ID. */> _members;
					//map <std::string, bool> peers;
					//LIB::NAME_A <std::string /*Value (IP address)*/, Mathematics::Number::Natural /*Key: Index*/> members;
					//LIB::NAME_A <Mathematics::Number::Natural, > members;
					// bool confirm;
					// string answer;
					
					// LIB::NAME_A <LIB::NAME_A <conflict, std::string>, LIB::mathematics::numbers::natural> conflicts;
					
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
					// void keepalive_request (void);
					// void keepalive_respond (void);
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
					
					void distribute (void);
					boost::thread * distribution;
					//boost::thread distribution (boost::bind (& LIB::cluster::members::distribute, this));
					
					const bool broadcast (LIB::communication::message, const LIB::containers::NTT <> &) const;
					const bool transmit (const LIB::communication::message &, const member &) const;
					const std::string communicate (const LIB::communication::message &, const member &) const;
				public:
					const bool transmit (const LIB::communication::message &, const LIB::mathematics::numbers::natural &/* id*/) const;
					const std::string communicate (const LIB::communication::message &, const LIB::mathematics::numbers::natural &/* id*/) const;
					const bool broadcast (const LIB::communication::message &) const;
					const std::string communicate_mass (const LIB::communication::message &) const;
					// For the keep-alive/discovery timer.
					//boost::asio::io_service io;
					//boost::asio::deadline_timer timer (io);
					// In microseconds (1 µs = 0.000 001 s).
					//boost::mutex mutex_timeout_timer;
					//boost::condition_variable condition_variable_timeout_timer;
					
					//bool _active;
			};
	}
}

//#include "../cluster.h++"
//#include "machine.h++"
