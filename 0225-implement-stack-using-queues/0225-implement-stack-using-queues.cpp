class MyStack {
public:
queue<int>q;
    MyStack() {
    }
    void push (int x)
    {
        q.push(x);
        int size =q.size();
        for(int i=1;i<size ;i++){
        q.push(q.front()); 
        q.pop();
    }
    }

    int pop (){
        
    int value =q.front ();
    q.pop ();
    return value ;
    }
 int top ()
{ 
    return q.front();

}
bool empty ()
{
    return q.empty () ;

}
};