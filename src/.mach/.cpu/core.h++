// Computational platform.
class core
{
	//protected:
		//bool ended;
	
	public:
		core (const bool & = processor::default_state);
		~core (void);
		
		// const core operator = (const core &);
		
		//const bool active (void) const;
		
		// Non-blocking:
		// To control the state.
		//void run (const bool = true);
		
		// Blocking:
		// To pause the target/worker thread until it is set to `run ([true])` again.
		//void pause (void);
		
		// Active state getter.
		const bool active (void) const;
		// Active state setter.
		const bool run (const bool & = true);
	protected:
		boost::thread * thread;
		//boost::thread thread (boost::bind (& LIB::machine::resources::processor::perform, this));
		
		bool running;
		
		void perform (void);
		const bool execute (const instruction &);
		void pause (void) const;
		
		// LIB::machine::resources::processor * processor;
		
		//bool _active;
		// Activity's state.
		//std::mutex activity;
		
		// LIB::Pointer <boost::thread> thread;
		//LIB::NAME_A <LIB::machine::devices::processor::instruction, LIB::mathematics::numbers::natural> queue;
		// std::queue <instruction> queue;
};

