#pragma once

#include "store.hxx"
#include <noware/contnr/array.cxx>
#include "dev.cxx"
//#include "../mmach/store.cxx"
//#include <cstring>

//#include ".store/.incl.cxx"

std::string const noware::smach::store::grp_dft = "noware::smach::store";
bool const noware::smach::store::write_dft = true;
//bool const noware::smach::store::cache_dft = true;
//unsigned short int const noware::smach::store::copy_dft = 1;

//#include ".store/.cxx"

noware::smach::store::store (void)
{
////	node.initialize ();
////	node.start ();
//	assert (node.join (/*noware::smach::store::*/grp_dft));
	////assert (node.join (/*store::*/grp_dft));
//	assert (node.join ("noware::smach::store::nonfull")); // Temporary: dynamically find when needed.
////	node.reception_set (boost::bind (boost::mem_fn (&noware::smach::store::receive), this, _1));
	////node.reception_set (boost::mem_fn (&noware::smach::store::receive));
	////node.reception_set (&noware::smach::store::receive);
	
	write = write_dft; // Temporary: TODO: dynamically find this.
//	cache = cache_dft;
//	copy = copy_dft;
}

noware::smach::store::~store (void)
{
//	node.reception_unset ();
	// node.leave (/*noware::smach::store::*/grp_dft);
//	node.stop ();
//	node.finalize ();
}

const bool noware::smach::store::start (void)
{
	if (!dev::start ())
		return false;
	
	if (!_node.join (grp_dft))
		return false;
	
	if (!_node.join (grp_dft + std::string ("::nonfull"))) // Temporary: dynamically find when needed.
		return false;
	
	return true;
}

//const noware::var noware::smach::store::evaluate (const noware::var & expression)
//{
//	return "";
//}
//

bool const noware::smach::store::respond (zmq::msg & msg_response, zmq::msg const & msg_request, zyre_event_t const * const/* event*/, std::string const &/* event_type*/, std::string const &/* src*/, net::cast const &/* src_cast*/)
{
	std::cerr << "noware::smach::store::respond()::called" << std::endl;
	
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
	
	std::cerr << "noware::smach::store::respond()::if::message[subject]==[" << message ["subject"] << ']' << std::endl;
	
	//std::cerr << "noware::smach::store::respond()::if::message[type]==" << message ["type"] << "::else::in scope" << std::endl;
	
	if (message ["subject"] == "existence")
	{
		std::cerr << "noware::smach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
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
		
		//msg_response = response ["value"];
		//return true;
	}
	/*
	else if (message ["subject"] == "existence.group")
	{
		std::cerr << "noware::smach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
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
		std::cerr << "noware::smach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
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
		
		std::cerr << "noware::smach::store::respond()::message[subject]==" << message ["subject"] << "::response[value.exist]==" << response ["value.exist"] << std::endl;
		if (response ["value.exist"] == "1")
			std::cerr << "noware::smach::store::respond()::message[subject]==" << message ["subject"] << "::response[value]==" << response ["value"] << std::endl;
	}
	else if (message ["subject"] == "assignment")
	{
		std::cerr << "noware::smach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["type"] = "response";
		response ["subject"] = message ["subject"];
		response ["group"] = message ["group"];
		response ["key"] = message ["key"];
		//response ["existence"] = data.exist (message ["group"]) && data.get (message ["group"]).exist (message ["key"]);
		
		if (!write || full ())
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
			std::cerr << "noware::smach::store::respond()::if::message[subject]==" << message ["subject"] << "::try..." << std::endl;
			try
			{
				std::cerr << "noware::smach::store::respond()::if::message[subject]==" << message ["subject"] << "::try::in scope" << std::endl;
				if (data.at (message ["group"]).at (message ["key"]) == message ["value"])
				{
					std::cerr << "noware::smach::store::respond()::if::message[subject]==" << message ["subject"] << "::try::if" << std::endl;
					response ["value"] = "1";
				}
				else
				{
					std::cerr << "noware::smach::store::respond()::if::message[subject]==" << message ["subject"] << "::try::if::else" << std::endl;
					response ["value"] = "0";
				}
			}
			catch (...)
			{
				std::cerr << "noware::smach::store::respond()::if::message[subject]==" << message ["subject"] << "::try::catch" << std::endl;
				response ["value"] = "0";
			}
			
			//response ["value"] = "1";
			
			std::cerr << "noware::smach::store::respond()::if::message[subject]==" << message ["subject"] << "::response[value]==[" << response ["value"] << ']' << std::endl;
			//return response ["value"] == "1";
			*/
			
			if (full ())
				assert (_node.leave (grp_dft + std::string ("::nonfull")));
			
			assert (_node.join (grp_dft + std::string ("::nonempty")));
			
			response ["value"] = "1";
		}
		
		//msg_response = response ["value"];
		//return true;
	}
	else if (message ["subject"] == "removal")
	{
		std::cerr << "noware::smach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		std::cerr << "noware::smach::store::respond()::message[group]==" << message ["group"] << "" << std::endl;
		std::cerr << "noware::smach::store::respond()::message[key]==" << message ["key"] << "" << std::endl;
		
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
		
		//msg_response = response ["value"];
		//return true;
	}
	else if (message ["subject"] == "size::count")
	{
		std::cerr << "noware::smach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["type"] = "response";
		response ["subject"] = message ["subject"];
		//response ["key"] = message ["key"];
		
		if (message.count ("group") > 0)
		{
			std::cerr << "noware::smach::store::respond()::group[ed]" << std::endl;
			
			if (data.count (message ["group"]) > 0)
			{
				std::cerr << "noware::smach::store::respond()::group::exist" << std::endl;
				response ["value"] = data [message ["group"]].size ();
			}
			else
			{
				std::cerr << "noware::smach::store::respond()::group::not exist" << std::endl;
				response ["value"] = "0";
			}
		}
		else
		{
			std::cerr << "noware::smach::store::respond()::not group[ed]" << std::endl;
			//response ["value"] = data.size ();
			//std::cerr << "noware::smach::store::respond()::data.size ()==[" << data.size () << ']' << std::endl;
			result_tmp = 0;
			for (const std::pair <std::string, std::map <std::string, std::string>> & group : data)
			{
				result_tmp += group.second.size ();
			}
			response ["value"] = result_tmp.operator std::string const ();
			//response ["value"] = "12321";
			
			std::cerr << "noware::smach::store::respond()::result_tmp==[" << result_tmp << ']' << std::endl;
			std::cerr << "noware::smach::store::respond()::response[value]==[" << response ["value"] << ']' << std::endl;
		}
		
		//msg_response = response ["value"];
		//return true;
	}
	else if (message ["subject"] == "size::avail")
	{
		std::cerr << "noware::smach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["type"] = "response";
		response ["subject"] = message ["subject"];
		response ["value"] = "0";
		
		//msg_response = response ["value"];
		//return true;
	}
	else if (message ["subject"] == "size::used")
	{
		std::cerr << "noware::smach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["type"] = "response";
		response ["subject"] = message ["subject"];
		response ["value"] = "0";
		
		//msg_response = response ["value"];
		//return true;
	}
	else if (message ["subject"] == "size::capac")
	{
		std::cerr << "noware::smach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["type"] = "response";
		response ["subject"] = message ["subject"];
		response ["value"] = "0";
		
		//msg_response = response ["value"];
		//return true;
	}
	else if (message ["subject"] == "empty")
	{
		std::cerr << "noware::smach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["type"] = "response";
		response ["subject"] = message ["subject"];
		
		if (data.empty ())
			response ["value"] = "1";
		else
			response ["value"] = "0";
		
		//msg_response = response ["value"];
		//return true;
	}
	else if (message ["subject"] == "full")
	{
		std::cerr << "noware::smach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
		response ["type"] = "response";
		response ["subject"] = message ["subject"];
		
		response ["value"] = "0";
		
		//msg_response = response ["value"];
		//return true;
	}
	else if (message ["subject"] == "clearance")
	{
		std::cerr << "noware::smach::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
		
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
				
				if (empty ())
					assert (_node.leave (grp_dft + std::string ("::nonempty")));
			}
			else
			{
				//response ["key"] = message ["key"];
				//response ["meta"] = data.exist (message ["key"]);
				//if (response ["meta"])
				data.clear ();
				assert (_node.leave (grp_dft + std::string ("::nonempty")));
			}
			
			assert (_node.join (grp_dft + std::string ("::nonfull")));
			
			//response ["subject"] = message ["subject"];
			//response ["type"] = "response";
			response ["value"] = "1";
		}
		
		//msg_response = response ["value"];
		//return true;
	}
	else
	{
		std::cerr << "noware::smach::store::respond()::else::return[false]" << std::endl;
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
//	std::cerr << "noware::smach::store::respond()::node.unicast (response, zyre_event_peer_uuid (event)==" << (result ? "Success" : "Failure") << std::endl;
	//return result;
	
	return result;
}

const bool noware::smach::store::exist (const std::string & key) const
{
	return exist ("", key);
}

const bool noware::smach::store::exist (const std::string & grp, const std::string & key) const
{
	std::string const * val;
	return get (grp, key, val);
}

bool const/*success*/ noware::smach::store::get (const std::string & key, std::string const * & val) const
//const std::pair <std::string/*value*/, bool/*reference*/> noware::smach::store::get (const std::string & key) const
{
	return get ("", key, val);
}

bool const/*success*/ noware::smach::store::get (std::string const & grp, std::string const & key, std::string const * & val) const
//const std::pair <std::string/*value*/, bool/*reference*/> noware::smach::store::get (const std::string & group, const std::string & key) const
{
	try
	{
		val = &(data.at (grp).at (key));
		return true;
	}
	catch (...)
	{
		return false;
	}
	
	// to satisfy the compiler
	return false;
}

bool const noware::smach::store::set (std::string const & key, std::string const & val)
//const bool noware::smach::store::set (const std::string & key, const std::string & value, const bool & reference)
{
	return set ("", key, val);
	//return set ("", key, value, reference);
}

bool const noware::smach::store::set (std::string const & grp, std::string const & key, std::string const & val)
//const bool noware::smach::store::set (const std::string & group, const std::string & key, const std::string & value, const bool & reference)
{
	data [grp] [key] = val;
	return true;
}

const cln::nr noware::smach::store::capac (void) const
{
	return 0;
}

const cln::nr noware::smach::store::used (void) const
{
	return 0;
}

const cln::nr noware::smach::store::avail (void) const
{
	return 0;
}

cln::nr const noware::smach::store::size (void) const
{
	cln::nr cnt;
	
	cnt = 0;
	for (std::pair <std::string, std::map <std::string, std::string>> const & grp : data)
		cnt += grp.second.size ();
	
	return cnt;
}

cln::nr const noware::smach::store::size (std::string const & grp) const
{
	try
	{
		return data.at (grp).size ();
	}
	catch (...)
	{
		return 0;
	}
}

bool const noware::smach::store::empty (void) const
{
	return size () <= 0;
}

bool const noware::smach::store::full (void) const
{
	return false;
}

/*
bool const rename (std::string const & old_k, std::string const & new_k);
{
	
	return true;
}
*/

bool const noware::smach::store::remove (std::string const & key)
{
	return remove ("", key);
}

bool const noware::smach::store::remove (std::string const & grp, std::string const & key)
{
	try
	{
		data.at (grp).erase (key);
	}
	catch (...)
	{
		// no such group
		return true;
	}
	
	if (data.at (grp).size () <= 0)
		data.erase (grp);
	
	return true;
}

bool const noware::smach::store::clear (void)
{
	data.clear ();
	//_size = 0;
	return true;
}

bool const noware::smach::store::clear (std::string const & grp)
{
	data.erase (grp);
	return true;
}

/*
std::string & noware::smach::store::operator [] (std::string const & key)
{
	std::string const * val;
	
	if (get ("", key, val))
		return *val;
	
	// TODO: handle case when set/get fails
	set ("", key, "");
	get ("", key, val);
	return *val;
}
*/

/*
template <typename value>
virtual const iterator <value> noware::smach::store::begin (void) const
{
}

template <typename value>
virtual const iterator <value> noware::smach::store::end (void) const
{
}

template <typename value>
virtual const iterator <value> noware::smach::store::operator ++ (void)
{
}

template <typename value>
virtual const iterator <value> noware::smach::store::operator -- (void)
{
}

template <typename value>
virtual const bool noware::smach::store::operator == (const iterator <value> & other) const
{
}

template <typename value>
virtual const value noware::smach::store::operator * (void) const
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
	std::cerr << "noware::smach::dev::multicast()::called" << std::endl;
	//if (!message.is_group ())
	//	return "";
	
	std::string request_token;
	zmq::msg msg_resp;
	//noware::nr responses_count;
	
	request_token = noware::random::string (token_size_dft);
	std::cerr << "noware::smach::dev::multicast()::request_token==[" << request_token << ']' << std::endl;
	
	msg_req.prepend (zmq::msg::frame (dev::grp_dft + std::string ("::response::desired")));
	msg_req.prepend (zmq::msg::frame (request_token));
	
	if (!node.multicast (msg_req, group))
	{
		std::cerr << "noware::smach::dev::multicast()::node.multicast()::failure" << std::endl;
		return msg_resp;
	}
	
	std::cerr << "noware::smach::dev::multicast()::node.multicast()::success" << std::endl;
	
	iteration = receive_local (request_token, node.peers_size (group), responses_count, group, net::cast::multi);
	
	//return *this;
}

virtual const misc::iterator <std::tuple <std::string, std::string, std::string>> operator -- (void);
//virtual const store operator -- (void)
{}
*/
