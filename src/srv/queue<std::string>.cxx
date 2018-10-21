#pragma once

#include "dev.cxx"
#include "queue.hxx"
#include <cln/nr.cxx>
#include <noware/var.cxx>
#include "../msg/subj.hxx"

template <typename val_t>
std::string const noware::vos::srv::queue <val_t>::grp_dft = "noware::vos::srv::queue";

template <typename val_t>
noware::vos::srv::queue <val_t>::queue (void)
{
	//assert (node.join (grp_dft));
	//assert (node.join ("noware::vos::srv::queue::nonfull"));
}

template <typename val_t>
noware::vos::srv::queue <val_t>::~queue (void)
{
}

template <typename val_t>
bool const noware::vos::srv::queue <val_t>::start (void)
{
	if (!dev::start ())
		return false;
	
	if (!_node.join (/*noware::vos::srv::store::*/grp_dft))
		return false;
	
	if (!_node.join (grp_dft + std::string ("::nonfull"))) // Temporary: dynamically find when needed.
		return false;
	
	return true;
}

template <typename val_t>
bool const noware::vos::srv::queue <val_t>::empty (void) const
{
	return queue.empty ();
}

/*
const bool noware::vos::srv::queue::empty_local (void) const
{
	return queue.empty ();
}
*/

template <typename val_t>
bool const noware::vos::srv::queue <val_t>::full (void) const
{
	return false;
}

/*
const bool noware::vos::srv::queue::full_local (void) const
{
	return false;
}
*/

template <typename val_t>
cln::nr const noware::vos::srv::queue <val_t>::size (void) const
{
	return queue.size ();
}

template <typename val_t>
bool const noware::vos::srv::queue <val_t>::next (val_t & element) const
{
	if (queue.empty ())
		return false;
	
	element = queue.front ();
	return true;
}

template <typename val_t>
bool const noware::vos::srv::queue <val_t>::next_dequeue (val_t & element)
{
	if (queue.empty ())
		return false;
	
	//val_t front;
	element = queue.front ();
	queue.pop ();
	return true;
}

template <typename val_t>
bool const noware::vos::srv::queue <val_t>::dequeue (void)
{
	if (queue.empty ())
		return false;
	
	queue.pop ();
	return true;
}

template <typename val_t>
bool const noware::vos::srv::queue <val_t>::enqueue (val_t const & element)
{
	if (full ())
		return false;
	
	queue.push (element);
	return true;
}

template <typename val_t>
bool const noware::vos::srv::queue <val_t>::clear (void)
{
	queue = {};
	return true;
}

template <typename val_t>
bool const/* success*/ noware::vos::srv::queue <val_t>::respond (zmq::msg & re, zmq::msg const & req, zyre_event_t const * const/* event*/, std::string const &/* event_type*/, std::string const &/* src*/, net::cast const &/* src_cast*/)
{
	std::cerr << grp_dft << "::respond()::call" << std::endl;
	
	msg::subj * msg_req_subj;
	
	req.dump ();
	
	try
	{
		msg_req_subj = req.data.at (0/*subj*/).data.data <msg::subj> ();
		
		re.data [0] = req.data.at (0/*msg::subj*/);;
		
		switch (*msg_req_subj)
		{
			case msg::subj::empty:
				std::cerr << grp_dft << "::respond()::if::message[subject]==empty::in scope" << std::endl;
				
				bool empty_;
				empty_ = queue.empty ();
				re.data [1] = zmq::message_t (&empty_, sizeof empty_);
				break;
			case msg::subj::size:
				std::cerr << grp_dft << "::respond()::size" << std::endl;
				
				int unsigned count;
				count = queue.size ();
				re.data [1] = zmq::message_t (&count, sizeof count);
				break;
			case msg::subj::next_dequeue:
				std::cerr << grp_dft << "::respond()::next_dequeue" << std::endl;
				
				//bool succ;
				if (!queue.empty ())
				{
					val_t element;
					element = queue.front ();
					// this is performed in respond_post()
					// reason: do not dequeue if the caller did not receive the element
					//queue.pop ();
					re.data [1] = zmq::message_t (&element, sizeof element);
					//succ = true;
				}
				//else
				//	succ = false;
				//re.data [1] = zmq::message_t (&succ, sizeof succ);
				break;
			case msg::subj::next:
				std::cerr << grp_dft << "::respond()::next" << std::endl;
				
				//bool succ;
				if (!queue.empty ())
				{
					val_t element;
					element = queue.front ();
					re.data [1] = zmq::message_t (&element, sizeof element);
					//succ = true;
				}
				//else
				//	succ = false;
				//re.data [1] = zmq::message_t (&succ, sizeof succ);
				break;
			case msg::subj::dequeue:
			{
				std::cerr << grp_dft << "::respond()::dequeue" << std::endl;
				
				bool succ;
				if (queue.empty ())
					succ = false;
				else
				{
					queue.pop ();
					
					if (queue.empty ())
						assert (_node.leave (grp_dft + std::string ("::nonempty")));
					
					assert (_node.join (grp_dft + std::string ("::nonfull")));
					
					succ = true;
				}
				re.data [1] = zmq::message_t (&succ, sizeof succ);
				break;
			}
			case msg::subj::enqueue:
			{
				std::cerr << grp_dft << "::respond()::enqueue" << std::endl;
				
				bool succ;
				if (full ())
					succ = false;
				else
				{
					std::cerr << grp_dft << "::respond()::enqueue::succ" << std::endl;
					
					val_t element;
					//req.dump ();
					std::cerr << grp_dft << "::respond()::enqueue::cast" << std::endl;
					element = *(req.data.at (1).data.data <val_t> ());
					std::cerr << grp_dft << "::respond()::enqueue::push" << std::endl;
					queue.push (element);
					
					if (full ())
						assert (_node.leave (grp_dft + std::string ("::nonfull")));
					
					assert (_node.join (grp_dft + std::string ("::nonempty")));
					
					succ = true;
				}
				re.data [1] = zmq::message_t (&succ, sizeof succ);
				break;
			}
			case msg::subj::clear:
			{
				std::cerr << grp_dft << "::respond()::clear" << std::endl;
				
				bool succ;
				queue = {};
				assert (_node.leave (grp_dft + std::string ("::nonempty")));
				assert (_node.join (grp_dft + std::string ("::nonfull")));
				succ = true;
				re.data [1] = zmq::message_t (&succ, sizeof succ);
				break;
			}
			default:
				return false;
		}
	}
	catch (...)
	{
		std::cerr << grp_dft << "::respond()::exception" << std::endl;
		return false;
	}
	
	std::cerr << grp_dft << "::respond()::return" << std::endl;
	return true;
}

template <typename val_t>
bool const/* success*/ noware::vos::srv::queue <val_t>::respond_post (zmq::msg const & re, zmq::msg const & req, zyre_event_t const * const event, std::string const & event_type, std::string const &/* src*/, net::cast const &/* src_cast*/, bool const & result)
{
	std::cerr << grp_dft << "::respond_post()::call" << std::endl;
	
	if (result)
	{
		msg::subj * msg_req_subj;
		
		try
		{
			msg_req_subj = req.data.at (0/*subj*/).data.data <msg::subj> ();
			
			switch (*msg_req_subj)
			{
				case msg::subj::next_dequeue:
					std::cerr << grp_dft << "::respond_post()::next_dequeue" << std::endl;
					
					if (queue.empty ())
						return false;
					else
					{
						queue.pop ();
						
						if (queue.empty ())
							assert (_node.leave (grp_dft + std::string ("::nonempty")));
						
						assert (_node.join (grp_dft + std::string ("::nonfull")));
						
						//response ["success"] = "1";
						////response ["value"] = "1";
						return true;
					}
			}
		}
		catch (...)
		{
			std::cerr << grp_dft << "::respond_post()::exception" << std::endl;
			return false;
		}
	}
	
	return true;
}
