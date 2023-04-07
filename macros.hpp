#ifndef MACROS_HPP
#define MACROS_HPP

#ifdef _WIN32
#define CLEAR()\
system("cls")
#endif

#ifdef __linux__
#include <term.h>
#define CLEAR()\
setupterm(NULL, fileno(stdout), NULL);\
putp(tigetstr("clear"))
#endif


#endif