from serial import Serial
from pynput.keyboard import KeyCode, Listener, Key
isFinished = False
device_name = '/dev/ttyACM0' #arduino device name for Linux-based OS
baud_rate = 9600 #Note: this must equal Arduino baud rate, otherwise signal is not recieved!
serialConn = Serial(device_name, baud_rate, timeout=.1)
def send_serialMsg(msg):
	global serialConn
	print("Sending: " + msg)
	serialConn.write(bytes(msg,'utf-8'))
	try:
		#try normal way of recieving data
		line = serialConn.readline().decode('utf-8').rstrip()
	except:
		#if normal way doesn't work, try getting binary representation to see what went wrong
		line = str(serialConn.readline())
	print("Recieved: " + line)
def onpress(key):
	global isFinished
	if isinstance(key, KeyCode): #lets us know if we can safely use key.char
		if key.char.isalpha():
			print("alphabetical character pressed")
			send_serialMsg(key.char)
			return False # Stop listener
	if key == Key.esc:
	# Stop listener
		isFinished = True
		return False
def onrelease(key):
	global isFinished
	if isinstance(key, KeyCode): #lets us know if we can safely use key.char
		if key.char.isalpha():
			print("alphabetical character released")
			return False # Stop listener
	if key == Key.esc:
		isFinished = True
		return False # Stop listener
# Collect events until released
while (isFinished == False):
	# initialising Listener object
	# It is in fact necessary to make on_press and on_release tied to different listeners btw   
	with Listener(suppress = True, on_press = onpress) as l:
		l.join()
	with Listener(suppress = True, on_release = onrelease) as l:
		l.join()