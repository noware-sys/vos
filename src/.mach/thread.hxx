#pragma once

class thread
	: public dev
{
	public:
		thread (void);
		virtual ~thread (void);
		
		//static const std::string grp_dft;
		
		virtual const std::string id (void) const;
		virtual const std::string group (void) const;
		
		virtual const bool stop (void);
		virtual const bool status (void) const;
		virtual const bool start (void);
		
		virtual const bool load (const std::string &/* file_name*/);
		virtual const bool loaded (void) const;
		virtual const bool clear (void);
	protected:
		virtual const bool/* success*/ respond (const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const zmq::msg &/* rx'd*/, zmq::msg &/* response*/);
		virtual const bool/* success*/ search (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/);// const
		virtual const bool/* success*/ search_local (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/);// const
		virtual const zmq::msg/* result*/ aggregate (const zmq::msg &/* result*/, const noware::nr &/* responses_count*//* number of peers who answered*/, const zmq::msg &/* response*/, const zmq::msg &/* expression*/);
		
	protected:
		std::map <unsigned int, cpu::instr> instr;
		
		std::string grp;
		//noware::nr id;
		// current index ndx
		unsigned int ndx;
		bool main;
		bool running;
		bool _loaded;
		
		virtual const bool advance_local (void);
		virtual const bool advance (void);
		virtual const bool enqueue (const cpu::instr &/* element*/);
};
