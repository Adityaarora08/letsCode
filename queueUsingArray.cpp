#include<iostream>
using namespace std;
template <typename T>
class QueueUsingArray{
	T *data;
	int nextIndex;
	int frontIndex;
	int size;
	int capacity;
public:
	QueueUsingArray(int s)
	{
		data= new T[s];
		nextIndex=0;
		frontIndex=-1;
		size=0;
		capacity=s;
	}
	int getSize()
	{
		return size;
	}
	bool isEmpty()
	{
		return size==0;
	}
	void enqueue(T element)
	{
		if(size==capacity)
		{
			T *newData=new T[2*capacity];
			int j=0;
			for(int i=frontIndex;i<capacity;i++)
			{
				newData[j]=data[i];
				j++;
			}
			for(int i=0;i<frontIndex;i++)
			{
				newData[j]=data[i];
				j++;
			}
			delete [] data;
			data=newData;
			frontIndex=0;
			nextIndex=capacity;
			capacity=2*capacity;
			//cout<<"Queue is full"<<endl;
			//return;
		}
		data[nextIndex]=element;
		nextIndex=(nextIndex+1)%capacity;
		if(frontIndex==-1)
		{
			frontIndex=0;
		}
		size++;		
	}
	T front()
	{
		if(isEmpty())
		{
			cout<<"Queue is empty"<<endl;
			return 0;
		}
		return data[frontIndex];
	}
	T dequeue()
	{
		if(isEmpty())
		{
			cout<<"Queue is empty"<<endl;
			return 0;
		}
		T ans= data[frontIndex];
		frontIndex=(frontIndex+1)%capacity;;
		size--;
		if(size==0)
		{
			frontIndex=-1;
			nextIndex=0;
		}
		return ans;	
	}
};
int main()
{
	QueueUsingArray<int> q(4);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	cout<<q.dequeue()<<endl;
	cout<<q.isEmpty()<<endl;
	q.enqueue(1);
	cout<<q.front()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	return 0;
}
