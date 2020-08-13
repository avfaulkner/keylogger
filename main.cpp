#include <iostream>
#include <windows.h> //interact with windows os

using namespace std;

int main ()
{
    MSG Msg;
// GetMessage will check the message queue for message, if there aren't any messages in the queue it will block.
//Blocking, in this case, would mean that GetMessage will wait for a valid message to pop up into the message queue.

    while(GetMessage(&Msg, NULL, 0, 0))
    {
        // TranslateMessage will take a message from this program that is intended for a window (i.e. a terminal window)
        // and will modify the message with the message/command passed in Msg
        TranslateMessage(&Msg);
        // Forward the message to the system
        DispatchMessage(&Msg);
        // This will cause the window/console to not open when the program starts.
    }
    return 0;
}
