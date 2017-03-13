#!/usr/bin/python

import sys
import os
import SocketServer

class MyTCPHandler(SocketServer.StreamRequestHandler):
  """
  The RequestHandler class for our server.

  It is instantiated once per connection to the server, and must
  override the handle() method to implement communication to the
  client.
  """
  def loadData(self, filename):
    # Init the data structures dictionary
    self.parameters = {}
    # Load in the file data
    input = open(filename, 'r')
    strucfiles = input.readlines()
    # read in data structure from named files
    for dfile in strucfiles:
      spath = os.environ.get("SFILEPATH")
      dfile = spath + "/" + dfile.rstrip()
      s=""
      df = open(dfile, 'r')
      s = df.read()
      print strucfiles,"\n",dfile,"\n",s
      filep = dfile.split(".")
      filep = filep[-2].split("/")
      self.parameters[filep[-1]] = s
      print str(self.parameters)

  def handle(self):
    # Initialise some connection data
    self.loadData("strucfiles.dat")
    self.client_connected = False
    self.cmd_id = ""

    while (1):
      try:
        # Listen for incoming commands
        self.command = self.rfile.readline().strip()

        self.reply = ""
        resp = self.parseCommand()
        if resp == True:
          # Good format command, continue
          self.wfile.write(self.reply + "\n")
        else:
          server.close()
          sys.exit(0)

      except KeyboardInterrupt:
        # Quit
        server.close()
        sys.exit(0)

  def parseCommand(self):
    # Check the length
    if len(self.command) == 0:
      return False

    if self.command[0:3] == 'get':
      print "received get command"
      dname = self.command[4:] + "Struc"
      if dname in self.parameters:
        self.reply = self.parameters[dname]
      else:
        self.reply = "ERR! Parameter " + self.command[4:] + " not known"
      return True
      
    if self.command[0:4] == 'exit':
      return False
    
    return True



if __name__ == "__main__":
  HOST, PORT = "localhost", 7115
  #HOST, PORT = "10.2.2.55", 7010

  def server_bind(self):
        self.socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.socket.bind(self.server_address)

  try:  
    os.environ["SFILEPATH"]
  except KeyError: 
    print "Please set the environment variable SFILEPATH"
    sys.exit(1)
  # Create the server, binding to localhost on port 9999
  server = SocketServer.TCPServer((HOST, PORT), MyTCPHandler)

  # Activate the server; this will keep running until you
  # interrupt the program with Ctrl-C
  server.serve_forever()

