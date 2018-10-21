void noware::vos::srv::cpu::x86_64::cycle (void)
{
	std::cerr << "noware::vos::srv::cpu::x86_64::cycle()::in scope" << std::endl;
	
	///*vmach::cpu::x86_64::*/insn _insn;
	//std::string inst_curr;
	//std::string insn_ptr;
	//std::string inst_next;
	store_key_t insn_ptr;
	store_val_t val;
	//std::string insn_part;
	//std::string code;
	queue_val_t element;
	
	//std::bitset <8> insn_byte;
	
	//cln::nr index_max;
	//cln::nr index;
	//std::string index;
	
	//noware::var src;
	//noware::var dest;
	
	//noware::var src_offset;
	//noware::var dest_offset;
	
	//std::string separator;
	//std::string input;
	
	//std::string thread_id;
	//std::string thread_name;
	thread _thread;
	
	// was the last executed instruction
	// the last one that should be executed in this thread?
	// (ie. has the end been reached?) 
	bool end;
	
	/*
	bool result_offset_prefetch_visited;
	bool dest_offset_prefetch_visited;
	bool src_offset_prefetch_visited;
	
	bool result;
	*/
	
	// nr of insns, of the same thread,
	// executed in series, within the same parent loop,
	// before resuming usage of the networked queue again
	cln::nr insn_cache_curr;
	
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
	
	_DecodeType dt = Decode64Bits;
	_CodeInfo ci;
	int unsigned decodedInstructionsCount;
	_DInst decodedInstructions [1];
	char unsigned code [15];
	
	/*
	result = false;
	
	result_offset_prefetch_visited = false;
	dest_offset_prefetch_visited = false;
	src_offset_prefetch_visited = false;
	*/
	
	//// program counter
	//unsigned int pc;
	//insn_ptr << std::bin;
	
	
	ci.codeOffset = 0;
	ci.dt = dt;
	ci.features = DF_NONE;
	
	end = false;
	
	
	while (true)
	//while (_running)
	//while (!boost::this_thread::interruption_requested ())
	{
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::x86_64::cycle()::while(true)::in scope" << std::endl;
		//std::cerr << "noware::smach::cpu::exe()::while(_running)::in scope" << std::endl;
		
		while (/*_node.peer_size ("noware::mmach::queue") > 0 && */!empty ())
		{
			std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::x86_64::cycle()::while(!empty())::in scope" << std::endl;
			
			
			// fetch the next instruction, dequeuing it, and decoding (deserializing) it
			
			
			// fetch
			std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::x86_64::cycle()::next_dequeue()" << std::endl;
			//inst.deserialize (next_dequeue ());
			//thread_name = std::string ("thread ") + thread_id;
			//thread_name = next_dequeue ();
			
			if (!next_dequeue (element))
				//continue
				;
			if (!_thread.deserialize (element))
				//continue
				;
			
			// dump member variables
			//std::cerr << _thread.dump () << std::endl;
			
			insn_ptr = _thread.insn_ptr;
			
			for (insn_cache_curr = 0; insn_cache_curr < _insn_cache && !end; ++insn_cache_curr)
			{
				/*
				// TODO get the *complete* instruction code
				// (not only the first ram location)
				insn_part = "";
				insn_code = "";
				
				do
				{
					// save the code that we have so far
					insn_code += insn_part;
					
					// get the single ram location's value pointed to by insn_ptr address
					insn_part = get (_thread.id, insn_ptr);
					
					// increment insn_ptr to point to the next isns_part
					insn_ptr = std::bitset <64> (std::bitset <64> (insn_ptr).to_ullong () + 1).to_string ();
				}
				while (!insn::code_is_fin (std::bitset <8> (insn_part), insn_code));
				
				// save the last part of the code
				// that could not have been saved after the last iteration in the loop
				insn_code += insn_part;
				
				// convert the obtained byte - std::string -> std::bitset
				//for (unsigned short int ndx = 0; ndx < 8/*insn_byte.size ()*//* && ndx < insn_part.size ()* /; ++ndx)
				//{
				//	insn_byte [ndx] = (insn_part [ndx] == '0' ? false : true);
				//}
				//std::bitset <8> (insn_part);
				
				//while (!insn::code_fin (std::bitset <8> (insn_part)/*insn_byte* /))
				//{
				//	// increment the byte to go to the next ram location
				//	// perform a binary addition:
				//	for (unsigned short int ndx = 7; ndx >= 0/*insn_byte.size ()* //* && ndx < insn_part.size ()* /; --ndx)
				//	{
				//		insn_byte [ndx] = (insn_part [ndx] == '0' ? false : true);
				//	}
				//}
				
				
				// decode it
				// into the instruction class
				_insn = insn::decode (insn_code);
				*/
				
				// fetch 15 bytes, the maximum any instruction may be
				//insn_part = "";
				//insn_code = "";
				for (int short unsigned ndx = 0; ndx < 15; ++ndx, ++insn_ptr)
				{
					//get (_thread.id, insn_ptr, val);
					//code [ndx] = get (_thread.id, insn_ptr, val);
					get (_thread.id, insn_ptr, /*dest*/code [ndx]);
				}
				
				
				//code = (unsigned char const * const) (insn_code.c_str ());
				
				ci.code = code;
				ci.codeLen = sizeof (code);
				
				decodedInstructionsCount = 0;
				// decompose the instruction/s
				distorm_decompose (&ci, decodedInstructions, 1, &decodedInstructionsCount);
				
				
				// dump member variables
				//std::cerr << _insn.dump () << std::endl;
				
				
			//	// verify its validity
				//if (!_insn.deserialize (get (thread_name, /*std::string ("insn ") + */get (thread_name, "insn_ptr"))))
			//	if (!_insn.is_valid ()))
			//		//continue
			//		;
				
				if
				(
						 decodedInstructionsCount == 0
					//|| decodedInstructions.flags == FLAG_NOT_DECODABLE
				)
				{
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::x86_64::cycle()::insn::invalid" << std::endl;
					//continue;
				}
				else
				{
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::vos::srv::cpu::x86_64::cycle()::insn::valid" << std::endl;
					
					//thread_id = std::string ("thread ") + inst.thread_id;
					
					// execute it
					// evaluate it
					//assert (exe (_insn, insn_ptr, _thread.id));
					assert (exe (end, decodedInstructions [0]/*, insn_ptr*/, _thread));
					////val (inst);
					
					// TODO advance the instruction pointer
					// by the size of the just-executed instruction
					// (in bytes)
					_thread.insn_ptr += decodedInstructions [0].size;
				}
			}
			
			std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::x86_64::cycle()::stop/continue?" << std::endl;
				
				// advance the index
				//index_max = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, "index.max"/* key*/);
				//index = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, "index"/* key*/);
				
				// Preserve the user-chosen value when they customly set the index
				//if (inst.operation != "jmp")
				//	++index;
				
				
				//std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::exe()::index_max==[" << index_max << "]" << std::endl;
				//std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::exe()::index==[" << index << "]" << std::endl;
				//if (index.operator const unsigned long int () > index_max.operator const unsigned long int ())
			//	if (inst.next == "0")
			//	{
			//		std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::exe::stop::thread_name[" << thread_name << "]" << std::endl;
					//std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::exe::restart(reset)::thread_id[" << thread_id << "]" << std::endl;
					//assert (set (/*std::string ("thread ") + inst.*/thread_id/* group*/, "running"/* key*/, "0"/* value*/));
					//assert (clear (thread_id));
					//assert (set (/*std::string ("thread ") + inst.*/thread_id/* group*/, "index"/* key*/, "1"/* value*/));
			//	}
			//	else
			//	{
			//		std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::exe::continue" << std::endl;
			//		
			//		assert (set (/*std::string ("thread ") + inst.*/thread_name/* group*/, "index"/* key*/, inst.next/* value*/));
					//inst_next = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, std::string ("instr ") + index.operator const std::string ()/* key*/);
					
					//if (get (/*std::string ("thread ") + inst.*/thread_id/* group*/, "running"/* key*/) == "1")
					//	assert (enqueue (inst_next));
					//else
					//	assert (clear (/*std::string ("thread ") + inst.*/thread_id/* group*/));
			//		assert (enqueue (thread_name));
					
					//node.unicast (msg, inst.thread_id);
					//multival (msg, inst.thread_id);
					//map_thread.clear ();
					
					//boost::this_thread::sleep_for (boost::chrono::milliseconds (200));
			//	}
				
			//}
			//else
			//{
			//	std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::next_dequeue()::null instruction" << std::endl;
			//}
			
			if (end)
			{
				// clear up all the memory used by this thread
				//assert (clear (_thread.id));
			}
			else
			{
				// continue on running with the next instruction
				// (_thread.insn_ptr should, at this point,
				// refer to the beginning of the next instruction)
				assert (enqueue (_thread.serialize ()));
			}
		}
		
		///
		
		// increment/adjust pc
		//...
		
		//ir = fetch (pc);
		//exe (decode (ir));
		//exe (decode (fetch (pc)));
		
		///
		
		
		// make sure that any previously set 'true' value
		// is not read before any instruction is indeed enqueued,
		// then becoming available
		{
			//boost::lock_guard <boost::mutex> lock (_mutex);
			_insn_avail = false;
		}
		
		// wait for more instructions to become available (to become enqueued)
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::x86_64::cycle()::condition.wait(lock)ing" << std::endl;
		while (!_insn_avail)
		{
			_condition_instr_enqueued.wait (lock);
		}
		//boost::this_thread::sleep_for (boost::chrono::seconds (noten_delay_dft));
		//_mutex.lock ();
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::x86_64::cycle()::condition.wait(lock)ed" << std::endl;
		//std::cerr << "[" << boost::this_thread::get_id () << "]noware::smach::cpu::_mutex.lock()ed" << std::endl;
		
		
		// check if we are asked to stop
		try
		{
			boost::this_thread::interruption_point ();
		}
		//catch (...)
		catch (boost::thread_interrupted const &/* interruption*/)
		{
			std::cerr << "[" << boost::this_thread::get_id () << "] " << "noware::smach::cpu::x86_64::cycle()::interruption_point()::caught boost::thread_interrupted" << std::endl;
			
			// ...stop
			break;
		}
	}
	
	//_condition_instr_enqueued.notify_all ();
}
