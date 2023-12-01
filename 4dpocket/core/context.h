#pragma once

namespace pocket {

template <typename T>
class singletonContext {
public:
    singletonContext(const singletonContext&) = delete;
    singletonContext& operator=(const singletonContext&) = delete;

    static T& getInstance() {
        static T instance;
        return instance;
    }
    // 获取一个实例
    // T& ctx = singletonContext::getInstance();
private:
    singletonContext() {};
};






}


