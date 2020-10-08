#pragma once
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <cassert>
#include <iostream>

class Function_pool{

private:
    // Queue accepts functions
    std::queue<std::function<void()>> m_function_queue; 
    // A mutex lock 
    std::mutex m_lock; 
    // A codition variable    
    std::condition_variable m_data_condition; 
    // An atomic object    
    std::atomic<bool> m_accept_functions; 

public:

    Function_pool();
    ~Function_pool();
    void push(std::function<void()> func);
    void done();
    void infinite_loop_func();
};
