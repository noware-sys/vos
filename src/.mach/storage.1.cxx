#include "storage.hxx"

const noware::var noware::machine::storage::group_default = "";

noware::machine::storage::storage (void)
{
	node.reception_set (boost::bind (boost::mem_fn (&noware::machine::storage::receive), this, _1));
	node.join ("storage");
}

noware::machine::storage::~storage (void)
{
	node.leave ("storage");
}

//const noware::any noware::machine::storage::evaluate (const noware::any & expression)
//{
//	return "";
//}
//

const bool noware::machine::storage::exists (const noware::any & name) const
{
	if (data.exists (name))
		return true;
	
	noware::matrix message;
	
	message ["subject"] = "exists";
	message ["name"] = name;
	
	//if (!nodes.evaluate (message))
	//if (!node.evaluate (message))
	//	return false;
	
	//return nodes.respond ();
	//return node.respond ();
	//return node.evaluate (message);
	return multicast (message);
}

const noware::any noware::machine::storage::get (const noware::any & name) const
{
	if (data.exists (name))
		return data [name];
	else if (!exists (name))
		return "";
	
	noware::matrix message;
	
	message ["subject"] = "get";
	message ["name"] = name;
	
	//if (!nodes.evaluate (message))
	//if (!node.evaluate (message))
	//	return "";
	
	//return nodes.respond ();
	//return node.respond ();
	//return node.evaluate (message);
	return multicast (message);
}

const bool noware::machine::storage::set (const noware::any & name, const noware::any & content)
{
	if (data.exists (name))
		return data.set (name, content);
	
	noware::matrix message;
	
	message ["subject"] = "set";
	message ["name"] = name;
	message ["content"] = content;
	
	//if (!nodes.evaluate (message))
	//if (!node.evaluate (message))
	//	return false;
	
	//return nodes.respond ();
	//return node.respond ();
	//return node.evaluate (message);
	return multicast (message);
}

const noware::number noware::machine::storage::magnitude (void) const
{
	//return 0;
	noware::matrix message;
	
	message ["subject"] = "magnitude";
	
	//if (!nodes.evaluate (message))
	//if (!node.evaluate (message))
	//	return data.size ();
	
	//return nodes.respond () + data.size ();
	//return node.evaluate (message) + data.size ();
	return multicast (message) + data.size ();
}

const bool noware::machine::storage::remove (const noware::any & name)
{
	if (data.exists (name))			// Only local (this zyre node).
		return data.unset (name);
	else if (!exists (name))		// Entire cluster.
		return true;
	
	noware::matrix message;
	
	message ["subject"] = "remove";
	message ["name"] = name;
	
	//if (!nodes.evaluate (message))
	//if (!node.evaluate (message))
	//	return false;
	
	//return nodes.respond ();
	//return node.respond ();
	//return node.evaluate (message);
	return multicast (message);
}

const bool noware::machine::storage::clear (void)
{
	if (!data.clear ())
		return false;
	
	noware::matrix message;
	
	message ["subject"] = "clear";
	
	//if (!nodes.evaluate (message))
	//if (!node.evaluate (message))
	//	return false;
	
	//return nodes.respond ();
	//return node.respond ();
	//return node.evaluate (message);
	return multicast (message);
}

const noware::any noware::machine::storage::unicast (const noware::matrix & message, const std::string & peer)
{
	return "";
}

const noware::var noware::machine::storage::multicast (noware::tree <> message, const std::string & group)
{
	if (!message.is_group ())
		return "";
	
	std::string filter = "";
	
	if (message.exists ("subject"))
		filter += message ["subject"];
	
	if (message.exists ("name"))
		filter += message ["name"];
	
	if (message.exists ("content"))
		filter += message ["content"];
	
	// Data, collapsed into a string.
	//message ["filter"] = filter;
	if (!node.multicast (/*filter + */message, group))
		return "";
	
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
}

void noware::machine::storage::receive (const zyre_event_t *& event)
{
	std::string event_type = zyre_event_type (event);
	noware::tree <> message;
	
	/*
	if (zyre_event_type (event) == "ENTER")
	{
		////  If new peer, say hello to it and wait for it to answer us
		//zsys_info ("[%s] peer entered", zyre_event_peer_name (event));
		//zyre_whispers (zyre, zyre_event_peer_uuid (event), "Hello");
	}
	else if (zyre_event_type (event) == "EXIT")
	{
		//zsys_info ("[%s] peer exited", zyre_event_peer_name (event));
	}
	*/
	//else
	if (event_type == "WHISPER" || event_type == "SHOUT")
	{
		//zsys_info ("[%s] received ping (WHISPER)", zyre_event_peer_name (event));
		//zyre_shouts (zyre, "GLOBAL", "Hello");
		
		zmq::message_t message_zmq;
		//std::string message_part;
		//std::string message;
		//std::string group;	// Group name which the message was sent to.
		//noware::list <> peer;
		
    //  Initialize random number generator
    //srandom ((unsigned) time (NULL));
    //while (true)
    //{
    	// First, get the message from the zyre peer.
			message_zmq = zyre_recv (node._node);
			
			if (message_zmq != nullptr)
			{
				// Read message.
				//do
				//{
					message ["event"] = zmsg_popstr (message_zmq);	// Type of the event (in this case, "WHISPER" or "SHOUT").
					message ["peer"] ["id"] = zmsg_popstr (zyre_message);	// Peer ID.
					message ["peer"] ["name"] = zmsg_popstr (zyre_message);	// Peer name.
				
					if (message ["event"] == "SHOUT")
						message ["group"] =  = zmsg_popstr (zyre_message);	// Group name.
				
					message ["content"] =  = zmsg_popstr (zyre_message);	// Message body.
				//}
				//while (zmq_msg_more (message_zmq) != 0);
				
		    //int zipcode, temperature, relhumidity;
				//
		    ////  Get values that will fool the boss
		    //zipcode     = within (100000);
		    //temperature = within (215) - 80;
		    //relhumidity = within (50) + 10;
				
				// Prepare for transmission.
				zmq::context_t context (1);
				zmq::socket_t transmitter (context, ZMQ_PUB);
				transmitter.bind ("tcp://127.0.0.1:5555");
				//transmitter.bind("ipc://weather.ipc");                // Not usable on Windows.
				
				zmq::message_t forwarded_message (message ["content"].length ());
		    //  Send message to all subscribers
		    snprintf
				(
					(char *) forwarded_message.data (), message ["content"].length (),
					"%s",
					message ["content"]
				)
		    ;
		    std::cout << "Forwarding Message " << '[' << static_cast <char *> (forwarded_message.data ()) << ']' << std::endl;
		    publisher.send (forwarded_message);
			}
    //}
    //return 0;
	}
	/*
	else if (zyre_event_type (event) == "SHOUT")
	{
		/*
		zsys_info
		(
			"[%s](%s) received ping (SHOUT)"
			,
			zyre_event_peer_name (event)
			,
			zyre_event_group (event)
		)
		;
		*/
	//}
}

