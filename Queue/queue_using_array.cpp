#include <iostream>
#include <string>
using namespace std;

class queue
{
private:
    int front;
    int rear;
    int arr[3];
public:
    queue()
    {
        front = rear = -1;
        for (int i = 0; i < 3; i++)
        {
            arr[i] = 0;
        }
    }
    bool isempty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }
    bool isfull(){
        if(rear == 2)
        return true;
        else
        return false;
    }
    void enqueue(int val){
        if (isfull())
         {
         cout<<"Queue is full"<<endl;
         return ;
         }
         else if(isempty()){
             rear = front = 0;
             arr[rear] = val;
         }
        else{
            rear ++;
            arr[rear] = val;
        }
    }
    int dequeue(){
        int x;
        if(isempty())
        {
        return 0;
        
        }
        else if(rear == front){
            x = arr[front];
            arr[front] = 0;
            front =rear = -1;
            return x; 
        }
        else
        {
            int x = arr[front];
            arr[front] = 0;
            front++;
            return x;
        }
    }
    int count(){
        return(rear-front+1);
    }
    void display(){
        cout<<"all value of the queue are :"<<endl;
        for (int i = 0; i < 3; i++)
        {
            cout<<arr[i]<<" ";
        }
        
    }
};

int main()
{   
    queue q1;
    int value,option;
    do
    {
        cout << "\nwhat operation do you want to perform ?select option number, enter 0 to exit " << endl;

        cout << "1. enqueue()" << endl;
        cout << "2. dequeue()" << endl;
        cout << "3. isempty()" << endl;
        cout << "4. isfull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. clear screen()" << endl;
        cin >> option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout<<"\nenter the value of item to enqueue in the queue is: ";
            cin>>value;
            q1.enqueue(value);
            break;
        case 2:
            if (q1.isempty())
            {
                cout << "queue is empty " << endl;
            }
            else
            {
                cout<<"dequeue operation is called,dequeu value is "<<q1.dequeue()<<endl;
            }
             break;
        case 3:
            if (q1.isempty())
                cout << "queue is empty " << endl;
            else
                cout << "queue is full " << endl;
            break;
        case 4:
            if (q1.isfull())
                cout << " queue is full " << endl;
            else
                cout << " queue is empty " << endl;
            break;
        case 5:
            cout<<"count function is called,count of item in queue is :"<<q1.count()<<endl;
            break;
        case 6:
            cout<<"display function is called!!"<<endl;
            q1.display();
            break;
        case 7:
            system("cls");
        default:
            cout << "enter proper option number " << endl;
            break;
        }
    } while (option != 0);
    return 0;
}
