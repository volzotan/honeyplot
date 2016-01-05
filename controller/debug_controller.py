import serial
from serial.tools import list_ports

import urwid

class Controller(object):

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

    
    def read(self):
        inp = ''
        while (True):
            c = self.conn.read()
            if c == "" or c is None:
                raise Exception("timeout")
            inp += c
            print('received: ' + inp) #DEBUG
            if ';' in inp:
                return inp


    def send_cmd(self, cmd, payload=None, flush=False):
        if flush:
            #read till timeout
            while True:
                try:
                    self.read()
                except:
                    break

        if payload is None:
            message = "{0}\n".format(cmd)
        else:
            if len(payload) == 1:
                message = "{0} {1}\n".format(cmd, payload[0])
            else:
                message = "{0} {1} {2}\n".format(cmd, payload[0], payload[1])

        self.conn.write(message)
        response = self.read()

        # logger.debug("{0} {1} :: {2}".format(cmd, payload, response))
        print("{0} {1} :: {2}".format(cmd, payload, response))

        # try:
        #     if response[0:3] != "#OK":
        #         raise Exception

        #     if response[len(response)-1] != ";":
        #         raise Exception

        # except Exception as e:
        #     logger.error("communication error [{0}]".format(response), exc_info=True)

        return response #[4:len(response)-1]


    def close(self):
        if self.conn is not None:
            self.conn.close()


class Faceplate(object):

    def __init__(self):
        pass

    def start(self):
        btn_close = urwid.Button("exit")
        filler = urwid.Filler(btn_close)
        urwid.connect_signal(btn_close, "click", self.exitAndClose)

        urwid.MainLoop(filler).run() #, unhandled_input=self.input_handler).run()


    def input_handler(self, key):
        print "foo"
        exitAndClose()


    def exitAndClose(self, *args): # connect_signal passes the param btn
        raise urwid.ExitMainLoop()
        

if __name__ == "__main__":
    Faceplate().start()
    #controller = Controller()
    #controller.connect()
    #controller.send_cmd("s")
