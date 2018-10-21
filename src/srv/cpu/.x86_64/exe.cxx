//bool const noware::smach::cpu::x86_64::exe (/*vmach::cpu::bbj::*/insn const & _insn, std::string & insn_ptr, std::string const & thread_id)
bool const noware::vos::srv::cpu::x86_64::exe (bool & end, _DInst const & _insn/*, uint64_t & insn_ptr*/, thread & _thread)
{
	std::cerr << "noware::vos::srv::cpu:x86_64::exe()::in scope" << std::endl;
	
	if (_insn.flags == FLAG_NOT_DECODABLE)
	{
		std::cerr << "noware::vos::srv::cpu:x86_64::exe()::insn::!valid" << std::endl;
		
		return false;
	}
	
	switch (_insn.opcode)
	{
		case I_INT:
			// an interrupt
			std::cerr << "noware::vos::srv::cpu::x86_64::exe()::I_INT" << std::endl;
			
			// what kind of interrupt?
			switch (_insn/*.ops [0]*/.imm.qword)
			{
				// ...a system call
				case 0x80:
					std::cerr << "noware::smach::cpu::exe()::int==128" << std::endl;
					
					// what kind of system call?
					switch (_thread.eax)
					{
						// ...to sys_write
						case 0x4:
							std::cerr << "noware::smach::cpu::exe()::eax==0x4" << std::endl;
							
							// with what file descriptor?
							switch (_thread.ebx)
							{
								// being std output
								case 0x1:
									std::cerr << "noware::smach::cpu::exe()::ebx==0x1" << std::endl;
									
									
									// how many bytes to write (%edx bytes) to stdout
									// from the memory location pointed to
									// by the value in %ecx
									uint64_t count;
									
									// the memory location
									store_key_t ndx;
									
									// the value of the memory location
									store_val_t val;
									
									count = _thread.edx;
									ndx = _thread.ecx;
									
									
									// sys_call sys_write to std_output
									for (; count > 0; --count, ++ndx)
									{
										std::cerr << "noware::smach::cpu::exe()::ndx[" << ndx << "]" << std::endl;
										
										if (!get (_thread.id, ndx, val))
										{
											std::cerr << "noware::smach::cpu::exe()::get[false]" << std::endl;
											//return false;
										}
										else if (!cout (val))
										{
											std::cerr << "noware::smach::cpu::exe()::cout[false]" << std::endl;
											//return false;
										}
										else
										{
											std::cerr << "noware::smach::cpu::exe()::cout[true]" << std::endl;
											//return true;
										}
									}
							}
							
							break;
						
						// ...to_sys_exit
						case 0x1:
							// perform program exit
							// by simply notifying the caller;
							// they will take care of releasing the resources.
							// 
							// this is done,
							// because is is simpler to search for/reach/assert
							// this terminating instruction, here, in this function
							// than in the calling one; we just notify them
							end = true;
					}
				
				return true;
			}
		/*	
		case x86_64::opn::_nop:
			// a null operation
			// there is no need to effectively do anything
			return true;
		*/
		case I_MOV:
			//std::string src;
			//std::string dest;
			
			switch (_insn.ops [0].type)
			{
				case O_REG:
					std::cerr << "noware::vos::srv::cpu::x86_64::exe()::I_MOV::op[0].type==O_REG" << std::endl;
					
					uint64_t * dest;
					//uint64_t * src;
					
					//dest = GET_REGISTER_NAME (_insn.ops [0].index);
					switch (_insn.ops [0].index)
					{
						case R_EAX:
							std::cerr << "noware::vos::srv::cpu::x86_64::exe()::I_MOV::O_REG::op[0].index::R_EAX" << std::endl;
							
							dest = &_thread.eax;
							break;
							
						case R_EBX:
							std::cerr << "noware::vos::srv::cpu::x86_64::exe()::I_MOV::O_REG::op[0].index::R_EBX" << std::endl;
							
							dest = &_thread.ebx;
							break;
							
						case R_ECX:
							std::cerr << "noware::vos::srv::cpu::x86_64::exe()::I_MOV::O_REG::op[0].index::R_ECX" << std::endl;
							
							dest = &_thread.ecx;
							break;
							
						case R_EDX:
							std::cerr << "noware::vos::srv::cpu::x86_64::exe()::I_MOV::O_REG::op[0].index::R_EDX" << std::endl;
							
							dest = &_thread.edx;
							break;
							
						default:
							std::cerr << "noware::vos::srv::cpu::x86_64::exe()::I_MOV::O_REG::op[0].index::undefined" << std::endl;
							
							return false;
					}
					
					//std::cerr << "noware::vos::srv::cpu::x86_64::exe()::I_MOV::O_REG::op[0].index[" << dest << "]" << std::endl;
					
					switch (_insn.ops [1].type)
					{
						case O_IMM:
							std::cerr << "noware::vos::srv::cpu::x86_64::exe()::I_MOV::op[1].type==O_IMM" << std::endl;
							
							/*
							std::stringstream ss;
							
							ss << std::hex;
							ss << std::nouppercase;
							ss << std::noshowbase;
							//ss << std::setw ();
							//ss << std::setfill ('0');
							
							ss << _insn.ops [1].imm.qword;
							
							src = ss.str ();
							*/
							
							*dest = _insn/*.ops [1]*/.imm.qword;
							
							std::cerr << "noware::vos::srv::cpu::x86_64::exe()::I_MOV::O_IMM::imm.qword[" << *dest << "]" << std::endl;
							break;
							
						default:
							std::cerr << "noware::vos::srv::cpu::x86_64::exe()::I_MOV::op[1].type::undefined" << std::endl;
							
							return false;
					}
					
					return true;
				default:
					std::cerr << "noware::vos::srv::cpu::x86_64::exe()::I_MOV::op[0].type::undefined" << std::endl;
					
					return false;
			}
			
			//std::cerr << "noware::vos::srv::cpu::x86_64::exe()::set(thread_id==\"" << thread_id << "\", dest==\"" << dest << "\", src==\"" << src << "\")" << std::endl;
			//
			//return set (thread_id, dest, src);
			
		default:
			// undefined operation
			std::cerr << "noware::vos::srv::cpu::x86_64::exe()::operation::undefined" << std::endl;
			
			return false;
	}
}
