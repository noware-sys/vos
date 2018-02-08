#pragma once

//#include <thread>
#include <assert.h>
#include <fstream>

//#include <boost/function.hpp>
////#include <boost/function_equal.hpp>
//#include <boost/bind.hpp>
#include <boost/thread.hpp>

#include <omp.h>

#include "pmach.hxx"

//#include "array.txx"
#include "var.cxx"
#include "mach.cxx"
#include <zmq/msg.cxx>
//#include "nr.cxx"
//#include "container/list/sqlite.cxx"
//#include ".mach/.incl.cxx"
//#include ".mach/.cxx"

noware::pmach::pmach (void)
{
	/*
	thread * t;
	
	t = new thread ();
	
	trd [t -> group ()] = t;
	*/
	
	
	//cpu.start ();
	
	/*
	unsigned int cores = boost::thread::hardware_concurrency ();
	store * mem;
	queue * q;
	cpu * proc;
	
	#pragma omp parallel
	{
		#pragma omp for
		for (unsigned int ndx = 1; ndx <= cores; ++ndx)
		{
			#pragma omp critical
			{
				mem = &_store [ndx];
			}
			
			#pragma omp critical
			{
				q = &_queue [ndx];
			}
			
			#pragma omp critical
			{
				proc = &_cpu [ndx];
			}
			
			//assert (proc -> start ());
			//_cpu [ndx].node.init ();
			//_cpu [ndx].node.init ();
			//_cpu [ndx].node.init ();
		}
	}
	*/
}

noware::pmach::~pmach (void)
{
	//delete
}

//const LIB::container::NAME_V LIB::pmach::evaluate (const LIB::container::NAME_V & expression)
//{
//	return "";
//}

/*
const bool noware::pmach::enqueue (const std::string & file_name)
{
//	if (!trd.load (file_name))
//		return false;
	
	//if (!trd.start ())
	//	return false;
	
	return false;
}
*/

const bool noware::pmach::empty (void) const
{
	return store::empty ();
}

const bool noware::pmach::empty_local (void) const
{
	return store::empty_local ();
}

const bool noware::pmach::full (void) const
{
	return store::full ();
}

const bool noware::pmach::full_local (void) const
{
	return store::full_local ();
}

const bool noware::pmach::stop (void)
{
	//if (!running ())
	//	return true;
	
	if (!dev::stop ())
		return false;
	
	//running = false;
	//exen -> join ();
	delete exen;
	exen = nullptr;
	
	return true;
}

const bool noware::pmach::running (void) const
{
	if (!dev::running ())
		return false;
	
	if (exen == nullptr)
		return false;
	
	return true;
}

const bool noware::pmach::start (void)
{
	//if (running ())
	//	return true;
	if (exen != nullptr)
		return true;
	
	if (!dev::start ());
		return false;
	
	//running = true;
	exen = new boost::thread (boost::bind (boost::mem_fn (&noware::pmach::exe), this));
	
	return exen != nullptr;
}

void noware::pmach::exe (void)
{
	std::cerr << "noware::pmach::exe()::in scope" << std::endl;
	
	mach::cpu::instr inst;
	mach::cpu::instr inst_next;
	
	noware::nr index_max;
	noware::nr index;
	
	//noware::var src;
	//noware::var dest;
	
	//noware::var src_offset;
	//noware::var dest_offset;
	
	char delimiter;
	std::string input;
	
	std::string thread_id;
	
	bool result;
	
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
	
	while (true)
	//while (running)
	{
		std::cerr << "noware::pmach::exe()::while(true)::in scope" << std::endl;
		std::cerr << "noware::pmach::exe()::while(running)::in scope" << std::endl;
		
		while (!empty ())
		{
			std::cerr << "noware::pmach::exe()::while(!empty())::in scope" << std::endl;
			
			// fetch next (and dequeue)
			std::cerr << "noware::pmach::next_dequeue()" << std::endl;
			inst = next_dequeue ();
			
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
			
			//std::cerr << "noware::pmach::exe::set(\"thread " << inst.thread_id << "\"," << inst.oprnd [1] << "," << inst.oprnd [0] << ")" << std::endl;
			
			// arg 1
			// destination/result
			if (inst.arg_type ["1"])
			{
				std::cerr << "noware::pmach::exe::instr.ref[arg1]==true" << std::endl;
				
				inst.arg ["1"] = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, inst.arg ["1"]);
			}
			else
			{
				std::cerr << "noware::pmach::exe::instr.ref[arg1]==false" << std::endl;
			}
			std::cerr << "noware::pmach::exe::instr[arg1]==[" << inst.arg["1"] << "]" << std::endl;
			
			// arg 2
			if (inst.arg_type ["2"])
			{
				std::cerr << "noware::pmach::exe::instr.ref[arg2]==true" << std::endl;
				
				inst.arg ["2"] = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, inst.arg ["2"]);
			}
			else
			{
				std::cerr << "noware::pmach::exe::instr.ref[arg2]==false" << std::endl;
			}
			std::cerr << "noware::pmach::exe::instr[arg2]==[" << inst.arg["2"] << "]" << std::endl;
			
			// arg 3
			if (inst.arg_type ["3"])
			{
				std::cerr << "noware::pmach::exe::instr.ref[arg3]==true" << std::endl;
				
				inst.arg ["3"] = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, inst.arg ["3"]);
			}
			else
			{
				std::cerr << "noware::pmach::exe::instr.ref[arg3]==false" << std::endl;
			}
			std::cerr << "noware::pmach::exe::instr[arg3]==[" << inst.arg["3"] << "]" << std::endl;
			
			// arg 4
			if (inst.arg_type ["4"])
			{
				std::cerr << "noware::pmach::exe::instr.ref[arg4]==true" << std::endl;
				
				inst.arg ["4"] = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, inst.arg ["4"]);
			}
			else
			{
				std::cerr << "noware::pmach::exe::instr.ref[arg4]==false" << std::endl;
			}
			std::cerr << "noware::pmach::exe::instr[arg4]==[" << inst.arg["4"] << "]" << std::endl;
			
			if (inst.dev == "store")
			{
				if (inst.opr == "set")
				{
					std::cerr << "noware::pmach::exe::instr::store::set" << std::endl;
					//std::cerr << inst.arg ["value"];
					
					//assert (set (thread_id/* group*/, dest/* key*/, src/* value*/));
					result = set (thread_id/* group*/, inst.arg ["2"]/* key*/, inst.arg ["3"]/* value*/);
				}
				else if (inst.opr == "unset")
				{
					std::cerr << "noware::pmach::exe::instr::store::unset" << std::endl;
					//std::cerr << inst.arg ["value"];
					
					result = remove (thread_id/* group*/, inst.arg ["2"]);
				}
				else if (inst.opr == "exist")
				{
					std::cerr << "noware::pmach::exe::instr::store::unset" << std::endl;
					//std::cerr << inst.arg ["value"];
					
					result = exist (thread_id/* group*/, inst.arg ["2"]);
				}
			}
			else if (inst.dev == "cmd")
			{
				if (inst.opr == "set")
				{
					std::cerr << "noware::pmach::exe::instr::cmd::set[" << inst.arg ["2"] << "]" << std::endl;
					
					// space
					if (inst.arg ["2"] == "\\_")
					{
						//std::cout << "TWO";
						std::cout << ' ';
					}
					/*
					// back slash
					else if (inst.arg ["2"] == "\\")
					{
						//std::cout << "TWO";
						std::cout << ;
					}
					*/
					// new line
					else if (inst.arg ["2"] == "\\n")
					{
						//std::cout << "TWO";
						std::cout << std::endl;
					}
					else
					{
						std::cout << inst.arg ["2"];
					}
					
					result = true;
				}
				else if (inst.opr == "get")
				{
					std::cerr << "noware::pmach::exe::instr::cmd::get(std::cin," << input << "," << inst.arg ["3"] [0] << ")" << std::endl;
					if (inst.arg ["3"] == "\\n")
						std::getline (std::cin, input, '\n');
					else
						std::getline (std::cin, input, inst.arg ["3"] [0]);
					std::cerr << "noware::pmach::exe::instr::cmd::get::set(" << thread_id << "," << inst.arg ["2"] << "," << input << ")" << std::endl;
					result = set (thread_id/* group*/, inst.arg ["2"], input);
					std::cerr << "noware::pmach::exe::instr::cmd::get::set()::result==[" << result << "]" << std::endl;
					//result = true;
				}
			}
			
			// if the destination is a reference:
			// if the result was requested to be saved in a variable
			if (inst.arg ["1"] != "null")
			{
				assert (set (thread_id, inst.arg ["1"], result ? "1" : "0"));
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
		
		//	std::cerr << "noware::pmach::node.multicast(" << map_thread_serial << "," << inst.thread_id << ")" << std::endl;
		//	std::cerr << "noware::pmach::node.unicast(" << map_thread_serial << "," << inst.thread_id << ")" << std::endl;
			//std::cerr << "noware::pmach::multicast(" << map_thread_serial << "," << inst.thread_id << ")" << std::endl;
			
		//	msg = map_thread_serial;
		//	msg.prepend (zmq::msg::frame ("dummy_request_token"));
			//msg.prepend (zmq::msg::frame (noware::random::string (noware::pmach::dev::token_size_dft)));
			
		//	node.multicast (msg, inst.thread_id);
		
			if (inst.arg ["4"] == "0")
			{
				// "0" means "stop";
				// end the execution of the thread
				
				//assert (set (/*std::string ("thread ") + inst.*/thread_id/* group*/, "running"/* key*/, "0"/* value*/));
				assert (clear (thread_id));
			}
			else
			{
				index_max = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, "index.max"/* key*/);
				
				if (inst.arg ["4"] == "next")
				{
					index = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, "index"/* key*/);
					++index;
				}
				else
				{
					index = inst.arg ["4"];
				}
				
				std::cerr << "noware::pmach::exen()::index_max==[" << index_max << "]" << std::endl;
				std::cerr << "noware::pmach::exen()::index==[" << index << "]" << std::endl;
				if (index.operator const unsigned int () > index_max.operator const unsigned int ())
				{
					std::cerr << "noware::pmach::exen()::resetting index=1" << std::endl;
					// assert (set (/*std::string ("thread ") + inst.*/thread_id/* group*/, "running"/* key*/, "0"/* value*/));
					index = 1;
				}
				assert (set (/*std::string ("thread ") + inst.*/thread_id/* group*/, "index"/* key*/, index/* value*/));
				
				inst_next = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, std::string ("instr ") + index.operator const std::string ()/* key*/);
				
				//if (get (/*std::string ("thread ") + inst.*/thread_id/* group*/, "running"/* key*/) == "1")
				//	assert (enqueue (inst_next));
				//else
				//	assert (clear (/*std::string ("thread ") + inst.*/thread_id/* group*/));
				assert (enqueue (inst_next));
				
				//node.unicast (msg, inst.thread_id);
				//multival (msg, inst.thread_id);
				//map_thread.clear ();
			}
		}
		
		std::cerr << "noware::pmach::sleeping..." << std::endl;
		boost::this_thread::sleep_for (boost::chrono::seconds (3));
	}
}

const noware::nr noware::pmach::count (void) const
{
	return store::count ();
}

const bool/* success*/ noware::pmach::respond (zmq::msg & response, const zmq::msg & rxd_msg, const zyre_event_t * event, const std::string & event_type, const std::string & src, const net::cast & src_cast)
{
	if (src_cast == net::cast::multi)
	{
		if (src == store::grp_dft || src == "noware::pmach::store::nonfull" || src == "noware::pmach::store::nonempty")
		{
			return store::respond (response, rxd_msg, event, event_type, src, src_cast);
		}
		else if (src == queue::grp_dft || src == "noware::pmach::queue::nonfull" || src == "noware::pmach::queue::nonempty")
		{
			return queue::respond (response, rxd_msg, event, event_type, src, src_cast);
		}
	}
	else
	{
		if (store::respond (response, rxd_msg, event, event_type, src, src_cast))
			return true;
		else if (queue::respond (response, rxd_msg, event, event_type, src, src_cast))
			return true;
	}
	
	// The default case.
	return store::dev::respond (response, rxd_msg, event, event_type, src, src_cast);
}

const bool/* success*/ noware::pmach::respond_post (const zmq::msg & response, const zmq::msg & rxd_msg, const zyre_event_t * event, const std::string & event_type, const std::string & src, const net::cast & src_cast)
{
	if (src_cast == net::cast::multi)
	{
		if (src == store::grp_dft || src == "noware::pmach::store::nonfull" || src == "noware::pmach::store::nonempty")
		{
			return store::respond_post (response, rxd_msg, event, event_type, src, src_cast);
		}
		else if (src == queue::grp_dft || src == "noware::pmach::queue::nonfull" || src == "noware::pmach::queue::nonempty")
		{
			return queue::respond_post (response, rxd_msg, event, event_type, src, src_cast);
		}
	}
	else
	{
		if (store::respond_post (response, rxd_msg, event, event_type, src, src_cast))
			return true;
		else if (queue::respond_post (response, rxd_msg, event, event_type, src, src_cast))
			return true;
	}
	
	// The default case.
	return dev::respond_post (response, rxd_msg, event, event_type, src, src_cast);
}

const bool/* success*/ noware::pmach::search (zmq::msg & result, const zmq::msg & xpr, const std::string & src, const net::cast & src_cast)
{
	if (src_cast == net::cast::multi)
	{
		if (src == store::grp_dft || src == "noware::pmach::store::nonfull" || src == "noware::pmach::store::nonempty")
		{
			return store::search (result, xpr, src, src_cast);
		}
		else if (src == queue::grp_dft || src == "noware::pmach::queue::nonfull" || src == "noware::pmach::queue::nonempty")
		{
			return queue::search (result, xpr, src, src_cast);
		}
	}
	else
	{
		if (store::search (result, xpr, src, src_cast))
			return true;
		else if (queue::search (result, xpr, src, src_cast))
			return true;
	}
	
	// The default case.
	return dev::search (result, xpr, src, src_cast);
}

const bool/* success*/ noware::pmach::search_local (zmq::msg & result, const zmq::msg & xpr, const std::string & src, const net::cast & src_cast)
{
	if (src_cast == net::cast::multi)
	{
		if (src == store::grp_dft || src == "noware::pmach::store::nonfull" || src == "noware::pmach::store::nonempty")
		{
			return store::search_local (result, xpr, src, src_cast);
		}
		else if (src == queue::grp_dft || src == "noware::pmach::queue::nonfull" || src == "noware::pmach::queue::nonempty")
		{
			return queue::search_local (result, xpr, src, src_cast);
		}
	}
	else
	{
		if (store::search_local (result, xpr, src, src_cast))
			return true;
		else if (queue::search_local (result, xpr, src, src_cast))
			return true;
	}
	
	// The default case.
	return dev::search_local (result, xpr, src, src_cast);
}

const zmq::msg/* result*/ noware::pmach::aggregate (const zmq::msg & result, const zmq::msg & response, const zmq::msg & xpr, const noware::nr & responses_count, const std::string & src, const net::cast & src_cast)
{
	if (src_cast == net::cast::multi)
	{
		if (src == store::grp_dft || src == "noware::mach::store::nonfull" || src == "noware::mach::store::nonempty")
		{
			return store::aggregate (result, response, xpr, responses_count, src, src_cast);
		}
		else if (src == queue::grp_dft || src == "noware::mach::queue::nonfull" || src == "noware::mach::queue::nonempty")
		{
			return queue::aggregate (result, response, xpr, responses_count, src, src_cast);
		}
	}
	else
	{
		if (store::aggregate (result, response, xpr, responses_count, src, src_cast))
			return true;
		else if (queue::aggregate (result, response, xpr, responses_count, src, src_cast))
			return true;
	}
	
	// The default case.
	return dev::aggregate (result, response, xpr, responses_count, src, src_cast);
}

const bool noware::pmach::load_file (const std::string & file_name)
{
	std::ifstream file;
	std::string thread_id;
	std::string id, device, operation, arg1, arg2, arg3, arg4;
	bool arg1type, arg2type, arg3type, arg4type;
	//std::string dest, src;
	//bool dest_is_ref, src_is_ref;
	//bool dest_is_offset, src_is_offset;
	mach::cpu::instr _instr;
	//std::map <std::string, std::string> _instr;
	unsigned int _ndx;
	std::string token;
	//std::string token_prev;
	//std::string dest_offset_location, src_offset_location;
	
	file.open (file_name);
	
	if (!file.is_open ())
		return false;
	
	_ndx = 0;
	_instr.thread_id = noware::random::string (16);
	thread_id = std::string ("thread ") + _instr.thread_id;
	//token_prev = "";
	//_instr.thread_id = "1";
	//_instr.oprn = cpu::opr::set;
	//while (file >> operation >> dest >> dest_ref >> dest_is_offset >> dest_offset_location >> src >> src_ref >> src_is_offset >> src_offset_location)
	while (file >> id >> device >> operation >> arg1type >> arg1 >> arg2type >> arg2 >> arg3type >> arg3 >> arg4type >> arg4)
	//while (file >> token)
	{
		++_ndx;
		
		_instr.dev = device;
		_instr.opr = operation;
		
		_instr.arg ["1"] = arg1;
		_instr.arg ["2"] = arg2;
		_instr.arg ["3"] = arg3;
		_instr.arg ["4"] = arg4;
		
		_instr.arg_type ["1"] = arg1type;
		_instr.arg_type ["2"] = arg2type;
		_instr.arg_type ["3"] = arg3type;
		_instr.arg_type ["4"] = arg4type;
		
		//assert (set (thread_id, std::string ("instr ") + noware::nr (_ndx).operator const std::string (), _instr.serialize ()));
		assert (set (thread_id, std::string ("instr ") + id, _instr.serialize ()));
	}
	
	file.close ();
	
	if (_ndx > 0)
	{
		//assert (set (std::string ("thread ") + _instr.thread_id, "running", "0"));
		assert (set (thread_id, "running", "1"));
		assert (set (thread_id, "index", "1"));
		//set (std::string ("thread ") + _instr.thread_id, "running", "0");
		assert (set (thread_id, "index.max", noware::nr (_ndx).operator const std::string ()));
		
		_instr = get (thread_id, "instr 1");
		assert (enqueue (_instr));
	}
	
	//_loaded = true;
	
	return true;
}
