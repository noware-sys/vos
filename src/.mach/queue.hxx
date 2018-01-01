#pragma once

//namespace noware
//{
	//namespace machine
	//{
		class queue
			//: virtual public dev
			: virtual public cluster::node
		{
			public:
				queue (void);
				virtual ~queue (void);
				
				virtual const bool start (void);
				
				static const std::string grp_dft;
				
				// dequeue beginning first head top pop next current present fetch operate
				virtual const std::string next (void) const;
				// get the next element and dequeue
				virtual const std::string next_dequeue (void);
				virtual const bool dequeue (void);
				virtual const bool enqueue (const std::string &/* element*/);
				virtual const noware::nr count (void) const;
				virtual const bool empty (void) const;
				virtual const bool empty_local (void) const;
				virtual const bool full (void) const;
				virtual const bool full_local (void) const;
				
			protected:
				virtual const bool/* success*/ respond (zmq::msg &/* response*/, const zmq::msg &/* rx'd*/, const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const std::string &/* src*/, const net::cast &/* src_cast*/);
				virtual const bool/* success*/ respond_post (const zmq::msg &/* response (read-only)*/, const zmq::msg &/* rx'd*/, const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const std::string &/* src*/, const net::cast &/* src_cast*/, const bool &/* result*/);
				virtual const bool/* success*/ search (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/, const noware::nr &/* total, expected resonses count*/, const noware::nr &/* current count of peers who responded (so far)*/, const std::string &/* src*/, const net::cast &/* src_cast*/);// const
				virtual const bool/* success*/ search_local (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/, const std::string &/* src*/, const net::cast &/* src_cast*/);// const
				virtual const zmq::msg/* result*/ aggregate (const zmq::msg &/* result*/, const zmq::msg &/* response*/, const zmq::msg &/* expression*/, const noware::nr &/* responses_count*//* number of peers who answered*/, const std::string &/* src*/, const net::cast &/* src_cast*/);
				
			protected:
				std::queue <std::string> queue;
		};
	//}
//}

/*
	{
		(ins(req()));
		(ins(req()));
		(ins(req()));
	}
*/

/*
	activity
	{
		process (exp (ins));
		process (exp (ins));
		process (exp (ins));
	}
*/

/*
	activity
	{
		process (operation (instruction ...) ...);
		process (operation (instruction ...) ...);
		process (operation (instruction ...) ...);
	}
*/

/*
	main activity
	# parallel
	{
		sub activity / action ...
		# parallel
		{
			process
			# serial
			{
				operation ...
				# parallel or serial
				{
					instruction; ...
				}
			}
		}
	}
*/

/*
	
	{
		# parallel
		{
			process
			{
				# serial
				{
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
					
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
					
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
				};
			};
			
			process
			{
				# serial
				{
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
					
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
					
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
				};
			};
			
			process
			{
				# serial
				{
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
					
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
					
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
				};
			};
		};
	};
*/
