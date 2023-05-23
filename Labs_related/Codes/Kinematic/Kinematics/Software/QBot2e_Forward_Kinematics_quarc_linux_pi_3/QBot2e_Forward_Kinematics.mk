# Copyright 2019 Quanser, Inc.
#
# File    : quarc_linux_pi_3.tmf
#
# Abstract:
#	Real-Time Workshop template makefile for building a Linux ARM-based
#	stand-alone real-time version of Simulink model using
#	generated C code.
#
# 	This makefile attempts to conform to the guidelines specified in the
# 	IEEE Std 1003.2-1992 (POSIX) standard. It is designed to be used
#       with GNU Make which is located in matlabroot/rtw/bin.
#
# 	Note that this template is automatically customized by the Real-Time
#	Workshop build procedure to create "<model>.mk"
#
#   The following defines can be used to modify the behavior of the build:
#     OPT_OPTS       - Optimization options. Default is -O.
#     CPP_OPTS       - C++ compiler options.
#     OPTS           - User specific compile options.
#     USER_SRCS      - Additional user sources, such as files needed by
#                      S-functions.
#     USER_INCLUDES  - Additional include paths
#                      (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#       To enable debugging:
#         set DEBUG_BUILD = 1 below, which will trigger OPTS=-g and
#          LDFLAGS += -g (may vary with compiler version, see compiler doc)
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see quarc_linux_pi_3.tlc

#------------------------ Macros read by make_rtw ------------------------------
#
# The following macros are read by the Real-Time Workshop build procedure:
#
#  MAKECMD          - This is the command used to invoke the make utility
#  MAKEFILE_FILESEP - Replaces all instances of the current file separator 
#                     with the given one. See help for updateFileSeparator.
#  HOST             - What platform this template makefile is targeted for
#                     (i.e. PC or UNIX)
#  BUILD            - Invoke make from the Real-Time Workshop build procedure
#                     (yes/no)?
#  SYS_TARGET_FILE  - Name of system target file.

MAKECMD          = make
MAKEFILE_FILESEP = /
HOST             = PC
BUILD            = yes
SYS_TARGET_FILE  = quarc_linux_pi_3.tlc
BUILD_SUCCESS    = \#\#\# Created

#---------------------- Tokens expanded by make_rtw ----------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# Real-Time Workshop build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to where MATLAB is installed.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link.
#  NUMST               - Number of sample times
#  TID01EQ             - yes (1) or no (0): Are sampling rates of continuous task
#                        (tid=0) and 1st discrete task equal.
#  NCSTATES            - Number of continuous states
#  COMPUTER            - Computer type. See the MATLAB computer command.
#  BUILDARGS           - Options passed in at the command line.
#  MULTITASKING        - yes (1) or no (0): Is solver mode multitasking
#  MAT_FILE            - yes (1) or no (0): Should mat file logging be done
#  GEN_MDLREF_SFCN     - (1/0): are we generating model reference wrapper s-function
#  TGT_FCN_LIB         - Target Funtion library to use
#  MODELREFS           - List of referenced models

MODEL                = QBot2e_Forward_Kinematics
MODULES              = QBot2e_Forward_Kinematics_data.c QBot2e_Forward_Kinematics_main.c rtGetInf.c rtGetNaN.c rt_nonfinite.c
MAKEFILE             = QBot2e_Forward_Kinematics.mk
MATLAB_ROOT          = C:/Program Files/MATLAB/R2019b
ALT_MATLAB_ROOT      = C:/PROGRA~1/MATLAB/R2019b
MATLAB_BIN           = C:/Program Files/MATLAB/R2019b/bin
MASTER_ANCHOR_DIR    = 
START_DIR            = C:/Users/thien/DOCUME~1/ACADEM~1/79CE6~1.AUT/AUTONO~1/LABS_R~1/Codes/KINEMA~1/KINEMA~1/Software
S_FUNCTIONS_LIB      = C:/PROGRA~1/Quanser/QUARC/lib/LICFC8~1/libhil.a C:/PROGRA~1/Quanser/QUARC/lib/LICFC8~1/LI5A2F~1.A C:/PROGRA~1/Quanser/QUARC/lib/LICFC8~1/LIBQUA~4.A
NUMST                = 2
TID01EQ              = 1
NCSTATES             = 8
COMPUTER             = PCWIN64
BUILDARGS            =  EXT_MODE=1 EXTMODE_STATIC_ALLOC=0 TMW_EXTMODE_TESTING=0 EXTMODE_STATIC_ALLOC_SIZE=1000000 EXTMODE_TRANSPORT=0 SHOW_TIMES=0 STRIPSYMBOLS=0 DEBUG=0 DEBUG_HEAP=0 INCLUDE_MDL_TERMINATE_FCN=1 ISPROTECTINGMODEL=NOTPROTECTING OPTS="-DEXT_MODE -DON_TARGET_WAIT_FOR_START=0"
MULTITASKING         = 0
MAT_FILE             = 0
TGT_FCN_LIB          = None
MODELREFS            = 
TARGET_LANG_EXT      = c
OPTIMIZATION_FLAGS   = 
ADDITIONAL_LDFLAGS   = 
DEFINES_CUSTOM       = 
SYSTEM_LIBS          = 
CODE_INTERFACE_PACKAGING = Nonreusable function

CLASSIC_INTERFACE    = 1
# Optional for GRT
ALLOCATIONFCN        = 0
ONESTEPFCN           = 0
TERMFCN              = 1
MULTI_INSTANCE_CODE  = 0

# To enable debugging:
# set DEBUG_BUILD = 1
DEBUG_BUILD          = 0

#--------------------------- Model and reference models -----------------------
MODELLIB                  = 
MODELREF_LINK_LIBS        = 
RELATIVE_PATH_TO_ANCHOR   = ..
# NONE: standalone, SIM: modelref sim, RTW: modelref rtw
MODELREF_TARGET_TYPE       = NONE

#--------------------------- Additional options -------------------------------

ASSERTACTION     = "Stop model with an error"
HAVESTDIO        =  1
   
#-- In the case when directory name contains space ---
ifneq ($(MATLAB_ROOT),$(ALT_MATLAB_ROOT))
MATLAB_ROOT := $(ALT_MATLAB_ROOT)
endif

#--------------------------- Tool Specifications -------------------------------

include $(QUARC)/include/linux_pi_3_tools.mk

#------------------------------ Include Path -----------------------------------

# Additional file include paths

ADD_INCLUDES:=$(ADD_INCLUDES);$(START_DIR)
ADD_INCLUDES:=$(ADD_INCLUDES);$(START_DIR)/QBot2e_Forward_Kinematics_quarc_linux_pi_3
ADD_INCLUDES:=$(ADD_INCLUDES);$(MATLAB_ROOT)/extern/include
ADD_INCLUDES:=$(ADD_INCLUDES);$(MATLAB_ROOT)/simulink/include
ADD_INCLUDES:=$(ADD_INCLUDES);$(MATLAB_ROOT)/rtw/c/src
ADD_INCLUDES:=$(ADD_INCLUDES);$(MATLAB_ROOT)/rtw/c/src/ext_mode/common
ADD_INCLUDES:=$(ADD_INCLUDES);$(MATLAB_ROOT)/toolbox/coder/rtiostream/src
ADD_INCLUDES:=$(ADD_INCLUDES);$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils
ADD_INCLUDES:=$(ADD_INCLUDES);C:/PROGRA~1/Quanser/QUARC/include

QUARC_INCLUDES=$(QUARC)/include

CPATH:=;$(RELATIVE_PATH_TO_ANCHOR);$(QUARC_INCLUDES);$(ADD_INCLUDES);$(USER_INCLUDES);$(INSTRUMENT_INCLUDES)

ifneq ($(SHARED_SRC_DIR),)
CPATH:=$(CPATH);$(SHARED_SRC_DIR)
endif

export CPATH

#----------------------------- Real-Time Model ---------------------------------
RTM_CC_OPTS = -DUSE_RTMODEL

#-------------------------------- C Flags --------------------------------------

# Optimization Options
ifndef OPT_OPTS
OPT_OPTS = $(DEFAULT_OPT_OPTS)
endif

# Required Options
REQ_OPTS = -march=armv8-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon-vfpv4 \
           -Wall -fmessage-length=0 -MMD -MP -fpic -feliminate-unused-debug-types

# General User Options
ifeq ($(DEBUG_BUILD),0)
DBG_FLAG =
else
#   Set OPTS=-g and any additional flags for debugging
DBG_FLAG = -g
LDFLAGS += -g
endif

OPTS = -Wno-unused-but-set-variable -Wno-unused-variable

# Compiler options, etc:
ifneq ($(OPTIMIZATION_FLAGS),)
CC_OPTS = $(REQ_OPTS) $(OPTS) $(RTM_CC_OPTS) $(OPTIMIZATION_FLAGS)
else
CC_OPTS = $(OPT_OPTS) $(REQ_OPTS) $(OPTS) $(RTM_CC_OPTS)
endif

ifeq ($(ASSERTACTION), "Ignore")
  ASSERT_DEFINES = -DASSERTIONS=0
else 
  ifeq ($(ASSERTACTION), "Stop model with an error")
    ASSERT_DEFINES = -DASSERTIONS=1 -DDOASSERTS
  else 
    ifeq ($(ASSERTACTION), "Print assertion")
      ASSERT_DEFINES = -DASSERTIONS=2 -DDOASSERTS
    endif
  endif
endif

ifeq ($(HAVESTDIO),1)
STDIO_DEFINES = -DHAVESTDIO
else
STDIO_DEFINES =
endif

CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DRT -DNUMST=$(NUMST) \
                  -DTID01EQ=$(TID01EQ) -DNCSTATES=$(NCSTATES) \
                  -DMULTITASKING=$(MULTITASKING) $(STDIO_DEFINES) -DMAT_FILE=$(MAT_FILE) \
                  -DVXWORKS -DQUARC -D_GNU_SOURCE -DTARGET_TYPE=linux_pi_3 -D_RASPBERRY_PI -D_RASPBERRY_PI_3 \
                  -DONESTEPFCN=$(ONESTEPFCN) -DTERMFCN=$(TERMFCN) \
		          -DMULTI_INSTANCE_CODE=$(MULTI_INSTANCE_CODE) \
		          -DCLASSIC_INTERFACE=$(CLASSIC_INTERFACE) \
		          -DALLOCATIONFCN=$(ALLOCATIONFCN) \
                  $(ASSERT_DEFINES) $(OPT_DEFINES)

CFLAGS   = $(SYSROOT) $(CC_OPTS) $(ANSI_OPTS) $(DEFINES_CUSTOM) $(CPP_REQ_DEFINES) $(INCLUDES)
CPPFLAGS = $(SYSROOT) $(CPP_OPTS) $(CC_OPTS) $(CPP_ANSI_OPTS) $(DEFINES_CUSTOM) $(CPP_REQ_DEFINES) $(INCLUDES)
LDFLAGS := $(SYSROOT) $(LDFLAGS) -Wl,--hash-style=gnu -Wl,--as-needed -L$(QUARC)/lib/linux_pi_3

#-------------------------- Additional Libraries ------------------------------

# rtwmakecfg mechanism appears to fail for the Linux ARM target since the S_FUNCTIONS_LIB
# macro is not generated correctly. This shortcoming appears to be a bug in RTW.
# Hence, add additional libraries required here.

QUARC_LIBS = \
	-lextmode_quarc_r2013b \
	-lquanser_communications \
	-lquanser_runtime \
	-lquanser_common

SYSTEM_LIBS += $(QUARC_LIBS) -lrt -lpthread -ldl -lm

LIBS =
 

# See rtwmakecfg.m documentation

LIBS += $(S_FUNCTIONS_LIB) $(INSTRUMENT_LIBS)

#----------------------------- Source Files ------------------------------------

USER_SRCS =

USER_OBJS       = $(addsuffix .o, $(basename $(USER_SRCS)))
LOCAL_USER_OBJS = $(notdir $(USER_OBJS))

SRCS = $(MODULES)

ifeq ($(MODELREF_TARGET_TYPE), NONE)
    PRODUCT            = $(RELATIVE_PATH_TO_ANCHOR)/$(MODEL)$(TARGET_EXT)
    BIN_SETTING        = $(LD) $(LDFLAGS) -o $(PRODUCT)
    BUILD_PRODUCT_TYPE = "executable"
    SRCS              += $(MODEL).$(TARGET_LANG_EXT) rt_sim.c
else
    # Model reference rtw target
    PRODUCT            = $(MODELLIB)
    BUILD_PRODUCT_TYPE = "library"
endif

ifneq ($(findstring .cpp,$(suffix $(SRCS), $(USER_SRCS))),)
  LD = $(CPP)
  SYSTEM_LIBS += $(CPP_SYS_LIBS) 
endif

OBJS      = $(addsuffix .o, $(basename $(SRCS))) $(USER_OBJS)
LINK_OBJS = $(sort $(addsuffix .o, $(basename $(SRCS))) $(LOCAL_USER_OBJS))

ADDITIONAL_LDFLAGS += $(ARCH_SPECIFIC_LDFLAGS)

#------------- Test Compile using gcc -Wall to look for warnings ---------------
#
# DO_GCC_TEST=1 runs gcc with compiler warning flags on all the source files
# used in this build. This includes the generated code, and any user source
# files needed for the build and placed in this directory.
#
# See $(QUARC)/include/linux_arm_tools.mk for the definition of GCC_WARN_OPTS
GCC_TEST_CMD  := echo
GCC_TEST_OUT  := > nul:
ifeq ($(DO_GCC_TEST), 1)
  GCC_TEST := gcc -c -o nul: $(GCC_WARN_OPTS_MAX) $(CPP_REQ_DEFINES) \
                                     $(INCLUDES)
  GCC_TEST_CMD := echo; echo "\#\#\# GCC_TEST $(GCC_TEST) $<"; $(GCC_TEST)
  GCC_TEST_OUT := ; echo
endif

#----------------------------- Lint (sol2 only) --------------------------------

LINT_SRCS = $(MODEL)_main.c $(MATLAB_ROOT)/rtw/c/src/rt_sim.c
ifneq ($(SOLVER), )
  LINT_SRCS += $(MATLAB_ROOT)/rtw/c/src/$(SOLVER)
endif
ifneq ($(LINT_EXT_COMMON_SRC), )
  LINT_SRCS += $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/$(LINT_EXT_COMMON_SRC)
endif
ifneq ($(LINT_EXT_TCPIP_SRC), )
  LINT_SRCS += $(MATLAB_ROOT)/rtw/c/src/ext_mode/tcpip/$(LINT_EXT_TCPIP_SRC)
endif
LINT_SRCS += $(MODEL).$(TARGET_LANG_EXT) $(MODULES) $(USER_SRCS) $(S_FUNCTIONS)
LINTOPTSFILE = $(MODEL).lintopts

LINT_ERROFF1 = E_NAME_DEF_NOT_USED2,E_NAME_DECL_NOT_USED_DEF2
LINT_ERROFF2 = $(LINT_ERROFF1),E_FUNC_ARG_UNUSED
LINT_ERROFF  = $(LINT_ERROFF2),E_INDISTING_FROM_TRUNC2,E_NAME_USED_NOT_DEF2

# Define a BUILD_SUCCESS macro that accounts for the difference in escape
# characters between make and the shell.
BUILD_SUCCESS_EX := \$(BUILD_SUCCESS)

#--------------------------------- Rules ---------------------------------------
ifeq ($(MODELREF_TARGET_TYPE),NONE)
$(PRODUCT) : $(OBJS) $(LIBS) $(MODELREF_LINK_LIBS)
	$(BIN_SETTING) $(LINK_OBJS) $(MODELREF_LINK_LIBS) $(LIBS) $(ADDITIONAL_LDFLAGS) $(SYSTEM_LIBS)
ifeq ($(STRIPSYMBOLS),1)
	$(STRIP) --strip-debug --strip-unneeded $(PRODUCT)
endif
	@echo $(BUILD_SUCCESS_EX) $(BUILD_PRODUCT_TYPE) $(MODEL)$(TARGET_EXT)
else
$(PRODUCT) : $(OBJS)
	@rm -f $(MODELLIB)
	$(AR) ruvs $(MODELLIB) $(LINK_OBJS)
	@echo $(BUILD_SUCCESS_EX) $(MODELLIB)
	@echo $(BUILD_SUCCESS_EX) $(BUILD_PRODUCT_TYPE) $(MODEL)$(TARGET_EXT)
endif

%.o : %.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG) $<

%.o : %.cpp
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG) $<

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG) $<

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CPP) -c $(CPPFLAGS) $<

ifeq ($(CLASSIC_INTERFACE), 1)
ifeq ($(TARGET_LANG_EXT),cpp)
%.o : $(QUARC)/quarc/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CPPFLAGS) $<

%.o : $(QUARC)/src/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CPPFLAGS) $<
else
%.o : $(QUARC)/quarc/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<

%.o : $(QUARC)/src/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<
endif
endif

%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<

%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<

%.o : $(MATLAB_ROOT)/simulink/src/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<

%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<

%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<



%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CPP) -c $(CPPFLAGS) $<
%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CPP) -c $(CPPFLAGS) $<
%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.cpp
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CPP) -c $(CPPFLAGS) $<
%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.cpp
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CPP) -c $(CPPFLAGS) $<


#------------------------------- Libraries -------------------------------------





#----------------------------- Dependencies ------------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw

#--------- Miscellaneous rules to purge, clean and lint (sol2 only) ------------

purge : clean
	@echo \#\#\# Deleting the generated source code for $(MODEL)
	@del /q $(MODEL).c $(MODEL).h $(MODEL)_types.h $(MODEL)_data.c \
	        $(MODEL)_private.h $(MODEL).rtw $(MODULES) rtw_proj.tmw $(MAKEFILE)

clean :
	@echo \#\#\# Deleting the objects and $(PRODUCT)
	@del /q $(LINK_OBJS) $(PRODUCT)

lint  : rtwlib.ln
	@lint -errchk -errhdr=%user -errtags=yes -F -L. -lrtwlib -x -Xc \
	      -erroff=$(LINT_ERROFF) \
	      -D_POSIX_C_SOURCE $(CFLAGS) $(LINT_SRCS)
	@del /q $(LINTOPTSFILE)
	@echo
	@echo \#\#\# Created lint output only, no executable
	@echo

rtwlib.ln : $(MAKEFILE) rtw_proj.tmw
	@echo
	@echo \#\#\# Linting ...
	@echo
	@del /q llib-lrtwlib.ln $(LINTOPTSFILE)
	@echo "-dirout=. -errchk -errhdr=%user " >> $(LINTOPTSFILE)
	@echo "-errtags -F -ortwlib -x -Xc " >> $(LINTOPTSFILE)
	@echo "-erroff=$(LINT_ERROFF) " >> $(LINTOPTSFILE)
	@echo "-D_POSIX_C_SOURCE $(CFLAGS) " >> $(LINTOPTSFILE)
	@for %%file in ($(MATLAB_ROOT)/rtw/c/libsrc/*.c) do echo "%file " >> $(LINTOPTSFILE);
	lint -flagsrc=$(LINTOPTSFILE)

# EOF: quarc_linux_pi_3.tmf
