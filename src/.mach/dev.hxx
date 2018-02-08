#pragma once

//#include "../var.hdr.cxx"

//namespace noware
//{
	// Place in another project (kernel/os)?
	//namespace machine
	//{
			// resource rsrc rsc
			// device dev
			class dev //: misc::instance
			{
				public:
					dev (void);
					virtual ~dev (void);
					
					virtual bool const fin (void);
					virtual bool const inited (void) const;
					virtual bool const init (void);
					
					virtual bool const stop (void);
					virtual bool const running (void) const;
					virtual bool const start (void);
					
					// Could be reimplemented in the inheriting, device-specific, class.
					virtual bool const disable (void);
					virtual bool const enabled (void) const;
					virtual bool const enable (void);
					
					// evaluate expression
					virtual std::string const val (std::string const &/* xpr*/);
					
				//protected:
					//static net::cluster nodes;
					//net::node node;
					/*zmq::*/zyre _node;
				//protected:
				//private:
					// Manager of received messages.
					virtual void rx (zyre_event_t * const/* zyre_event*/);
					
					
					// Receives the response from the query.
					//virtual const noware::var receive_local (const std::string &/* response_type*/, const std::string &/* filter*/ = "") const;
					//virtual const zmq::msg receive_local (cln::nr &/* responses_count*//* number of peers who answered*/, const std::string &/* (zyre) group (to receive from (where the message was sent to))*/ = /*noware::machine::device::*/grp_dft) const;
					virtual const zmq::msg receive_local (const std::string &/* request_token*/, const cln::nr &/* number of expected responses*/, cln::nr &/* responses_count*//* number of peers who actually answered*/, const std::string &/* src*/, const net::cast &/* src_cast*/) const;
					
					// Transmits/Redirect the response to the thread who queried it.
					//virtual const bool unicast_local (const zmq::msg &/* message*/) const;
					virtual const bool unicast_local (const zmq::msg &/* message*/, const std::string &/* request_token*/) const;
					//virtual const bool unicast_local (const zmsg_t */* message*/) const;
					
					static std::string const grp_dft;
					static cln::nr const token_size_dft;
					
					// Internal proxy
					//zmq::context_t * local_context;
					////zmq::context_t local_context {1};
					//zmq::socket_t * local_socket;
					////void local_reception (void);
					
					//
					// Only these functions
					// need to be implemented
					// by the inheriting class:
					//
					////virtual const noware::tree <>/* response*/ respond (const noware::tree <> &/* message*/);
					//virtual const bool/* success*/ respond (const /*zmq::msg &*/zmsg_t */* message*/, const zyre_event_t */* (zyre) event*/);
					
					virtual const bool/* success*/ respond (zmq::msg &/* response*/, const zmq::msg &/* rx'd*/, const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const std::string &/* src*/, const net::cast &/* src_cast*/);
					virtual const bool/* success*/ respond_post (const zmq::msg &/* response (read-only)*/, const zmq::msg &/* rx'd*/, const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const std::string &/* src*/, const net::cast &/* src_cast*/, const bool &/* result*/);
					//virtual const bool/* success*/ rx_response (const zyre_event_t */* (zyre) event*/);
					//virtual const bool/* success*/ rx_request (const zyre_event_t */* (zyre) event*/);
					//virtual const bool/* success*/ request (const zyre_event_t */* (zyre) event*/);
				//	virtual const bool/* success*/ infrastruct (const zmq::msg &/* rx'd*/, const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const std::string &/* src*/, const net::cast &/* src_cast*/);
					//virtual const bool/* success*/ infrastruct (const zmq::msg &/* rx'd*/, const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/);
					virtual const bool/* success*/ infrastruct (const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/);
					virtual const bool/* success*/ search (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/, const cln::nr &/* total, expected resonses count*/, const cln::nr &/* current count of peers who responded (so far)*/, const std::string &/* src*/, const net::cast &/* src_cast*/);// const
					virtual const bool/* success*/ search_local (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/, const std::string &/* src*/, const net::cast &/* src_cast*/);// const
					virtual const zmq::msg/* result*/ aggregate (const zmq::msg &/* result*/, const zmq::msg &/* response*/, const zmq::msg &/* expression*/, const cln::nr &/* responses_count*//* number of peers who answered*/, const std::string &/* src*/, const net::cast &/* src_cast*/);
			};
	//}
//}
