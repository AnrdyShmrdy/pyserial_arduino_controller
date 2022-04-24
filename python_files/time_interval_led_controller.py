from serial import Serial
from time import sleep
device_name = '/dev/ttyACM0' #arduino device name for Linux-based OS
baud_rate = 9600 #Note: this must equal Arduino baud rate, otherwise signal is not recieved!
delay = 0.5
serialConn = Serial(device_name, baud_rate, timeout=.1)
serialConn.reset_input_buffer()
def send_serialMsg(msg):
	global serialConn
	print("Sending: " + msg)
	serialConn.write(bytes(msg,'utf-8'))
def recieve_serialMsg():
	try:
		#try normal way of recieving data
		line = serialConn.readline().decode('utf-8').rstrip()
	except:
		#if normal way doesn't work, try getting binary representation to see what went wrong
		line = str(serialConn.readline())
	print("Recieved: " + line)
def SendRecieve(msg):
	send_serialMsg(msg)
	sleep(delay)
	recieve_serialMsg()
	sleep(delay)
while(True):
	SendRecieve('1')
	SendRecieve('0')