#pragma once

//#include "dev.hdr.cxx"
//#include "../var.cxx"
//#include "../net/node.cxx"

const std::string noware::mach::dev::grp_dft = "noware::mach::dev";
const noware::nr noware::mach::dev::token_size_dft = 16;

noware::mach::dev::dev (void)
{
	//local_context = new zmq::context_t (1);
	//local_socket = new zmq::socket_t (*local_context, ZMQ_);
	//
	//local_socket -> bind ("");
	
	//init ();
	
	//assert (node.init ());
	//assert (node.join (grp_dft));
	
	//nodes.add (node);
	
	assert (node.reception_set (boost::bind (boost::mem_fn (&noware::mach::dev::receive), this, _1)));
	//	return false;
}

noware::mach::dev::~dev (void)
{
	//node.stop ();
	//node.finalize ();
	
	//nodes.remove (node);
	//assert (node.fin ());
	
	//stop ();
	fin ();
	assert (node.reception_unset ());
}

const bool noware::mach::dev::fin (void)
{
	//if (!node.reception_unset ())
	//	return false;
	
	if (!node.fin ())
		return false;
	
	return true;
}

const bool noware::mach::dev::inited (void) const
{
	//if (!node.reception_is_set ())
	//	return false;
	
	if (!node.inited ())
		return false;
	
	return true;
}

const bool noware::mach::dev::init (void)
{
	//if (!node.reception_set (boost::bind (boost::mem_fn (&noware::mach::dev::receive), this, _1)))
	//	return false;
	
	if (!node.init ())
		return false;
	
	return true;
}

const bool noware::mach::dev::stop (void)
{
//	if (!running ())
//		return true;
	
	if (!node.stop ())
		return false;
	
	//if (!node.fin ())
	//	return false;
	
	//if (!node.reception_unset ())
	//	return false;
	
	return true;
}

const bool noware::mach::dev::running (void) const
{
//	if (!inited ())
//		return false;
	
	if (!node.running ())
		return false;
	
	//if (!node.reception_is_set ())
	//	return false;
	
	//if (!node.inited ())
	//	return false;
	
	return true;
}

const bool noware::mach::dev::start (void)
{
	//local_context = new zmq::context_t (1);
	//local_socket = new zmq::socket_t (*local_context, ZMQ_);
	//
	//local_socket -> bind ("");
	
//	if (running ())
//		return true;
	
	//if (!node.init ())
	//	return false;
	
	//if (!node.start ())
	//	return false;
	
	//if (node.reception_is_set ())
	//	return true;
	
	//if (!node.reception_set (boost::bind (boost::mem_fn (&noware::mach::dev::receive), this, _1)))
	//	return false;
	
	//if (!inited ())
	//	return false;
	
	if (!enabled ())
		return false;
	
	if (!node.start ())
		return false;
	
	//nodes.add (node);
	
	return true;
}

const bool noware::mach::dev::disable (void)
{
	if (!node.stop ())
		return false;
	
	return false;
}

const bool noware::mach::dev::enabled (void) const
{
	return true;
}

const bool noware::mach::dev::enable (void)
{
	return true;
}

const zmq::msg/* value*/ noware::mach::dev::locval (const zmq::msg & expression)
{
	return unival (expression, node.id ());
}

const zmq::msg/* value*/ noware::mach::dev::unival (const zmq::msg & expression, const std::string & peer_id)
{
	zmq::msg result;
	
	if (search_local (result, expression, peer_id, net::cast::uni))
		return result;
	else
	{
		//noware::nr responses_count;
		
		return aggregate (result, unicast (expression, /*noware::mach::dev::*/peer_id), expression, 1, peer_id, net::cast::uni);
	}
}

const zmq::msg/* value*/ noware::mach::dev::anyval (const zmq::msg & expression)
{
	zmq::msg result;
	std::string peer_id;
	
	peer_id = node.any ();
	
	std::cerr << " noware::mach::dev::anyval()::peer.id::[" << peer_id << "]" << std::endl;
	
	if (search_local (result, expression, peer_id, net::cast::uni))
		return result;
	else
	{
		//noware::nr responses_count;
		//std::string peer_id;
		
		//return aggregate (result, anycast (expression, peer_id), expression, 1, peer_id);
		return aggregate (result, unicast (expression, peer_id), expression, 1, peer_id, net::cast::uni);
	}
}

const zmq::msg/* value*/ noware::mach::dev::anyval (const zmq::msg & expression, const std::string & group)
{
	zmq::msg result;
	std::string peer_id;
	
	peer_id = node.any (group);
	
	std::cerr << " noware::mach::dev::anyval(group)::peer.id::[" << peer_id << "]" << std::endl;
	
	if (search_local (result, expression, peer_id, net::cast::uni))
		return result;
	else
	{
		//noware::nr responses_count;
		
		//return aggregate (result, anycast (expression, /*noware::mach::dev::*/group), expression, 1, group);
		return aggregate (result, unicast (expression, /*noware::mach::dev::*/peer_id), expression, 1, peer_id, net::cast::uni);
	}
}

const zmq::msg noware::mach::dev::multival (const zmq::msg & expression, const std::string & group)
{
	zmq::msg result;
	
	if (search_local (result, expression, group, net::cast::multi))
		return result;
	else
	{
		noware::nr responses_count;
		
		return aggregate (result, multicast (expression, responses_count, /*noware::mach::dev::*/group), expression, responses_count, group, net::cast::multi);
	}
	
	//return "";
	//if (!nodes.val (expression))
	//	return false;
	//nodes.val (expression);
	//
	//return nodes.respond ();
}

const zmq::msg/* value*/ noware::mach::dev::broadval (const zmq::msg & expression)
{
	zmq::msg result;
	
	if (search_local (result, expression, "", net::cast::broad))
		return result;
	else
	{
		noware::nr responses_count;
		
		return aggregate (result, broadcast (expression, responses_count), expression, responses_count, "", net::cast::broad);
	}
}

const zmq::msg noware::mach::dev::aggregate (const zmq::msg &/* result*//* from search_local*/, const zmq::msg & response/* from ...search*/, const zmq::msg &/* expression*/, const noware::nr &/* responses_count*/, const std::string &/* src*/, const net::cast &/* src_cast*/)
{
	return response;
}

const zmq::msg noware::mach::dev::unicast (zmq::msg msg_req, /*const std::string & filter, */const std::string & peer)
{
	std::cerr << "noware::mach::dev::unicast()::called" << std::endl;
	
	std::string request_token;
	zmq::msg msg_resp;
	noware::nr responses_count;
	
	//return msg_resp;
	
	request_token = noware::random::string (token_size_dft);
	std::cerr << "noware::mach::dev::unicast()::request_token==[" << request_token << ']' << std::endl;
	
	msg_req.prepend (zmq::msg::frame ("noware::mach::dev::response::desired"));
	msg_req.prepend (zmq::msg::frame (request_token));
	//msg_req.prepend (zmq::msg::frame ("noware::mach::dev::response"));
	
	if (!node.unicast (/*filter + */msg_req, peer))
	{
		std::cerr << "noware::mach::dev::unicast()::node.unicast()::failure" << std::endl;
		return msg_resp;
	}
	
	std::cerr << "noware::mach::dev::unicast()::node.unicast()::success" << std::endl;
	//return receive_local (message ["subject"].get_value (), filter);
	//return receive_local (message, filter);
	
	//return msg_resp;
	return receive_local (request_token, 1, responses_count, peer, net::cast::uni);
	//return receive_local_uni (peer, filter);
}

const zmq::msg/* message: response*/ noware::mach::dev::anycast (zmq::msg msg_req, std::string & peer_id)
{
	std::cerr << "noware::mach::dev::anycast()::called" << std::endl;
	
	std::string request_token;
	//std::string peer_id;
	zmq::msg msg_response;
	noware::nr responses_count;
	
	request_token = noware::random::string (token_size_dft);
	std::cerr << "noware::mach::dev::anycast(msg)::request_token==[" << request_token << ']' << std::endl;
	
	msg_req.prepend (zmq::msg::frame ("noware::mach::dev::response::desired"));
	msg_req.prepend (zmq::msg::frame (request_token));
	
	if (!node.anycast (msg_req, peer_id))
	{
		std::cerr << "noware::mach::dev::anycast()::node.anycast()::failure" << std::endl;
		return msg_response;
	}
	
	//return receive_local (request_token, 1, responses_count, grp_dft);
	return receive_local (request_token, 1, responses_count, peer_id, net::cast::uni);
}

const zmq::msg/* message: response*/ noware::mach::dev::anycast (zmq::msg msg_req, std::string & peer_id, const std::string & group)
{
	std::cerr << "noware::mach::dev::anycast(" << group << ")::called" << std::endl;
	
	std::string request_token;
	//std::string peer_id;
	zmq::msg msg_response;
	noware::nr responses_count;
	
	request_token = noware::random::string (token_size_dft);
	std::cerr << "noware::mach::dev::anycast(msg," << group << ")::request_token==[" << request_token << ']' << std::endl;
	
	msg_req.prepend (zmq::msg::frame ("noware::mach::dev::response::desired"));
	msg_req.prepend (zmq::msg::frame (request_token));
	
	std::cerr << "noware::mach::dev::anycast(" << group << ")::msg_req.data::pre-loop" << std::endl;
	for (const std::pair <unsigned int, zmq::msg::frame> & element : msg_req.data)
	{
		std::cerr << "noware::mach::dev::anycast(" << group << ")::msg_req.data[" << element.first << "]==\"" << std::string (element.second) << "\"" << std::endl;
	}
	
	std::cerr << "noware::mach::dev::anycast(" << group << ")::node.anycast(" << group << ")::pre" << std::endl;
	if (!node.anycast (msg_req, peer_id, group))
	{
		std::cerr << "noware::mach::dev::anycast(" << group << ")::node.anycast(" << group << ")::failure" << std::endl;
		return msg_response;
	}
	std::cerr << "noware::mach::dev::anycast(" << group << ")::node.anycast(" << group << ")::success" << std::endl;
	
	//return receive_local (grp_dft, responses_count, request_token, 1);
	return receive_local (request_token, 1, responses_count, peer_id, net::cast::uni);
}

const zmq::msg noware::mach::dev::multicast (zmq::msg msg_req, noware::nr & responses_count, const std::string & group)
{
	std::cerr << "noware::mach::dev::multicast()::called" << std::endl;
	//if (!message.is_group ())
	//	return "";
	
	std::string request_token;
	zmq::msg msg_resp;
	//noware::nr responses_count;
	
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
	
	request_token = noware::random::string (token_size_dft);
	std::cerr << "noware::mach::dev::multicast()::request_token==[" << request_token << ']' << std::endl;
	
	msg_req.prepend (zmq::msg::frame ("noware::mach::dev::response::desired"));
	msg_req.prepend (zmq::msg::frame (request_token));
	
	if (!node.multicast (/*filter + */msg_req, group))
	{
		std::cerr << "noware::mach::dev::multicast()::node.multicast()::failure" << std::endl;
		return msg_resp;
	}
	
	std::cerr << "noware::mach::dev::multicast()::node.multicast()::success" << std::endl;
	//return receive_local (message ["subject"].get_value (), filter);
	//return receive_local (message, filter);
	//return receive_local (responses_count, request_token, group);
	//return receive_local (grp_dft, responses_count, request_token, node.peers_size (group));
	return receive_local (request_token, node.peers_size (group), responses_count, group, net::cast::multi);
	
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

const zmq::msg/* message: response*/ noware::mach::dev::broadcast (zmq::msg msg_req, noware::nr & responses_count/* number of peers who answered*/)
{
	std::cerr << "noware::mach::dev::broadcast()::called" << std::endl;
	
	std::string request_token;
	zmq::msg msg_response;
	//noware::nr responses_count;
	
	request_token = noware::random::string (token_size_dft);
	std::cerr << "noware::mach::dev::broadast()::request_token==[" << request_token << ']' << std::endl;
	
	msg_req.prepend (zmq::msg::frame ("noware::mach::dev::response::desired"));
	msg_req.prepend (zmq::msg::frame (request_token));
	
	if (!node.broadcast (msg_req))
	{
		std::cerr << "noware::mach::dev::multicast()::node.multicast()::failure" << std::endl;
		return msg_response;
	}
	
	//return receive_local (grp_dft, responses_count, request_token, node.peers_size ());
	return receive_local (request_token, node.peers_size (), responses_count, "", net::cast::broad);
}

void noware::mach::dev::receive (const zyre_event_t * event)
{
	std::cerr << "noware::mach::dev::receive()::called" << std::endl;
	
	//const char * event_type = zyre_event_type (event);
	std::string event_type;
	std::string src;
	net::cast src_cast;
	//noware::tree <> message_zyre;
	//noware::tree <> message;
	//zmsg_t * zmsg;
	//zframe_t * zframe;
	zmq::msg msg;
	//noware::nr frame_ndx;
	bool result;
	//bool respond;
	
	event_type = zyre_event_type (event);
	//src = zyre_event_group (event);
	
	//if (event_type == "WHISPER" || event_type == "SHOUT")
	//{
		
		//zmsg_t * zmq_msg;
		
		//if (zmq_msg != nullptr)
		//{
		//	std::cerr << "noware::mach::dev::receive()::zmq_msg!=nullptr" << std::endl;
			//std::string msg;
			//noware::tree <> msg;
			
			// First, get the message from the zyre peer.
			//zmsg = zyre_event_msg (event);
			/*
			frame_ndx = 1;
			zframe = zmsg_first (zmsg);
			
			while (zframe != nullptr)
			{
				msg.data [frame_ndx] = *zframe;
				zframe = zmsg_next (zmsg);
				++frame_ndx;
			}
			*/
			
			//if (msg.deserialize (zmsg_popstr (zmq_msg)))
			//{
				//std::cerr << "*zmq_msg==" << '[' << (const char *) zmq_msg << ']' << std::endl;
				//std::cerr << "zmsg_popstr(zmq_msg)==" << '[' << zmsg_popstr (zmq_msg) << ']' << std::endl;
			//	std::cerr << "msg.serialize()==" << '[' << msg.serialize () << ']' << std::endl;
				
				
	//bool result;
	
	//zmq::msg msg;
	zmsg_t * zmsg;
	//zmsg_t * zmsg_response;
	//zframe_t * zframe_response;
	//std::string event_type;
	//std::string response_token;
	std::string request_token;
	
	//zmsg = zyre_event_msg (event);
	//msg = zyre_event_msg (event);
	//msg = zmsg;
	//event_type = zyre_event_type (event);
	//assert (event);
	//assert (zmsg);
	
	//event_type = zyre_event_type (event);
	
	std::cerr << "noware::mach::dev::receive()::event_type==[" << event_type << ']' << std::endl;
	
	//result = node.unicast (respond (msg), zyre_event_peer_uuid (event));
//	std::cerr << "noware::mach::dev::receive()::responding()..." << std::endl;
	//result = respond (zmsg, event);
//	result = respond (event);
//	std::cerr << "noware::mach::dev::receive()::responded()==" << '[' << (result ? "success" : "failure") << ']' << std::endl;
	//std::cerr << "noware::mach::dev::receive()::node.unicast (response, zyre_event_peer_uuid (event)==" << (result ? "Success" : "Failure") << std::endl;
	
	// request
	// response
	// data message
	// WHISPER SHOUT
	if (event_type == "WHISPER" || event_type == "SHOUT")
	{
		std::cerr << "noware::mach::dev::receive()::event_type==(WHISPER||SHOUT)==[" << event_type << ']' << "::in scope" << std::endl;
		//std::cerr << "noware::mach::dev::respond()::event not of interest" << std::endl;
		
		//return false;
		zmsg = zyre_event_msg (event);
		
		if (zmsg != nullptr)
		{
			std::cerr << "noware::mach::dev::receive()::event_msg==nullptr" << std::endl;
			
			if (event_type == "WHISPER")
			{
				src_cast = net::cast::uni;
				src = zyre_event_peer_uuid (event);
			}
			else //if (event_type = "SHOUT")
			{
				src_cast = net::cast::multi;
				src = zyre_event_group (event);
			}
			
			//return false;
			//respond = false;
			
			std::cerr << "noware::mach::dev::receive()::event of type data" << std::endl;
			msg = zmsg;
			
			//response_token = msg.first ();
			
			std::cerr << "noware::mach::dev::receive()::msg.data::pre-loop" << std::endl;
			for (const std::pair <unsigned int, zmq::msg::frame> & element : msg.data)
			{
				std::cerr << "noware::mach::dev::receive()::msg.data[" << element.first << "]==\"" << std::string (element.second) << "\"" << std::endl;
			}
			
			request_token = msg.first ();
			msg.first_rm ();
			
			std::cerr << "noware::mach::dev::receive()::request_token::post-removal" << std::endl;
			
			std::cerr << "noware::mach::dev::receive()::msg.data::pre-loop" << std::endl;
			for (const std::pair <unsigned int, zmq::msg::frame> & element : msg.data)
			{
				std::cerr << "noware::mach::dev::receive()::msg.data[" << element.first << "]==\"" << std::string (element.second) << "\"" << std::endl;
			}
			
			// This message is a response.
			//if (response_token == "noware::mach::dev::response")
			if (msg.first ()/* response_token*/ == "noware::mach::dev::response::present")
			{
				std::cerr << "noware::mach::dev::receive()::response[noware::mach::dev::response::present]" << std::endl;
				
				msg.first_rm ();
				
				
				std::cerr << "noware::mach::dev::receive()::unicast_local(msg," << request_token << ")" << std::endl;
				// Redirect the message to the function which asked for it.
				////unicast_local (zmsg_popstr (zmq_msg));
				//result = unicast_local (msg_rx);
				result = unicast_local (msg, request_token);
				std::cerr << "noware::mach::dev::receive()::unicast_local(msg," << request_token << ")==[" << (result ? "success" : "failure") << "]" << std::endl;
				
				//return result;
			}
			// This message is a request;
			// a response (confirmation) is also being requested.
			else if (msg.first ()/* response_token*/ == "noware::mach::dev::response::desired")
			{
				std::cerr << "noware::mach::dev::receive()::request[noware::mach::dev::response::desired]" << std::endl;
				
				msg.first_rm ();
				
				zmq::msg msg_response;
				
				result = respond (msg_response, msg, event, event_type, src, src_cast);
				
				if (result)
				{
					std::cerr << "noware::mach::dev::receive()::respond[true]" << std::endl;
					
					msg_response.prepend (zmq::msg::frame ("noware::mach::dev::response::present"));
					msg_response.prepend (zmq::msg::frame (request_token));
					
					// Send back the answer.
					result = node.unicast (msg_response, zyre_event_peer_uuid (event));
					
					//if (result)
					//{
						std::cerr << "noware::mach::dev::receive()::respond_post[true]ing" << std::endl;
						
						result = respond_post (msg_response, msg, event, event_type, src, src_cast, result);
						
						std::cerr << "noware::mach::dev::receive()::respond_post[true]ed" << std::endl;
					//}
				}
				else
				{
					std::cerr << "noware::mach::dev::receive()::respond[false]" << std::endl;
				}
			}
			// This message is a request;
			// a response is not being requested.
			else
			{
				std::cerr << "noware::mach::dev::receive()::request[noware::mach::dev::response::nondesired]" << std::endl;
				
				if (msg.first () == "noware::mach::dev::response::nondesired")
					msg.first_rm ();
				
				zmq::msg msg_response;
				
				result = respond (msg_response, msg, event, event_type, src, src_cast);
			}
		}
	}
	// infrastructure message
	// ENTER EXIT JOIN LEAVE
	else
	{
		std::cerr << "noware::mach::dev::receive()::event of type infrastruct[ure]" << std::endl;
		result = infrastruct (/*msg, */event, event_type/*, src, src_cast*/);
		std::cerr << "noware::mach::dev::receive()::infrastruct(event," << event_type << ",msg)==[" << (result ? "success" : "failure") << "]" << std::endl;
	}
	
	//std::cerr << "noware::mach::dev::receive()::event==" << event_type << std::endl;
	
				
				
			//}
			//else
			//{
			//	std::cerr << "noware::mach::dev::receive()::msg.deserialize()==False" << std::endl;
			//}
			//std::cerr << "noware::mach::dev::receive()::msg[subject]==[" << msg ["subject"] << ']' << std::endl;
		//}
		//else
		//{
		//	std::cerr << "noware::mach::dev::receive()::zmq_msg==nullptr" << std::endl;
		//}
	//}
	
	//std::cerr << "noware::mach::dev::receive()::free()..." << std::endl;
	////free (event_type);
	//std::cerr << "noware::mach::dev::receive()::free()...OK" << std::endl;
	std::cerr << "noware::mach::dev::receive()::return[" << (result ? "true" : "false") << "]" << std::endl;
	
	return result;
}

//const bool noware::mach::dev::respond (const zmsg_t */* msg*/, const zyre_event_t */* event*/)
const bool noware::mach::dev::respond (zmq::msg &/* response*/, const zmq::msg &/* rx'd*/, const zyre_event_t */* event*/, const std::string &/* event_type*/, const std::string &/* src*/, const net::cast &/* src_cast*/)
{
	std::cerr << "noware::mach::dev::respond()::called" << std::endl;
	
	return false;
}

const bool noware::mach::dev::respond_post (const zmq::msg &/* response*/, const zmq::msg &/* rx'd*/, const zyre_event_t */* event*/, const std::string &/* event_type*/, const std::string &/* src*/, const net::cast &/* src_cast*/, const bool & result)
{
	std::cerr << "noware::mach::dev::respond_post()::called" << std::endl;
	
	return true;
}

//const bool noware::mach::dev::infrastruct (const zmq::msg &/* rx'd*/, const zyre_event_t */* event*/, const std::string &/* event_type*/, const std::string &/* src*/, const net::cast &/* src_cast*/)
//const bool noware::mach::dev::infrastruct (const zmq::msg &/* rx'd*/, const zyre_event_t */* event*/, const std::string &/* event_type*/)
const bool noware::mach::dev::infrastruct (const zyre_event_t */* event*/, const std::string &/* event_type*/)
{
	std::cerr << "noware::mach::dev::infrastruct()::called" << std::endl;
	
	return false;
}

const zmq::msg noware::mach::dev::receive_local (const std::string & request_token/*, const std::string & response_type*/, const noware::nr & responses_expected, noware::nr & responses_count, const std::string & src, const net::cast & src_cast) const
{
	std::cerr << "noware::mach::dev::receive_local::called" << std::endl;
	//std::cerr << "noware::mach::dev::receive_local(response_type=[" << response_type << "], filter=[" << filter << "])::called" << std::endl;
	
	int bind_return_code;
	
	// Socket options.
	int linger;
	int recv_timeout;
	
	std::string conn;	// Connection string.
	
	
	//conn = (std::string) "inproc://" + filter;
	//conn = "inproc://connection1";
	
	std::cerr << "noware::mach::dev::receive_local()::conn==[" << conn << ']' << std::endl;
	std::cerr << "noware::mach::dev::receive_local()::request_token==[" << request_token << ']' << std::endl;
	
	zmq::context_t context (1);
	//  Socket to talk to server
	//std::cerr << "Collecting updates from weather server...\n" << std::endl;
	//zmq::socket_t receiver (context, ZMQ_SUB);
	//zmq::socket_t receiver (context, ZMQ_PAIR);
	//zmq::socket_t receiver (context, ZMQ_REP);
	zmq::socket_t receiver (context, ZMQ_DEALER);
//	receiver.bind ("tcp://127.0.0.1:3210");
	//receiver.bind (conn.c_str ());
	//receiver.bind ("tcp://0.0.0.0:5555");
	receiver.bind ((std::string ("ipc://./") + request_token).c_str ());
	//receiver.bind ((std::string ("inproc://") + request_token).c_str ());
	
	//std::cerr << "noware::mach::dev::receive_local()::receiver.bind()==[" << bind_return_code << ']' << std::endl;
	//linger = 0;	// No lingering...
	//recv_timeout = 3000;	// 3 seconds
	
	// Subscribe to the filter.
	//receiver.setsockopt (ZMQ_SUBSCRIBE, filter.c_str (), sizeof (filter));
	//receiver.setsockopt (ZMQ_LINGER, &linger, sizeof (linger));
	receiver.setsockopt <int> (ZMQ_LINGER, 0);
	//receiver.setsockopt (ZMQ_RCVTIMEO, &recv_timeout, sizeof (recv_timeout));
	receiver.setsockopt <int> (ZMQ_RCVTIMEO, 3000);
	
	
	// zlist_t * peers;
	
	//assert (zlist_size (peers) == 1);
	//zlist_destroy (&peers);
	
	zmq::msg message;
	zmq::msg response;
	//noware::nr::natural n;
	//zmq::message_t message_filter;
	zmq::message_t message_content;
	//boost::function <const bool/* search_* */ (const noware::tree <> &/* response_type*/, noware::var &/* filter*/)> search;
	
	/*
	response = "";
	// Decide which search function should be used.
	std::cerr << "noware::mach::dev::receive_local(response_type=[" << response_type << "], filter=[" << filter << "])::pre-if" << std::endl;
	if (response_type == "get")
	{
	  std::cerr << "noware::mach::dev::receive_local()::response_type==[" << response_type << ']' << "::in scope" << std::endl;
		search = boost::bind (boost::mem_fn (&noware::mach::dev::search_get), this, _1, _2);
		//search = &noware::mach::dev::search_get;
	}
	else if (response_type == "set")
	{
	  std::cerr << "noware::mach::dev::receive_local()::response_type==[" << response_type << ']' << "::in scope" << std::endl;
		search = boost::bind (boost::mem_fn (&noware::mach::dev::search_set), this, _1, _2);
		//search = &noware::mach::dev::search_set;
	}
	else
	{
	  std::cerr << "noware::mach::dev::receive_local()::response_type::if-else::in scope" << std::endl;
		return "";
	}
	*/
	
	//std::cerr << "noware::mach::dev::receive_local(response_type=[" << response_type << "], filter=[" << filter << "])::node.size()==[" << node.size () << ']' << std::endl;
	//std::cerr << "noware::mach::dev::receive_local(filter=[" << filter << "])::node.size()==[" << node.size () << ']' << std::endl;
	std::cerr << "noware::mach::dev::receive_local::node.peers_size()==[" << node.peers_size () << ']' << std::endl;
	
	/*
	//zlist_t * peers;
	peers = zyre_peers (node.zyre ());
	if (peers == nullptr);
	{
		std::cerr << "noware::mach::dev::receive_local(response_type=[" << response_type << "], filter=[" << filter << "])::peers==nullptr" << std::endl;
		
		return result;
	}
	*/
	// Ensure that all relevant peers respond.
	//n = 0;
	//result = "";
	unsigned int responses_nr;
	unsigned int responses_expect;
	
	//responses_nr = responses_count;
	responses_expect = responses_expected;
  std::cerr << "noware::mach::dev::receive_local()::pre-loop" << std::endl;
	std::cerr << "noware::mach::dev::receive_local()::responses_expected==[" << responses_expected << ']' << std::endl;
	std::cerr << "noware::mach::dev::receive_local()::responses_expect==[" << responses_expect << ']' << std::endl;
	//std::cerr << "noware::mach::dev::receive_local()::responses_count==[" << responses_count << ']' << std::endl;
	//std::cerr << "noware::mach::dev::receive_local()::responses_nr==[" << responses_nr << ']' << std::endl;
	//for (/*noware::nr::natural n*/responses_count = 0; responses_count < /*zlist_size (peers)*/ noware::nr (node.size (group)); ++responses_count)
	//for (/*noware::nr::natural n*/responses_nr = 0; responses_nr < /*zlist_size (peers)*/ node.size (group); ++responses_nr)
	for (/*noware::nr::natural n*/responses_nr = 0; responses_nr < /*zlist_size (peers)*/ responses_expect; ++responses_nr)
	{
		//std::cerr << "noware::mach::dev::receive_local()::while::responses_count==[" << responses_count << ']' << std::endl;
		std::cerr << "noware::mach::dev::receive_local()::while::responses_count==[" << responses_nr << ']' << std::endl;
		
		//zmq::message_t message_filter;
		//zmq::message_t message_content;
		
		//std::cerr << "noware::mach::dev::receive_local()::loop::receiving::filter" << std::endl;
		//receiver.recv (&message_filter);
		//std::cerr << "noware::mach::dev::receive_local()::loop:: received::filter" << std::endl;
		
		std::cerr << "noware::mach::dev::receive_local()::loop::receiving::message" << std::endl;
		if (!receiver.recv (&message_content))
		{
			//std::cerr << "noware::mach::dev::receive_local()::loop::receiving::message::[false]" << std::endl;
			std::cerr << "noware::mach::dev::receive_local()::loop::receiving::message::[false]::break" << std::endl;
			
			break;
		}
		
		std::cerr << "noware::mach::dev::receive_local()::loop:: received::message" << std::endl;
		
		std::cerr << "noware::mach::dev::receive_local()::message_tree.deserialize()::pre-call" << std::endl;
		
		//std::cerr << "noware::mach::dev::receive_local()::message_filter.data()==[" << static_cast <const char *> (message_filter.data ())	<< ']' << std::endl;
		
		std::cerr << "noware::mach::dev::receive_local()::message_content.data()==[" << static_cast <const char *> (message_content.data ()) << ']' << std::endl;
		
		//message = static_cast <const char *> (message_content.data ());
		message = message_content;
		//if (!message_tree.deserialize (static_cast <const char *> (message_content.data ())))
		//{
		//	std::cerr << "noware::mach::dev::receive_local()::message_tree.deserialize()==False" << std::endl;
		//	return response;
		//}
		
		std::cerr << "noware::mach::dev::receive_local()::message_tree.deserialize()==True" << std::endl;
		// Refresh the list of peers,
		// in case any of them departed the cluster since our previous iteration(s),
		// even if it is improbable.
		/*
		zlist_destroy (&peers);
		//zlist_t * peers;
		peers = zyre_peers (node.zyre ());
		
		if (peers == nullptr)
		{
		  std::cerr << "noware::mach::dev::receive_local()::in-while::peers==nullptr" << std::endl;
			return "";
		}
		*/
		// React to/Parse the message.
		// search() returns bool/success if we found the (correct) answer that we are searching for.
		// when we haven't yet found the entire answer, we continue;
		// when we fail, we (could) short-circuit the loop (stop looping).
  	std::cerr << "noware::mach::dev::receive_local()::if(search())::pre-call" << std::endl;
		if (search (response, message, src, src_cast))
		{
	  	std::cerr << "noware::mach::dev::receive_local()::if(search())::break" << std::endl;
			break;
		}
  	std::cerr << "noware::mach::dev::receive_local()::if(search())::post-call" << std::endl;
		
		//++n;
	}
  std::cerr << "noware::mach::dev::receive_local()::post-loop" << std::endl;
	
	responses_count = responses_nr;
	//zlist_destroy (&peers);
	
  //std::cerr << "noware::mach::dev::receive_local()::return response==[" << response << ']' << std::endl;
	return response;
	
	//std::istringstream iss(static_cast<char*>(update.data()));
	//std::cerr << "Message=" << '[' << static_cast <char *> (update.data ()) << ']' << std::endl;
}

const bool noware::mach::dev::unicast_local (const zmq::msg & msg, const std::string & request_token) const
//const bool noware::mach::dev::unicast_local (const zmsg_t * msg) const
{
	//zmq::msg filter;
	zmq::message_t message;
	//std::string msg_serial;
	//zframe_t * zframe;
	std::string conn;	// Connection string.
	//noware::tree <> msg_tree;
	bool result;
	
	//filter = "";
	
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
	
//	std::cerr << "noware::mach::dev::unicast_local()::msg[content].get_value ().text ()==[" << msg << ']' << std::endl;
	//std::cerr << "noware::mach::dev::unicast_local()::msg[content].get_value ().text ()==[" << msg ["content"].get_value ().text () << ']' << std::endl;
	////std::cerr << "noware::mach::dev::unicast_local()::msg[content].get_value ().text ()==[" << msg ["content"].get_value ().text () << ']' << std::endl;
	
	//zframe = zmsg_first (msg);
	//message.rebuild (zframe_data (zframe), zframe_size (zframe));
	
	
	std::cerr << "noware::mach::dev::unicast_local()::conn==[" << conn << ']' << std::endl;
	std::cerr << "noware::mach::dev::unicast_local()::request_token==[" << request_token << ']' << std::endl;
	
	//msg_serial = msg.serialize ();
	
	zmq::context_t context (1);
	//zmq::socket_t transmitter (context, ZMQ_PUB);
	//zmq::socket_t transmitter (context, ZMQ_PAIR);
	//zmq::socket_t transmitter (context, ZMQ_REQ);
	zmq::socket_t transmitter (context, ZMQ_DEALER);
//	transmitter.connect ("tcp://127.0.0.1:3210");
	//transmitter.connect (conn.c_str ());
	//transmitter.bind ("tcp://*:5555");
	transmitter.connect ((std::string ("ipc://./") + request_token).c_str ());
	//transmitter.connect ((std::string ("inproc://") + request_token).c_str ());
	
	/////zmq::message_t filter_msg (sizeof (filter.c_str ()));
	//zmq::message_t filter_msg (filter.length ());
	////zmq::message_t message (sizeof (msg_serial.c_str ()));
	//zmq::message_t message (msg.length ());

	//snprintf ((char *) message.data(), 20 ,
	//	"%05d %d %d", zipcode, temperature, relhumidity);
	//std::memcpy (filter_msg.data (), filter.c_str (), sizeof (filter.c_str ()));
//	std::memcpy (filter_msg.data (), filter.c_str (), filter.length ());
	//std::memcpy (message.data (), msg_serial.c_str (), sizeof (msg_serial.c_str ()));
//	std::memcpy (message.data (), msg.c_str (), msg.length ());
	
//	std::cerr << "message==" << '[' << static_cast <const char *> (message.data ()) << ']' << std::endl;
	std::cerr << "noware::mach::dev::unicast_local()::message==" << '[' << static_cast <const char *> (msg.operator zmq::message_t & ().data ()) << ']' << std::endl;
	
	
  std::cerr << "noware::mach::dev::unicast_local()::send()" << std::endl;
	//return
	result =
		//transmitter.send (filter_msg, ZMQ_SNDMORE)
		//&&
		//transmitter.send (msg.operator zmq::message_t & ())
		//transmitter.send (message);
		transmitter.send (msg.operator zmq::message_t & ());
	;
	
	//zclock_sleep (1500);
	
	std::cerr << "noware::mach::dev::unicast_local()::send()==[" << (result ? "Success" : "Failure") << ']' << std::endl;
	
	//return true;
	return result;
}

// Short-circuited (triggered by success).
const bool noware::mach::dev::search (zmq::msg &/* result*/, const zmq::msg &/* message*/, const std::string &/* src*/, const net::cast &/* src_cast*/)// const
{
	std::cerr << "noware::mach::dev::search()::called" << std::endl;
	
	return false;
}

const bool noware::mach::dev::search_local (zmq::msg &/* result*/, const zmq::msg &/* message*/, const std::string &/* src*/, const net::cast &/* src_cast*/)// const
{
	std::cerr << "noware::mach::dev::search_local()::called" << std::endl;
	
	return false;
}
