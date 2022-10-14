#include <iostream>
#include <dotenv.h>

int main()
{
    dotenv::init();

    std::cout << std::getenv("TESTE") << std::endl;
    return 0;
}
