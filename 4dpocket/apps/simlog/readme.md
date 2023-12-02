# 简易的日志

## c++使用

```cpp
int main() {
    using namespace pocket::simlog;
    Logger log1("a.txt", LogLevel::DEBUG);
    log1.debug("1");
    log1.info("2");
    log1.warning("3");
    log1.error("4");
    log1.critical("5");
    return 0;
}
```
效果

![Alt text](image.png)

同时内容会保存在文件中。
