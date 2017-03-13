<envPaths
cd "$(TOP)"

epicsEnvSet "EPICS_TS_MIN_WEST", '0'


# Loading libraries
# -----------------

# Device initialisation
# ---------------------

dbLoadDatabase "dbd/miroTest.dbd"
miroTest_registerRecordDeviceDriver(pdbbase)

drvAsynIPPortConfigure("ctrlPort", "localhost:7115", 0, 0, 0)
drvAsynIPPortConfigure("dataPort", "localhost:7116", 0, 0, 0)

# miroCameraConfig(portName, driverName, maxBuffers, maxMemory, priority, stackSize )
miroCameraConfig("MIRO", "ctrlPort", "dataPort", 0, 0, 0, 0)

miroCameraDebug("MIRO", "all", 1)

# Final ioc initialisation
# ------------------------

dbLoadRecords 'db/miroCamera.db'
iocInit
