#include "lib/yaskawa.h"

Yaskawa armRobot;

double standby_pos[6] = { 610, 153, 35, 90, 85 };

int main(){

    if(!armRobot.connected){
        int res = armRobot.tcp_connect("192.168.171.222");
        if(res != 0){
            armRobot.send_command2(str2char("CONNECT Robot_access Keep-Alive:50000\r"), armRobot.pRecv);
        }
    }
    
    return 0;
} 