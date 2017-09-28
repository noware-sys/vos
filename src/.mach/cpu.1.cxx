//#pragma once

//#include "processor.hdr.cxx"

const std::string noware::mach::cpu::grp_dft = "cpu";

noware::mach::cpu::instr::instr (void)
{
	operation = operation::none;
}

noware::mach::cpu::instr::~instr (void)
{
}

noware::mach::cpu::instr::val (void)
{
	return "";
}

noware::mach::cpu::cpu (void)
{
	assert (node.join (grp_dft));
}

noware::mach::cpu::~cpu (void)
{
}

const noware::nr noware::mach::cpu::size (void) const
{
	//bool result;
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "magnitude";
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return 0;
	
	return std::string (anyval (zmq::msg (expression_serial), noware::mach::queue::grp_dft));
}

const bool noware::mach::cpu::empty (void) const
{
	return size () <= 0;
}

const bool noware::mach::cpu::full (void) const
{
	return false;
}

const instr noware::mach::cpu::next (void) const
{
	instr inst;
	
	if (full ())
		return inst;
	
	bool result;
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "next";
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return inst;
	
	return instr (std::string (anyval (zmq::msg (expression_serial), "queue.nonempty")) == "1");
}

const bool noware::mach::cpu::dequeue (void)
{
	if (full ())
		return false;
	
	bool result;
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "dequeue";
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	return std::string (anyval (zmq::msg (expression_serial), "queue.nonempty")) == "1";
}

const bool noware::mach::cpu::enqueue (const instr & inst)
{
	//return false;
	
	if (full ())
		return false;
	
	bool result;
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "enqueue";
	expression ["element"] = inst.serialize ();
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	return std::string (anyval (zmq::msg (expression_serial), "queue.nonfull")) == "1";
}

const bool noware::mach::cpu::enqueue (const noware::var & operand1, const opr & op, const noware::var & operand2)
{
	instr inst;
	
	inst.oprn = op;
	inst.oprnd [0] = operand1;
	inst.oprnd [1] = operand2;
	
	return enqueue (inst);
}

const bool/* success*/ noware::mach::cpu::respond (const zyre_event_t * event)
{
	std::cout << "noware::mach::queue::respond()::called" << std::endl;
	
	zmq::msg msg;
	zmsg_t * zmsg;
	//zmsg_t * zmsg_response;
	//zframe_t * zframe_response;
	std::string event_type;
	
	//zmsg = zyre_event_msg (event);
	//msg = zyre_event_msg (event);
	//msg = zmsg;
	//event_type = zyre_event_type (event);
	//assert (event);
	//assert (zmsg);
	
	event_type = zyre_event_type (event);
	if (event_type != "WHISPER" && event_type != "SHOUT")
	{
		std::cout << "noware::mach::queue::respond()::event not of interest" << std::endl;
		
		return false;
	}
	std::cout << "noware::mach::queue::respond()::event==" << event_type << std::endl;
	
	zmsg = zyre_event_msg (event);
	if (zmsg == nullptr)
	{
		std::cout << "noware::mach::queue::respond()::event_msg==nullptr" << std::endl;
		
		return false;
	}
	
	std::cout << "noware::mach::queue::respond()::event of interest" << std::endl;
	msg = zmsg;
	
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
	////if (!message.deserialize (msg_rx))
	if (!noware::deserialize <std::map <std::string, std::string>> (message, std::string (msg)))
	//if (!noware::deserialize <std::map <std::string, std::string>> (message, std::string ((char *) zframe_data (frm), zframe_size (frm))))
		return false;
	
	result = false;
	
	std::cout << "noware::mach::queue::respond()::if::message[subject]==[" << message ["subject"] << ']' << std::endl;
	
	if (message ["type"] == "response")
	{
		std::cout << "noware::mach::queue::respond()::if::message[type]==" << message ["type"] << "::in scope" << std::endl;
		
		//if (message ["subject"] == "existence")
		//{
			std::cout << "noware::mach::queue::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			//std::cout << "noware::mach::queue::receive()::else::msg[subject]==" << msg ["subject"] << "::sleeping" << std::endl;
			//zclock_sleep (1500);
			
			// Redirect the message to the function which asked for it.
			////unicast_local (zmsg_popstr (zmq_msg));
			//result = unicast_local (msg_rx);
			result = unicast_local (msg, "");
			std::cout << "noware::mach::queue::respond()::unicast_local(message)==" << (result ? "success" : "failure") << std::endl;
		//}
	}
	else	// if (message ["type"] == "request")
	{
		//std::cout << "noware::mach::queue::respond()::if::message[type]==" << message ["type"] << "::else::in scope" << std::endl;
		
		if (message ["subject"] == "magnitude")
		{
			std::cout << "noware::mach::queue::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			//response ["key"] = message ["key"];
			
			//std::cout << "noware::mach::queue::respond()::not group[ed]" << std::endl;
			//response ["value"] = data.size ();
			//std::cout << "noware::mach::queue::respond()::data.size ()==[" << data.size () << ']' << std::endl;
			//result_tmp = 0;
			//result_tmp += group.second.size ();
			result_tmp = queue.size ();
			response ["value"] = result_tmp.operator const std::string ();
			//response ["value"] = noware::var (queue.size ());
			//std::cout << "noware::mach::queue::respond()::result_tmp==[" << result_tmp << ']' << std::endl;
			std::cout << "noware::mach::queue::respond()::response[value]==[" << response ["value"] << ']' << std::endl;
		}
		else if (message ["subject"] == "next")
		{
			std::cout << "noware::mach::queue::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			//response ["key"] = message ["key"];
			
			//std::cout << "noware::mach::queue::respond()::not group[ed]" << std::endl;
			//response ["value"] = data.size ();
			//std::cout << "noware::mach::queue::respond()::data.size ()==[" << data.size () << ']' << std::endl;
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
			//std::cout << "noware::mach::queue::respond()::result_tmp==[" << result_tmp << ']' << std::endl;
			std::cout << "noware::mach::queue::respond()::response[value]==[" << response ["value"] << ']' << std::endl;
		}
		else if (message ["subject"] == "dequeue")
		{
			std::cout << "noware::mach::queue::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			//response ["key"] = message ["key"];
			
			//std::cout << "noware::mach::queue::respond()::not group[ed]" << std::endl;
			//response ["value"] = data.size ();
			//std::cout << "noware::mach::queue::respond()::data.size ()==[" << data.size () << ']' << std::endl;
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
				response ["value"] = "1";
			}
			//response ["value"] = noware::var (queue.size ());
			//std::cout << "noware::mach::queue::respond()::result_tmp==[" << result_tmp << ']' << std::endl;
			std::cout << "noware::mach::queue::respond()::response[value]==[" << response ["value"] << ']' << std::endl;
		}
		else if (message ["subject"] == "enqueue")
		{
			std::cout << "noware::mach::queue::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			//response ["key"] = message ["key"];
			
			//std::cout << "noware::mach::queue::respond()::not group[ed]" << std::endl;
			//response ["value"] = data.size ();
			//std::cout << "noware::mach::queue::respond()::data.size ()==[" << data.size () << ']' << std::endl;
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
				response ["value"] = "1";
			}
			//response ["value"] = noware::var (queue.size ());
			//std::cout << "noware::mach::queue::respond()::result_tmp==[" << result_tmp << ']' << std::endl;
			std::cout << "noware::mach::queue::respond()::response[value]==[" << response ["value"] << ']' << std::endl;
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
		result = node.unicast (zmq::msg (response_serial), zyre_event_peer_uuid (event));
		
		//zmsg_response = zmsg_new ();
		//zframe_response = zframe_new (response_serial.data (), response_serial.size ());
		//zmsg_append (zmsg_response, &zframe_response);
		
		//result = node.unicast (zmsg_response, zyre_event_peer_uuid (event));
		std::cout << "noware::mach::store::respond()::node.unicast (response, zyre_event_peer_uuid (event)==" << (result ? "Success" : "Failure") << std::endl;
		//return result;
	}
	
	return result;
}

const bool/* success*/ noware::mach::cpu::search (zmq::msg & msg_result, const zmq::msg & msg_resp)
{
	std::cout << "noware::mach::queue::search()::called" << std::endl;
	
	//noware::tree <std::string, std::string> resp;
	std::map <std::string, std::string> resp;
	//noware::tree <std::string, std::string> result;
	//std::string result;
	noware::var result_tmp;
	//bool result;
	
	//if (!resp.deserialize (msg_resp))
	if (!noware::deserialize <std::map <std::string, std::string>> (resp, std::string (msg_resp)))
	{
		std::cout << "noware::mach::queue::search()::deserialize::failure" << std::endl;
		return false;
	}
	std::cout << "noware::mach::queue::search()::deserialize::success" << std::endl;
	
	
	//result ["subject"] = resp ["subject"];
	
	if (resp ["subject"] == "magnitude")
	{
		std::cout << "noware::mach::queue::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		result_tmp = msg_result;
		//if (result_tmp.kind () != noware::var::type::nr)
		//	result_tmp = 0;
		
		//result += data.size ();
		//result ["value"] += resp ["value"];
		result_tmp += noware::var (resp ["value"]);
		msg_result = result_tmp;
		
		std::cout << "noware::mach::queue::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cout << "noware::mach::queue::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return false;
	}
	else if (resp ["subject"] == "next")
	{
		std::cout << "noware::mach::queue::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		//std::cout << "noware::mach::queue::search()::queue.front ()==[" << queue.front () << ']' << std::endl;
		
		//result_tmp = queue.front ();
		//std::cout << "noware::mach::queue::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		
		if (resp ["success"] == "0")
			return false;
		
		//msg_result = result_tmp;
		//msg_result = queue.front ();
		msg_result = resp ["value"];
		std::cout << "noware::mach::queue::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return true;
		//return false;
	}
	else if (resp ["subject"] == "dequeue")
	{
		std::cout << "noware::mach::queue::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		/*
		queue.pop ();
		
		if (empty_local ())
		{
			assert (node.leave ("queue.nonempty"));
		}
		
		assert (node.join ("queue.nonfull"));
		
		
		msg_result = "1";
		
		std::cout << "noware::mach::queue::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cout << "noware::mach::queue::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return true;
		*/
		
		msg_result = resp ["value"];
		
		return msg_result == "1";
	}
	else if (resp ["subject"] == "enqueue")
	{
		std::cout << "noware::mach::queue::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		/*
		queue.push (resp ["element"]);
		
		if (full_local ())
		{
			assert (node.leave ("queue.nonfull"));
		}
		
		assert (node.join ("queue.nonempty"));
		
		
		msg_result = "1";
		
		std::cout << "noware::mach::queue::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cout << "noware::mach::queue::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return true;
		*/
		
		msg_result = resp ["value"];
		
		return msg_result == "1";
	}
	
	return false;
}

const bool/* success*/ noware::mach::cpu::search_local (zmq::msg & msg_result, const zmq::msg & msg_req)
{
	std::cout << "noware::mach::queue::search_local()::called" << std::endl;
	
	//std::cout << "noware::mach::queue::search_local()::message[subject]==[" << message ["subject"] << ']' << std::endl;
	
	
	//noware::tree <std::string, std::string> req;
	std::map <std::string, std::string> req;
	//noware::tree <std::string, std::string> resp;
	//noware::var resp;
	std::cout << "noware::mach::queue::search_local()::req" << std::endl;
	//noware::var result_local;
	//bool result;
	std::cout << "noware::mach::queue::search_local()::result" << std::endl;
	
	//if (!req.deserialize (msg_req))
	if (!noware::deserialize <std::map <std::string, std::string>> (req, std::string (msg_req)))
	{
		std::cout << "noware::mach::queue::search_local()::deserialize::false" << std::endl;
		return false;
	}
	
	std::cout << "noware::mach::queue::search_local()::deserialize" << std::endl;
	
	//resp ["subject"] = req ["subject"];
	
	std::cout << "noware::mach::queue::search_local()::req[\"subject\"]==[" << req ["subject"] << ']' << std::endl;
	
	if (req ["subject"] == "magnitude")
	{
		//if (result.type () != noware::var::container::type::numeric)
		msg_result = noware::nr (queue.size ());
		
		
		//resp ["value"] = result;
		//msg_resp = resp.serialize ();
		//msg_resp = result;
		//std::cout << "noware::mach::queue::search_local()::magnitude::result==[" << result << ']' << std::endl;
		std::cout << "noware::mach::queue::search_local()::[" << req ["subject"] << "]::result==[" << std::string (msg_result) << ']' << std::endl;
		//std::cout << "noware::mach::queue::search_local()::magnitude::msg_resp==[" << std::string (msg_resp) << ']' << std::endl;
		return false;
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
		//std::cout << "noware::mach::queue::search_local()::magnitude::result==[" << result << ']' << std::endl;
		std::cout << "noware::mach::queue::search_local()::[" << req ["subject"] << "]::result==[" << std::string (msg_result) << ']' << std::endl;
		//std::cout << "noware::mach::queue::search_local()::magnitude::msg_resp==[" << std::string (msg_resp) << ']' << std::endl;
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
			assert (node.leave ("queue.nonempty"));
		}
		
		assert (node.join ("queue.nonfull"));
		
		msg_result = "1";
		//resp ["value"] = result;
		//msg_resp = resp.serialize ();
		//msg_resp = result;
		//std::cout << "noware::mach::queue::search_local()::magnitude::result==[" << result << ']' << std::endl;
		std::cout << "noware::mach::queue::search_local()::[" << req ["subject"] << "]::result==[" << std::string (msg_result) << ']' << std::endl;
		//std::cout << "noware::mach::queue::search_local()::magnitude::msg_resp==[" << std::string (msg_resp) << ']' << std::endl;
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
			assert (node.leave ("queue.nonfull"));
		}
		
		assert (node.join ("queue.nonempty"));
		
		msg_result = "1";
		//resp ["value"] = result;
		//msg_resp = resp.serialize ();
		//msg_resp = result;
		//std::cout << "noware::mach::queue::search_local()::magnitude::result==[" << result << ']' << std::endl;
		std::cout << "noware::mach::queue::search_local()::[" << req ["subject"] << "]::result==[" << std::string (msg_result) << ']' << std::endl;
		//std::cout << "noware::mach::queue::search_local()::magnitude::msg_resp==[" << std::string (msg_resp) << ']' << std::endl;
		return true;
	}
	
	return false;
}

const zmq::msg/* result*/ noware::mach::cpu::aggregate (const zmq::msg & result, const noware::nr & responses_count/* number of peers who answered*/, const zmq::msg & response, const zmq::msg & expression)
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
	
	if (xpr ["subject"] == "magnitude")
	{
		return (reslt + resp).operator const std::string ();
	}
	/*
	else if (xpr ["subject"] == "removal" || xpr ["subject"] == "clearance")
	{
		std::cout << "noware::mach::store::respond()::if::expression[subject]==" << xpr ["subject"] << "::in scope" << std::endl;
		std::cout << "noware::mach::store::respond()::if::expression[subject]==" << xpr ["subject"] << "::in scope::reponses_count==[" << responses_count << "]" << std::endl;
		
		//if (responses_count > noware::nr::natural (0))
		if (responses_count > 0)
		{
			std::cout << "noware::mach::store::respond()::if::(responses_count > noware::nr::natural (0))" << "::in scope" << std::endl;
			
			return zmq::msg ((result == "1" && response == "1") ? "1" : "0");
		}
		else
		{
			std::cout << "noware::mach::store::respond()::if::(responses_count > noware::nr::natural (0))" << "::else::in scope" << std::endl;
			
			return result;
		}
	}
	*/
	
	return response;
}
