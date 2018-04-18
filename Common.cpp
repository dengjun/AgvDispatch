﻿#include "Common.h"

std::string getTimeStrNow()
{
    using std::chrono::system_clock;

    //获取当前时间
    auto time_now = std::chrono::system_clock::now();
    //计算当前时间的 毫秒数 %1000;
    int ms = std::chrono::duration_cast<std::chrono::milliseconds>(time_now.time_since_epoch()).count()%1000;

    std::time_t tt = std::chrono::system_clock::to_time_t(time_now);

    std::stringstream ss;


    //gcc 4.9及之前版本不支持 std::put_time//需要gcc 5.0+
    ss << std::put_time(std::localtime(&tt), "%Y-%m-%d %H:%M:%S") << "." << ms;

    return ss.str();
}

std::string toHexString(char *data,int len)
{
    std::ostringstream out;
    out<<std::hex<<std::setfill('0');
    for(int i=0;i<len;++i){
        out<<std::setw(2)<<(0xff &(data[i]))<<std::setw(1)<<" ";
    }
    return out.str();
}
