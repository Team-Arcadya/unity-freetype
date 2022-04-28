
#include "nativelog.h"

#include <sstream>
#include <queue>

static NativeLogEmit s_callback = nullptr;

struct LogData{
    std::string message;
    int size;
};

static queue<LogData>* s_queuedLogs = new queue<LogData>();

NativeLog::NativeLog(/* args */)
{
}

NativeLog::~NativeLog()
{
}


void NativeLog::Log(std::string msg){
    if(s_callback == nullptr) return;

    LogData rec;
    rec.message = msg;
    rec.size = msg.size();
    s_queuedLogs->push(rec);

}

void NativeLog::Log(const char* msg){
    if(s_callback == nullptr) return;
    
    string str = std::string(msg);

    LogData rec;
    rec.message = str;
    rec.size = str.size();
    s_queuedLogs->push(rec);
}

int NativeLog::Flush(){

    int size = s_queuedLogs->size();
    if(size == 0){
        return 0;
    }

    while (s_queuedLogs->size() > 0)
    {
        LogData rec = s_queuedLogs->front();
        s_queuedLogs->pop();
        if(rec.size > 0){
           s_callback(rec.message.c_str(),rec.message.size());
        }
    }
    return size;
    
}


void NativeLog_REG_CB(NativeLogEmit callback){
    s_callback = callback;

    if(callback!=nullptr){
        NativeLog::Log("nativelog registered");
    }
}

int NativeLog_FLUSH(){
    return NativeLog::Flush();
}

void NativeLog_TEST(){
    NativeLog::Log("test cstring");

    NativeLog::Log(std::string("test std::string"));

    std::stringstream ss;

    int val = 232034;
    ss<< "test stirng from stream intval:" << val;

    std::string str = ss.str();
    NativeLog::Log(str);
    
}
