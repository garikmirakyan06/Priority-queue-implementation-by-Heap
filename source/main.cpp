#include "Priority_queue.hpp"

int main() {
	
	std::initializer_list<int> l = {2,5,4};
    Priority_queue<int> pq = {2,6,2,4};
    pq = {2,5};
    
    while(pq.size() != 0) { std::cout << pq.top(); pq.pop(); }
    
    
    return 0;
}
