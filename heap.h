#pragma once
#include<iostream>
using namespace std;
class Heap {
	int* arr;
	int capacity;
	int current;
public:
	Heap() {
		arr = new int[5];
		 capacity = 5;
		current = -1;
	}
	Heap(int size) {
		arr = new int[size+1];
		capacity = size+1;
		current = -1;
	}
	void insert(int n) {
		
		if (current+1==capacity-1)
		{
			return;
		}

		current++;

		arr[current] = n;
		MinHeapify(current);
	}
	
	int getParent(int childIndex) {
		return (childIndex -1)/2;
	}


	void MinHeapify(int child) {
		while (child !=0)
		{
			if(arr[child]>arr[getParent(child)]){
				return;
			}
			else {
			int temp = arr[child];
			arr[child] = arr[getParent(child)];
			arr[getParent(child)] = temp;
				child = getParent(child);
				}
			}
		}

		void MaxHeapify(int child) {
			while (child != 0)
			{
				if (arr[child] <= arr[getParent(child)]) {
					return;
				}
				else {
					int temp = arr[child];
					arr[child] = arr[getParent(child)];
					arr[getParent(child)] = temp;
					child = getParent(child);
				}
			}
		}
		void display() {
			for ( int i = 0; i <=current; i++)
			{
				cout << arr[i] << " ";
			}
		}
};
