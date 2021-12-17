import serial.tools.list_ports
import serial
import time


class SerialComm:
    class SerialException(Exception):
        pass

    __serial_con__: serial.Serial
    __timeout__: int

    def __init__(self, serial_port: str = "", baud_rate: int = 9600, timeout: int = 15):
        self.__timeout__ = timeout

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
            timeout=timeout,
        )

        if not self.__serial_con__.isOpen():
            self.__serial_con__.open()

        time.sleep(1.25)

    def sendBlock(self, start_marker: int = 0x1F, end_marker: int = 0x1E):
        header: str = f"{start_marker:02}{end_marker:02}{self.__timeout__:02}"
        self.__serial_con__.write(header.encode())
        print(header)


if __name__ == "__main__":
    device = SerialComm(baud_rate=115200, timeout=15)
    device.sendBlock()
