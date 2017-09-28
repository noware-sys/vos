#pragma once

//#include <string>

class cmd
	: virtual public dev
{
	public:
		cmd (void);
		virtual ~cmd (void);
		
		static const std::string grp_dft;
		
		virtual const bool set (const std::string &/* value*/);
		virtual const std::string get (const char &/* delimiter*/ = '\n');
		
	//protected:
		virtual const bool/* success*/ respond (const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const zmq::msg &/* rx'd*/, zmq::msg &/* response*/);
		virtual const bool/* success*/ search (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/);// const
		virtual const bool/* success*/ search_local (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/);// const
	//	virtual const zmq::msg/* result*/ aggregate (const zmq::msg &/* result*/, const noware::nr &/* responses_count*//* number of peers who answered*/, const zmq::msg &/* response*/, const zmq::msg &/* expression*/);
};
