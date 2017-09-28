#pragma once

class screen
	: public dev
{
	public:
		queue (void);
		virtual ~queue (void);
		
		static const std::string grp_dft;
		
		// dequeue beginning first head top pop next current present fetch operate
		virtual const std::string next (void) const;
		// get the next element and dequeue
		virtual const std::string next_dequeue (void);
		virtual const bool dequeue (void);
		virtual const bool enqueue (const std::string &/* element*/);
		virtual const noware::nr size (void) const;
		virtual const bool empty (void) const;
		virtual const bool empty_local (void) const;
		virtual const bool full (void) const;
		virtual const bool full_local (void) const;
		
	protected:
		virtual const bool/* success*/ respond (const zyre_event_t */* (zyre) event*/);
		virtual const bool/* success*/ search (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/);// const
		virtual const bool/* success*/ search_local (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/);// const
		virtual const zmq::msg/* result*/ aggregate (const zmq::msg &/* result*/, const noware::nr &/* responses_count*//* number of peers who answered*/, const zmq::msg &/* response*/, const zmq::msg &/* expression*/);
		
	protected:
		std::queue <std::string> queue;
};
