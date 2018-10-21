#pragma once

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
			inst.deserialize (next_dequeue ());
			
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
				
				if (inst.dest_key != "index")	// Preserve the user-chosen value when they customly set the index
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
			//boost::this_thread::sleep_for (boost::chrono::seconds (noten_delay_dft));
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
