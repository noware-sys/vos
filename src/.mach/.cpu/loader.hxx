class loader
	: virtual public dev
{
	public:
		virtual const bool load_file (const std::string &/* file_name*/);
		
		
		// Store functionality
		
		virtual const std::string/* value*/ get (const std::string &/* group*/, const std::string &/* key*/) const;
		virtual const std::string/* value*/ get (const std::string &/* key*/) const;
		
		virtual const bool/* success*/ set (const std::string &/* group*/, const std::string &/* key*/, const std::string &/* content/value*/);
		virtual const bool/* success*/ set (const std::string &/* key*/, const std::string &/* content/value*/);
		
		
		// Queue functionality
		
		virtual const bool enqueue (const cpu::instr &);
		
		
		// Device functionality
		
		virtual const bool/* success*/ search (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/, const std::string &/* src*/, const net::cast &/* src_cast*/);// const
};
