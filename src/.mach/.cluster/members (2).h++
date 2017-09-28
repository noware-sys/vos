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
		
			class members : public LIB::communication::messaging
			{
				public:
					friend class boost::serialization::access;
					
					template <typename archive>
					void serialize (archive & /* Archive (stream). */, const unsigned int &/* Version. */);
					
					//template <typename Archive>
					//void save (Archive &/* Archive (stream). */, const unsigned int &/* Version. */) const;
					//
					//template <typename Archive>
					//void load (Archive &/* Archive (stream). */, const unsigned int &/* Version. */);
					
					// For resolving ID conflicts.
					class conflict
					{
						public:
							conflict (void);
							~conflict (void);
							
							bool response;
							boost::asio::deadline_timer * timer;
							
							//LIB::NAME_A <LIB::NAME_A <bool, std::string>, LIB::mathematics::numbers::natural> response;
							//LIB::NAME_A <LIB::NAME_A <boost::asio::io_service, std::string>, LIB::mathematics::numbers::natural> io;
							//LIB::NAME_A <LIB::NAME_A <boost::asio::deadline_timer *, std::string>, LIB::mathematics::numbers::natural> timer;
						//protected:
							boost::asio::io_service io;
					};
					/*
					// For resolving ID conflicts.
					class conflict
					{
						public:
							conflict (void);
							~conflict (void);
							
							LIB::NAME_A <bool, std::string> response;
							LIB::NAME_A <boost::asio::io_service, std::string> io;
							LIB::NAME_A <boost::asio::deadline_timer *, std::string> timer;

							//LIB::NAME_A <LIB::NAME_A <bool, std::string>, LIB::mathematics::numbers::natural> response;
							//LIB::NAME_A <LIB::NAME_A <boost::asio::io_service, std::string>, LIB::mathematics::numbers::natural> io;
							//LIB::NAME_A <LIB::NAME_A <boost::asio::deadline_timer *, std::string>, LIB::mathematics::numbers::natural> timer;
					};
					*/
					class communication
					{
						public:
							~communication (void);
							
							std::mutex lock;
							LIB::NTT <> data;
					};
					
					members (void/*const LIB::mathematics::numbers::natural &*//* keepalive time (milliseconds)*//* = 15000*/);
					~members (void);
					
					//friend class LIB::cluster::cluster;
					
					LIB::mathematics::numbers::natural
						keepalive = 15000,	// Time (milliseconds) between online checks among nodes.
						//timeout		// Time (milliseconds) to wait before a node is declared offline.
						//delay		// Discovery delay.
						delay_max = 3000 // milliseconds
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
					const LIB::NAME_A <LIB::cluster::member, LIB::mathemathics::numbers::natural> & operator * (void) const;
					const LIB::NAME_A <LIB::cluster::member, LIB::mathemathics::numbers::natural> & operator -> (void) const;
					const LIB::NAME_A <LIB::cluster::member, LIB::mathemathics::numbers::natural> & operator () (void) const;
					const LIB::NAME_A <LIB::cluster::member, LIB::mathemathics::numbers::natural> & list (void) const;
					
					
					void input (LIB::entity <>/* remote_endpoint*/, const std::string &/* message*/);
					void dummy (void) const;
					
					LIB::tools::randomizer randomizer;
				protected:
					LIB::mathematics::numbers::natural local;	// The ID of the local (literal) machine.
					//LIB::cluster::machine * local_machine;	// The local machine.
					
					LIB::NAME_A <conflict, LIB::mathematics::numbers::natural> conflicts;
					LIB::NAME_A <communication, LIB::mathematics::numbers::natural> communications;
					
					// Communication interface.
					// This should be set from LIB::cluster::cluster::cluster.
					//LIB::network::mpi * mpi;
					// LIB::network::mpi mpi;
					//LIB::cluster::cluster * cluster;
					
					//std::string localhost;
					//std::map<std::string, bool> members;
					//bool running;
					//std::map<std::string, bool> members;
					// LIB::NAME_A <bool /*Value (Online/Offline)*/, std::string /*Key (IP address)*/> peers;
					LIB::NAME_A <LIB::cluster::member /* Member. */, LIB::mathemathics::numbers::natural/* ID. */> _members;
					//map <std::string, bool> peers;
					//LIB::NAME_A <std::string /*Value (IP address)*/, Mathematics::Number::Natural /*Key: Index*/> members;
					//LIB::NAME_A <Mathematics::Number::Natural, > members;
					// bool confirm;
					// string answer;
					
					LIB::NAME_A <LIB::NAME_A <conflict, std::string>, LIB::mathematics::numbers::natural> conflicts;
					
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
					//boost::thread * distribution;
					boost::thread distribution (boost::bind (& LIB::cluster::members::distribute, this));
					
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
