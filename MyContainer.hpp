#pragma once
#include "Order.hpp"
#include "AscendingOrder.hpp"
#include "DescendingOrder.hpp"
#include "MiddleOutOrder.hpp"
#include "SideCrossOrder.hpp"

namespace merchav
{
    template<typename T=int> 
    class MyContainer
    {
        public:
            struct Node {
                T value;
                Node* next;
                Node* previous;
                Node(T value) : value(value), next(nullptr), previous(nullptr) {}
            };

    private:
        
        Node* _head;
        Node* _tail;
        int _size;

        template<typename> class AscendingOrderIterator;
        friend class AscendingOrderIterator<T>;

        
        template<typename> class DescendingOrderIterator;
        friend class DescendingOrderIterator<T>;

        
        template<typename> class MiddleOutOrderIterator;
        friend class MiddleOutOrderIterator<T>;
        
        template<typename> class OrderIterator;
        friend class OrderIterator<T>;

        
        template<typename> class SideCrossOrderIterator;
        friend class SideCrossOrderIterator<T>;




    public:
        MyContainer() : _head(nullptr), _tail(nullptr), _size(0){}
        ~MyContainer(){}
        void add(T item)
        {
            if (_size == 0) {
                _head = new Node(item);
                _tail = _head;
            } else {
                Node* newNode = new Node(item);
                _tail->next = newNode;
                newNode->previous = _tail;
                _tail = newNode;
                
            }
            _size++;
        }
        
        void remove(T item)
        {
            Node* current = _head;
            
            while (current!=nullptr){
                if (current->value==item){

                    if (current->previous==nullptr){ //its the old head
                        _head=current->next;
                    }else{
                        (current->previous)->next=(current->next);
                    }
                    if (current->next==nullptr){// its the old tail
                        _tail=current->previous;
                    }else{
                        (current->next)->previous=(current->previous);
                    }

                    _size--;

                }
                current=current->next;
            }
            
        }
        int size(){
            int count=0;
            Node* current = _head;
            
            while (current!=nullptr){
                count++;
                current=current->next;
            }
            return count;
        }
        T get(int index){
            Node* current = _head;
            for (int i=0;i<index;i++){
                current=current->next;
            }
            return current->value;
        }
        std::ostream& operator<<(std::ostream& os)
        {
            Node* current = _head;
            while (current!=nullptr){
                
            os << "MyContainer contents: ";
            }
            return os;
        }
        merchav::OrderIterator<T> begin() {
            return OrderIterator<T>{_head};
        }
	
        merchav::OrderIterator<T> end() {
            return OrderIterator<T>{nullptr};
        }
    };
} 
