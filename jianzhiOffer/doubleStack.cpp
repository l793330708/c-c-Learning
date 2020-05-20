#include <iostream>
#include <stack>
using namespace std;
/*
 利用双栈模拟队列
 */
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int tmp;
       while(!stack1.empty())
       {
           tmp = stack1.top();
           stack1.pop();
           stack2.push(tmp);
       }
       if(stack2.empty())
       {
           return -1;
       }else{
            tmp = stack2.top();
            stack2.pop();
            return tmp;
       }
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
int main(){

    Solution s;
    for(int i=1;i<=5;i++)
    {
        s.push(i);
    }
    for(int i=1;i<=5;i++)
    {
        cout<<s.pop()<<endl;
    }
    return 0;
}
