#include "time.h"
#include "Windows.h"

void time::delay(int ms)  //delay function
{
    clock_t timeDelay = ms + clock();    //Step up the difference from clock delay
    while (timeDelay > clock());         //stop when the clock is higher than time delay
}
void time::printData(int x, int y, int hour, int minute, int second, int color) {   //print data to screen
    common::setConsoleColor(BRIGHT_WHITE, color);
    common::gotoXY(x + 2, y);
    cout << ":";
    common::gotoXY(x + 5, y);
    cout << ":";
    if (hour > 9) {
        common::gotoXY(x, y);
        cout << hour;
    }
    else {
        common::gotoXY(x, y); cout << "0";
        common::gotoXY(x + 1, y); cout << hour;
    }

    if (minute > 9) {
        common::gotoXY(x + 3, y);
        cout << minute;
    }
    else {
        common::gotoXY(x + 3, y); cout << "0";
        common::gotoXY(x + 4, y); cout << minute;
    }

    if (second > 9) {
        common::gotoXY(x + 6, y); cout << second;
    }
    else {
        common::gotoXY(x + 6, y); cout << "0";
        common::gotoXY(x + 7, y); cout << second;
    }
}

int time::selection(int x, int y, int& hour, int& minute, int& second, int& ms, int input) {      // menu selection
    int flag = 0;
    //while (1) {    //collect input from user
    //    if (input == 111 || input == 79) {
    //        flag = 1; break; //press O set flag to 1 means stop
    //    }      
    //    else if (input == 98 || input == 66) {
    //        int _hour = hour, _minute = minute, _second = second; flag = 1; //press N reset everything, set flag to 1 means stop
    //        printData(x, y, hour, minute, second);                //print the new data after reset
    //        break;
    //    }
    //}
    switch (input) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        flag = 2;
    case 7:
        flag = 0;
        break;
    case 8:
        flag = 1;
        break;
    }
    return flag;
}

void time::counter(int x, int y, int& hour, int& minute, int& second, int& ms, int input, int color) {
    int flag = selection(x, y, hour, minute, second, ms, input);
    //while (!kbhit() && flag == 0) {     //keep looping while the user didn't hit any key and flag is 0
    //    if (minute < 0) {            //after minute is greater than 59, reset minute and increase 1 hour
    //        minute = 59; --hour;
    //    }
    //    if (second < 0) {         //after second is greater than 59, reset second and increase 1 minute
    //        second = 59; --minute;
    //    }
    //    printData(x, y, hour, minute, second);           //print out the new data, delay for 1000 millisecond and increase 1 second.
    //    Sleep(1000); second -= 1;
    //}
    while (!kbhit() && flag == 0) {
        if (minute < 0) {
            minute = 59; --hour;
        }
        if (second < 0) {
            second = 59; --minute;
        }
        if (ms < 0) {
            ms = 99; --second;
        }
        if (second != -1) printData(x, y, hour, minute, second, color);
        delay(10); ms -= 1;
    }
    // selection(x, y, hour, minute, second, input);    //after the user hit the keyboard, call the menu selection
}

//void time::stayTime(int x, int y, int& hour, int& minute, int& second, int& ms, int color) {
//    common::setColor(color);
//    int temp = 0;
//    while (!kbhit()) {
//        if (minute < 0) {
//            minute = 59; --hour;
//        }
//        if (second < 0) {
//            second = 59; --minute;
//        }
//        if (ms < 0) {
//            ms = 99; 
//            temp = second;
//            --second;
//        }
//        if (second != -1 && temp != second) {
//            common::setColor(color);
//            printData(x, y, hour, minute, second, color);
//        }
//        delay(10); ms -= 1;
//    }
//}

void time::timer(int x, int y, int& hour, int& minute, int& second, int& ms, int input, int color) {
    common::setColor(color);
    while (1) {             //keep the program running and never end
        counter(x, y, hour, minute, second, ms, input, color);
    }
}

void time::timerForBot(int x, int y, int& hour, int& minute, int& second, int& ms, int color, int countTime) {
    ms -= 25; int temp = 0;
    if (minute < 0) {
        minute = 59; --hour;
    }
    if (second < 0) {
        second = 59; --minute;
    }
    if (ms < 0) {
        ms = 75;
        temp = second;
        --second;
    }
    if (second != -1 && temp != second) {
        common::setConsoleColor(BRIGHT_WHITE, color);
        printData(x, y, hour, minute, second, color);
    }
}
