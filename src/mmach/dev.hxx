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
	// Place in another project (kernel/os?)?
	namespace mmach
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
				dev (void);
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
				virtual bool const/* success*/ respond (zmq::msg &/* response*/, zmq::msg const &/* rx'd*/, zyre_event_t const * const/* (zyre) event*/, std::string const &/* event_type*/, std::string const &/* src*/, net::cast const &/* src_cast*/);
		//		virtual bool const/* success*/ respond_post (zmq::msg const &/* response (read-only)*/, zmq::msg const &/* rx'd*/, zyre_event_t const * const/* (zyre) event*/, std::string const &/* event_type*/, std::string const &/* src*/, net::cast const &/* src_cast*/, bool const &/* result*/);
				//virtual const bool/* success*/ rx_response (const zyre_event_t */* (zyre) event*/);
				//virtual const bool/* success*/ rx_request (const zyre_event_t */* (zyre) event*/);
				//virtual const bool/* success*/ request (const zyre_event_t */* (zyre) event*/);
		//	//	virtual const bool/* success*/ infrastruct (const zmq::msg &/* rx'd*/, const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const std::string &/* src*/, const net::cast &/* src_cast*/);
				//virtual const bool/* success*/ infrastruct (const zmq::msg &/* rx'd*/, const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/);
		//		virtual bool const/* success*/ infrastruct (zyre_event_t const * const/* (zyre) event*/, std::string const &/* event_type*/);
				// handle reply
				virtual bool const/* success*/ search (zmq::msg &/* result*/, zmq::msg const &/* message/expression*/, cln::nr const &/* total, expected resonses count*/, cln::nr const &/* current count of peers who responded (so far)*/, std::string const &/* src*/, net::cast const &/* src_cast*/);// const
		//		virtual bool const/* success*/ search_local (zmq::msg &/* result*/, zmq::msg const &/* message/expression*/, std::string const &/* src*/, net::cast const &/* src_cast*/);// const
		//		virtual zmq::msg const/* result*/ aggregate (zmq::msg const &/* result*/, zmq::msg const &/* response*/, zmq::msg const &/* expression*/, cln::nr const &/* responses_count*//* number of peers who answered*/, std::string const &/* src*/, net::cast const &/* src_cast*/);
		};
	}
}
