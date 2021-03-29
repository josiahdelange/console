## Example compilation
Note the target "demoError" should fail to compile, demonstrating the requirement of defining timestamp type.
```
$ make -C examples 
make: Entering directory '/src/console/examples'
g++ -o demoEpoch -DTIMESTAMP_EPOCH -I../ consoleDemo.cpp 
g++ -o demoDate -DTIMESTAMP_DATE -I../ consoleDemo.cpp
g++ -o demoError -I../ consoleDemo.cpp
In file included from consoleDemo.cpp:1:
../console.h:61:2: error: #error "Must define TIMESTAMP_DATE or TIME_STAMP_EPOCH."
   61 | #error "Must define TIMESTAMP_DATE or TIME_STAMP_EPOCH."
      |  ^~~~~
../console.h: In function 'void console(std::string, std::string, std::string)':
../console.h:63:22: error: 'timeStamp' was not declared in this scope
   63 |  std::cout << "[" << timeStamp << "] ";
      |                      ^~~~~~~~~
make: *** [Makefile:14: demoError] Error 1
make: Leaving directory '/src/console/examples'
```

## Example of using date-time timestamps
```
$ ./examples/demoDate 
[2021-03-28 23:17:20] consoleDemo[main] Hello, World!
[2021-03-28 23:17:20] consoleDemo[func1] Hola, Mundo!
[2021-03-28 23:17:20] consoleDemo[func2] Kon'nichiwa sekai!
```

## Example of using epoch timestamps
```
$ ./examples/demoEpoch 
[1616987844785] consoleDemo[main] Hello, World!
[1616987844785] consoleDemo[func1] Hola, Mundo!
[1616987844785] consoleDemo[func2] Kon'nichiwa sekai!
```

