# Singleton Class

A singleton class is a special type of class in OPPs which can have only one object or instance at a time.

This is implemented by using core concepts on OOPs namely access modifiers, constructors & static methods.

####  Steps to implement Singleton Class in C++

1. Make all the constructors of the class private.
2. Delete the copy constructor and assigment operator of the class.
    ```
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    ```    
3. Make a private static pointer that can point to the same class object (singleton class). 
4. Make a public static method that returns the pointer to the same class object (singleton class).
5. Thread Safty: use the mutex for preventing of multiple create of singleton class while using threads

    ```
    #include <mutex>
    std::mutex mtx; 
    ```


    - Double Checked Locking: For perfomane optimization, you can use double-checked locking in getInstance() mehtod
