#!/usr/bin/python
import sys
import os
import socket
import select
import threading
import thread
import time

camera_params = { 
	'cam' : {
		'syncimg' : 0,
		'master' : 0,
		'tcmode' : 0,
		'trigpol' : 1,
		'trigfilt' : 1,
		'frdelay' : 0,
		'startonacq' : 1,
		'aux1mode' : 0,
		'aux2mode' : 0,
		'memgateen' : 1,
		'rtoen' : 0,
		'membpp' : 12,
		'tsformat' : 1,
		'longready' : 0,
		'dark' : 0,
		'quiet' : 0,
		'tsetsns' : 30,
		'tsetcam' : 50,
		'apoffdis' : 0,
		'rtotfr' : 0,
		'cines' : 16,	
		'battarm' : 0,
		'battmode' : 0,
		'wtrarmdelay' : 0,
		'wtrarmtime' : 0,
		'poffdelay' : 10,
		'readygate' : 0,
		'timezone' : -3600,
		'lang' : "en_US",
		'occset' : ""
	},
  'info' : {
  	'hwver' : 8001,
	  'pver' : 16,
	  'sver' : 1023,
	  'fver' : 39,
	  'model' : "Phantom Miro M310",
	  'sensor' : 62,
	  'snsversion' : 0,
	  'snsserial' : 0,
	  'occver' : 0,
	  'tally' : 0,
	  'kernel' : 425,
	  'swver' : 14967,
	  'xver' : 840,
	  'serial' : 17277,
	  'memsz' : 12288,
	  'cfa' : 0,
	  'filter' : 0,
	  'maxcines' : 17,
	  'name' : "17277",
	  'kernsz' : 24,
	  'xmax' : 1280,
	  'ymax' : 800,
	  'xinc' : 64,
	  'yinc' : 8,
	  'xblock' : 8,
	  'yblock' : 8,
	  'winx' : 32,
	  'winy' : 8,
	  'pixps' : 17857,
	  'rotps' : 196427,
	  'fotps' : 553567,
	  'minfrate' : 24,
	  'tmodel' : 4,
	  'maxrate' : 1000000,
	  'expdead' : 427,
	  'minexp' : 1000,
	  'magtp' : 720000000,
	  'cinemem' : 12181,
	  'mdepths' : 0x1000,
	  'rtobyteps' : 3200,
	  'rtopacket' : 160,
	  'rtopacketovhead' : 12,
	  'rtofrovhead' : 1900,
	  'rto_channels' : 0,
	  'snstemp' : 30,
	  'tepower' : 54,
	  'camtemp' : 52,
	  'fanpower' : 28,
	  'batti' : 0,
	  'battv' : 271,
	  'battstate' : 0,
	  'batttimer' : 0,
	  'vbatt' : 0.2645052632,
	  'vcdina' : 0.3747157895,
	  'vcdinb' : 23.95976842,
	  'genlockstatus' : 0,
	  'features' : "bref blk4 burst edr attach earlyimg notify atrig aexp cf quiet shtr",
	  'imgformats' : "8 8R P16 P16R P10",
	  'videosystems' : "0 1",
	  'basechroma' : 1,
	  'baseei' : 13000,
	  'setup' : "Donal_Std_Rad_2000fps"
  },
	'c1' : {
		'res' : '1280 x 800',
		'rate' : 1080,
		'exp' : 925482,
		'shoff' : 0,
		'edrexp' : 0,
		'ptframes' : 820,
		'bcount' : 0,
		'bperiod' : 307692,
		'hqenable' : 0,
		'frcount' : 820,
		'ramp' : "",
		'state' : '{ WTR DEF ABL ACT }',
		'start' : 0x475000,
		'len' : 0x1F90000,
		'frsize' : 40336,
		'frspace' : 33095680,
		'firstfr' : 0,
		'lastfr' : 0,
		'format' : 0,
		'decimation' : 1,
		'in' : 0,
		'out' : 0,
		'aexpmode' : 0,
		'aexpcomp' : -0.1605,
		'trigtime' : {
			'secs' : 0,
			'frac' : 0
		},
		'cam' : {
			'syncimg' : 0,
			'master' : 0,
			'tcmode' : 0,
			'trigpol' : 1,
			'trigfilt' : 1,
			'frdelay' : 0,
			'startonacq' : 1,
			'aux1mode' : 0,
			'aux2mode' : 0,
			'memgateen' : 1,
			'membpp' : 12,
			'tsformat' : 1
		},
		'info' : {
			'hwver' : 8001,
			'sver' : 1023,
			'fver' : 39,
			'pver' : 16,
			'model' : "Phantom Miro M310",
			'sensor' : 62,
			'snsversion' : 0,
			'snsserial' : 0,
			'kernel' : 425,
			'swver' : 14967,
			'xver' : 840,
			'serial' : 17277,
			'cfa' : 0,
			'filter' : 0,
			'name' : "17277",
			'mdepths' : 0x1000,
			'genlockstatus' : 0,
			'snstemp' : 0,
			'camtemp' : 0,
			'features' : "bref blk4 burst edr attach earlyimg notify atrig aexp cf quiet shtr"
		},
		'adj' : {	
			'red' : 1,
			'green' : 1,
			'blue' : 1,
			'wbtemp' : 5600,
			'wbcc' : 0,
			'wbred' : 1.321455044,
			'wbblue' : 1.824537662,
			'edgeg' : 0,
			'edger' : 0,
			'edgeth' : 0,
			'gamma' : 0.57544,
			'rgamma' : 0,
			'bgamma' : 0,
			'toe' : 1,
			'gain' : 3.176874,
			'offset' : -0.0785,
			'flare' : 0,
			'hue' : 0,
			'sat' : 1,
			'rped' : 0,
			'gped' : 0,
			'bped' : 0,
			'tone' : "",
			'mmsat' : "",
			'mmhue' : "",
			'chroma' : 1,
			'matrix' : 1,
			'log' : 0,
			'sdimin' : 32,
			'sdimax' : 960,
			'cmatrix' : "cal 1.7326 0.119326 -0.785386  -0.380114 1.78173 -0.901473  -0.125864 -0.102658 2.18562",
			'umatrix' : "",
			'filter' : ""
		},
		'meta' : {	
			'name' : "",
			'uuid' : "",
			'system' : 1,
			'pbrate' : 50,
			'tcrate' : 25,
			'trigtc' : "",
			'pax' : 0,
			'pay' : 0,
			'paox' : -640,
			'paoy' : -400,
			'vox' : 0,
			'voy' : 0,
			'vw' : 1280,
			'vh' : 504,
			'vow' : 711,
			'voh' : 280,
			'ox' : -160,
			'oy' : -120,
			'w' : 1,
			'h' : 1,
			'ow' : 1280,
			'oh' : 504,
			'crop' : 0,
			'resize' : 0,
			'lens' : "",
			'fstop' : 0,
			'flen' : 0,
			'gps' : "",
			'comment' : "",
			'xset' : ""
		}
	}
}

data_socket = None
raw_image = ["0"] * 10240
data_str = "".join(raw_image)
#for x in range(0, 1024000):
#  raw_image = raw_image + [1]

def dict_to_response(name, dict_in, level=None):
  tabs = ""
  if level != None:
    for index in range(0, level):
      tabs += "\t"
  reply = tabs + name + " : {\t\\\r\n"
  new_level = 0
  if level == None:
    new_level = 1
  else:
    new_level = level + 1
  for item in dict_in:
    quote = ""
    if isinstance(dict_in[item], dict):
      reply += dict_to_response(item, dict_in[item], new_level) + "\t\\\r\n"
    else:
      if isinstance(dict_in[item], str):
        quote = "\""
      reply += tabs + "\t" + item + " : " + quote + str(dict_in[item]) + quote + ",\t\\\r\n"
  reply += tabs + "}"
  #print reply
  return reply

#def loadData(filename):
#  # Init the data structures dictionary
#  dataStructures = {}
#  # Load in the file data
#  input = open(filename, 'r')
#  strucfiles = input.readlines()
#  # read in data structure from named files
#  for dfile in strucfiles:
#    spath = os.environ.get("SFILEPATH")
#    dfile = spath + "/" + dfile.rstrip()
#    s=""
#    df = open(dfile, 'r')
#    s = df.read()
#    filep = dfile.split(".")
#    filep = filep[-2].split("/")
#    dataStructures[filep[-1]] = s
#    print strucfiles,"\n",filep[-1]
#  return dataStructures
##    print str(dataStructures)

def commandHandler(accepted_socket):
  buf_size = 1024

  # Initialise some connection data
  #dataStructures = loadData("strucfiles.dat")

  while (1):
    try:
      # Listen for incoming commands
#      command = rfile.readline().strip()
      data = accepted_socket.recv(buf_size)
      command = data.strip()
      reply = ""
      reply, resp = parseCommand(command)
      if resp == True:
        # Good format command, continue
        accepted_socket.send(reply + "\n")
      else:
        accepted_socket.close()
        sys.exit(0)

    except KeyboardInterrupt:
      # Quit
      server.close()
      sys.exit(0)

def write_image():
  for x in range(0, 100):
    data_socket.send(data_str)

def parseCommand(command):
  print data_socket
  # Check the length
  if len(command) == 0:
    return False

  if command[0:6] == 'attach':
    print "Attach called to data port"
    reply = 'OK'

  if command[0:3] == 'img':
    print "Recording to cine"
    thread.start_new_thread( write_image, () )
    reply = 'OK'

  if command[0:3] == 'get':
    print "received get command"
    dname = command[4:]
    print "Get: " + str(dname)
    if dname in camera_params:
      reply = dict_to_response(dname, camera_params[dname])
      print 'dname, reply = ', dname, reply
    else:
      reply = "ERR! Parameter " + command[4:] + " not known"
    return reply, True
    
  if command[0:4] == 'exit':
    return "", False
  
  return reply, True


def handleConnection(accepted_socket, address):
  buf_size = 1024
  port = address[1]
  if port == 7115:
    print 'We have a command connection on port ', port
    commandHandler(accepted_socket)
  elif port == 7116:
    print 'We have a data stream connection on port ', port
    global data_socket
    data_socket = accepted_socket
    print data_socket
  else:
    print 'Unrecognized port connection on ', port
        
  data = accepted_socket.recv(buf_size)
  if data:
    print data
    accepted_socket.send('Hello, and goodbye.')
    accepted_socket.close()
    
def server():
  sock_lst = []
  host = 'localhost'
  backlog = 5 # Number of clients on wait.
  
#  print dict_to_response('cam', camera_structure['cam'])
#  print dict_to_response('c1', camera_structure['c1'])

  try:
    for port in (7115, 7116):
      sock_lst.append(socket.socket(socket.AF_INET, socket.SOCK_STREAM))
      sock_lst[-1].setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1) 
      sock_lst[-1].bind((host, port)) 
      sock_lst[-1].listen(backlog)
  except socket.error, (value, message):
    if sock_lst[-1]:
      sock_lst[-1].close()
      sock_lst = sock_lst[:-1]
    print 'Could not open socket: ' + message
    sys.exit(1)
  
  acquiring = threading.Event()
  while True:
    read, write, error = select.select(sock_lst,[],[])
  
    for r in read:
      for item in sock_lst:
        if r == item:
          accepted_socket, address = item.accept()
          server_thread = threading.Thread(target=handleConnection, args=(accepted_socket, item.getsockname()))
          # Exit the server thread when the main thread terminates
          server_thread.setDaemon(True)
          server_thread.start()


server()
# if __name__ == "__main__":
#    main()

