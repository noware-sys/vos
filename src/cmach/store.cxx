#pragma once

//#include <cstring>
#include "store.hxx"

#include <noware/contnr/array.cxx>
#include "dev.cxx"
#include "../mmach/store.cxx"

//#include ".store/.incl.cxx"

std::string const noware::cmach::store::grp_dft = "noware::cmach::store";
//bool const noware::cmach::store::write_dft = true;
//bool const noware::pmach::store::cache_dft = true;
//unsigned short int const noware::pmach::store::copy_dft = 1;

//#include ".store/.cxx"

noware::cmach::store::store (void)
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

noware::cmach::store::~store (void)
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

bool const noware::cmach::store::search (zmq::msg & msg_result, zmq::msg const & msg_resp, cln::nr const &/* response_expected*/, cln::nr const &/* responses_occured*/, std::string const &/* src*/, net::cast const &/* src_cast*/)
{
	std::cerr << "noware::cmach::store::search()::called" << std::endl;
	
	//noware::tree <std::string, std::string> resp;
	std::map <std::string, std::string> resp;
	//noware::tree <std::string, std::string> result;
	//std::string result;
	noware::var result_tmp;
	//bool result;
	
	//if (!resp.deserialize (msg_resp))
	if (!noware::deserialize <std::map <std::string, std::string>> (resp, std::string (msg_resp)))
	{
		std::cerr << "noware::cmach::store::search()::deserialize::failure" << std::endl;
		return false;
	}
	std::cerr << "noware::cmach::store::search()::deserialize::success" << std::endl;
	
	
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
		
		//return msg_result == "1";
		return false;
	}
	else if (resp ["subject"] == "size::count")
	{
		std::cerr << "noware::cmach::store::search()::subject==magnitude" << std::endl;
		
		result_tmp = msg_result;
		if (result_tmp.t () != noware::var::type::nr)
			result_tmp = 0;
		
		//result += data.size ();
		//result ["value"] += resp ["value"];
		result_tmp += noware::var (resp ["value"]);
		msg_result = result_tmp;
		
		std::cerr << "noware::cmach::store::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cerr << "noware::cmach::store::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return false;
	}
	else if (resp ["subject"] == "size::avail")
	{
		std::cerr << "noware::cmach::store::search()::subject==magnitude" << std::endl;
		
		result_tmp = msg_result;
		if (result_tmp.t () != noware::var::type::nr)
			result_tmp = 0;
		
		//result += data.size ();
		//result ["value"] += resp ["value"];
		result_tmp += noware::var (resp ["value"]);
		msg_result = result_tmp;
		
		std::cerr << "noware::cmach::store::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cerr << "noware::cmach::store::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return false;
	}
	else if (resp ["subject"] == "size::total")
	{
		std::cerr << "noware::cmach::store::search()::subject==magnitude" << std::endl;
		
		result_tmp = msg_result;
		if (result_tmp.t () != noware::var::type::nr)
			result_tmp = 0;
		
		//result += data.size ();
		//result ["value"] += resp ["value"];
		result_tmp += noware::var (resp ["value"]);
		msg_result = result_tmp;
		
		std::cerr << "noware::cmach::store::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cerr << "noware::cmach::store::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
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

const bool noware::cmach::store::exist (const std::string & key) const
{
	return exist ("", key);
}

const bool noware::cmach::store::exist (const std::string & grp, const std::string & key) const
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
	return anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft) == "1";
}

bool const/*success*/ noware::cmach::store::get (const std::string & key, std::string & val) const
//const std::pair <std::string/*value*/, bool/*reference*/> noware::pmach::store::get (const std::string & key) const
{
	return get ("", key, val);
}

bool const noware::cmach::store::get (std::string const & grp, std::string const & key, std::string & val) const
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
}

bool const noware::cmach::store::set (std::string const & key, std::string const & val)
//const bool noware::pmach::store::set (const std::string & key, const std::string & value, const bool & reference)
{
	return set ("", key, val);
	//return set ("", key, value, reference);
}

bool const noware::cmach::store::set (std::string const & grp, std::string const & key, std::string const & val)
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
	return anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft) == "1";
}

const cln::nr noware::cmach::store::capac (void) const
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "size::capac";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return std::string (anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft));
}

const cln::nr noware::cmach::store::used (void) const
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "size::used";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return std::string (anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft));
}

const cln::nr noware::cmach::store::avail (void) const
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "size::avail";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return std::string (anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft));
}

cln::nr const noware::cmach::store::size (void) const
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "size::count";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return std::string (anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft));
}

cln::nr const noware::cmach::store::size (std::string const & grp) const
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "size::count";
	expression ["group"] = grp;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return std::string (anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft));
}

bool const noware::cmach::store::empty (void) const
{
	//return count () <= 0;
	
	////noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "empty";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft) == "1";
}

bool const noware::cmach::store::full (void) const
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "full";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft) == "1";
}

/*
bool const rename (std::string const & old_k, std::string const & new_k);
{
	
	return true;
}
*/

bool const noware::cmach::store::remove (std::string const & key)
{
	return remove ("", key);
}

bool const noware::cmach::store::remove (std::string const & grp, std::string const & key)
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
	return anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft) == "1";
}

bool const noware::cmach::store::clear (void)
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "clearance";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft) == "1";
}

bool const noware::cmach::store::clear (std::string const & grp)
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "clearance";
	expression ["group"] = grp;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft) == "1";
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
