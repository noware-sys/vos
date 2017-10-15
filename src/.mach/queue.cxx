#pragma once

//#include "processor.hdr.cxx"

const std::string noware::mach::queue::grp_dft = "noware::mach::queue";

noware::mach::queue::queue (void)
{
	//assert (node.join (grp_dft));
	//assert (node.join ("noware::mach::queue::nonfull"));
}

noware::mach::queue::~queue (void)
{
}

const bool noware::mach::queue::start (void)
{
	if (!dev::start ())
		return false;
	
	if (!node.join (/*noware::mach::store::*/grp_dft))
		return false;
	
	if (!node.join ("noware::mach::queue::nonfull")) // Temporary: dynamically find when needed.
		return false;
	
	return true;
}

const bool noware::mach::queue::empty (void) const
{
	return count () <= 0;
}

const bool noware::mach::queue::empty_local (void) const
{
	return queue.empty ();
}

const bool noware::mach::queue::full (void) const
{
	return false;
}

const bool noware::mach::queue::full_local (void) const
{
	return false;
}

const noware::nr noware::mach::queue::count (void) const
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "size::count";
	//expression ["group"] = group;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return queue.size ();
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return std::string (multival (zmq::msg (expression_serial), noware::mach::queue::grp_dft));
	//return 0;
}

const std::string noware::mach::queue::next (void) const
{
	if (empty ())
		return "";
	
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "next";
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return "";
	
	return std::string (anyval (zmq::msg (expression_serial), "noware::mach::queue::nonempty"));
}

const std::string noware::mach::queue::next_dequeue (void)
{
	if (empty ())
		return "";
	
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "next_dequeue";
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return "";
	
	return std::string (anyval (zmq::msg (expression_serial), "noware::mach::queue::nonempty"));
}

const bool noware::mach::queue::dequeue (void)
{
	if (empty ())
		return false;
	
	bool result;
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "dequeue";
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return std::string (anyval (zmq::msg (expression_serial), "noware::mach::queue::nonempty")) == "1";
	/*
	result = std::string (anyval (zmq::msg (expression_serial), "noware::mach::queue::nonempty")) == "1";
	//return "";
	
	if (result)
	{
		if (empty_local ())
			assert (node.leave ("noware::mach::queue::nonempty"));
		
		if (!full_local ())
			// There is now, at least, one free spot.
			assert (node.join ("noware::mach::queue::nonfull"));
	}
	
	return result;
	*/
}

const bool noware::mach::queue::enqueue (const std::string & element)
{
	if (full ())
		return false;
	
	bool result;
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "enqueue";
	expression ["element"] = element;
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	if (std::string (anyval (zmq::msg (expression_serial), "noware::mach::queue::nonfull")) == "1")
	{
		// Enqueuing notice.
		zmq::msg notice;
		std::string peer_id;
		
		notice = "enqueued(instr)";
		notice.prepend (zmq::msg::frame ("noware::mach::dev::response::nondesired"));	// Optional
		notice.prepend (zmq::msg::frame (noware::random::string (16)));
		
		// Try to transmit: "An instruction was enqueued.".
		//node.multicast (notice, cpu::grp_dft);
		node.anycast (notice, peer_id, cpu::grp_dft);
		
		return true;
	}
	else
	{
		return false;
	}
	/*
	result = std::string (anyval (zmq::msg (expression_serial), "noware::mach::queue::nonfull")) == "1";
	
	if (result)
	{
		if (full_local ())
			assert (node.leave ("noware::mach::queue::nonfull"));
		
		if (!empty_local ())
			assert (node.join ("noware::mach::queue::nonempty"));
	}
	
	return result;
	*/
}

const bool/* success*/ noware::mach::queue::respond (zmq::msg & msg_response, const zmq::msg & msg_request, const zyre_event_t * event, const std::string & event_type, const std::string &/* src*/, const net::cast &/* src_cast*/)
{
	std::cerr << "noware::mach::queue::respond()::called" << std::endl;
	
	//zmq::msg msg;
	//zmsg_t * zmsg;
	//zmsg_t * zmsg_response;
	//zframe_t * zframe_response;
	//std::string event_type;
	
	//zmsg = zyre_event_msg (event);
	//msg = zyre_event_msg (event);
	//msg = zmsg;
	//event_type = zyre_event_type (event);
	//assert (event);
	//assert (zmsg);
	
	//noware::tree <std::string, std::string> response;
	std::map <std::string, std::string> response;
	//noware::tree <std::string, std::string> message;
	std::map <std::string, std::string> message;
	noware::var result_tmp;
	bool result;
	
//	zframe_t * frm;
	//noware::nr ndx;
	
	//data.clear ();
	//frm = zmsg_first (msg_rx);
//	frm = zmsg_first (zmsg);
	//ndx = 1;
	//while (frm != nullptr)
	//{
		// This makes a copy of the frame.
		//data [ndx] = *frm;
		
		//zframe_destroy (&f);
		
	//	frm = zmsg_next (&other);
	//	++ndx;
	//}
	
	//return other;
	for (const std::pair <unsigned int, zmq::msg::frame> & element : msg_request.data)
	{
		std::cerr << "noware::mach::queue::respond()::msg_request.data[" << element.first << "]==\"" << std::string (element.second) << "\"" << std::endl;
	}
	//std::cerr << "noware::mach::queue::respond()::std::string(msg_request.data[1])==[" << std::string (msg_request.data [1]) << "]" << std::endl;
	////if (!message.deserialize (msg_rx))
	if (!noware::deserialize <std::map <std::string, std::string>> (message, std::string (msg_request)))
	//if (!noware::deserialize <std::map <std::string, std::string>> (message, std::string ((char *) zframe_data (frm), zframe_size (frm))))
	{
		std::cerr << "noware::mach::queue::respond()::deserialize()==[failure]" << std::endl;
		
		return false;
	}
	std::cerr << "noware::mach::queue::respond()::deserialize()==[success]" << std::endl;

	result = false;
	
	std::cerr << "noware::mach::queue::respond()::if::message[subject]==[" << message ["subject"] << ']' << std::endl;
	
	//std::cerr << "noware::mach::queue::respond()::if::message[type]==" << message ["type"] << "::else::in scope" << std::endl;
	
	if (message ["subject"] == "size::count")
	{
		std::cerr << "noware::mach::queue::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["type"] = "response";
		response ["subject"] = message ["subject"];
		//response ["key"] = message ["key"];
		
		//std::cerr << "noware::mach::queue::respond()::not group[ed]" << std::endl;
		//response ["value"] = data.size ();
		//std::cerr << "noware::mach::queue::respond()::data.size ()==[" << data.size () << ']' << std::endl;
		//result_tmp = 0;
		//result_tmp += group.second.size ();
		result_tmp = queue.size ();
		response ["value"] = result_tmp.operator const std::string ();
		//response ["value"] = noware::var (queue.size ());
		//std::cerr << "noware::mach::queue::respond()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cerr << "noware::mach::queue::respond()::response[value]==[" << response ["value"] << ']' << std::endl;
	}
	else if (message ["subject"] == "next_dequeue")
	{
		std::cerr << "noware::mach::queue::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["type"] = "response";
		response ["subject"] = message ["subject"];
		//response ["key"] = message ["key"];
		
		//std::cerr << "noware::mach::queue::respond()::not group[ed]" << std::endl;
		//response ["value"] = data.size ();
		//std::cerr << "noware::mach::queue::respond()::data.size ()==[" << data.size () << ']' << std::endl;
		//result_tmp = 0;
		//result_tmp += group.second.size ();
		
		//result_tmp = queue.size ();
		//response ["value"] = result_tmp.operator const std::string ();
		if (empty_local ())
		{
			response ["success"] = "0";
		}
		else
		{
			response ["value"] = queue.front ();
			/*
			queue.pop ();
			
			if (empty_local ())
			{
				assert (node.leave ("noware::mach::queue::nonempty"));
			}
			
			assert (node.join ("noware::mach::queue::nonfull"));
			
			*/
			response ["success"] = "1";
			//response ["value"] = "1";
		}
		//response ["value"] = noware::var (queue.size ());
		//std::cerr << "noware::mach::queue::respond()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cerr << "noware::mach::queue::respond()::response[success]==[" << response ["success"] << ']' << std::endl;
		std::cerr << "noware::mach::queue::respond()::response[value]==[" << response ["value"] << ']' << std::endl;
		
		/*
		// Send back the answer.
		//result = node.unicast (zmq::msg (response.serialize ()), zyre_event_peer_uuid (event));
		std::string response_serial;
		if (!noware::serialize <std::map <std::string, std::string>> (response_serial, response))
			return false;
		result = node.unicast (zmq::msg (response_serial), zyre_event_peer_uuid (event));
		
		//zmsg_response = zmsg_new ();
		//zframe_response = zframe_new (response_serial.data (), response_serial.size ());
		//zmsg_append (zmsg_response, &zframe_response);
		
		//result = node.unicast (zmsg_response, zyre_event_peer_uuid (event));
		std::cerr << "noware::mach::queue::respond()::node.unicast(response,zyre_event_peer_uuid(event)==[" << (result ? "success" : "failure") << "]" << std::endl;
		//return result;
		
		if (result)
		{
			queue.pop ();
			
			return true;
		}
		
		return false;
		*/
		//return true;
	}
	else if (message ["subject"] == "next")
	{
		std::cerr << "noware::mach::queue::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["type"] = "response";
		response ["subject"] = message ["subject"];
		//response ["key"] = message ["key"];
		
		//std::cerr << "noware::mach::queue::respond()::not group[ed]" << std::endl;
		//response ["value"] = data.size ();
		//std::cerr << "noware::mach::queue::respond()::data.size ()==[" << data.size () << ']' << std::endl;
		//result_tmp = 0;
		//result_tmp += group.second.size ();
		
		//result_tmp = queue.size ();
		//response ["value"] = result_tmp.operator const std::string ();
		if (empty_local ())
		{
			response ["success"] = "0";
		}
		else
		{
			response ["value"] = queue.front ();
			response ["success"] = "1";
		}
		//response ["value"] = noware::var (queue.size ());
		//std::cerr << "noware::mach::queue::respond()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cerr << "noware::mach::queue::respond()::response[value]==[" << response ["value"] << ']' << std::endl;
	}
	else if (message ["subject"] == "dequeue")
	{
		std::cerr << "noware::mach::queue::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["type"] = "response";
		response ["subject"] = message ["subject"];
		//response ["key"] = message ["key"];
		
		//std::cerr << "noware::mach::queue::respond()::not group[ed]" << std::endl;
		//response ["value"] = data.size ();
		//std::cerr << "noware::mach::queue::respond()::data.size ()==[" << data.size () << ']' << std::endl;
		//result_tmp = 0;
		//result_tmp += group.second.size ();
		
		//result_tmp = queue.size ();
		//response ["value"] = result_tmp.operator const std::string ();
		if (empty_local ())
		{
			response ["value"] = "0";
		}
		else
		{
			queue.pop ();
			
			if (empty_local ())
			{
				assert (node.leave ("noware::mach::queue::nonempty"));
			}
			
			assert (node.join ("noware::mach::queue::nonfull"));
			
			response ["value"] = "1";
		}
		//response ["value"] = noware::var (queue.size ());
		//std::cerr << "noware::mach::queue::respond()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cerr << "noware::mach::queue::respond()::response[value]==[" << response ["value"] << ']' << std::endl;
	}
	else if (message ["subject"] == "enqueue")
	{
		std::cerr << "noware::mach::queue::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["type"] = "response";
		response ["subject"] = message ["subject"];
		//response ["key"] = message ["key"];
		
		//std::cerr << "noware::mach::queue::respond()::not group[ed]" << std::endl;
		//response ["value"] = data.size ();
		//std::cerr << "noware::mach::queue::respond()::data.size ()==[" << data.size () << ']' << std::endl;
		//result_tmp = 0;
		//result_tmp += group.second.size ();
		
		//result_tmp = queue.size ();
		//response ["value"] = result_tmp.operator const std::string ();
		if (full_local ())
		{
			response ["value"] = "0";
		}
		else
		{
			queue.push (message ["element"]);
			//response ["value"] = "1";
			
			if (full_local ())
			{
				assert (node.leave ("noware::mach::queue::nonfull"));
			}
			
			assert (node.join ("noware::mach::queue::nonempty"));
			
			//msg_result = "1";
			response ["value"] = "1";
		}
		//response ["value"] = noware::var (queue.size ());
		//std::cerr << "noware::mach::queue::respond()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cerr << "noware::mach::queue::respond()::response[value]==[" << response ["value"] << ']' << std::endl;
	}
	else
	{
		return false;
	}
	
	// Send back the answer.
	//result = node.unicast (zmq::msg (response.serialize ()), zyre_event_peer_uuid (event));
	std::string response_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (response_serial, response))
		return false;
	//result = node.unicast (zmq::msg (response_serial), zyre_event_peer_uuid (event));
	
	msg_response = response_serial;
	
	result = true;
	
	//zmsg_response = zmsg_new ();
	//zframe_response = zframe_new (response_serial.data (), response_serial.size ());
	//zmsg_append (zmsg_response, &zframe_response);
	
	//result = node.unicast (zmsg_response, zyre_event_peer_uuid (event));
	//std::cerr << "noware::mach::queue::respond()::node.unicast (response, zyre_event_peer_uuid (event)==" << (result ? "Success" : "Failure") << std::endl;
	//return result;
	
	return result;
}

const bool/* success*/ noware::mach::queue::respond_post (const zmq::msg & msg_response, const zmq::msg & msg_request, const zyre_event_t * event, const std::string & event_type, const std::string &/* src*/, const net::cast &/* src_cast*/, const bool & result)
{
	if (result)
	{
		std::map <std::string, std::string> message;
		
		if (!noware::deserialize <std::map <std::string, std::string>> (message, std::string (msg_request)))
		//if (!noware::deserialize <std::map <std::string, std::string>> (message, std::string ((char *) zframe_data (frm), zframe_size (frm))))
			return false;
		
		if (message ["subject"] == "next_dequeue")
		{
			if (empty_local ())
			{
				return false;
			}
			else
			{
				queue.pop ();
				
				if (empty_local ())
				{
					assert (node.leave ("noware::mach::queue::nonempty"));
				}
				
				assert (node.join ("noware::mach::queue::nonfull"));
				
				//response ["success"] = "1";
				////response ["value"] = "1";
				return true;
			}
		}
	}
	
	return true;
}

const bool/* success*/ noware::mach::queue::search (zmq::msg & msg_result, const zmq::msg & msg_resp, const noware::nr &/* total, expected resonses count*/, const noware::nr &/* current count of peers who responded (so far)*/, const std::string &/* src*/, const net::cast &/* src_cast*/)
{
	std::cerr << "noware::mach::queue::search()::called" << std::endl;
	
	//noware::tree <std::string, std::string> resp;
	std::map <std::string, std::string> resp;
	//noware::tree <std::string, std::string> result;
	//std::string result;
	noware::var result_tmp;
	//bool result;
	
	//if (!resp.deserialize (msg_resp))
	if (!noware::deserialize <std::map <std::string, std::string>> (resp, std::string (msg_resp)))
	{
		std::cerr << "noware::mach::queue::search()::deserialize::failure" << std::endl;
		return false;
	}
	std::cerr << "noware::mach::queue::search()::deserialize::success" << std::endl;
	
	
	//result ["subject"] = resp ["subject"];
	
	if (resp ["subject"] == "size::count")
	{
		std::cerr << "noware::mach::queue::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		result_tmp = msg_result;
		//if (result_tmp.kind () != noware::var::type::nr)
		//	result_tmp = 0;
		
		//result += data.size ();
		//result ["value"] += resp ["value"];
		result_tmp += noware::var (resp ["value"]);
		msg_result = result_tmp;
		
		std::cerr << "noware::mach::queue::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cerr << "noware::mach::queue::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return false;
	}
	/*
	else if (resp ["subject"] == "next_dequeue")
	{
		std::cerr << "noware::mach::queue::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		//std::cerr << "noware::mach::queue::search()::queue.front ()==[" << queue.front () << ']' << std::endl;
		
		//result_tmp = queue.front ();
		//std::cerr << "noware::mach::queue::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		
		if (resp ["success"] == "0")
			return false;
		
		//msg_result = result_tmp;
		//msg_result = queue.front ();
		msg_result = resp ["value"];
		std::cerr << "noware::mach::queue::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return true;
		//return false;
	}
	*/
	else if (resp ["subject"] == "next_dequeue" || resp ["subject"] == "next")
	{
		std::cerr << "noware::mach::queue::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		//std::cerr << "noware::mach::queue::search()::queue.front ()==[" << queue.front () << ']' << std::endl;
		
		//result_tmp = queue.front ();
		//std::cerr << "noware::mach::queue::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		
		if (resp ["success"] == "0")
			return false;
		
		//msg_result = result_tmp;
		//msg_result = queue.front ();
		msg_result = resp ["value"];
		std::cerr << "noware::mach::queue::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return true;
		//return false;
	}
	else if (resp ["subject"] == "dequeue")
	{
		std::cerr << "noware::mach::queue::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		/*
		queue.pop ();
		
		if (empty_local ())
		{
			assert (node.leave ("noware::mach::queue::nonempty"));
		}
		
		assert (node.join ("noware::mach::queue::nonfull"));
		
		
		msg_result = "1";
		
		std::cerr << "noware::mach::queue::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cerr << "noware::mach::queue::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return true;
		*/
		
		msg_result = resp ["value"];
		
		return msg_result == "1";
	}
	else if (resp ["subject"] == "enqueue")
	{
		std::cerr << "noware::mach::queue::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		/*
		queue.push (resp ["element"]);
		
		if (full_local ())
		{
			assert (node.leave ("noware::mach::queue::nonfull"));
		}
		
		assert (node.join ("noware::mach::queue::nonempty"));
		
		
		msg_result = "1";
		
		std::cerr << "noware::mach::queue::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cerr << "noware::mach::queue::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return true;
		*/
		
		msg_result = resp ["value"];
		
		return msg_result == "1";
	}
	
	return false;
}

const bool/* success*/ noware::mach::queue::search_local (zmq::msg & msg_result, const zmq::msg & msg_req, const std::string &/* src*/, const net::cast &/* src_cast*/)
{
	std::cerr << "noware::mach::queue::search_local()::called" << std::endl;
	
	//std::cerr << "noware::mach::queue::search_local()::message[subject]==[" << message ["subject"] << ']' << std::endl;
	
	
	//noware::tree <std::string, std::string> req;
	std::map <std::string, std::string> req;
	//noware::tree <std::string, std::string> resp;
	//noware::var resp;
	std::cerr << "noware::mach::queue::search_local()::req" << std::endl;
	//noware::var result_local;
	//bool result;
	std::cerr << "noware::mach::queue::search_local()::result" << std::endl;
	
	//if (!req.deserialize (msg_req))
	if (!noware::deserialize <std::map <std::string, std::string>> (req, std::string (msg_req)))
	{
		std::cerr << "noware::mach::queue::search_local()::deserialize::false" << std::endl;
		return false;
	}
	
	std::cerr << "noware::mach::queue::search_local()::deserialize" << std::endl;
	
	//resp ["subject"] = req ["subject"];
	
	std::cerr << "noware::mach::queue::search_local()::req[\"subject\"]==[" << req ["subject"] << ']' << std::endl;
	
	if (req ["subject"] == "size::count")
	{
		//if (result.type () != noware::var::container::type::numeric)
		msg_result = noware::nr (queue.size ());
		
		
		//resp ["value"] = result;
		//msg_resp = resp.serialize ();
		//msg_resp = result;
		//std::cerr << "noware::mach::queue::search_local()::magnitude::result==[" << result << ']' << std::endl;
		std::cerr << "noware::mach::queue::search_local()::[" << req ["subject"] << "]::result==[" << std::string (msg_result) << ']' << std::endl;
		//std::cerr << "noware::mach::queue::search_local()::magnitude::msg_resp==[" << std::string (msg_resp) << ']' << std::endl;
		return false;
	}
	else if (req ["subject"] == "next_dequeue")
	{
		//if (result.type () != noware::var::container::type::numeric)
		//result = queue.size ();
		
		if (empty_local ())
		{
			//msg_result = "";
			
			return false;
		}
		
		
		msg_result = queue.front ();
		queue.pop ();
		
		if (empty_local ())
		{
			assert (node.leave ("noware::mach::queue::nonempty"));
		}
		
		assert (node.join ("noware::mach::queue::nonfull"));
		
		//resp ["value"] = result;
		//msg_resp = resp.serialize ();
		//msg_resp = result;
		//std::cerr << "noware::mach::queue::search_local()::magnitude::result==[" << result << ']' << std::endl;
		std::cerr << "noware::mach::queue::search_local()::[" << req ["subject"] << "]::result==[" << std::string (msg_result) << ']' << std::endl;
		//std::cerr << "noware::mach::queue::search_local()::magnitude::msg_resp==[" << std::string (msg_resp) << ']' << std::endl;
		return true;
	}
	else if (req ["subject"] == "next")
	{
		//if (result.type () != noware::var::container::type::numeric)
		//result = queue.size ();
		
		if (empty_local ())
		{
			//msg_result = "";
			
			return false;
		}
		
		
		msg_result = queue.front ();
		//resp ["value"] = result;
		//msg_resp = resp.serialize ();
		//msg_resp = result;
		//std::cerr << "noware::mach::queue::search_local()::magnitude::result==[" << result << ']' << std::endl;
		std::cerr << "noware::mach::queue::search_local()::[" << req ["subject"] << "]::result==[" << std::string (msg_result) << ']' << std::endl;
		//std::cerr << "noware::mach::queue::search_local()::magnitude::msg_resp==[" << std::string (msg_resp) << ']' << std::endl;
		return true;
	}
	else if (req ["subject"] == "dequeue")
	{
		//if (result.type () != noware::var::container::type::numeric)
		//result = queue.size ();
		
		if (empty_local ())
		{
			msg_result = "0";
			
			return false;
		}
		
		
		queue.pop ();
		
		if (empty_local ())
		{
			assert (node.leave ("noware::mach::queue::nonempty"));
		}
		
		assert (node.join ("noware::mach::queue::nonfull"));
		
		msg_result = "1";
		//resp ["value"] = result;
		//msg_resp = resp.serialize ();
		//msg_resp = result;
		//std::cerr << "noware::mach::queue::search_local()::magnitude::result==[" << result << ']' << std::endl;
		std::cerr << "noware::mach::queue::search_local()::[" << req ["subject"] << "]::result==[" << std::string (msg_result) << ']' << std::endl;
		//std::cerr << "noware::mach::queue::search_local()::magnitude::msg_resp==[" << std::string (msg_resp) << ']' << std::endl;
		return true;
	}
	else if (req ["subject"] == "enqueue")
	{
		//if (result.type () != noware::var::container::type::numeric)
		//result = queue.size ();
		
		if (full_local ())
		{
			msg_result = "0";
			
			return false;
		}
		
		
		queue.push (req ["element"]);
		
		if (full_local ())
		{
			assert (node.leave ("noware::mach::queue::nonfull"));
		}
		
		assert (node.join ("noware::mach::queue::nonempty"));
		
		msg_result = "1";
		//resp ["value"] = result;
		//msg_resp = resp.serialize ();
		//msg_resp = result;
		//std::cerr << "noware::mach::queue::search_local()::magnitude::result==[" << result << ']' << std::endl;
		std::cerr << "noware::mach::queue::search_local()::[" << req ["subject"] << "]::result==[" << std::string (msg_result) << ']' << std::endl;
		//std::cerr << "noware::mach::queue::search_local()::magnitude::msg_resp==[" << std::string (msg_resp) << ']' << std::endl;
		return true;
	}
	
	return false;
}

const zmq::msg/* result*/ noware::mach::queue::aggregate (const zmq::msg & result, const zmq::msg & response, const zmq::msg & expression, const noware::nr & responses_count/* number of peers who answered*/, const std::string &/* src*/, const net::cast &/* src_cast*/)
{
	//noware::tree <std::string, std::string> xpr;
	std::map <std::string, std::string> xpr;
	//noware::tree <std::string, std::string> resp_;
	//noware::tree <std::string, std::string> result_;
	noware::var resp;
	noware::var reslt;
	
	
	// Local
	reslt = std::string (result);
	// Remote
	resp = std::string (response);
	
	//if (!xpr.deserialize (expression))
	if (!noware::deserialize <std::map <std::string, std::string>> (xpr, std::string (expression)))
		return response;
	
	if (xpr ["subject"] == "size::count")
	{
		return (reslt + resp).operator const std::string ();
	}
	/*
	else if (xpr ["subject"] == "removal" || xpr ["subject"] == "clearance")
	{
		std::cerr << "noware::mach::store::respond()::if::expression[subject]==" << xpr ["subject"] << "::in scope" << std::endl;
		std::cerr << "noware::mach::store::respond()::if::expression[subject]==" << xpr ["subject"] << "::in scope::reponses_count==[" << responses_count << "]" << std::endl;
		
		//if (responses_count > noware::nr::natural (0))
		if (responses_count > 0)
		{
			std::cerr << "noware::mach::store::respond()::if::(responses_count > noware::nr::natural (0))" << "::in scope" << std::endl;
			
			return zmq::msg ((result == "1" && response == "1") ? "1" : "0");
		}
		else
		{
			std::cerr << "noware::mach::store::respond()::if::(responses_count > noware::nr::natural (0))" << "::else::in scope" << std::endl;
			
			return result;
		}
	}
	*/
	
	return response;
}
