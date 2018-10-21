#pragma once

#include "queue.hxx"
#include "dev.cxx"
#include "../man/queue.cxx"
#include <cln/nr.cxx>
#include "../msg/subj.hxx"

template <typename val_t>
std::string const noware::vos::usr::queue <val_t>::grp_dft = "noware::vos::usr::queue";

template <typename val_t>
noware::vos::usr::queue <val_t>::queue (void)
{
	//assert (_node.join (grp_dft));
	//assert (_node.join ("noware::vos::usr::queue <val_t>::nonfull"));
}

template <typename val_t>
noware::vos::usr::queue <val_t>::~queue (void)
{
}

// const bool noware::vos::usr::queue <val_t>::start (void)
// {
// 	if (!dev::start ())
// 		return false;
// 	
// 	//if (!_node.join (/*noware::cmach::store::*/grp_dft))
// 	//	return false;
// 	//
// 	//if (!_node.join (grp_dft + std::string ("::nonfull"))) // Temporary: dynamically find when needed.
// 	//	return false;
// 	
// 	return true;
// }

template <typename val_t>
bool const noware::vos::usr::queue <val_t>::empty (void) const
{
	std::cerr << "noware::vos::usr::queue::empty()" << std::endl;
	
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	
	subj = msg::subj::empty;
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	
	
	// perform the call
	re = anyval (req, noware::vos::man::queue <val_t>::grp_dft);
	
	try
	{
		//if (!(*(re.data.at (0).data.data <bool> ())/*succes*/))
		//	return true;
		
		return *(re.data.at (1).data.data <bool> ())/*data value*/;
	}
	catch (...)
	{
		std::cerr << "noware::vos::usr::queue::empty::exception::caught" << std::endl;
		return false;
	}
}

/*
const bool noware::vos::usr::queue <val_t>::empty_local (void) const
{
	return queue.empty ();
}
*/

template <typename val_t>
bool const noware::vos::usr::queue <val_t>::full (void) const
{
	std::cerr << "noware::vos::usr::queue::full()" << std::endl;
	
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	
	subj = msg::subj::full;
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	
	
	// perform the call
	re = anyval (req, noware::vos::man::queue <val_t>::grp_dft);
	
	try
	{
		//if (!(*(re.data.at (0).data.data <bool> ())/*succes*/))
		//	return true;
		
		return *(re.data.at (1).data.data <bool> ())/*data value*/;
	}
	catch (...)
	{
		std::cerr << "noware::vos::usr::queue::empty::exception::caught" << std::endl;
		return false;
	}
}

/*
const bool noware::vos::usr::queue <val_t>::full_local (void) const
{
	return false;
}
*/

template <typename val_t>
cln::nr const noware::vos::usr::queue <val_t>::size (void) const
{
	std::cerr << "noware::vos::usr::queue::size()" << std::endl;
	
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	
	subj = msg::subj::size;
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	
	
	// perform the call
	re = anyval (req, noware::vos::man::queue <val_t>::grp_dft);
	
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

template <typename val_t>
bool const noware::vos::usr::queue <val_t>::next (val_t & element) const
{
	std::cerr << "noware::vos::usr::queue::next()" << std::endl;
	
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	
	subj = msg::subj::next;
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	
	
	// perform the call
	re = anyval (req, noware::vos::man::queue <val_t>::grp_dft);
	
	try
	{
		//if (!(*(re.data.at (0).data.data <bool> ())/*succes*/))
		//	return false;
		//
		//if (!(*(re.data.at (1).data.data <bool> ())/*exist*/))
		//	return false;
		
		if (re.data.count (1) <= 0)
			return false;
		
		element = *(re.data.at (1).data.data <val_t> ())/*data value*/;
		return true;
	}
	catch (...)
	{
		return false;
	}
}

template <>
bool const noware::vos::usr::queue <std::string>::next (std::string & element) const
{
	std::cerr << "noware::vos::usr::queue<std::string>::next()" << std::endl;
	
	typedef std::string val_t;
	
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	
	subj = msg::subj::next;
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	
	
	// perform the call
	re = anyval (req, noware::vos::man::queue <val_t>::grp_dft);
	
	try
	{
		//if (!(*(re.data.at (0).data.data <bool> ())/*succes*/))
		//	return false;
		//
		//if (!(*(re.data.at (1).data.data <bool> ())/*exist*/))
		//	return false;
		
		if (re.data.count (1) <= 0)
			return false;
		
		// data value
		element = re.data.at (1).data.data <char const> ();
		return true;
	}
	catch (...)
	{
		return false;
	}
}

template <typename val_t>
bool const noware::vos::usr::queue <val_t>::next_dequeue (val_t & element)
{
	std::cerr << "noware::vos::usr::queue::next_dequeue()" << std::endl;
	
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	
	subj = msg::subj::next_dequeue;
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	
	
	// perform the call
	re = anyval (req, noware::vos::man::queue <val_t>::grp_dft);
	
	try
	{
		//if (!(*(re.data.at (0).data.data <bool> ())/*succes*/))
		//	return false;
		//
		//if (!(*(re.data.at (1).data.data <bool> ())/*exist*/))
		//	return false;
		
		//if (re.data.count (1) <= 0)
		//	return false;
		
		element = *(re.data.at (1).data.data <val_t> ())/*data value*/;
		return true;
	}
	catch (...)
	{
		return false;
	}
}

template <>
bool const noware::vos::usr::queue <std::string>::next_dequeue (std::string & element)
{
	std::cerr << "noware::vos::usr::queue<std::string>::next_dequeue()" << std::endl;
	
	typedef std::string val_t;
	
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	
	subj = msg::subj::next_dequeue;
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	
	
	// perform the call
	re = anyval (req, noware::vos::man::queue <val_t>::grp_dft);
	
	try
	{
		//if (!(*(re.data.at (0).data.data <bool> ())/*succes*/))
		//	return false;
		//
		//if (!(*(re.data.at (1).data.data <bool> ())/*exist*/))
		//	return false;
		
		//if (re.data.count (1) <= 0)
		//	return false;
		
		// data value
		element = re.data.at (1).data.data <char const> ();
		return true;
	}
	catch (...)
	{
		return false;
	}
}

template <typename val_t>
bool const noware::vos::usr::queue <val_t>::dequeue (void)
{
	std::cerr << "noware::vos::usr::queue::dequeue()" << std::endl;
	
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	
	subj = msg::subj::dequeue;
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	
	
	// perform the call
	re = anyval (req, noware::vos::man::queue <val_t>::grp_dft);
	
	try
	{
		//if (!(*(re.data.at (0).data.data <bool> ())/*succes*/))
		//	return false;
		//
		//if (!(*(re.data.at (1).data.data <bool> ())/*exist*/))
		//	return false;
		
		// success
		return *(re.data.at (1).data.data <bool> ());
	}
	catch (...)
	{
		return false;
	}
}

template <typename val_t>
bool const noware::vos::usr::queue <val_t>::enqueue (val_t const & element)
{
	std::cerr << "noware::vos::usr::queue::enqueue()" << std::endl;
	
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	
	subj = msg::subj::enqueue;
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	req.data [1] = zmq::message_t (&element, sizeof element);
	
	
	// perform the call
	re = anyval (req, noware::vos::man::queue <val_t>::grp_dft);
	
	try
	{
		// success
		return *(re.data.at (1).data.data <bool> ());
	}
	catch (...)
	{
		return false;
	}
}

template <>
bool const noware::vos::usr::queue <std::string>::enqueue (std::string const & element)
{
	std::cerr << "noware::vos::usr::queue<std::string>::enqueue()" << std::endl;
	
	typedef std::string val_t;
	
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	
	subj = msg::subj::enqueue;
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	req.data [1] = zmq::message_t (element.c_str (), element.size () + 1/* for '\0'*/);
	
	
	// perform the call
	re = anyval (req, noware::vos::man::queue <val_t>::grp_dft);
	
	try
	{
		// success
		return *(re.data.at (1).data.data <bool> ());
	}
	catch (...)
	{
		return false;
	}
}

template <typename val_t>
bool const noware::vos::usr::queue <val_t>::clear (void)
{
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	
	subj = msg::subj::clear;
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	
	
	// perform the call
	re = anyval (req, noware::vos::man::queue <val_t>::grp_dft);
	
	try
	{
		//if (!(*(re.data.at (0).data.data <bool> ())/*succes*/))
		//	return true;
		
		return *(re.data.at (1).data.data <bool> ())/*data value*/;
	}
	catch (...)
	{
		std::cerr << "noware::vos::usr::queue::clear::exception::caught" << std::endl;
		return false;
	}
}

template <typename val_t>
bool const/* success*/ noware::vos::usr::queue <val_t>::search_remote (zmq::msg const & msg_result, const zmq::msg & msg_resp, const cln::nr &/* total, expected resonses count*/, const cln::nr &/* current count of peers who responded (so far)*/, const std::string &/* src*/, const net::cast &/* src_cast*/)
{
	std::cerr << grp_dft << "::search()::called" << std::endl;
	
	return true;
}

template <typename val_t>
bool const/* success*/ noware::vos::usr::queue <val_t>::aggregate_remote (zmq::msg & msg_result/* overall/final result. passed during each iteration*/, zmq::msg const & msg_curr/* current response message/expression*/, cln::nr const &/* total, expected resonses count*/, cln::nr const &/* current count of peers who responded (so far)*/, std::string const &/* src*/, net::cast const &/* src_cast*/)
{
	// normally, there should be only one message:
	// the one from the manager who we requested from,
	// so this function should only be called once,
	// having the current message as the only message (and the final result)
	msg_result = msg_curr;
	return true;
}
