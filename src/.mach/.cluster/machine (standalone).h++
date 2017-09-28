#pragma once
//#ifndef __MACHINE
//#define __MACHINE

// Standard:
#include <string>
#include <sstream>

// Boost:
#include <boost/any.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>

// This library:
//#include "Lexical_Analyzer"
//#include "../default.h++"
//#include "peers.h++"
#include "../containers/array.h++"
#include "../mathematics.h++"	// "mathematics.h++" should be included after "array.h++" in this "machine.h++" file.
#include "../machine/resource.h++"
#include "../machine/resources/memory.h++"
#include "../machine/resources/processor.h++"
//#include "../machine/resources.h++"
//#include "members.h++"
#include "../containers/entity.h++"
//#include "../network/ip/mpi.h++"
#include "../network/mpi.h++"
#include "../language/interpreter.h++"
#include "../communication/message.h++"

namespace LIB
{
	namespace cluster
	{
		class machine
		{
			public:
				machine (void);
				~ machine (void);
				
				enum type
				{
					literal,
					reference
				};
				
				//enum operation
				//{
				//};
				
				/*
				class paths
				{
					public:
						mathematics::numbers::natural best;
						
						// The paths to get to this machine.
						LIB::NAME_A <LIB::NAME_A <LIB::NAME_V, mathematics::numbers::natural>, mathematics::numbers::natural> paths;
				};
				*/
				//using namespace LIB;
				/*
				class container
				{
					public:
						enum type
						{
							variable,
							string,
							number
						};
						
						//container (void);
						//container (const container &);
						
						type t;
						
						boost::any content;
				};
				*/
				//LIB::machine::devices::processor cpu;
				
				// LIB::NAME_A <machine *, mathematics::numbers::natural> peers;
				const LIB::NAME_A <machine *, mathematics::numbers::natural> * peers (const bool &/* Recursive. */ = false);
				//members membs;
				
				//class process
				//{
				//};
				
				//void run (const bool & = false);
				
				//// Connections with peers.
				// Transfer to a network device (implementation)?
				//LIB::NAME_A <LIB::NAME_A <std::string, /*LIB::mathematics::numbers::*/natural>, /*LIB::mathematics::numbers::*/natural> connections;
				
				//LIB::machine::resources rscs;
				//LIB::NAME_A <LIB::machine::resources::resource> rscs;
				// LIB::NAME_A <LIB::machine::resource *> resources;
				
				//LIB::cluster::memory memory;
				//LIB::machine::devices::processor _processor;
				//processor.
				
				// Enqueue instructions.
				// bool enqueue (const std::string &/* file_name*/);
				//bool enqueue (const LIB::cluster::devices::processor::instructions & /* A queue of instruction. */);
				//bool enqueue (const LIB::cluster::devices::processor::instruction & /* A single instruction. */);
				
				//bool parse (const std::string);
				
				// Provide read-only access:
				//const LIB::NAME_A <std::string, std::string> & get_error (void) const;
				// std::string get_error_code (void);
				// std::string get_error_message (void);
				
				//const bool set (const std::string &/* name*/, const boost::any &/* value*/, const std::string &/* group*/ = "");
				//const bool get (const std::string &/* name*/, const boost::any &/* value*/, const std::string &/* group*/ = "") const;
				//const bool exist (const std::string &/* name*/, const std::string &/* group*/ = "") const;
				//const bool rename (const std::string &/* name*/, const std::string &/* new name*/, const std::string &/* group*/ = "", const std::string &/* new group*/ = "");
				//const bool unset (const std::string &/* name*/, const std::string &/* group*/ = "");
				//const LIB::NAME_A <LIB::machine::resource> & resources (const bool &/* Include peers. */ = false, const bool &/* Include peers' peers (effect: recursion). */ = false);
				const LIB::NAME_A <LIB::machine::resource> resources (const bool &/* Include from all members. */ = false);
				//const machine * & operator [] (const mathematics::numbers::natural &);
				
				const type & get_type (void) const;
				const bool run (const bool & = true);
				
				//// Allow access to "mpi".
				//friend class LIB::machine::resource;
				const LIB::network::mpi * & get_mpi (void) const;
				
				// Manage outgoing point-to-point message.
				const bool send (const communication::message &, const mathematics::numbers::natural &/* ID. */) const;
				const bool send (const communication::message &, const LIB::entity <std::string, mathematics::numbers::natural> &/* Addresses of one endpoint. */) const;
				// Manage outgoing point-to-multi-point message.
				const bool broadcast (const communication::message &) const;
				const bool broadcast (const communication::message &, const LIB::entity <mathematics::numbers::natural, mathematics::numbers::natural> &/* Identifications. */ &) const;
				
				// Manage incoming point-to-point message.
				void receive (const std::string &/* Message. */);
				// Manage incoming point-to-multi-point message.
				void listen (const std::string &/* Message. */);
			protected:
				bool
					running
					,
					* main_timeout_timer_running
					,
					timeout_timer_running
					,
					responded	// If this machine has responded before timing out. For keeping alive.
				;
				
				type t;
				
				// Communication interface.
				LIB::network::mpi * mpi;
				
				// Resources (local and remote).
				LIB::NAME_A <LIB::machine::resource> rscs;
				// LIB::entity <boost::any, std::string> entities;
				//LIB::entity <container, std::string> entities;
				
				// LIB::language::interpreter interpreter_;
				// LIB::NAME_A <std::string, std::string> error;
				
				// Unique identifier.
				mathematics::numbers::natural id;
				
				// Peers (which are directly connected and indirectly connected to this machine).
				LIB::NAME_A <machine *, mathematics::numbers::natural> * machines;
				void machines_clear (void);
				// The path to get to this machine.
				// This is only the best path,even if there are multiple ones.
				// It lists the steps to get to it from the owner of the object.
				LIB::NAME_A <LIB::NAME_V, mathematics::numbers::natural> path;
				
				// Get the next available unique ID.
				mathematics::numbers::natural next_id (void) const;
				
				void scan (void);
				boost::thread * scanning, * time_timer_wait_thread;
				
				// For the keep-alive/discovery timer.
				boost::asio::io_service io_service;
				boost::asio::deadline_timer scanning_timer (io_service);
				// In microseconds (1 µs = 0.000 001 s).
				mathematics::numbers::natural keepalive, timeout;
				
				boost::mutex * mutex_timeout_timer;
				boost::condition_variable * condition_variable_timeout_timer;
				
				//// Start the timeout timer.
				//void timeout_time_run (void);
				void timeout_pause (void);
		};
		
		//class machine
		//{
		//	public:
		//		
		//};
	}
}

//#endif
