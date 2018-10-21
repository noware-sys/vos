#pragma once

#include "cpu.hxx"
#include <cln/nr.cxx>
#include ".cpu/.incl.cxx"
#include ".cpu/.cxx"

unsigned int const noware::smach::cpu::noten_delay_dft = 5;
std::string const noware::smach::cpu::grp_dft = "noware::smach::cpu";

//#include ".cpu/.cxx"

/*
noware::smach::cpu::instr::instr (void)
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

noware::smach::cpu::instr::instr (std::string const & other)
{
	//oprn = opr::none;
	//deserialize (other);
	*this = other;
}

noware::smach::cpu::instr::~instr (void)
{
}

template <typename archive>
void noware::smach::cpu::instr::serialize (archive & arch, unsigned int const &/ * version* /)
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

bool const noware::smach::cpu::instr::deserialize (std::string const & serial)
{
	return noware::deserialize <noware::smach::cpu::instr> (*this, serial);
}

std::string const noware::smach::cpu::instr::serialize (void) const
{
	std::string serial;
	
	if (noware::serialize <noware::smach::cpu::instr> (serial, *this))
		return serial;
	else
		return "";
}

/ *
const std::string noware::smach::cpu::instr::val (void) const
{
	//return oprnd [0];
	return "";
}
* /

noware::smach::cpu::instr const & noware::smach::cpu::instr::operator = (instr const & other)
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

const std::string & noware::smach::cpu::instr::operator = (const std::string & other)
{
	deserialize (other);
	return other;
}

noware::smach::cpu::instr::operator const std::string (void) const
{
	return serialize ();
}

void noware::smach::cpu::instr::dump (void) const
{
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::thread_id[" << thread_id << "]" << std::endl;
	
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::result_ref[" << result_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::result_dev[" << result_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::result_key[" << result_key << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::result_offset_prefetch_ref[" << result_offset_prefetch_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::result_offset_prefetch_dev[" << result_offset_prefetch_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::result_offset_prefetch_key[" << result_offset_prefetch_key << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::result_offset_postfetch_ref[" << result_offset_postfetch_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::result_offset_postfetch_dev[" << result_offset_postfetch_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::result_offset_postfetch_key[" << result_offset_postfetch_key << "]" << std::endl;
	
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::oprn[" << oprn << "]" << std::endl;
	
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::dest_ref[" << dest_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::dest_dev[" << dest_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::dest_key[" << dest_key << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::dest_offset_prefetch_ref[" << dest_offset_prefetch_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::dest_offset_prefetch_dev[" << dest_offset_prefetch_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::dest_offset_prefetch_key[" << dest_offset_prefetch_key << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::dest_offset_postfetch_ref[" << dest_offset_postfetch_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::dest_offset_postfetch_dev[" << dest_offset_postfetch_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::dest_offset_postfetch_key[" << dest_offset_postfetch_key << "]" << std::endl;
	
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::src_ref[" << src_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::src_dev[" << src_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::src_key[" << src_key << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::src_offset_prefetch_ref[" << src_offset_prefetch_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::src_offset_prefetch_dev[" << src_offset_prefetch_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::src_offset_prefetch_key[" << src_offset_prefetch_key << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::src_offset_postfetch_ref[" << src_offset_postfetch_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::src_offset_postfetch_dev[" << src_offset_postfetch_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::instr::dump()::src_offset_postfetch_key[" << src_offset_postfetch_key << "]" << std::endl;
}
*/
noware::smach::cpu::cpu (void)
{
	//_running = false;	// Not strictly needed
	_exen = nullptr;
	_notification = nullptr;
	//assert (node.join (grp_dft));
	//node.join ("noware::mach::thread::1");
}

noware::smach::cpu::~cpu (void)
{
	//_running = false;
	stop ();
	//fin ();
	//_mutex.unlock ();
}

const bool noware::smach::cpu::stop (void)
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
		
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::stop()::_exen->interrupt()ing" << std::endl;
		_exen -> interrupt ();
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::stop()::_exen->interrupt()ed" << std::endl;
		
		{
			//boost::lock_guard <boost::mutex> lock (_mutex);
			//_insn_avail = true;
		}
		//_condition_instr_enqueued.notify_all ();
		//_condition_instr_enqueued.notify_one ();
		//_running = false;
		
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::stop()::_exen->join()ing" << std::endl;
		_exen -> join ();
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::stop()::_exen->join()ed" << std::endl;
		
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::stop()::delete-ing _exen" << std::endl;
		delete _exen;
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::stop()::delete-ed _exen" << std::endl;
		_exen = nullptr;
	}
	
	if (_notification != nullptr)
	{
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::stop()::_notification->interrupt()ing" << std::endl;
		_notification -> interrupt ();
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::stop()::_notification->interrupt()ed" << std::endl;
		
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::stop()::_notification->join()ing" << std::endl;
		_notification -> join ();
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::stop()::_notification->join()ed" << std::endl;
		
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::stop()::delete-ing _notification" << std::endl;
		delete _notification;
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::stop()::delete-ed _notification" << std::endl;
		_notification = nullptr;
	}
	
	if (!dev::stop ());
		return false;
	
	//_running = false;
	
	return true;
}

const bool noware::smach::cpu::running (void) const
{
	if (_exen == nullptr || _notification == nullptr)
		return false;
	
	if (!dev::running ())
		return false;
	
	return true;
}

const bool noware::smach::cpu::start (void)
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
		_notification = new boost::thread (boost::bind (boost::mem_fn (&noware::smach::cpu::notify), this, noten_delay_dft));
		
		if (_notification == nullptr)
			return false;
	}
	
	if (_exen == nullptr)
	{
		_exen = new boost::thread (boost::bind (boost::mem_fn (&noware::smach::cpu::exe), this));
		
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

//#include ".cpu/exe.mov.cxx"
#include ".cpu/exe.x86_64.cxx"

void noware::smach::cpu::notify (const unsigned int & delay_)
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
			std::cerr << "[" << boost::this_thread::get_id () << "] " << "noware::smach::cpu::notify::sleeping for " << delay_ << " seconds" << std::endl;
			boost::this_thread::sleep_for (boost::chrono::seconds (delay_));
			std::cerr << "[" << boost::this_thread::get_id () << "] " << "noware::smach::cpu::notify::slept for " << delay_ << " seconds" << std::endl;
		}
		catch (const boost::thread_interrupted &/* interruption*/)
		{
			std::cerr << "[" << boost::this_thread::get_id () << "] " << "noware::smach::cpu::notify::this_thread.sleep()::caught boost::thread_interrupted" << std::endl;
			break;
		}
		
		//_mutex.unlock ();
		std::cerr << "[" << boost::this_thread::get_id () << "] " << "noware::smach::cpu::notify::_condition_instr_enqueued.notify_all()ing" << std::endl;
		{
			//boost::lock_guard <boost::mutex> lock (_mutex);
			_insn_avail = true;
		}
		_condition_instr_enqueued.notify_all ();
		std::cerr << "[" << boost::this_thread::get_id () << "] " << "noware::smach::cpu::notify::_condition_instr_enqueued.notify_all()ed" << std::endl;
		
		try
		{
			boost::this_thread::interruption_point ();
		}
		catch (...)
		//catch (const boost::thread_interrupted &/* interruption*/)
		{
			std::cerr << "[" << boost::this_thread::get_id () << "] " << "noware::smach::cpu::notify::interruption_point()::caught boost::thread_interrupted" << std::endl;
			break;
		}
	}
	
	//_condition_instr_enqueued.notify_all ();
}

// Store
const bool noware::smach::cpu::exist (const std::string & key) const
{
	return exist (std::string (""), key);
}

const bool noware::smach::cpu::exist (const std::string & group, const std::string & key) const
{
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "existence";
	expression ["group"] = group;
	expression ["key"] = key;
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	return std::string (anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft)) == "1";
}

const bool noware::smach::cpu::clear (void)
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

const bool noware::smach::cpu::clear (const std::string & group)
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "clearance";
	expression ["group"] = group;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft) == "1";
}

const bool noware::smach::cpu::remove (const std::string & group, const std::string & key)
{
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "removal";
	expression ["group"] = group;
	expression ["key"] = key;
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	return std::string (anyval (zmq::msg (expression_serial), noware::mmach::store::grp_dft)) == "1";
}

const bool noware::smach::cpu::remove (const std::string & key)
{
	return remove (std::string (""), key);
}

const std::string/* value*/ noware::smach::cpu::get (const std::string & group, const std::string & key) const
{
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "obtainment";
	expression ["group"] = group;
	expression ["key"] = key;
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return "";
	
	return std::string (anyval (zmq::msg (expression_serial), "noware::mmach::store::nonempty"));
}

const std::string/* value*/ noware::smach::cpu::get (const std::string & key) const
{
	return get (std::string (""), key);
}

const bool/* success*/ noware::smach::cpu::set (const std::string & group, const std::string & key, const std::string & value)
{
	std::cerr << "noware::mmach::cpu::set()::in scope" << std::endl;
	
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "assignment";
	expression ["group"] = group;
	expression ["key"] = key;
	expression ["value"] = value;
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
	{
		std::cerr << "noware::mmach::cpu::set()::serialize()::false" << std::endl;
		
		return false;
	}
	
	std::cerr << "noware::mmach::cpu::set()::return" << std::endl;
	return std::string (anyval (zmq::msg (expression_serial), "noware::mmach::store::nonfull")) == "1";
}

const bool/* success*/ noware::smach::cpu::set (const std::string & key, const std::string & value)
{
	return set (std::string (""), key);
}

// Queue
const cln::nr noware::smach::cpu::size (void) const
{
	//bool result;
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "size::count";
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return 0;
	
	return std::string (anyval (zmq::msg (expression_serial), noware::mmach::queue::grp_dft));
}

const bool noware::smach::cpu::empty (void) const
{
	//return count () <= 0;
	
	////noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "empty";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return anyval (zmq::msg (expression_serial), noware::smach::store::grp_dft) == "1";
}

const bool noware::smach::cpu::full (void) const
{
	return false;
}

const std::string noware::smach::cpu::next_dequeue (void)
{
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	std::string inst;
	
	expression ["subject"] = "next_dequeue";
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return inst;
	
	return std::string (anyval (zmq::msg (expression_serial), "noware::mmach::queue::nonempty"));
}

const std::string noware::mmach::cpu::next (void) const
{
	std::string inst;
	
	if (full ())
		return inst;
	
	bool result;
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "next";
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return inst;
	
	return std::string (anyval (zmq::msg (expression_serial), "noware::mmach::queue::nonempty"));
}

const bool noware::mmach::cpu::dequeue (void)
{
	if (full ())
		return false;
	
	bool result;
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "dequeue";
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	return std::string (anyval (zmq::msg (expression_serial), "noware::mmach::queue::nonempty")) == "1";
}

const bool noware::smach::cpu::enqueue (std::string const & inst)
{
	//return false;
	
	if (full ())
		return false;
	
	//bool result;
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "enqueue";
	expression ["element"] = inst;
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	if (std::string (anyval (zmq::msg (expression_serial), "noware::mmach::queue::nonfull")) == "1")
	//if (std::string (multival (zmq::msg (expression_serial), "noware::mach::queue::nonfull")) == "1")
	{
		{
			//boost::lock_guard <boost::mutex> lock (_mutex);
			_insn_avail = true;
		}
		_condition_instr_enqueued.notify_all ();
		
		return true;
	}
	else
	{
		return false;
	}
}

const bool noware::smach::cpu::cout (const std::string & value)
{
	
	zmq::msg msg;
	std::map <std::string, std::string> xpr;
	std::string xpr_serial;
	
	xpr ["subject"] = "cout";
	xpr ["value"] = value;
	
	if (!noware::serialize <std::map <std::string, std::string>> (xpr_serial, xpr))
		return false;
	
	msg = xpr_serial;
	return multival (msg, noware::smach::cmd::grp_dft) == "1";
	
	/*
	std::cout << value << std::endl;
	return true;
	*/
}

bool const noware::smach::cpu::cin (std::string & result, const char & delimiter)
{
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
}

/*
const bool noware::smach::cpu::enqueue (const std::string & operand1, const opr & op, const std::string & operand2, const std::string & thread_id)
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
const bool noware::smach::cpu::enqueue (const cpu::dev & device, const opr & op, const std::map <std::string, std::string> & arg, const std::string & thread_id)
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
const bool noware::smach::cpu::respond (const zyre_event_t * event, const std::string & event_type, const std::string & shouted_group, const zmq::msg & msg_request, zmq::msg & msg_response)
{
	std::cerr << "noware::smach::cpu::respond()::called" << std::endl;
	
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
	
	std::cerr << "noware::smach::cpu::respond()::if::message[subject]==[" << message ["subject"] << ']' << std::endl;
	
	if (message ["type"] == "response")
	{
		std::cerr << "noware::smach::cpu::respond()::if::message[type]==" << message ["type"] << "::in scope" << std::endl;
		
		//if (message ["subject"] == "existence")
		//{
			std::cerr << "noware::smach::cpu::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			//std::cerr << "noware::smach::cpu::receive()::else::msg[subject]==" << msg ["subject"] << "::sleeping" << std::endl;
			//zclock_sleep (1500);
			
			// Redirect the message to the function which asked for it.
			////unicast_local (zmsg_popstr (zmq_msg));
			//result = unicast_local (msg_rx);
			result = unicast_local (msg, "");
			std::cerr << "noware::smach::cpu::respond()::unicast_local(message)==" << (result ? "success" : "failure") << std::endl;
		//}
	}
	
	return result;
}
*/

const bool/* success*/ noware::smach::cpu::respond (zmq::msg &/* response*/, const zmq::msg & rxd, const zyre_event_t */* (zyre) event*/, const std::string & event_type, const std::string &/* src*/, const net::cast &/* src_cast*/)
{
	std::cerr << "noware::smach::cpu::respond()::in scope" << std::endl;
	std::cerr << "noware::smach::cpu::respond()::event_type==[" << event_type << "]" << std::endl;
	
	std::cerr << "noware::smach::cpu::respond()::rxd==[" << std::string (rxd) << "]" << std::endl;
	//std::cerr << "noware::smach::cpu::respond()::rxd.data[1]==[" << std::string (rxd.data [1]) << "]" << std::endl;
	if (rxd == "enqueued(instr)")
	{
		// There are instructions to execute.
		//std::cerr << "noware::smach::cpu::respond()::_mutex.unlock()" << std::endl;
		//_mutex.unlock ();
		std::cerr << "noware::smach::cpu::respond()::_condition_instr_enqueued.notify_all()" << std::endl;
		{
			//boost::lock_guard <boost::mutex> lock (_mutex);
			_insn_avail = true;
		}
		_condition_instr_enqueued.notify_all ();
	}
	
	return true;
}

const bool/* success*/ noware::smach::cpu::search (zmq::msg & msg_result, const zmq::msg & msg_resp, const cln::nr &/* total, expected resonses count*/, const cln::nr &/* current count of peers who responded (so far)*/, const std::string &/* src*/, const net::cast &/* src_cast*/)
{
	std::cerr << "noware::smach::cpu::search()::called" << std::endl;
	
	//noware::tree <std::string, std::string> resp;
	std::map <std::string, std::string> resp;
	//noware::tree <std::string, std::string> result;
	//std::string result;
	noware::var result_tmp;
	//bool result;
	
	//if (!resp.deserialize (msg_resp))
	if (!noware::deserialize <std::map <std::string, std::string>> (resp, std::string (msg_resp)))
	{
		std::cerr << "noware::smach::cpu::search()::deserialize::failure" << std::endl;
		return false;
	}
	std::cerr << "noware::smach::cpu::search()::deserialize::success" << std::endl;
	
	
	//result ["subject"] = resp ["subject"];
	
	// Store
	if (resp ["subject"] == "existence")
	{
		msg_result = resp ["value"];
		
		return msg_result == "1";
	}
	else if (resp ["subject"] == "obtainment")
	{
		if (resp ["value.exist"] == "0")
		{
			return false;
		}
		
		msg_result = resp ["value"];
		
		return true;
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
	else if (resp ["subject"] == "clearance")
	{
		msg_result = resp ["value"];
		
		//return msg_result == "1";
		return false;
	}
	// Queue
	else if (resp ["subject"] == "size::count")
	{
		std::cerr << "noware::smach::cpu::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		result_tmp = msg_result;
		//if (result_tmp.kind () != noware::var::type::nr)
		//	result_tmp = 0;
		
		//result += data.size ();
		//result ["value"] += resp ["value"];
		result_tmp += noware::var (resp ["value"]);
		msg_result = result_tmp;
		
		std::cerr << "noware::smach::cpu::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cerr << "noware::smach::cpu::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return false;
	}
	else if (resp ["subject"] == "next_dequeue")
	{
		std::cerr << "noware::smach::cpu::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		//std::cerr << "noware::smach::cpu::search()::queue.front ()==[" << queue.front () << ']' << std::endl;
		
		//result_tmp = queue.front ();
		//std::cerr << "noware::smach::cpu::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		
		
		if (resp ["success"] == "0")
			return false;
		
		//msg_result = result_tmp;
		//msg_result = queue.front ();
		msg_result = resp ["value"];
		std::cerr << "noware::smach::cpu::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return true;
		//return false;
		
		
		//std::cerr << "noware::smach::cpu::search()::resp[success]==[" << resp ["success"] << ']' << std::endl;
		//return resp ["success"] == "1";
	}
	else if (resp ["subject"] == "next")
	{
		std::cerr << "noware::smach::cpu::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		//std::cerr << "noware::smach::cpu::search()::queue.front ()==[" << queue.front () << ']' << std::endl;
		
		//result_tmp = queue.front ();
		//std::cerr << "noware::smach::cpu::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		
		
		if (resp ["success"] == "0")
			return false;
		
		//msg_result = result_tmp;
		//msg_result = queue.front ();
		msg_result = resp ["value"];
		std::cerr << "noware::smach::cpu::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return true;
		//return false;
		
		
		//std::cerr << "noware::smach::cpu::search()::resp[success]==[" << resp ["success"] << ']' << std::endl;
		//return resp ["success"] == "1";
	}
	else if (resp ["subject"] == "dequeue")
	{
		std::cerr << "noware::smach::cpu::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		/*
		queue.pop ();
		
		if (empty_local ())
		{
			assert (node.leave ("noware::mach::queue::nonempty"));
		}
		
		assert (node.join ("noware::mach::queue::nonfull"));
		
		
		msg_result = "1";
		
		std::cerr << "noware::mach::queue::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cerr << "noware::mach::queue::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return true;
		*/
		
		msg_result = resp ["value"];
		
		return msg_result == "1";
	}
	else if (resp ["subject"] == "enqueue")
	{
		std::cerr << "noware::smach::cpu::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		/*
		queue.push (resp ["element"]);
		
		if (full_local ())
		{
			assert (node.leave ("noware::mach::queue::nonfull"));
		}
		
		assert (node.join ("noware::mach::queue::nonempty"));
		
		
		msg_result = "1";
		
		std::cerr << "noware::mach::queue::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cerr << "noware::mach::queue::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return true;
		*/
		
		msg_result = resp ["value"];
		
		return msg_result == "1";
	}
	else if (resp ["subject"] == "cout")
	{
		//std::cout << request ["value"];
		msg_result = resp ["value"];
		//return msg_result == "1";
		//return true;
		return false;
	}
	else if (resp ["subject"] == "cin")
	{
		//std::cout << request ["value"];
		msg_result = resp ["value"];
		//return msg_result == "1";
		return true;
	}
	
	return false;
}

#include ".cpu/val.x86_64.cxx"
//#include ".cpu/exe-x86_64.cxx"
