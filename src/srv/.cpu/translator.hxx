class translator
	//: virtual public dev
{
	public:
		//std::string const read (std::string const &/* file_name*/) virtual;
		//bool const write (std::string const &/* file_name*/) virtual;
		
		//bool const load (std::string const &/* file_name*/) virtual;
		std::string const translate (std::string const &/* content*/) static virtual;
	protected:
		std::string const translate_single (std::string const &/* instruction*/) static virtual;
};
