#include <ace/OS.h>
#include <ace/Log_Msg.h>

#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;

    ACE_DEBUG((LM_DEBUG,"Hello, ACE!\n "));
    ACE_OS::exit(1);

    return 0;
}