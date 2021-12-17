import serial.tools.list_ports
import serial
import time


class SerialComm:
    class SerialException(Exception):
        pass

    __serial_con__ = serial.Serial

    def __init__(self, serial_port: str = "", baud_rate: int = 9600):
        ports = [
            i.device for i in serial.tools.list_ports.comports() if "SER" in i.hwid
        ]

        if len(ports) >= 1:
            ports = [ports[0]]
        else:
            raise self.SerialException("Could not find serial device")

        self.__serial_con__ = serial.Serial(
            ports[0] if len(serial_port) < 3 else serial_port,
            baudrate=baud_rate,
            timeout=1,
        )

        if not self.__serial_con__.isOpen():
            self.__serial_con__.open()

        time.sleep(1.25)

    def sendBlock(self):
        header = 0
        header += 0x1F * 10000
        header += 0x1C * 100
        header += 15
        print(header)
        self.__serial_con__.write(header)


if __name__ == "__main__":
    device = SerialComm()
    device.sendBlock()
