#pragma once

//#include <cstring>
#include "store.hxx"

#include <noware/contnr/array.cxx>
#include "dev.cxx"
#include "../smach/store.cxx"

//#include ".store/.incl.cxx"

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
std::string const noware::vos::man::store <val_t, key_t, grp_t>::grp_dft = "noware::vos::man::store";
//bool const noware::vos::man::store::write_dft = true;

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::man::store <val_t, key_t, grp_t>::cache_dft = true;
//unsigned short int const noware::pmach::store::copy_dft = 1;

//#include ".store/.cxx"

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
noware::vos::man::store <val_t, key_t, grp_t>::store (void)
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

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
noware::vos::man::store <val_t, key_t, grp_t>::~store (void)
{
//	node.reception_unset ();
	// node.leave (/*noware::pmach::store::*/grp_dft);
//	node.stop ();
//	node.finalize ();
}

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::man::store <val_t, key_t, grp_t>::start (void)
{
	if (!net::node::start ())
		return false;
	
	if (!_node.join (grp_dft))
		return false;
	
	return true;
}

/*
bool const noware::vos::man::store::start (void)
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

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const/* success*/ noware::vos::man::store <val_t, key_t, grp_t>::aggregate_remote (zmq::msg & msg_result, zmq::msg const & msg_re_curr/* current response message/expression*/, cln::nr const &/* total, expected resonses count*/, cln::nr const &/* current count of peers who responded (so far)*/, std::string const &/* src*/, net::cast const &/* src_cast*/)
{
	std::cerr << "noware::vos::man::store::aggregate_remote()" << std::endl;
	
	msg::subj * re_subj;
	
	try
	{
		// copy the subject (msg::subj):
		// rep <- req
		if (msg_result.data.count (0) <= 0 && msg_re_curr.data.count (0) > 0)
		{
			msg_result.data [0] = msg_re_curr.data.at (0);
			
			re_subj = msg_re_curr.data.at (0).data.data <msg::subj> ();
		}
		else
			// invalid message (msg::subj is missing)
			return false;
		
		switch (*re_subj)
		{
			case msg::subj::get:
				if (msg_result.data.count (1) <= 0 && msg_re_curr.data.count (1) > 0)
				{
					// the value
					msg_result.data [1] = msg_re_curr.data.at (1);
				}
				break;
			case msg::subj::size:
			case msg::subj::avail:
			case msg::subj::capac:
			case msg::subj::used:
				// if there is no available count in the received message, then fail
				if (msg_re_curr.data.count (1) <= 0)
					return false;
				
				int unsigned * count_prev;
				int unsigned * count_curr;
				
				// if there is no previous value set yet,
				// create one, and set it to 0
				if (msg_result.data.count (1) <= 0)
				{
					// quantity
					int unsigned qty;
					
					qty = 0;
					
					msg_result.data [1] = zmq::message_t (&qty, sizeof qty);
				}
				
				count_prev = msg_result.data.at (1).data.data <int unsigned> ();
				count_curr = msg_re_curr.data.at (1).data.data <int unsigned> ();
				
				*count_prev += *count_curr;
				
				break;
			
			// OR
			// (any of these must be true for any nodes for the result to be true)
			case msg::subj::exist:
			
			// AND
			// (all of these must be true for all nodes for the result to be true)
			case msg::subj::full:
			case msg::subj::empty:
			case msg::subj::del:
			case msg::subj::clear:
			case msg::subj::set:
				// if there is no available value in the received message, then fail
				if (msg_re_curr.data.count (1) <= 0)
					return false;
				
				bool * val_prev;
				bool * val_curr;
				
				// if there is no previous value set yet,
				// create one, and set it to 0
				if (msg_result.data.count (1) <= 0)
				{
					// value
					bool val;
					
					val = false;
					
					msg_result.data [1] = zmq::message_t (&val, sizeof val);
				}
				
				val_prev = msg_result.data.at (1).data.data <bool> ();
				val_curr = msg_re_curr.data.at (1).data.data <bool> ();
				
				if (*re_subj == msg::subj::exist)
					*val_prev = *val_prev || *val_curr;
				else
					*val_prev = *val_prev && *val_curr;
				
				break;
			default:
				return false;
		}
	}
	catch (...)
	{
		std::cerr << "noware::vos::usr::store::aggregate_remote()::caught" << std::endl;
		return false;
	}
	
	// default
	return true;
}

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::man::store <val_t, key_t, grp_t>::respond (zmq::msg & re, zmq::msg const & req, zyre_event_t const * const/* event*/, std::string const &/* event_type*/, std::string const &/* src*/, net::cast const &/* src_cast*/)
{
	std::cerr << "noware::vos::man::store::respond()::called" << std::endl;
	
	msg::subj * req_subj;
	
	try
	{
		req_subj = req.data.at (0/*subj*/).data.data <msg::subj> ();
		
		switch (*req_subj)
		{
			case msg::subj::set:
				re = anyval (req, noware::vos::srv::store::grp_dft + std::string ("::nonfull"));
				break;
			case msg::subj::get:
			case msg::subj::exist:
			case msg::subj::del:
			case msg::subj::clear:
				re = multival (req, noware::vos::srv::store::grp_dft + std::string ("::nonempty"));
				break;
			case msg::subj::avail:
			case msg::subj::capac:
			case msg::subj::used:
			case msg::subj::full:
			case msg::subj::empty:
				re = multival (req, noware::vos::srv::store::grp_dft);
				break;
			default:
				return false;
		}
	}
	catch (...)
	{
		std::cerr << "noware::vos::man::store::respond()::caught" << std::endl;
		return false;
	}
	
	return true;
}

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::man::store <val_t, key_t, grp_t>::search_remote (zmq::msg const & msg_result, zmq::msg const & msg_re_curr, cln::nr const &/* response_expected*/, cln::nr const &/* responses_occured*/, std::string const &/* src*/, net::cast const &/* src_cast*/)
{
	std::cerr << "noware::vos::man::store::search_remote()::called" << std::endl;
	return false;
}

/*
template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
const bool noware::vos::man::store <val_t, key_t, grp_t>::exist (const std::string & key) const
{
	return exist ("", key);
}
*/

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::man::store <val_t, key_t, grp_t>::exist (grp_t const & grp, key_t const & key) const
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

/*
template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::man::store <val_t, key_t, grp_t>::get (std::string const & key, std::string & val) const
{
	return get ("", key, val);
}
*/

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::man::store <val_t, key_t, grp_t>::get (grp_t const & grp, key_t const & key, val_t & val) const
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
	
	std::cout << "noware::vos::man::store::get()::result_str" << "[" << result_str << "]" << std::endl;
	
	if (!noware::deserialize <std::map <std::string, std::string>> (result, result_str))
		return false;
	
	try
	{
		if (result.at ("value.exist") == "0")
			return false;
		std::cout << "noware::vos::man::store::get()::val.exist" << "[" << true << "]" << std::endl;
		
		val = result.at ("value");
		std::cout << "noware::vos::man::store::get()::val" << "[" << val << "]" << std::endl;
		return true;
	}
	catch (...)
	{
		return false;
	}
	
	return false;
}

/*
template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::man::store <val_t, key_t, grp_t>::set (std::string const & key, std::string const & val)
{
	return set ("", key, val);
	//return set ("", key, value, reference);
}
*/

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::man::store <val_t, key_t, grp_t>::set (grp_t const & grp, key_t const & key, val_t const & val)
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

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
cln::nr const noware::vos::man::store <val_t, key_t, grp_t>::capac (void) const
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

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
cln::nr const noware::vos::man::store <val_t, key_t, grp_t>::used (void) const
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

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
cln::nr const noware::vos::man::store <val_t, key_t, grp_t>::avail (void) const
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

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
zmq::msg const noware::vos::man::store <val_t, key_t, grp_t>::size (void) const
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
	//std::cout << "noware::vos::man::store::size()::result" << "[" << result << "]" << std::endl;
	//return result;
	
	
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg subj;
	
	
	subj = msg::size;
	
	req [0] = zmq::message_t (&subj, sizeof subj);
	
	
	// perform the call
	re = multival (req, noware::vos::srv::store::grp_dft);
	
	try
	{
		if (!(*(re.data.at (0).data.data <bool> ())/*succes*/))
			return 0;
		
		return *(re.data.at (1).data.data <int unsigned> ()/*data value*/;
	}
	catch (...)
	{
		std::cerr << "noware::vos::usr::store::used::caught exception" << std::endl;
		return 0;
	}
}

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
cln::nr const noware::vos::man::store <val_t, key_t, grp_t>::size (grp_t const & grp) const
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

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::man::store <val_t, key_t, grp_t>::empty (void) const
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

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::man::store <val_t, key_t, grp_t>::full (void) const
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

/*
template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::man::store <val_t, key_t, grp_t>::del (key_t const & key)
{
	return remove ("", key);
}
*/

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::man::store <val_t, key_t, grp_t>::del (grp_t const & grp, key_t const & key)
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
	std::cout << "noware::vos::man::store::remove()::result==" << "[" << result << "]" << std::endl;
	return result == "1";
}

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::man::store <val_t, key_t, grp_t>::clear (void)
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

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::man::store <val_t, key_t, grp_t>::clear (grp_t const & grp)
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
