#pragma once

//#include "processor.hdr.cxx"
#include ".cpu/.cxx"

const unsigned int noware::mach::cpu::notification_delay_dft = 5;
const std::string noware::mach::cpu::grp_dft = "noware::mach::cpu";

noware::mach::cpu::instr::instr (void)
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

noware::mach::cpu::instr::instr (std::string const & other)
{
	//oprn = opr::none;
	//deserialize (other);
	*this = other;
}

noware::mach::cpu::instr::~instr (void)
{
}

template <typename archive>
void noware::mach::cpu::instr::serialize (archive & arch, unsigned int const &/* version*/)
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

bool const noware::mach::cpu::instr::deserialize (std::string const & serial)
{
	return noware::deserialize <noware::mach::cpu::instr> (*this, serial);
}

std::string const noware::mach::cpu::instr::serialize (void) const
{
	std::string serial;
	
	if (noware::serialize <noware::mach::cpu::instr> (serial, *this))
		return serial;
	else
		return "";
}

/*
const std::string noware::mach::cpu::instr::val (void) const
{
	//return oprnd [0];
	return "";
}
*/

noware::mach::cpu::instr const & noware::mach::cpu::instr::operator = (instr const & other)
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

const std::string & noware::mach::cpu::instr::operator = (const std::string & other)
{
	deserialize (other);
	return other;
}

noware::mach::cpu::instr::operator const std::string (void) const
{
	return serialize ();
}

void noware::mach::cpu::instr::dump (void) const
{
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::thread_id[" << thread_id << "]" << std::endl;
	
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::result_ref[" << result_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::result_dev[" << result_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::result_key[" << result_key << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::result_offset_prefetch_ref[" << result_offset_prefetch_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::result_offset_prefetch_dev[" << result_offset_prefetch_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::result_offset_prefetch_key[" << result_offset_prefetch_key << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::result_offset_postfetch_ref[" << result_offset_postfetch_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::result_offset_postfetch_dev[" << result_offset_postfetch_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::result_offset_postfetch_key[" << result_offset_postfetch_key << "]" << std::endl;
	
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::oprn[" << oprn << "]" << std::endl;
	
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::dest_ref[" << dest_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::dest_dev[" << dest_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::dest_key[" << dest_key << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::dest_offset_prefetch_ref[" << dest_offset_prefetch_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::dest_offset_prefetch_dev[" << dest_offset_prefetch_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::dest_offset_prefetch_key[" << dest_offset_prefetch_key << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::dest_offset_postfetch_ref[" << dest_offset_postfetch_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::dest_offset_postfetch_dev[" << dest_offset_postfetch_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::dest_offset_postfetch_key[" << dest_offset_postfetch_key << "]" << std::endl;
	
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::src_ref[" << src_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::src_dev[" << src_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::src_key[" << src_key << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::src_offset_prefetch_ref[" << src_offset_prefetch_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::src_offset_prefetch_dev[" << src_offset_prefetch_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::src_offset_prefetch_key[" << src_offset_prefetch_key << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::src_offset_postfetch_ref[" << src_offset_postfetch_ref << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::src_offset_postfetch_dev[" << src_offset_postfetch_dev << "]" << std::endl;
	std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::instr::dump()::src_offset_postfetch_key[" << src_offset_postfetch_key << "]" << std::endl;
}

noware::mach::cpu::cpu (void)
{
	//_running = false;	// Not strictly needed
	_exen = nullptr;
	_notification = nullptr;
	//assert (node.join (grp_dft));
	//node.join ("noware::mach::thread::1");
}

noware::mach::cpu::~cpu (void)
{
	//_running = false;
	stop ();
	//fin ();
	//_mutex.unlock ();
}

const bool noware::mach::cpu::stop (void)
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
		
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::stop()::_exen->interrupt()ing" << std::endl;
		_exen -> interrupt ();
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::stop()::_exen->interrupt()ed" << std::endl;
		
		{
			//boost::lock_guard <boost::mutex> lock (_mutex);
			//_insn_avail = true;
		}
		//_condition_instr_enqueued.notify_all ();
		//_condition_instr_enqueued.notify_one ();
		//_running = false;
		
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::stop()::_exen->join()ing" << std::endl;
		_exen -> join ();
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::stop()::_exen->join()ed" << std::endl;
		
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::stop()::delete-ing _exen" << std::endl;
		delete _exen;
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::stop()::delete-ed _exen" << std::endl;
		_exen = nullptr;
	}
	
	if (_notification != nullptr)
	{
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::stop()::_notification->interrupt()ing" << std::endl;
		_notification -> interrupt ();
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::stop()::_notification->interrupt()ed" << std::endl;
		
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::stop()::_notification->join()ing" << std::endl;
		_notification -> join ();
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::stop()::_notification->join()ed" << std::endl;
		
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::stop()::delete-ing _notification" << std::endl;
		delete _notification;
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::stop()::delete-ed _notification" << std::endl;
		_notification = nullptr;
	}
	
	if (!dev::stop ());
		return false;
	
	//_running = false;
	
	return true;
}

const bool noware::mach::cpu::running (void) const
{
	if (_exen == nullptr || _notification == nullptr)
		return false;
	
	if (!dev::running ())
		return false;
	
	return true;
}

const bool noware::mach::cpu::start (void)
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
		_notification = new boost::thread (boost::bind (boost::mem_fn (&noware::mach::cpu::notify), this, notification_delay_dft));
		
		if (_notification == nullptr)
			return false;
	}
	
	if (_exen == nullptr)
	{
		_exen = new boost::thread (boost::bind (boost::mem_fn (&noware::mach::cpu::exe), this));
		
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
	
	if (!node.join (grp_dft))
		return false;
	
	//_running = true;
	//return _exen != nullptr;
	//assert (_exen != nullptr);
	return true;
}

void noware::mach::cpu::exe (void)
{
	std::cerr << "noware::mach::cpu::exe()::in scope" << std::endl;
	
	instr inst;
	instr inst_next;
	
	noware::nr index_max;
	noware::nr index;
	
	//noware::var src;
	//noware::var dest;
	
	//noware::var src_offset;
	//noware::var dest_offset;
	
	//std::string separator;
	std::string input;
	
	std::string thread_id;
	
	bool result_offset_prefetch_visited;
	bool dest_offset_prefetch_visited;
	bool src_offset_prefetch_visited;
	
	bool result;
	
	boost::unique_lock <boost::mutex> lock (_mutex);
	
	/*
	//zmq::msg msg_thread;
	std::map <std::string, std::string> map_thread;
	std::string map_thread_serial;
	zmq::msg msg;
	
	map_thread ["subject"] = "notification";
	map_thread ["success"] = "1";
	
	noware::serialize <std::map <std::string, std::string>> (map_thread_serial, map_thread);
	
	msg = map_thread_serial;
	
	msg.prepend (zmq::msg::frame ("dummy_request_token"));
	*/
	
	result = false;
	
	result_offset_prefetch_visited = false;
	dest_offset_prefetch_visited = false;
	src_offset_prefetch_visited = false;
	
	while (true)
	//while (_running)
	//while (!boost::this_thread::interruption_requested ())
	{
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe()::while(true)::in scope" << std::endl;
		//std::cerr << "noware::mach::cpu::exe()::while(_running)::in scope" << std::endl;
		
		//std::cerr << "noware::mach::cpu::exe()::empty()==[" << empty () << "]==noware::mach::cpu::exe()::empty()" << std::endl;
		while (!empty ())
		{
			std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe()::while(!empty())::in scope" << std::endl;
			
			// fetch next (and dequeue)
			std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::next_dequeue()" << std::endl;
			inst = next_dequeue ();
			
			// Dump member variables
			inst.dump ();
			
			if (inst.thread_id != "" && inst.oprn != "")
			{
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::next_dequeue()::valid instruction" << std::endl;
				
				// decode
				thread_id = std::string ("thread ") + inst.thread_id;
				
				// execute
				//inst.val ();
				/*
				if (inst.oprnd_src_ref)
				{
					inst.oprnd [0] = get (inst.oprnd [0]);
				}
				*/
				//set (inst.oprnd [2]/* group*/, inst.oprnd [1]/* key*/, inst.oprnd [0]/* value*/);
				////set (grp, inst.oprnd [1]/* key*/, inst.oprnd [0]/* value*/);
				//if ()
				//set (inst.oprnd [2]/* group*/, inst.oprnd [1]/* key*/, inst.oprnd [0]/* value*/);
				
				//std::cerr << "noware::mach::cpu::exe::set(\"thread " << inst.thread_id << "\"," << inst.oprnd [1] << "," << inst.oprnd [0] << ")" << std::endl;
				
				// result offset (postfetch) (obtainment)
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.result_offset_postfetch_key(pre)==[" << inst.result_offset_postfetch_key << "]" << std::endl;
				while (inst.result_offset_postfetch_ref.operator const unsigned int () > 0 && inst.result_offset_postfetch_key != "null")
				{
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.result_offset_postfetch_ref==[true]" << std::endl;
					
					if (inst.result_offset_postfetch_dev == "store")
						inst.result_offset_postfetch_key = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, inst.result_offset_postfetch_key);
					else if (inst.result_offset_postfetch_dev == "cmd")
						///*inst.src_offset_key = */get (inst.src_offset_key, /*std::string ("thread ") + inst.*/thread_id/* group*/, inst.src_offset_key);
						
						/*inst.dest_offset_key = */
						if (!cin (inst.result_offset_postfetch_key))
							break;
					
					--inst.result_offset_postfetch_ref;
				}
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.result_offset_postfetch_key(post)==[" << inst.result_offset_postfetch_key << "]" << std::endl;
				
				// result offset (prefetch) (obtainment)
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.result_offset_prefetch_key(pre)==[" << inst.result_offset_prefetch_key << "]" << std::endl;
				while (inst.result_offset_prefetch_ref.operator const unsigned int () > 0 && inst.result_offset_prefetch_key != "null")
				{
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.result_offset_prefetch_ref==true" << std::endl;
					
					if (inst.result_offset_prefetch_dev == "store")
						inst.result_offset_prefetch_key = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, inst.result_offset_prefetch_key);
					else if (inst.result_offset_prefetch_dev == "cmd")
						///*inst.result_offset_key = */get (inst.result_offset_key, /*std::string ("thread ") + inst.*/thread_id/* group*/, inst.result_offset_key);
						
						/*inst.result_offset_key = */
						if (!cin (inst.result_offset_prefetch_key))
							break;
					
					--inst.result_offset_prefetch_ref;
				}
				/*
				else
				{
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.result_offset_prefetch_ref==false" << std::endl;
				}
				*/
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.result_offset_prefetch_key(post)==[" << inst.result_offset_prefetch_key << "]" << std::endl;
				
				// result
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.result_key(pre)==[" << inst.result_key << "]" << std::endl;
				while (inst.result_ref.operator const unsigned int () > 0 && inst.result_key != "null")
				{
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.result_ref==true" << std::endl;
					
					// result offset (prefetch) (application)
					if (!result_offset_prefetch_visited && inst.result_offset_prefetch_key != "null")
						inst.result_key = (noware::var (inst.result_key) + noware::var (inst.result_offset_prefetch_key)).operator const std::string ();
					
					if (inst.result_dev == "store")
						inst.result_key = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, inst.result_key);
					else if (inst.result_dev == "cmd")
						///*inst.result_key = */get (inst.result_key, /*std::string ("thread ") + inst.*/thread_id/* group*/, inst.result_key);
						
						/*inst.result_key = */
						if (!cin (inst.result_key))
							break;
					
					result_offset_prefetch_visited = true;
					--inst.result_ref;
				}
				/*
				else
				{
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.result_ref==false" << std::endl;
				}
				*/
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.result_key(post)==[" << inst.result_key << "]" << std::endl;
				
				// destination offset (postfetch) (obtainment)
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.dest_offset_postfetch_key(pre)==[" << inst.dest_offset_postfetch_key << "]" << std::endl;
				while (inst.dest_offset_postfetch_ref.operator const unsigned int () > 0 && inst.dest_offset_postfetch_key != "null")
				{
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.dest_offset_postfetch_ref==[true]" << std::endl;
					
					if (inst.dest_offset_postfetch_dev == "store")
						inst.dest_offset_postfetch_key = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, inst.dest_offset_postfetch_key);
					else if (inst.dest_offset_postfetch_dev == "cmd")
						///*inst.src_offset_key = */get (inst.src_offset_key, /*std::string ("thread ") + inst.*/thread_id/* group*/, inst.src_offset_key);
						
						/*inst.dest_offset_key = */
						if (!cin (inst.dest_offset_postfetch_key))
							break;
					
					--inst.dest_offset_postfetch_ref;
				}
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.dest_offset_postfetch_key(post)==[" << inst.dest_offset_postfetch_key << "]" << std::endl;
				
				// destination offset (prefetch) (obtainment)
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.dest_offset_prefetch_key(pre)==[" << inst.dest_offset_prefetch_key << "]" << std::endl;
				while (inst.dest_offset_prefetch_ref.operator const unsigned int () > 0 && inst.dest_offset_prefetch_key != "null")
				{
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.dest_offset_prefetch_ref==true" << std::endl;
					
					if (inst.dest_offset_prefetch_dev == "store")
						inst.dest_offset_prefetch_key = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, inst.dest_offset_prefetch_key);
					else if (inst.dest_offset_prefetch_dev == "cmd")
						///*inst.dest_offset_key = */get (inst.dest_offset_key, /*std::string ("thread ") + inst.*/thread_id/* group*/, inst.dest_offset_key);
						
						/*inst.dest_offset_key = */
						if (!cin (inst.dest_offset_prefetch_key))
							break;
					
					--inst.dest_offset_prefetch_ref;
				}
				/*
				else
				{
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.dest_offset_prefetch_ref==false" << std::endl;
				}
				*/
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.dest_offset_prefetch_key(post)==[" << inst.dest_offset_prefetch_key << "]" << std::endl;
				
				// destination
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.dest_key(pre)==[" << inst.dest_key << "]" << std::endl;
				while (inst.dest_ref.operator const unsigned int () > 0 && inst.dest_key != "null")
				{
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.dest_ref==[true]" << std::endl;
					
					// destination offset (prefetch) (application)
					if (!dest_offset_prefetch_visited && inst.dest_offset_prefetch_key != "null")
						inst.dest_key = (noware::var (inst.dest_key) + noware::var (inst.dest_offset_prefetch_key)).operator const std::string ();
					
					if (inst.dest_dev == "store")
						inst.dest_key = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, inst.dest_key);
					else if (inst.dest_dev == "cmd")
						///*inst.dest_key = */get (inst.dest_key, /*std::string ("thread ") + inst.*/thread_id/* group*/, inst.dest_key);
						
						/*inst.dest_key = */
						if (!cin (inst.dest_key))
							break;
					
					dest_offset_prefetch_visited = true;
					--inst.dest_ref;
				}
				/*
				else
				{
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.dest_ref==[false]" << std::endl;
				}
				*/
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.dest_key(post)==[" << inst.dest_key << "]" << std::endl;
				
				// source offset (postfetch) (obtainment)
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.src_offset_postfetch_key(pre)==[" << inst.src_offset_postfetch_key << "]" << std::endl;
				while (inst.src_offset_postfetch_ref.operator const unsigned int () > 0 && inst.src_offset_postfetch_key != "null")
				{
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.src_offset_postfetch_ref==[true]" << std::endl;
					
					if (inst.src_offset_postfetch_dev == "store")
						inst.src_offset_postfetch_key = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, inst.src_offset_postfetch_key);
					else if (inst.src_offset_postfetch_dev == "cmd")
						///*inst.src_offset_key = */get (inst.src_offset_key, /*std::string ("thread ") + inst.*/thread_id/* group*/, inst.src_offset_key);
						
						/*inst.src_offset_key = */
						if (!cin (inst.src_offset_postfetch_key))
							break;
					
					--inst.src_offset_postfetch_ref;
				}
				/*
				else
				{
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.src_offset_prefetch_ref==[false]" << std::endl;
				}
				*/
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.src_offset_postfetch_key(post)==[" << inst.src_offset_postfetch_key << "]" << std::endl;
				
				// source offset (prefetch) (obtainment)
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.src_offset_prefetch_key(pre)==[" << inst.src_offset_prefetch_key << "]" << std::endl;
				while (inst.src_offset_prefetch_ref.operator const unsigned int () > 0 && inst.src_offset_prefetch_key != "null")
				{
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.src_offset_prefetch_ref==[true]" << std::endl;
					
					if (inst.src_offset_prefetch_dev == "store")
						inst.src_offset_prefetch_key = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, inst.src_offset_prefetch_key);
					else if (inst.src_offset_prefetch_dev == "cmd")
						///*inst.src_offset_key = */get (inst.src_offset_key, /*std::string ("thread ") + inst.*/thread_id/* group*/, inst.src_offset_key);
						
						/*inst.src_offset_key = */
						if (!cin (inst.src_offset_prefetch_key))
							break;
					
					--inst.src_offset_prefetch_ref;
				}
				/*
				else
				{
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.src_offset_prefetch_ref==[false]" << std::endl;
				}
				*/
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.src_offset_prefetch_key(post)==[" << inst.src_offset_prefetch_key << "]" << std::endl;
				
				// source
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.src_key(pre)==[" << inst.src_key << "]" << std::endl;
				while (inst.src_ref.operator const unsigned int () > 0 && inst.src_key != "null")
				{
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.src_ref==[true]" << std::endl;
					
					// source offset (prefetch) (application)
					if (!src_offset_prefetch_visited && inst.src_offset_prefetch_key != "null")
						inst.src_key = (noware::var (inst.src_key) + noware::var (inst.src_offset_prefetch_key)).operator const std::string ();
					
					if (inst.src_dev == "store")
						inst.src_key = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, inst.src_key);
					else if (inst.src_dev == "cmd")
						///*inst.src_key = */get (inst.src_key, /*std::string ("thread ") + inst.*/thread_id/* group*/, inst.src_key);
						
						/*inst.src_key = */
						if (!cin (inst.src_key))
							break;
					
					src_offset_prefetch_visited = true;
					--inst.src_ref;
				}
				/*
				else
				{
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.src_ref==[false]" << std::endl;
				}
				*/
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr.src_key(post)==[" << inst.src_key << "]" << std::endl;
				
				
				
				// result offset (postfetch) application
				if (inst.result_offset_postfetch_key != "null")
				{
					inst.result_key = (noware::var (inst.result_key) + noware::var (inst.result_offset_postfetch_key)).operator const std::string ();
				}
				
				// destintion offset (postfetch) application
				if (inst.dest_offset_postfetch_key != "null")
				{
					inst.dest_key = (noware::var (inst.dest_key) + noware::var (inst.dest_offset_postfetch_key)).operator const std::string ();
				}
				
				// source offset (postfetch) application
				if (inst.src_offset_postfetch_key != "null")
				{
					//inst.src_key = noware::var (inst.src_key) + inst.src_offset_key;
					inst.src_key = (noware::var (inst.src_key) + noware::var (inst.src_offset_postfetch_key)).operator const std::string ();
				}
				//std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr::src_offset_key[" << inst.dest_dev << "]" << std::endl;
				
				
				
				if (inst.oprn == "set")
				{
					/*
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr::set::dest_dev[" << inst.dest_dev << "]" << std::endl;
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr::set::dest_offset_key[" << inst.dest_offset_key << "]" << std::endl;
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr::set::src_key[" << inst.src_key << "]" << std::endl;
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr::set::src_offset_key[" << inst.src_offset_key << "]" << std::endl;
					*/
					//std::cerr << inst.arg ["value"];
					
					if (inst.dest_dev == "store")
					{
						//assert (set (thread_id/* group*/, dest/* key*/, src/* value*/));
						result = set (thread_id/* group*/, inst.dest_key/* key*/, inst.src_key/* value*/);
					}
					else if (inst.dest_dev == "cmd")
						result = cout (inst.src_key);
				}
				else if (inst.oprn == "delete")
				{
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr::delete" << std::endl;
					//std::cerr << inst.arg ["value"];
					
					result = remove (thread_id/* group*/, inst.dest_key);
				}
				else if (inst.oprn == "exist")
				{
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::instr::exist" << std::endl;
					//std::cerr << inst.arg ["value"];
					
					result = exist (thread_id/* group*/, inst.src_key);
				}
				
				
				
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::result[" << result << "]" << std::endl;
				
				if (inst.result_dev != "null")
				// The result was requested to be saved to a device
				{
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::saving result [" << result << "]" << std::endl;
					/*
					if (inst.result_offset_dev != "null")
					{
						
					}
					*/
					if (inst.result_dev == "store")
					{
						std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::into var [" << inst.result_key << "]" << std::endl;
						
						assert (set (thread_id, inst.result_key, result ? "1" : "0"));
					}
					else if (inst.result_dev == "cmd")
						assert (cout (result ? "1" : "0"));
				}
				
				//assert (set (inst.thread_id/* group*/, inst.oprnd [1]/* key*/, inst.oprnd [0]/* value*/));
				
				// remove the instruction from the queue
				// it is now processed
				// it is no longer needed
				//dequeue ();
				
				//// synchronize with our cpu group
				//node.multicast (msg_cpu_serial, grp);
				
				//// synchronize all the members of the thread group
				// tell the caller that we have successfully executed the instruction
				//node.unicast (, inst.thread_id);
				//node.multicast (msg_thread_serial, inst.oprnd [2]);
			//	map_thread ["subject"] = "notification";
			//	map_thread ["success"] = "1";
				//map_thread ["instr.ndx"] = inst.ndx;
				
			//	noware::serialize <std::map <std::string, std::string>> (map_thread_serial, map_thread);
			
			//	std::cerr << "noware::mach::cpu::node.multicast(" << map_thread_serial << "," << inst.thread_id << ")" << std::endl;
			//	std::cerr << "noware::mach::cpu::node.unicast(" << map_thread_serial << "," << inst.thread_id << ")" << std::endl;
				//std::cerr << "noware::mach::cpu::multicast(" << map_thread_serial << "," << inst.thread_id << ")" << std::endl;
				
			//	msg = map_thread_serial;
			//	msg.prepend (zmq::msg::frame ("dummy_request_token"));
				//msg.prepend (zmq::msg::frame (noware::random::string (noware::mach::dev::token_size_dft)));
				
			//	node.multicast (msg, inst.thread_id);
				
				
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::stop/continue?" << std::endl;
				
				index_max = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, "index.max"/* key*/);
				index = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, "index"/* key*/);
				++index;
				
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe()::index_max==[" << index_max << "]" << std::endl;
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe()::index==[" << index << "]" << std::endl;
				if (index.operator const unsigned int () > index_max.operator const unsigned int ())
				{
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::stop(clear)::thread_id[" << thread_id << "]" << std::endl;
					//assert (set (/*std::string ("thread ") + inst.*/thread_id/* group*/, "running"/* key*/, "0"/* value*/));
					//assert (clear (thread_id));
				}
				else
				{
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::continue" << std::endl;
					
					assert (set (/*std::string ("thread ") + inst.*/thread_id/* group*/, "index"/* key*/, index.operator const std::string ()/* value*/));
					inst_next = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, std::string ("instr ") + index.operator const std::string ()/* key*/);
					
					//if (get (/*std::string ("thread ") + inst.*/thread_id/* group*/, "running"/* key*/) == "1")
					//	assert (enqueue (inst_next));
					//else
					//	assert (clear (/*std::string ("thread ") + inst.*/thread_id/* group*/));
					assert (enqueue (inst_next));
					
					//node.unicast (msg, inst.thread_id);
					//multival (msg, inst.thread_id);
					//map_thread.clear ();
					
					//boost::this_thread::sleep_for (boost::chrono::milliseconds (200));
				}
			}
			else
			{
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::next_dequeue()::invalid instruction" << std::endl;
			}
		}
		
		//std::cerr << "noware::mach::cpu::exe()::while(!empty())::in scope" << std::endl;
		
		//std::cerr << "noware::mach::cpu::exe()::empty()" << std::endl;
		
		//std::cerr << "[" << boost::this_thread::get_id () << "]noware::mach::cpu::sleeping..." << std::endl;
		//boost::this_thread::sleep_for (boost::chrono::seconds (3));
		//std::cerr << "[" << boost::this_thread::get_id () << "]noware::mach::cpu::exe::_mutex.lock()" << std::endl;
		//_mutex.lock ();
		
		{
			//boost::lock_guard <boost::mutex> lock (_mutex);
			_insn_avail = false;
		}
		
		try
		{
			std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::condition.wait(lock)ing" << std::endl;
			//boost::this_thread::interruption_point ();
			while (!_insn_avail)
			{
				_condition_instr_enqueued.wait (lock);
			}
			//boost::this_thread::sleep_for (boost::chrono::seconds (notification_delay_dft));
			//_mutex.lock ();
			std::cerr << "[" << boost::this_thread::get_id () << "] noware::mach::cpu::exe::condition.wait(lock)ed" << std::endl;
			//std::cerr << "[" << boost::this_thread::get_id () << "]noware::mach::cpu::_mutex.lock()ed" << std::endl;
		}
		catch (const boost::thread_interrupted &/* interruption*/)
		{
			std::cerr << "[" << boost::this_thread::get_id () << "] " << "noware::mach::cpu::exe::condition.wait()::caught boost::thread_interrupted" << std::endl;
			break;
		}
		
		
		try
		{
			boost::this_thread::interruption_point ();
		}
		catch (...)
		//catch (const boost::thread_interrupted &/* interruption*/)
		{
			std::cerr << "[" << boost::this_thread::get_id () << "] " << "noware::mach::cpu::exe::interruption_point()::caught boost::thread_interrupted" << std::endl;
			break;
		}
	}
	
	//_condition_instr_enqueued.notify_all ();
}

void noware::mach::cpu::notify (const unsigned int & delay_)
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
			std::cerr << "[" << boost::this_thread::get_id () << "] " << "noware::mach::cpu::notify::sleeping for " << delay_ << " seconds" << std::endl;
			boost::this_thread::sleep_for (boost::chrono::seconds (delay_));
			std::cerr << "[" << boost::this_thread::get_id () << "] " << "noware::mach::cpu::notify::slept for " << delay_ << " seconds" << std::endl;
		}
		catch (const boost::thread_interrupted &/* interruption*/)
		{
			std::cerr << "[" << boost::this_thread::get_id () << "] " << "noware::mach::cpu::notify::this_thread.sleep()::caught boost::thread_interrupted" << std::endl;
			break;
		}
		
		//_mutex.unlock ();
		std::cerr << "[" << boost::this_thread::get_id () << "] " << "noware::mach::cpu::notify::_condition_instr_enqueued.notify_all()ing" << std::endl;
		{
			//boost::lock_guard <boost::mutex> lock (_mutex);
			_insn_avail = true;
		}
		_condition_instr_enqueued.notify_all ();
		std::cerr << "[" << boost::this_thread::get_id () << "] " << "noware::mach::cpu::notify::_condition_instr_enqueued.notify_all()ed" << std::endl;
		
		try
		{
			boost::this_thread::interruption_point ();
		}
		catch (...)
		//catch (const boost::thread_interrupted &/* interruption*/)
		{
			std::cerr << "[" << boost::this_thread::get_id () << "] " << "noware::mach::cpu::notify::interruption_point()::caught boost::thread_interrupted" << std::endl;
			break;
		}
	}
	
	//_condition_instr_enqueued.notify_all ();
}

// Store
const bool noware::mach::cpu::exist (const std::string & key) const
{
	return exist (std::string (""), key);
}

const bool noware::mach::cpu::exist (const std::string & group, const std::string & key) const
{
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "existence";
	expression ["group"] = group;
	expression ["key"] = key;
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	return std::string (anyval (zmq::msg (expression_serial), noware::mach::store::grp_dft)) == "1";
}

const bool noware::mach::cpu::clear (void)
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "clearance";
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return multival (zmq::msg (expression_serial), noware::mach::store::grp_dft) == "1";
}

const bool noware::mach::cpu::clear (const std::string & group)
{
	//noware::tree <std::string, std::string> expression;
	std::map <std::string, std::string> expression;
	
	expression ["subject"] = "clearance";
	expression ["group"] = group;
	
	std::string expression_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	//return multival (zmq::msg (expression.serialize ()), noware::mach::store::grp_dft);
	return multival (zmq::msg (expression_serial), noware::mach::store::grp_dft) == "1";
}

const bool noware::mach::cpu::remove (const std::string & group, const std::string & key)
{
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "removal";
	expression ["group"] = group;
	expression ["key"] = key;
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	return std::string (anyval (zmq::msg (expression_serial), noware::mach::store::grp_dft)) == "1";
}

const bool noware::mach::cpu::remove (const std::string & key)
{
	return remove (std::string (""), key);
}

const std::string/* value*/ noware::mach::cpu::get (const std::string & group, const std::string & key) const
{
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "obtainment";
	expression ["group"] = group;
	expression ["key"] = key;
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return "";
	
	return std::string (anyval (zmq::msg (expression_serial), "noware::mach::store::nonempty"));
}

const std::string/* value*/ noware::mach::cpu::get (const std::string & key) const
{
	return get (std::string (""), key);
}

const bool/* success*/ noware::mach::cpu::set (const std::string & group, const std::string & key, const std::string & value)
{
	std::cerr << "noware::mach::cpu::set()::in scope" << std::endl;
	
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "assignment";
	expression ["group"] = group;
	expression ["key"] = key;
	expression ["value"] = value;
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
	{
		std::cerr << "noware::mach::cpu::set()::serialize()::false" << std::endl;
		
		return false;
	}
	
	std::cerr << "noware::mach::cpu::set()::return" << std::endl;
	return std::string (anyval (zmq::msg (expression_serial), "noware::mach::store::nonfull")) == "1";
}

const bool/* success*/ noware::mach::cpu::set (const std::string & key, const std::string & value)
{
	return set (std::string (""), key);
}

// Queue
const noware::nr noware::mach::cpu::count (void) const
{
	//bool result;
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "size::count";
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return 0;
	
	return std::string (multival (zmq::msg (expression_serial), noware::mach::queue::grp_dft));
}

const bool noware::mach::cpu::empty (void) const
{
	return count () <= 0;
}

const bool noware::mach::cpu::full (void) const
{
	return false;
}

const noware::mach::cpu::instr noware::mach::cpu::next_dequeue (void)
{
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	instr inst;
	
	expression ["subject"] = "next_dequeue";
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return inst;
	
	return instr (std::string (anyval (zmq::msg (expression_serial), "noware::mach::queue::nonempty")));
}

const noware::mach::cpu::instr noware::mach::cpu::next (void) const
{
	instr inst;
	
	if (full ())
		return inst;
	
	bool result;
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "next";
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return inst;
	
	return instr (std::string (anyval (zmq::msg (expression_serial), "noware::mach::queue::nonempty")));
}

const bool noware::mach::cpu::dequeue (void)
{
	if (full ())
		return false;
	
	bool result;
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "dequeue";
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	return std::string (anyval (zmq::msg (expression_serial), "noware::mach::queue::nonempty")) == "1";
}

const bool noware::mach::cpu::enqueue (const instr & inst)
{
	//return false;
	
	if (full ())
		return false;
	
	//bool result;
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "enqueue";
	expression ["element"] = inst.serialize ();
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	if (std::string (anyval (zmq::msg (expression_serial), "noware::mach::queue::nonfull")) == "1")
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

const bool noware::mach::cpu::cout (const std::string & value)
{
	
	zmq::msg msg;
	std::map <std::string, std::string> xpr;
	std::string xpr_serial;
	
	xpr ["subject"] = "cout";
	xpr ["value"] = value;
	
	if (!noware::serialize <std::map <std::string, std::string>> (xpr_serial, xpr))
		return false;
	
	msg = xpr_serial;
	return multival (msg, noware::mach::cmd::grp_dft) == "1";
	
	/*
	std::cout << value << std::endl;
	return true;
	*/
}

bool const noware::mach::cpu::cin (std::string & result, const char & delimiter)
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
const bool noware::mach::cpu::enqueue (const std::string & operand1, const opr & op, const std::string & operand2, const std::string & thread_id)
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
const bool noware::mach::cpu::enqueue (const cpu::dev & device, const opr & op, const std::map <std::string, std::string> & arg, const std::string & thread_id)
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
const bool noware::mach::cpu::respond (const zyre_event_t * event, const std::string & event_type, const std::string & shouted_group, const zmq::msg & msg_request, zmq::msg & msg_response)
{
	std::cerr << "noware::mach::cpu::respond()::called" << std::endl;
	
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
	
	std::cerr << "noware::mach::cpu::respond()::if::message[subject]==[" << message ["subject"] << ']' << std::endl;
	
	if (message ["type"] == "response")
	{
		std::cerr << "noware::mach::cpu::respond()::if::message[type]==" << message ["type"] << "::in scope" << std::endl;
		
		//if (message ["subject"] == "existence")
		//{
			std::cerr << "noware::mach::cpu::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			//std::cerr << "noware::mach::cpu::receive()::else::msg[subject]==" << msg ["subject"] << "::sleeping" << std::endl;
			//zclock_sleep (1500);
			
			// Redirect the message to the function which asked for it.
			////unicast_local (zmsg_popstr (zmq_msg));
			//result = unicast_local (msg_rx);
			result = unicast_local (msg, "");
			std::cerr << "noware::mach::cpu::respond()::unicast_local(message)==" << (result ? "success" : "failure") << std::endl;
		//}
	}
	
	return result;
}
*/

const bool/* success*/ noware::mach::cpu::respond (zmq::msg &/* response*/, const zmq::msg & rxd, const zyre_event_t */* (zyre) event*/, const std::string & event_type, const std::string &/* src*/, const net::cast &/* src_cast*/)
{
	std::cerr << "noware::mach::cpu::respond()::in scope" << std::endl;
	std::cerr << "noware::mach::cpu::respond()::event_type==[" << event_type << "]" << std::endl;
	
	std::cerr << "noware::mach::cpu::respond()::rxd==[" << std::string (rxd) << "]" << std::endl;
	//std::cerr << "noware::mach::cpu::respond()::rxd.data[1]==[" << std::string (rxd.data [1]) << "]" << std::endl;
	if (rxd == "enqueued(instr)")
	{
		// There are instructions to execute.
		//std::cerr << "noware::mach::cpu::respond()::_mutex.unlock()" << std::endl;
		//_mutex.unlock ();
		std::cerr << "noware::mach::cpu::respond()::_condition_instr_enqueued.notify_all()" << std::endl;
		{
			//boost::lock_guard <boost::mutex> lock (_mutex);
			_insn_avail = true;
		}
		_condition_instr_enqueued.notify_all ();
	}
	
	return true;
}

const bool/* success*/ noware::mach::cpu::search (zmq::msg & msg_result, const zmq::msg & msg_resp, const noware::nr &/* total, expected resonses count*/, const noware::nr &/* current count of peers who responded (so far)*/, const std::string &/* src*/, const net::cast &/* src_cast*/)
{
	std::cerr << "noware::mach::cpu::search()::called" << std::endl;
	
	//noware::tree <std::string, std::string> resp;
	std::map <std::string, std::string> resp;
	//noware::tree <std::string, std::string> result;
	//std::string result;
	noware::var result_tmp;
	//bool result;
	
	//if (!resp.deserialize (msg_resp))
	if (!noware::deserialize <std::map <std::string, std::string>> (resp, std::string (msg_resp)))
	{
		std::cerr << "noware::mach::cpu::search()::deserialize::failure" << std::endl;
		return false;
	}
	std::cerr << "noware::mach::cpu::search()::deserialize::success" << std::endl;
	
	
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
		std::cerr << "noware::mach::cpu::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		result_tmp = msg_result;
		//if (result_tmp.kind () != noware::var::type::nr)
		//	result_tmp = 0;
		
		//result += data.size ();
		//result ["value"] += resp ["value"];
		result_tmp += noware::var (resp ["value"]);
		msg_result = result_tmp;
		
		std::cerr << "noware::mach::cpu::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cerr << "noware::mach::cpu::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return false;
	}
	else if (resp ["subject"] == "next_dequeue")
	{
		std::cerr << "noware::mach::cpu::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		//std::cerr << "noware::mach::cpu::search()::queue.front ()==[" << queue.front () << ']' << std::endl;
		
		//result_tmp = queue.front ();
		//std::cerr << "noware::mach::cpu::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		
		
		if (resp ["success"] == "0")
			return false;
		
		//msg_result = result_tmp;
		//msg_result = queue.front ();
		msg_result = resp ["value"];
		std::cerr << "noware::mach::cpu::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return true;
		//return false;
		
		
		//std::cerr << "noware::mach::cpu::search()::resp[success]==[" << resp ["success"] << ']' << std::endl;
		//return resp ["success"] == "1";
	}
	else if (resp ["subject"] == "next")
	{
		std::cerr << "noware::mach::cpu::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		//std::cerr << "noware::mach::cpu::search()::queue.front ()==[" << queue.front () << ']' << std::endl;
		
		//result_tmp = queue.front ();
		//std::cerr << "noware::mach::cpu::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		
		
		if (resp ["success"] == "0")
			return false;
		
		//msg_result = result_tmp;
		//msg_result = queue.front ();
		msg_result = resp ["value"];
		std::cerr << "noware::mach::cpu::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return true;
		//return false;
		
		
		//std::cerr << "noware::mach::cpu::search()::resp[success]==[" << resp ["success"] << ']' << std::endl;
		//return resp ["success"] == "1";
	}
	else if (resp ["subject"] == "dequeue")
	{
		std::cerr << "noware::mach::cpu::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
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
		std::cerr << "noware::mach::cpu::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
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
