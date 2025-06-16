#pragma once
#include "MyContainer.hpp"


namespace merchav
{
    template<typename T>
    class OrderIterator
    {
        
    private:
        MyContainer<T>::Node* pointer_to_current_node;

    public:
        OrderIterator(Node* ptr = nullptr)
			: pointer_to_current_node(ptr) {
		}
        

        OrderIterator& operator++() {
			pointer_to_current_node = pointer_to_current_node->next;
			return *this;
		}

		const OrderIterator operator++(int) {
			OrderIterator tmp= *this;
			pointer_to_current_node= pointer_to_current_node->next;
			return tmp;
		}
        T operator*() {
            return pointer_to_current_node->value;
        }
        T operator->() {
            return &(pointer_to_current_node->value);
        }

        bool operator==(const OrderIterator& oi) const {
			return pointer_to_current_node == oi.pointer_to_current_node;
		}

		bool operator!=(const OrderIterator& oi) const {
			return pointer_to_current_node != oi.pointer_to_current_node;
		}
    
    };

    

    

} // namespace merchav