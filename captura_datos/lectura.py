


from serialExcel import SerialExcel

# Indicar Puerto serie de conexión y baud rate
puerto = '/dev/cu.usbmodem1101'
baud = 9600

serialExcel = SerialExcel(puerto,baud)

columnas = ['gyroX', 'gyroY', 'gyroZ', 'magX', 'magY', 'magZ', 'accelX', 'accelY', 'accelZ', 'presion']
serialExcel.setColumns(['gyroX', 'gyroY', 'gyroZ', 'magX', 'magY', 'magZ', 'accelX', 'accelY', 'accelZ', 'presion' ])
serialExcel.setRecordsNumber(500)

serialExcel.readPort()
serialExcel.writeFile("DataImportada.xls")
