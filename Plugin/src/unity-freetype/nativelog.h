#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;



class NativeLog
{
private:
    NativeLog(/* args */);
    ~NativeLog();
public:
    static void Log(string msg);
    static void Log(const char* msg);

    static int Flush();
};

#ifdef _MSC_VER
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __attribute__ ((visibility ("default")))
#endif

extern "C"
{
    typedef void(*NativeLogEmit)(const char* msg,int size);
    EXPORT void NativeLog_REG_CB(NativeLogEmit callback);
    EXPORT int NativeLog_FLUSH();
    EXPORT void NativeLog_TEST();
}