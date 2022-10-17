#include <iostream>
#include<vector>
#include <map>

using namespace std;
#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker{

public:

    string m_name;
    int m_salary;

};

void createWorker(vector<Worker>&v){
    string nameSeed  = "ABCDEFGHIJ";
    for(int i = 0;i<10;i++){
        Worker worker;
        worker.m_name = "员工";
        worker.m_name += nameSeed[i];
        worker.m_salary= rand()%10000 +10000;//10000-19999
        //将员工放在容器中
        v.push_back(worker);




    }
}
void setGroup(vector<Worker>&v,multimap<int,Worker>&x){
    for(vector<Worker>::iterator it= v.begin();it!=v.end();it++){
        //产生随机部门编号
        int deptid = rand()%3;
        //将员工插入到分组中
        x.insert(make_pair(deptid,*it));
    }



}
void showWorkerByGroup(multimap<int,Worker>&x){
    //0 A B C 1 D E 2 F G H I
    cout<<"策划部门"<<endl;
    multimap<int,Worker>::iterator pos  = x.find(CEHUA);
    int count  =x.count(CEHUA);
    int index = 0;
    for(;pos!=x.end()&&index<count;pos++,index++){
        cout<<"姓名  "<<pos->second.m_name<<"  工资 "<<pos->second.m_salary<<endl;

    }
    cout<<"-----------------"<<endl;
    cout<<"美术部门"<<endl;
    pos  = x.find(MEISHU);
    count  =x.count(MEISHU);
    index = 0;
    for(;pos!=x.end()&&index<count;pos++,index++){
        cout<<"姓名  "<<pos->second.m_name<<"  工资 "<<pos->second.m_salary<<endl;

    }
    cout<<"-----------------"<<endl;
    cout<<"研发部门"<<endl;
    pos  = x.find(YANFA);
    count  =x.count(YANFA);
    index = 0;
    for(;pos!=x.end()&&index<count;pos++,index++){
        cout<<"姓名  "<<pos->second.m_name<<"  工资 "<<pos->second.m_salary<<endl;

    }




}

int main() {
    //随机数种子
    srand((unsigned int)time(NULL));
    //1.创建员工
    vector<Worker>vworker;
    createWorker(vworker);
    //2.员工分组
    multimap<int,Worker>mworker;
    setGroup(vworker,mworker);
    //3.分组显示员工
    showWorkerByGroup(mworker);
    //测试
//    for(vector<Worker>::iterator it =vworker.begin();it!=vworker.end();it++){
//        cout<<"姓名  "<<it->m_name<<"  "<<"工资  "<<it->m_salary<<endl;
//    }





    return 0;
}
