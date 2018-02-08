#pragma once
////#ifndef __MACHINE
////#define __MACHINE
//
//// Standard:
//#include <string>
//#include <sstream>
//
//// Boost:
////#include <boost/any.hpp>
//#include <boost/asio.hpp>
//#include <boost/bind.hpp>
//#include <boost/thread.hpp>
//#include <boost/thread/mutex.hpp>
//#include <boost/thread/condition_variable.hpp>
//
//// This library:
////#include "Lexical_Analyzer"
//#include "../default.h++"
// #include "name.h++"
// #include "cotainer/null.h++"
////#include "peers.h++"
//#include "../containers/array.h++"
// #include "container/any.hxx"
//#include "../containers/memory.h++"
// #include "container/entity_2.hxx"
//#include "../mathematics.h++"	// "mathematics.h++" should be included after "array.h++" in this "machine.h++" file.
//#include "../machine/resource.h++"
////#include "../machine/resources.h++"
//#include "../machine/resources/memory.h++"
//#include "../machine/resources/processor.h++"
////#include "members.h++"
//// #include "../containers/entity.h++"
////#include "../network/ip/mpi.h++"
// #include "net/mpi.hxx"
// #include "computer.hxx"
////#include "../language/interpreter.h++"
//#include "../communication/messaging.h++"
//#include "../cluster/members.h++"
////#include "../cluster.h++"
//#include "network.h++"
//#include ".machine/header.hxx"
//
////#ifndef NTT
////	#define NTT entity
////#endif

//#include "list.hdr.cxx"

/*
// For device.
#include "var.hxx"
#include "net/node.hxx"
#include "nr.hxx"
//// For devices.
//#include <zmqpp/zmqpp.hpp>
*/

/*
// For storage
#include <imatix/zyre/zyre.h>
#include <zmq.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
//#include <boost/function_equal.hpp>
#include <boost/thread/mutex.hpp>
#include <cstring>	// For std::memcpy()
*/
#include "pmach/store.hxx"
#include "vmach/store.hxx"
#include "cmach/store.hxx"

//// For storage::sqlite
//#include "container/list/sqlite.hdr.cxx"

//#include <zmq/msg.hxx>

//#include ".mach/.incl.hxx"

namespace noware
{
	// calculator computer mach[ine] robot
	// dev[ice]
	class mach
		//: virutal public dev
		//: virutal public mach::store
		//, virutal public mach::queue
	{
		/*
			1. Resource Presentation/Aggregation/Sharing (Server) -- Machine (Physical Machine)
			2. Virtual Machine (Client) -- Machine (Software/Virtual Machine/OS)
			3. Logic (Applied Usage) -- Calculator/Computer (Software/OS/Application)
		*/
		
		public:
			//#include ".mach/.hxx"
			
			mach (void);
			virtual ~mach (void);
		
		public:
			
			//store _store;
			std::map <unsigned int, smach::store> _sstore;
			std::map <unsigned int, mmach::store> _mstore;
			std::map <unsigned int, cmach::store> _cstore;
			
			//queue _queue;
			//std::map <unsigned int, queue> _queue;
			
			//cpu _cpu;
			//std::map <unsigned int, cpu> _cpu;
			
			
			//std::map <std::string, thread *> trd;
			//thread trd;
			
			/*
			store s1, s2;
			queue q1, q2;
			cpu p1, p2;
			*/
	};
}

//#include ".machine/footer.hxx"
