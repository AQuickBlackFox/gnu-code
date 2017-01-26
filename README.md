# gnu-code
Code related to Linux development


## Notes
### Position Independent Code (PIC)
PIC stands for position-independent code. The functions in a shared library may be loaded at different
addresses in different programs, so the code in the shared object must not depend on the address (or
position) at which it is loaded. This consideration has no impact on you, as the programmer, except that
you must remember to use the -fPIC flag when compiling code that will be used in a shared library
