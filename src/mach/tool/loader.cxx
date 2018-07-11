#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <zmq/msg.cxx>

#include "loader.hxx"
#include "../../cmach/dev.cxx"
#include "../../smach/cpu.cxx"

const bool noware::mach::tool::loader::load_store_file (const std::string & file_name, std::string const & thread_id)
{
	std::ifstream file;
	
	//std::string thread;
	
	//cpu::x86_64::instr instr;
	std::string key, val;
	//unsigned long int ndx;
	//std::string token_prev;
	//std::string dest_offset_location, src_offset_location;
	std::string thread_name;
	
	// the first instruction;
	// the "entry point"
	//std::string instr1;
	
	file.open (file_name);
	
	if (!file.is_open ())
		return false;
	
	//ndx = 0;
	//instr.thread_id = noware::random::string (16);
	//instr.thread_id = thread_id;
	thread_name = std::string ("thread ") + thread_id;
	//thread = std::string ("thread ") + thread_id;
	//token_prev = "";
	//_instr.thread_id = "1";
	//_instr.oprn = cpu::opr::set;
	//while (file >> operation >> dest >> dest_ref >> dest_is_offset >> dest_offset_location >> src >> src_ref >> src_is_offset >> src_offset_location)
	//while (file >> id >> device >> operation >> arg1type >> arg1 >> arg2type >> arg2 >> arg3type >> arg3 >> arg4type >> arg4)
	while (std::getline (file, key) && std::getline (file, val))
	//while (file >> token)
	{
		//++ndx;
		
		std::cerr << "set(\"" << thread_name << "\", \"" << key << "\", \"" << val << "\")" << std::endl;
		assert (set (thread_name, key, val));
		//assert (set (thread_id, std::string ("instr ") + label, _instr.serialize ()));
	}
	
	file.close ();
	
	//_loaded = true;
	
	return true;
}

const bool noware::mach::tool::loader::load_cpu_file (const std::string & file_name, std::string const & thread_id)
{
	std::ifstream file;
	
	std::string thread_name;
	
	//smach::cpu::x86_64::instr instr;
	//std::string token;
	//std::string operation;
	//cln::nr ndx;
	std::string instr_id;
	std::string instr_id_entry;
	std::string instr_str;
	
	//cln::nr length;
	
	//unsigned long int ndx;
	//std::string token_prev;
	//std::string dest_offset_location, src_offset_location;
	
	// the first instruction;
	// the "entry point"
	//std::string instr1;
	
	smach::cpu::bbj::instr instr;
	
	// whether there are no instructions
	bool empty;
	
	
	empty = true;
	
	file.open (file_name);
	
	if (!file.is_open ())
		return false;
	
	//ndx = 0;
	//instr.thread_id = noware::random::string (16);
	//instr.thread_id = thread_id;
	thread_name = std::string ("thread ") + thread_id;
	//token_prev = "";
	//_instr.thread_id = "1";
	//_instr.oprn = cpu::opr::set;
	//while (file >> operation >> dest >> dest_ref >> dest_is_offset >> dest_offset_location >> src >> src_ref >> src_is_offset >> src_offset_location)
	//while (file >> id >> device >> operation >> arg1type >> arg1 >> arg2type >> arg2 >> arg3type >> arg3 >> arg4type >> arg4)
	
	if (file >> instr_id_entry)
	{
		// get the rest of the instruction
		if (!std::getline (file, instr_str, ';'))
		{
			file.close ();
			return false;
		}
		
		instr = instr_deserialize (instr_str);
		
		std::cerr << "noware::mach::cpu::loader::load_file()::instr_id_entry[" << instr_id_entry << "]" << std::endl;
		//std::cerr << "noware::mach::cpu::loader::load_file()::instr.operation[" << instr.operation << "]" << std::endl;
		std::cerr << instr.dump () << std::endl;
		//instr.operation = operation_get (operation);
		assert (set (thread_name, std::string ("instr ") + instr_id_entry, instr.serialize ()));
		//assert (set (thread_id, std::string ("instr ") + label, _instr.serialize ()));
		
		empty = false;
	}
	
	while
	(
		file >>
		
		// instruction id
		instr_id
		
		/*
		// operation
		instr.operation >>
		
		// dest
			instr.dest >>
		
		// src_ref
			instr.src_ref >>
		
		// src
			instr.src >>
		
		// next
			instr.next
		*/
	)
	
	//while (std::getline (file, instr_str, ';'))
	//while (file >> token)
	{
		//++ndx;
		
		/*
		if (empty)
		{
			instr_id_entry = instr_id;
		}
		*/
		
		// get the rest of the instruction
		if (!std::getline (file, instr_str, ';'))
		{
			file.close ();
			return false;
		}
		
		instr = instr_deserialize (instr_str);
		
		std::cerr << "noware::mach::cpu::loader::load_file()::instr_id[" << instr_id << "]" << std::endl;
		//std::cerr << "noware::mach::cpu::loader::load_file()::instr.operation[" << instr.operation << "]" << std::endl;
		std::cerr << instr.dump () << std::endl;
		//instr.operation = operation_get (operation);
		assert (set (thread_name, std::string ("instr ") + instr_id, instr.serialize ()));
		//assert (set (thread_id, std::string ("instr ") + label, _instr.serialize ()));
		
		//empty = false;
	}
	
	file.close ();
	
	if (!empty)
	{
		////assert (set (std::string ("thread ") + _instr.thread_id, "running", "0"));
		//assert (set (thread_id, "running", "1"));
		assert (set (thread_name, "index", instr_id_entry));
		//set (std::string ("thread ") + _instr.thread_id, "running", "0");
		//assert (set (thread_name, "index.max", cln::nr (ndx).operator const std::string ()));
		
		//instr1 = get (thread_id, "instr 1");
		//_instr.dump ();
		//assert (enqueue (_instr));
		if (!enqueue (thread_name))
			return false;
	}
	
	//_loaded = true;
	
	return true;
}

//#include "loader.operation_get.cxx"
noware::smach::cpu::bbj::instr const noware::mach::tool::loader::instr_deserialize (std::string const & instr_str) const
{
	noware::smach::cpu::bbj::instr instr;
	std::stringstream instr_ss;
	cln::nr length;
	unsigned short int operation;
	//std::string dev;
	char * buffer;
	
	instr_ss.str (instr_str);
	
	instr_ss >> operation;
	instr.operation = operation == 0 ? noware::smach::cpu::bbj::opr::_null : noware::smach::cpu::bbj::opr::_bbj;
	
	
	instr_ss >> instr.dest_dev;
	
	instr_ss >> length;
	buffer = new char [(unsigned long int) length+1];
	instr_ss.ignore (1);	// the space between the length and the value
	instr_ss.read (buffer, length);
	buffer [(unsigned long int) length] = '\0';
	instr.dest = buffer;
	delete [] buffer;
	
	
	instr_ss >> instr.src_dev;
	
	//instr_ss >> instr.src_ref;
	
	instr_ss >> length;
	buffer = new char [(unsigned long int) length+1];
	instr_ss.ignore (1);	// the space between the length and the value
	instr_ss.read (buffer, length);
	buffer [(unsigned long int) length] = '\0';
	instr.src = buffer;
	delete [] buffer;
	
	
	instr_ss >> length;
	buffer = new char [(unsigned long int) length+1];
	instr_ss.ignore (1);	// the space between the length and the value
	instr_ss.read (buffer, length);
	buffer [(unsigned long int) length] = '\0';
	instr.next = buffer;
	delete [] buffer;
	
	return instr;
}

std::string const/* value*/ noware::mach::tool::loader::get (const std::string & group, const std::string & key) const
{
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "obtainment";
	expression ["group"] = group;
	expression ["key"] = key;
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
	{
		std::cerr << "noware::mach::tool::loader::get()::serialize()::failure" << std::endl;
		
		return "";
	}
	
	return std::string (anyval (zmq::msg (expression_serial), "noware::mmach::store"));
}

const std::string/* value*/ noware::mach::tool::loader::get (const std::string & key) const
{
	return get (std::string (""), key);
}

const bool/* success*/ noware::mach::tool::loader::set (const std::string & group, const std::string & key, const std::string & value)
{
	std::cerr << "noware::mach::tool::loader::set()::in scope" << std::endl;
	
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "assignment";
	expression ["group"] = group;
	expression ["key"] = key;
	expression ["value"] = value;
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
	{
		std::cerr << "noware::mach::tool::loader::set()::serialize()::false" << std::endl;
		
		return false;
	}
	
	//std::cerr << "noware::mach::tool::loader::set()::return" << std::endl;
	if (std::string (anyval (zmq::msg (expression_serial), "noware::mmach::store")) == "1")
	{
		std::cerr << "noware::mach::tool::loader::set()::return==[true]" << std::endl;
		return true;
	}
	else
	{
		std::cerr << "noware::mach::cpu::loader::set()::return==[false]" << std::endl;
		return false;
	}
}

const bool/* success*/ noware::mach::tool::loader::set (const std::string & key, const std::string & value)
{
	return set (std::string (""), key);
}

bool const noware::mach::tool::loader::enqueue (std::string const & element)
{
	//return false;
	
	//if (full ())
	//	return false;
	
	//bool result;
	std::map <std::string, std::string> expression;
	std::string expression_serial;
	
	expression ["subject"] = "enqueue";
	expression ["element"] = element;
	
	if (!noware::serialize <std::map <std::string, std::string>> (expression_serial, expression))
		return false;
	
	if (std::string (anyval (zmq::msg (expression_serial), "noware::mmach::queue")) == "1")
	//if (std::string (multival (zmq::msg (expression_serial), "noware::mach::queue::nonfull")) == "1")
	{
		/*
		// Enqueuing notice.
		// Try to transmit: "An instruction was enqueued.".
		zmq::msg notice;
		std::string peer_id;
		
		notice = "enqueued(instr)";
		notice.prepend (zmq::msg::frame ("noware::mach::dev::response::nondesired"));	// Optional
		notice.prepend (zmq::msg::frame (noware::random::string (16)));
		
		std::cerr << "noware::mach::cpu::loader::enqueue()::broadcast" << std::endl;
		//node.multicast (notice, cpu::grp_dft);
		_node.anycast (notice, peer_id, mach::cpu::grp_dft);
		*/
		
		return true;
	}
	else
	{
		return false;
	}
}

const bool/* success*/ noware::mach::tool::loader::search (zmq::msg & msg_result, const zmq::msg & msg_resp, const cln::nr &/* total, expected resonses count*/, const cln::nr &/* current count of peers who responded (so far)*/, const std::string &/* src*/, const net::cast &/* src_cast*/)
{
	std::cerr << "noware::mach::cpu::loader::search()::called" << std::endl;
	
	//noware::tree <std::string, std::string> resp;
	std::map <std::string, std::string> resp;
	//noware::tree <std::string, std::string> result;
	//std::string result;
	noware::var result_tmp;
	//bool result;
	
	//if (!resp.deserialize (msg_resp))
	if (!noware::deserialize <std::map <std::string, std::string>> (resp, std::string (msg_resp)))
	{
		std::cerr << "noware::mach::cpu::loader::search()::deserialize::failure" << std::endl;
		return false;
	}
	std::cerr << "noware::mach::cpu::loader::search()::deserialize::success" << std::endl;
	
	
	//result ["subject"] = resp ["subject"];
	
	// Store
	if (resp ["subject"] == "existence")
	{
		msg_result = resp ["value"];
		
		return msg_result == "1";
	}
	else if (resp ["subject"] == "obtainment")
	{
		if (resp ["value.exist"] == "1")
		{
			msg_result = resp ["value"];
			return true;
		}
		
		return false;
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
		std::cerr << "noware::mach::cpu::loader::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		result_tmp = msg_result;
		//if (result_tmp.kind () != noware::var::type::nr)
		//	result_tmp = 0;
		
		//result += data.size ();
		//result ["value"] += resp ["value"];
		result_tmp += noware::var (resp ["value"]);
		msg_result = result_tmp;
		
		std::cerr << "noware::mach::cpu::loader::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		std::cerr << "noware::mach::cpu::loader::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return false;
	}
	else if (resp ["subject"] == "next_dequeue")
	{
		std::cerr << "noware::mach::cpu::loader::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		//std::cerr << "noware::mach::cpu::loader::search()::queue.front ()==[" << queue.front () << ']' << std::endl;
		
		//result_tmp = queue.front ();
		//std::cerr << "noware::mach::cpu::loader::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		
		
		if (resp ["success"] == "0")
			return false;
		
		//msg_result = result_tmp;
		//msg_result = queue.front ();
		msg_result = resp ["value"];
		std::cerr << "noware::mach::cpu::loader::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return true;
		//return false;
		
		
		//std::cerr << "noware::mach::cpu::loader::search()::resp[success]==[" << resp ["success"] << ']' << std::endl;
		//return resp ["success"] == "1";
	}
	else if (resp ["subject"] == "next")
	{
		std::cerr << "noware::mach::cpu::loader::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
		//std::cerr << "noware::mach::cpu::loader::search()::queue.front ()==[" << queue.front () << ']' << std::endl;
		
		//result_tmp = queue.front ();
		//std::cerr << "noware::mach::cpu::loader::search()::result_tmp==[" << result_tmp << ']' << std::endl;
		
		
		if (resp ["success"] == "0")
			return false;
		
		//msg_result = result_tmp;
		//msg_result = queue.front ();
		msg_result = resp ["value"];
		std::cerr << "noware::mach::cpu::loader::search()::msg_result==[" << std::string (msg_result) << ']' << std::endl;
		
		return true;
		//return false;
		
		
		//std::cerr << "noware::mach::cpu::loader::search()::resp[success]==[" << resp ["success"] << ']' << std::endl;
		//return resp ["success"] == "1";
	}
	else if (resp ["subject"] == "dequeue")
	{
		std::cerr << "noware::mach::cpu::loader::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
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
		std::cerr << "noware::mach::cpu::loader::search()::subject==[" << resp ["subject"] << ']' << std::endl;
		
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
	
	return false;
}
