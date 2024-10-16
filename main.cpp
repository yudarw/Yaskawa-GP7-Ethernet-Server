#include "lib/yaskawa.h"

// create robot instance 
Yaskawa armRobot;

// robot initial position
double standby_pos[6] = { 610, 153, 35, 180, 90, 85 };

// --------------- main ---------------- //
int main(){
    // Connect to yaskawa gp7 controller
    if(!armRobot.connected){
        // Set the robot IP
        int res = armRobot.tcp_connect("192.168.171.222");
        if(res != 0){
            // Keep connection alive
            armRobot.send_command2(str2char("CONNECT Robot_access Keep-Alive:50000\r"), armRobot.pRecv);

            // ---------- Execute simple movement ------------ //
            // Enable the servo
            armRobot.SVON();
            armRobot.MoveL(610, 153, 35, 180, 90, 0);    
        }
    }
    
    return 0;
} 
