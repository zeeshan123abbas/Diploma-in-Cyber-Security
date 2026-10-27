#include "utils.h"

// returns 1 if port is between 0 and 65535, otherwise 0
int isValidPort(int port)
{
    return port >= 0 && port <= 65535;
}
