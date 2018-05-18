#pragma once

//#include "../net/cast.hxx"
//#include <string>
//#include <zmq/msg.hxx>
//#include <zyre.h>
//#include <zyre.hxx>
#include <noware/net/node.hxx>
//#include <cln/nr.hxx>

namespace noware
{
	// TODO?: rename cmach -> umach (user machine)
	// Place in another project (kernel/os?)?
	namespace cmach
	{
		// client of multiple physical resources
		// the instances this client creates a virtual resource
		
		// resource rsrc rsc
		// device dev
		class dev
			//: misc::instance
			//: pmach::dev
			: virtual public net::node
		{
			public:
				//dev (void);
				//virtual ~dev (void);
				
				static const std::string grp_dft;
				//static const cln::nr token_size_dft;
				
				virtual bool const start (void);
				
				// to be implemented by the inheriting, device-specific, class
				// evaluate expression
				//virtual std::string const val (std::string const &/* xpr*/);
				
			protected:
				//
				// Only these functions
				// need to be implemented
				// by the inheriting class:
				//
				////virtual const noware::tree <>/* response*/ respond (const noware::tree <> &/* message*/);
				//virtual const bool/* success*/ respond (const /*zmq::msg &*/zmsg_t */* message*/, const zyre_event_t */* (zyre) event*/);
				
				// handle request
			//	virtual const bool/* success*/ respond (zmq::msg &/* response*/, const zmq::msg &/* rx'd*/, const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const std::string &/* src*/, const net::cast &/* src_cast*/);
			//	virtual const bool/* success*/ respond_post (const zmq::msg &/* response (read-only)*/, const zmq::msg &/* rx'd*/, const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const std::string &/* src*/, const net::cast &/* src_cast*/, const bool &/* result*/);
				//virtual const bool/* success*/ rx_response (const zyre_event_t */* (zyre) event*/);
				//virtual const bool/* success*/ rx_request (const zyre_event_t */* (zyre) event*/);
				//virtual const bool/* success*/ request (const zyre_event_t */* (zyre) event*/);
			////	virtual const bool/* success*/ infrastruct (const zmq::msg &/* rx'd*/, const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const std::string &/* src*/, const net::cast &/* src_cast*/);
				//virtual const bool/* success*/ infrastruct (const zmq::msg &/* rx'd*/, const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/);
			//	virtual const bool/* success*/ infrastruct (const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/);
				// handle reply
				virtual bool const/* success*/ search (zmq::msg &/* result*/, zmq::msg const &/* message/expression*/, cln::nr const &/* total, expected resonses count*/, cln::nr const &/* current count of peers who responded (so far)*/, std::string const &/* src*/, net::cast const &/* src_cast*/);// const
			//	virtual const bool/* success*/ search_local (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/, const std::string &/* src*/, const net::cast &/* src_cast*/);// const
			//	virtual const zmq::msg/* result*/ aggregate (const zmq::msg &/* result*/, const zmq::msg &/* response*/, const zmq::msg &/* expression*/, const cln::nr &/* responses_count*//* number of peers who answered*/, const std::string &/* src*/, const net::cast &/* src_cast*/);
		};
	}
}
