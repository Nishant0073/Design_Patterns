#include<bits/stdc++.h>
#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;


class Logger{
	private:

	static Logger *loggerInstance;
	static mutex mtx;
	static int cnt ;
	Logger(){
		cnt++;
		cout<<"New Instance created with ID: "<<cnt<<endl;
	};

	public:

	Logger(const Logger&);
	Logger operator=(const Logger&);

	static Logger* getInstance(){

		//mtx is expensive so if the loggerinstace is null then only use the mtx to lock it
		if(loggerInstance==NULL)
		{
			mtx.lock();
			if(loggerInstance==NULL){
				loggerInstance = new Logger();
			}
			mtx.unlock();
		}

		return loggerInstance;
	}

	static void log(string msg){
		cout<<msg<<endl;
	}
};


Logger* Logger::loggerInstance = nullptr;
int Logger::cnt = 0;
mutex Logger::mtx;

//without threading


/*
int main(){

	Logger* logger;

	Logger* logger1 = logger->getInstance();
	logger1->log("This is mgs from user1");

	Logger* logger2 = logger->getInstance();
	logger2->log("This is msg from user2");

}*/


/*
 Using threads
 */

void user1Logs(){
	Logger* logger = Logger::getInstance();
	logger->log("This is mgs from user1");
}


void user2Logs(){
	Logger* logger = Logger::getInstance();
	logger->log("This is mgs from user2");
}

int main(){
	thread t1(user1Logs);
	thread t2(user2Logs);
	t1.join();
	t2.join();

}
