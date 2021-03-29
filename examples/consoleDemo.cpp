#include "console.h"

void func2();

void func1() {
	console("consoleDemo", "Hola, Mundo!");
	func2();
}

void func2() {
	console("consoleDemo", "Kon'nichiwa sekai!");
	///func1();
}

int main() {
	console("consoleDemo", "Hello, World!");
	func1();
	return 0;
}
