import serial
import threading
# sudo pip install pyserial

def set_interval(func, sec):
    def func_wrapper():
        set_interval(func, sec)
        func()
    t = threading.Timer(sec, func_wrapper)
    t.start()
    return t

def get_value():
    data = ser.readline()
    print data,

# Serial port parameters
serial_speed = 9600
serial_port = '/dev/tty.Pusheen-DevB'
# ll /dev/tty.*

ser = serial.Serial(serial_port, serial_speed, timeout=1)

set_interval(get_value(), 1)
