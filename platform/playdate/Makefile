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


SRC +=  source/pdnewlib.c
SRC +=  source/playdateHost.cpp

SRC +=  ../../source/vm.cpp
	SRC +=  ../../source/graphics.cpp
		SRC +=  ../../source/nibblehelpers.cpp
		SRC +=  ../../source/mathhelpers.cpp
		SRC +=  ../../source/stringToDataHelpers.cpp
	SRC +=  ../../source/picoluaapi.cpp
		SRC +=  ../../source/Input.cpp
		SRC +=  ../../source/printHelper.cpp
		
	SRC +=  ../../source/fontdata.cpp
	SRC +=  ../../source/cart.cpp

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
