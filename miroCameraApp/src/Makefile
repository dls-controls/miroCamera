TOP=../..

include $(TOP)/configure/CONFIG

# -------------------------------
# Build a Support Module
# -------------------------------

LIBRARY_IOC += miro
#PROD += createParamIncludes

DBD += miroCameraSupport.dbd

# The following are compiled and added to the support library
HDEPENDS = YES

#createParamIncludes_SRCS += createParamIncludes.cpp
#createParamIncludes_SRCS += miroCameraSupport.cpp

miro_SRCS += MiroCamera.cpp
miro_SRCS += miroCameraSupport.cpp


DATA += miro_hdf5.xml

# We need to link against the EPICS Base libraries
include $(ADCORE)/ADApp/commonLibraryMakefile

include $(TOP)/configure/RULES
