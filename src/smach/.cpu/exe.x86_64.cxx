#pragma once

void noware::smach::cpu::exe (void)
{
	std::cerr << "noware::smach::cpu::exe()::in scope" << std::endl;
	
	/*vmach::cpu::*/x86_64::instr inst;
	std::string inst_next;
	
	cln::nr index_max;
	cln::nr index;
	
	//noware::var src;
	//noware::var dest;
	
	//noware::var src_offset;
	//noware::var dest_offset;
	
	//std::string separator;
	//std::string input;
	
	std::string thread_id;
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
	
	while (true)
	//while (_running)
	//while (!boost::this_thread::interruption_requested ())
	{
		std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::exe()::while(true)::in scope" << std::endl;
		//std::cerr << "noware::smach::cpu::exe()::while(_running)::in scope" << std::endl;
		
		//std::cerr << "noware::smach::cpu::exe()::empty()==[" << empty () << "]==noware::smach::cpu::exe()::empty()" << std::endl;
		while (!empty ())
		{
			std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::exe()::while(!empty())::in scope" << std::endl;
			
			// fetch the next instruction, dequeuing it, and decoding (deserializing) it
			std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::next_dequeue()" << std::endl;
			inst.deserialize (next_dequeue ());
			
			// dump member variables
			//inst.dump ();
			
			if (!inst.null ())
			{
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::next_dequeue()::valid instruction" << std::endl;
				
				thread_id = std::string ("thread ") + inst.thread_id;
				
				// execute;
				// evaluate
				val (inst);
				
				
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::exe::stop/continue?" << std::endl;
				
				// advance the index
				index_max = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, "index.max"/* key*/);
				index = get (/*std::string ("thread ") + inst.*/thread_id/* group*/, "index"/* key*/);
				
				// Preserve the user-chosen value when they customly set the index
				//if (inst.operation != "jmp")
					++index;
				
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::exe()::index_max==[" << index_max << "]" << std::endl;
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::exe()::index==[" << index << "]" << std::endl;
				if (index.operator const unsigned long int () > index_max.operator const unsigned long int ())
				{
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::exe::stop(clear)::thread_id[" << thread_id << "]" << std::endl;
					//std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::exe::restart(reset)::thread_id[" << thread_id << "]" << std::endl;
					//assert (set (/*std::string ("thread ") + inst.*/thread_id/* group*/, "running"/* key*/, "0"/* value*/));
					//assert (clear (thread_id));
					//assert (set (/*std::string ("thread ") + inst.*/thread_id/* group*/, "index"/* key*/, "1"/* value*/));
				}
				else
				{
					std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::exe::continue" << std::endl;
					
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
				std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::next_dequeue()::null instruction" << std::endl;
			}
		}
		
		//std::cerr << "noware::smach::cpu::exe()::while(!empty())::in scope" << std::endl;
		
		//std::cerr << "noware::smach::cpu::exe()::empty()" << std::endl;
		
		//std::cerr << "[" << boost::this_thread::get_id () << "]noware::smach::cpu::sleeping..." << std::endl;
		//boost::this_thread::sleep_for (boost::chrono::seconds (3));
		//std::cerr << "[" << boost::this_thread::get_id () << "]noware::smach::cpu::exe::_mutex.lock()" << std::endl;
		//_mutex.lock ();
		
		{
			//boost::lock_guard <boost::mutex> lock (_mutex);
			_insn_avail = false;
		}
		
		try
		{
			std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::exe::condition.wait(lock)ing" << std::endl;
			//boost::this_thread::interruption_point ();
			while (!_insn_avail)
			{
				_condition_instr_enqueued.wait (lock);
			}
			//boost::this_thread::sleep_for (boost::chrono::seconds (noten_delay_dft));
			//_mutex.lock ();
			std::cerr << "[" << boost::this_thread::get_id () << "] noware::smach::cpu::exe::condition.wait(lock)ed" << std::endl;
			//std::cerr << "[" << boost::this_thread::get_id () << "]noware::smach::cpu::_mutex.lock()ed" << std::endl;
		}
		catch (const boost::thread_interrupted &/* interruption*/)
		{
			std::cerr << "[" << boost::this_thread::get_id () << "] " << "noware::smach::cpu::exe::condition.wait()::caught boost::thread_interrupted" << std::endl;
			break;
		}
		
		
		try
		{
			boost::this_thread::interruption_point ();
		}
		catch (...)
		//catch (const boost::thread_interrupted &/* interruption*/)
		{
			std::cerr << "[" << boost::this_thread::get_id () << "] " << "noware::smach::cpu::exe::interruption_point()::caught boost::thread_interrupted" << std::endl;
			break;
		}
	}
	
	//_condition_instr_enqueued.notify_all ();
}
