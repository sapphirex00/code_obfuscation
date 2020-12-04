#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
/*
Control-Flow Flattening PoC 
Version with flattening and bogus jump
Author: Sapphirex00
- Version: 1.1
*/

void spawn(string inbuf)
{
	LPSTR command = const_cast<char *>(inbuf.c_str());
	LPSTARTUPINFOA si  = new STARTUPINFOA();
	LPPROCESS_INFORMATION pi = new PROCESS_INFORMATION();
    CreateProcessA(NULL, command, NULL, NULL, TRUE, 0 , NULL, NULL, si, pi);
}

void call_cff()
{
    int controlflow = 1;
    std::vector<char> inbuf;
    while(controlflow)
    {
        switch(controlflow)
        {
            case 1:
                inbuf.push_back('p');
                if(!controlflow)
                {
                    controlflow = 2;
                }
                else
                {
                    controlflow = 2;
                }
                break;
            case 2:
                inbuf.push_back('o');
                if(!controlflow)
                {
                    controlflow = 3;
                }
                else
                {
                    controlflow = 3;
                }
                break;
            case 3:
                inbuf.push_back('w');
                if(!controlflow)
                {
                    controlflow = 4;
                }
                else
                {
                    controlflow = 4;
                }
                break;
            case 4:
                inbuf.push_back('e');
                if(!controlflow)
                {
                    controlflow = 5;
                }
                else
                {
                    controlflow = 5;
                }
                break;
            case 5:
                inbuf.push_back('r');
                if(!controlflow)
                {
                    controlflow = 6;
                }
                else
                {
                    controlflow = 6;
                }
                break;
            case 6:
                inbuf.push_back('s');
                if(!controlflow)
                {
                    controlflow = 7;
                }
                else
                {
                    controlflow = 7;
                }
                break;
            case 7:
                inbuf.push_back('h');
                if(!controlflow)
                {
                    controlflow = 8;
                }
                else
                {
                    controlflow = 8;
                }
                break;
            case 8:
                inbuf.push_back('e');
                if(!controlflow)
                {
                    controlflow = 9;
                }
                else
                {
                    controlflow = 9;
                }
                break;
            case 9:
                inbuf.push_back('l');
                if(!controlflow)
                {
                    controlflow = 10;
                }
                else
                {
                    controlflow = 10;
                }
                break;
            case 10:
                inbuf.push_back('l');
                if(!controlflow)
                {
                    controlflow = 11;
                }
                else
                {
                    controlflow = 11;
                }
                break;
            case 11:
                inbuf.push_back('.');
                if(!controlflow)
                {
                    controlflow = 12;
                }
                else
                {
                    controlflow = 12;
                }
                break;
            case 12:
                inbuf.push_back('e');
                if(!controlflow)
                {
                    controlflow = 13;
                }
                else
                {
                    controlflow = 13;
                }
            case 13:
                inbuf.push_back('x');
                if(!controlflow)
                {
                    controlflow = 14;
                }
                else
                {
                    controlflow = 14;
                }
                break;
            case 14:
                inbuf.push_back('e');
                if(!controlflow)
                {
                    controlflow = 0;
                }
                else
                {
                    controlflow = 0;
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
