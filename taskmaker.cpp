﻿#include "taskmaker.h"
#include "Jacking/jacktaskmaker.h"
#include "qunchuang/qunchuangtaskmaker.h"
#include "common.h"

TaskMaker::TaskMaker()
{

}

TaskMaker::~TaskMaker()
{

}

TaskMaker* TaskMaker::getInstance()
{
    if(GLOBAL_AGV_PROJECT == AGV_PROJECT_QINGDAO){
        //不同的AGV，调用不同的子类，即可
        static JackTaskMaker *m_ins = nullptr;
        if(m_ins == nullptr){
            m_ins = new JackTaskMaker();
        }
        return m_ins;
    }else if(GLOBAL_AGV_PROJECT == AGV_PROJECT_QUNCHUANG){
        //不同的AGV，调用不同的子类，即可
        static QunChuangTaskMaker *m_ins = nullptr;
        if(m_ins == nullptr){
            m_ins = new QunChuangTaskMaker();
        }
        return m_ins;
    }
    return nullptr;
}

void TaskMaker::makeTask(std::string from ,std::string to,int dispatch_id,int ceid)
{

}
