#pragma once

#include "store.hxx"

#include "dev.cxx"
#include <string>
#include <noware/contnr/array.cxx>
#include <cln/nr.cxx>
#include <noware/var.cxx>
#include "../srv/store.cxx"
#include "../msg/subj.hxx"

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
		if (msg_re_curr.data.count (0) > 0)
		{
			re_subj = msg_re_curr.data.at (0).data.data <msg::subj> ();
			
			if (msg_result.data.count (0) <= 0)
			{
				msg_result.data [0] = msg_re_curr.data.at (0);
			}
		}
		else
		{
			// invalid message (msg::subj is missing)
			return false;
		}
		
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
					
					// this sets up the value for subsequent iterations
					// depending on the type of boolean logic required
					if (*re_subj == msg::subj::exist)
						val = false;
					else
						val = true;
					
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
				std::cerr << "noware::vos::man::store::respond()::set" << std::endl;
				re = anyval (req, noware::vos::srv::store <val_t, key_t, grp_t>::grp_dft + std::string ("::nonfull"));
				break;
			case msg::subj::get:
			case msg::subj::exist:
			case msg::subj::del:
			case msg::subj::clear:
				std::cerr << "noware::vos::man::store::respond()::get/exist/del/clear" << std::endl;
				re = multival (req, noware::vos::srv::store <val_t, key_t, grp_t>::grp_dft + std::string ("::nonempty"));
				
				// the special case of obtainment is excluded from this logic:
				// obtainment has the return value optionally present, dependent on
				// whether the value existed in the first place. its logic does not
				// change: its success is determined by the fact if we actually otained
				// the desired value
				if (*req_subj != msg::subj::get)
				{
					std::cerr << "noware::vos::man::store::respond()::exist/del/clear" << std::endl;
					
					// if there were no nonempty peers,
					// then consider that the task is already done
					// (return success)
					if (re.data.count (1) <= 0)
					{
						std::cerr << "noware::vos::man::store::respond()::exist/del/clear::!present[1]" << std::endl;
						
						bool succ;
						succ = true;
						re.data [1] = zmq::message_t (&succ, sizeof succ);
					}
				}
				
				/*
					we need to add the heading msg::subj also
					(if there were no replying nodes => empty message),
					to preserve the order of indexes;
					otherwise, the map will be reindexed
					when the message is being casted while it is being sent/received
					within the class zmq::msg
				*/
				if (re.data.count (0) <= 0)
				{
					//msg::subj subj;
					//subj = *req_subj;
					//re.data [0] = zmq::message_t (req_subj, sizeof *req_subj);
					re.data [0] = req.data.at (0);
				}
				
				
				break;
			case msg::subj::size:
			case msg::subj::avail:
			case msg::subj::capac:
			case msg::subj::used:
			case msg::subj::full:
			case msg::subj::empty:
				std::cerr << "noware::vos::man::store::respond()::msg::subj::avail/capac/used/full/empty" << std::endl;
				re = multival (req, noware::vos::srv::store <val_t, key_t, grp_t>::grp_dft);
				break;
			default:
				std::cerr << "noware::vos::man::store::respond()::default" << std::endl;
				return false;
		}
	}
	catch (...)
	{
		std::cerr << "noware::vos::man::store::respond()::caught" << std::endl;
		return false;
	}
	
	std::cerr << "noware::vos::man::store::respond()::return[true]" << std::endl;
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
