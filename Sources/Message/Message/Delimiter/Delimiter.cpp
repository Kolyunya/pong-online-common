#include <Message/Message/Delimiter/Delimiter.hpp>
#include <Message/MessageHeader/MessageHeader.hpp>

Delimiter::Delimiter ( void )
{
    this->initializeData();
}

void Delimiter::initializeHeader ( void )
{
    this->header = MessageHeader::DelimiterHeader;
}
