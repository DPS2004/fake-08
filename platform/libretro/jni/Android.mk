
LOCAL_PATH := $(call my-dir)

CORE_DIR := $(LOCAL_PATH)/

include $(CORE_DIR)/Makefile.common

COREFLAGS := -DANDROID -D__LIBRETRO__ -Wall -Wno-deprecated -ffunction-sections -std=c++17 -fno-rtti -fexceptions  $(INCFLAGS)


include $(CLEAR_VARS)

LOCAL_MODULE        := fake_08_libretro
LOCAL_CPP_EXTENSION := .cpp .c
LOCAL_SRC_FILES     := $(SOURCES_CXX)
LOCAL_C_INCLUDES    := $(MY_INCLUDES)
LOCAL_CXXFLAGS      := $(COREFLAGS)
LOCAL_LDFLAGS       := -Wl

include $(BUILD_SHARED_LIBRARY)
