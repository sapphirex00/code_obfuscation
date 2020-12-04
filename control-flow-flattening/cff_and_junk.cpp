#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include<sstream>
using namespace std;
/*
Control Flow-Flattening PoC 
Version with flattening, bogus jump and junk code
Author: Sapphirex00
Contact: sapphired25519@protonmail.com
Version: 1.2
*/

void spawn(string inbuf)
{
	LPSTR command = const_cast<char *>(inbuf.c_str());
	LPSTARTUPINFOA si  = new STARTUPINFOA();
	LPPROCESS_INFORMATION pi = new PROCESS_INFORMATION();
    CreateProcessA(NULL, command, NULL, NULL, TRUE, 0 , NULL, NULL, si, pi);
}

void idk()
{
    int asd = 2323;
    int fds = 1323;
    int sss = asd + fds;
}

void call_cff()
{
    int controlflow = 100;
    std::vector<char> inbuf;
    while(controlflow)
    {
        switch(controlflow)
        {
            case 100:
                inbuf.push_back('p');
                if(!controlflow)
                {
                    controlflow = 100 + 50 + 50 ;
                    idk();
                } else
                {
                    controlflow = 110 + 90;
                }
                break;
            case 200:
                inbuf.push_back('o');
                if(!controlflow)
                {
                    controlflow = 100 + 100 + 50 + 50 ;
                    idk();
                }
                else
                {
                    controlflow = 500 - 200;
                }
                break;
            case 300:
                inbuf.push_back('w');
                if(!controlflow)
                {
                    controlflow = 125 + 125 + 566;
                    idk();
                }
                else
                {
                    controlflow = 125 + 125 + 125 + 25;
                }
                break;
            case 400:
                inbuf.push_back('e');
                if(!controlflow)
                {
                    controlflow = 500 * 120 + 111;
                    idk();
                }
                else
                {
                    controlflow = 50 + 50;
                    controlflow *= 5;
                }
                break;
            case 500:
                inbuf.push_back('r');
                if(!controlflow)
                {
                    controlflow = 656 - 45;
                    idk();
                }
                else
                {
                    controlflow = 6 * 100;
                }
                break;
            case 600:
                inbuf.push_back('s');
                if(!controlflow)
                {
                    controlflow = 71456 + 10;
                    idk();
                }
                else
                {
                    controlflow += 100;
                }
                break;
            case 700:
                inbuf.push_back('h');
                if(!controlflow)
                {
                    controlflow = 8;
                    idk();
                }
                else
                {
                    controlflow += 100;
                }
                break;
            case 800:
                inbuf.push_back('e');
                if(!controlflow)
                {
                    controlflow = 9 - 1 - 4;
                    idk();
                }
                else
                {
                    controlflow = 900;
                }
                break;
            case 900:
                inbuf.push_back('l');
                if(controlflow != 900)
                {
                    controlflow = 10156;
                    idk();
                }
                else
                {
                    controlflow = 10 * 10 * 10;
                }
                break;
            case 1000:
                inbuf.push_back('l');
                if(!controlflow)
                {
                    controlflow = 117757 - 1 / 10;
                    idk();
                }
                else
                {
                    controlflow = 1100;
                }
                break;
            case 1100:
                inbuf.push_back('.');
                if(!controlflow)
                {
                    controlflow = 12456 - 4 - 1;
                    idk();
                }
                else
                {
                    controlflow = 12 * 100;
                }
                break;
            case 1200:
                inbuf.push_back('e');
                if(!controlflow)
                {
                    controlflow = 1300;
                    idk();
                }
                else
                {
                    controlflow = 13 - 13 + 13;
                    controlflow *= 100;
                }
            case 1300:
                inbuf.push_back('x');
                if(!controlflow)
                {
                    controlflow = 1411 - 1;
                    idk();
                }
                else
                {
                    controlflow = 14 * 100;
                }
                break;
            case 1400:
                inbuf.push_back('e');
                if(!controlflow)
                {
                    controlflow = 11 - 10 * 1;
                }
                else
                {
                    controlflow = 1400 - 1000 - 200 - 200;
                }
                break;
        }
    }
    std::ostringstream outbuf;
    for (char c: inbuf) {
        outbuf << c;
    }
    std::string command(outbuf.str());
    std::cout << "Executed command: " << command << std::endl;
    spawn(command);
}

void call_std()
{
    std::string inbuf = "powershell.exe";
    std::cout << "Executed command: " << inbuf << std::endl;
    spawn(inbuf);
}

int main()
{
    call_std();
    call_cff();
    return 0;
}
