#include<iostream>

const int size = 50;

struct Stack {
	int array[size];
	int index;
	int min;	

};

void push (Stack* s, int n) {
	if (s->index > size - 1) {
		std::cout<<"Srack Overflow"<<std::endl;
		return;
	}  
	if (s->index < 1) {
		s->min = n;
	} else if(n < s->min) {
		s->min = n;
	}
	s->array[s->index] = n;
	++s->index;
	
}

void print (Stack* s) {
	
	for (int i = 0; i < s->index; i++) {

		std::cout<<s->array[i]<<std::endl;
	}

}

int pop (Stack* s) {
	if (s->index == 0) {
		std::cout<<"Stack is empty"<<std::endl;
		return -1;
	} 
	int end = s->array[s->index];
	--s->index;
	 return end;
	
}

int get_minimum (Stack* s) {
	if (s->index == 0) {
                std::cout<<"Stack is empty"<<std::endl;
                return -1;
        }

	return s->min;
}

int main () {
	Stack s;
	s.index = 0;
	push(&s,10);
	push(&s,5);
	push(&s,7);
	push(&s,15);
	print(&s);
	pop(&s);
	print(&s);
	std::cout<<"Last element = "<<pop(&s)<<std::endl;
	std::cout<<"min = "<< get_minimum(&s)<<std::endl;

}
