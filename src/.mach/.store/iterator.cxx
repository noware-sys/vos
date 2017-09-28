#pragma once

template <typename value>
virtual const iterator <value> noware::mach::storage::iterator::begin (void) const
{
}

template <typename value>
virtual const iterator <value> noware::mach::storage::iterator::end (void) const
{
}

template <typename value>
virtual const iterator <value> noware::mach::storage::iterator::operator ++ (void)
{
}

template <typename value>
virtual const iterator <value> noware::mach::storage::iterator::operator -- (void)
{
}

template <typename value>
virtual const bool noware::mach::storage::iterator::operator == (const iterator <value> & other) const
{
}

template <typename value>
virtual const value noware::mach::storage::iterator::operator * (void) const
{
}
