#!../../bin/linux-x86_64/miroApp

errlogInit(20000)

epicsEnvSet("EPICS_CA_MAX_ARRAY_BYTES",  64000000)
epicsEnvSet("EPICS_CA_AUTO_ADDR_LIST",   "NO")
epicsEnvSet("EPICS_CA_ADDR_LIST",        "127.0.0.255")
epicsEnvSet("EPICS_CAS_INTF_ADDR_LIST",  "127.0.0.1")

< envPaths
#epicsThreadSleep(20)
dbLoadDatabase("$(TOP)/dbd/miroApp.dbd")
miroApp_registerRecordDeviceDriver(pdbbase) 

# Prefix for all records
epicsEnvSet("PREFIX", "DEV:VEO1:")
# The port name for the detector
epicsEnvSet("PORT",   "VEO1")
# The queue size for all plugins
epicsEnvSet("QSIZE",  "20")
# The maximim image width; used for row profiles in the NDPluginStats plugin
epicsEnvSet("XSIZE",  "1280")
# The maximim image height; used for column profiles in the NDPluginStats plugin
epicsEnvSet("YSIZE",  "960")
# The maximum number of time seried points in the NDPluginStats plugin
epicsEnvSet("NCHANS", "2048")
# The maximum number of frames buffered in the NDPluginCircularBuff plugin
epicsEnvSet("CBUFFS", "500")
# The search path for database files
epicsEnvSet("EPICS_DB_INCLUDE_PATH", "$(ADCORE)/db")
# Size of data allowed 
epicsEnvSet("EPICS_CA_MAX_ARRAY_BYTES", 20000000)
#epicsThreadSleep(15)


# Configure control and data TCP/IP socket connections. Default ports should be 7115 and 7116 respectively.
drvAsynIPPortConfigure("CTRL", "100.100.214.107:7115", 100, 0, 0)
drvAsynIPPortConfigure("DATA", "100.100.214.107:7116", 100, 0, 0)

# Configure the camera
miroCameraConfig("$(PORT)", "CTRL", "DATA", 0, 0, 0, 0)

# Enable debugging for certain functions
#miroCameraDebug("$(PORT)", "readoutDataStream", 1);

asynSetTraceIOMask($(PORT), 0, 2)
#asynSetTraceMask($(PORT), 0, 0xff)

# Load base camera records
dbLoadRecords("$(MIROCAMERA)/db/miroCamera.template", "P=$(PREFIX),R=cam1:,PORT=$(PORT),ADDR=0,TIMEOUT=1")

# Load a template for each configured cine
dbLoadRecords("$(MIROCAMERA)/db/miroCine.template", "P=$(PREFIX),R=cam1:, CINE=1, PORT=$(PORT),ADDR=0,TIMEOUT=1")
dbLoadRecords("$(MIROCAMERA)/db/miroCine.template", "P=$(PREFIX),R=cam1:, CINE=2, PORT=$(PORT),ADDR=0,TIMEOUT=1")
dbLoadRecords("$(MIROCAMERA)/db/miroCine.template", "P=$(PREFIX),R=cam1:, CINE=3, PORT=$(PORT),ADDR=0,TIMEOUT=1")
dbLoadRecords("$(MIROCAMERA)/db/miroCine.template", "P=$(PREFIX),R=cam1:, CINE=4, PORT=$(PORT),ADDR=0,TIMEOUT=1")
dbLoadRecords("$(MIROCAMERA)/db/miroCine.template", "P=$(PREFIX),R=cam1:, CINE=5, PORT=$(PORT),ADDR=0,TIMEOUT=1")
dbLoadRecords("$(MIROCAMERA)/db/miroCine.template", "P=$(PREFIX),R=cam1:, CINE=6, PORT=$(PORT),ADDR=0,TIMEOUT=1")
dbLoadRecords("$(MIROCAMERA)/db/miroCine.template", "P=$(PREFIX),R=cam1:, CINE=7, PORT=$(PORT),ADDR=0,TIMEOUT=1")
dbLoadRecords("$(MIROCAMERA)/db/miroCine.template", "P=$(PREFIX),R=cam1:, CINE=8, PORT=$(PORT),ADDR=0,TIMEOUT=1")
dbLoadRecords("$(MIROCAMERA)/db/miroCine.template", "P=$(PREFIX),R=cam1:, CINE=9, PORT=$(PORT),ADDR=0,TIMEOUT=1")
dbLoadRecords("$(MIROCAMERA)/db/miroCine.template", "P=$(PREFIX),R=cam1:, CINE=10:, PORT=$(PORT),ADDR=0,TIMEOUT=1")
dbLoadRecords("$(MIROCAMERA)/db/miroCine.template", "P=$(PREFIX),R=cam1:, CINE=11, PORT=$(PORT),ADDR=0,TIMEOUT=1")
dbLoadRecords("$(MIROCAMERA)/db/miroCine.template", "P=$(PREFIX),R=cam1:, CINE=12, PORT=$(PORT),ADDR=0,TIMEOUT=1")
dbLoadRecords("$(MIROCAMERA)/db/miroCine.template", "P=$(PREFIX),R=cam1:, CINE=13, PORT=$(PORT),ADDR=0,TIMEOUT=1")
dbLoadRecords("$(MIROCAMERA)/db/miroCine.template", "P=$(PREFIX),R=cam1:, CINE=14, PORT=$(PORT),ADDR=0,TIMEOUT=1")
dbLoadRecords("$(MIROCAMERA)/db/miroCine.template", "P=$(PREFIX),R=cam1:, CINE=15, PORT=$(PORT),ADDR=0,TIMEOUT=1")
dbLoadRecords("$(MIROCAMERA)/db/miroCine.template", "P=$(PREFIX),R=cam1:, CINE=16, PORT=$(PORT),ADDR=0,TIMEOUT=1")


#
# Create a standard arrays plugin, set it to get data from Driver.
# int NDStdArraysConfigure(const char *portName, int queueSize, int blockingCallbacks, const char *NDArrayPort, int NDArrayAddr, int maxBuffers, size_t maxMemory,
#                          int priority, int stackSize, int maxThreads)
NDStdArraysConfigure("Image1", 3, 0, "$(PORT)", 0)
dbLoadRecords("$(ADCORE)/db/NDStdArrays.template", "P=$(PREFIX),R=image1:,PORT=Image1,ADDR=0,NDARRAY_PORT=$(PORT),TIMEOUT=1,TYPE=Int16,FTVL=SHORT,NELEMENTS=6000000")

#
# Load all other plugins using commonPlugins.cmd
< $(ADCORE)/iocBoot/commonPlugins.cmd

set_requestfile_path("$(MIROCAMERA)/db")

#asynSetTraceMask($(PORT),0,0x09)
#asynSetTraceMask($(PORT),0,0x11)
iocInit()

# save things every thirty seconds
create_monitor_set("auto_settings.req", 30, "P=$(PREFIX)")
