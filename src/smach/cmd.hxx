#pragma once

#include "dev.hxx"
#include <string>
#include <cln/nr.hxx>

namespace noware
{
	namespace smach
	{
		class cmd
			: virtual public dev
			//: virtual public cluster::node
		{
			public:
				cmd (void);
				virtual ~cmd (void);
				
				virtual bool const start (void);
				
				std::string const static grp_dft;
				
				virtual const bool set (const std::string &/* value*/);
				virtual const std::string get (const char &/* delimiter*/ = '\n');
				
			//protected:
				//virtual const bool/* success*/ respond (const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const zmq::msg &/* rx'd*/, zmq::msg &/* response*/);
				virtual const bool/* success*/ respond (zmq::msg &/* response*/, const zmq::msg &/* rx'd*/, const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const std::string &/* src*/, const net::cast &/* src_cast*/);
				//virtual const bool/* success*/ search (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/);// const
				virtual const bool/* success*/ search (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/, const cln::nr &/* total, expected resonses count*/, const cln::nr &/* current count of peers who responded (so far)*/, const std::string &/* src*/, const net::cast &/* src_cast*/);// const
				//virtual const bool/* success*/ search_local (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/);// const
				virtual const bool/* success*/ search_local (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/, const std::string &/* src*/, const net::cast &/* src_cast*/);// const
			//	virtual const zmq::msg/* result*/ aggregate (const zmq::msg &/* result*/, const cln::nr &/* responses_count*//* number of peers who answered*/, const zmq::msg &/* response*/, const zmq::msg &/* expression*/);
			protected:
				virtual bool const cout (std::string const &/* value*/);
				virtual bool const cin (std::string &/* value*/, char const &/* delimiter*/ = '\n');
		};
	}
}
