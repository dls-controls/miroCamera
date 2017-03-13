TOP=../..

include $(TOP)/configure/CONFIG

# -------------------------------
# Build a Support Module
# -------------------------------

LIBRARY_IOC += miro
PROD += createParamIncludes

DBD += miroCameraSupport.dbd

# The following are compiled and added to the support library
HDEPENDS = YES

createParamIncludes_SRCS += createParamIncludes.cpp
createParamIncludes_SRCS += miroCameraSupport.cpp

miro_SRCS += MiroCamera.cpp
miro_SRCS += miroCameraSupport.cpp

miro_LIBS += asyn
miro_LIBS += ADBase
miro_LIBS += busy

# We need to link against the EPICS Base libraries
miro_LIBS += $(EPICS_BASE_IOC_LIBS)


include $(TOP)/configure/RULES
