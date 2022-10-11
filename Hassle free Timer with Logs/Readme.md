Easily profiling your functions

The timer starts when it's instantiated and it ends when it goes out of scope.

Example:
```cpp
void SomeFunc()
{
	Timer t("Time it took to run SomeFunc");
	
	// do work

}

void SomeFuncWithScope()
{
	// do work
	{
		// scope

		Timer t("I'm now profiling this scope inside SomeFuncWithScope");
		// do work
		// do some other work

		{
			Timer t2("Profiling a scope inside a scope");
			// do some more work
		}// the scope ends, so the timer t2 stops

	}// the scope ends, so the timer t1 stops

}
```

NOTE: The timer also accepts variadic arguments, so you can also do:
```cpp
int iDigit = 69;
Timer t("Here's my cool digit %d", iDigit);
```
