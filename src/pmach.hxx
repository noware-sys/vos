#pragma once

#include <zmq/msg.hxx>

#include "mach.hxx"
//#include ".mach/.incl.hxx"

namespace noware
{
	/*
	class mach
	{
		public:
			class store;
			class queue;
	};
	*/
	//class mach;
	
	// calculator computer p[hysical_]mach[ine] robot
	// dev[ice]
	class pmach
		//: public dev
		: public mach::store
		, public mach::queue
	{
		/*
			1. Resource Presentation/Aggregation/Sharing (Server) -- Machine (Physical Machine)
			2. Virtual Machine (Client) -- Machine (Software/Virtual Machine/OS)
			3. Logic (Applied Usage) -- Calculator/Computer (Software/OS/Application)
		*/
		
		public:
			//#include ".mach/.hxx"
			
			pmach (void);
			virtual ~pmach (void);
			
			// do evaluate calculate compute solve perform process execute query enqueue go ok request demand command input
			//const LIB::containers::NAME_V query (const LIB::containers::NAME_V &);
			//const bool evaluate (const LIB::containers::NAME_V &);
		//	const LIB::container::NAME_V evaluate (const LIB::container::NAME_V &);
			
			//const bool enqueue (const std::string &/* file_name*/);
			
			// copies copy redundancy
			//const noware::nr redundancy (void) const;
			//const bool redundancy (const noware::nr);
			
			//computer computer;
			
			const bool stop (void);
			const bool running (void) const;
			const bool start (void);
			
			virtual const bool empty (void) const;
			virtual const bool empty_local (void) const;
			virtual const bool full (void) const;
			virtual const bool full_local (void) const;
			
			virtual const noware::nr count (void) const;
			
			virtual const bool load_file (const std::string &/* file_name*/);
			
		protected:
			//virtual const bool/* success*/ respond (const /*zmq::msg &*/zmsg_t */* message*/, const zyre_event_t */* (zyre) event*/);
			virtual const bool/* success*/ respond (zmq::msg &/* response*/, const zmq::msg &/* rx'd*/, const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const std::string &/* src*/, const net::cast &/* src_cast*/);
			virtual const bool/* success*/ respond_post (const zmq::msg &/* response (read-only)*/, const zmq::msg &/* rx'd*/, const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const std::string &/* src*/, const net::cast &/* src_cast*/);
			//virtual const bool/* success*/ infrastruct (const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const zmq::msg &/* rx'd*/);
			virtual const bool/* success*/ search (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/, const std::string &/* src*/, const net::cast &/* src_cast*/);// const
			virtual const bool/* success*/ search_local (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/, const std::string &/* src*/, const net::cast &/* src_cast*/);// const
			virtual const zmq::msg/* result*/ aggregate (const zmq::msg &/* result*/, const zmq::msg &/* response*/, const zmq::msg &/* expression*/, const noware::nr &/* responses_count*//* number of peers who answered*/, const std::string &/* src*/, const net::cast &/* src_cast*/);
			
		protected:
		/*
		public:
			//store _store;
			std::map <unsigned int, store> _store;
			
			//queue _queue;
			std::map <unsigned int, queue> _queue;
			
			//cpu _cpu;
			std::map <unsigned int, cpu> _cpu;
			
			//std::map <std::string, thread *> trd;
			//thread trd;
		*/
			
			// 'EXEcutioN' thread
			// For running "void exe (void)".
			boost::thread * exen;
			
			// executer of instructions
			void exe (void);
			
			//array <device> device;
		//	/*LIB::machine::*//*device::*/processor processor;
				//LIB::container::memory memory;
			//	LIB::container::entity_2 memory;
			//LIB::network::mpi mpi;
			
			//manager mngr;
			//noware::list <manager> mngr;
			//noware::list <storage::sqlite> memory;
			//noware::list <processor> cpu;
			// display sight vision view
			//noware::list <display> view;
			// net network
			//noware::list <net> network;
			
		//public:
		//	#include ".machine/inner footer.hxx"
	};
}

//#include ".machine/footer.hxx"
