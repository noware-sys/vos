LIB::machine::device::processor::instructions::instructions (void)
{
	//active = true;
	//processing = false;

	//inputs [0] = inputs [1] = 0;
	//instructions [0] = instructions [1] = "";

	//user = "Guest";	// The default user.
}

LIB::machine::device::processor::instructions::instructions (const instructions & other)
{
	//operator= (other);
	instructions_ = other.instructions_;
}

template <typename Archive>
void LIB::machine::device::processor::instructions::serialize (Archive & archive, const unsigned int & version)
{
	//archive & _instructions;

	//archive & user;
}

LIB::machine::device::processor::instructions::operator std::string (void)
{
	return LIB::serialize <LIB::machine::device::processor::instructions> (*this);
}

LIB::machine::device::processor::instructions LIB::machine::device::processor::instructions::operator = (const std::string & serial)
{
	LIB::deserialize <LIB::machine::device::processor::instructions> (serial, *this);

	return *this;
}

LIB::machine::device::processor::instructions LIB::machine::device::processor::instructions::operator = (const LIB::machine::device::processor::instructions & other)
{
	instructions_ = other.instructions_;
	
	return *this;
}

