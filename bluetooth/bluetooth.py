import json
import serial
import httplib, urllib, urllib2
import iso8601, datetime
import random
# sudo pip install pyserial

# Serial port parameters
serial_speed = 9600
serial_port = '/dev/tty.Pusheen-DevB'
# ll /dev/tty.*
ct = 0

try:
	ser = serial.Serial(serial_port, serial_speed, timeout=1)
	print 'start'
	sz = 30
	l = [1]*sz

	while True:
		dist = int(ser.readline())
		ct = ct+1

		t = iso8601.parse_date(str(datetime.datetime.now()))
		l = l[1:sz] + [1 if dist < 50 else 0]
		ls = sum(l)

		data = {
		        'datapoints': [{
		        	"v2eaf5cd080e811e4" : dist,
		        	"v8073ca40828911e4" : '='*(ls/(sz/10)) + '[%d(%d%%)]' % (ls, ls*100/sz),
					"at" : str(t)
		       	}]
		}

		print 'no.%d dist=%d sum=%d' % (ct, dist, sum(l))


		data = json.dumps(data)

		req = urllib2.Request('http://106.186.30.234/api/devices/c6a89825f1364bed/updatedata?apikey=c3ec40a829b5424c')
		req.add_header('Content-Type', 'application/json')

		response = urllib2.urlopen(req, data)
	
except Exception, e:
	raise e
