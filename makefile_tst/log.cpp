#include <stdio.h>
#include "log.h"

log::log()
{
}

log::~log()
{
}

void log::output(const char* content)
{
    printf("%s\n", content);
}
