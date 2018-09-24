void noware::smach::cpu::x86_64::cycle (void)
{
	std::cerr << "noware::smach::cpu::x86_64::cycle()::in scope" << std::endl;
	
	/*vmach::cpu::x86_64::*/insn _insn;
	//std::string inst_curr;
	//std::string insn_ptr;
	//std::string inst_next;
	
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
	/*
	bool result_offset_prefetch_visited;
	bool dest_offset_prefetch_visited;
	bool src_offset_prefetch_visited;
	
	bool result;
	*/
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
	
	/*
	result = false;
	
	result_offset_prefetch_visited = false;
	dest_offset_prefetch_visited = false;
	src_offset_prefetch_visited = false;
	*/
	
	//// program counter
	//unsigned int pc;
	
	
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
			if (!_thread.deserialize (next_dequeue ()))
				//continue
				;
			
			// dump member variables
			//std::cerr << _thread.dump () << std::endl;
			
			// decode
			//index = get (thread_name, "index");
			//if (!_insn.deserialize (get (thread_name, /*std::string ("insn ") + */get (thread_name, "insn_ptr"))))
			if (!_insn.decode (get (_thread.id, _thread.insn_ptr))))
				//continue
				;
			
			// dump member variables
			//std::cerr << _insn.dump () << std::endl;
			
			//if (!inst.null ())
			//{
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::x86_64::cycle()::next_dequeue()::valid instruction" << std::endl;
				
				//thread_id = std::string ("thread ") + inst.thread_id;
				
				// execute
				// evaluate
				exe (_insn, _thread);
				//val (inst);
				
				
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
		}
		
		///
		
		// increment/adjust pc
		//...
		
		//ir = fetch (pc);
		//exe (decode (ir));
		//exe (decode (fetch (pc)));
		
		///
		
		
		// Make sure that any previously set 'true' value
		// is not read before any instruction is indeed enqueued,
		// becoming available.
		{
			//boost::lock_guard <boost::mutex> lock (_mutex);
			_insn_avail = false;
		}
		
		// Wait for more instructions to become available (be enqueued).
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::x86_64::cycle()::condition.wait(lock)ing" << std::endl;
		//boost::this_thread::interruption_point ();
		while (!_insn_avail)
		{
			_condition_instr_enqueued.wait (lock);
		}
		//boost::this_thread::sleep_for (boost::chrono::seconds (noten_delay_dft));
		//_mutex.lock ();
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::x86_64::cycle()::condition.wait(lock)ed" << std::endl;
		//std::cerr << "[" << boost::this_thread::get_id () << "]noware::smach::cpu::_mutex.lock()ed" << std::endl;
		
		
		try
		{
			boost::this_thread::interruption_point ();
		}
		//catch (...)
		catch (boost::thread_interrupted const &/* interruption*/)
		{
			std::cerr << "[" << boost::this_thread::get_id () << "] " << "noware::smach::cpu::x86_64::cycle()::interruption_point()::caught boost::thread_interrupted" << std::endl;
			break;
		}
	}
	
	//_condition_instr_enqueued.notify_all ();
}
