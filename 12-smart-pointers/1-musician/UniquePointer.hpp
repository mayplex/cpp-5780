/**
 * A demo implementation of a unique pointer.
 * 
 * Author: Eran Kaufmann
 * Since:  2020-06
 */

template<typename T> class UniquePointer {
	T* ptr = nullptr;

public:
	UniquePointer()=default;

	// Convert from C pointer:
	UniquePointer(T* new_ptr):
		ptr(new_ptr) {}

	UniquePointer<T>& operator=(T* new_ptr) {
		if (ptr) delete ptr;
		ptr = new_ptr;
		return *this;
	}

	// Delete when out of scope:
	~UniquePointer(){ 
		if (ptr) delete ptr; 
	}

	// Behave like C pointer:
	T* operator->(){
		return ptr;
	}
	T& operator*(){
		return *ptr;
	}

	// Do not allow to duplicate:
	UniquePointer(UniquePointer const& other) = delete;
	UniquePointer& operator=(UniquePointer const& other) = delete;

	// Move constructor and operator=:
	UniquePointer(UniquePointer&& other){
		ptr  = other.ptr;
		other.ptr = nullptr;
	}
	void operator=(UniquePointer&& other){
		if (ptr) delete ptr; 
		ptr  = other.ptr;
		other.ptr = nullptr;
	}
};
