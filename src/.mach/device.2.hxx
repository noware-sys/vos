//#pragma once

//#include "../var.hdr.cxx"

//namespace noware
//{
	// Place in another project (kernel/os)?
	//namespace machine
	//{
			class device //: misc::instance
			{
				public:
					device (void);
					virtual ~device (void);
					
					//virtual const noware::var evaluate (const noware::var &/* expression*/);
					virtual const noware::var/* value*/ evaluate (const noware::tree <> &/* expression*/, const std::string &/* (zyre) group*/ = group_default);
					
					//virtual const noware::var/* value*/ get (const noware::var &/* key*/) const;
					//virtual const bool/* success*/ set (const noware::var &/* key*/, const noware::var &/* value*/);
					
					// Transmit a message to one node.
					virtual const noware::var/* response*/ unicast (const noware::tree <> &/* message*/, const std::string &/* peer (id)*/);
					
					// Transmit a message to multiple nodes.
					// Main usage: request other nodes to perform an operation.
					virtual const noware::var/* response*/ multicast (const noware::tree <> &/* message*/, noware::nr::natural &/* responses_count*//* number of peers who answered*/, const std::string &/* (zyre) group*/ = /*noware::machine::device::*/group_default, const std::string &/* filter*/ = "");
					
					static const noware::var group_default;
				//protected:
					//static net::cluster nodes;
					net::node node;
				//protected:
					//virtual const noware::tree <>/* response*/ respond (const noware::tree <> &/* message*/);
					virtual const bool/* success*/ respond (const noware::tree <> &/* message*/, const zyre_event_t */* (zyre) event*/);
					virtual const bool/* success*/ search (noware::var &/* result*/, const noware::tree <> &/* message/expression*/);// const
					virtual const bool/* success*/ search_local (noware::var &/* result*/, const noware::tree <> &/* message/expression*/);// const
					virtual const noware::var/* result*/ aggregate (const noware::var &/* result*/, noware::nr::natural &/* responses_count*//* number of peers who answered*/, const noware::var &/* response*/, const noware::tree <> &/* expression*/);
				//private:
					// Manager of received messages.
					virtual void receive (const zyre_event_t */* zyre_event*/);
					
					// Receives responses from queries.
					//virtual const noware::var receive_local (const std::string &/* response_type*/, const std::string &/* filter*/ = "") const;
					virtual const noware::var receive_local (noware::nr::natural &/* responses_count*//* number of peers who answered*/, const std::string &/* (zyre) group (to receive from (where the message was sent to))*/ = /*noware::machine::device::*/group_default, const std::string &/* ^filter*/ = "") const;
					
					// Transmits responses to the thread who queried.
					virtual const bool unicast_local (const noware::tree <> &/* message*/) const;
			};
	//}
//}
