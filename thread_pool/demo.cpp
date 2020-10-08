#include "thread_pool.hpp"
#include <string>
#include <iostream>
#include <mutex>
#include <functional>
#include <thread>
#include <vector>

using namespace std;

Function_pool func_pool;

class quit_worker_exception : public exception {};

void example_function(){
	cout << "Hello Thread \n" << endl;
}

int main(){
    // Variables
    vector<thread> thread_pool;
    int num_threads;
    
    num_threads = thread::hardware_concurrency();

    for (int i = 0; i < num_threads; i++){
        thread_pool.push_back(thread(&Function_pool::infinite_loop_func, &func_pool));
    }

    //here we should send our functions
    for (int i = 0; i < 50; i++){
        func_pool.push(example_function);
    }
    func_pool.done();
    for (unsigned int i = 0; i < thread_pool.size(); i++){
        thread_pool.at(i).join();
    }
}
