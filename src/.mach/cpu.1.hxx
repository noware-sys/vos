//#pragma once

//namespace noware
//{
	//namespace machine
	//{
		// processor cpu
		// thread task job
		class cpu
			: public dev
		{
			public:
				enum class opr
				{
					none,
					// For controlling the flow of the execution:
					// and intersection
					// or union
					
					obtainment,	// attainment obtainment get read
					assignment,	// assignment settlement set write
					//presence,
					removal,		// removal resettal
					
					addition,
					substraction,
					multiplication,
					division,
					
					exponentiation
					modulo,
					modulus,
					complement,
					
					//cat,				// concatenate
					
					//output		// output set echo
					//go,			// go[[ ]to] skip jump hop
				};
				
				class instr
				{
					public:
						instr (void);
						virtual ~instr (void);
						
						opr oprn;	// Optional.
						//noware::var operand1;
						//noware::var operand2;	// Optional.
						noware::var oprnd [2];
						
						//dependents;	// Not really needed.
						//dependencies;
						
						//const bool operator== (const instruction &/* other*/) const;
						virtual const noware::var /*e*/val/*uate*/ (void) const;
						
						virtual const bool deserialize (const std::string &);
						virtual const std::string serialize (void) const;
				};
				
				cpu (void);
				virtual ~cpu (void);
			protected:
				// dequeue beginning first head top pop next fetch operate
				virtual const instr next (void) const;
				virtual const bool dequeue (void);
				//const instruction dequeue (void);
			public:
				virtual const noware::nr size (void) const;
				virtual const bool empty (void) const;
				virtual const bool full (void) const;
				
				virtual const bool enqueue (const instr &);
				//const bool enqueue (const operation &/* operator*/, const noware::var &/* operand1*/, const noware::var &/* operand2*/ = "");	// Accurate.
				virtual const bool enqueue (const noware::var &/* operand1*/, const operation &/* operator*/ = operation::none, const noware::var &/* operand2*/ = "");	// Convenient.
				// do perform execute apply evaluate
				//const bool apply (const instruction &);
			protected:
				virtual const bool/* success*/ respond (const zyre_event_t */* (zyre) event*/);
				virtual const bool/* success*/ search (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/);// const
				virtual const bool/* success*/ search_local (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/);// const
				virtual const zmq::msg/* result*/ aggregate (const zmq::msg &/* result*/, const noware::nr &/* responses_count*//* number of peers who answered*/, const zmq::msg &/* response*/, const zmq::msg &/* expression*/);
			protected:
				// Process/Find/Search for/ the next instruction on-the-fly.
				// Do not store an instruction queue.
				//std::queue <instruction> queue;
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
*/
