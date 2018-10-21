#pragma once

#include "x86_64.hxx"
#include <bitset>
#include <string>
//#include <sstream>
#include <cln/nr.cxx>
#include "../dev.cxx"
#include "../../usr/store.cxx"
#include "../../usr/queue.cxx"
#include "../../msg/subj.hxx"
#include ".x86_64/.incl.cxx"
#include <noware/var>

int short unsigned const noware::vos::srv::cpu::x86_64::noten_delay_dft = 10;
cln::nr const noware::vos::srv::cpu::x86_64::insn_cache_dft = 1;
std::string const noware::vos::srv::cpu::x86_64::grp_dft = "noware::vos::srv::cpu::x86_64";

#include ".x86_64/.cxx"

#include ".x86_64/exe.cxx"
#include ".x86_64/cycle.cxx"

/*
noware::vos::srv::cpu::instr::instr (void)
{
	thread_id = "";
	
	//oprn = opr::none;
	//device = dev::none;
	
	result_ref = false;
	result_dev = "";
	result_key = "";
	result_offset_prefetch_ref = false;
	result_offset_prefetch_dev = "";
	result_offset_prefetch_key = "";
	result_offset_postfetch_ref = false;
	result_offset_postfetch_dev = "";
	result_offset_postfetch_key = "";
	
	oprn = "";
	
	dest_ref = false;
	dest_dev = "";
	dest_key = "";
	dest_offset_prefetch_ref = false;
	dest_offset_prefetch_dev = "";
	dest_offset_prefetch_key = "";
	dest_offset_postfetch_ref = false;
	dest_offset_postfetch_dev = "";
	dest_offset_postfetch_key = "";
	
	src_ref = false;
	src_dev = "";
	src_key = "";
	src_offset_prefetch_ref = false;
	src_offset_prefetch_dev = "";
	src_offset_prefetch_key = "";
	src_offset_postfetch_ref = false;
	src_offset_postfetch_dev = "";
	src_offset_postfetch_key = "";
}

noware::vos::srv::cpu::instr::instr (std::string const & other)
{
	//oprn = opr::none;
	//deserialize (other);
	*this = other;
}

noware::vos::srv::cpu::instr::~instr (void)
{
}

template <typename archive>
void noware::vos::srv::cpu::instr::serialize (archive & arch, unsigned int const &/ * version* /)
{
	arch & thread_id;
	
	arch & result_ref;
	arch & result_dev;
	arch & result_key;
	arch & result_offset_prefetch_ref;
	arch & result_offset_prefetch_dev;
	arch & result_offset_prefetch_key;
	arch & result_offset_postfetch_ref;
	arch & result_offset_postfetch_dev;
	arch & result_offset_postfetch_key;
	
	arch & oprn;
	
	arch & dest_ref;
	arch & dest_dev;
	arch & dest_key;
	arch & dest_offset_prefetch_ref;
	arch & dest_offset_prefetch_dev;
	arch & dest_offset_prefetch_key;
	arch & dest_offset_postfetch_ref;
	arch & dest_offset_postfetch_dev;
	arch & dest_offset_postfetch_key;
	
	arch & src_ref;
	arch & src_dev;
	arch & src_key;
	arch & src_offset_prefetch_ref;
	arch & src_offset_prefetch_dev;
	arch & src_offset_prefetch_key;
	arch & src_offset_postfetch_ref;
	arch & src_offset_postfetch_dev;
	arch & src_offset_postfetch_key;
}

bool const noware::vos::srv::cpu::instr::deserialize (std::string const & serial)
{
	return noware::deserialize <noware::vos::srv::cpu::instr> (*this, serial);
}

std::string const noware::vos::srv::cpu::instr::serialize (void) const
{
	std::string serial;
	
	if (noware::serialize <noware::vos::srv::cpu::instr> (serial, *this))
		return serial;
	else
		return "";
}

/ *
const std::string noware::vos::srv::cpu::instr::val (void) const
{
	//return oprnd [0];
	return "";
}
* /

noware::vos::srv::cpu::instr const & noware::vos::srv::cpu::instr::operator = (instr const & other)
{
	thread_id = other.thread_id;
	
	result_ref = other.result_ref;
	result_dev = other.result_dev;
	result_key = other.result_key;
	result_offset_prefetch_ref = other.result_offset_prefetch_ref;
	result_offset_prefetch_dev = other.result_offset_prefetch_dev;
	result_offset_prefetch_key = other.result_offset_prefetch_key;
	result_offset_postfetch_ref = other.result_offset_postfetch_ref;
	result_offset_postfetch_dev = other.result_offset_postfetch_dev;
	result_offset_postfetch_key = other.result_offset_postfetch_key;
	
	oprn = other.oprn;
	
	dest_ref = other.dest_ref;
	dest_dev = other.dest_dev;
	dest_key = other.dest_key;
	dest_offset_prefetch_ref = other.dest_offset_prefetch_ref;
	dest_offset_prefetch_dev = other.dest_offset_prefetch_dev;
	dest_offset_prefetch_key = other.dest_offset_prefetch_key;
	dest_offset_postfetch_ref = other.dest_offset_postfetch_ref;
	dest_offset_postfetch_dev = other.dest_offset_postfetch_dev;
	dest_offset_postfetch_key = other.dest_offset_postfetch_key;
	
	src_ref = other.src_ref;
	src_dev = other.src_dev;
	src_key = other.src_key;
	src_offset_prefetch_ref = other.src_offset_prefetch_ref;
	src_offset_prefetch_dev = other.src_offset_prefetch_dev;
	src_offset_prefetch_key = other.src_offset_prefetch_key;
	src_offset_postfetch_ref = other.src_offset_postfetch_ref;
	src_offset_postfetch_dev = other.src_offset_postfetch_dev;
	src_offset_postfetch_key = other.src_offset_postfetch_key;
	
	return *this;
}

const std::string & noware::vos::srv::cpu::instr::operator = (const std::string & other)
{
	deserialize (other);
	return other;
}

noware::vos::srv::cpu::instr::operator const std::string (void) const
{
	return serialize ();
}

void noware::vos::srv::cpu::instr::dump (void) const
{
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::thread_id[" << thread_id << "]" << std::endl;
	
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::result_ref[" << result_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::result_dev[" << result_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::result_key[" << result_key << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::result_offset_prefetch_ref[" << result_offset_prefetch_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::result_offset_prefetch_dev[" << result_offset_prefetch_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::result_offset_prefetch_key[" << result_offset_prefetch_key << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::result_offset_postfetch_ref[" << result_offset_postfetch_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::result_offset_postfetch_dev[" << result_offset_postfetch_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::result_offset_postfetch_key[" << result_offset_postfetch_key << "]" << std::endl;
	
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::oprn[" << oprn << "]" << std::endl;
	
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::dest_ref[" << dest_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::dest_dev[" << dest_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::dest_key[" << dest_key << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::dest_offset_prefetch_ref[" << dest_offset_prefetch_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::dest_offset_prefetch_dev[" << dest_offset_prefetch_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::dest_offset_prefetch_key[" << dest_offset_prefetch_key << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::dest_offset_postfetch_ref[" << dest_offset_postfetch_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::dest_offset_postfetch_dev[" << dest_offset_postfetch_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::dest_offset_postfetch_key[" << dest_offset_postfetch_key << "]" << std::endl;
	
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::src_ref[" << src_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::src_dev[" << src_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::src_key[" << src_key << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::src_offset_prefetch_ref[" << src_offset_prefetch_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::src_offset_prefetch_dev[" << src_offset_prefetch_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::src_offset_prefetch_key[" << src_offset_prefetch_key << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::src_offset_postfetch_ref[" << src_offset_postfetch_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::src_offset_postfetch_dev[" << src_offset_postfetch_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::instr::dump()::src_offset_postfetch_key[" << src_offset_postfetch_key << "]" << std::endl;
}
*/
noware::vos::srv::cpu::x86_64::x86_64 (void)
{
	//_running = false;	// Not strictly needed
	_exen = nullptr;
	_notification = nullptr;
	//assert (node.join (grp_dft));
	//node.join ("noware::mach::thread::1");
	
	_insn_cache = insn_cache_dft;
}

noware::vos::srv::cpu::x86_64::~x86_64 (void)
{
	//_running = false;
	stop ();
	//fin ();
	//_mutex.unlock ();
}

bool const noware::vos::srv::cpu::x86_64::stop (void)
{
	//if (!running ())
	//	return true;
	
	//if (_exen == nullptr && _notification == nullptr)
	//	return true;
	
	//if (!dev::stop ());
	//	return false;
	
	//assert (node.reception_unset ());
	//_running = false;
	
	/*
	#pragma omp parallel
	{
		#pragma omp for
		for (unsigned int ndx = 1; ndx <= 2 ; ++ndx)
		{
			#pragma omp critical
			{
				_exen -> interrupt ();
				_exen -> join ();
				delete _exen;
				_exen = nullptr;
			}
			
			#pragma omp critical
			{
				_notification -> interrupt ();
				_notification -> join ();
				delete _notification;
				_notification = nullptr;
			}
		}
	}
	*/
	
	//_mutex.unlock ();
	//_condition_instr_enqueued.notify_all ();
	
	//_running = false;
	
	if (_exen != nullptr)
	{
		//boost::this_thread::sleep_for (boost::chrono::seconds (2));
		
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::stop()::_exen->interrupt()ing" << std::endl;
		_exen -> interrupt ();
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::stop()::_exen->interrupt()ed" << std::endl;
		
		{
			//boost::lock_guard <boost::mutex> lock (_mutex);
			//_insn_avail = true;
		}
		//_condition_instr_enqueued.notify_all ();
		//_condition_instr_enqueued.notify_one ();
		//_running = false;
		
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::stop()::_exen->join()ing" << std::endl;
		_exen -> join ();
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::stop()::_exen->join()ed" << std::endl;
		
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::stop()::delete-ing _exen" << std::endl;
		delete _exen;
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::stop()::delete-ed _exen" << std::endl;
		_exen = nullptr;
	}
	
	if (_notification != nullptr)
	{
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::stop()::_notification->interrupt()ing" << std::endl;
		_notification -> interrupt ();
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::stop()::_notification->interrupt()ed" << std::endl;
		
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::stop()::_notification->join()ing" << std::endl;
		_notification -> join ();
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::stop()::_notification->join()ed" << std::endl;
		
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::stop()::delete-ing _notification" << std::endl;
		delete _notification;
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::stop()::delete-ed _notification" << std::endl;
		_notification = nullptr;
	}
	
	if (!dev::stop ());
		return false;
	
	//_running = false;
	
	return true;
}

bool const noware::vos::srv::cpu::x86_64::running (void) const
{
	if (_exen == nullptr || _notification == nullptr)
		return false;
	
	if (!dev::running ())
		return false;
	
	return true;
}

bool const noware::vos::srv::cpu::x86_64::start (void)
{
	//_running = true;
	
	//if (running ())
	//	return true;
	
	//if (_exen != nullptr && _notification != nullptr)
	//	return true;
	
	//assert (dev::start ());
	if (!dev::start ())
		return false;
	
	//_running = true;
	if (_notification == nullptr)
	{
		_notification = new boost::thread (boost::bind (boost::mem_fn (&noware::vos::srv::cpu::x86_64::notify), this, noten_delay_dft));
		
		if (_notification == nullptr)
			return false;
	}
	
	if (_exen == nullptr)
	{
		_exen = new boost::thread (boost::bind (boost::mem_fn (&noware::vos::srv::cpu::x86_64::cycle), this));
		
		if (_exen == nullptr)
		{
			_notification -> interrupt ();
			_notification -> join ();
			delete _notification;
			_notification = nullptr;
			
			//_running = false;	// Not strictly needed
			
			return false;
		}
	}
	
	if (!_node.join (grp_dft))
		return false;
	
	//_running = true;
	//return _exen != nullptr;
	//assert (_exen != nullptr);
	return true;
}

void noware::vos::srv::cpu::x86_64::notify (int unsigned const & delay_)
{
	//boost::this_thread::disable_interruption non_interrupt;
	//boost::lock_guard <boost::mutex> lock (_mutex);
	
	while (true)
	//while (_running)
	//while (!boost::this_thread::interruption_requested ())
	{
		//_insn_avail = false;
		
		try
		{
			std::cerr << "[" << boost::this_thread::get_id () << "] " << "noware::vos::srv::cpu::notify::sleeping for " << delay_ << " seconds" << std::endl;
			boost::this_thread::sleep_for (boost::chrono::seconds (delay_));
			std::cerr << "[" << boost::this_thread::get_id () << "] " << "noware::vos::srv::cpu::notify::slept for " << delay_ << " seconds" << std::endl;
		}
		catch (const boost::thread_interrupted &/* interruption*/)
		{
			std::cerr << "[" << boost::this_thread::get_id () << "] " << "noware::vos::srv::cpu::notify::this_thread.sleep()::caught boost::thread_interrupted" << std::endl;
			break;
		}
		
		//_mutex.unlock ();
		std::cerr << "[" << boost::this_thread::get_id () << "] " << "noware::vos::srv::cpu::notify::_condition_instr_enqueued.notify_all()ing" << std::endl;
		{
			//boost::lock_guard <boost::mutex> lock (_mutex);
			_insn_avail = true;
		}
		_condition_instr_enqueued.notify_all ();
		std::cerr << "[" << boost::this_thread::get_id () << "] " << "noware::vos::srv::cpu::notify::_condition_instr_enqueued.notify_all()ed" << std::endl;
		
		try
		{
			boost::this_thread::interruption_point ();
		}
		catch (...)
		//catch (const boost::thread_interrupted &/* interruption*/)
		{
			std::cerr << "[" << boost::this_thread::get_id () << "] " << "noware::vos::srv::cpu::notify::interruption_point()::caught boost::thread_interrupted" << std::endl;
			break;
		}
	}
	
	//_condition_instr_enqueued.notify_all ();
}

bool const noware::vos::srv::cpu::x86_64::clear (void)
{
	return usr::store <store_val_t, store_key_t, store_grp_t>::clear ();
}

// Queue
cln::nr const noware::vos::srv::cpu::x86_64::size (void) const
{
	return usr::queue <queue_val_t>::size ();
}

bool const noware::vos::srv::cpu::x86_64::empty (void) const
{
	return usr::queue <queue_val_t>::empty ();
}

bool const noware::vos::srv::cpu::x86_64::full (void) const
{
	return usr::queue <queue_val_t>::full ();
}

bool const noware::vos::srv::cpu::x86_64::cout (char unsigned const & val)
{
	/*
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	subj = msg::subj::cout;
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	req.data [1] = zmq::message_t (val.c_str (), val.size () + 1/* for '\0'* /);
	
	re = multival (req, noware::vos::srv::cmd::grp_dft);
	
	try
	{
		// result
		return *(re.data.at (1).data.data <bool> ());
	}
	catch (...)
	{
		return false;
	}
	*/
	
	/*
	cln::nr out_val;
	
	out_val = value;
	
	std::cout << (char) (out_val.operator unsigned long int const ());
	*/
	
	
	//std::cout << val;
	std::cout << "##############################[" << val << "]##############################" << std::endl;
	
	return true;
	
}

bool const noware::vos::srv::cpu::x86_64::cin (std::string & result, char const & delimiter)
{
	/*
	zmq::msg msg;
	std::map <std::string, std::string> xpr;
	std::string xpr_serial;
	
	xpr ["subject"] = "cin";
	xpr ["delimiter"] = delimiter;
	
	if (!noware::serialize <std::map <std::string, std::string>> (xpr_serial, xpr))
		return "";
	
	msg = xpr_serial;
	result = locval (msg);
	return true;
	*/
	return false;
}

/*
const bool noware::vos::srv::cpu::enqueue (const std::string & operand1, const opr & op, const std::string & operand2, const std::string & thread_id)
{
	instr inst;
	
	inst.oprn = op;
	inst.oprnd [0] = operand1;
	inst.oprnd [1] = operand2;
	//inst.oprnd [2] = operand3;
	inst.thread_id = thread_id;
	
	return enqueue (inst);
}
*/
/*
const bool noware::vos::srv::cpu::enqueue (const cpu::dev & device, const opr & op, const std::map <std::string, std::string> & arg, const std::string & thread_id)
{
	instr inst;
	
	inst.oprn = op;
	inst.device = device;
	//inst.oprnd [0] = operand1;
	//inst.oprnd [1] = operand2;
	////inst.oprnd [2] = operand3;
	inst.arg = arg;
	inst.thread_id = thread_id;
	
	return enqueue (inst);
}
*/

/*
const bool noware::vos::srv::cpu::respond (const zyre_event_t * event, const std::string & event_type, const std::string & shouted_group, const zmq::msg & msg_request, zmq::msg & msg_response)
{
	std::cerr << "noware::vos::srv::cpu::respond()::called" << std::endl;
	
	//noware::tree <std::string, std::string> response;
	std::map <std::string, std::string> response;
	//noware::tree <std::string, std::string> message;
	std::map <std::string, std::string> message;
	noware::var result_tmp;
	bool result;
	
//	zframe_t * frm;
	//cln::nr ndx;
	
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
	
	std::cerr << "noware::vos::srv::cpu::respond()::if::message[subject]==[" << message ["subject"] << ']' << std::endl;
	
	if (message ["type"] == "response")
	{
		std::cerr << "noware::vos::srv::cpu::respond()::if::message[type]==" << message ["type"] << "::in scope" << std::endl;
		
		//if (message ["subject"] == "existence")
		//{
			std::cerr << "noware::vos::srv::cpu::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			//std::cerr << "noware::vos::srv::cpu::receive()::else::msg[subject]==" << msg ["subject"] << "::sleeping" << std::endl;
			//zclock_sleep (1500);
			
			// Redirect the message to the function which asked for it.
			////unicast_local (zmsg_popstr (zmq_msg));
			//result = unicast_local (msg_rx);
			result = unicast_local (msg, "");
			std::cerr << "noware::vos::srv::cpu::respond()::unicast_local(message)==" << (result ? "success" : "failure") << std::endl;
		//}
	}
	
	return result;
}
*/

bool/* success*/ const noware::vos::srv::cpu::x86_64::respond (zmq::msg &/* response*/, const zmq::msg & rxd, const zyre_event_t */* (zyre) event*/, const std::string & event_type, const std::string &/* src*/, const net::cast &/* src_cast*/)
{
	std::cerr << "noware::vos::srv::cpu::respond()::in scope" << std::endl;
	std::cerr << "noware::vos::srv::cpu::respond()::event_type==[" << event_type << "]" << std::endl;
	
	//std::cerr << "noware::vos::srv::cpu::respond()::rxd==[" << std::string (rxd) << "]" << std::endl;
	////std::cerr << "noware::vos::srv::cpu::respond()::rxd.data[1]==[" << std::string (rxd.data [1]) << "]" << std::endl;
	if (rxd == "enqueued(instr)")
	{
		std::cerr << "noware::vos::srv::cpu::respond()::rxd==[enqueued(instr)]" << std::endl;
		
		// There are instructions to execute.
		//std::cerr << "noware::vos::srv::cpu::respond()::_mutex.unlock()" << std::endl;
		//_mutex.unlock ();
		std::cerr << "noware::vos::srv::cpu::respond()::_condition_instr_enqueued.notify_all()" << std::endl;
		{
			//boost::lock_guard <boost::mutex> lock (_mutex);
			_insn_avail = true;
		}
		_condition_instr_enqueued.notify_all ();
	}
	
	return true;
}

bool/* success*/ const noware::vos::srv::cpu::x86_64::search_remote (zmq::msg const & msg_result, const zmq::msg & msg_resp, const cln::nr &/* total, expected resonses count*/, const cln::nr &/* current count of peers who responded (so far)*/, const std::string &/* src*/, const net::cast &/* src_cast*/)
{
	std::cerr << "noware::vos::srv::cpu::search()::called" << std::endl;
	
	return false;
}

bool const/* success*/ noware::vos::srv::cpu::x86_64::aggregate_remote (zmq::msg & msg_result/* overall/final result. passed during each iteration*/, zmq::msg const & msg_curr/* current response message/expression*/, cln::nr const &/* total, expected resonses count*/, cln::nr const &/* current count of peers who responded (so far)*/, std::string const &/* src*/, net::cast const &/* src_cast*/)
{
	// normally, there should be only one message:
	// the one from the manager who we requested from,
	// so this function should only be called once,
	// having the current message as the only message (and the final result)
	msg_result = msg_curr;
	return true;
}
