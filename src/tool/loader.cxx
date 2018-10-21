#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <zmq/msg.cxx>

#include "loader.hxx"
#include "../usr/dev.cxx"
#include "../msg/subj.hxx"
#include "../srv/cpu/x86_64.cxx"

bool const noware::vos::tool::loader::load_file_store (std::string const & file_name, int unsigned const & thread_id/*, char const & delim_inner, char const & delim_outer*/)
{
	std::ifstream file;
	
	//std::string thread;
	
	//cpu::x86_64::instr instr;
//	std::string key, val;
	int long unsigned key;
	int short unsigned val;
	//unsigned long int ndx;
	//std::string token_prev;
	//std::string dest_offset_location, src_offset_location;
//	std::string thread_name;
//	std::string key_prefix;
	
	// the first instruction;
	// the "entry point"
	//std::string instr1;
	
	file.open (file_name);
	
	if (!file.is_open ())
		return false;
	
	//ndx = 0;
	//instr.thread_id = noware::random::string (16);
	//instr.thread_id = thread_id;
//	thread_name = std::string ("thread ") + thread_id;
//	key_prefix = std::string ("ram ");
	//thread = std::string ("thread ") + thread_id;
	//token_prev = "";
	//_instr.thread_id = "1";
	//_instr.oprn = cpu::opr::set;
	//while (file >> operation >> dest >> dest_ref >> dest_is_offset >> dest_offset_location >> src >> src_ref >> src_is_offset >> src_offset_location)
	//while (file >> id >> device >> operation >> arg1type >> arg1 >> arg2type >> arg2 >> arg3type >> arg3 >> arg4type >> arg4)
//	while (std::getline (file, key) && std::getline (file, val))
	//while (file >> token)
	while (file >> key >> val)
	{
		//++ndx;
		
		std::cerr << "noware::vos::tool::loader::set(\"" << thread_id << "\", \"" << /*key_prefix << */key << "\", \"" << val << "\")" << std::endl;
		assert (set (thread_id, /*key_prefix + */key, val));
		//assert (set (thread_id, std::string ("instr ") + label, _instr.serialize ()));
	}
	
	file.close ();
	
	//_loaded = true;
	
	return true;
}

char unsigned const/* value*/ noware::vos::tool::loader::get (int unsigned const & grp, uint64_t const & key) const
{
	std::cerr << "noware::vos::tool::loader::get(" << grp << ',' << key << ')' << std::endl;
	
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
	
	// transmit the request
	re = anyval (req, "noware::vos::man::store");
	
	try
	{
		//if (!(*(re.data.at (0).data.data <bool> ())/*succes*/))
		//	return false;
		
		return *(re.data.at (1).data.data <char unsigned> ())/*result*/;
	}
	catch (...)
	{
		return '\0';
	}
}

//const std::string/* value*/ noware::vos::tool::loader::get (const std::string & key) const
//{
//	return get (std::string (""), key);
//}

bool const/* success*/ noware::vos::tool::loader::set (int unsigned const & grp, uint64_t const & key, char unsigned const & val)
{
	std::cerr << "noware::vos::tool::loader::set(" << grp << ',' << key << ',' << ((int short unsigned) val) << ")::in scope" << std::endl;
	
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
	
	// perform the request
	re = anyval (req, "noware::vos::man::store");
	
	try
	{
		std::cerr << "noware::vos::usr::store::set()::try" << std::endl;
		// succes
		return *(re.data.at (1).data.data <bool> ());
	}
	catch (...)
	{
		std::cerr << "noware::vos::usr::store::seet()::caught exception" << std::endl;
		return false;
	}
	
	return false;
}

//const bool/* success*/ noware::vos::tool::loader::set (const std::string & key, const std::string & value)
//{
//	return set (std::string (""), key);
//}

bool const noware::vos::tool::loader::enqueue (std::string const & element)
{
	std::cerr << "noware::vos::tool::loader::enqueue(\"" << element << "\")::called" << std::endl;
	
	// the requesting message
	zmq::msg req;
	
	// the replying message
	zmq::msg re;
	
	// the subject of the conversation
	msg::subj subj;
	
	
	subj = msg::subj::enqueue;
	
	req.data [0] = zmq::message_t (&subj, sizeof subj);
	req.data [1] = zmq::message_t (element.c_str (), element.size () + 1);
	
	
	// perform the call
	re = anyval (req, "noware::vos::man::queue");
	
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

bool const/* success*/ noware::vos::tool::loader::aggregate_remote (zmq::msg & msg_result/* overall/final result. passed during each iteration*/, zmq::msg const & msg_curr/* current response message/expression*/, cln::nr const &/* total, expected resonses count*/, cln::nr const &/* current count of peers who responded (so far)*/, std::string const &/* src*/, net::cast const &/* src_cast*/)
{
	// normally, there should be only one message:
	// the one from the manager who we requested from,
	// so this function should only be called once,
	// having the current message as the only message (and the final result)
	msg_result = msg_curr;
	return true;
}

const bool/* success*/ noware::vos::tool::loader::search_remote (zmq::msg const & msg_result, const zmq::msg & msg_resp, const cln::nr &/* total, expected resonses count*/, const cln::nr &/* current count of peers who responded (so far)*/, const std::string &/* src*/, const net::cast &/* src_cast*/)
{
	std::cerr << "noware::vos::cpu::loader::search_remote()::called" << std::endl;
	
	return true;
}
