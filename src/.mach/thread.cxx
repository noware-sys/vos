#pragma once

//const std::string noware::mach::queue::grp_dft = "noware::mach::thread";

noware::mach::thread::thread (void)
{
	main = false;
	_loaded = false;
	running = false;
	//grp = "";
	grp = "noware::mach::thread::1";
	ndx = 0;
	
	//node.join ("noware::mach::thread::1");
	node.join (grp);
}

noware::mach::thread::~thread (void)
{
}

const std::string noware::mach::thread::id (void) const
{
	return node.id ();
}

const std::string noware::mach::thread::group (void) const
{
	return grp;
}

const bool noware::mach::thread::stop (void)
{
	if (!status ())
		return true;
	
	running = false;
	
	return true;
}

const bool noware::mach::thread::status (void) const
{
	return running;
}

const bool noware::mach::thread::start (void)
{
	std::cout << "noware::mach::thread::start()::called" << std::endl;
	
	if (status ())
	{
		std::cout << "noware::mach::thread::start()::status()==false" << std::endl;
		return true;
	}
	std::cout << "noware::mach::thread::start()::status()==true" << std::endl;
	
	if (!loaded ())
	{
		std::cout << "noware::mach::thread::start()::!loaded()==true" << std::endl;
		return false;
	}
	std::cout << "noware::mach::thread::start()::!loaded()==false" << std::endl;
	
	ndx = 1;
	std::cout << "noware::mach::thread::start()::enqueue()::pre" << std::endl;
	assert (enqueue (instr [ndx]));
	std::cout << "noware::mach::thread::start()::enqueue()::post" << std::endl;
	
	running = true;
	
	return true;
}

const bool noware::mach::thread::clear (void)
{
	stop ();
	instr.clear ();
	ndx = 0;
	_loaded = false;
	
	return true;
}

const bool noware::mach::thread::loaded (void) const
{
	return _loaded;
}

const bool noware::mach::thread::load (const std::string & file_name)
{
	if (loaded ())
		clear ();
	
	std::ifstream file;
	std::string dest, src;
	cpu::instr _instr;
	unsigned int _ndx;
	
	file.open (file_name);
	
	if (!file.is_open ())
		return false;
	
	_ndx = 1;
	while (file >> dest >> src)
	{
		_instr.oprnd [0] = src;
		_instr.oprnd [1] = dest;
		//_instr.ndx = _ndx;
		
		_instr.thread_id = grp;
		//_instr.thread_id = id ();
		
		instr [_ndx] = _instr;
		
		++_ndx;
	}
	
	file.close ();
	
	_loaded = true;
	
	return true;
}

const bool noware::mach::thread::advance_local (void)
{
	++ndx;
	
	if (instr.count (ndx) == 0)
	// reset pointer
	{
		ndx = 1;
	}
	
	return true;
}

const bool noware::mach::thread::advance (void)
{
	return false;
}

const bool noware::mach::thread::enqueue (const cpu::instr & element)
{
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "enqueue";
	expression ["element"] = element.serialize ();
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	return std::string (anyval (zmq::msg (expression_serial), "noware::mach::queue::nonfull")) == "1";
}

const bool/* success*/ noware::mach::thread::respond (const zyre_event_t * event, const std::string & event_type, const zmq::msg & msg_request, zmq::msg & msg_response)
{
	std::cout << "noware::mach::thread::respond()::called" << std::endl;
	
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
	
	std::cout << "noware::mach::thread::respond()::msg_request.data::pre-loop" << std::endl;
	for (const std::pair <unsigned int, zmq::msg::frame> & element : msg_request.data)
	{
		std::cout << "noware::mach::thread::respond()::msg_request.data[" << element.first << "]==\"" << std::string (element.second) << "\"" << std::endl;
	}
	
	////if (!message.deserialize (msg_rx))
	if (!noware::deserialize <std::map <std::string, std::string>> (message, std::string (msg_request)))
	//if (!noware::deserialize <std::map <std::string, std::string>> (message, std::string ((char *) zframe_data (frm), zframe_size (frm))))
	{
		std::cout << "noware::mach::thread::respond()::deserialize::false" << std::endl;
		
		return false;
	}
	std::cout << "noware::mach::thread::respond()::deserialize::true" << std::endl;

	//result = false;
	
	std::cout << "noware::mach::thread::respond()::if::message[subject]==[" << message ["subject"] << ']' << std::endl;
	
	
	//std::cout << "noware::mach::thread::respond()::if::message[type]==" << message ["type"] << "::else::in scope" << std::endl;
	
	if (message ["subject"] == "notification")
	//if (message ["subject"] == "enqueue")
	{
		std::cout << "noware::mach::thread::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		//response = message;
		//response ["type"] = "response";
		
		//response ["subject"] = message ["subject"];
		//response ["group"] = message ["group"];
		//response ["key"] = message ["key"];
		
		if (message ["success"] == "1")
		{
			std::cout << "noware::mach::thread::respond()::advance_local()" << std::endl;
			advance_local ();
		}
		/*
			else
				try again
		*/
		
		if (running)
		{
			std::cout << "noware::mach::thread::respond()::running::true" << std::endl;
			std::cout << "noware::mach::thread::respond()::enqueue(ndx==[" << ndx << "])" << std::endl;
			assert (enqueue (instr [ndx]));
		}
		else
		{
			std::cout << "noware::mach::thread::respond()::running::false" << std::endl;
		}
	}
	/*
	else
	{
		return false;
	}
	*/
	
	/*
	// Send back the answer.
	//result = node.unicast (zmq::msg (response.serialize ()), zyre_event_peer_uuid (event));
	std::string response_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (response_serial, response))
		return false;
	result = node.unicast (zmq::msg (response_serial), zyre_event_peer_uuid (event));
	*/
	//msg_response = "1";
	
	//zmsg_response = zmsg_new ();
	//zframe_response = zframe_new (response_serial.data (), response_serial.size ());
	//zmsg_append (zmsg_response, &zframe_response);
	
	//result = node.unicast (zmsg_response, zyre_event_peer_uuid (event));
//	std::cout << "noware::mach::store::respond()::node.unicast (response, zyre_event_peer_uuid (event)==" << (result ? "Success" : "Failure") << std::endl;
	//return result;
	
	//return result;
	//return true;
	return false;
}

const bool/* success*/ noware::mach::thread::search (zmq::msg & msg_result, const zmq::msg & msg_resp)
{
	std::cout << "noware::mach::thread::search()::called" << std::endl;
	
	//noware::tree <std::string, std::string> resp;
	std::map <std::string, std::string> resp;
	//noware::tree <std::string, std::string> result;
	//std::string result;
	noware::var result_tmp;
	//bool result;
	
	//if (!resp.deserialize (msg_resp))
	if (!noware::deserialize <std::map <std::string, std::string>> (resp, std::string (msg_resp)))
	{
		std::cout << "noware::mach::thread::search()::deserialize::failure" << std::endl;
		return false;
	}
	std::cout << "noware::mach::thread::search()::deserialize::success" << std::endl;
	
	
	//result ["subject"] = resp ["subject"];
	
	if (resp ["subject"] == "enqueue")
	{
		std::cout << "noware::mach::thread::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		/*
		queue.push (resp ["element"]);
		
		if (full_local ())
		{
			assert (node.leave ("noware::mach::queue::nonfull"));
		}
		
		assert (node.join ("noware::mach::queue::nonempty"));
		
		
		msg_result = "1";
		
		std::cout << "noware::mach::queue::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cout << "noware::mach::queue::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return true;
		*/
		
		msg_result = resp ["value"];
		
		return msg_result == "1";
	}
	
	return false;
	//return true;
}

const bool/* success*/ noware::mach::thread::search_local (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/)
{
	std::cout << "noware::mach::thread::search_local()::called" << std::endl;
	
	return false;
}

const zmq::msg/* result*/ noware::mach::thread::aggregate (const zmq::msg &/* result*/, const noware::nr &/* responses_count*//* number of peers who answered*/, const zmq::msg & response, const zmq::msg &/* expression*/)
{
	return response;
}
