#pragma once

//#include <cstring>
#include "store.hxx"

#include "dev.cxx"
#include <string>
#include <noware/contnr/array.cxx>
#include <cln/nr.cxx>
#include <noware/var.cxx>
#include "../man/store.cxx"
#include "../msg/subj.hxx"

//#include ".store/.incl.cxx"

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
std::string const noware::vos::usr::store <val_t, key_t, grp_t>::grp_dft = "noware::vos::usr::store";
//bool const noware::cmach::store::write_dft = true;
//bool const noware::pmach::store::cache_dft = true;
//unsigned short int const noware::pmach::store::copy_dft = 1;

//#include ".store/.cxx"

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
noware::vos::usr::store <val_t, key_t, grp_t>::store (void)
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
//	cache = cache_dft;
//	copy = copy_dft;
}

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
noware::vos::usr::store <val_t, key_t, grp_t>::~store (void)
{
//	node.reception_unset ();
	// node.leave (/*noware::pmach::store::*/grp_dft);
//	node.stop ();
//	node.finalize ();
}

/*
const bool noware::cmach::store::start (void)
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
bool const/* success*/ noware::vos::usr::store <val_t, key_t, grp_t>::aggregate_remote (zmq::msg & msg_result/* overall/final result. passed during each iteration*/, zmq::msg const & msg_curr/* current response message/expression*/, cln::nr const &/* total, expected resonses count*/, cln::nr const &/* current count of peers who responded (so far)*/, std::string const &/* src*/, net::cast const &/* src_cast*/)
{
	// normally, there should be only one message:
	// the one from the manager who we requested from,
	// so this function should only be called once,
	// having the current message as the only message (and the final result)
	msg_result = msg_curr;
	return true;
}

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
//bool const noware::vos::usr::store <val_t, key_t, grp_t>::search_remote (zmq::msg const & msg_result, zmq::msg const & msg_re_curr, cln::nr const & response_expected, cln::nr const & responses_occured, std::string const & src, net::cast const & src_cast)
bool const noware::vos::usr::store <val_t, key_t, grp_t>::search_remote (zmq::msg const &, zmq::msg const &, cln::nr const &, cln::nr const &, std::string const &, net::cast const &)
{
	return true;
}
/*
{
	std::cerr << "noware::vos::usr::store::search()::called" << std::endl;
	
	msg * msg_req_subj;
	
	try
	{
		msg_req_subj = req.data.at (0).data.data <msg> ();
		
		switch (*msg_req_subj)
		{
			case msg::get:
				if (msg_re_curr.data.count (1) > 0)
					msg_result.data [1] = msg_re_curr.data.at (1);
				
				msg_result.data [0] = msg_re_curr.data.at (0);
				return false;
			case msg::size:
			case msg::avail:
			case msg::capac:
			case msg::used:
			case msg::exist:
			case msg::full:
			case msg::empty:
				//return *(req.data.at (1).data.data <bool> ());
				msg_result.data [1] = msg_re_curr.data.at (1);
			case msg::set:
			case msg::del:
			case msg::clear:
				msg_result.data [0] = msg_re_curr.data.at (0);
				return false;
		}
	}
	catch (...)
	{
		std::cerr << "noware::vos::usr::store::search()::caught" << std::endl;
	}
	
	// default case
	return false;
}
*/

/*
bool const noware::vos::usr::store::exist (const key_t & key) const
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
bool const noware::vos::usr::store <val_t, key_t, grp_t>::exist (grp_t const & grp, key_t const & key) const
{
	////noware::tree <std::string, std::string> expression;
	//std::map <std::string, std::string> expression;
	
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	subj = msg::subj::exist;
	
	/*
	expression ["subject"] = "existence";
	expression ["group"] = grp;
	expression ["key"] = key;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	*/
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	req.data [1] = zmq::message_t (&grp, sizeof grp);
	req.data [2] = zmq::message_t (&key, sizeof key);
	
	////return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	//return anyval (zmq::msg (expression_serial), noware::vos::man::store::grp_dft) == "1";
	re = anyval (req, noware::vos::man::store <val_t, key_t, grp_t>::grp_dft);
	
	try
	{
		//if (!(*(re.data.at (0).data.data <bool> ())/*succes*/))
		//	return false;
		
		return *(re.data.at (1).data.data <bool> ())/*result*/;
	}
	catch (...)
	{
		return false;
	}
}

/*
bool const/*success* / noware::vos::usr::store::get (key_t const & key, val_t & val) const
//const std::pair <std::string/*value* /, bool/*reference* /> noware::pmach::store::get (const std::string & key) const
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
bool const noware::vos::usr::store <val_t, key_t, grp_t>::get (grp_t const & grp, key_t const & key, val_t & val) const
//const std::pair <std::string/*value*/, bool/*reference*/> noware::pmach::store::get (const std::string & group, const std::string & key) const
{
	std::cerr << "noware::vos::usr::store::get()" << std::endl;
	
	/*
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
	result_str = anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft);
	
	if (!noware::deserialize <std::map <std::string, std::string>> (result, result_str))
		return false;
	
	try
	{
		if (result.at ("value.exist") == "0")
			return false;
		
		val = result.at ("value");
		return true;
	}
	catch (...)
	{
		return false;
	}
	
	return false;
	*/
	
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	
	subj = msg::subj::get;
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	req.data [1] = zmq::message_t (&grp, sizeof grp);
	req.data [2] = zmq::message_t (&key, sizeof key);
	
	
	// perform the call
	re = anyval (req, noware::vos::man::store <val_t, key_t, grp_t>::grp_dft);
	
	try
	{
		//if (!(*(re.data.at (0).data.data <bool> ())/*succes*/))
		//	return false;
		//
		//if (!(*(re.data.at (1).data.data <bool> ())/*exist*/))
		//	return false;
		
		if (re.data.count (1) <= 0)
			return false;
		
		val = *(re.data.at (1).data.data <val_t> ())/*data value*/;
		return true;
	}
	catch (...)
	{
		return false;
	}
}

/*
bool const noware::vos::usr::store::set (key_t const & key, val_t const & val)
//const bool noware::pmach::store::set (const std::string & key, const std::string & value, const bool & reference)
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
bool const noware::vos::usr::store <val_t, key_t, grp_t>::set (grp_t const & grp, key_t const & key, val_t const & val)
//const bool noware::pmach::store::set (const std::string & group, const std::string & key, const std::string & value, const bool & reference)
{
	/*
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
	return anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft) == "1";
	*/
	
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	
	subj = msg::subj::set;
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	req.data [1] = zmq::message_t (&grp, sizeof grp);
	req.data [2] = zmq::message_t (&key, sizeof key);
	req.data [3] = zmq::message_t (&val, sizeof val);
	
	// perform the call
	re = anyval (req, noware::vos::man::store <val_t, key_t, grp_t>::grp_dft);
	
	try
	{
		std::cerr << "noware::vos::usr::store::set()::try" << std::endl;
		return *(re.data.at (1).data.data <bool> ())/*succes*/;
	}
	catch (...)
	{
		std::cerr << "noware::vos::usr::store::seet()::caught exception" << std::endl;
		return false;
	}
	
	return false;
}

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
cln::nr const noware::vos::usr::store <val_t, key_t, grp_t>::capac (void) const
{
	/*
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "size::capac";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return std::string (anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft));
	*/
	
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	
	subj = msg::subj::capac;
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	
	
	// perform the call
	re = anyval (req, noware::vos::man::store <val_t, key_t, grp_t>::grp_dft);
	
	try
	{
		//if (!(*(re.data.at (0).data.data <bool> ())/*succes*/))
		//	return 0;
		
		return *(re.data.at (1).data.data <int unsigned> ())/*data value*/;
	}
	catch (...)
	{
		std::cerr << "noware::vos::usr::store::capac::caught exception" << std::endl;
		return 0;
	}
}

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
cln::nr const noware::vos::usr::store <val_t, key_t, grp_t>::used (void) const
{
	/*
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "size::used";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return std::string (anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft));
	*/
	
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	
	subj = msg::subj::used;
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	
	
	// perform the call
	re = anyval (req, noware::vos::man::store <val_t, key_t, grp_t>::grp_dft);
	
	try
	{
		//if (!(*(re.data.at (0).data.data <bool> ())/*succes*/))
		//	return 0;
		
		return *(re.data.at (1).data.data <int unsigned> ())/*data value*/;
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
cln::nr const noware::vos::usr::store <val_t, key_t, grp_t>::avail (void) const
{
	/*
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "size::avail";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return std::string (anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft));
	*/
	
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	
	subj = msg::subj::avail;
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	
	
	// perform the call
	re = anyval (req, noware::vos::man::store <val_t, key_t, grp_t>::grp_dft);
	
	try
	{
		//if (!(*(re.data.at (0).data.data <bool> ())/*succes*/))
		//	return 0;
		
		return *(re.data.at (1).data.data <int unsigned> ())/*data value*/;
	}
	catch (...)
	{
		std::cerr << "noware::vos::usr::store::avail::caught exception" << std::endl;
		return 0;
	}
}

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
cln::nr const noware::vos::usr::store <val_t, key_t, grp_t>::size (void) const
{
	std::cerr << "noware::vos::usr::store::size()" << std::endl;
	
	/*
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "size::count";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return std::string (anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft));
	*/
	
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	
	subj = msg::subj::size;
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	
	
	// perform the call
	re = anyval (req, noware::vos::man::store <val_t, key_t, grp_t>::grp_dft);
	
	try
	{
		std::cerr << "noware::vos::usr::store::size()::try" << std::endl;
		
		//if (!(*(re.data.at (0).data.data <bool> ())/*succes*/))
		//	return 0;
		
		return *(re.data.at (1).data.data <int unsigned> ())/*data value*/;
	}
	catch (...)
	{
		std::cerr << "noware::vos::usr::store::size()::caught" << std::endl;
		return 0;
	}
}

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
cln::nr const noware::vos::usr::store <val_t, key_t, grp_t>::size (grp_t const & grp) const
{
	/*
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "size::count";
	expression ["group"] = grp;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return std::string (anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft));
	*/
	
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	
	subj = msg::subj::size;
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	req.data [1] = zmq::message_t (&grp, sizeof grp);
	
	
	// perform the call
	re = anyval (req, noware::vos::man::store <val_t, key_t, grp_t>::grp_dft);
	
	try
	{
		//if (!(*(re.data.at (0).data.data <bool> ())/*succes*/))
		//	return 0;
		
		return *(re.data.at (1).data.data <int unsigned> ())/*data value*/;
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
bool const noware::vos::usr::store <val_t, key_t, grp_t>::empty (void) const
{
	/*
	//return count () <= 0;
	
	////noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "empty";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft) == "1";
	*/
	
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	
	subj = msg::subj::empty;
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	
	
	// perform the call
	re = anyval (req, noware::vos::man::store <val_t, key_t, grp_t>::grp_dft);
	
	try
	{
		//if (!(*(re.data.at (0).data.data <bool> ())/*succes*/))
		//	return true;
		
		return *(re.data.at (1).data.data <bool> ())/*data value*/;
	}
	catch (...)
	{
		std::cerr << "noware::vos::usr::store::empty::caught exception" << std::endl;
		return false;
	}
}

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::usr::store <val_t, key_t, grp_t>::full (void) const
{
	/*
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "full";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft) == "1";
	*/
	
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	
	subj = msg::subj::full;
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	
	
	// perform the call
	re = anyval (req, noware::vos::man::store <val_t, key_t, grp_t>::grp_dft);
	
	try
	{
		//if (!(*(re.data.at (0).data.data <bool> ())/*succes*/))
		//	return true;
		
		return *(re.data.at (1).data.data <bool> ())/*data value*/;
	}
	catch (...)
	{
		std::cerr << "noware::vos::usr::store::full::caught exception" << std::endl;
		return false;
	}
}

/*
bool const rename (std::string const & old_k, std::string const & new_k);
{
	
	return true;
}
*/

/*
bool const noware::vos::usr::store::remove (key_t const & key)
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
bool const noware::vos::usr::store <val_t, key_t, grp_t>::del (grp_t const & grp, key_t const & key)
{
	/*
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "removal";
	expression ["group"] = grp;
	expression ["key"] = key;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft) == "1";
	*/
	
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	
	subj = msg::subj::del;
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	req.data [1] = zmq::message_t (&grp, sizeof grp);
	req.data [2] = zmq::message_t (&key, sizeof key);
	
	
	// perform the call
	re = anyval (req, noware::vos::man::store <val_t, key_t, grp_t>::grp_dft);
	
	try
	{
		return *(re.data.at (1).data.data <bool> ())/*success*/;
	}
	catch (...)
	{
		std::cerr << "noware::vos::usr::store::del::caught exception" << std::endl;
		return false;
	}
}

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::usr::store <val_t, key_t, grp_t>::clear (void)
{
	/*
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "clearance";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft) == "1";
	*/
	
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	
	subj = msg::subj::clear;
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	
	
	// perform the call
	re = anyval (req, noware::vos::man::store <val_t, key_t, grp_t>::grp_dft);
	
	try
	{
		return *(re.data.at (1).data.data <bool> ())/*success*/;
	}
	catch (...)
	{
		std::cerr << "noware::vos::usr::store::clear(void)::caught exception" << std::endl;
		return false;
	}
}

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::usr::store <val_t, key_t, grp_t>::clear (grp_t const & grp)
{
	/*
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "clearance";
	expression ["group"] = grp;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft) == "1";
	*/
	
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	
	subj = msg::subj::clear;
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	req.data [1] = zmq::message_t (&grp, sizeof grp);
	
	
	// perform the call
	re = anyval (req, noware::vos::man::store <val_t, key_t, grp_t>::grp_dft);
	
	try
	{
		return *(re.data.at (1).data.data <bool> ())/*success*/;
	}
	catch (...)
	{
		std::cerr << "noware::vos::usr::store::clear(grp)::caught exception" << std::endl;
		return false;
	}
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
