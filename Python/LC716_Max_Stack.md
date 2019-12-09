# Method 1:
This method requires O(N) for `.popMax` and O(1) for other methods.

|Speed|Memory|
|-|-|
|55%|100%|


```python {.line-numbers}
class MaxStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.st = []
        self.max_st = []

    def push(self, x: int) -> None:
        self.st.append(x)
        self.max_st.append(max(self.max_st[-1], x) if len(self.max_st)>0 else x)

    def pop(self) -> int:
        self.max_st.pop()
        return self.st.pop()

    def top(self) -> int:
        return self.st[-1]

    def peekMax(self) -> int:
        return self.max_st[-1]

    def popMax(self) -> int:
        max_v = self.peekMax()
        tmp_st = []
        while self.top()!=max_v:
            tmp_st.append(self.pop())
        self.pop()
        while len(tmp_st)>0:
            self.push(tmp_st.pop())
        return max_v

# Your MaxStack object will be instantiated and called as such:
# obj = MaxStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.peekMax()
# param_5 = obj.popMax()
```


# Method 2:
This method is more complex, but it is a very good problem for understanding different data structures. This method use `C++` `map` data structure. The key are ordered by size. The stack is implemented using double linked list. Except `.peekMax` and `.top` have O(1) time complexity, all other methods (`.push`, `.pop`, `popMax`) have O(logn) time complexity.

|Speed|Memory|
|-|-|
|54.73%|44.44%|

```C++ {.line-numbers}
struct Node {
    int val;
    Node* pre=nullptr;
    Node* next=nullptr;
    Node(int x): val(x) {}
};

class MaxStack {
    map<int, vector<Node*>> mymap;
    Node* head=new Node(-1);
    Node* tail=new Node(-1);
public:
    /** initialize your data structure here. */
    MaxStack() {
        head->next = tail;
        tail->pre = head;
    }
    ~MaxStack() {
        delete head, tail;
    }
    
    void push(int x) {
        Node* node=new Node(x);
        node->pre = tail->pre;
        node->next = tail;
        tail->pre->next = node;
        tail->pre = node;
        if (mymap.find(x)==mymap.end())
            mymap.insert(pair<int, vector<Node*>>(x, {node}));
        else
            mymap[x].push_back(node);
    }
    
    int pop() {
        Node* node = tail->pre;
        mymap[node->val].pop_back();
        if (mymap[node->val].size()==0) mymap.erase(node->val);
        int res = node->val;
        del(node);
        return res;
    }
    
    int top() {
        return tail->pre->val;
    }
    
    int peekMax() {
        return mymap.rbegin()->first;
    }
    
    int popMax() {
        Node* node = mymap.rbegin()->second.back();
        mymap.rbegin()->second.pop_back();
        int res = node->val;
        del(node);
        if (mymap.rbegin()->second.size()==0) mymap.erase(res);
        return res;
    }
    
private:
    void del(Node* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
        delete node;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
```

