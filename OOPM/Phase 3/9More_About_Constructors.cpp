#include <iostream>
#include <utility> //! Required for std::move to enable move semantics

using namespace std;

class ResourceManager {
private:
    string name;       // Stores the name of the resource
    int* dataPointer;  // Pointer to heap-allocated integers (the managed resource)

public:
    //! 1. DEFAULT CONSTRUCTOR
    // Called automatically when an object is created without any arguments.
    ResourceManager() {
        name = "Default_Resource";      // Assign a default name
        dataPointer = new int(0);       // Allocate fresh heap memory and initialize it to 0
        cout << "Default Constructor: Created " << name << " at " << dataPointer << "\n";
    }

    //! 2. PARAMETERIZED CONSTRUCTOR
    // Called when an object is initialized with explicit, specific values.
    ResourceManager(string resName, int initialValue) {
        name = move(resName);                 // Efficiently transfer ownership of the string
        dataPointer = new int(initialValue);  // Allocate fresh heap memory with the user's value
        cout << "Parameterized Constructor: Created " << name << " with value " << *dataPointer << "\n";
    }

    //! 3. COPY CONSTRUCTOR
    // Creates a completely new duplicate object from an existing object.
    // Uses a const reference (&) to read the original object without altering it.
    ResourceManager(const ResourceManager& other) {
        name = other.name + "_Copy";          // Give the copy a unique name tracking its origin
        dataPointer = new int(*other.dataPointer); // DEEP COPY: Allocate *new* memory and copy the value
        cout << "Copy Constructor: Deep copied from " << other.name << " to " << name << "\n";
    }

    //! 4. MOVE CONSTRUCTOR (COULD SKIP THIS ONE IF YOU WANT, IT IS HARD TO UNDERSTAND and IS NOT IN THE CURRICULUM)
    // Fast-tracks ownership of resources from a temporary, dying object ('other').
    // Uses an rvalue reference (&&). marked 'noexcept' for optimization safety.
    ResourceManager(ResourceManager&& other) noexcept {
        name = move(other.name) + "_Moved";   // Take the string and tag it as moved
        dataPointer = other.dataPointer;      // SHALLOW COPY: Directly steal the memory pointer address
        other.dataPointer = nullptr;          // CRITICAL: Ground the old pointer to prevent double deletion
        cout << "Move Constructor: Stole resources for " << name << "\n";
    }

    //! 5. DESTRUCTOR
    // Automatically runs when the object goes out of scope to clean up heap memory.
    ~ResourceManager() {
        if (dataPointer != nullptr) {
            cout << "Destructor: Deleting heap memory for " << name << " at " << dataPointer << "\n";
            delete dataPointer;        // Free the allocated memory on the heap
            dataPointer = nullptr;     // Reset the pointer to prevent a dangling reference
        } else {
            // Runs if the object's resources were stolen by a Move Constructor
            cout << "Destructor: Nothing to free for " << name << " (Resource was moved)\n";
        }
    }

    // Helper method to display the internal state of the object
    void printState() const {
        if (dataPointer) {
            cout << " -> Object " << name << " holds value " << *dataPointer << "\n";
        } else {
            cout << " -> Object " << name << " is empty (null pointer)\n";
        }
    }
};

int main() {
    cout << "--- Starting Lifecycle Tracing ---\n\n";

    cout << "1 Triggering Default Constructor\n";
    ResourceManager res1; // Triggers Default Constructor
    res1.printState();
    cout << "\n";

    cout << "2 Triggering Parameterized Constructor\n";
    ResourceManager res2("Custom_Asset", 42); // Triggers Parameterized Constructor
    res2.printState();
    cout << "\n";

    cout << "3 Triggering Copy Constructor\n";
    ResourceManager res3 = res2; // Triggers Copy Constructor (allocates brand new memory for res3)
    res3.printState();
    cout << "\n";

    cout << "4 Triggering Move Constructor\n";
    // std::move converts res3 into a temporary "rvalue", forcing the Move Constructor to execute
    ResourceManager res4 = move(res3); 
    
    cout << "\nAfter moving:\n";
    res3.printState(); // res3 is now safely hollowed out (holds a null pointer)
    res4.printState(); // res4 now successfully owns the resource stolen from res3
    cout << "\n";

    cout << "--- Leaving Local Scope (Destructors execute in reverse order of creation) ---\n";
    return 0; // res4, res3, res2, and res1 are destroyed in that exact sequence here
}
