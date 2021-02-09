#include "../HeaderFiles/Guest.h"

void Guest::execute()
{
    
    cout << "I am " << threadObj.get_id() << " answering the call!" << std::endl;
    
}

void Guest::start()
{
    threadObj = thread(&Guest::execute, this);
}
