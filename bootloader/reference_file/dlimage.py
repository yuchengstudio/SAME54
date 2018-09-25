import serial
import argparse;
import os
import struct
import time

#author: ZhangQuan

#python 2.7.x is required
#command line argument '-b 115200 -p COMx -f binary_file'

FRAME_LEN = 128
ACK = 's'

def main():
	#command line arguments setting for parser
	parser = argparse.ArgumentParser('downloading the binary file by UART port')
	parser.add_argument('-b', '--baudrate', default=115200, type=int, help='baudrare of COM port')
	parser.add_argument('-p', '--port', help='name of COM port')
	parser.add_argument('-f', '--file', help='name of binary image file')
	args = parser.parse_args()
	
	if args.port is None:
		print "COM port for downloading must be specified"
		exit()
	if args.file is None:
		print "binary image file for downloading must be specified"
		exit()
	
	print args
	
	#get the length of the image file
	try:
		file_len = os.path.getsize(args.file)
	except WindowsError:
		print "'"+ args.file + "'" + " does not exist"
		exit()
	
	print "'" + args.file + "' file length is: " + str(file_len)
	
	len_buf = struct.pack("<I", file_len)
	
	print len_buf
	
	ser = serial.Serial()
	ser.baudrate = args.baudrate
	ser.port = args.port
	
	#print ser
	
	try:
		ser.open()
		ser.write(len_buf)
		ser.flush()
	except serial.SerialException:
		print "serial port error"
		ser.close()
		exit()
	
	with open(args.file, "rb") as f:
		while (file_len != 0):
			f_buf = f.read(min(file_len, FRAME_LEN))
			ser.write(f_buf)
			ser.flush()
			file_len = file_len - min(file_len, FRAME_LEN)
			ack = ser.read(1)
			
			if ack != 's':
				print 'no ack is received: ' + str(ack)
			else:
				print '128 bytes has been acknowleged'
	
	
	print 'downloading finished'
	ser.close()
		
if __name__ == '__main__':
	main()
	