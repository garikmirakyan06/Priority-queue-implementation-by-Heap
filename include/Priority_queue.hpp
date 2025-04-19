#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <iostream>
#include <vector>
#include <functional> // For std::greater and std::less
#include <initializer_list>

/**
 * The heap condition is that, for all nodes except the root, 
 * the parent node's value must have higher or equal priority than that node's value.
 *
 * if comparator is std::less - minHeap
 * if comparator is std::greater - maxHeap 
 */


template <typename T, typename Container = std::vector<T>, typename Compare = std::greater<T>>
class Priority_queue {
private:
    Container container;
    Compare compare;

    void heapify_down(size_t);
    void heapify_up(); // Start with last element
	
	template <typename InputIterator>
	void make_heap(InputIterator first, InputIterator last);
	
	void make_heap() { make_heap(container.begin(), container.end()); } // Overloading for full container 

public:
	// Member types
	using container_type = Container;
	using value_compare = Compare;
	using value_type = typename Container::value_type;
	using size_type = typename Container::size_type;
	using reference = typename Container::reference;
	
	// Constructors
    explicit Priority_queue(const Container& container = Container(),
    const Compare& compare = Compare())
    : container(container), compare(compare) {
    	if(container.size() != 0)
    		make_heap(); // first = container.begin(), last = container.end()
    }
    
	// Range constructor
	template <typename InputIterator>
	Priority_queue(InputIterator first, InputIterator last,
    const Compare& compare = Compare())
    : container(first, last), compare(compare) {
    	make_heap();
    }
    
    // Copy constructor
    Priority_queue(const Priority_queue& other) : container(other.container), compare(other.compare) {} 
    
    // Move constructor
    Priority_queue(Priority_queue&& other) noexcept : container(std::move(other.container)), compare(std::move(other.compare)) {} // noexcept is used to work optimally with STL containers
    
    // Initilizer_list constructor
    Priority_queue(std::initializer_list<T> lis) : container(lis), compare() {
    	make_heap();
    }
    
    // Copy assignment
    Priority_queue& operator=(const Priority_queue& other) {
		if(this != &other) {
			container = other.container;
			compare = other.compare;
		}
		return *this;
	}
    
    // Move assignment
    Priority_queue& operator=(Priority_queue&& other) noexcept {
		if(this != &other) {
			container = std::move(other.container);
			compare = std::move(other.compare);
		}
		return *this;
	}
	
	// Destructor
	~Priority_queue() = default;
	
    // Functions
    bool empty() const;
    size_t size() const;
    T top() const;
    void push(const T&);
    void pop();
};




// make_heap
/**
 * 
 * time complexity is O(n) (maximum 3*n comparisons) 
 * 
 */
template <typename T, typename Container, typename Compare>
template <typename InputIterator>
void Priority_queue<T, Container, Compare>::make_heap(InputIterator first, InputIterator last) {
	for(int i = container.size()/2 - 1; i >= 0; i--) { // dont count leaves
		heapify_down(i);
	}
}

// pop
template <typename T, typename Container, typename Compare>
void Priority_queue<T, Container, Compare>::pop() {
    // swap the last element with first (highest priority), delete the last element and heapify-down 
    if (empty()) {
        throw std::out_of_range("Priority queue is empty.");
    }

    std::swap(container[0], container[container.size()-1]);
    container.pop_back();
    heapify_down(0);
}


// push
template <typename T, typename Container, typename Compare>
void Priority_queue<T, Container, Compare>::push(const T& value) {
    // insert the value of the end of vector and heapify-up

    container.push_back(value);
    heapify_up();
}

// top 
template <typename T, typename Container, typename Compare>
T Priority_queue<T, Container, Compare>::top() const {
    if (empty()) {
        throw std::out_of_range("Priority queue is empty.");
    }
    return container[0];
}


// heapify-up
template <typename T, typename Container, typename Compare>
void Priority_queue<T, Container, Compare>::heapify_up() {
/**
 * 
 * This function is called in push() when we add a value
 * at the end vector and heapify-up for correcting the
 * condition of heap.
 * 
 * time complexity is O(log n) the height of tree
 * 
 * space complexity is O(1)
 * 
 */

    size_t i = container.size()-1;
    while(i > 0) {
        size_t parent = (i-1)/2;
        if(!compare(container[i], container[parent])) {
            break;
        }
        std::swap(container[parent], container[i]);
        i = parent;
    } 
}


// heapify-down
template <typename T, typename Container, typename Compare>
void Priority_queue<T, Container, Compare>::heapify_down(size_t i) {
/*
 * This function is called after removing the root element and replacing it
 * with the last element in the heap. It compares the current element with its
 * children and swaps it with the child having the highest priority.
 * This process continues while the i-th node is not leaf or the largest
 * priority is parent node (holds the heap condition).
 *
 * Precondition is that i-th node's left and right subtree must be valid heaps.
 * 
 * time complexity is O(log n) the height of a tree.
 * 
 * space complexity is O(1) (becouse algorithm is iterative not recursive)
 * 
 */
    while(true) {
        size_t left = 2*i + 1;
        size_t right = 2*i + 2;
        size_t largest_priority = i;

        if(left < container.size() && compare(container[left], container[largest_priority])) {
            largest_priority = left;
        }
        if(right < container.size() && compare(container[right], container[largest_priority])) {
            largest_priority = right;
        }
        if(largest_priority != i) {
            std::swap(container[largest_priority], container[i]);
            i = largest_priority;   
        }
        else { // holds the heap condition
            break;
        }
    }

}


// empty
template <typename T, typename Container, typename Compare>
bool Priority_queue<T, Container, Compare>::empty() const {
    return container.empty();
}

// size
template <typename T, typename Container, typename Compare>
size_t Priority_queue<T, Container, Compare>::size() const {
    return container.size();
}



#endif
