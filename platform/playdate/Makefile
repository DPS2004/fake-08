ifeq ($(HEAP_SIZE),)
HEAP_SIZE      = 8388208
endif
ifeq ($(STACK_SIZE),)
STACK_SIZE     = 61800
endif

ifeq ($(PRODUCT),)
PRODUCT = TestCPP.pdx
endif

SELF_DIR := $(dir $(lastword $(MAKEFILE_LIST)))

SDK = ${PLAYDATE_SDK_PATH}
ifeq ($(SDK),)
SDK = $(shell egrep '^\s*SDKRoot' ~/.Playdate/config | head -n 1 | cut -c9-)
endif

ifeq ($(SDK),)
$(error SDK path not found; set ENV value PLAYDATE_SDK_PATH)
endif

VPATH +=

# List C/C++ source files here




SRC +=  source/main.cpp

SRC +=  ../../libs/z8lua-pd/eris.c
SRC +=  ../../libs/z8lua-pd/lapi.c
SRC +=  ../../libs/z8lua-pd/lauxlib.c
SRC +=  ../../libs/z8lua-pd/lbaselib.c
SRC +=  ../../libs/z8lua-pd/lbitlib.c
SRC +=  ../../libs/z8lua-pd/lcode.c
SRC +=  ../../libs/z8lua-pd/lcorolib.c
SRC +=  ../../libs/z8lua-pd/lctype.c
SRC +=  ../../libs/z8lua-pd/ldblib.c
SRC +=  ../../libs/z8lua-pd/ldebug.c
SRC +=  ../../libs/z8lua-pd/ldo.c
SRC +=  ../../libs/z8lua-pd/ldump.c
SRC +=  ../../libs/z8lua-pd/lfunc.c
SRC +=  ../../libs/z8lua-pd/lgc.c
SRC +=  ../../libs/z8lua-pd/linit.c
SRC +=  ../../libs/z8lua-pd/liolib.c
SRC +=  ../../libs/z8lua-pd/llex.c
SRC +=  ../../libs/z8lua-pd/lmem.c
SRC +=  ../../libs/z8lua-pd/loadlib.c
SRC +=  ../../libs/z8lua-pd/lobject.c
SRC +=  ../../libs/z8lua-pd/lopcodes.c
SRC +=  ../../libs/z8lua-pd/loslib.c
SRC +=  ../../libs/z8lua-pd/lparser.c
SRC +=  ../../libs/z8lua-pd/lpico8lib.c
SRC +=  ../../libs/z8lua-pd/lstate.c
SRC +=  ../../libs/z8lua-pd/lstring.c
SRC +=  ../../libs/z8lua-pd/lstrlib.c
SRC +=  ../../libs/z8lua-pd/ltable.c
SRC +=  ../../libs/z8lua-pd/ltablib.c
SRC +=  ../../libs/z8lua-pd/ltests.c
SRC +=  ../../libs/z8lua-pd/ltm.c
SRC +=  ../../libs/z8lua-pd/lundump.c
SRC +=  ../../libs/z8lua-pd/lvm.c
SRC +=  ../../libs/z8lua-pd/lzio.c




SRC +=  source/pdnewlib.c
SRC +=  source/playdateHost.cpp

SRC +=  ../../source/vm.cpp
	SRC +=  ../../source/graphics.cpp
		SRC +=  ../../source/nibblehelpers.cpp
		SRC +=  ../../source/mathhelpers.cpp
		SRC +=  ../../source/stringToDataHelpers.cpp
		SRC +=  ../../source/Input.cpp
		SRC +=  ../../source/printHelper.cpp
		
	SRC +=  ../../source/fontdata.cpp
	SRC +=  ../../source/cart.cpp
	SRC +=  ../../source/picoluaapi.cpp
	SRC +=  ../../source/emojiconversion.cpp

SRC +=  ../../source/logger.cpp
SRC +=  ../../source/Audio.cpp



# List all user directories here
UINCDIR += ../../source
UINCDIR += ../../libs/lodepng
UINCDIR += ../../libs/z8lua-pd

# List all user C/C++ define here, like -D_DEBUG=1
UDEFS += -D__PLAYDATE__

# Define ASM defines here
UADEFS += -D__PLAYDATE__

# List the user directory to look for the libraries here
ULIBDIR +=

# List all user libraries here
ULIBS += 

#CLANGFLAGS = -fsanitize=address

include C_API_EDIT/buildsupport/common.mk
