# Voidworks Legacy

Reverse engineering research project loosely attempting to create a modding framework for DS3


## Legacy?

This is a **nonfunctional**, pruned version of the original Voidworks for archival and academic purposes

Offsets have been zeroed out and the spiciest parts have been removed

Mainline Voidworks is being reworked into a more generic modding tool


## Usage

The following is an example of a simple DS3 mod that turns the game window borderless using Voidworks

```c++
#include <voidworks.h>

BOOL WINAPI DllMain(HINSTANCE baseaddr, DWORD reason, BOOL isstatic) {
  SetWindowBorderless();
  return 1;
}
```

More comprehensive examples can be found in [examples/](examples/)


## Contributors

See [AUTHORS.md](AUTHORS.md)
