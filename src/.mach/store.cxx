#pragma once

#include "store.hxx"
//#include <cstring>

//#include ".store/.incl.cxx"

std::string const noware::mach::store::grp_dft = "noware::mach::store";
bool const noware::mach::store::write_dft = true;
bool const noware::mach::store::cache_dft = true;

#include ".store/.cxx"

noware::mach::store::store (void)
{
////	node.initialize ();
////	node.start ();
//	assert (node.join (/*noware::mach::store::*/grp_dft));
	////assert (node.join (/*store::*/grp_dft));
//	assert (node.join ("noware::mach::store::nonfull")); // Temporary: dynamically find when needed.
////	node.reception_set (boost::bind (boost::mem_fn (&noware::mach::store::receive), this, _1));
	////node.reception_set (boost::mem_fn (&noware::mach::store::receive));
	////node.reception_set (&noware::mach::store::receive);
	write = write_dft; // Temporary: TODO: dynamically find this.
	cache = cache_dft;
}

noware::mach::store::~store (void)
{
//	node.reception_unset ();
	// node.leave (/*noware::mach::store::*/grp_dft);
//	node.stop ();
//	node.finalize ();
}

const bool noware::mach::store::start (void)
{
	if (!dev::start ())
		return false;
	
	if (!node.join (/*noware::mach::store::*/grp_dft))
		return false;
	
	if (!node.join ("noware::mach::store::nonfull")) // Temporary: dynamically find when needed.
		return false;
	
	return true;
}

//const noware::var noware::mach::store::evaluate (const noware::var & expression)
//{
//	return "";
//}
//

const zmq::msg noware::mach::store::aggregate (const zmq::msg & result, const zmq::msg & response, const zmq::msg & expression, const noware::nr & responses_count, const std::string &/* src*/, const net::cast &/* src_cast*/)
{
	//noware::tree <std::string, std::string> xpr;
	std::map <std::string, std::string> xpr;
	//noware::tree <std::string, std::string> resp_;
	//noware::tree <std::string, std::string> result_;
	noware::var resp;
	noware::var reslt;
	
	
	resp = std::string (response);
	reslt = std::string (result);
	
	//if (!xpr.deserialize (expression))
	if (!noware::deserialize <std::map <std::string, std::string>> (xpr, std::string (expression)))
		return response;
	
	if (xpr ["subject"] == "size::count")
	{
		return (reslt + resp).operator const std::string ();
	}
	else if (xpr ["subject"] == "size::avail")
	{
		return (reslt + resp).operator const std::string ();
	}
	else if (xpr ["subject"] == "size::total")
	{
		return (reslt + resp).operator const std::string ();
	}
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
	
	return response;
}

const bool noware::mach::store::respond (zmq::msg & msg_response, const zmq::msg & msg_request, /*const zmsg_t * msg_rx*//* received message*//*, */const zyre_event_t * event, const std::string & event_type, const std::string & src, const net::cast & src_cast)
{
	std::cerr << "noware::mach::store::respond()::called" << std::endl;
	
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
	////if (!message.deserialize (msg_rx))
	if (!noware::deserialize <std::map <std::string, std::string>> (message, std::string (msg_request)))
	//if (!noware::deserialize <std::map <std::string, std::string>> (message, std::string ((char *) zframe_data (frm), zframe_size (frm))))
		return false;
	
	result = false;
	
	std::cerr << "noware::mach::store::respond()::if::message[subject]==[" << message ["subject"] << ']' << std::endl;
	
	//std::cerr << "noware::mach::store::respond()::if::message[type]==" << message ["type"] << "::else::in scope" << std::endl;
	
	if (message ["subject"] == "existence")
	{
		std::cerr << "noware::mach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response = message;
		response ["type"] = "response";
		//response ["subject"] = message ["subject"];
		//response ["group"] = message ["group"];
		//response ["key"] = message ["key"];
		
		//if (!data.exist (message ["group"]))
		//	response ["value"] = false;
		//else
		try
		{
			data.at (message ["group"]).at (message ["key"]);
			response ["value"] = "1";
		}
		catch (...)
		{
			response ["value"] = "0";
		}
	}
	/*
	else if (message ["subject"] == "existence.group")
	{
		std::cerr << "noware::mach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["type"] = "response";
		response ["subject"] = message ["subject"];
		response ["group"] = message ["group"];
		//response ["key"] = message ["key"];
		//if (!data.exist (message ["group"]))
		//	response ["value"] = false;
		//else
			response ["value"] = data.exist (message ["group"]);
	}
	*/
	else if (message ["subject"] == "obtainment")
	{
		std::cerr << "noware::mach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["type"] = "response";
		response ["subject"] = message ["subject"];
		response ["group"] = message ["group"];
		response ["key"] = message ["key"];
		
		try
		{
			//std::pair <std::string, bool> value = data.at (message ["group"]).at (message ["key"]);
			response ["value"] = data.at (message ["group"]).at (message ["key"]);
			//response ["value"] = value.first;
			//response ["value.reference"] = value.second ? "1" : "0";
			response ["value.exist"] = "1";
		}
		catch (...)
		{
			response ["value.exist"] = "0";
		}
		
		std::cerr << "noware::mach::store::respond()::message[subject]==" << message ["subject"] << "::response[value.exist]==" << response ["value.exist"] << std::endl;
		if (response ["value.exist"] == "1")
			std::cerr << "noware::mach::store::respond()::message[subject]==" << message ["subject"] << "::response[value]==" << response ["value"] << std::endl;
	}
	else if (message ["subject"] == "assignment")
	{
		std::cerr << "noware::mach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["type"] = "response";
		response ["subject"] = message ["subject"];
		response ["group"] = message ["group"];
		response ["key"] = message ["key"];
		//response ["existence"] = data.exist (message ["group"]) && data.get (message ["group"]).exist (message ["key"]);
		
		if (!write || full_local ())
		{
			response ["value"] = "0";
			//return false;
		}
		else
		{
			//response ["type"] = "response";
			//response ["subject"] = message ["subject"];
			//response ["group"] = message ["group"];
			//response ["key"] = message ["key"];
			////response ["existence"] = data.exist (message ["group"]) && data.get (message ["group"]).exist (message ["key"]);
			
			data [message ["group"]] [message ["key"]] = message ["value"];
			//data [message ["group"]] [message ["key"]] = std::pair <std::string, bool> (message ["value"], message ["reference"] == "1" ? true : false);
			/*
			std::cerr << "noware::mach::store::respond()::if::message[subject]==" << message ["subject"] << "::try..." << std::endl;
			try
			{
				std::cerr << "noware::mach::store::respond()::if::message[subject]==" << message ["subject"] << "::try::in scope" << std::endl;
				if (data.at (message ["group"]).at (message ["key"]) == message ["value"])
				{
					std::cerr << "noware::mach::store::respond()::if::message[subject]==" << message ["subject"] << "::try::if" << std::endl;
					response ["value"] = "1";
				}
				else
				{
					std::cerr << "noware::mach::store::respond()::if::message[subject]==" << message ["subject"] << "::try::if::else" << std::endl;
					response ["value"] = "0";
				}
			}
			catch (...)
			{
				std::cerr << "noware::mach::store::respond()::if::message[subject]==" << message ["subject"] << "::try::catch" << std::endl;
				response ["value"] = "0";
			}
			
			//response ["value"] = "1";
			
			std::cerr << "noware::mach::store::respond()::if::message[subject]==" << message ["subject"] << "::response[value]==[" << response ["value"] << ']' << std::endl;
			//return response ["value"] == "1";
			*/
			
			if (full_local ())
				assert (node.leave ("noware::mach::store::nonfull"));
			
			assert (node.join ("noware::mach::store::nonempty"));
			
			response ["value"] = "1";
		}
	}
	else if (message ["subject"] == "removal")
	{
		std::cerr << "noware::mach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		std::cerr << "noware::mach::store::respond()::message[group]==" << message ["group"] << "" << std::endl;
		std::cerr << "noware::mach::store::respond()::message[key]==" << message ["key"] << "" << std::endl;
		
		try
		{
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["group"] = message ["group"];
			response ["key"] = message ["key"];
			
			if (data.count (message.at ("group")) <= 0 || data.at (message.at ("group")).count (message.at ("key")) <= 0)
			{
				response ["value"] = "1";
				//return true;
			}
			else if (!write)
			{
				response ["value"] = "0";
				//return false;
			}
			else
			{
				//response ["type"] = "response";
				//response ["subject"] = message ["subject"];
				//response ["group"] = message ["group"];
				//response ["key"] = message ["key"];
				////response ["meta"] = data.exist (message ["key"]);
				
				try
				{
					data.at (message ["group"]).erase (message ["key"]);
					response ["value"] = "1";
					
					if (data.at (message ["group"]).empty ())
						data.erase (message ["group"]);
				}
				catch (...)
				{
					// The group does not exist (idempotency).
					response ["value"] = "1";
				}
			}
		}
		catch (...)
		{
		}
	}
	else if (message ["subject"] == "size::count")
	{
		std::cerr << "noware::mach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["type"] = "response";
		response ["subject"] = message ["subject"];
		//response ["key"] = message ["key"];
		
		if (message.count ("group") > 0)
		{
			std::cerr << "noware::mach::store::respond()::group[ed]" << std::endl;
			
			if (data.count (message ["group"]) > 0)
			{
				std::cerr << "noware::mach::store::respond()::group::exist" << std::endl;
				response ["value"] = data [message ["group"]].size ();
			}
			else
			{
				std::cerr << "noware::mach::store::respond()::group::not exist" << std::endl;
				response ["value"] = "0";
			}
		}
		else
		{
			std::cerr << "noware::mach::store::respond()::not group[ed]" << std::endl;
			//response ["value"] = data.size ();
			//std::cerr << "noware::mach::store::respond()::data.size ()==[" << data.size () << ']' << std::endl;
			result_tmp = 0;
			for (const std::pair <std::string, std::map <std::string, std::string>> & group : data)
			{
				result_tmp += group.second.size ();
			}
			response ["value"] = result_tmp.operator const std::string ();
			
			std::cerr << "noware::mach::store::respond()::result_tmp==[" << result_tmp << ']' << std::endl;
			std::cerr << "noware::mach::store::respond()::response[value]==[" << response ["value"] << ']' << std::endl;
		}
	}
	else if (message ["subject"] == "size::avail")
	{
		std::cerr << "noware::mach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["type"] = "response";
		response ["subject"] = message ["subject"];
		//response ["key"] = message ["key"];
		
		if (message.count ("group") > 0)
		{
			std::cerr << "noware::mach::store::respond()::group[ed]" << std::endl;
			
			if (data.count (message ["group"]) > 0)
			{
				std::cerr << "noware::mach::store::respond()::group::exist" << std::endl;
				response ["value"] = data [message ["group"]].size ();
			}
			else
			{
				std::cerr << "noware::mach::store::respond()::group::not exist" << std::endl;
				response ["value"] = "0";
			}
		}
		else
		{
			std::cerr << "noware::mach::store::respond()::not group[ed]" << std::endl;
			//response ["value"] = data.size ();
			//std::cerr << "noware::mach::store::respond()::data.size ()==[" << data.size () << ']' << std::endl;
			result_tmp = 0;
			for (const std::pair <std::string, std::map <std::string, std::string>> & group : data)
			{
				result_tmp += group.second.size ();
			}
			response ["value"] = result_tmp.operator const std::string ();
			
			std::cerr << "noware::mach::store::respond()::result_tmp==[" << result_tmp << ']' << std::endl;
			std::cerr << "noware::mach::store::respond()::response[value]==[" << response ["value"] << ']' << std::endl;
		}
	}
	else if (message ["subject"] == "size::total")
	{
		std::cerr << "noware::mach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["type"] = "response";
		response ["subject"] = message ["subject"];
		//response ["key"] = message ["key"];
		
		if (message.count ("group") > 0)
		{
			std::cerr << "noware::mach::store::respond()::group[ed]" << std::endl;
			
			if (data.count (message ["group"]) > 0)
			{
				std::cerr << "noware::mach::store::respond()::group::exist" << std::endl;
				response ["value"] = data [message ["group"]].size ();
			}
			else
			{
				std::cerr << "noware::mach::store::respond()::group::not exist" << std::endl;
				response ["value"] = "0";
			}
		}
		else
		{
			std::cerr << "noware::mach::store::respond()::not group[ed]" << std::endl;
			//response ["value"] = data.size ();
			//std::cerr << "noware::mach::store::respond()::data.size ()==[" << data.size () << ']' << std::endl;
			result_tmp = 0;
			for (const std::pair <std::string, std::map <std::string, std::string>> & group : data)
			{
				result_tmp += group.second.size ();
			}
			response ["value"] = result_tmp.operator const std::string ();
			
			std::cerr << "noware::mach::store::respond()::result_tmp==[" << result_tmp << ']' << std::endl;
			std::cerr << "noware::mach::store::respond()::response[value]==[" << response ["value"] << ']' << std::endl;
		}
	}
	else if (message ["subject"] == "clearance")
	{
		std::cerr << "noware::mach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["subject"] = message ["subject"];
		response ["type"] = "response";
		
		if (!write)
		{
			response ["value"] = "0";
			//return false;
		}
		else
		{
			if (message.count ("group") > 0/* && data.count (message.at ("group")) > 0*/)
			{
				data.erase (message.at ("group"));
			}
			else
			{
				//response ["key"] = message ["key"];
				//response ["meta"] = data.exist (message ["key"]);
				//if (response ["meta"])
				data.clear ();
			}
			
			if (empty_local ())
				assert (node.leave ("noware::mach::store::nonempty"));
			
			assert (node.join ("noware::mach::store::nonfull"));
			
			//response ["subject"] = message ["subject"];
			//response ["type"] = "response";
			response ["value"] = "1";
		}
	}
	else
	{
		std::cerr << "noware::mach::store::respond()::else::return[false]" << std::endl;
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
//	std::cerr << "noware::mach::store::respond()::node.unicast (response, zyre_event_peer_uuid (event)==" << (result ? "Success" : "Failure") << std::endl;
	//return result;
	
	return result;
}

const bool noware::mach::store::search (zmq::msg & msg_result, const zmq::msg & msg_resp, const noware::nr &/* response_expected*/, const noware::nr &/* responses_occured*/, const std::string &/* src*/, const net::cast &/* src_cast*/)
{
	std::cerr << "noware::mach::store::search()::called" << std::endl;
	
	//noware::tree <std::string, std::string> resp;
	std::map <std::string, std::string> resp;
	//noware::tree <std::string, std::string> result;
	//std::string result;
	noware::var result_tmp;
	//bool result;
	
	//if (!resp.deserialize (msg_resp))
	if (!noware::deserialize <std::map <std::string, std::string>> (resp, std::string (msg_resp)))
	{
		std::cerr << "noware::mach::store::search()::deserialize::failure" << std::endl;
		return false;
	}
	std::cerr << "noware::mach::store::search()::deserialize::success" << std::endl;
	
	
	//result ["subject"] = resp ["subject"];
	
	if (resp ["subject"] == "existence")
	{
		msg_result = resp ["value"];
		
		return msg_result == "1";
	}
	/*
	else if (message ["subject"] == "existence.group")
	{
		result = message ["value"];
		
		return result;
	}
	*/
	else if (resp ["subject"] == "obtainment")
	{
		if (resp ["value.exist"] == "1")
		{
			msg_result = resp ["value"];
			return true;
		}
		
		return false;
	}
	else if (resp ["subject"] == "assignment")
	{
		msg_result = resp ["value"];
		
		return msg_result == "1";
	}
	else if (resp ["subject"] == "removal")
	{
		msg_result = resp ["value"];
		
		//return msg_result == "1";
		return false;
	}
	else if (resp ["subject"] == "size::count")
	{
		std::cerr << "noware::mach::store::search()::subject==magnitude" << std::endl;
		
		result_tmp = msg_result;
		if (result_tmp.t () != noware::var::type::nr)
			result_tmp = 0;
		
		//result += data.size ();
		//result ["value"] += resp ["value"];
		result_tmp += noware::var (resp ["value"]);
		msg_result = result_tmp;
		
		std::cerr << "noware::mach::store::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cerr << "noware::mach::store::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return false;
	}
	else if (resp ["subject"] == "size::avail")
	{
		std::cerr << "noware::mach::store::search()::subject==magnitude" << std::endl;
		
		result_tmp = msg_result;
		if (result_tmp.t () != noware::var::type::nr)
			result_tmp = 0;
		
		//result += data.size ();
		//result ["value"] += resp ["value"];
		result_tmp += noware::var (resp ["value"]);
		msg_result = result_tmp;
		
		std::cerr << "noware::mach::store::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cerr << "noware::mach::store::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return false;
	}
	else if (resp ["subject"] == "size::total")
	{
		std::cerr << "noware::mach::store::search()::subject==magnitude" << std::endl;
		
		result_tmp = msg_result;
		if (result_tmp.t () != noware::var::type::nr)
			result_tmp = 0;
		
		//result += data.size ();
		//result ["value"] += resp ["value"];
		result_tmp += noware::var (resp ["value"]);
		msg_result = result_tmp;
		
		std::cerr << "noware::mach::store::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cerr << "noware::mach::store::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return false;
	}
	else if (resp ["subject"] == "clearance")
	{
		msg_result = resp ["value"];
		
		//return msg_result == "1";
		return false;
	}
	
	return false;
}

const bool noware::mach::store::search_local (zmq::msg & msg_resp, const zmq::msg & msg_req, const std::string &/* src*/, const net::cast &/* src_cast*/)
{
	std::cerr << "noware::mach::store::search_local()::called" << std::endl;
	
	//std::cerr << "noware::mach::store::search_local()::message[subject]==[" << message ["subject"] << ']' << std::endl;
	
	
	//noware::tree <std::string, std::string> req;
	std::map <std::string, std::string> req;
	//noware::tree <std::string, std::string> resp;
	//noware::var resp;
	std::cerr << "noware::mach::store::search_local()::req" << std::endl;
	noware::var result;
	//bool result;
	std::cerr << "noware::mach::store::search_local()::result" << std::endl;
	
	//if (!req.deserialize (msg_req))
	if (!noware::deserialize <std::map <std::string, std::string>> (req, std::string (msg_req)))
	{
		std::cerr << "noware::mach::store::search_local()::deserialize::false" << std::endl;
		return false;
	}
	
	std::cerr << "noware::mach::store::search_local()::deserialize" << std::endl;
	
	//resp ["subject"] = req ["subject"];
	
	std::cerr << "noware::mach::store::search_local()::req[\"subject\"]==[" << req ["subject"] << ']' << std::endl;
	
	if (req ["subject"] == "existence")
	{
		std::cerr << "noware::mach::store::search_local()::req[\"subject\"]==[" << req ["subject"] << ']' << std::endl;
		
		try
		{
			std::cerr << "noware::mach::store::search_local()::req[\"subject\"]==[" << req ["subject"] << ']' << "::req.group" << std::endl;
			const std::string group_name = req.at ("group");
			std::cerr << "noware::mach::store::search_local()::req[\"subject\"]==[" << req ["subject"] << ']' << "::data.group" << std::endl;
			const std::map <std::string, std::string> group = data.at (req.at ("group"));
			std::cerr << "noware::mach::store::search_local()::req[\"subject\"]==[" << req ["subject"] << ']' << "::data.key" << std::endl;
			const std::string value = data.at (req.at ("group")).at (req.at ("key"));
			//const std::string value = group.at (req.at ("key"));
			
			//resp ["value"] = "1";
			//msg_resp = resp.serialize ();
			std::cerr << "noware::mach::store::search_local()::req[\"subject\"]==[" << req ["subject"] << ']' << "::msg_resp=\"1\"" << std::endl;
			msg_resp = "1";
			std::cerr << "noware::mach::store::search_local()::req[\"subject\"]==[" << req ["subject"] << ']' << "::return" << std::endl;
			return true;
		}
		catch (...)
		{
		}
		
		//resp ["value"] = "0";
		//msg_resp = resp.serialize ();
		msg_resp = "0";
		return false;
	}
	else if (req ["subject"] == "obtainment")
	{
		try
		{
			if (req.count ("type") > 0 && req.at ("type") == "range")
			{
				std::string val, grp;
				noware::nr ndx, size;
				
				ndx = req.at ("start");
				size = req.at ("size");
				grp = req.at ("group");
				
				for (val = ""; size > 0; --size, ++ndx)
					val += get (grp, ndx.operator std::string const ());
				
				msg_resp = val;
				return true;
			}
			else
			{
				// const std::string group_name = req.at ("group");
				// const std::map <std::string, std::string> group = data.at (req.at ("group"));
				const std::string value = data.at (req.at ("group")).at (req.at ("key"));
				//const std::pair <std::string, bool> value = data.at (req.at ("group")).at (req.at ("key"));
				//const std::string value = group.at (req.at ("key"));
				
				//std::string value_serial;
				//if (!noware::serialize <std::pair <std::string, bool>> (value_serial, value))
				//	return false;
				
				//resp ["value"] = value;
				//msg_resp = resp.serialize ();
				
				msg_resp = value;
				//msg_resp = value_serial;
				
				std::cerr << "noware::mach::store::search_local()::req[\"subject\"]==[" << req ["subject"] << "]::value==[" << value << "]" << std::endl;
				//std::cerr << "noware::mach::store::search_local()::req[\"subject\"]==[" << req ["subject"] << "]::value==[" << value_serial << "]" << std::endl;
				std::cerr << "noware::mach::store::search_local()::req[\"subject\"]==[" << req ["subject"] << "]::return true" << std::endl;
				
				return true;
			}
		}
		catch (...)
		{
			return false;
		}
		
		//msg_resp = "0";
		std::cerr << "noware::mach::store::search_local()::req[\"subject\"]==[" << req ["subject"] << "]::return false" << std::endl;
		return false;
	}
	else if (req ["subject"] == "assignment")
	{
		if (!write || full_local ())
		{
			msg_resp = "0";
			return false;
		}
		
		try
		{
			
			//data [req.at ("group")] [req.at ("key")] = std::pair <bool, std::string> (req.at ("reference") == "1" ? true : false, req.at ("value"));
			data [req.at ("group")] [req.at ("key")] = req.at ("value");
			
			//const std::map <std::string, std::string> & group = data.at (req.at ("group"));
			//std::string & value = data.at (req.at ("group")).at (req.at ("key"));
			
			if (full_local ())
				assert (node.leave ("noware::mach::store::nonfull"));
			
			assert (node.join ("noware::mach::store::nonempty"));
			
			
			//resp ["value"] = "1";
			//msg_resp = resp.serialize ();
			msg_resp = "1";
			return true;
		}
		catch (...)
		{
			//assert (node.leave ("noware::mach::store::nonempty"));
		}
		
		msg_resp = "0";
		return false;
	}
	else if (req ["subject"] == "removal")
	{
		//assert (node.join ("noware::mach::store::nonempty"));
		try
		{
			if (data.count (req.at ("group")) <= 0 || data.at (req.at ("group")).count (req.at ("key")) <= 0)
			{
				msg_resp = "1";
				return true;
			}
			else if (!write)
			{
				msg_resp = "0";
				return false;
			}
			
			data [req.at ("group")].erase (req.at ("key"));
			
			if (data [req.at ("group")].empty ())
				data.erase (req.at ("group"));
			
			
			if (empty_local ())
				assert (node.leave ("noware::mach::store::nonempty"));
			
			assert (node.join ("noware::mach::store::nonfull"));
			
			//resp ["value"] = "1";
			//msg_resp = resp.serialize ();
			//return true;
		}
		catch (...)
		{
		}
		
		// The group+key was absent...
		//resp ["value"] = "1";
		//msg_resp = resp.serialize ();
		msg_resp = "1";
		
		return true;
	}
	else if (req ["subject"] == "size::count")
	{
		//if (result.type () != noware::var::container::type::numeric)
		result = 0;
		
		try
		{
			const std::string group_name = req.at ("group");
			const std::map <std::string, std::string> group = data.at (req.at ("group"));
			
			result += data.at (req.at ("group")).size ();
			//result += group.size ();
		}
		catch (...)
		{
			for (const std::pair <std::string, std::map <std::string, std::string>> & group : data)
			{
				result += group.second.size ();
			}
		}
		
		
		//resp ["value"] = result;
		//msg_resp = resp.serialize ();
		msg_resp = result;
		std::cerr << "noware::mach::store::search_local()::magnitude::result==[" << result << ']' << std::endl;
		std::cerr << "noware::mach::store::search_local()::magnitude::msg_resp==[" << std::string (msg_resp) << ']' << std::endl;
		return false;
	}
	else if (req ["subject"] == "size::avail")
	{
		//if (result.type () != noware::var::container::type::numeric)
		result = 0;
		
		//resp ["value"] = result;
		//msg_resp = resp.serialize ();
		msg_resp = result;
		std::cerr << "noware::mach::store::search_local()::magnitude::result==[" << result << ']' << std::endl;
		std::cerr << "noware::mach::store::search_local()::magnitude::msg_resp==[" << std::string (msg_resp) << ']' << std::endl;
		return false;
	}
	else if (req ["subject"] == "size::total")
	{
		//if (result.type () != noware::var::container::type::numeric)
		result = 0;
		
		//resp ["value"] = result;
		//msg_resp = resp.serialize ();
		msg_resp = result;
		std::cerr << "noware::mach::store::search_local()::magnitude::result==[" << result << ']' << std::endl;
		std::cerr << "noware::mach::store::search_local()::magnitude::msg_resp==[" << std::string (msg_resp) << ']' << std::endl;
		return false;
	}
	else if (req ["subject"] == "clearance")
	{
		if (!write)
		{
			msg_resp = "0";
			return false;
		}
		
		if (req.count ("group") > 0/* && data.count (req.at ("group")) > 0*/)
		{
			//const std::string group_name = req.at ("group");
			//const std::map <std::string, std::string> group = data.at (req.at ("group"));
			
			data.erase (req.at ("group"));
		}
		else
		{
			/*result = */data.clear ();
		}
		
		if (empty_local ())
			assert (node.leave ("noware::mach::store::nonempty"));
		
		assert (node.join ("noware::mach::store::nonfull"));
		
		//resp ["subject"] = req ["subject"];
		
		//resp ["value"] = "1";
		//msg_resp = resp.serialize ();
		msg_resp = "1";
		//resp ["value"] = "1";
		//msg_resp = resp.serialize ();
		
		//return !result;
		return false;
	}
	/*
	else if (message ["subject"] == "iteration")
	{
		for (const noware::array <noware::array <>>::container & group : data)
		{
			for (const noware::array <>::container & key : group)
			{
				if (iterations >= message ["iterations"])
				{
					result = key.v;
					
					break;
				}
				
				++ iterations;
			}
			
			if (iterations >= message ["iterations"])
			{
				break;
			}
		}
		
		return false;
	}
	*/
	
	return false;
}

const bool noware::mach::store::exist (const std::string & key) const
{
	return exist (std::string (""), key);
}

const bool noware::mach::store::exist (const std::string & group, const std::string & key) const
{
	//return !get (group, key).empty ();
	
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "existence";
	expression ["group"] = group;
	expression ["key"] = key;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return multival (zmq::msg (expression_serial), noware::mach::store::grp_dft) == "1";
}

const std::map <unsigned int, std::string> noware::mach::store::owner (const std::string & key) const
{
	std::map <unsigned int, std::string> owners;
	return owners;
}

const std::map <unsigned int, std::string> noware::mach::store::owner (const std::string & group, const std::string & key) const
{
	std::map <unsigned int, std::string> owners;
	return owners;
}

const std::string/*value*/ noware::mach::store::get (const std::string & key) const
//const std::pair <std::string/*value*/, bool/*reference*/> noware::mach::store::get (const std::string & key) const
{
	return get (std::string (""), key);
}

const std::string/*value*/ noware::mach::store::get (const std::string & group, const std::string & key) const
//const std::pair <std::string/*value*/, bool/*reference*/> noware::mach::store::get (const std::string & group, const std::string & key) const
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	//std::string response;
	//std::pair <std::string, bool> returned_value ("", false);
	
	expression ["subject"] = "obtainment";
	expression ["group"] = group;
	expression ["key"] = key;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return "";
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	
	//return multival (zmq::msg (expression_serial), noware::mach::store::grp_dft);
	return multival (zmq::msg (expression_serial), "noware::mach::store::nonempty");
	/*
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		//return std::pair <std::string, bool> ("", false);
		return returned_value;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	
	//return multival (zmq::msg (expression_serial), noware::mach::store::grp_dft);
	response = multival (zmq::msg (expression_serial), noware::mach::store::grp_dft);
	
	if (!noware::deserialize <std::pair <std::string, bool>> (returned_value, response))
		//return std::pair <std::string, bool> ("", false);
		return returned_value;
	
	return returned_value;
	*/
}

std::string const/* value*/ noware::mach::store::get (std::string const & group, noware::nr const & start, noware::nr const & size) const
{
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "obtainment";
	expression ["group"] = group;
	//expression ["key"] = key;
	
	expression ["type"] = "range";
	expression ["start"] = start.operator std::string const ();
	expression ["size"] = size.operator std::string const ();
	
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return "";
	
	return multival (zmq::msg (expression_serial), "noware::mach::store::nonempty");
}

std::string const/* value*/ noware::mach::store::get (noware::nr const & start, noware::nr const & size) const
{
	return get ("", start, size);
}

const bool noware::mach::store::set (const std::string & key, const std::string & value)
//const bool noware::mach::store::set (const std::string & key, const std::string & value, const bool & reference)
{
	return set ("", key, value);
	//return set ("", key, value, reference);
}

const bool noware::mach::store::set (const std::string & group, const std::string & key, const std::string & value)
//const bool noware::mach::store::set (const std::string & group, const std::string & key, const std::string & value, const bool & reference)
{
	/*
	if (cache)
	{
		try
		{
			
		}
		catch (...)
		{
			
		}
	}
	*/
	
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "assignment";
	expression ["group"] = group;
	expression ["key"] = key;
	expression ["value"] = value;
	//expression ["reference"] = reference ? "1" : "0";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	
	//return multival (zmq::msg (expression_serial), noware::mach::store::grp_dft) == "1";
//	return anyval (zmq::msg (expression_serial), noware::mach::store::grp_dft) == "1";
	return anyval (zmq::msg (expression_serial), "noware::mach::store::nonfull") == "1";
}

const noware::nr noware::mach::store::size (void) const
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "size::total";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
	{
		std::cerr << "noware::mach::store::size()::serialize::failure" << std::endl;
		
		return 0;
	}
	std::cerr << "noware::mach::store::size()::serialize::success" << std::endl;
	
	return std::string (multival (zmq::msg (expression_serial), noware::mach::store::grp_dft));
}

const noware::nr noware::mach::store::size_local (void) const
{
	//return used_local () + avail_local ();
	return 0;
}

const noware::nr noware::mach::store::used (void) const
//const unsigned int noware::mach::store::size (void) const
{
	return 0;
}

const noware::nr noware::mach::store::used_local (void) const
{
	return (sizeof data) * CHAR_BIT;
}

const noware::nr noware::mach::store::avail (void) const
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "size::avail";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return 0;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return std::string (multival (zmq::msg (expression_serial), noware::mach::store::grp_dft));
}

const noware::nr noware::mach::store::avail_local (void) const
{
	return 0;
}

//const noware::nr::natural noware::mach::store::size (void) const
const noware::nr noware::mach::store::count (void) const
//const unsigned int noware::mach::store::size (void) const
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "size::count";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
	{
		std::cerr << "noware::mach::store::size()::serialize::failure" << std::endl;
		
		return 0;
	}
	std::cerr << "noware::mach::store::size()::serialize::success" << std::endl;
	
	/*
	expression.clear ();
	std::cerr << "noware::mach::store::size()::expression.size ()==[" << expression.size () << ']' << std::endl;
	
	std::cerr << "noware::mach::store::size()::expression.deserialize()::..." << std::endl;
	if (!noware::deserialize <std::map <std::string, std::string>> (expression, expression_serial))
	{
		std::cerr << "noware::mach::store::size()::deserialize::failure" << std::endl;
		return 0;
	}
	
	std::cerr << "noware::mach::store::size()::deserialized:" << std::endl;
	std::cerr << '[' << std::endl;
	std::cerr << expression_serial << std::endl;
	std::cerr << ']' << std::endl;
	std::cerr << "noware::mach::store::size()::expression.size ()==[" << expression.size () << ']' << std::endl;
	
	std::cerr << "noware::mach::store::size()::zmq::msg(str):" << std::endl;
	std::cerr << '[' << std::endl;
	std::cerr << std::string (zmq::msg (expression_serial)) << std::endl;
	//zmq::msg test (expression_serial);
	//std::cerr << '}' << std::endl;
	//std::cerr << test.data [1].operator const std::string ();
	std::cerr << ']' << std::endl;
	
	std::cerr << "noware::mach::store::size()::assert()..." << std::endl;
	assert (expression_serial == std::string (zmq::msg (expression_serial)));
	std::cerr << "noware::mach::store::size()::assert()...OK" << std::endl;
	*/
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return std::string (multival (zmq::msg (expression_serial), noware::mach::store::grp_dft));
}

const noware::nr noware::mach::store::count_local (void) const
{
	return data.size ();
}

const noware::nr noware::mach::store::count (const std::string & group) const
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "size::count";
	expression ["group"] = group;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return 0;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return std::string (multival (zmq::msg (expression_serial), noware::mach::store::grp_dft));
}

const noware::nr noware::mach::store::count_local (const std::string & group) const
{
	try
	{
		return data.at (group).size ();
	}
	catch (...)
	{
		return 0;
	}
}

const bool noware::mach::store::empty (void) const
{
	return count () <= 0;
}

const bool noware::mach::store::empty_local (void) const
{
	return data.empty ();
	//return used_local () <= 0;
}

const bool noware::mach::store::full (void) const
{
	return false;
}

const bool noware::mach::store::full_local (void) const
{
	return false;
}

const bool noware::mach::store::remove (const std::string & key)
{
	return remove ("", key);
}

const bool noware::mach::store::remove (const std::string & group, const std::string & key)
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "clearance";
	expression ["group"] = group;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return multival (zmq::msg (expression_serial), noware::mach::store::grp_dft) == "1";
}

const bool noware::mach::store::clear (void)
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "clearance";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return multival (zmq::msg (expression_serial), noware::mach::store::grp_dft) == "1";
}

const bool noware::mach::store::clear (const std::string & group)
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "clearance";
	expression ["group"] = group;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return multival (zmq::msg (expression_serial), noware::mach::store::grp_dft) == "1";
}

/*
template <typename value>
virtual const iterator <value> noware::mach::store::begin (void) const
{
}

template <typename value>
virtual const iterator <value> noware::mach::store::end (void) const
{
}

template <typename value>
virtual const iterator <value> noware::mach::store::operator ++ (void)
{
}

template <typename value>
virtual const iterator <value> noware::mach::store::operator -- (void)
{
}

template <typename value>
virtual const bool noware::mach::store::operator == (const iterator <value> & other) const
{
}

template <typename value>
virtual const value noware::mach::store::operator * (void) const
{
}
*/

/*
// For range-based for looping:

virtual const misc::iterator <std::tuple <std::string, std::string, std::string>> begin (void) const;
//virtual const store begin (void) const
{
	misc::iterator <std::tuple <std::string, std::string, std::string>> iterator;
	
	return iterator;
}

virtual const misc::iterator <std::tuple <std::string, std::string, std::string>> end (void) const;
//virtual const store end (void) const
{}

virtual const std::tuple <std::string, std::string, std::string> operator * (void) const
{}

virtual const bool operator == (const misc::iterator <std::tuple <std::string, std::string, std::string>> & other) const;
//virtual const bool operator == (const store & other) const
{}

virtual const misc::iterator <std::tuple <std::string, std::string, std::string>> operator ++ (void);
//virtual const store operator ++ (void)
{
	std::cerr << "noware::mach::dev::multicast()::called" << std::endl;
	//if (!message.is_group ())
	//	return "";
	
	std::string request_token;
	zmq::msg msg_resp;
	//noware::nr responses_count;
	
	request_token = noware::random::string (token_size_dft);
	std::cerr << "noware::mach::dev::multicast()::request_token==[" << request_token << ']' << std::endl;
	
	msg_req.prepend (zmq::msg::frame ("noware::mach::dev::response::desired"));
	msg_req.prepend (zmq::msg::frame (request_token));
	
	if (!node.multicast (msg_req, group))
	{
		std::cerr << "noware::mach::dev::multicast()::node.multicast()::failure" << std::endl;
		return msg_resp;
	}
	
	std::cerr << "noware::mach::dev::multicast()::node.multicast()::success" << std::endl;
	
	iteration = receive_local (request_token, node.peers_size (group), responses_count, group, net::cast::multi);
	
	//return *this;
}

virtual const misc::iterator <std::tuple <std::string, std::string, std::string>> operator -- (void);
//virtual const store operator -- (void)
{}
*/
