#pragma once

//#include ".instr/.incl.cxx"
//#include ".instr/.cxx"
//#include "_instr/.cxx"

noware::smach::cpu::bbj::instr::instr (void)
{
	//thread_id = "";
	//_operation = "";
	_oprn = oprn::_null;
	//dest_dev = mach::dev::cmd;
	//dest_dev = "";
	//src_dev = mach::dev::null;
	//src_dev = "";
}

std::string const noware::smach::cpu::bbj::instr::dump (void) const
{
	std::stringstream ss;
	
	ss << "   _oprn[" << _oprn << ']' << std::endl;
	ss << "dest_dev[" << dest_dev << ']' << std::endl;
	ss << "    dest[" << dest << ']' << std::endl;
	ss << " src_dev[" << src_dev << ']' << std::endl;
	ss << "     src[" << src << ']' << std::endl;
	ss << "    next[" << next << ']' << std::endl;
	
	return ss.str ();
}

template <typename archive>
void noware::smach::cpu::bbj::instr::serialize (archive & arch, unsigned int const &/* version*/)
{
	//arch & thread_id;
	
	arch & _oprn;
	//arch & _operation;
	//arch & args_nr;
	
	arch & dest_dev;
	arch & dest;
	arch & src_dev;
	arch & src;
	arch & next;
}

bool const noware::smach::cpu::bbj::instr::null (void) const
{
	return _oprn == oprn::_null;
}

std::string const noware::smach::cpu::bbj::instr::serialize (void) const
{
	std::string serial;
	
	if (noware::serialize <noware::smach::cpu::bbj::instr> (serial, *this))
		return serial;
	else
		return "";
}

bool const noware::smach::cpu::bbj::instr::deserialize (std::string const & serial)
{
	return noware::deserialize <noware::smach::cpu::bbj::instr> (*this, serial);
}

