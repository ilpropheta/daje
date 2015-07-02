/*
  What about using a queue as a stack and viceversa?!
  Basically, from a mathematical point of view, stacks and queues have the same "power".
  The following classes can be generalized on typename T.
*/

#include <stack>
#include <queue>

/* 
  Stack implemented by using a queue.
  Keypoint: the order of data is maintained when pushing a new item.
*/
class stack_from_queue
{
public:
    // O(n)
    void push(int i)
    {
      queue<int> tmp;
      tmp.push(i);
      while (!q.empty())
      {
          tmp.push(q.front());
          q.pop();
      }
      q = std::move(tmp); // or swap
    }

    // O(1)
    void pop()
    {
        q.pop();
    }

    // O(1)
    int top() const
    {
        return q.front();
    }

    // O(1) - not in general (it depends on the real container)
    bool empty() const
    {
        return q.empty();
    }
    
private:
    std::queue<int> q;
};

/* 
  Queue implemented by using two stacks.
  Keypoint: two stacks are used, one for storing input and another for output.
  When front/pop is requested, input data is copied (in general moved) to the output stack,
  this way the correct order is guaranteed.
*/
class queue_from_stack
{
public:
  // O(1)
  void push(int i)
  {
    in.push(i);
  }
  
  // O(n) in general
  // O(1) when out is not empty
  int front() const
  {
    // in -> out logic may be moved out
    if (out.empty())
    {
      while (!in.empty())
      {
        out.push(in.top());
        in.pop();
      }
    }
    return out.top();
  }
  
  // O(n)/O(1) as front
  void pop()
  {
    front();
    out.pop();
  }
  
  // O(1) - not in general (it depends on the real container)
  bool empty() const
  {
    return in.empty() && out.empty();
  }
  
private:
  // mutable for making front const
  mutable std::stack<int> in;
  mutable std::stack<int> out;
};
