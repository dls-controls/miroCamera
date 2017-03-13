TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

#=============================
# Build the IOC application

PROD_IOC = miroTest
# miroTest.dbd will be created and installed
DBD += miroTest.dbd

# miroTest.dbd will be made up from these files:
miroTest_DBD += base.dbd
miroTest_DBD += miroCameraSupport.dbd
miroTest_DBD += asyn.dbd
miroTest_DBD += drvAsynIPPort.dbd
miroTest_DBD += ADSupport.dbd 
miroTest_DBD += busySupport.dbd

# miroTest_registerRecordDeviceDriver.cpp derives from miroTest.dbd
miroTest_SRCS += miroTest_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
miroTest_SRCS_DEFAULT += miroTestMain.cpp
miroTest_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#miroTest_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Link in the support libraries
miroTest_LIBS += miro
miroTest_LIBS += asyn
miroTest_LIBS += ADBase
miroTest_LIBS += busy

# Finally link to the EPICS Base libraries
miroTest_LIBS += $(EPICS_BASE_IOC_LIBS)

#=============================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

