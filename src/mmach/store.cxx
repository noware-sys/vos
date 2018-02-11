#pragma once

//#include <cstring>
#include "store.hxx"

#include <noware/contnr/array.cxx>
#include "dev.cxx"
#include "../smach/store.cxx"

//#include ".store/.incl.cxx"

std::string const noware::mmach::store::grp_dft = "noware::mmach::store";
//bool const noware::mmach::store::write_dft = true;
bool const noware::mmach::store::cache_dft = true;
//unsigned short int const noware::pmach::store::copy_dft = 1;

//#include ".store/.cxx"

noware::mmach::store::store (void)
{
////	node.initialize ();
////	node.start ();
//	assert (node.join (/*noware::pmach::store::*/grp_dft));
	////assert (node.join (/*store::*/grp_dft));
//	assert (node.join ("noware::pmach::store::nonfull")); // Temporary: dynamically find when needed.
////	node.reception_set (boost::bind (boost::mem_fn (&noware::pmach::store::receive), this, _1));
	////node.reception_set (boost::mem_fn (&noware::pmach::store::receive));
	////node.reception_set (&noware::pmach::store::receive);
	
//	write = write_dft; // Temporary: TODO: dynamically find this.
	cache = cache_dft;
//	copy = copy_dft;
}

noware::mmach::store::~store (void)
{
//	node.reception_unset ();
	// node.leave (/*noware::pmach::store::*/grp_dft);
//	node.stop ();
//	node.finalize ();
}

bool const noware::mmach::store::start (void)
{
	if (!net::node::start ())
		return false;
	
	if (!_node.join (grp_dft))
		return false;
	
	return true;
}

/*
bool const noware::mmach::store::start (void)
{
	if (!dev::start ())
		return false;
	
	if (!node.join (grp_dft))
		return false;
	
	//if (!node.join (grp_dft + std::string ("::nonfull"))) // Temporary: dynamically find when needed.
	//	return false;
	
	return true;
}
*/

//const noware::var noware::pmach::store::evaluate (const noware::var & expression)
//{
//	return "";
//}
//

zmq::msg const noware::mmach::store::aggregate (zmq::msg const & result, zmq::msg const & response, zmq::msg const & expression, cln::nr const & responses_count, std::string const &/* src*/, net::cast const &/* src_cast*/)
{
	std::cerr << "noware::mmach::store::aggregate()::response==[" << std::string (response) << "]" << std::endl;
	return response;
	
	/*
	//noware::tree <std::string, std::string> xpr;
	std::map <std::string, std::string> xpr;
	//noware::tree <std::string, std::string> resp_;
	//noware::tree <std::string, std::string> result_;
	noware::var resp;
	noware::var reslt;
	
	
	resp = std::string (response);
	reslt = std::string (result);
	
	std::cerr << "noware::mmach::store::aggregate()::if::(responses_count > noware::nr::natural (0))" << "::in scope::result==[" << std::string (result) << "]" << std::endl;
	std::cerr << "noware::mmach::store::aggregate()::if::(responses_count > noware::nr::natural (0))" << "::in scope::response==[" << std::string (response) << "]" << std::endl;
	std::cerr << "noware::mmach::store::aggregate()::if::(responses_count > noware::nr::natural (0))" << "::in scope::reslt==[" << reslt << "]" << std::endl;
	std::cerr << "noware::mmach::store::aggregate()::if::(responses_count > noware::nr::natural (0))" << "::in scope::resp==[" << resp << "]" << std::endl;
	
	//if (!xpr.deserialize (expression))
	if (!noware::deserialize <std::map <std::string, std::string>> (xpr, std::string (expression)))
		return response;
	
	if (xpr ["subject"] == "size::count")
	{
		return (reslt + resp).operator std::string const ();
	}
	else if (xpr ["subject"] == "size::avail")
	{
		return (reslt + resp).operator std::string const ();
	}
	else if (xpr ["subject"] == "size::total")
	{
		return (reslt + resp).operator std::string const ();
	}
	else if (xpr ["subject"] == "removal" || xpr ["subject"] == "clearance")
	{
		std::cerr << "noware::mmach::store::aggregate()::if::expression[subject]==" << xpr ["subject"] << "::in scope" << std::endl;
		std::cerr << "noware::mmach::store::aggregate()::if::expression[subject]==" << xpr ["subject"] << "::in scope::reponses_count==[" << responses_count << "]" << std::endl;
		
		//if (responses_count > noware::nr::natural (0))
		if (responses_count > 0)
		{
			std::cerr << "noware::mmach::store::aggregate()::if::(responses_count > noware::nr::natural (0))" << "::in scope" << std::endl;
			
			return zmq::msg ((result == "1" && response == "1") ? "1" : "0");
		}
		else
		{
			std::cerr << "noware::mmach::store::aggregate()::if::(responses_count > noware::nr::natural (0))" << "::else::in scope" << std::endl;
			
			return result;
		}
	}
	
	return response;
	*/
}

bool const noware::mmach::store::respond (zmq::msg & msg_response, zmq::msg const & msg_request, zyre_event_t const * const/* event*/, std::string const &/* event_type*/, std::string const &/* src*/, net::cast const &/* src_cast*/)
{
	std::cerr << "noware::mmach::store::respond()::called" << std::endl;
	
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
	
	std::cerr << "noware::mmach::store::respond()::if::message[subject]==[" << message ["subject"] << ']' << std::endl;
	
	//std::cerr << "noware::pmach::store::respond()::if::message[type]==" << message ["type"] << "::else::in scope" << std::endl;
	
	if (message ["subject"] == "existence")
	{
		std::cerr << "noware::mmach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response = message;
		response ["type"] = "response";
		//response ["subject"] = message ["subject"];
		//response ["group"] = message ["group"];
		//response ["key"] = message ["key"];
		
		//if (!data.exist (message ["group"]))
		//	response ["value"] = false;
		//else
		/*try
		{*/
			if (exist (message.at ("group"), message.at ("key")))
				response ["value"] = "1";
			else
				response ["value"] = "0";
		/*}
		catch (...)
		{
			response ["value"] = "0";
		}*/
	}
	/*
	else if (message ["subject"] == "existence.group")
	{
		std::cerr << "noware::pmach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
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
		std::cerr << "noware::mmach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["type"] = "response";
		response ["subject"] = message ["subject"];
		response ["group"] = message ["group"];
		response ["key"] = message ["key"];
		std::string value;
		
		try
		{
			if (get (message.at ("group"), message.at ("key"), value))
			{
				response ["value"] = value;
				response ["value.exist"] = "1";
			}
			else
				response ["value.exist"] = "0";
		}
		catch (...)
		{
			response ["value.exist"] = "0";
		}
		
		std::cerr << "noware::mmach::store::respond()::message[subject]==" << message ["subject"] << "::response[value.exist]==" << response ["value.exist"] << std::endl;
		if (response ["value.exist"] == "1")
			std::cerr << "noware::mmach::store::respond()::message[subject]==" << message ["subject"] << "::response[value]==" << response ["value"] << std::endl;
	}
	else if (message ["subject"] == "assignment")
	{
		std::cerr << "noware::mmach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["type"] = "response";
		response ["subject"] = message ["subject"];
		response ["group"] = message ["group"];
		response ["key"] = message ["key"];
		
		try
		{
			if (set (message.at ("group"), message.at ("key"), message.at ("value")))
			{
				response ["value"] = "1";
			}
			else
				response ["value"] = "0";
		}
		catch (...)
		{
			response ["value"] = "0";
		}
	}
	else if (message ["subject"] == "removal")
	{
		std::cerr << "noware::mmach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		std::cerr << "noware::mmach::store::respond()::message[group]==" << message ["group"] << "" << std::endl;
		std::cerr << "noware::mmach::store::respond()::message[key]==" << message ["key"] << "" << std::endl;
		
		try
		{
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["group"] = message ["group"];
			response ["key"] = message ["key"];
			
			if (remove (message.at ("group"), message.at ("key")))
			{
				std::cerr << "noware::mmach::store::respond()::removal::remove()::true" << std::endl;
				response ["value"] = "1";
			}
			else
			{
				std::cerr << "noware::mmach::store::respond()::removal::remove()::false" << std::endl;
				response ["value"] = "0";
			}
		}
		catch (...)
		{
			std::cerr << "noware::mmach::store::respond()::removal::caught(...)" << "" << std::endl;
			response ["value"] = "0";
		}
		
		std::cerr << "noware::mmach::store::respond()::removal::response[value]==" << response ["value"] << "" << std::endl;
	}
	else if (message ["subject"] == "size::count")
	{
		std::cerr << "noware::mmach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["type"] = "response";
		response ["subject"] = message ["subject"];
		//response ["key"] = message ["key"];
		
		response ["value"] = size ().operator std::string const ();
		//size ();
		//response ["value"] = "54321";
		std::cerr << "noware::mmach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope::response[value]::[" << response ["value"] << "]" << std::endl;
	}
	else if (message ["subject"] == "size::used")
	{
		std::cerr << "noware::mmach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["type"] = "response";
		response ["subject"] = message ["subject"];
		//response ["key"] = message ["key"];
		
		response ["value"] = used ().operator std::string const ();
	}
	else if (message ["subject"] == "size::avail")
	{
		std::cerr << "noware::mmach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["type"] = "response";
		response ["subject"] = message ["subject"];
		//response ["key"] = message ["key"];
		
		response ["value"] = avail ().operator std::string const ();
	}
	else if (message ["subject"] == "size::capac")
	{
		std::cerr << "noware::mmach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["type"] = "response";
		response ["subject"] = message ["subject"];
		//response ["key"] = message ["key"];
		
		response ["value"] = capac ().operator std::string const ();
	}
	else if (message ["subject"] == "clearance")
	{
		std::cerr << "noware::mmach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["subject"] = message ["subject"];
		response ["type"] = "response";
		
		if (message.count ("group") > 0/* && data.count (message.at ("group")) > 0*/)
		{
			if (clear (message.at ("group")))
				response ["value"] = "1";
			else
				response ["value"] = "0";
		}
		else
		{
			if (clear ())
				response ["value"] = "1";
			else
				response ["value"] = "0";
		}
	}
	else
	{
		std::cerr << "noware::mmach::store::respond()::else::return[false]" << std::endl;
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
//	std::cerr << "noware::pmach::store::respond()::node.unicast (response, zyre_event_peer_uuid (event)==" << (result ? "Success" : "Failure") << std::endl;
	//return result;
	
	return result;
}

bool const noware::mmach::store::search (zmq::msg & msg_result, zmq::msg const & msg_resp, cln::nr const &/* response_expected*/, cln::nr const &/* responses_occured*/, std::string const &/* src*/, net::cast const &/* src_cast*/)
{
	std::cerr << "noware::mmach::store::search()::called" << std::endl;
	
	//noware::tree <std::string, std::string> resp;
	std::map <std::string, std::string> resp;
	//noware::tree <std::string, std::string> result;
	//std::string result;
	noware::var result_tmp;
	//bool result;
	
	//if (!resp.deserialize (msg_resp))
	if (!noware::deserialize <std::map <std::string, std::string>> (resp, std::string (msg_resp)))
	{
		std::cerr << "noware::mmach::store::search()::deserialize::failure" << std::endl;
		return false;
	}
	std::cerr << "noware::mmach::store::search()::deserialize::success" << std::endl;
	
	
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
		/*
		if (resp ["value.exist"] == "1")
		{
			msg_result = resp ["value"];
			return true;
		}
		
		return false;
		*/
		msg_result = msg_resp;
		return resp ["value.exist"] == "1";
	}
	else if (resp ["subject"] == "assignment")
	{
		msg_result = resp ["value"];
		
		return msg_result == "1";
	}
	else if (resp ["subject"] == "removal")
	{
		msg_result = resp ["value"];
		std::cerr << "noware::mmach::store::search()::subject==removal" << std::endl;
		std::cerr << "noware::mmach::store::search()::subject==removal::response[value]==[" << resp ["value"] << "]" << std::endl;
		std::cerr << "noware::mmach::store::search()::subject==removal::msg_result==[" << std::string (msg_result) << "]" << std::endl;
		
		//return msg_result == "1";
		return false;
	}
	else if (resp ["subject"] == "size::count")
	{
		std::cerr << "noware::mmach::store::search()::subject==magnitude" << std::endl;
		
		result_tmp = msg_result;
		if (result_tmp.t () != noware::var::type::nr)
			result_tmp = 0;
		
		//result += data.size ();
		//result ["value"] += resp ["value"];
		result_tmp += noware::var (resp ["value"]);
		msg_result = result_tmp;
		
		std::cerr << "noware::mmach::store::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cerr << "noware::mmach::store::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return false;
	}
	else if (resp ["subject"] == "size::avail")
	{
		std::cerr << "noware::mmach::store::search()::subject==magnitude" << std::endl;
		
		result_tmp = msg_result;
		if (result_tmp.t () != noware::var::type::nr)
			result_tmp = 0;
		
		//result += data.size ();
		//result ["value"] += resp ["value"];
		result_tmp += noware::var (resp ["value"]);
		msg_result = result_tmp;
		
		std::cerr << "noware::mmach::store::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cerr << "noware::mmach::store::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return false;
	}
	else if (resp ["subject"] == "size::total")
	{
		std::cerr << "noware::mmach::store::search()::subject==magnitude" << std::endl;
		
		result_tmp = msg_result;
		if (result_tmp.t () != noware::var::type::nr)
			result_tmp = 0;
		
		//result += data.size ();
		//result ["value"] += resp ["value"];
		result_tmp += noware::var (resp ["value"]);
		msg_result = result_tmp;
		
		std::cerr << "noware::mmach::store::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cerr << "noware::mmach::store::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
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

const bool noware::mmach::store::exist (const std::string & key) const
{
	return exist ("", key);
}

const bool noware::mmach::store::exist (const std::string & grp, const std::string & key) const
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "existence";
	expression ["group"] = grp;
	expression ["key"] = key;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return multival (zmq::msg (expression_serial), noware::smach::store::grp_dft + std::string ("::nonempty")) == "1";
}

bool const/*success*/ noware::mmach::store::get (std::string const & key, std::string & val) const
//const std::pair <std::string/*value*/, bool/*reference*/> noware::pmach::store::get (const std::string & key) const
{
	return get ("", key, val);
}

bool const noware::mmach::store::get (std::string const & grp, std::string const & key, std::string & val) const
//const std::pair <std::string/*value*/, bool/*reference*/> noware::pmach::store::get (const std::string & group, const std::string & key) const
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	std::map <std::string, std::string> result;
	std::string result_str;
	std::string expression_serial;
	
	expression ["subject"] = "obtainment";
	expression ["group"] = grp;
	expression ["key"] = key;
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	result_str = multival (zmq::msg (expression_serial), noware::smach::store::grp_dft + std::string ("::nonempty"));
	
	std::cout << "noware::mmach::store::get()::result_str" << "[" << result_str << "]" << std::endl;
	
	if (!noware::deserialize <std::map <std::string, std::string>> (result, result_str))
		return false;
	
	try
	{
		if (result.at ("value.exist") == "0")
			return false;
		std::cout << "noware::mmach::store::get()::val.exist" << "[" << true << "]" << std::endl;
		
		val = result.at ("value");
		std::cout << "noware::mmach::store::get()::val" << "[" << val << "]" << std::endl;
		return true;
	}
	catch (...)
	{
		return false;
	}
	
	return false;
}

bool const noware::mmach::store::set (std::string const & key, std::string const & val)
//const bool noware::pmach::store::set (const std::string & key, const std::string & value, const bool & reference)
{
	return set ("", key, val);
	//return set ("", key, value, reference);
}

bool const noware::mmach::store::set (std::string const & grp, std::string const & key, std::string const & val)
//const bool noware::pmach::store::set (const std::string & group, const std::string & key, const std::string & value, const bool & reference)
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "assignment";
	expression ["group"] = grp;
	expression ["key"] = key;
	expression ["value"] = val;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return multival (zmq::msg (expression_serial), noware::smach::store::grp_dft + std::string ("::nonfull")) == "1";
}

const cln::nr noware::mmach::store::capac (void) const
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "size::capac";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return std::string (multival (zmq::msg (expression_serial), noware::smach::store::grp_dft));
}

const cln::nr noware::mmach::store::used (void) const
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "size::used";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return std::string (multival (zmq::msg (expression_serial), noware::smach::store::grp_dft + std::string ("::nonempty")));
}

const cln::nr noware::mmach::store::avail (void) const
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "size::avail";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return std::string (multival (zmq::msg (expression_serial), noware::smach::store::grp_dft + std::string ("::nonfull")));
}

cln::nr const noware::mmach::store::size (void) const
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "size::count";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return std::string (multival (zmq::msg (expression_serial), noware::smach::store::grp_dft + std::string ("::nonempty")));
	//std::string result = std::string (multival (zmq::msg (expression_serial), noware::smach::store::grp_dft/* + std::string ("::nonempty")*/));
	//std::cout << "noware::mmach::store::size()::result" << "[" << result << "]" << std::endl;
	//return result;
}

cln::nr const noware::mmach::store::size (std::string const & grp) const
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "size::count";
	expression ["group"] = grp;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return std::string (multival (zmq::msg (expression_serial), noware::smach::store::grp_dft + std::string ("::nonempty")));
}

bool const noware::mmach::store::empty (void) const
{
	//return count () <= 0;
	
	////noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "empty";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return multival (zmq::msg (expression_serial), noware::smach::store::grp_dft) == "1";
}

bool const noware::mmach::store::full (void) const
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "full";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return multival (zmq::msg (expression_serial), noware::smach::store::grp_dft) == "1";
}

/*
bool const rename (std::string const & old_k, std::string const & new_k);
{
	
	return true;
}
*/

bool const noware::mmach::store::remove (std::string const & key)
{
	return remove ("", key);
}

bool const noware::mmach::store::remove (std::string const & grp, std::string const & key)
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "removal";
	expression ["group"] = grp;
	expression ["key"] = key;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	
	//return multival (zmq::msg (expression_serial), noware::smach::store::grp_dft + std::string ("::nonempty")) == "1";
	std::string result = multival (zmq::msg (expression_serial), noware::smach::store::grp_dft + std::string ("::nonempty"));
	std::cout << "noware::mmach::store::remove()::result==" << "[" << result << "]" << std::endl;
	return result == "1";
}

bool const noware::mmach::store::clear (void)
{
	if (_node.peer_size (noware::smach::store::grp_dft + std::string ("::nonempty")) == 0)
		// there is no content:
		// all serving nodes are empty
		return true;
	
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "clearance";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return multival (zmq::msg (expression_serial), noware::smach::store::grp_dft + std::string ("::nonempty")) == "1";
}

bool const noware::mmach::store::clear (std::string const & grp)
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "clearance";
	expression ["group"] = grp;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return multival (zmq::msg (expression_serial), noware::smach::store::grp_dft + std::string ("::nonempty")) == "1";
}

/*
std::string operator [] (std::string const & key)
{
	std::string val;
	
	if (get ("", key, val))
		return val;
	
	// TODO: handle case when set/get fails here
	set ("", key, "");
	//get ("", key, val);
	//return val;
	return "";
}
*/
