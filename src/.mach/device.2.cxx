//#include "device.hdr.cxx"
#include "../var.cxx"
#include "../net/node.cxx"

const noware::var noware::machine::device::group_default = "";

noware::machine::device::device (void)
{
	node.initialize ();
	node.start ();
	node.reception_set (boost::bind (boost::mem_fn (&noware::machine::device::receive), this, _1));
	
	//nodes.add (node);
}

noware::machine::device::~device (void)
{
	//node.stop ();
	//node.finalize ();
	
	//nodes.remove (node);
}

const noware::var noware::machine::device::evaluate (const noware::tree <> & expression, const std::string & group)
{
	noware::var result;
	
	if (search_local (result, expression))
		return result;
	else
	{
		noware::nr::natural responses_count;
		
		return aggregate (result, responses_count, multicast (expression, responses_count, /*noware::machine::device::*/group, ""), expression);
	}
	
	//return "";
	//if (!nodes.evaluate (expression))
	//	return false;
	//nodes.evaluate (expression);
	//
	//return nodes.respond ();
}

const noware::var noware::machine::device::unicast (const noware::tree <> & message, /*const std::string & filter, */const std::string & peer)
{
	return "";
}

const noware::var noware::machine::device::aggregate (const noware::var & result, noware::nr::natural & responses_count, const noware::var & response, const noware::tree <> & expression)
{
	return response;
}

const noware::var noware::machine::device::multicast (const noware::tree <> & message, noware::nr::natural & responses_count, const std::string & group, const std::string & filter)
{
	std::cout << "noware::machine::device::multicast()::called" << std::endl;
	//if (!message.is_group ())
	//	return "";
	
	
//	std::string filter;
	
//	filter = "";
//	filter += (noware::var) '/' + "response";
	
	//if (message.exists ("subject"))
//		filter += (noware::var) '/' + message ["subject"];
	
	//filter += (noware::var) '/' + message ["type"];
	
	//if (message.exists ("name"))
//		filter += (noware::var) '/' + message ["name"];
	
	//if (message.exists ("content"))
	//	filter += '/' + message ["content"];
	
	// Data, collapsed into a string.
	//message ["filter"] = filter;
	
	if (!node.multicast (/*filter + */message, group))
	{
		std::cout << "noware::machine::device::multicast()::node.multicast()::failure" << std::endl;
		return "";
	}
	
	std::cout << "noware::machine::device::multicast()::node.multicast()::success" << std::endl;
	//return receive_local (message ["subject"].get_value (), filter);
	//return receive_local (message, filter);
	return receive_local (responses_count, group, filter);
	
	/*
	// Prepare for reception.
	zmq::context_t context (1);
	zmq::socket_t receiver (context, ZMQ_SUB);
	receiver.connect ("tcp://127.0.0.1:5555");
	
	// Subscribe only to the answer we asked for.
	receiver.setsockopt (ZMQ_SUBSCRIBE, filter.c_str (), filter.length ());
	
	noware::tree <> response;
	//std::stringstream ss;
	zmq::message_t response_zmq;
	for (;;)
	{
		receiver.recv (&response_zmq);
		//ss << static_cast <char *> (response_zmq.data ());
		// Parse the message into a tree object.
		//response.deserialize (ss.to_string ());
		//response.deserialize (static_cast <char *> (response_zmq.data ()));
		//if ()
		//ss.clear ();
	}
	*/
}

void noware::machine::device::receive (const zyre_event_t * event)
{
	std::cout << "noware::machine::device::receive()::called" << std::endl;
	
	std::string event_type = zyre_event_type (event);
	//noware::tree <> message_zyre;
	//noware::tree <> message;
	
	std::cout << "noware::machine::device::receive()::event_type==[" << event_type << ']' << std::endl;
	
	if (event_type == "WHISPER" || event_type == "SHOUT")
	{
		std::cout << "noware::machine::device::receive()::event_type==(WHISPER||SHOUT)==[" << event_type << ']' << "::in scope" << std::endl;
		
		zmsg_t * zmq_msg;
		
		if (zmq_msg != nullptr)
		{
			std::cout << "noware::machine::device::receive()::zmq_msg!=nullptr" << std::endl;
			//std::string msg;
			noware::tree <> msg;
			
			// First, get the message from the zyre peer.
			zmq_msg = zyre_event_msg (event);
			
			//msg = zmsg_popstr (zmq_msg);
			if (msg.deserialize (zmsg_popstr (zmq_msg)))
			{
				//std::cout << "*zmq_msg==" << '[' << (const char *) zmq_msg << ']' << std::endl;
				//std::cout << "zmsg_popstr(zmq_msg)==" << '[' << zmsg_popstr (zmq_msg) << ']' << std::endl;
				std::cout << "msg.serialize()==" << '[' << msg.serialize () << ']' << std::endl;
				
				
				bool result;
				
				//result = node.unicast (respond (msg), zyre_event_peer_uuid (event));
				result = respond (msg, event);
				
				std::cout << "noware::machine::device::receive()::node.unicast (response, zyre_event_peer_uuid (event)==" << (result ? "Success" : "Failure") << std::endl;
			}
			else
			{
				std::cout << "noware::machine::device::receive()::msg.deserialize()==False" << std::endl;
			}
			//std::cout << "noware::machine::device::receive()::msg[subject]==[" << msg ["subject"] << ']' << std::endl;
		}
		else
		{
			std::cout << "noware::machine::device::receive()::zmq_msg==nullptr" << std::endl;
		}
	}
}

const bool noware::machine::device::respond (const noware::tree <> & message, const zyre_event_t * event)
{
	std::cout << "noware::machine::device::respond()::called" << std::endl;
	
	return false;
}

const noware::var noware::machine::device::receive_local (noware::nr::natural & responses_count, const std::string & group, /*const std::string & response_type, */const std::string & filter) const
{
	std::cout << "noware::machine::device::receive_local(filter==[" << filter << "])::called" << std::endl;
	//std::cout << "noware::machine::device::receive_local(response_type=[" << response_type << "], filter=[" << filter << "])::called" << std::endl;
	
	int bind_return_code;
	
	std::string conn;	// Connection string.
	
	//conn = (std::string) "inproc://" + filter;
	//conn = "inproc://connection1";
	
	std::cout << "noware::machine::device::receive_local()::conn==[" << conn << ']' << std::endl;
	
	zmq::context_t context (1);
	//  Socket to talk to server
	//std::cout << "Collecting updates from weather server...\n" << std::endl;
	//zmq::socket_t receiver (context, ZMQ_SUB);
	//zmq::socket_t receiver (context, ZMQ_PAIR);
	zmq::socket_t receiver (context, ZMQ_REP);
	receiver.bind ("tcp://127.0.0.1:3210");
	//receiver.bind (conn.c_str ());
	//receiver.bind ("tcp://0.0.0.0:5555");
	
	//std::cout << "noware::machine::device::receive_local()::receiver.bind()==[" << bind_return_code << ']' << std::endl;
	
	
	// Subscribe to the filter.
	//receiver.setsockopt (ZMQ_SUBSCRIBE, filter.c_str (), sizeof (filter));
	
	
	// zlist_t * peers;
	
	//assert (zlist_size (peers) == 1);
	//zlist_destroy (&peers);
	
	noware::tree <> message_tree;
	noware::var response;
	//noware::nr::natural n;
	zmq::message_t message_filter;
	zmq::message_t message_content;
	//boost::function <const bool/* search_* */ (const noware::tree <> &/* response_type*/, noware::var &/* filter*/)> search;
	
	/*
	response = "";
	// Decide which search function should be used.
	std::cout << "noware::machine::device::receive_local(response_type=[" << response_type << "], filter=[" << filter << "])::pre-if" << std::endl;
	if (response_type == "get")
	{
	  std::cout << "noware::machine::device::receive_local()::response_type==[" << response_type << ']' << "::in scope" << std::endl;
		search = boost::bind (boost::mem_fn (&noware::machine::device::search_get), this, _1, _2);
		//search = &noware::machine::device::search_get;
	}
	else if (response_type == "set")
	{
	  std::cout << "noware::machine::device::receive_local()::response_type==[" << response_type << ']' << "::in scope" << std::endl;
		search = boost::bind (boost::mem_fn (&noware::machine::device::search_set), this, _1, _2);
		//search = &noware::machine::device::search_set;
	}
	else
	{
	  std::cout << "noware::machine::device::receive_local()::response_type::if-else::in scope" << std::endl;
		return "";
	}
	*/
	
	//std::cout << "noware::machine::device::receive_local(response_type=[" << response_type << "], filter=[" << filter << "])::node.peers_count()==[" << node.peers_count () << ']' << std::endl;
	std::cout << "noware::machine::device::receive_local(filter=[" << filter << "])::node.peers_count()==[" << node.peers_count () << ']' << std::endl;
	
	/*
	//zlist_t * peers;
	peers = zyre_peers (node.zyre ());
	if (peers == nullptr);
	{
		std::cout << "noware::machine::device::receive_local(response_type=[" << response_type << "], filter=[" << filter << "])::peers==nullptr" << std::endl;
		
		return result;
	}
	*/
	// Ensure that all relevant peers respond.
	//n = 0;
	//result = "";
  std::cout << "noware::machine::device::receive_local()::pre-loop" << std::endl;
	for (/*noware::nr::natural n*/responses_count = 0; responses_count < /*zlist_size (peers)*/ node.peers_count (group); ++responses_count)
	{
		std::cout << "noware::machine::device::receive_local()::while::responses_count==[" << responses_count << ']' << std::endl;
		
		//zmq::message_t message_filter;
		//zmq::message_t message_content;
		
		std::cout << "noware::machine::device::receive_local()::loop::receiving::filter" << std::endl;
		receiver.recv (&message_filter);
		std::cout << "noware::machine::device::receive_local()::loop:: received::filter" << std::endl;
		
		std::cout << "noware::machine::device::receive_local()::loop::receiving::message" << std::endl;
		receiver.recv (&message_content);
		std::cout << "noware::machine::device::receive_local()::loop:: received::message" << std::endl;
		
		std::cout << "noware::machine::device::receive_local()::message_tree.deserialize()::pre-call" << std::endl;
		
		std::cout << "noware::machine::device::receive_local()::message_filter.data()==[" << static_cast <const char *> (message_filter.data ())	<< ']' << std::endl;
		
		std::cout << "noware::machine::device::receive_local()::message_content.data()==[" << static_cast <const char *> (message_content.data ()) << ']' << std::endl;
		
		if (!message_tree.deserialize (static_cast <const char *> (message_content.data ())))
		{
			std::cout << "noware::machine::device::receive_local()::message_tree.deserialize()==False" << std::endl;
			return response;
		}
		
		std::cout << "noware::machine::device::receive_local()::message_tree.deserialize()==True" << std::endl;
		// Refresh the list of peers,
		// in case any of them departed the cluster since our previous iteration(s),
		// even if it is improbable.
		/*
		zlist_destroy (&peers);
		//zlist_t * peers;
		peers = zyre_peers (node.zyre ());
		
		if (peers == nullptr)
		{
		  std::cout << "noware::machine::device::receive_local()::in-while::peers==nullptr" << std::endl;
			return "";
		}
		*/
		// React to/Parse the message.
		// search() returns bool/success if we found the (correct) answer that we are searching for.
		// when we haven't yet found the entire answer, we continue;
		// when we fail, we (could) short-circuit the loop (stop looping).
  	std::cout << "noware::machine::device::receive_local()::if(search())::pre-call" << std::endl;
		if (search (response, message_tree))
		{
	  	std::cout << "noware::machine::device::receive_local()::if(search())::break" << std::endl;
			break;
		}
		
		//++n;
	}
  std::cout << "noware::machine::device::receive_local()::post-loop" << std::endl;
	
	//zlist_destroy (&peers);
	
  std::cout << "noware::machine::device::receive_local()::return response==[" << response << ']' << std::endl;
	return response;
	
	//std::istringstream iss(static_cast<char*>(update.data()));
	//std::cout << "Message=" << '[' << static_cast <char *> (update.data ()) << ']' << std::endl;
}

const bool noware::machine::device::unicast_local (const noware::tree <> & msg) const
{
	std::string filter;
	std::string msg_serial;
	std::string conn;	// Connection string.
	//noware::tree <> msg_tree;
	bool result;
	
	filter = "";
	//filter += (noware::var) '/' + "response";
	//msg_tree.deserialize (msg);
	
	//if (msg_tree.exists ("subject"))
//		filter += (noware::var) '/' + msg ["subject"];
	
//	filter += (noware::var) '/' + msg ["type"];
	
	//if (msg_tree.exists ("name"))
//		filter += (noware::var) '/' + msg ["name"];
	
	//if (msg_tree.exists ("content"))
	//	filter += '/' + msg_tree ["content"];
	
	//conn = (std::string) "inproc://" + filter;
	//conn = "inproc://connection1";
	
	std::cout << "noware::machine::device::unicast_local()::msg[content].get_value ().text ()==[" << msg ["content"].get_value ().text () << ']' << std::endl;
	//std::cout << "noware::machine::device::unicast_local()::msg[content].get_value ().text ()==[" << msg ["content"].get_value ().text () << ']' << std::endl;
	
	
	std::cout << "noware::machine::device::unicast_local()::conn==[" << conn << ']' << std::endl;
	
	msg_serial = msg.serialize ();
	
	zmq::context_t context (1);
	//zmq::socket_t transmitter (context, ZMQ_PUB);
	//zmq::socket_t transmitter (context, ZMQ_PAIR);
	zmq::socket_t transmitter (context, ZMQ_REQ);
	transmitter.connect ("tcp://127.0.0.1:3210");
	//transmitter.connect (conn.c_str ());
	//transmitter.bind ("tcp://*:5555");
	
	
	//zmq::message_t filter_msg (sizeof (filter.c_str ()));
	zmq::message_t filter_msg (filter.length ());
	//zmq::message_t message (sizeof (msg_serial.c_str ()));
	zmq::message_t message (msg_serial.length ());

	//snprintf ((char *) message.data(), 20 ,
	//	"%05d %d %d", zipcode, temperature, relhumidity);
	//std::memcpy (filter_msg.data (), filter.c_str (), sizeof (filter.c_str ()));
	std::memcpy (filter_msg.data (), filter.c_str (), filter.length ());
	//std::memcpy (message.data (), msg_serial.c_str (), sizeof (msg_serial.c_str ()));
	std::memcpy (message.data (), msg_serial.c_str (), msg_serial.length ());
	
	std::cout << "message==" << '[' << static_cast <char *> (message.data ()) << ']' << std::endl;
	
	
  std::cout << "noware::machine::device::unicast_local()::send()" << std::endl;
	//return
	result =
		transmitter.send (filter_msg, ZMQ_SNDMORE)
		&&
		transmitter.send (message)
	;
	
	//zclock_sleep (1500);
	
	std::cout << "noware::machine::device::unicast_local()::send()==[" << (result ? "Success" : "Failure") << ']' << std::endl;
	
	//return true;
	return result;
}

// Short-circuited (triggered by success).
const bool noware::machine::device::search (noware::var & result, const noware::tree <> & message)// const
{
	std::cout << "noware::machine::device::search()::called" << std::endl;
	
	return false;
}

const bool noware::machine::device::search_local (noware::var &/* result*/, const noware::tree <> &/* message/expression*/)// const
{
	return false;
}
