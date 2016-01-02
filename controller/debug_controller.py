import serial
from serial.tools import list_ports

class Controller():
    def __init__(self):
        self.conn = None

    def search_ports(self):
        port_gen = list_ports.comports()
        port_list = []
        for elem in port_gen:
            port_list.append(elem)

        # for i in range(0, len(port_list)):
            # print("{0}: {1}".format(i, port_list[i][0]))
            # print port_list[i]

        print port_list

        for elem in port_list:
            if elem[1] == "FT231X USB UART":
                return elem

        return None

    def connect(self):
        port = self.search_ports()

        if port is not None:
            self.conn = serial.Serial(port[0], 9600, timeout=3)
        else:
            raise Exception("no port found")

    def close(self):
        if self.conn is not None:
            self.conn.close()

Controller().connect()