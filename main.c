#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

int main() {
    printf("Hello");

    const char* port = "/dev/ttyUSB0";
    int serial_port = open(port, O_RDWR);
    if (serial_port < 0) {
        perror("Error connecting");
        return 1;
    }

    struct termios tty;
    memset(&tty, 0, sizeof(tty));
    if (tcgetattr(serial_port, &tty) != 0) {
        perror("Error - atrybuty portu szeregowego");
        return 1;
    }

    tty.c_cflag &= -PARENB;
    tty.c_cflag &= -CSTOPB;
    tty.c_cflag &= -CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag &= -CRTSCTS;

    cfsetispeed(&tty, B9600);
    cfsetispeed(&tty, B9600);

    tty.c_lflag |= ICANON | ECHO;

    if (tcsetattr(serial_port, TCSANOW, &tty) != 0){
        perror("Error - port szeregowy");
        return 1;
    }
    printf("Podaj kąt 0-180 stopni: ");

    char angle_str[4];
    fgets(angle_str, sizeof(angle_str), stdin);

    int angle = atoi(angle_str);
    if (angle < 0 || angle > 180) {
        fprintf(stderr, "Wrong angle");
        close(serial_port);
        return 1;
    }

    dprintf(serial_port, "%d", angle);

    char response[3];
    read(serial_port, response, sizeof(response));

    printf("%s\n", response);

    close(serial_port);
    return 0;    
}

