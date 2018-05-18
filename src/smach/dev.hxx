#pragma once

#include <noware/net/node.hxx>

namespace noware
{
	// Place in another project (kernel/os)?
	namespace smach
	{
		// server of a generic physical resource
		// resource rsrc rsc
		// device dev
		class dev
			//: misc::instance
			: virtual public net::node
		{
			public:
				//dev (void);
				//virtual ~dev (void);
				
				std::string const static grp_dft;
				
				virtual bool const start (void);
				
				// to be implemented by the inheriting, device-specific, class
				// evaluate expression
				//virtual std::string const val (std::string const &/* xpr*/);
			protected:
				virtual bool const/* success*/ respond (zmq::msg &/* response*/, zmq::msg const &/* rx'd*/, zyre_event_t const * const/* (zyre) event*/, std::string const &/* event_type*/, std::string const &/* src*/, net::cast const &/* src_cast*/);
				
				// Optional:
				virtual bool const/* success*/ respond_post (zmq::msg const &/* response (read-only)*/, zmq::msg const &/* rx'd*/, zyre_event_t const * const/* (zyre) event*/, std::string const &/* event_type*/, std::string const &/* src*/, net::cast const &/* src_cast*/, bool const &/* result*/);
		};
	}
}
