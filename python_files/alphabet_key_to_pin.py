from pynput.keyboard import KeyCode, Listener, Key
isFinished = False
fPinNo = 22; #first pin number = 'a' or 'A'
lPinNo = 48; #last pin number = 'z' or 'Z'
ucase_offset = ord('A')-fPinNo; #subtract from uppercase letter ascii value to get pin# for Arduino
lcase_offset = ord('a')-fPinNo; #subtract from lowercase letter ascii value to get pin# for Arduino

def onpress(key):
	global isFinished
	if isinstance(key, KeyCode): #lets us know if we can safely use key.char
		if key.char.isupper():
			print("uppercase character pressed")
			pinToWrite = ord(key.char)-ucase_offset
			print("pinToWrite: " + str(pinToWrite))
			return False # Stop listener
		elif key.char.islower():
			print("lowercase character pressed")
			pinToWrite = ord(key.char)-lcase_offset
			print("pinToWrite: " + str(pinToWrite))
			return False # Stop listener	
	if key == Key.esc:
	# Stop listener
		isFinished = True
		return False
def onrelease(key): #we need this to ensure keypresses are not sent when holding down a key
	global isFinished
	if isinstance(key, KeyCode): #lets us know if we can safely use key.char
		if key.char.isupper():
			print("uppercase character released")
			return False # Stop listener
		elif key.char.islower():
			print("lowercase character released")
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